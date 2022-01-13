---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Geometry/basic.h
    title: Geometry/basic.h
  - icon: ':heavy_check_mark:'
    path: Geometry/circle.h
    title: Geometry/circle.h
  - icon: ':warning:'
    path: Geometry/smallestEnclosingCircle.h
    title: Geometry/smallestEnclosingCircle.h
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
    }\n#line 1 \"Geometry/circle.h\"\nstruct Circle : Point {\n    double r;\n   \
    \ Circle(double _x = 0, double _y = 0, double _r = 0) : Point(_x, _y), r(_r) {}\n\
    \    Circle(Point p, double _r) : Point(p), r(_r) {}\n    \n    bool contains(Point\
    \ p) { return (*this - p).len() <= r + EPS; }\n\n    double area() const { return\
    \ r*r*M_PI; }\n\n    // definitions in https://en.wikipedia.org/wiki/Circle\n\
    \    // assumption: 0 <= theta <= 2*PI\n    // theta: angle in radian\n    double\
    \ sector_area(double theta) const {\n        return 0.5 * r * r * theta;\n   \
    \ }\n\n    // assumption: 0 <= theta <= 2*PI\n    // theta: angle in radian\n\
    \    double segment_area(double theta) const {\n        return 0.5 * r * r * (theta\
    \ - sin(theta));\n    }\n};\nistream& operator >> (istream& cin, Circle& c) {\n\
    \    cin >> c.x >> c.y >> c.r;\n    return cin;\n}\nostream& operator << (ostream&\
    \ cout, const Circle& c) {\n    cout << '(' << c.x << \", \" << c.y << \") \"\
    \ << c.r;\n    return cout;\n}\n\n// Find common tangents to 2 circles\n// Tested:\n\
    // - http://codeforces.com/gym/100803/ - H\n// Helper method\nvoid tangents(Point\
    \ c, double r1, double r2, vector<Line> & ans) {\n    double r = r2 - r1;\n  \
    \  double z = sqr(c.x) + sqr(c.y);\n    double d = z - sqr(r);\n    if (d < -EPS)\
    \  return;\n    d = sqrt(fabs(d));\n    Line l((c.x * r + c.y * d) / z,\n    \
    \        (c.y * r - c.x * d) / z,\n            r1);\n    ans.push_back(l);\n}\n\
    // Actual method: returns vector containing all common tangents\nvector<Line>\
    \ tangents(Circle a, Circle b) {\n    vector<Line> ans; ans.clear();\n    for\
    \ (int i=-1; i<=1; i+=2)\n        for (int j=-1; j<=1; j+=2)\n            tangents(b-a,\
    \ a.r*i, b.r*j, ans);\n    for(int i = 0; i < (int) ans.size(); ++i)\n       \
    \ ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;\n\n    vector<Line> ret;\n    for(int\
    \ i = 0; i < (int) ans.size(); ++i) {\n        if (std::none_of(ret.begin(), ret.end(),\
    \ [&] (Line l) { return areSame(l, ans[i]); })) {\n            ret.push_back(ans[i]);\n\
    \        }\n    }\n    return ret;\n}\n\n// Circle & line intersection\n// Tested:\n\
    // - http://codeforces.com/gym/100803/ - H\nvector<Point> intersection(Line l,\
    \ Circle cir) {\n    double r = cir.r, a = l.a, b = l.b, c = l.c + l.a*cir.x +\
    \ l.b*cir.y;\n    vector<Point> res;\n\n    double x0 = -a*c/(a*a+b*b),  y0 =\
    \ -b*c/(a*a+b*b);\n    if (c*c > r*r*(a*a+b*b)+EPS) return res;\n    else if (fabs(c*c\
    \ - r*r*(a*a+b*b)) < EPS) {\n        res.push_back(Point(x0, y0) + Point(cir.x,\
    \ cir.y));\n        return res;\n    } else {\n        double d = r*r - c*c/(a*a+b*b);\n\
    \        double mult = sqrt (d / (a*a+b*b));\n        double ax,ay,bx,by;\n  \
    \      ax = x0 + b * mult;\n        bx = x0 - b * mult;\n        ay = y0 - a *\
    \ mult;\n        by = y0 + a * mult;\n\n        res.push_back(Point(ax, ay) +\
    \ Point(cir.x, cir.y));\n        res.push_back(Point(bx, by) + Point(cir.x, cir.y));\n\
    \        return res;\n    }\n}\n\n// helper functions for commonCircleArea\ndouble\
    \ cir_area_solve(double a, double b, double c) {\n    return acos((a*a + b*b -\
    \ c*c) / 2 / a / b);\n}\ndouble cir_area_cut(double a, double r) {\n    double\
    \ s1 = a * r * r / 2;\n    double s2 = sin(a) * r * r / 2;\n    return s1 - s2;\n\
    }\n// Tested: http://codeforces.com/contest/600/problem/D\ndouble commonCircleArea(Circle\
    \ c1, Circle c2) { //return the common area of two circle\n    if (c1.r < c2.r)\
    \ swap(c1, c2);\n    double d = (c1 - c2).len();\n    if (d + c2.r <= c1.r + EPS)\
    \ return c2.r*c2.r*M_PI;\n    if (d >= c1.r + c2.r - EPS) return 0.0;\n    double\
    \ a1 = cir_area_solve(d, c1.r, c2.r);\n    double a2 = cir_area_solve(d, c2.r,\
    \ c1.r);\n    return cir_area_cut(a1*2, c1.r) + cir_area_cut(a2*2, c2.r);\n}\n\
    \n// Check if 2 circle intersects. Return true if 2 circles touch\nbool areIntersect(Circle\
    \ u, Circle v) {\n    if (cmp((u - v).len(), u.r + v.r) > 0) return false;\n \
    \   if (cmp((u - v).len() + v.r, u.r) < 0) return false;\n    if (cmp((u - v).len()\
    \ + u.r, v.r) < 0) return false;\n    return true;\n}\n\n// If 2 circle touches,\
    \ will return 2 (same) points\n// If 2 circle are same --> be careful\n// Tested:\n\
    // - http://codeforces.com/gym/100803/ - H\n// - http://codeforces.com/gym/100820/\
    \ - I\nvector<Point> circleIntersect(Circle u, Circle v) {\n    vector<Point>\
    \ res;\n    if (!areIntersect(u, v)) return res;\n    double d = (u - v).len();\n\
    \    double alpha = acos((u.r * u.r + d*d - v.r * v.r) / 2.0 / u.r / d);\n\n \
    \   Point p1 = (v - u).rotate(alpha);\n    Point p2 = (v - u).rotate(-alpha);\n\
    \    res.push_back(p1 / p1.len() * u.r + u);\n    res.push_back(p2 / p2.len()\
    \ * u.r + u);\n    return res;\n}\n#line 1 \"Geometry/smallestEnclosingCircle.h\"\
    \n// Smallest enclosing circle:\n// Given N points. Find the smallest circle enclosing\
    \ these points.\n// Amortized complexity: O(N)\n//\n// Tested:\n// - https://www.spoj.com/problems/ALIENS/\n\
    // - https://www.spoj.com/problems/QCJ4/\n// - https://www.acmicpc.net/problem/2626\n\
    \nstruct SmallestEnclosingCircle {\n    Circle getCircle(vector<Point> points)\
    \ {\n        assert(!points.empty());\n\n        random_shuffle(points.begin(),\
    \ points.end());\n        Circle c(points[0], 0);\n        int n = points.size();\n\
    \n        for (int i = 1; i < n; i++)\n            if ((points[i] - c).len() >\
    \ c.r + EPS)\n            {\n                c = Circle(points[i], 0);\n     \
    \           for (int j = 0; j < i; j++)\n                    if ((points[j] -\
    \ c).len() > c.r + EPS)\n                    {\n                        c = Circle((points[i]\
    \ + points[j]) / 2, (points[i] - points[j]).len() / 2);\n                    \
    \    for (int k = 0; k < j; k++)\n                            if ((points[k] -\
    \ c).len() > c.r + EPS)\n                                c = getCircumcircle(points[i],\
    \ points[j], points[k]);\n                    }\n            }\n\n        return\
    \ c;\n    }\n\n    // NOTE: This code work only when a, b, c are not collinear\
    \ and no 2 points are same --> DO NOT\n    // copy and use in other cases.\n \
    \   Circle getCircumcircle(Point a, Point b, Point c) {\n        assert(a != b\
    \ && b != c && a != c);\n        assert(ccw(a, b, c));\n\n        double d = 2.0\
    \ * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));\n        assert(fabs(d)\
    \ > EPS);\n        double x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y)\
    \ + c.norm() * (a.y - b.y)) / d;\n        double y = (a.norm() * (c.x - b.x) +\
    \ b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x)) / d;\n        Point p(x, y);\n\
    \        return Circle(p, (p - a).len());\n    }\n};\n#line 5 \"Geometry/SPOJ_ALIENS.cpp\"\
    \n\nint main()\n{\n    int test, n;\n    double x, y;\n\n    cin >> test;\n  \
    \  while (test--) {\n        cin >> n;\n        vector<Point> points;\n      \
    \  while (n--) {\n            scanf(\"%lf%lf\", &x, &y);\n            points.push_back(Point(x,\
    \ y));\n        }\n\n        SmallestEnclosingCircle scc;\n        Circle c =\
    \ scc.getCircle(points);\n        printf(\"%.2lf\\n%.2lf %.2lf\\n\", c.r, c.x,\
    \ c.y);\n    }\n}\n\n"
  code: "#include \"../template.h\"\n#include \"basic.h\"\n#include \"circle.h\"\n\
    #include \"smallestEnclosingCircle.h\"\n\nint main()\n{\n    int test, n;\n  \
    \  double x, y;\n\n    cin >> test;\n    while (test--) {\n        cin >> n;\n\
    \        vector<Point> points;\n        while (n--) {\n            scanf(\"%lf%lf\"\
    , &x, &y);\n            points.push_back(Point(x, y));\n        }\n\n        SmallestEnclosingCircle\
    \ scc;\n        Circle c = scc.getCircle(points);\n        printf(\"%.2lf\\n%.2lf\
    \ %.2lf\\n\", c.r, c.x, c.y);\n    }\n}\n\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  - Geometry/circle.h
  - Geometry/smallestEnclosingCircle.h
  isVerificationFile: false
  path: Geometry/SPOJ_ALIENS.cpp
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/SPOJ_ALIENS.cpp
layout: document
redirect_from:
- /library/Geometry/SPOJ_ALIENS.cpp
- /library/Geometry/SPOJ_ALIENS.cpp.html
title: Geometry/SPOJ_ALIENS.cpp
---
