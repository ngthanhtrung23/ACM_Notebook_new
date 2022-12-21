---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/basic.h
    title: Geometry/basic.h
  - icon: ':heavy_check_mark:'
    path: Geometry/polygon.h
    title: Geometry/polygon.h
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "#line 1 \"Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
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
    \n// for int types\ntemplate<typename T, typename std::enable_if<!std::is_floating_point<T>::value>::type\
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
    }\n#line 1 \"Geometry/polygon.h\"\n// Polygon: convex hull, in polygon, convex\
    \ diameter ..\n// Functions with param vector<P<T>> works with both integers and\
    \ floating points\n// Functions with param Polygon works with floating points\
    \ only.\n\ntypedef vector< Point > Polygon;\n\n// Convex Hull:\n// If minimum\
    \ point --> #define REMOVE_REDUNDANT\n// Known issues:\n// - Max. point does not\
    \ work when some points are the same.\n// Tested:\n// - (min points) https://open.kattis.com/problems/convexhull\n\
    // - (max points) https://cses.fi/problemset/task/2195\n\n// #define REMOVE_REDUNDANT\n\
    template<typename T>\nT area2(P<T> a, P<T> b, P<T> c) { return a%b + b%c + c%a;\
    \ }\n\ntemplate<typename T>\nvoid ConvexHull(vector<P<T>> &pts) {\n    sort(pts.begin(),\
    \ pts.end());\n    pts.erase(unique(pts.begin(), pts.end()), pts.end());\n   \
    \ vector<P<T>> up, dn;\n    for (int i = 0; i < (int) pts.size(); i++) {\n#ifdef\
    \ REMOVE_REDUNDANT\n        while (up.size() > 1 && area2(up[up.size()-2], up.back(),\
    \ pts[i]) >= 0) up.pop_back();\n        while (dn.size() > 1 && area2(dn[dn.size()-2],\
    \ dn.back(), pts[i]) <= 0) dn.pop_back();\n#else\n        while (up.size() > 1\
    \ && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();\n        while\
    \ (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();\n\
    #endif\n        up.push_back(pts[i]);\n        dn.push_back(pts[i]);\n    }\n\
    \    pts = dn;\n    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);\n\
    \    \n#ifdef REMOVE_REDUNDANT\n    if (pts.size() <= 2) return;\n    dn.clear();\n\
    \    dn.push_back(pts[0]);\n    dn.push_back(pts[1]);\n    for (int i = 2; i <\
    \ (int) pts.size(); i++) {\n        if (onSegment(dn[dn.size()-2], pts[i], dn.back()))\
    \ dn.pop_back();\n        dn.push_back(pts[i]);\n    }\n    if (dn.size() >= 3\
    \ && onSegment(dn.back(), dn[1], dn[0])) {\n        dn[0] = dn.back();\n     \
    \   dn.pop_back();\n    }\n    pts = dn;\n#endif\n}\n\n// Area, perimeter, centroid\n\
    template<typename T>\nT signed_area2(vector<P<T>> p) {\n    T area(0);\n    for(int\
    \ i = 0; i < (int) p.size(); i++) {\n        area += p[i] % p[(i + 1) % p.size()];\n\
    \    }\n    return area;\n}\ndouble area(const Polygon &p) {\n    return std::abs(signed_area2(p)\
    \ / 2.0);\n}\nPoint centroid(Polygon p) {\n    Point c(0,0);\n    double scale\
    \ = 3.0 * signed_area2(p);\n    for (int i = 0; i < (int) p.size(); i++){\n  \
    \      int j = (i+1) % p.size();\n        c = c + (p[i]+p[j])*(p[i].x*p[j].y -\
    \ p[j].x*p[i].y);\n    }\n    return c / scale;\n}\ndouble perimeter(Polygon p)\
    \ {\n    double res = 0;\n    for(int i = 0; i < (int) p.size(); ++i) {\n    \
    \    int j = (i + 1) % p.size();\n        res += (p[i] - p[j]).len();\n    }\n\
    \    return res;\n}\n\n// Is convex: checks if polygon is convex.\n// Return true\
    \ for degen points (all vertices are collinear)\ntemplate<typename T>\nbool is_convex(const\
    \ vector<P<T>> &P) {\n    int sz = (int) P.size();\n    int min_ccw = 2, max_ccw\
    \ = -2;\n    for (int i = 0; i < sz; i++) {\n        int c = ccw(P[i], P[(i+1)\
    \ % sz], P[(i+2) % sz]);\n        min_ccw = min(min_ccw, c);\n        max_ccw\
    \ = max(max_ccw, c);\n    }\n    return min_ccw * max_ccw >= 0;\n}\n\n// Inside\
    \ polygon: O(N). Works with any polygon\n// Tested:\n// - https://open.kattis.com/problems/pointinpolygon\n\
    // - https://open.kattis.com/problems/cuttingpolygon\nenum PolygonLocation { OUT,\
    \ ON, IN };\nPolygonLocation in_polygon(const Polygon &p, Point q) {\n    if ((int)p.size()\
    \ == 0) return PolygonLocation::OUT;\n\n    // Check if point is on edge.\n  \
    \  int n = p.size();\n    REP(i,n) {\n        int j = (i + 1) % n;\n        Point\
    \ u = p[i], v = p[j];\n\n        if (u > v) swap(u, v);\n\n        if (ccw(u,\
    \ v, q) == 0 && u <= q && q <= v) return PolygonLocation::ON;\n    }\n\n    //\
    \ Check if point is strictly inside.\n    int c = 0;\n    for (int i = 0; i <\
    \ n; i++) {\n        int j = (i + 1) % n;\n        if (((p[i].y <= q.y && q.y\
    \ < p[j].y)\n                    || (p[j].y <= q.y && q.y < p[i].y))\n       \
    \         && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (double) (p[j].y\
    \ - p[i].y)) {\n            c = !c;\n        }\n    }\n    return c ? PolygonLocation::IN\
    \ : PolygonLocation::OUT;\n}\n\n// Check point in convex polygon, O(logN)\n#define\
    \ Det(a,b,c) ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))\n\
    PolygonLocation in_convex(vector<Point>& l, Point p){\n    int a = 1, b = l.size()-1,\
    \ c;\n    if (Det(l[0], l[a], l[b]) > 0) swap(a,b);\n\n    if (onSegment(l[0],\
    \ l[a], p)) return ON;\n    if (onSegment(l[0], l[b], p)) return ON;\n\n    if\
    \ (Det(l[0], l[a], p) > 0 || Det(l[0], l[b], p) < 0) return OUT;\n    while(abs(a-b)\
    \ > 1) {\n        c = (a+b)/2;\n        if (Det(l[0], l[c], p) > 0) b = c; else\
    \ a = c;\n    }\n    int t = cmp(Det(l[a], l[b], p), 0);\n    return (t == 0)\
    \ ? ON : (t < 0) ? IN : OUT;\n}\n\n\n// Cut a polygon with a line. Returns half\
    \ on left-hand-side.\n// To return the other half, reverse the direction of Line\
    \ l (by negating l.a, l.b)\n// The line must be formed using 2 points\nPolygon\
    \ polygon_cut(const Polygon& P, Line l) {\n    Polygon Q;\n    for(int i = 0;\
    \ i < (int) P.size(); ++i) {\n        Point A = P[i], B = (i == ((int) P.size())-1)\
    \ ? P[0] : P[i+1];\n        if (ccw(l.A, l.B, A) != -1) Q.push_back(A);\n    \
    \    if (ccw(l.A, l.B, A)*ccw(l.A, l.B, B) < 0) {\n            Point p; areIntersect(Line(A,\
    \ B), l, p);\n            Q.push_back(p);\n        }\n    }\n    return Q;\n}\n\
    \n// Find intersection of 2 convex polygons\n// Helper method\nbool intersect_1pt(Point\
    \ a, Point b,\n    Point c, Point d, Point &r) {\n    double D =  (b - a) % (d\
    \ - c);\n    if (cmp(D, 0) == 0) return false;\n    double t =  ((c - a) % (d\
    \ - c)) / D;\n    double s = -((a - c) % (b - a)) / D;\n    r = a + (b - a) *\
    \ t;\n    return cmp(t, 0) >= 0 && cmp(t, 1) <= 0 && cmp(s, 0) >= 0 && cmp(s,\
    \ 1) <= 0;\n}\nPolygon convex_intersect(Polygon P, Polygon Q) {\n    const int\
    \ n = P.size(), m = Q.size();\n    int a = 0, b = 0, aa = 0, ba = 0;\n    enum\
    \ { Pin, Qin, Unknown } in = Unknown;\n    Polygon R;\n    do {\n        int a1\
    \ = (a+n-1) % n, b1 = (b+m-1) % m;\n        double C = (P[a] - P[a1]) % (Q[b]\
    \ - Q[b1]);\n        double A = (P[a1] - Q[b]) % (P[a] - Q[b]);\n        double\
    \ B = (Q[b1] - P[a]) % (Q[b] - P[a]);\n        Point r;\n        if (intersect_1pt(P[a1],\
    \ P[a], Q[b1], Q[b], r)) {\n            if (in == Unknown) aa = ba = 0;\n    \
    \        R.push_back( r );\n            in = B > 0 ? Pin : A > 0 ? Qin : in;\n\
    \        }\n        if (C == 0 && B == 0 && A == 0) {\n            if (in == Pin)\
    \ { b = (b + 1) % m; ++ba; }\n            else            { a = (a + 1) % m; ++aa;\
    \ }\n        } else if (C >= 0) {\n            if (A > 0) { if (in == Pin) R.push_back(P[a]);\
    \ a = (a+1)%n; ++aa; }\n            else       { if (in == Qin) R.push_back(Q[b]);\
    \ b = (b+1)%m; ++ba; }\n        } else {\n            if (B > 0) { if (in == Qin)\
    \ R.push_back(Q[b]); b = (b+1)%m; ++ba; }\n            else       { if (in ==\
    \ Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }\n        }\n    } while ( (aa <\
    \ n || ba < m) && aa < 2*n && ba < 2*m );\n    if (in == Unknown) {\n        if\
    \ (in_convex(Q, P[0])) return P;\n        if (in_convex(P, Q[0])) return Q;\n\
    \    }\n    return R;\n}\n\n// Find the diameter of polygon.\n// Returns:\n//\
    \ <diameter, <ids of 2 points>>\npair<double, pair<int,int>> convex_diameter(const\
    \ Polygon &p) {\n    const int n = p.size();\n    int is = 0, js = 0;\n    for\
    \ (int i = 1; i < n; ++i) {\n        if (p[i].y > p[is].y) is = i;\n        if\
    \ (p[i].y < p[js].y) js = i;\n    }\n    double maxd = (p[is]-p[js]).len();\n\
    \    int i, maxi, j, maxj;\n    i = maxi = is;\n    j = maxj = js;\n    do {\n\
    \        int ii = (i+1) % n, jj = (j+1) % n;\n        if ((p[ii] - p[i]) % (p[jj]\
    \ - p[j]) >= 0) j = jj;\n        else i = ii;\n        if ((p[i] - p[j]).len()\
    \ > maxd) {\n            maxd = (p[i] - p[j]).len();\n            maxi = i;\n\
    \            maxj = j;\n        }\n    } while (i != is || j != js);\n    return\
    \ {maxd, std::minmax(maxi, maxj)}; /* farthest pair is (maxi, maxj). */\n}\n\n\
    // Pick theorem\n// Given non-intersecting polygon.\n// S = area\n// I = number\
    \ of integer points strictly Inside\n// B = number of points on sides of polygon\n\
    // S = I + B/2 - 1\n#line 6 \"Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp\"\
    \n\nvoid solve() {\n    int n; cin >> n;\n    Polygon g(n);\n    for (auto& p\
    \ : g) cin >> p;\n    ConvexHull(g);\n    int idx = 0;\n    FOR(i,1,n-1) if (cmpy(g[i],\
    \ g[idx])) idx = i;\n\n    cout << g.size() << endl;\n    REP(i,g.size()) cout\
    \ << (fixed) << setprecision(0) << g[(idx + i) % g.size()] << '\\n';\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n\n#include \"../../template.h\"\n#include \"../basic.h\"\n#include \"../polygon.h\"\
    \n\nvoid solve() {\n    int n; cin >> n;\n    Polygon g(n);\n    for (auto& p\
    \ : g) cin >> p;\n    ConvexHull(g);\n    int idx = 0;\n    FOR(i,1,n-1) if (cmpy(g[i],\
    \ g[idx])) idx = i;\n\n    cout << g.size() << endl;\n    REP(i,g.size()) cout\
    \ << (fixed) << setprecision(0) << g[(idx + i) % g.size()] << '\\n';\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  - Geometry/polygon.h
  isVerificationFile: true
  path: Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp
  requiredBy: []
  timestamp: '2022-02-06 13:43:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp
layout: document
redirect_from:
- /verify/Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp
- /verify/Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp.html
title: Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp
---
