// A straightforward, but probably sub-optimal KD-tree implmentation that's
// probably good enough for most things (current it's a 2D-tree)
//
//  - constructs from n points in O(n lg^2 n) time
//  - handles nearest-neighbor query in O(lg n) if points are well distributed
//  - worst case for nearest-neighbor may be linear in pathological case

const ll sentry = numeric_limits<ll>::max();
struct point
{ ll x, y; point(ll xx = 0, ll yy = 0) : x(xx), y(yy) {} };
bool operator==(const point &a, const point &b)
{ return a.x == b.x && a.y == b.y; }
bool on_x(const point &a, const point &b)
{ return a.x < b.x; }
bool on_y(const point &a, const point &b)
{ return a.y < b.y; }

// bounding box for a set of points
struct bbox {
  ll x0, x1, y0, y1;
  bbox() : x0(sentry), x1(-sentry), y0(sentry), y1(-sentry) {}
  // computes bounding box from a bunch of points
  void compute(const vector<point> &v) {
    for (int i = 0; i < v.size(); ++i) {
      x0 = min(x0, v[i].x); x1 = max(x1, v[i].x);
      y0 = min(y0, v[i].y); y1 = max(y1, v[i].y);
    }
  }
  // squared distance between a point and this bbox, 0 if inside
  ll distance(const point &p) {
    if (p.x < x0) {
      if (p.y < y0)       return dist2(point(x0, y0), p);
      else if (p.y > y1)  return dist2(point(x0, y1), p);
      else                return dist2(point(x0, p.y), p);
    } else if (p.x > x1) {
      if (p.y < y0)       return dist2(point(x1, y0), p);
      else if (p.y > y1)  return dist2(point(x1, y1), p);
      else                return dist2(point(x1, p.y), p);
    } else {
      if (p.y < y0)       return dist2(point(p.x, y0), p);
      else if (p.y > y1)  return dist2(point(p.x, y1), p);
      else                return 0;
    }
  }
};

struct kdnode
{
  bool leaf;      // true if this is a leaf node (has one point)
  point pt;       // the single point of this is a leaf
  bbox bound;     // bounding box for set of points in children
  kdnode *first, *second; // two children of this kd-node
  kdnode() : leaf(false), first(0), second(0) {}
  ~kdnode() { if (first) delete first; if (second) delete second; }
  ll intersect(const point &p) { return bound.distance(p); }
  void construct(vector<point> &vp) {
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
      vector<point> vl(vp.begin(), vp.begin()+half);
      vector<point> vr(vp.begin()+half, vp.end());
      first = new kdnode();   first->construct(vl);
      second = new kdnode();  second->construct(vr);
    }
  }
};

struct kdtree {
  kdnode *root;
  kdtree(const vector<point> &vp) {
    vector<point> v(vp.begin(), vp.end());
    root = new kdnode(); root->construct(v);
  }
  ~kdtree() { delete root; }

  ll search(kdnode *node, const point &p) {
    if (node->leaf) {
// commented special case tells a point not to find itself
//            if (p == node->pt) return sentry;
//            else
        return dist2(p, node->pt);
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
  ll nearest(const point &p) { return search(root, p); }
};
