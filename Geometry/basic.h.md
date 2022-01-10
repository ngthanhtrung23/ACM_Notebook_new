---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/SPOJ_ALIENS.cpp
    title: Geometry/SPOJ_ALIENS.cpp
  - icon: ':warning:'
    path: Geometry/basic.cpp
    title: Geometry/basic.cpp
  - icon: ':warning:'
    path: Geometry/circle.cpp
    title: Geometry/circle.cpp
  - icon: ':warning:'
    path: Geometry/polygon.cpp
    title: Geometry/polygon.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/basic_ccw.test.cpp
    title: Geometry/tests/basic_ccw.test.cpp
  - icon: ':x:'
    path: Geometry/tests/basic_segment_distance.test.cpp
    title: Geometry/tests/basic_segment_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/basic_segment_intersect.test.cpp
    title: Geometry/tests/basic_segment_intersect.test.cpp
  - icon: ':x:'
    path: Geometry/tests/polygon_area.test.cpp
    title: Geometry/tests/polygon_area.test.cpp
  - icon: ':x:'
    path: Geometry/tests/polygon_in_convex.test.cpp
    title: Geometry/tests/polygon_in_convex.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://cses.fi/problemset/task/2190/
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 355, in update\n    raise BundleErrorAt(path, i + 1, \"found codes out\
    \ of include guard\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Geometry/basic.h: line 4: found codes out of include guard\n"
  code: "#ifndef EPS\n#define EPS 1e-6\n#endif\n\n#ifndef GEOMETRY_BASIC\n#define\
    \ GEOMETRY_BASIC\nconst double PI = acos(-1.0);\n\ndouble DEG_to_RAD(double d)\
    \ { return d * PI / 180.0; }\ndouble RAD_to_DEG(double r) { return r * 180.0 /\
    \ PI; }\n\ninline int cmp(double a, double b) {\n    return (a < b - EPS) ? -1\
    \ : ((a > b + EPS) ? 1 : 0);\n}\n\nstruct Point {\n    double x, y;\n    Point()\
    \ { x = y = 0.0; }\n    Point(double _x, double _y) : x(_x), y(_y) {}\n\n    Point\
    \ operator + (const Point& a) const { return Point(x+a.x, y+a.y); }\n    Point\
    \ operator - (const Point& a) const { return Point(x-a.x, y-a.y); }\n    Point\
    \ operator * (double k) const { return Point(x*k, y*k); }\n    Point operator\
    \ / (double k) const { return Point(x/k, y/k); }\n\n    double operator * (const\
    \ Point& a) const { return x*a.x + y*a.y; } // dot product\n    double operator\
    \ % (const Point& a) const { return x*a.y - y*a.x; } // cross product\n\n    int\
    \ cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y);\
    \ }\n\n    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0;\
    \ }\n    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)\n    #undef Comp\n\
    \n    Point conj() { return Point(x, -y); }\n    double norm() { return x*x +\
    \ y*y; }\n\n    // Note: There are 2 ways for implementing len():\n    // 1. sqrt(norm())\
    \ --> fast, but inaccurate (produce some values that are of order X^2)\n    //\
    \ 2. hypot(x, y) --> slow, but much more accurate\n    double len() { return sqrt(norm());\
    \ }\n\n    Point rotate(double alpha) {\n        double cosa = cos(alpha), sina\
    \ = sin(alpha);\n        return Point(x * cosa - y * sina, x * sina + y * cosa);\n\
    \    }\n};\n\nint ccw(Point a, Point b, Point c) {\n    return cmp((b-a)%(c-a),0);\n\
    }\nint RE_TRAI = ccw(Point(0, 0), Point(0, 1), Point(-1, 1));\nint RE_PHAI = ccw(Point(0,\
    \ 0), Point(0, 1), Point(1, 1));\nistream& operator >> (istream& cin, Point& p)\
    \ {\n    cin >> p.x >> p.y;\n    return cin;\n}\nostream& operator << (ostream&\
    \ cout, Point& p) {\n    cout << p.x << ' ' << p.y;\n    return cout;\n}\n\ndouble\
    \ angle(Point a, Point o, Point b) { // min of directed angle AOB & BOA\n    a\
    \ = a - o; b = b - o;\n    return acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));\n\
    }\n\ndouble directed_angle(Point a, Point o, Point b) { // angle AOB, in range\
    \ [0, 2*PI)\n    double t = -atan2(a.y - o.y, a.x - o.x)\n            + atan2(b.y\
    \ - o.y, b.x - o.x);\n    while (t < 0) t += 2*PI;\n    return t;\n}\n\n// Distance\
    \ from p to Line ab (closest Point --> c)\ndouble distToLine(Point p, Point a,\
    \ Point b, Point &c) {\n    Point ap = p - a, ab = b - a;\n    double u = (ap\
    \ * ab) / ab.norm();\n    c = a + (ab * u);\n    return (p-c).len();\n}\n\n//\
    \ Distance from p to segment ab (closest Point --> c)\ndouble distToLineSegment(Point\
    \ p, Point a, Point b, Point &c) {\n    Point ap = p - a, ab = b - a;\n    double\
    \ u = (ap * ab) / ab.norm();\n    if (u < 0.0) {\n        c = Point(a.x, a.y);\n\
    \        return (p - a).len();\n    }\n    if (u > 1.0) {\n        c = Point(b.x,\
    \ b.y);\n        return (p - b).len();\n    }\n    return distToLine(p, a, b,\
    \ c);\n}\n\n// NOTE: WILL NOT WORK WHEN a = b = 0.\nstruct Line {\n    double\
    \ a, b, c;\n    Point A, B; // Added for polygon intersect line. Do not rely on\
    \ assumption that these are valid\n\n    Line(double _a, double _b, double _c)\
    \ : a(_a), b(_b), c(_c) {} \n\n    Line(Point _A, Point _B) : A(_A), B(_B) {\n\
    \        a = B.y - A.y;\n        b = A.x - B.x;\n        c = - (a * A.x + b *\
    \ A.y);\n    }\n    Line(Point P, double m) {\n        a = -m; b = 1;\n      \
    \  c = -((a * P.x) + (b * P.y));\n    }\n    double f(Point p) {\n        return\
    \ a*p.x + b*p.y + c;\n    }\n};\n\nbool areParallel(Line l1, Line l2) {\n    return\
    \ cmp(l1.a*l2.b, l1.b*l2.a) == 0;\n}\n\nbool areSame(Line l1, Line l2) {\n   \
    \ return areParallel(l1 ,l2) && cmp(l1.c*l2.a, l2.c*l1.a) == 0\n             \
    \   && cmp(l1.c*l2.b, l1.b*l2.c) == 0;\n}\n\nbool areIntersect(Line l1, Line l2,\
    \ Point &p) {\n    if (areParallel(l1, l2)) return false;\n    double dx = l1.b*l2.c\
    \ - l2.b*l1.c;\n    double dy = l1.c*l2.a - l2.c*l1.a;\n    double d  = l1.a*l2.b\
    \ - l2.a*l1.b;\n    p = Point(dx/d, dy/d);\n    return true;\n}\n\n// closest\
    \ point from p in line l.\nvoid closestPoint(Line l, Point p, Point &ans) {\n\
    \    if (fabs(l.b) < EPS) {\n        ans.x = -(l.c) / l.a; ans.y = p.y;\n    \
    \    return;\n    }\n    if (fabs(l.a) < EPS) {\n        ans.x = p.x; ans.y =\
    \ -(l.c) / l.b;\n        return;\n    }\n    Line perp(l.b, -l.a, - (l.b*p.x -\
    \ l.a*p.y));\n    areIntersect(l, perp, ans);\n}\n\nvoid reflectionPoint(Line\
    \ l, Point p, Point &ans) {\n    Point b;\n    closestPoint(l, p, b);\n    ans\
    \ = p + (b - p) * 2;\n}\n\n// Segment intersect\n// Tested:\n// - https://cses.fi/problemset/task/2190/\n\
    // returns true if p is on segment [a, b]\nbool onSegment(Point a, Point b, Point\
    \ p) {\n    return ccw(a, b, p) == 0\n        && min(a.x, b.x) <= p.x && p.x <=\
    \ max(a.x, b.x)\n        && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);\n}\n\
    \n// Returns true if segment [a, b] and [c, d] intersects\n// End point also returns\
    \ true\nbool segmentIntersect(Point a, Point b, Point c, Point d) {\n    if (onSegment(a,\
    \ b, c)\n            || onSegment(a, b, d)\n            || onSegment(c, d, a)\n\
    \            || onSegment(c, d, b)) {\n        return true;\n    }\n\n    return\
    \ ccw(a, b, c) * ccw(a, b, d) < 0\n        && ccw(c, d, a) * ccw(c, d, b) < 0;\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/basic.h
  requiredBy:
  - Geometry/SPOJ_ALIENS.cpp
  - Geometry/circle.cpp
  - Geometry/basic.cpp
  - Geometry/polygon.cpp
  timestamp: '2022-01-10 23:30:30+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Geometry/tests/polygon_in_convex.test.cpp
  - Geometry/tests/basic_ccw.test.cpp
  - Geometry/tests/polygon_area.test.cpp
  - Geometry/tests/basic_segment_distance.test.cpp
  - Geometry/tests/basic_segment_intersect.test.cpp
documentation_of: Geometry/basic.h
layout: document
redirect_from:
- /library/Geometry/basic.h
- /library/Geometry/basic.h.html
title: Geometry/basic.h
---
