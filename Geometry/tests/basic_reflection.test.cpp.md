---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/basic.h
    title: Geometry/basic.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-9
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
  bundledCode: "#line 1 \"Geometry/tests/basic_reflection.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\n\n#line\
    \ 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b);\
    \ i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a)\
    \ for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x)\
    \ { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a\
    \ << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n)\
    \ { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define\
    \ sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n// Copied from\
    \ https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\ntemplate<class\
    \ U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {\n   \
    \ return out << '(' << p.first << \", \" << p.second << ')';\n}\n\ntemplate<class\
    \ Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
    \ string>::value, ostream&>::type\noperator << (ostream& out, const Con& con)\
    \ {\n    out << '{';\n    for (auto beg = con.begin(), it = beg; it != con.end();\
    \ it++) {\n        out << (it == beg ? \"\" : \", \") << *it;\n    }\n    return\
    \ out << '}';\n}\ntemplate<size_t i, class T> ostream& print_tuple_utils(ostream&\
    \ out, const T& tup) {\n    if constexpr(i == tuple_size<T>::value) return out\
    \ << \")\"; \n    else return print_tuple_utils<i + 1, T>(out << (i ? \", \" :\
    \ \"(\") << get<i>(tup), tup); \n}\ntemplate<class ...U> ostream& operator <<\
    \ (ostream& out, const tuple<U...>& t) {\n    return print_tuple_utils<0, tuple<U...>>(out,\
    \ t);\n}\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r) {\n    return uniform_int_distribution<long long>\
    \ (0, r-1)(rng);\n}\n\nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    solve();\n    return 0;\n}\n#line 2 \"Geometry/basic.h\"\n\n\
    #ifndef EPS  // allow test files to overwrite EPS\n#define EPS 1e-6\n#endif\n\n\
    const double PI = acos(-1.0);\n\ndouble DEG_to_RAD(double d) { return d * PI /\
    \ 180.0; }\ndouble RAD_to_DEG(double r) { return r * 180.0 / PI; }\n\ninline int\
    \ cmp(double a, double b) {\n    return (a < b - EPS) ? -1 : ((a > b + EPS) ?\
    \ 1 : 0);\n}\n\nstruct Point {\n    double x, y;\n    Point() { x = y = 0.0; }\n\
    \    Point(double _x, double _y) : x(_x), y(_y) {}\n\n    Point operator + (const\
    \ Point& a) const { return Point(x+a.x, y+a.y); }\n    Point operator - (const\
    \ Point& a) const { return Point(x-a.x, y-a.y); }\n    Point operator * (double\
    \ k) const { return Point(x*k, y*k); }\n    Point operator / (double k) const\
    \ { return Point(x/k, y/k); }\n\n    double operator * (const Point& a) const\
    \ { return x*a.x + y*a.y; } // dot product\n    double operator % (const Point&\
    \ a) const { return x*a.y - y*a.x; } // cross product\n\n    int cmp(Point q)\
    \ const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }\n\n    #define\
    \ Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }\n    Comp(>)\
    \ Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)\n    #undef Comp\n\n    Point conj()\
    \ { return Point(x, -y); }\n    double norm() { return x*x + y*y; }\n\n    //\
    \ Note: There are 2 ways for implementing len():\n    // 1. sqrt(norm()) --> fast,\
    \ but inaccurate (produce some values that are of order X^2)\n    // 2. hypot(x,\
    \ y) --> slow, but much more accurate\n    double len() { return hypot(x, y);\
    \ }\n\n    Point rotate(double alpha) {\n        double cosa = cos(alpha), sina\
    \ = sin(alpha);\n        return Point(x * cosa - y * sina, x * sina + y * cosa);\n\
    \    }\n};\n\n// Compare points by (y, x)\nauto cmpy = [] (const Point& a, const\
    \ Point& b) {\n    if (a.y != b.y) return a.y < b.y;\n    return a.x < b.x;\n\
    };\n\nint ccw(Point a, Point b, Point c) {\n    return cmp((b-a)%(c-a),0);\n}\n\
    int RE_TRAI = ccw(Point(0, 0), Point(0, 1), Point(-1, 1));\nint RE_PHAI = ccw(Point(0,\
    \ 0), Point(0, 1), Point(1, 1));\nistream& operator >> (istream& cin, Point& p)\
    \ {\n    cin >> p.x >> p.y;\n    return cin;\n}\nostream& operator << (ostream&\
    \ cout, Point& p) {\n    cout << p.x << ' ' << p.y;\n    return cout;\n}\n\ndouble\
    \ angle(Point a, Point o, Point b) { // min of directed angle AOB & BOA\n    a\
    \ = a - o; b = b - o;\n    return acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));\n\
    }\n\ndouble directed_angle(Point a, Point o, Point b) { // angle AOB, in range\
    \ [0, 2*PI)\n    double t = -atan2(a.y - o.y, a.x - o.x)\n            + atan2(b.y\
    \ - o.y, b.x - o.x);\n    while (t < 0) t += 2*PI;\n    return t;\n}\n\n// Distance\
    \ from p to Line ab (closest Point --> c)\n// i.e. c is projection of p on AB\n\
    double distToLine(Point p, Point a, Point b, Point &c) {\n    Point ap = p - a,\
    \ ab = b - a;\n    double u = (ap * ab) / ab.norm();\n    c = a + (ab * u);\n\
    \    return (p-c).len();\n}\n\n// Distance from p to segment ab (closest Point\
    \ --> c)\ndouble distToLineSegment(Point p, Point a, Point b, Point &c) {\n  \
    \  Point ap = p - a, ab = b - a;\n    double u = (ap * ab) / ab.norm();\n    if\
    \ (u < 0.0) {\n        c = Point(a.x, a.y);\n        return (p - a).len();\n \
    \   }\n    if (u > 1.0) {\n        c = Point(b.x, b.y);\n        return (p - b).len();\n\
    \    }\n    return distToLine(p, a, b, c);\n}\n\n// NOTE: WILL NOT WORK WHEN a\
    \ = b = 0.\nstruct Line {\n    double a, b, c;\n    Point A, B; // Added for polygon\
    \ intersect line. Do not rely on assumption that these are valid\n\n    Line(double\
    \ _a, double _b, double _c) : a(_a), b(_b), c(_c) {} \n\n    Line(Point _A, Point\
    \ _B) : A(_A), B(_B) {\n        a = B.y - A.y;\n        b = A.x - B.x;\n     \
    \   c = - (a * A.x + b * A.y);\n    }\n    Line(Point P, double m) {\n       \
    \ a = -m; b = 1;\n        c = -((a * P.x) + (b * P.y));\n    }\n    double f(Point\
    \ p) {\n        return a*p.x + b*p.y + c;\n    }\n};\n\nbool areParallel(Line\
    \ l1, Line l2) {\n    return cmp(l1.a*l2.b, l1.b*l2.a) == 0;\n}\n\nbool areSame(Line\
    \ l1, Line l2) {\n    return areParallel(l1 ,l2) && cmp(l1.c*l2.a, l2.c*l1.a)\
    \ == 0\n                && cmp(l1.c*l2.b, l1.b*l2.c) == 0;\n}\n\nbool areIntersect(Line\
    \ l1, Line l2, Point &p) {\n    if (areParallel(l1, l2)) return false;\n    double\
    \ dx = l1.b*l2.c - l2.b*l1.c;\n    double dy = l1.c*l2.a - l2.c*l1.a;\n    double\
    \ d  = l1.a*l2.b - l2.a*l1.b;\n    p = Point(dx/d, dy/d);\n    return true;\n\
    }\n\n// closest point from p in line l.\nvoid closestPoint(Line l, Point p, Point\
    \ &ans) {\n    if (fabs(l.b) < EPS) {\n        ans.x = -(l.c) / l.a; ans.y = p.y;\n\
    \        return;\n    }\n    if (fabs(l.a) < EPS) {\n        ans.x = p.x; ans.y\
    \ = -(l.c) / l.b;\n        return;\n    }\n    Line perp(l.b, -l.a, - (l.b*p.x\
    \ - l.a*p.y));\n    areIntersect(l, perp, ans);\n}\n\nvoid reflectionPoint(Line\
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
    }\n#line 5 \"Geometry/tests/basic_reflection.test.cpp\"\n\n#define ERROR 1e-9\n\
    \nvoid solve() {\n    cout << (fixed) << setprecision(10);\n    Point a, b; cin\
    \ >> a >> b;\n    int q; cin >> q;\n    while (q--) {\n        Point p; cin >>\
    \ p;\n        Point projection;\n        distToLine(p, a, b, projection);\n  \
    \      Point reflection = projection * 2 - p;\n        cout << reflection << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\
    \n\n#include \"../../template.h\"\n#include \"../basic.h\"\n\n#define ERROR 1e-9\n\
    \nvoid solve() {\n    cout << (fixed) << setprecision(10);\n    Point a, b; cin\
    \ >> a >> b;\n    int q; cin >> q;\n    while (q--) {\n        Point p; cin >>\
    \ p;\n        Point projection;\n        distToLine(p, a, b, projection);\n  \
    \      Point reflection = projection * 2 - p;\n        cout << reflection << '\\\
    n';\n    }\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  isVerificationFile: true
  path: Geometry/tests/basic_reflection.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 01:06:49+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Geometry/tests/basic_reflection.test.cpp
layout: document
redirect_from:
- /verify/Geometry/tests/basic_reflection.test.cpp
- /verify/Geometry/tests/basic_reflection.test.cpp.html
title: Geometry/tests/basic_reflection.test.cpp
---
