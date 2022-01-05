---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Misc/local_search.cpp\"\n// Problem: \n// Find P to minimize\
    \ PA + PB + PC.\n\n#include <sstream>\n#include <fstream>\n#include <cassert>\n\
    #include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <cmath>\n\
    #include <iostream>\n#include <iomanip>\n#include <algorithm>\n#include <vector>\n\
    #include <set>\n#include <stack>\n#include <map>\n#include <string>\n#include\
    \ <queue>\n#include <bitset>\nusing namespace std;\n\n#define int long long\n\
    #define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n#define FORD(i,\
    \ a, b) for (int i = (a), _##i = (b); i >= _##i; --i)\n#define REP(i, a) for (int\
    \ i = 0, _##i = (a); i < _##i; ++i)\n#define REPD(i,n) for(int i = (n)-1; i >=\
    \ 0; --i)\n\n#define DEBUG(X) { cerr << #X << \" = \" << (X) << endl; }\n#define\
    \ PR(A, n) { cerr << #A << \" = \"; FOR(_, 1, n) cerr << A[_] << ' '; cerr <<\
    \ endl; }\n#define PR0(A, n) { cerr << #A << \" = \"; REP(_, n) cerr << A[_] <<\
    \ ' '; cerr << endl; }\n\n#define sqr(x) ((x) * (x))\n#define ll long long\n#define\
    \ double long double\ntypedef pair<int, int> II;\n#define __builtin_popcount __builtin_popcountll\n\
    #define SZ(x) ((int)(x).size())\n#define ALL(a) (a).begin(), (a).end()\n#define\
    \ MS(a,x) memset(a, x, sizeof(a))\n#define next ackjalscjaowjico\n#define prev\
    \ ajcsoua0wucckjsl\n#define y1 alkscj9u20cjeijc\n#define left lajcljascjljl\n\
    #define right aucouasocjolkjl\n#define y0 u9cqu3jioajc\n\n#define TWO(X) (1LL<<(X))\n\
    #define CONTAIN(S,X) ((S) & TWO(X))\n\nint rand16() {\n    return rand() & (TWO(16)\
    \ - 1);\n}\nint my_rand() {\n    return rand16() << 32 | rand16() << 16 | rand16();\n\
    }\n\ndouble safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }\nint GI(int&\
    \ x) { return scanf(\"%lld\", &x); }\n\n#define EPS 1e-6\nconst double PI = acos(-1.0);\n\
    \ndouble DEG_to_RAD(double d) { return d * PI / 180.0; }\ndouble RAD_to_DEG(double\
    \ r) { return r * 180.0 / PI; }\n\ninline int cmp(double a, double b) {\n    return\
    \ (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);\n}\n\nstruct Point {\n    double\
    \ x, y;\n    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}\n\n    Point\
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
    \ 2. hypot(x, y) --> slow, but much more accurate\n    double len() { return hypot(x,\
    \ y); }\n\n    Point rotate(double alpha) {\n        double cosa = cos(alpha),\
    \ sina = sin(alpha);\n        return Point(x * cosa - y * sina, x * sina + y *\
    \ cosa);\n    }\n};\n\nint ccw(Point a, Point b, Point c) {\n    return cmp((b-a)%(c-a),0);\n\
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
    \ assumption that these are valid\n\n    Line(double a, double b, double c) :\
    \ a(a), b(b), c(c) {} \n\n    Line(Point A, Point B) : A(A), B(B) {\n        a\
    \ = B.y - A.y;\n        b = A.x - B.x;\n        c = - (a * A.x + b * A.y);\n \
    \   }\n    Line(Point P, double m) {\n        a = -m; b = 1;\n        c = -((a\
    \ * P.x) + (b * P.y));\n    }\n    double f(Point A) {\n        return a*A.x +\
    \ b*A.y + c;\n    }\n};\n\nbool areParallel(Line l1, Line l2) {\n    return cmp(l1.a*l2.b,\
    \ l1.b*l2.a) == 0;\n}\n\nbool areSame(Line l1, Line l2) {\n    return areParallel(l1\
    \ ,l2) && cmp(l1.c*l2.a, l2.c*l1.a) == 0\n                && cmp(l1.c*l2.b, l1.b*l2.c)\
    \ == 0;\n}\n\nbool areIntersect(Line l1, Line l2, Point &p) {\n    if (areParallel(l1,\
    \ l2)) return false;\n    double dx = l1.b*l2.c - l2.b*l1.c;\n    double dy =\
    \ l1.c*l2.a - l2.c*l1.a;\n    double d  = l1.a*l2.b - l2.a*l1.b;\n    p = Point(dx/d,\
    \ dy/d);\n    return true;\n}\n\nvoid closestPoint(Line l, Point p, Point &ans)\
    \ {\n    if (fabs(l.b) < EPS) {\n        ans.x = -(l.c) / l.a; ans.y = p.y;\n\
    \        return;\n    }\n    if (fabs(l.a) < EPS) {\n        ans.x = p.x; ans.y\
    \ = -(l.c) / l.b;\n        return;\n    }\n    Line perp(l.b, -l.a, - (l.b*p.x\
    \ - l.a*p.y));\n    areIntersect(l, perp, ans);\n}\n\nvoid reflectionPoint(Line\
    \ l, Point p, Point &ans) {\n    Point b;\n    closestPoint(l, p, b);\n    ans\
    \ = p + (b - p) * 2;\n}\n\nPoint A, B, C;\ndouble f(Point P) {\n    return (P\
    \ - A).len() + (P - B).len() + (P - C).len();\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0);\n\
    \    cin.tie(0);\n    cout << (fixed) << setprecision(9) << boolalpha;\n    cin\
    \ >> A >> B >> C;\n\n    Point P = A;\n    double len = 2000;\n    REP(turn,10000)\
    \ {\n        Point dir(0, len);\n\n        const int NANGLE = 100;\n        Point\
    \ best = P;\n        double best_value = f(best);\n\n        REP(angle,NANGLE)\
    \ {\n            Point Q = P + dir;\n            double cur = f(Q);\n        \
    \    if (cur < best_value) {\n                best_value = cur;\n            \
    \    best = Q;\n            }\n\n            dir = dir.rotate(2 * PI / NANGLE);\n\
    \        }\n\n        P = best;\n        len *= 0.99;\n    }\n    cout << P <<\
    \ endl;\n    return 0;\n}\n\n"
  code: "// Problem: \n// Find P to minimize PA + PB + PC.\n\n#include <sstream>\n\
    #include <fstream>\n#include <cassert>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <cmath>\n#include <iostream>\n#include <iomanip>\n\
    #include <algorithm>\n#include <vector>\n#include <set>\n#include <stack>\n#include\
    \ <map>\n#include <string>\n#include <queue>\n#include <bitset>\nusing namespace\
    \ std;\n\n#define int long long\n#define FOR(i, a, b) for (int i = (a), _##i =\
    \ (b); i <= _##i; ++i)\n#define FORD(i, a, b) for (int i = (a), _##i = (b); i\
    \ >= _##i; --i)\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\
    #define REPD(i,n) for(int i = (n)-1; i >= 0; --i)\n\n#define DEBUG(X) { cerr <<\
    \ #X << \" = \" << (X) << endl; }\n#define PR(A, n) { cerr << #A << \" = \"; FOR(_,\
    \ 1, n) cerr << A[_] << ' '; cerr << endl; }\n#define PR0(A, n) { cerr << #A <<\
    \ \" = \"; REP(_, n) cerr << A[_] << ' '; cerr << endl; }\n\n#define sqr(x) ((x)\
    \ * (x))\n#define ll long long\n#define double long double\ntypedef pair<int,\
    \ int> II;\n#define __builtin_popcount __builtin_popcountll\n#define SZ(x) ((int)(x).size())\n\
    #define ALL(a) (a).begin(), (a).end()\n#define MS(a,x) memset(a, x, sizeof(a))\n\
    #define next ackjalscjaowjico\n#define prev ajcsoua0wucckjsl\n#define y1 alkscj9u20cjeijc\n\
    #define left lajcljascjljl\n#define right aucouasocjolkjl\n#define y0 u9cqu3jioajc\n\
    \n#define TWO(X) (1LL<<(X))\n#define CONTAIN(S,X) ((S) & TWO(X))\n\nint rand16()\
    \ {\n    return rand() & (TWO(16) - 1);\n}\nint my_rand() {\n    return rand16()\
    \ << 32 | rand16() << 16 | rand16();\n}\n\ndouble safe_sqrt(double x) { return\
    \ sqrt(max((double)0.0, x)); }\nint GI(int& x) { return scanf(\"%lld\", &x); }\n\
    \n#define EPS 1e-6\nconst double PI = acos(-1.0);\n\ndouble DEG_to_RAD(double\
    \ d) { return d * PI / 180.0; }\ndouble RAD_to_DEG(double r) { return r * 180.0\
    \ / PI; }\n\ninline int cmp(double a, double b) {\n    return (a < b - EPS) ?\
    \ -1 : ((a > b + EPS) ? 1 : 0);\n}\n\nstruct Point {\n    double x, y;\n    Point(double\
    \ x = 0.0, double y = 0.0) : x(x), y(y) {}\n\n    Point operator + (const Point&\
    \ a) const { return Point(x+a.x, y+a.y); }\n    Point operator - (const Point&\
    \ a) const { return Point(x-a.x, y-a.y); }\n    Point operator * (double k) const\
    \ { return Point(x*k, y*k); }\n    Point operator / (double k) const { return\
    \ Point(x/k, y/k); }\n\n    double operator * (const Point& a) const { return\
    \ x*a.x + y*a.y; } // dot product\n    double operator % (const Point& a) const\
    \ { return x*a.y - y*a.x; } // cross product\n\n    int cmp(Point q) const { if\
    \ (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }\n\n    #define Comp(x)\
    \ bool operator x (Point q) const { return cmp(q) x 0; }\n    Comp(>) Comp(<)\
    \ Comp(==) Comp(>=) Comp(<=) Comp(!=)\n    #undef Comp\n\n    Point conj() { return\
    \ Point(x, -y); }\n    double norm() { return x*x + y*y; }\n\n    // Note: There\
    \ are 2 ways for implementing len():\n    // 1. sqrt(norm()) --> fast, but inaccurate\
    \ (produce some values that are of order X^2)\n    // 2. hypot(x, y) --> slow,\
    \ but much more accurate\n    double len() { return hypot(x, y); }\n\n    Point\
    \ rotate(double alpha) {\n        double cosa = cos(alpha), sina = sin(alpha);\n\
    \        return Point(x * cosa - y * sina, x * sina + y * cosa);\n    }\n};\n\n\
    int ccw(Point a, Point b, Point c) {\n    return cmp((b-a)%(c-a),0);\n}\nint RE_TRAI\
    \ = ccw(Point(0, 0), Point(0, 1), Point(-1, 1));\nint RE_PHAI = ccw(Point(0, 0),\
    \ Point(0, 1), Point(1, 1));\nistream& operator >> (istream& cin, Point& p) {\n\
    \    cin >> p.x >> p.y;\n    return cin;\n}\nostream& operator << (ostream& cout,\
    \ Point& p) {\n    cout << p.x << ' ' << p.y;\n    return cout;\n}\n\ndouble angle(Point\
    \ a, Point o, Point b) { // min of directed angle AOB & BOA\n    a = a - o; b\
    \ = b - o;\n    return acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));\n}\n\n\
    double directed_angle(Point a, Point o, Point b) { // angle AOB, in range [0,\
    \ 2*PI)\n    double t = -atan2(a.y - o.y, a.x - o.x)\n            + atan2(b.y\
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
    \ assumption that these are valid\n\n    Line(double a, double b, double c) :\
    \ a(a), b(b), c(c) {} \n\n    Line(Point A, Point B) : A(A), B(B) {\n        a\
    \ = B.y - A.y;\n        b = A.x - B.x;\n        c = - (a * A.x + b * A.y);\n \
    \   }\n    Line(Point P, double m) {\n        a = -m; b = 1;\n        c = -((a\
    \ * P.x) + (b * P.y));\n    }\n    double f(Point A) {\n        return a*A.x +\
    \ b*A.y + c;\n    }\n};\n\nbool areParallel(Line l1, Line l2) {\n    return cmp(l1.a*l2.b,\
    \ l1.b*l2.a) == 0;\n}\n\nbool areSame(Line l1, Line l2) {\n    return areParallel(l1\
    \ ,l2) && cmp(l1.c*l2.a, l2.c*l1.a) == 0\n                && cmp(l1.c*l2.b, l1.b*l2.c)\
    \ == 0;\n}\n\nbool areIntersect(Line l1, Line l2, Point &p) {\n    if (areParallel(l1,\
    \ l2)) return false;\n    double dx = l1.b*l2.c - l2.b*l1.c;\n    double dy =\
    \ l1.c*l2.a - l2.c*l1.a;\n    double d  = l1.a*l2.b - l2.a*l1.b;\n    p = Point(dx/d,\
    \ dy/d);\n    return true;\n}\n\nvoid closestPoint(Line l, Point p, Point &ans)\
    \ {\n    if (fabs(l.b) < EPS) {\n        ans.x = -(l.c) / l.a; ans.y = p.y;\n\
    \        return;\n    }\n    if (fabs(l.a) < EPS) {\n        ans.x = p.x; ans.y\
    \ = -(l.c) / l.b;\n        return;\n    }\n    Line perp(l.b, -l.a, - (l.b*p.x\
    \ - l.a*p.y));\n    areIntersect(l, perp, ans);\n}\n\nvoid reflectionPoint(Line\
    \ l, Point p, Point &ans) {\n    Point b;\n    closestPoint(l, p, b);\n    ans\
    \ = p + (b - p) * 2;\n}\n\nPoint A, B, C;\ndouble f(Point P) {\n    return (P\
    \ - A).len() + (P - B).len() + (P - C).len();\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0);\n\
    \    cin.tie(0);\n    cout << (fixed) << setprecision(9) << boolalpha;\n    cin\
    \ >> A >> B >> C;\n\n    Point P = A;\n    double len = 2000;\n    REP(turn,10000)\
    \ {\n        Point dir(0, len);\n\n        const int NANGLE = 100;\n        Point\
    \ best = P;\n        double best_value = f(best);\n\n        REP(angle,NANGLE)\
    \ {\n            Point Q = P + dir;\n            double cur = f(Q);\n        \
    \    if (cur < best_value) {\n                best_value = cur;\n            \
    \    best = Q;\n            }\n\n            dir = dir.rotate(2 * PI / NANGLE);\n\
    \        }\n\n        P = best;\n        len *= 0.99;\n    }\n    cout << P <<\
    \ endl;\n    return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/local_search.cpp
  requiredBy: []
  timestamp: '2017-11-07 23:55:24+05:30'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/local_search.cpp
layout: document
redirect_from:
- /library/Misc/local_search.cpp
- /library/Misc/local_search.cpp.html
title: Misc/local_search.cpp
---
