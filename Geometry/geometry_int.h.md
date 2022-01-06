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
    - https://cses.fi/problemset/task/2195/
  bundledCode: "#line 1 \"Geometry/geometry_int.h\"\nusing ll = long long;\nint cmp(ll\
    \ a, ll b) {\n    if (a < b) return -1;\n    if (a > b) return 1;\n    return\
    \ 0;\n}\nstruct Point {\n    ll x, y;\n    Point() { x = y = 0.0; }\n    Point(ll\
    \ _x, ll _y) : x(_x), y(_y) {}\n\n    Point operator + (const Point& a) const\
    \ { return Point(x+a.x, y+a.y); }\n    Point operator - (const Point& a) const\
    \ { return Point(x-a.x, y-a.y); }\n\n    ll operator % (const Point& a) const\
    \ { return x*a.y - y*a.x; } // cross product\n\n    int cmp(Point q) const { if\
    \ (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }\n\n    #define Comp(x)\
    \ bool operator x (Point q) const { return cmp(q) x 0; }\n    Comp(>) Comp(<)\
    \ Comp(==) Comp(>=) Comp(<=) Comp(!=)\n    #undef Comp\n};\n\nint ccw(Point a,\
    \ Point b, Point c) {\n    return cmp((b-a)%(c-a),0);\n}\nint RE_TRAI = ccw(Point(0,\
    \ 0), Point(0, 1), Point(-1, 1));\nint RE_PHAI = ccw(Point(0, 0), Point(0, 1),\
    \ Point(1, 1));\nistream& operator >> (istream& cin, Point& p) {\n    cin >> p.x\
    \ >> p.y;\n    return cin;\n}\nostream& operator << (ostream& cout, Point& p)\
    \ {\n    cout << p.x << ' ' << p.y;\n    return cout;\n}\n\ntypedef vector< Point\
    \ > Polygon;\n\n// Convex Hull\n// Tested:\n// - https://cses.fi/problemset/task/2195/\n\
    ll area2(Point a, Point b, Point c) { return a%b + b%c + c%a; }\n#ifdef REMOVE_REDUNDANT\n\
    bool between(const Point &a, const Point &b, const Point &c) {\n    return (llabs(area2(a,b,c))\
    \ == 0\n            && (a.x-b.x)*(c.x-b.x) <= 0\n            && (a.y-b.y)*(c.y-b.y)\
    \ <= 0);\n}\n#endif\n\nvoid ConvexHull(vector<Point> &pts) {\n    sort(pts.begin(),\
    \ pts.end());\n    pts.erase(unique(pts.begin(), pts.end()), pts.end());\n   \
    \ vector<Point> up, dn;\n    for (int i = 0; i < (int) pts.size(); i++) {\n#ifdef\
    \ REMOVE_REDUNDANT\n        while (up.size() > 1 && area2(up[up.size()-2], up.back(),\
    \ pts[i]) >= 0) up.pop_back();\n        while (dn.size() > 1 && area2(dn[dn.size()-2],\
    \ dn.back(), pts[i]) <= 0) dn.pop_back();\n#else\n        while (up.size() > 1\
    \ && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();\n        while\
    \ (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();\n\
    #endif\n        up.push_back(pts[i]);\n        dn.push_back(pts[i]);\n    }\n\
    \    pts = dn;\n    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);\n\
    \    \n#ifdef REMOVE_REDUNDANT\n    if (pts.size() <= 2) return;\n    dn.clear();\n\
    \    dn.push_back(pts[0]);\n    dn.push_back(pts[1]);\n    for (int i = 2; i <\
    \ (int) pts.size(); i++) {\n        if (between(dn[dn.size()-2], dn[dn.size()-1],\
    \ pts[i])) dn.pop_back();\n        dn.push_back(pts[i]);\n    }\n    if (dn.size()\
    \ >= 3 && between(dn.back(), dn[0], dn[1])) {\n        dn[0] = dn.back();\n  \
    \      dn.pop_back();\n    }\n    pts = dn;\n#endif\n}\n"
  code: "using ll = long long;\nint cmp(ll a, ll b) {\n    if (a < b) return -1;\n\
    \    if (a > b) return 1;\n    return 0;\n}\nstruct Point {\n    ll x, y;\n  \
    \  Point() { x = y = 0.0; }\n    Point(ll _x, ll _y) : x(_x), y(_y) {}\n\n   \
    \ Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }\n  \
    \  Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }\n\n\
    \    ll operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product\n\
    \n    int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y);\
    \ }\n\n    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0;\
    \ }\n    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)\n    #undef Comp\n\
    };\n\nint ccw(Point a, Point b, Point c) {\n    return cmp((b-a)%(c-a),0);\n}\n\
    int RE_TRAI = ccw(Point(0, 0), Point(0, 1), Point(-1, 1));\nint RE_PHAI = ccw(Point(0,\
    \ 0), Point(0, 1), Point(1, 1));\nistream& operator >> (istream& cin, Point& p)\
    \ {\n    cin >> p.x >> p.y;\n    return cin;\n}\nostream& operator << (ostream&\
    \ cout, Point& p) {\n    cout << p.x << ' ' << p.y;\n    return cout;\n}\n\ntypedef\
    \ vector< Point > Polygon;\n\n// Convex Hull\n// Tested:\n// - https://cses.fi/problemset/task/2195/\n\
    ll area2(Point a, Point b, Point c) { return a%b + b%c + c%a; }\n#ifdef REMOVE_REDUNDANT\n\
    bool between(const Point &a, const Point &b, const Point &c) {\n    return (llabs(area2(a,b,c))\
    \ == 0\n            && (a.x-b.x)*(c.x-b.x) <= 0\n            && (a.y-b.y)*(c.y-b.y)\
    \ <= 0);\n}\n#endif\n\nvoid ConvexHull(vector<Point> &pts) {\n    sort(pts.begin(),\
    \ pts.end());\n    pts.erase(unique(pts.begin(), pts.end()), pts.end());\n   \
    \ vector<Point> up, dn;\n    for (int i = 0; i < (int) pts.size(); i++) {\n#ifdef\
    \ REMOVE_REDUNDANT\n        while (up.size() > 1 && area2(up[up.size()-2], up.back(),\
    \ pts[i]) >= 0) up.pop_back();\n        while (dn.size() > 1 && area2(dn[dn.size()-2],\
    \ dn.back(), pts[i]) <= 0) dn.pop_back();\n#else\n        while (up.size() > 1\
    \ && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();\n        while\
    \ (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();\n\
    #endif\n        up.push_back(pts[i]);\n        dn.push_back(pts[i]);\n    }\n\
    \    pts = dn;\n    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);\n\
    \    \n#ifdef REMOVE_REDUNDANT\n    if (pts.size() <= 2) return;\n    dn.clear();\n\
    \    dn.push_back(pts[0]);\n    dn.push_back(pts[1]);\n    for (int i = 2; i <\
    \ (int) pts.size(); i++) {\n        if (between(dn[dn.size()-2], dn[dn.size()-1],\
    \ pts[i])) dn.pop_back();\n        dn.push_back(pts[i]);\n    }\n    if (dn.size()\
    \ >= 3 && between(dn.back(), dn[0], dn[1])) {\n        dn[0] = dn.back();\n  \
    \      dn.pop_back();\n    }\n    pts = dn;\n#endif\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/geometry_int.h
  requiredBy: []
  timestamp: '2022-01-07 04:26:06+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/geometry_int.h
layout: document
redirect_from:
- /library/Geometry/geometry_int.h
- /library/Geometry/geometry_int.h.html
title: Geometry/geometry_int.h
---
