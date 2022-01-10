---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Geometry/basic.h
    title: Geometry/basic.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b)\
    \ for(int i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a;\
    \ i++)\n#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end();\
    \ ++it)\n\n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl; }\n\
    #define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout\
    \ << endl; }\n#define PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout << a[_]\
    \ << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\n\n// For printing pair,\
    \ container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
    template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>&\
    \ p) {\n    return out << '(' << p.first << \", \" << p.second << ')';\n}\n\n\
    template<class Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
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
    \ 1 : 0);\n}\n\n// for int types\ntemplate<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type\
    \ * = nullptr>\ninline int cmp(T a, T b) {\n    return (a == b) ? 0 : (a < b)\
    \ ? -1 : 1;\n}\n\ntemplate<typename T>\nstruct P {\n    T x, y;\n    P() { x =\
    \ y = T(0); }\n    P(T _x, T _y) : x(_x), y(_y) {}\n\n    P operator + (const\
    \ P& a) const { return P(x+a.x, y+a.y); }\n    P operator - (const P& a) const\
    \ { return P(x-a.x, y-a.y); }\n    P operator * (T k) const { return P(x*k, y*k);\
    \ }\n    P<double> operator / (double k) const { return P(x/k, y/k); }\n\n   \
    \ T operator * (const P& a) const { return x*a.x + y*a.y; } // dot product\n \
    \   T operator % (const P& a) const { return x*a.y - y*a.x; } // cross product\n\
    \n    int cmp(P q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y);\
    \ }\n\n    #define Comp(x) bool operator x (P q) const { return cmp(q) x 0; }\n\
    \    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)\n    #undef Comp\n\n\
    \    T norm() { return x*x + y*y; }\n\n    // Note: There are 2 ways for implementing\
    \ len():\n    // 1. sqrt(norm()) --> fast, but inaccurate (produce some values\
    \ that are of order X^2)\n    // 2. hypot(x, y) --> slow, but much more accurate\n\
    \    double len() { return hypot(x, y); }\n\n    P<double> rotate(double alpha)\
    \ {\n        double cosa = cos(alpha), sina = sin(alpha);\n        return P(x\
    \ * cosa - y * sina, x * sina + y * cosa);\n    }\n};\nusing Point = P<double>;\n\
    \n// Compare points by (y, x)\ntemplate<typename T = double>\nbool cmpy(const\
    \ P<T>& a, const P<T>& b) {\n    if (cmp(a.y, b.y)) return a.y < b.y;\n    return\
    \ a.x < b.x;\n};\n\ntemplate<typename T>\nint ccw(P<T> a, P<T> b, P<T> c) {\n\
    \    return cmp((b-a)%(c-a), T(0));\n}\n\nint RE_TRAI = ccw(Point(0, 0), Point(0,\
    \ 1), Point(-1, 1));\nint RE_PHAI = ccw(Point(0, 0), Point(0, 1), Point(1, 1));\n\
    \ntemplate<typename T>\nistream& operator >> (istream& cin, P<T>& p) {\n    cin\
    \ >> p.x >> p.y;\n    return cin;\n}\ntemplate<typename T>\nostream& operator\
    \ << (ostream& cout, P<T>& p) {\n    cout << p.x << ' ' << p.y;\n    return cout;\n\
    }\n\ndouble angle(Point a, Point o, Point b) { // min of directed angle AOB &\
    \ BOA\n    a = a - o; b = b - o;\n    return acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));\n\
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
    \ - l.a*p.y));\n    areIntersect(l, perp, ans);\n}\n\n// Segment intersect\n//\
    \ Tested:\n// - https://cses.fi/problemset/task/2190/\n// returns true if p is\
    \ on segment [a, b]\ntemplate<typename T>\nbool onSegment(const P<T>& a, const\
    \ P<T>& b, const P<T>& p) {\n    return ccw(a, b, p) == 0\n        && min(a.x,\
    \ b.x) <= p.x && p.x <= max(a.x, b.x)\n        && min(a.y, b.y) <= p.y && p.y\
    \ <= max(a.y, b.y);\n}\n\n// Returns true if segment [a, b] and [c, d] intersects\n\
    // End point also returns true\ntemplate<typename T>\nbool segmentIntersect(const\
    \ P<T>& a, const P<T>& b, const P<T>& c, const P<T>& d) {\n    if (onSegment(a,\
    \ b, c)\n            || onSegment(a, b, d)\n            || onSegment(c, d, a)\n\
    \            || onSegment(c, d, b)) {\n        return true;\n    }\n\n    return\
    \ ccw(a, b, c) * ccw(a, b, d) < 0\n        && ccw(c, d, a) * ccw(c, d, b) < 0;\n\
    }\n#line 3 \"Geometry/basic.cpp\"\n\nint main() {\n    Point P1, P2, P3(0, 1);\n\
    \    assert((P1 == P2) == true);\n    assert((P1 == P3) == false);\n\n    vector<Point>\
    \ P;\n    P.push_back(Point(2, 2));\n    P.push_back(Point(4, 3));\n    P.push_back(Point(2,\
    \ 4));\n    P.push_back(Point(6, 6));\n    P.push_back(Point(2, 6));\n    P.push_back(Point(6,\
    \ 5));\n\n    // sorting points demo\n    sort(P.begin(), P.end());\n    assert(P[0]\
    \ == Point(2, 2));\n    assert(P[1] == Point(2, 4));\n    assert(P[2] == Point(2,\
    \ 6));\n    assert(P[3] == Point(4, 3));\n    assert(P[4] == Point(6, 5));\n \
    \   assert(P[5] == Point(6, 6));\n\n    // rearrange the points as shown in the\
    \ diagram below\n    P.clear();\n    P.push_back(Point(2, 2));\n    P.push_back(Point(4,\
    \ 3));\n    P.push_back(Point(2, 4));\n    P.push_back(Point(6, 6));\n    P.push_back(Point(2,\
    \ 6));\n    P.push_back(Point(6, 5));\n    P.push_back(Point(8, 6));\n\n    /*\n\
    \    // the positions of these 7 points (0-based indexing)\n    6   P4      P3\
    \  P6\n    5           P5\n    4   P2\n    3       P1\n    2   P0\n    1\n   \
    \ 0 1 2 3 4 5 6 7 8\n    */\n\n    double d = (P[0] - P[5]).len();\n    assert(cmp(d,\
    \ 5.0) == 0);\n\n    // Line equations\n    Line l1(P[0], P[1]);\n    assert(cmp(l1.a\
    \ * P[0].x + l1.b * P[0].y + l1.c, 0) == 0);\n    assert(cmp(l1.a * P[1].x + l1.b\
    \ * P[1].y + l1.c, 0) == 0);\n\n    Line l2(P[0], P[2]);\n    assert(cmp(l2.a\
    \ * P[0].x + l2.b * P[0].y + l2.c, 0) == 0);\n    assert(cmp(l2.a * P[2].x + l2.b\
    \ * P[0].y + l2.c, 0) == 0);\n\n    // parallel, same, and Line intersection tests\n\
    \    Line l3(P[2], P[3]);\n    assert(areParallel(l1, l2) == false);\n    assert(areParallel(l1,\
    \ l3) == true);\n\n    Line l4(P[2], P[4]);\n    assert(areSame(l1, l2) == false);\n\
    \    assert(areSame(l2, l4) == true);\n\n    Point p12;\n    bool res = areIntersect(l1,\
    \ l2, p12);\n    assert(res);\n    assert(p12 == Point(2, 2));\n\n    // other\
    \ distances\n    Point ans;\n    d = distToLine(P[0], P[2], P[3], ans);\n    assert(cmp(d,\
    \ 1.788854382) == 0);\n    assert(ans == Point(1.2, 3.6));\n\n    closestPoint(l3,\
    \ P[0], ans);\n    assert(cmp(d, 1.788854382) == 0);\n    assert(ans == Point(1.2,\
    \ 3.6));\n\n    d = distToLineSegment(P[0], P[2], P[3], ans);\n    assert(cmp(d,\
    \ 2) == 0);\n    assert(ans == Point(2, 4));\n\n    d = distToLineSegment(P[1],\
    \ P[2], P[3], ans);\n    assert(cmp(d, 1.788854382) == 0);\n    assert(ans ==\
    \ Point(3.2, 4.6));\n\n    d = distToLineSegment(P[6], P[2], P[3], ans);\n   \
    \ assert(cmp(d, 2) == 0);\n    assert(ans == Point(6, 6));\n\n    reflectionPoint(l4,\
    \ P[1], ans);\n    assert(ans == Point(0, 3));\n\n    assert(cmp(RAD_to_DEG(angle(P[0],\
    \ P[4], P[3])), 90) == 0);\n    assert(cmp(RAD_to_DEG(angle(P[0], P[2], P[1])),\
    \ 63.434948823) == 0);\n    assert(cmp(RAD_to_DEG(angle(P[4], P[3], P[6])), 180)\
    \ == 0);\n\n    assert(ccw(P[0], P[2], P[3]) == -1);\n    assert(ccw(P[0], P[3],\
    \ P[2]) == 1);\n\n    assert(ccw(P[0], P[2], P[3]) != 0);\n    assert(ccw(P[0],\
    \ P[2], P[4]) == 0);\n\n    Point p(3, 7), q(11, 13), r(35, 30);\n    assert(ccw(p,\
    \ q, r) == -1);\n\n    /*\n    // the positions of these 6 points\n     E<-- \
    \ 4\n           3       B D<--\n           2   A C\n           1\n    -4-3-2-1\
    \ 0 1 2 3 4 5 6\n          -1\n          -2\n    F<--   -3\n    */\n\n    // translation\n\
    \    Point A(2.0, 2.0);\n    Point B(4.0, 3.0);\n    Point v = B - A;\n\n    Point\
    \ C(3.0, 2.0);\n    Point D = C + v;\n    assert(D == Point(5, 3));\n    Point\
    \ E = C + v * 0.5;\n    assert(E == Point(4, 2.5));\n\n    // rotation\n    assert(B\
    \ == Point(4, 3));\n    Point F = B.rotate(DEG_to_RAD(90));\n    assert(F == Point(-3,\
    \ 4));\n    Point G = B.rotate(DEG_to_RAD(180));\n    assert(G == Point(-4, -3));\n\
    \n    cout << \"All tests passed\" << endl;\n\n    return 0;\n}\n"
  code: "#include \"../template.h\"\n#include \"basic.h\"\n\nint main() {\n    Point\
    \ P1, P2, P3(0, 1);\n    assert((P1 == P2) == true);\n    assert((P1 == P3) ==\
    \ false);\n\n    vector<Point> P;\n    P.push_back(Point(2, 2));\n    P.push_back(Point(4,\
    \ 3));\n    P.push_back(Point(2, 4));\n    P.push_back(Point(6, 6));\n    P.push_back(Point(2,\
    \ 6));\n    P.push_back(Point(6, 5));\n\n    // sorting points demo\n    sort(P.begin(),\
    \ P.end());\n    assert(P[0] == Point(2, 2));\n    assert(P[1] == Point(2, 4));\n\
    \    assert(P[2] == Point(2, 6));\n    assert(P[3] == Point(4, 3));\n    assert(P[4]\
    \ == Point(6, 5));\n    assert(P[5] == Point(6, 6));\n\n    // rearrange the points\
    \ as shown in the diagram below\n    P.clear();\n    P.push_back(Point(2, 2));\n\
    \    P.push_back(Point(4, 3));\n    P.push_back(Point(2, 4));\n    P.push_back(Point(6,\
    \ 6));\n    P.push_back(Point(2, 6));\n    P.push_back(Point(6, 5));\n    P.push_back(Point(8,\
    \ 6));\n\n    /*\n    // the positions of these 7 points (0-based indexing)\n\
    \    6   P4      P3  P6\n    5           P5\n    4   P2\n    3       P1\n    2\
    \   P0\n    1\n    0 1 2 3 4 5 6 7 8\n    */\n\n    double d = (P[0] - P[5]).len();\n\
    \    assert(cmp(d, 5.0) == 0);\n\n    // Line equations\n    Line l1(P[0], P[1]);\n\
    \    assert(cmp(l1.a * P[0].x + l1.b * P[0].y + l1.c, 0) == 0);\n    assert(cmp(l1.a\
    \ * P[1].x + l1.b * P[1].y + l1.c, 0) == 0);\n\n    Line l2(P[0], P[2]);\n   \
    \ assert(cmp(l2.a * P[0].x + l2.b * P[0].y + l2.c, 0) == 0);\n    assert(cmp(l2.a\
    \ * P[2].x + l2.b * P[0].y + l2.c, 0) == 0);\n\n    // parallel, same, and Line\
    \ intersection tests\n    Line l3(P[2], P[3]);\n    assert(areParallel(l1, l2)\
    \ == false);\n    assert(areParallel(l1, l3) == true);\n\n    Line l4(P[2], P[4]);\n\
    \    assert(areSame(l1, l2) == false);\n    assert(areSame(l2, l4) == true);\n\
    \n    Point p12;\n    bool res = areIntersect(l1, l2, p12);\n    assert(res);\n\
    \    assert(p12 == Point(2, 2));\n\n    // other distances\n    Point ans;\n \
    \   d = distToLine(P[0], P[2], P[3], ans);\n    assert(cmp(d, 1.788854382) ==\
    \ 0);\n    assert(ans == Point(1.2, 3.6));\n\n    closestPoint(l3, P[0], ans);\n\
    \    assert(cmp(d, 1.788854382) == 0);\n    assert(ans == Point(1.2, 3.6));\n\n\
    \    d = distToLineSegment(P[0], P[2], P[3], ans);\n    assert(cmp(d, 2) == 0);\n\
    \    assert(ans == Point(2, 4));\n\n    d = distToLineSegment(P[1], P[2], P[3],\
    \ ans);\n    assert(cmp(d, 1.788854382) == 0);\n    assert(ans == Point(3.2, 4.6));\n\
    \n    d = distToLineSegment(P[6], P[2], P[3], ans);\n    assert(cmp(d, 2) == 0);\n\
    \    assert(ans == Point(6, 6));\n\n    reflectionPoint(l4, P[1], ans);\n    assert(ans\
    \ == Point(0, 3));\n\n    assert(cmp(RAD_to_DEG(angle(P[0], P[4], P[3])), 90)\
    \ == 0);\n    assert(cmp(RAD_to_DEG(angle(P[0], P[2], P[1])), 63.434948823) ==\
    \ 0);\n    assert(cmp(RAD_to_DEG(angle(P[4], P[3], P[6])), 180) == 0);\n\n   \
    \ assert(ccw(P[0], P[2], P[3]) == -1);\n    assert(ccw(P[0], P[3], P[2]) == 1);\n\
    \n    assert(ccw(P[0], P[2], P[3]) != 0);\n    assert(ccw(P[0], P[2], P[4]) ==\
    \ 0);\n\n    Point p(3, 7), q(11, 13), r(35, 30);\n    assert(ccw(p, q, r) ==\
    \ -1);\n\n    /*\n    // the positions of these 6 points\n     E<--  4\n     \
    \      3       B D<--\n           2   A C\n           1\n    -4-3-2-1 0 1 2 3\
    \ 4 5 6\n          -1\n          -2\n    F<--   -3\n    */\n\n    // translation\n\
    \    Point A(2.0, 2.0);\n    Point B(4.0, 3.0);\n    Point v = B - A;\n\n    Point\
    \ C(3.0, 2.0);\n    Point D = C + v;\n    assert(D == Point(5, 3));\n    Point\
    \ E = C + v * 0.5;\n    assert(E == Point(4, 2.5));\n\n    // rotation\n    assert(B\
    \ == Point(4, 3));\n    Point F = B.rotate(DEG_to_RAD(90));\n    assert(F == Point(-3,\
    \ 4));\n    Point G = B.rotate(DEG_to_RAD(180));\n    assert(G == Point(-4, -3));\n\
    \n    cout << \"All tests passed\" << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  isVerificationFile: false
  path: Geometry/basic.cpp
  requiredBy: []
  timestamp: '2022-01-11 03:43:32+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/basic.cpp
layout: document
redirect_from:
- /library/Geometry/basic.cpp
- /library/Geometry/basic.cpp.html
title: Geometry/basic.cpp
---
