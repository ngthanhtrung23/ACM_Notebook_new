---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://acm.timus.ru/problem.aspx?space=1&num=1469
    - http://vn.spoj.com/problems/VMLINES
    - https://cp-algorithms.com/geometry/intersecting_segments.html
  bundledCode: "#line 1 \"Geometry/n_segment_intersects.h\"\n// Given N segments.\n\
    // Check (and returns the indices) if there are 2 segments intersect.\n//\n//\
    \ NOTES:\n// - Must set Segment.id. Otherwise it will be impossible to debug..\n\
    // - Floating point number? copy from here:\n//   https://cp-algorithms.com/geometry/intersecting_segments.html\n\
    //\n// TESTED:\n// - http://acm.timus.ru/problem.aspx?space=1&num=1469\n// - http://vn.spoj.com/problems/VMLINES\n\
    \nint cmp(int x, int y) {\n    if (x == y) return 0;\n    if (x < y) return -1;\n\
    \    return 1;\n}\nstruct Point {\n    int x, y;\n\n    Point() { x = y = 0; }\n\
    \    Point(int x, int y) : x(x), y(y) {}\n\n    Point operator - (const Point&\
    \ a) const {\n        return Point(x - a.x, y - a.y);\n    }\n    int operator\
    \ % (const Point& a) const {\n        return x*a.y - y*a.x;\n    }\n};\nistream&\
    \ operator >> (istream& cin, Point& p) {\n    cin >> p.x >> p.y;\n    return cin;\n\
    }\n\nstruct Segment {\n    Point p, q;\n    int id;\n\n    double get_y(int x)\
    \ const {\n        if (p.x == q.x) return p.y;\n        return p.y + (q.y - p.y)\
    \ * (x - p.x) / (double) (q.x - p.x);\n    }\n};\nistream& operator >> (istream&\
    \ cin, Segment& s) {\n    cin >> s.p >> s.q;\n    return cin;\n}\n\nbool intersect1d(int\
    \ l1, int r1, int l2, int r2) {\n    if (l1 > r1) swap(l1, r1);\n    if (l2 >\
    \ r2) swap(l2, r2);\n\n    return max(l1, l2) <= min(r1, r2);\n}\nint ccw(Point\
    \ a, Point b, Point c) {\n    return cmp((b - a) % (c - a), 0);\n}\n\nbool intersect(const\
    \ Segment& a, const Segment& b) {\n    return intersect1d(a.p.x, a.q.x, b.p.x,\
    \ b.q.x)\n        && intersect1d(a.p.y, a.q.y, b.p.y, b.q.y)\n        && ccw(a.p,\
    \ a.q, b.p) * ccw(a.p, a.q, b.q) <= 0\n        && ccw(b.p, b.q, a.p) * ccw(b.p,\
    \ b.q, a.q) <= 0;\n}\n\nbool operator < (const Segment& a, const Segment& b) {\n\
    \    int x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));\n    return a.get_y(x)\
    \ < b.get_y(x) - 1e-9;\n}\n\nstruct Event {\n    int x;\n    int tp, id;\n\n \
    \   Event() {}\n    Event(int x, int tp, int id) : x(x), tp(tp), id(id) {}\n\n\
    \    bool operator < (const Event& e) const {\n        if (x != e.x) return x\
    \ < e.x;\n        return tp > e.tp;\n    }\n};\n\nset<Segment> s;\nvector< set<Segment>\
    \ :: iterator> where;\nset<Segment> :: iterator get_prev(set<Segment>::iterator\
    \ it) {\n    return it == s.begin() ? s.end() : --it;\n}\n\nset<Segment> :: iterator\
    \ get_next(set<Segment>::iterator it) {\n    return ++it;\n}\n\npair<int,int>\
    \ solve(const vector<Segment>& a) {\n    int n = SZ(a);\n    vector<Event> e;\n\
    \    REP(i,n) {\n        e.push_back(Event(min(a[i].p.x, a[i].q.x), +1, i));\n\
    \        e.push_back(Event(max(a[i].p.x, a[i].q.x), -1, i));\n    }\n    sort(ALL(e));\n\
    \n    s.clear();\n    where.resize(SZ(a));\n    REP(i,SZ(e)) {\n        int id\
    \ = e[i].id;\n        if (e[i].tp == +1) {\n            set<Segment>::iterator\
    \ next = s.lower_bound(a[id]), prev = get_prev(next);\n            if (next !=\
    \ s.end() && intersect(*next, a[id])) {\n                return make_pair(next->id,\
    \ id);\n            }\n            if (prev != s.end() && intersect(*prev, a[id]))\
    \ {\n                return make_pair(prev->id, id);\n            }\n        \
    \    where[id] = s.insert(next, a[id]);\n        } else {\n            set<Segment>::iterator\
    \ next = get_next(where[id]), prev = get_prev(where[id]);\n            if (next\
    \ != s.end() && prev != s.end() && intersect(*next, *prev)) {\n              \
    \  return make_pair(prev->id, next->id);\n            }\n            s.erase(where[id]);\n\
    \        }\n    }\n    return make_pair(-1, -1);\n}\n\n"
  code: "// Given N segments.\n// Check (and returns the indices) if there are 2 segments\
    \ intersect.\n//\n// NOTES:\n// - Must set Segment.id. Otherwise it will be impossible\
    \ to debug..\n// - Floating point number? copy from here:\n//   https://cp-algorithms.com/geometry/intersecting_segments.html\n\
    //\n// TESTED:\n// - http://acm.timus.ru/problem.aspx?space=1&num=1469\n// - http://vn.spoj.com/problems/VMLINES\n\
    \nint cmp(int x, int y) {\n    if (x == y) return 0;\n    if (x < y) return -1;\n\
    \    return 1;\n}\nstruct Point {\n    int x, y;\n\n    Point() { x = y = 0; }\n\
    \    Point(int x, int y) : x(x), y(y) {}\n\n    Point operator - (const Point&\
    \ a) const {\n        return Point(x - a.x, y - a.y);\n    }\n    int operator\
    \ % (const Point& a) const {\n        return x*a.y - y*a.x;\n    }\n};\nistream&\
    \ operator >> (istream& cin, Point& p) {\n    cin >> p.x >> p.y;\n    return cin;\n\
    }\n\nstruct Segment {\n    Point p, q;\n    int id;\n\n    double get_y(int x)\
    \ const {\n        if (p.x == q.x) return p.y;\n        return p.y + (q.y - p.y)\
    \ * (x - p.x) / (double) (q.x - p.x);\n    }\n};\nistream& operator >> (istream&\
    \ cin, Segment& s) {\n    cin >> s.p >> s.q;\n    return cin;\n}\n\nbool intersect1d(int\
    \ l1, int r1, int l2, int r2) {\n    if (l1 > r1) swap(l1, r1);\n    if (l2 >\
    \ r2) swap(l2, r2);\n\n    return max(l1, l2) <= min(r1, r2);\n}\nint ccw(Point\
    \ a, Point b, Point c) {\n    return cmp((b - a) % (c - a), 0);\n}\n\nbool intersect(const\
    \ Segment& a, const Segment& b) {\n    return intersect1d(a.p.x, a.q.x, b.p.x,\
    \ b.q.x)\n        && intersect1d(a.p.y, a.q.y, b.p.y, b.q.y)\n        && ccw(a.p,\
    \ a.q, b.p) * ccw(a.p, a.q, b.q) <= 0\n        && ccw(b.p, b.q, a.p) * ccw(b.p,\
    \ b.q, a.q) <= 0;\n}\n\nbool operator < (const Segment& a, const Segment& b) {\n\
    \    int x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));\n    return a.get_y(x)\
    \ < b.get_y(x) - 1e-9;\n}\n\nstruct Event {\n    int x;\n    int tp, id;\n\n \
    \   Event() {}\n    Event(int x, int tp, int id) : x(x), tp(tp), id(id) {}\n\n\
    \    bool operator < (const Event& e) const {\n        if (x != e.x) return x\
    \ < e.x;\n        return tp > e.tp;\n    }\n};\n\nset<Segment> s;\nvector< set<Segment>\
    \ :: iterator> where;\nset<Segment> :: iterator get_prev(set<Segment>::iterator\
    \ it) {\n    return it == s.begin() ? s.end() : --it;\n}\n\nset<Segment> :: iterator\
    \ get_next(set<Segment>::iterator it) {\n    return ++it;\n}\n\npair<int,int>\
    \ solve(const vector<Segment>& a) {\n    int n = SZ(a);\n    vector<Event> e;\n\
    \    REP(i,n) {\n        e.push_back(Event(min(a[i].p.x, a[i].q.x), +1, i));\n\
    \        e.push_back(Event(max(a[i].p.x, a[i].q.x), -1, i));\n    }\n    sort(ALL(e));\n\
    \n    s.clear();\n    where.resize(SZ(a));\n    REP(i,SZ(e)) {\n        int id\
    \ = e[i].id;\n        if (e[i].tp == +1) {\n            set<Segment>::iterator\
    \ next = s.lower_bound(a[id]), prev = get_prev(next);\n            if (next !=\
    \ s.end() && intersect(*next, a[id])) {\n                return make_pair(next->id,\
    \ id);\n            }\n            if (prev != s.end() && intersect(*prev, a[id]))\
    \ {\n                return make_pair(prev->id, id);\n            }\n        \
    \    where[id] = s.insert(next, a[id]);\n        } else {\n            set<Segment>::iterator\
    \ next = get_next(where[id]), prev = get_prev(where[id]);\n            if (next\
    \ != s.end() && prev != s.end() && intersect(*next, *prev)) {\n              \
    \  return make_pair(prev->id, next->id);\n            }\n            s.erase(where[id]);\n\
    \        }\n    }\n    return make_pair(-1, -1);\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/n_segment_intersects.h
  requiredBy: []
  timestamp: '2019-05-15 17:45:22+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/n_segment_intersects.h
layout: document
redirect_from:
- /library/Geometry/n_segment_intersects.h
- /library/Geometry/n_segment_intersects.h.html
title: Geometry/n_segment_intersects.h
---
