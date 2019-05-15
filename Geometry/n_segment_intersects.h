// Given N segments.
// Check (and returns the indices) if there are 2 segments intersect.
//
// NOTES:
// - Must set Segment.id. Otherwise it will be impossible to debug..
// - Floating point number? copy from here:
//   https://cp-algorithms.com/geometry/intersecting_segments.html
//
// TESTED:
// - http://acm.timus.ru/problem.aspx?space=1&num=1469
// - http://vn.spoj.com/problems/VMLINES

int cmp(int x, int y) {
    if (x == y) return 0;
    if (x < y) return -1;
    return 1;
}
struct Point {
    int x, y;

    Point() { x = y = 0; }
    Point(int x, int y) : x(x), y(y) {}

    Point operator - (const Point& a) const {
        return Point(x - a.x, y - a.y);
    }
    int operator % (const Point& a) const {
        return x*a.y - y*a.x;
    }
};
istream& operator >> (istream& cin, Point& p) {
    cin >> p.x >> p.y;
    return cin;
}

struct Segment {
    Point p, q;
    int id;

    double get_y(int x) const {
        if (p.x == q.x) return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (double) (q.x - p.x);
    }
};
istream& operator >> (istream& cin, Segment& s) {
    cin >> s.p >> s.q;
    return cin;
}

bool intersect1d(int l1, int r1, int l2, int r2) {
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);

    return max(l1, l2) <= min(r1, r2);
}
int ccw(Point a, Point b, Point c) {
    return cmp((b - a) % (c - a), 0);
}

bool intersect(const Segment& a, const Segment& b) {
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x)
        && intersect1d(a.p.y, a.q.y, b.p.y, b.q.y)
        && ccw(a.p, a.q, b.p) * ccw(a.p, a.q, b.q) <= 0
        && ccw(b.p, b.q, a.p) * ccw(b.p, b.q, a.q) <= 0;
}

bool operator < (const Segment& a, const Segment& b) {
    int x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    return a.get_y(x) < b.get_y(x) - 1e-9;
}

struct Event {
    int x;
    int tp, id;

    Event() {}
    Event(int x, int tp, int id) : x(x), tp(tp), id(id) {}

    bool operator < (const Event& e) const {
        if (x != e.x) return x < e.x;
        return tp > e.tp;
    }
};

set<Segment> s;
vector< set<Segment> :: iterator> where;
set<Segment> :: iterator get_prev(set<Segment>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

set<Segment> :: iterator get_next(set<Segment>::iterator it) {
    return ++it;
}

pair<int,int> solve(const vector<Segment>& a) {
    int n = SZ(a);
    vector<Event> e;
    REP(i,n) {
        e.push_back(Event(min(a[i].p.x, a[i].q.x), +1, i));
        e.push_back(Event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(ALL(e));

    s.clear();
    where.resize(SZ(a));
    REP(i,SZ(e)) {
        int id = e[i].id;
        if (e[i].tp == +1) {
            set<Segment>::iterator next = s.lower_bound(a[id]), prev = get_prev(next);
            if (next != s.end() && intersect(*next, a[id])) {
                return make_pair(next->id, id);
            }
            if (prev != s.end() && intersect(*prev, a[id])) {
                return make_pair(prev->id, id);
            }
            where[id] = s.insert(next, a[id]);
        } else {
            set<Segment>::iterator next = get_next(where[id]), prev = get_prev(where[id]);
            if (next != s.end() && prev != s.end() && intersect(*next, *prev)) {
                return make_pair(prev->id, next->id);
            }
            s.erase(where[id]);
        }
    }
    return make_pair(-1, -1);
}

