// Tested:
// - https://open.kattis.com/problems/closestpair1
// - https://open.kattis.com/problems/closestpair2
//
// A straightforward, but probably sub-optimal KD-tree implmentation that's
// probably good enough for most things (current it's a 2D-tree)
//
// - constructs from n Points in O(n lg^2 n) time
// - handles nearest-neighbor query in O(lg n) if Points are well distributed
// - worst case for nearest-neighbor may be linear in pathological case
// Note:
// - When there are multiple points in same position & we need to tell a Point
//   not to find itself, must handle separatedly.

typedef long long ll;
const ll sentry = numeric_limits<ll>::max();
struct Point {
    ll x, y;
    Point(ll xx = 0, ll yy = 0) : x(xx), y(yy) {}

    Point operator - (Point a) const { return Point(x-a.x, y-a.y); }

    ll dist2() { return x*x + y*y; }
};

bool operator == (const Point &a, const Point &b){
    return a.x == b.x && a.y == b.y;
}
bool on_x(const Point &a, const Point &b) {
    return a.x < b.x;
}
bool on_y(const Point &a, const Point &b) {
    return a.y < b.y;
}

// bounding box for a set of Points
struct Bbox {
    ll x0, x1, y0, y1;
    Bbox() : x0(sentry), x1(-sentry), y0(sentry), y1(-sentry) {}
    // computes bounding box from a bunch of Points
    void compute(const vector<Point> &v) {
        for (int i = 0; i < v.size(); ++i) {
            x0 = min(x0, v[i].x); x1 = max(x1, v[i].x);
            y0 = min(y0, v[i].y); y1 = max(y1, v[i].y);
        }
    }
    // squared distance between a Point and this Bbox, 0 if inside
    ll distance(const Point &p) {
        if (p.x < x0) {
            if (p.y < y0)       return (Point(x0, y0) - p).dist2();
            else if (p.y > y1)  return (Point(x0, y1) - p).dist2();
            else                return (Point(x0, p.y) - p).dist2();
        } else if (p.x > x1) {
            if (p.y < y0)       return (Point(x1, y0) - p).dist2();
            else if (p.y > y1)  return (Point(x1, y1) - p).dist2();
            else                return (Point(x1, p.y) - p).dist2();
        } else {
            if (p.y < y0)       return (Point(p.x, y0) - p).dist2();
            else if (p.y > y1)  return (Point(p.x, y1) - p).dist2();
            else                return 0;
        }
    }
};

struct Kdnode {
    bool leaf;      // true if this is a leaf node (has one Point)
    Point pt;       // the single Point of this is a leaf
    Bbox bound;     // bounding box for set of Points in children

    Kdnode *first, *second; // two children of this kd-node

    Kdnode() : leaf(false), first(0), second(0) {}
    ~Kdnode() { if (first) delete first; if (second) delete second; }

    ll intersect(const Point &p) {
        return bound.distance(p);
    }
    void construct(vector<Point> &vp) {
        bound.compute(vp);
        if (vp.size() == 1) { leaf = true; pt = vp[0]; }
        else {
            if (bound.x1-bound.x0 >= bound.y1-bound.y0)
                sort(vp.begin(), vp.end(), on_x);
            else // otherwise split on y-coordinate
                sort(vp.begin(), vp.end(), on_y);

            // divide by taking half the array for each child
            // (not best performance if many duplicates in the middle)
            int half = vp.size()/2;
            vector<Point> vl(vp.begin(), vp.begin()+half);
            vector<Point> vr(vp.begin()+half, vp.end());
            first = new Kdnode();   first->construct(vl);
            second = new Kdnode();  second->construct(vr);
        }
    }
};

struct kdtree {
    Kdnode *root;
    kdtree(const vector<Point> &vp) {
        vector<Point> v(vp.begin(), vp.end());
        root = new Kdnode(); root->construct(v);
    }
    ~kdtree() { delete root; }

    ll search(Kdnode *node, const Point &p) {
        if (node->leaf) {
            // commented special case tells a Point not to find itself
            // BUT NOTE THAT THIS WILL FAIL WHEN THERE ARE MULTIPLE POINTS AT SAME POSITION
            //            if (p == node->pt) return sentry;
            //            else
            return (p - node->pt).dist2();
        }
        ll bfirst = node->first->intersect(p);
        ll bsecond = node->second->intersect(p);
        if (bfirst < bsecond) {
            ll best = search(node->first, p);
            if (bsecond < best) best = min(best, search(node->second, p));
            return best;
        }
        else {
            ll best = search(node->second, p);
            if (bfirst < best) best = min(best, search(node->first, p));
            return best;
        }
    }
    // squared distance to the nearest
    ll nearest(const Point &p) {
        return search(root, p);
    }
};
