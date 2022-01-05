---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Geometry/basic.h
    title: Geometry/basic.h
  - icon: ':warning:'
    path: Geometry/polygon.h
    title: Geometry/polygon.h
  - icon: ':warning:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.h\"\n#include <bits/stdc++.h>\n\n#define FOR(i,a,b)\
    \ for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b);\
    \ i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a)\
    \ for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x)\
    \ { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a\
    \ << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n)\
    \ { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define\
    \ sqr(x) ((x) * (x))\nusing namespace std;\n\nint main() {\n    return 0;\n}\n\
    \n#line 1 \"Geometry/basic.h\"\n#define EPS 1e-6\nconst double PI = acos(-1.0);\n\
    \ndouble DEG_to_RAD(double d) { return d * PI / 180.0; }\ndouble RAD_to_DEG(double\
    \ r) { return r * 180.0 / PI; }\n\ninline int cmp(double a, double b) {\n    return\
    \ (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);\n}\n\nstruct Point {\n    double\
    \ x, y;\n    Point() { x = y = 0.0; }\n    Point(double _x, double _y) : x(_x),\
    \ y(_y) {}\n\n    Point operator + (const Point& a) const { return Point(x+a.x,\
    \ y+a.y); }\n    Point operator - (const Point& a) const { return Point(x-a.x,\
    \ y-a.y); }\n    Point operator * (double k) const { return Point(x*k, y*k); }\n\
    \    Point operator / (double k) const { return Point(x/k, y/k); }\n\n    double\
    \ operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product\n\
    \    double operator % (const Point& a) const { return x*a.y - y*a.x; } // cross\
    \ product\n\n    int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t;\
    \ return ::cmp(y,q.y); }\n\n    #define Comp(x) bool operator x (Point q) const\
    \ { return cmp(q) x 0; }\n    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)\n\
    \    #undef Comp\n\n    Point conj() { return Point(x, -y); }\n    double norm()\
    \ { return x*x + y*y; }\n\n    // Note: There are 2 ways for implementing len():\n\
    \    // 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are\
    \ of order X^2)\n    // 2. hypot(x, y) --> slow, but much more accurate\n    double\
    \ len() { return sqrt(norm()); }\n\n    Point rotate(double alpha) {\n       \
    \ double cosa = cos(alpha), sina = sin(alpha);\n        return Point(x * cosa\
    \ - y * sina, x * sina + y * cosa);\n    }\n};\n\nint ccw(Point a, Point b, Point\
    \ c) {\n    return cmp((b-a)%(c-a),0);\n}\nint RE_TRAI = ccw(Point(0, 0), Point(0,\
    \ 1), Point(-1, 1));\nint RE_PHAI = ccw(Point(0, 0), Point(0, 1), Point(1, 1));\n\
    istream& operator >> (istream& cin, Point& p) {\n    cin >> p.x >> p.y;\n    return\
    \ cin;\n}\nostream& operator << (ostream& cout, Point& p) {\n    cout << p.x <<\
    \ ' ' << p.y;\n    return cout;\n}\n\ndouble angle(Point a, Point o, Point b)\
    \ { // min of directed angle AOB & BOA\n    a = a - o; b = b - o;\n    return\
    \ acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));\n}\n\ndouble directed_angle(Point\
    \ a, Point o, Point b) { // angle AOB, in range [0, 2*PI)\n    double t = -atan2(a.y\
    \ - o.y, a.x - o.x)\n            + atan2(b.y - o.y, b.x - o.x);\n    while (t\
    \ < 0) t += 2*PI;\n    return t;\n}\n\n// Distance from p to Line ab (closest\
    \ Point --> c)\ndouble distToLine(Point p, Point a, Point b, Point &c) {\n   \
    \ Point ap = p - a, ab = b - a;\n    double u = (ap * ab) / ab.norm();\n    c\
    \ = a + (ab * u);\n    return (p-c).len();\n}\n\n// Distance from p to segment\
    \ ab (closest Point --> c)\ndouble distToLineSegment(Point p, Point a, Point b,\
    \ Point &c) {\n    Point ap = p - a, ab = b - a;\n    double u = (ap * ab) / ab.norm();\n\
    \    if (u < 0.0) {\n        c = Point(a.x, a.y);\n        return (p - a).len();\n\
    \    }\n    if (u > 1.0) {\n        c = Point(b.x, b.y);\n        return (p -\
    \ b).len();\n    }\n    return distToLine(p, a, b, c);\n}\n\n// NOTE: WILL NOT\
    \ WORK WHEN a = b = 0.\nstruct Line {\n    double a, b, c;\n    Point A, B; //\
    \ Added for polygon intersect line. Do not rely on assumption that these are valid\n\
    \n    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {} \n\n    Line(Point\
    \ _A, Point _B) : A(_A), B(_B) {\n        a = B.y - A.y;\n        b = A.x - B.x;\n\
    \        c = - (a * A.x + b * A.y);\n    }\n    Line(Point P, double m) {\n  \
    \      a = -m; b = 1;\n        c = -((a * P.x) + (b * P.y));\n    }\n    double\
    \ f(Point p) {\n        return a*p.x + b*p.y + c;\n    }\n};\n\nbool areParallel(Line\
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
    \ = p + (b - p) * 2;\n}\n#line 1 \"Geometry/polygon.h\"\ntypedef vector< Point\
    \ > Polygon;\n\n// Convex Hull:\n// If minimum point --> #define REMOVE_REDUNDANT\n\
    // If maximum point --> need to change >= and <= to > and < (see Note).\n// Known\
    \ issues:\n// - Max. point does not work when some points are the same.\n// Tested:\n\
    // - https://open.kattis.com/problems/convexhull\n/*\nbool operator<(const Point\
    \ &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }\nbool operator==(const\
    \ Point &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }\n */\n\
    double area2(Point a, Point b, Point c) { return a%b + b%c + c%a; }\n#ifdef REMOVE_REDUNDANT\n\
    bool between(const Point &a, const Point &b, const Point &c) {\n    return (fabs(area2(a,b,c))\
    \ < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);\n}\n#endif\n\
    \nvoid ConvexHull(vector<Point> &pts) {\n    sort(pts.begin(), pts.end());\n \
    \   pts.erase(unique(pts.begin(), pts.end()), pts.end());\n    vector<Point> up,\
    \ dn;\n    for (int i = 0; i < (int) pts.size(); i++) {\n#ifdef REMOVE_REDUNDANT\n\
    \        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >=\
    \ 0) up.pop_back();\n        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(),\
    \ pts[i]) <= 0) dn.pop_back();\n#else\n        while (up.size() > 1 && area2(up[up.size()-2],\
    \ up.back(), pts[i]) > 0) up.pop_back();\n        while (dn.size() > 1 && area2(dn[dn.size()-2],\
    \ dn.back(), pts[i]) < 0) dn.pop_back();\n#endif\n        up.push_back(pts[i]);\n\
    \        dn.push_back(pts[i]);\n    }\n    pts = dn;\n    for (int i = (int) up.size()\
    \ - 2; i >= 1; i--) pts.push_back(up[i]);\n    \n#ifdef REMOVE_REDUNDANT\n   \
    \ if (pts.size() <= 2) return;\n    dn.clear();\n    dn.push_back(pts[0]);\n \
    \   dn.push_back(pts[1]);\n    for (int i = 2; i < (int) pts.size(); i++) {\n\
    \        if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();\n\
    \        dn.push_back(pts[i]);\n    }\n    if (dn.size() >= 3 && between(dn.back(),\
    \ dn[0], dn[1])) {\n        dn[0] = dn.back();\n        dn.pop_back();\n    }\n\
    \    pts = dn;\n#endif\n}\n\n// Area, perimeter, centroid\ndouble signed_area(Polygon\
    \ p) {\n    double area = 0;\n    for(int i = 0; i < p.size(); i++) {\n      \
    \  int j = (i+1) % p.size();\n        area += p[i].x*p[j].y - p[j].x*p[i].y;\n\
    \    }\n    return area / 2.0;\n}\ndouble area(const Polygon &p) {\n    return\
    \ fabs(signed_area(p));\n}\nPoint centroid(Polygon p) {\n    Point c(0,0);\n \
    \   double scale = 6.0 * signed_area(p);\n    for (int i = 0; i < p.size(); i++){\n\
    \        int j = (i+1) % p.size();\n        c = c + (p[i]+p[j])*(p[i].x*p[j].y\
    \ - p[j].x*p[i].y);\n    }\n    return c / scale;\n}\ndouble perimeter(Polygon\
    \ P) {\n    double res = 0;\n    for(int i = 0; i < P.size(); ++i) {\n       \
    \ int j = (i + 1) % P.size();\n        res += (P[i] - P[j]).len();\n    }\n  \
    \  return res;\n}\n// Is convex: checks if polygon is convex. Assume there are\
    \ no 3 collinear points\nbool is_convex(const Polygon &P) {\n    int sz = (int)\
    \ P.size();\n    if (sz <= 2) return false;\n    int isLeft = ccw(P[0], P[1],\
    \ P[2]);\n    for (int i = 1; i < sz; i++)\n        if (ccw(P[i], P[(i+1) % sz],\
    \ P[(i+2) % sz]) * isLeft < 0)\n            return false;\n    return true;\n\
    }\n\n// Inside polygon: O(N). Works with any polygon\n// Tested:\n// - https://open.kattis.com/problems/pointinpolygon\n\
    // - https://open.kattis.com/problems/cuttingpolygon\nbool in_polygon(const Polygon\
    \ &p, Point q) {\n    if ((int)p.size() == 0) return false;\n\n    // Check if\
    \ point is on edge.\n    int n = SZ(p);\n    REP(i,n) {\n        int j = (i +\
    \ 1) % n;\n        Point u = p[i], v = p[j];\n\n        if (u > v) swap(u, v);\n\
    \n        if (ccw(u, v, q) == 0 && u <= q && q <= v) return true;\n    }\n\n \
    \   // Check if point is strictly inside.\n    int c = 0;\n    for (int i = 0;\
    \ i < n; i++) {\n        int j = (i + 1) % n;\n        if ((p[i].y <= q.y && q.y\
    \ < p[j].y || p[j].y <= q.y && q.y < p[i].y) && q.x < p[i].x + (p[j].x - p[i].x)\
    \ * (q.y - p[i].y) / (p[j].y - p[i].y)) c = !c;\n    }\n    return c;\n}\n\n//\
    \ Check point in convex polygon, O(logN)\n// Source: http://codeforces.com/contest/166/submission/1392387\n\
    // On edge --> false\n#define Det(a,b,c) ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))\n\
    bool in_convex(vector<Point>& l, Point p){\n    int a = 1, b = l.size()-1, c;\n\
    \    if (Det(l[0], l[a], l[b]) > 0) swap(a,b);\n    // Allow on edge --> if (Det...\
    \ > 0 || Det ... < 0)\n    if (Det(l[0], l[a], p) >= 0 || Det(l[0], l[b], p) <=\
    \ 0) return false;\n    while(abs(a-b) > 1) {\n        c = (a+b)/2;\n        if\
    \ (Det(l[0], l[c], p) > 0) b = c; else a = c;\n    }\n    // Alow on edge -->\
    \ return Det... <= 0\n    return Det(l[a], l[b], p) < 0;\n}\n\n\n// Cut a polygon\
    \ with a line. Returns one half.\n// To return the other half, reverse the direction\
    \ of Line l (by negating l.a, l.b)\n// The line must be formed using 2 points\n\
    Polygon polygon_cut(const Polygon& P, Line l) {\n    Polygon Q;\n    for(int i\
    \ = 0; i < P.size(); ++i) {\n        Point A = P[i], B = (i == P.size()-1) ? P[0]\
    \ : P[i+1];\n        if (ccw(l.A, l.B, A) != -1) Q.push_back(A);\n        if (ccw(l.A,\
    \ l.B, A)*ccw(l.A, l.B, B) < 0) {\n            Point p; areIntersect(Line(A, B),\
    \ l, p);\n            Q.push_back(p);\n        }\n    }\n    return Q;\n}\n\n\
    // Find intersection of 2 convex polygons\n// Helper method\nbool intersect_1pt(Point\
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
    \    }\n    return R;\n}\n\n// Find the diameter of polygon.\n// Rotating callipers\n\
    double convex_diameter(Polygon pt) {\n    const int n = pt.size();\n    int is\
    \ = 0, js = 0;\n    for (int i = 1; i < n; ++i) {\n        if (pt[i].y > pt[is].y)\
    \ is = i;\n        if (pt[i].y < pt[js].y) js = i;\n    }\n    double maxd = (pt[is]-pt[js]).norm();\n\
    \    int i, maxi, j, maxj;\n    i = maxi = is;\n    j = maxj = js;\n    do {\n\
    \        int jj = j+1; if (jj == n) jj = 0;\n        if ((pt[i] - pt[jj]).norm()\
    \ > (pt[i] - pt[j]).norm()) j = (j+1) % n;\n        else i = (i+1) % n;\n    \
    \    if ((pt[i]-pt[j]).norm() > maxd) {\n            maxd = (pt[i]-pt[j]).norm();\n\
    \            maxi = i; maxj = j;\n        }\n    } while (i != is || j != js);\n\
    \    return maxd; /* farthest pair is (maxi, maxj). */\n}\n\n// Closest pair\n\
    // Source: e-maxx.ru\n// Tested:\n// - https://open.kattis.com/problems/closestpair2\n\
    // - https://open.kattis.com/problems/closestpair1\n// Notes:\n// - Sort by X\
    \ first\n// - Implement compare by Y\n#define upd_ans(x, y) {}\n#define MAXN 100\n\
    double mindist = 1e20; // will be the result\nvoid rec(int l, int r, Point a[])\
    \ {\n    if (r - l <= 3) {\n        for (int i=l; i<=r; ++i)\n            for\
    \ (int j=i+1; j<=r; ++j)\n                    upd_ans(a[i], a[j]);\n        sort(a+l,\
    \ a+r+1, cmpy); // compare by y\n        return;\n    }\n\n    int m = (l + r)\
    \ >> 1;\n    int midx = a[m].x;\n    rec(l, m, a), rec(m+1, r, a);\n    static\
    \ Point t[MAXN];\n    merge(a+l, a+m+1, a+m+1, a+r+1, t, cmpy); // compare by\
    \ y\n    copy(t, t+r-l+1, a+l);\n\n    int tsz = 0;\n    for (int i=l; i<=r; ++i)\n\
    \        if (fabs(a[i].x - midx) < mindist) {\n            for (int j=tsz-1; j>=0\
    \ && a[i].y - t[j].y < mindist; --j)\n                upd_ans(a[i], t[j]);\n \
    \           t[tsz++] = a[i];\n        }\n}\n\n// Pick theorem\n// Given non-intersecting\
    \ polygon.\n// S = area\n// I = number of integer points strictly Inside\n// B\
    \ = number of points on sides of polygon\n// S = I + B/2 - 1\n\n// Check if we\
    \ can form triangle with edges x, y, z.\nbool isSquare(long long x) { /* */ }\n\
    bool isIntegerCoordinates(int x, int y, int z) {\n    long long s=(long long)(x+y+z)*(x+y-z)*(x+z-y)*(y+z-x);\n\
    \    return (s%4==0 && isSquare(s/4));\n}\n#line 4 \"Geometry/polygon.cpp\"\n\n\
    int main() {\n    cout << (fixed) << setprecision(9);\n    Polygon P;\n    P.push_back(Point(1,\
    \ 1));\n    P.push_back(Point(3, 3));\n    P.push_back(Point(9, 1));\n    P.push_back(Point(12,\
    \ 4));\n    P.push_back(Point(9, 7));\n    P.push_back(Point(1, 7));\n\n    //\
    \ Basic methods\n    assert(cmp(perimeter(P), 31.638263819) == 0);\n    assert(cmp(area(P),\
    \ 49.00) == 0);\n    assert(!is_convex(P));\n\n    // in_polygon\n    //7 P5--------------P4\n\
    \    //6 |                  \\\n    //5 |                    \\\n    //4 |   P7\
    \                P3\n    //3 |   P1___            /\n    //2 | / P6    \\ ___\
    \    /\n    //1 P0              P2\n    //0 1 2 3 4 5 6 7 8 9 101112\n\n    assert(in_polygon(P,\
    \ Point(3, 4)));\n    assert(!in_polygon(P, Point(3, 2)));\n\n    // Polygon cutting\n\
    \    //7 P5--------------P4\n    //6 |               |  \\\n    //5 |        \
    \       |    \\\n    //4 |               |     P3\n    //3 |   P1___       | \
    \   /\n    //2 | /       \\ ___ |  /\n    //1 P0              P2\n    //0 1 2\
    \ 3 4 5 6 7 8 9 101112\n    // new polygon (notice the index are different now):\n\
    \    //7 P4--------------P3\n    //6 |               |\n    //5 |            \
    \   |\n    //4 |               |\n    //3 |   P1___       |\n    //2 | /     \
    \  \\ ___ |\n    //1 P0              P2\n    //0 1 2 3 4 5 6 7 8 9\n\n    P =\
    \ polygon_cut(P, Line(P[2], P[4]));\n    assert(cmp(perimeter(P), 29.152982445)\
    \ == 0);\n    assert(cmp(area(P), 40.00) == 0);\n\n    // convex hull\n    //7\
    \ P3--------------P2\n    //6 |               |\n    //5 |               |\n \
    \   //4 |   P7          |\n    //3 |               |\n    //2 |              \
    \ |\n    //1 P0--------------P1\n    //0 1 2 3 4 5 6 7 8 9\n\n    P = convex_hull(P);\n\
    \    assert(cmp(perimeter(P), 28.00) == 0);\n    assert(cmp(area(P), 48.00) ==\
    \ 0);\n    assert(is_convex(P));\n    assert(in_convex(P, Point(3, 4)));\n   \
    \ assert(in_convex(P, Point(3, 2)));\n    assert(!in_convex(P, Point(3, 1)));\n\
    \    assert(!in_convex(P, Point(3, 0)));\n\n    assert(in_polygon(P, Point(3,\
    \ 4)));\n    assert(in_polygon(P, Point(3, 2)));\n    assert(!in_polygon(P, Point(3,\
    \ 0)));\n\n    P.clear();\n    for(int i = 0; i < 10; ++i)\n        for(int j\
    \ = 0; j < 10; ++j)\n            for(int turn = 0; turn < 3; ++turn)\n       \
    \         P.push_back(Point(i, j));\n    P = convex_hull(P);\n    assert(P.size()\
    \ == 4);\n    assert(P[0] == Point(0, 0));\n    assert(P[1] == Point(0, 9));\n\
    \    assert(P[2] == Point(9, 9));\n    assert(P[3] == Point(9, 0));\n\n    P.clear();\n\
    \    for(int i = 0; i < 10; ++i)\n        P.push_back(Point(7, 7 * i));\n    P\
    \ = convex_hull(P);\n    assert(P.size() == 2);\n    assert(P[0] == Point(7, 0));\n\
    \    assert(P[1] == Point(7, 63));\n\n    P.clear();\n    for(int i = 0; i < 10;\
    \ ++i)\n        P.push_back(Point(7, 7));\n    P = convex_hull(P);\n    assert(P.size()\
    \ == 1);\n    assert(P[0] == Point(7, 7));\n    cout << \"All test passed \" <<\
    \ endl;\n\n    return 0;\n}\n"
  code: "#include \"../template.h\"\n#include \"basic.h\"\n#include \"polygon.h\"\n\
    \nint main() {\n    cout << (fixed) << setprecision(9);\n    Polygon P;\n    P.push_back(Point(1,\
    \ 1));\n    P.push_back(Point(3, 3));\n    P.push_back(Point(9, 1));\n    P.push_back(Point(12,\
    \ 4));\n    P.push_back(Point(9, 7));\n    P.push_back(Point(1, 7));\n\n    //\
    \ Basic methods\n    assert(cmp(perimeter(P), 31.638263819) == 0);\n    assert(cmp(area(P),\
    \ 49.00) == 0);\n    assert(!is_convex(P));\n\n    // in_polygon\n    //7 P5--------------P4\n\
    \    //6 |                  \\\n    //5 |                    \\\n    //4 |   P7\
    \                P3\n    //3 |   P1___            /\n    //2 | / P6    \\ ___\
    \    /\n    //1 P0              P2\n    //0 1 2 3 4 5 6 7 8 9 101112\n\n    assert(in_polygon(P,\
    \ Point(3, 4)));\n    assert(!in_polygon(P, Point(3, 2)));\n\n    // Polygon cutting\n\
    \    //7 P5--------------P4\n    //6 |               |  \\\n    //5 |        \
    \       |    \\\n    //4 |               |     P3\n    //3 |   P1___       | \
    \   /\n    //2 | /       \\ ___ |  /\n    //1 P0              P2\n    //0 1 2\
    \ 3 4 5 6 7 8 9 101112\n    // new polygon (notice the index are different now):\n\
    \    //7 P4--------------P3\n    //6 |               |\n    //5 |            \
    \   |\n    //4 |               |\n    //3 |   P1___       |\n    //2 | /     \
    \  \\ ___ |\n    //1 P0              P2\n    //0 1 2 3 4 5 6 7 8 9\n\n    P =\
    \ polygon_cut(P, Line(P[2], P[4]));\n    assert(cmp(perimeter(P), 29.152982445)\
    \ == 0);\n    assert(cmp(area(P), 40.00) == 0);\n\n    // convex hull\n    //7\
    \ P3--------------P2\n    //6 |               |\n    //5 |               |\n \
    \   //4 |   P7          |\n    //3 |               |\n    //2 |              \
    \ |\n    //1 P0--------------P1\n    //0 1 2 3 4 5 6 7 8 9\n\n    P = convex_hull(P);\n\
    \    assert(cmp(perimeter(P), 28.00) == 0);\n    assert(cmp(area(P), 48.00) ==\
    \ 0);\n    assert(is_convex(P));\n    assert(in_convex(P, Point(3, 4)));\n   \
    \ assert(in_convex(P, Point(3, 2)));\n    assert(!in_convex(P, Point(3, 1)));\n\
    \    assert(!in_convex(P, Point(3, 0)));\n\n    assert(in_polygon(P, Point(3,\
    \ 4)));\n    assert(in_polygon(P, Point(3, 2)));\n    assert(!in_polygon(P, Point(3,\
    \ 0)));\n\n    P.clear();\n    for(int i = 0; i < 10; ++i)\n        for(int j\
    \ = 0; j < 10; ++j)\n            for(int turn = 0; turn < 3; ++turn)\n       \
    \         P.push_back(Point(i, j));\n    P = convex_hull(P);\n    assert(P.size()\
    \ == 4);\n    assert(P[0] == Point(0, 0));\n    assert(P[1] == Point(0, 9));\n\
    \    assert(P[2] == Point(9, 9));\n    assert(P[3] == Point(9, 0));\n\n    P.clear();\n\
    \    for(int i = 0; i < 10; ++i)\n        P.push_back(Point(7, 7 * i));\n    P\
    \ = convex_hull(P);\n    assert(P.size() == 2);\n    assert(P[0] == Point(7, 0));\n\
    \    assert(P[1] == Point(7, 63));\n\n    P.clear();\n    for(int i = 0; i < 10;\
    \ ++i)\n        P.push_back(Point(7, 7));\n    P = convex_hull(P);\n    assert(P.size()\
    \ == 1);\n    assert(P[0] == Point(7, 7));\n    cout << \"All test passed \" <<\
    \ endl;\n\n    return 0;\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  - Geometry/polygon.h
  isVerificationFile: false
  path: Geometry/polygon.cpp
  requiredBy: []
  timestamp: '2022-01-04 16:05:00+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/polygon.cpp
layout: document
redirect_from:
- /library/Geometry/polygon.cpp
- /library/Geometry/polygon.cpp.html
title: Geometry/polygon.cpp
---
