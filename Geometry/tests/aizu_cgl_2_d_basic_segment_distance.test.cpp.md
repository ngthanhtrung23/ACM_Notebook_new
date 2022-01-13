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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
  bundledCode: "#line 1 \"Geometry/tests/aizu_cgl_2_d_basic_segment_distance.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\"\
    \n\n#line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int\
    \ i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n\
    #define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\
    \n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n)\
    \ { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define\
    \ PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl;\
    \ }\n\n#define sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n//\
    \ Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
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
    \ (0, r-1)(rng);\n}\n\ntemplate<typename T>\nvector<T> read_vector(int n) {\n\
    \    vector<T> res(n);\n    for (int& x : res) cin >> x;\n    return res;\n}\n\
    \nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n  \
    \  solve();\n    return 0;\n}\n#line 2 \"Geometry/basic.h\"\n\n// Basic geometry\
    \ objects: Point, Line, Segment\n// Works with both integers and floating points\n\
    // Unless the problem has precision issue, can use Point, which uses double\n\
    // and has more functionalities.\n// For integers, can use P<long long>\n\n#ifndef\
    \ EPS  // allow test files to overwrite EPS\n#define EPS 1e-6\n#endif\n\nconst\
    \ double PI = acos(-1.0);\n\ndouble DEG_to_RAD(double d) { return d * PI / 180.0;\
    \ }\ndouble RAD_to_DEG(double r) { return r * 180.0 / PI; }\n\ninline int cmp(double\
    \ a, double b) {\n    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);\n}\n\
    \n// for int types\ntemplate<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type\
    \ * = nullptr>\ninline int cmp(T a, T b) {\n    return (a == b) ? 0 : (a < b)\
    \ ? -1 : 1;\n}\n\ntemplate<typename T>\nstruct P {\n    T x, y;\n    P() { x =\
    \ y = T(0); }\n    P(T _x, T _y) : x(_x), y(_y) {}\n\n    P operator + (const\
    \ P& a) const { return P(x+a.x, y+a.y); }\n    P operator - (const P& a) const\
    \ { return P(x-a.x, y-a.y); }\n    P operator * (T k) const { return P(x*k, y*k);\
    \ }\n    P<double> operator / (double k) const { return P(x/k, y/k); }\n\n   \
    \ T operator * (const P& a) const { return x*a.x + y*a.y; } // dot product\n \
    \   T operator % (const P& a) const { return x*a.y - y*a.x; } // cross product\n\
    \n    int cmp(const P<T>& q) const { if (int t = ::cmp(x,q.x)) return t; return\
    \ ::cmp(y,q.y); }\n\n    #define Comp(x) bool operator x (const P& q) const {\
    \ return cmp(q) x 0; }\n    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)\n\
    \    #undef Comp\n\n    T norm() { return x*x + y*y; }\n\n    // Note: There are\
    \ 2 ways for implementing len():\n    // 1. sqrt(norm()) --> fast, but inaccurate\
    \ (produce some values that are of order X^2)\n    // 2. hypot(x, y) --> slow,\
    \ but much more accurate\n    double len() { return hypot(x, y); }\n\n    P<double>\
    \ rotate(double alpha) {\n        double cosa = cos(alpha), sina = sin(alpha);\n\
    \        return P(x * cosa - y * sina, x * sina + y * cosa);\n    }\n};\nusing\
    \ Point = P<double>;\n\n// Compare points by (y, x)\ntemplate<typename T = double>\n\
    bool cmpy(const P<T>& a, const P<T>& b) {\n    if (cmp(a.y, b.y)) return a.y <\
    \ b.y;\n    return a.x < b.x;\n};\n\ntemplate<typename T>\nint ccw(P<T> a, P<T>\
    \ b, P<T> c) {\n    return cmp((b-a)%(c-a), T(0));\n}\n\nint RE_TRAI = ccw(Point(0,\
    \ 0), Point(0, 1), Point(-1, 1));\nint RE_PHAI = ccw(Point(0, 0), Point(0, 1),\
    \ Point(1, 1));\n\ntemplate<typename T>\nistream& operator >> (istream& cin, P<T>&\
    \ p) {\n    cin >> p.x >> p.y;\n    return cin;\n}\ntemplate<typename T>\nostream&\
    \ operator << (ostream& cout, const P<T>& p) {\n    cout << p.x << ' ' << p.y;\n\
    \    return cout;\n}\n\ndouble angle(Point a, Point o, Point b) { // min of directed\
    \ angle AOB & BOA\n    a = a - o; b = b - o;\n    return acos((a * b) / sqrt(a.norm())\
    \ / sqrt(b.norm()));\n}\n\ndouble directed_angle(Point a, Point o, Point b) {\
    \ // angle AOB, in range [0, 2*PI)\n    double t = -atan2(a.y - o.y, a.x - o.x)\n\
    \            + atan2(b.y - o.y, b.x - o.x);\n    while (t < 0) t += 2*PI;\n  \
    \  return t;\n}\n\n// Distance from p to Line ab (closest Point --> c)\n// i.e.\
    \ c is projection of p on AB\ndouble distToLine(Point p, Point a, Point b, Point\
    \ &c) {\n    Point ap = p - a, ab = b - a;\n    double u = (ap * ab) / ab.norm();\n\
    \    c = a + (ab * u);\n    return (p-c).len();\n}\n\n// Distance from p to segment\
    \ ab (closest Point --> c)\ndouble distToLineSegment(Point p, Point a, Point b,\
    \ Point &c) {\n    Point ap = p - a, ab = b - a;\n    double u = (ap * ab) / ab.norm();\n\
    \    if (u < 0.0) {\n        c = Point(a.x, a.y);\n        return (p - a).len();\n\
    \    }\n    if (u > 1.0) {\n        c = Point(b.x, b.y);\n        return (p -\
    \ b).len();\n    }\n    return distToLine(p, a, b, c);\n}\n\n// NOTE: WILL NOT\
    \ WORK WHEN a = b = 0.\nstruct Line {\n    double a, b, c;  // ax + by + c = 0\n\
    \    Point A, B;  // Added for polygon intersect line. Do not rely on assumption\
    \ that these are valid\n\n    Line(double _a, double _b, double _c) : a(_a), b(_b),\
    \ c(_c) {} \n\n    Line(Point _A, Point _B) : A(_A), B(_B) {\n        a = B.y\
    \ - A.y;\n        b = A.x - B.x;\n        c = - (a * A.x + b * A.y);\n    }\n\
    \    Line(Point P, double m) {\n        a = -m; b = 1;\n        c = -((a * P.x)\
    \ + (b * P.y));\n    }\n    double f(Point p) {\n        return a*p.x + b*p.y\
    \ + c;\n    }\n};\nostream& operator >> (ostream& cout, const Line& l) {\n   \
    \ cout << l.a << \"*x + \" << l.b << \"*y + \" << l.c;\n    return cout;\n}\n\n\
    bool areParallel(Line l1, Line l2) {\n    return cmp(l1.a*l2.b, l1.b*l2.a) ==\
    \ 0;\n}\n\nbool areSame(Line l1, Line l2) {\n    return areParallel(l1 ,l2) &&\
    \ cmp(l1.c*l2.a, l2.c*l1.a) == 0\n                && cmp(l1.c*l2.b, l1.b*l2.c)\
    \ == 0;\n}\n\nbool areIntersect(Line l1, Line l2, Point &p) {\n    if (areParallel(l1,\
    \ l2)) return false;\n    double dx = l1.b*l2.c - l2.b*l1.c;\n    double dy =\
    \ l1.c*l2.a - l2.c*l1.a;\n    double d  = l1.a*l2.b - l2.a*l1.b;\n    p = Point(dx/d,\
    \ dy/d);\n    return true;\n}\n\n// closest point from p in line l.\nvoid closestPoint(Line\
    \ l, Point p, Point &ans) {\n    if (fabs(l.b) < EPS) {\n        ans.x = -(l.c)\
    \ / l.a; ans.y = p.y;\n        return;\n    }\n    if (fabs(l.a) < EPS) {\n  \
    \      ans.x = p.x; ans.y = -(l.c) / l.b;\n        return;\n    }\n    Line perp(l.b,\
    \ -l.a, - (l.b*p.x - l.a*p.y));\n    areIntersect(l, perp, ans);\n}\n\n// Segment\
    \ intersect\n// Tested:\n// - https://cses.fi/problemset/task/2190/\n// returns\
    \ true if p is on segment [a, b]\ntemplate<typename T>\nbool onSegment(const P<T>&\
    \ a, const P<T>& b, const P<T>& p) {\n    return ccw(a, b, p) == 0\n        &&\
    \ min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)\n        && min(a.y, b.y) <= p.y\
    \ && p.y <= max(a.y, b.y);\n}\n\n// Returns true if segment [a, b] and [c, d]\
    \ intersects\n// End point also returns true\ntemplate<typename T>\nbool segmentIntersect(const\
    \ P<T>& a, const P<T>& b, const P<T>& c, const P<T>& d) {\n    if (onSegment(a,\
    \ b, c)\n            || onSegment(a, b, d)\n            || onSegment(c, d, a)\n\
    \            || onSegment(c, d, b)) {\n        return true;\n    }\n\n    return\
    \ ccw(a, b, c) * ccw(a, b, d) < 0\n        && ccw(c, d, a) * ccw(c, d, b) < 0;\n\
    }\n#line 5 \"Geometry/tests/aizu_cgl_2_d_basic_segment_distance.test.cpp\"\n\n\
    void solve() {\n    int q; cin >> q;\n    cout << (fixed) << setprecision(10);\n\
    \    while (q--) {\n        Point a, b; cin >> a >> b;\n        Point c, d; cin\
    \ >> c >> d;\n        Point t;\n\n        if (segmentIntersect(a, b, c, d)) cout\
    \ << 0.0 << endl;\n        else {\n            cout << min({\n               \
    \     distToLineSegment(a, c, d, t),\n                    distToLineSegment(b,\
    \ c, d, t),\n                    distToLineSegment(c, a, b, t),\n            \
    \        distToLineSegment(d, a, b, t)\n            }) << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\"\
    \n\n#include \"../../template.h\"\n#include \"../basic.h\"\n\nvoid solve() {\n\
    \    int q; cin >> q;\n    cout << (fixed) << setprecision(10);\n    while (q--)\
    \ {\n        Point a, b; cin >> a >> b;\n        Point c, d; cin >> c >> d;\n\
    \        Point t;\n\n        if (segmentIntersect(a, b, c, d)) cout << 0.0 <<\
    \ endl;\n        else {\n            cout << min({\n                    distToLineSegment(a,\
    \ c, d, t),\n                    distToLineSegment(b, c, d, t),\n            \
    \        distToLineSegment(c, a, b, t),\n                    distToLineSegment(d,\
    \ a, b, t)\n            }) << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  isVerificationFile: true
  path: Geometry/tests/aizu_cgl_2_d_basic_segment_distance.test.cpp
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Geometry/tests/aizu_cgl_2_d_basic_segment_distance.test.cpp
layout: document
redirect_from:
- /verify/Geometry/tests/aizu_cgl_2_d_basic_segment_distance.test.cpp
- /verify/Geometry/tests/aizu_cgl_2_d_basic_segment_distance.test.cpp.html
title: Geometry/tests/aizu_cgl_2_d_basic_segment_distance.test.cpp
---
