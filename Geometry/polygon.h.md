---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/polygon.cpp
    title: Geometry/polygon.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/polygon_area.test.cpp
    title: Geometry/tests/polygon_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/polygon_in_convex.test.cpp
    title: Geometry/tests/polygon_in_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/polygon_in_polygon.test.cpp
    title: Geometry/tests/polygon_in_polygon.test.cpp
  - icon: ':x:'
    path: Geometry/tests/polygon_is_convex.test.cpp
    title: Geometry/tests/polygon_is_convex.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - http://codeforces.com/contest/166/submission/1392387
    - https://open.kattis.com/problems/closestpair1
    - https://open.kattis.com/problems/closestpair2
    - https://open.kattis.com/problems/convexhull
    - https://open.kattis.com/problems/cuttingpolygon
    - https://open.kattis.com/problems/pointinpolygon
  bundledCode: "#line 1 \"Geometry/polygon.h\"\ntypedef vector< Point > Polygon;\n\
    \n// Convex Hull:\n// If minimum point --> #define REMOVE_REDUNDANT\n// If maximum\
    \ point --> need to change >= and <= to > and < (see Note).\n// Known issues:\n\
    // - Max. point does not work when some points are the same.\n// Tested:\n// -\
    \ https://open.kattis.com/problems/convexhull\n/*\nbool operator<(const Point\
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
    \ p) {\n    double area = 0;\n    for(int i = 0; i < (int) p.size(); i++) {\n\
    \        int j = (i+1) % p.size();\n        area += p[i].x*p[j].y - p[j].x*p[i].y;\n\
    \    }\n    return area / 2.0;\n}\ndouble area(const Polygon &p) {\n    return\
    \ fabs(signed_area(p));\n}\nPoint centroid(Polygon p) {\n    Point c(0,0);\n \
    \   double scale = 6.0 * signed_area(p);\n    for (int i = 0; i < (int) p.size();\
    \ i++){\n        int j = (i+1) % p.size();\n        c = c + (p[i]+p[j])*(p[i].x*p[j].y\
    \ - p[j].x*p[i].y);\n    }\n    return c / scale;\n}\ndouble perimeter(Polygon\
    \ p) {\n    double res = 0;\n    for(int i = 0; i < (int) p.size(); ++i) {\n \
    \       int j = (i + 1) % p.size();\n        res += (p[i] - p[j]).len();\n   \
    \ }\n    return res;\n}\n// Is convex: checks if polygon is convex. Assume there\
    \ are no 3 collinear points\nbool is_convex(const Polygon &P) {\n    int sz =\
    \ (int) P.size();\n    if (sz <= 2) return false;\n    int isLeft = ccw(P[0],\
    \ P[1], P[2]);\n    for (int i = 1; i < sz; i++)\n        if (ccw(P[i], P[(i+1)\
    \ % sz], P[(i+2) % sz]) * isLeft < 0)\n            return false;\n    return true;\n\
    }\n\n// Inside polygon: O(N). Works with any polygon\n// Tested:\n// - https://open.kattis.com/problems/pointinpolygon\n\
    // - https://open.kattis.com/problems/cuttingpolygon\nenum PolygonLocation { OUT,\
    \ ON, IN };\nPolygonLocation in_polygon(const Polygon &p, Point q) {\n    if ((int)p.size()\
    \ == 0) return PolygonLocation::OUT;\n\n    // Check if point is on edge.\n  \
    \  int n = p.size();\n    REP(i,n) {\n        int j = (i + 1) % n;\n        Point\
    \ u = p[i], v = p[j];\n\n        if (u > v) swap(u, v);\n\n        if (ccw(u,\
    \ v, q) == 0 && u <= q && q <= v) return PolygonLocation::ON;\n    }\n\n    //\
    \ Check if point is strictly inside.\n    int c = 0;\n    for (int i = 0; i <\
    \ n; i++) {\n        int j = (i + 1) % n;\n        if (((p[i].y <= q.y && q.y\
    \ < p[j].y)\n                    || (p[j].y <= q.y && q.y < p[i].y))\n       \
    \         && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))\
    \ {\n            c = !c;\n        }\n    }\n    return c ? PolygonLocation::IN\
    \ : PolygonLocation::OUT;\n}\n\n// Check point in convex polygon, O(logN)\n//\
    \ Source: http://codeforces.com/contest/166/submission/1392387\n#define Det(a,b,c)\
    \ ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))\nPolygonLocation\
    \ in_convex(vector<Point>& l, Point p){\n    int a = 1, b = l.size()-1, c;\n \
    \   if (Det(l[0], l[a], l[b]) > 0) swap(a,b);\n\n    if (onSegment(l[0], l[a],\
    \ p)) return ON;\n    if (onSegment(l[0], l[b], p)) return ON;\n\n    if (Det(l[0],\
    \ l[a], p) > 0 || Det(l[0], l[b], p) < 0) return OUT;\n    while(abs(a-b) > 1)\
    \ {\n        c = (a+b)/2;\n        if (Det(l[0], l[c], p) > 0) b = c; else a =\
    \ c;\n    }\n    int t = cmp(Det(l[a], l[b], p), 0);\n    return (t == 0) ? ON\
    \ : (t < 0) ? IN : OUT;\n}\n\n\n// Cut a polygon with a line. Returns one half.\n\
    // To return the other half, reverse the direction of Line l (by negating l.a,\
    \ l.b)\n// The line must be formed using 2 points\nPolygon polygon_cut(const Polygon&\
    \ P, Line l) {\n    Polygon Q;\n    for(int i = 0; i < (int) P.size(); ++i) {\n\
    \        Point A = P[i], B = (i == ((int) P.size())-1) ? P[0] : P[i+1];\n    \
    \    if (ccw(l.A, l.B, A) != -1) Q.push_back(A);\n        if (ccw(l.A, l.B, A)*ccw(l.A,\
    \ l.B, B) < 0) {\n            Point p; areIntersect(Line(A, B), l, p);\n     \
    \       Q.push_back(p);\n        }\n    }\n    return Q;\n}\n\n// Find intersection\
    \ of 2 convex polygons\n// Helper method\nbool intersect_1pt(Point a, Point b,\n\
    \    Point c, Point d, Point &r) {\n    double D =  (b - a) % (d - c);\n    if\
    \ (cmp(D, 0) == 0) return false;\n    double t =  ((c - a) % (d - c)) / D;\n \
    \   double s = -((a - c) % (b - a)) / D;\n    r = a + (b - a) * t;\n    return\
    \ cmp(t, 0) >= 0 && cmp(t, 1) <= 0 && cmp(s, 0) >= 0 && cmp(s, 1) <= 0;\n}\nPolygon\
    \ convex_intersect(Polygon P, Polygon Q) {\n    const int n = P.size(), m = Q.size();\n\
    \    int a = 0, b = 0, aa = 0, ba = 0;\n    enum { Pin, Qin, Unknown } in = Unknown;\n\
    \    Polygon R;\n    do {\n        int a1 = (a+n-1) % n, b1 = (b+m-1) % m;\n \
    \       double C = (P[a] - P[a1]) % (Q[b] - Q[b1]);\n        double A = (P[a1]\
    \ - Q[b]) % (P[a] - Q[b]);\n        double B = (Q[b1] - P[a]) % (Q[b] - P[a]);\n\
    \        Point r;\n        if (intersect_1pt(P[a1], P[a], Q[b1], Q[b], r)) {\n\
    \            if (in == Unknown) aa = ba = 0;\n            R.push_back( r );\n\
    \            in = B > 0 ? Pin : A > 0 ? Qin : in;\n        }\n        if (C ==\
    \ 0 && B == 0 && A == 0) {\n            if (in == Pin) { b = (b + 1) % m; ++ba;\
    \ }\n            else            { a = (a + 1) % m; ++aa; }\n        } else if\
    \ (C >= 0) {\n            if (A > 0) { if (in == Pin) R.push_back(P[a]); a = (a+1)%n;\
    \ ++aa; }\n            else       { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m;\
    \ ++ba; }\n        } else {\n            if (B > 0) { if (in == Qin) R.push_back(Q[b]);\
    \ b = (b+1)%m; ++ba; }\n            else       { if (in == Pin) R.push_back(P[a]);\
    \ a = (a+1)%n; ++aa; }\n        }\n    } while ( (aa < n || ba < m) && aa < 2*n\
    \ && ba < 2*m );\n    if (in == Unknown) {\n        if (in_convex(Q, P[0])) return\
    \ P;\n        if (in_convex(P, Q[0])) return Q;\n    }\n    return R;\n}\n\n//\
    \ Find the diameter of polygon.\n// Rotating callipers\ndouble convex_diameter(Polygon\
    \ pt) {\n    const int n = pt.size();\n    int is = 0, js = 0;\n    for (int i\
    \ = 1; i < n; ++i) {\n        if (pt[i].y > pt[is].y) is = i;\n        if (pt[i].y\
    \ < pt[js].y) js = i;\n    }\n    double maxd = (pt[is]-pt[js]).norm();\n    int\
    \ i, maxi, j, maxj;\n    i = maxi = is;\n    j = maxj = js;\n    do {\n      \
    \  int jj = j+1; if (jj == n) jj = 0;\n        if ((pt[i] - pt[jj]).norm() > (pt[i]\
    \ - pt[j]).norm()) j = (j+1) % n;\n        else i = (i+1) % n;\n        if ((pt[i]-pt[j]).norm()\
    \ > maxd) {\n            maxd = (pt[i]-pt[j]).norm();\n            maxi = i; maxj\
    \ = j;\n        }\n    } while (i != is || j != js);\n    return maxd; /* farthest\
    \ pair is (maxi, maxj). */\n}\n\n// Closest pair\n// Source: e-maxx.ru\n// Tested:\n\
    // - https://open.kattis.com/problems/closestpair2\n// - https://open.kattis.com/problems/closestpair1\n\
    // Notes:\n// - Sort by X first\n// - Implement compare by Y\n#define upd_ans(x,\
    \ y) {}\n#define MAXN 100\ndouble mindist = 1e20; // will be the result\nauto\
    \ cmpy = [] (const Point& a, const Point& b) {\n    return a.y < b.y;\n};\nvoid\
    \ rec(int l, int r, Point a[]) {\n    if (r - l <= 3) {\n        for (int i=l;\
    \ i<=r; ++i)\n            for (int j=i+1; j<=r; ++j)\n                    upd_ans(a[i],\
    \ a[j]);\n        sort(a+l, a+r+1, cmpy);\n        return;\n    }\n\n    int m\
    \ = (l + r) >> 1;\n    int midx = a[m].x;\n    rec(l, m, a), rec(m+1, r, a);\n\
    \    static Point t[MAXN];\n    merge(a+l, a+m+1, a+m+1, a+r+1, t, cmpy);\n  \
    \  copy(t, t+r-l+1, a+l);\n\n    int tsz = 0;\n    for (int i=l; i<=r; ++i)\n\
    \        if (fabs(a[i].x - midx) < mindist) {\n            for (int j=tsz-1; j>=0\
    \ && a[i].y - t[j].y < mindist; --j)\n                upd_ans(a[i], t[j]);\n \
    \           t[tsz++] = a[i];\n        }\n}\n\n// Pick theorem\n// Given non-intersecting\
    \ polygon.\n// S = area\n// I = number of integer points strictly Inside\n// B\
    \ = number of points on sides of polygon\n// S = I + B/2 - 1\n"
  code: "typedef vector< Point > Polygon;\n\n// Convex Hull:\n// If minimum point\
    \ --> #define REMOVE_REDUNDANT\n// If maximum point --> need to change >= and\
    \ <= to > and < (see Note).\n// Known issues:\n// - Max. point does not work when\
    \ some points are the same.\n// Tested:\n// - https://open.kattis.com/problems/convexhull\n\
    /*\nbool operator<(const Point &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x);\
    \ }\nbool operator==(const Point &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x);\
    \ }\n */\ndouble area2(Point a, Point b, Point c) { return a%b + b%c + c%a; }\n\
    #ifdef REMOVE_REDUNDANT\nbool between(const Point &a, const Point &b, const Point\
    \ &c) {\n    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y)\
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
    \      dn.pop_back();\n    }\n    pts = dn;\n#endif\n}\n\n// Area, perimeter,\
    \ centroid\ndouble signed_area(Polygon p) {\n    double area = 0;\n    for(int\
    \ i = 0; i < (int) p.size(); i++) {\n        int j = (i+1) % p.size();\n     \
    \   area += p[i].x*p[j].y - p[j].x*p[i].y;\n    }\n    return area / 2.0;\n}\n\
    double area(const Polygon &p) {\n    return fabs(signed_area(p));\n}\nPoint centroid(Polygon\
    \ p) {\n    Point c(0,0);\n    double scale = 6.0 * signed_area(p);\n    for (int\
    \ i = 0; i < (int) p.size(); i++){\n        int j = (i+1) % p.size();\n      \
    \  c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);\n    }\n    return c /\
    \ scale;\n}\ndouble perimeter(Polygon p) {\n    double res = 0;\n    for(int i\
    \ = 0; i < (int) p.size(); ++i) {\n        int j = (i + 1) % p.size();\n     \
    \   res += (p[i] - p[j]).len();\n    }\n    return res;\n}\n// Is convex: checks\
    \ if polygon is convex. Assume there are no 3 collinear points\nbool is_convex(const\
    \ Polygon &P) {\n    int sz = (int) P.size();\n    if (sz <= 2) return false;\n\
    \    int isLeft = ccw(P[0], P[1], P[2]);\n    for (int i = 1; i < sz; i++)\n \
    \       if (ccw(P[i], P[(i+1) % sz], P[(i+2) % sz]) * isLeft < 0)\n          \
    \  return false;\n    return true;\n}\n\n// Inside polygon: O(N). Works with any\
    \ polygon\n// Tested:\n// - https://open.kattis.com/problems/pointinpolygon\n\
    // - https://open.kattis.com/problems/cuttingpolygon\nenum PolygonLocation { OUT,\
    \ ON, IN };\nPolygonLocation in_polygon(const Polygon &p, Point q) {\n    if ((int)p.size()\
    \ == 0) return PolygonLocation::OUT;\n\n    // Check if point is on edge.\n  \
    \  int n = p.size();\n    REP(i,n) {\n        int j = (i + 1) % n;\n        Point\
    \ u = p[i], v = p[j];\n\n        if (u > v) swap(u, v);\n\n        if (ccw(u,\
    \ v, q) == 0 && u <= q && q <= v) return PolygonLocation::ON;\n    }\n\n    //\
    \ Check if point is strictly inside.\n    int c = 0;\n    for (int i = 0; i <\
    \ n; i++) {\n        int j = (i + 1) % n;\n        if (((p[i].y <= q.y && q.y\
    \ < p[j].y)\n                    || (p[j].y <= q.y && q.y < p[i].y))\n       \
    \         && q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))\
    \ {\n            c = !c;\n        }\n    }\n    return c ? PolygonLocation::IN\
    \ : PolygonLocation::OUT;\n}\n\n// Check point in convex polygon, O(logN)\n//\
    \ Source: http://codeforces.com/contest/166/submission/1392387\n#define Det(a,b,c)\
    \ ((double)(b.x-a.x)*(double)(c.y-a.y)-(double)(b.y-a.y)*(c.x-a.x))\nPolygonLocation\
    \ in_convex(vector<Point>& l, Point p){\n    int a = 1, b = l.size()-1, c;\n \
    \   if (Det(l[0], l[a], l[b]) > 0) swap(a,b);\n\n    if (onSegment(l[0], l[a],\
    \ p)) return ON;\n    if (onSegment(l[0], l[b], p)) return ON;\n\n    if (Det(l[0],\
    \ l[a], p) > 0 || Det(l[0], l[b], p) < 0) return OUT;\n    while(abs(a-b) > 1)\
    \ {\n        c = (a+b)/2;\n        if (Det(l[0], l[c], p) > 0) b = c; else a =\
    \ c;\n    }\n    int t = cmp(Det(l[a], l[b], p), 0);\n    return (t == 0) ? ON\
    \ : (t < 0) ? IN : OUT;\n}\n\n\n// Cut a polygon with a line. Returns one half.\n\
    // To return the other half, reverse the direction of Line l (by negating l.a,\
    \ l.b)\n// The line must be formed using 2 points\nPolygon polygon_cut(const Polygon&\
    \ P, Line l) {\n    Polygon Q;\n    for(int i = 0; i < (int) P.size(); ++i) {\n\
    \        Point A = P[i], B = (i == ((int) P.size())-1) ? P[0] : P[i+1];\n    \
    \    if (ccw(l.A, l.B, A) != -1) Q.push_back(A);\n        if (ccw(l.A, l.B, A)*ccw(l.A,\
    \ l.B, B) < 0) {\n            Point p; areIntersect(Line(A, B), l, p);\n     \
    \       Q.push_back(p);\n        }\n    }\n    return Q;\n}\n\n// Find intersection\
    \ of 2 convex polygons\n// Helper method\nbool intersect_1pt(Point a, Point b,\n\
    \    Point c, Point d, Point &r) {\n    double D =  (b - a) % (d - c);\n    if\
    \ (cmp(D, 0) == 0) return false;\n    double t =  ((c - a) % (d - c)) / D;\n \
    \   double s = -((a - c) % (b - a)) / D;\n    r = a + (b - a) * t;\n    return\
    \ cmp(t, 0) >= 0 && cmp(t, 1) <= 0 && cmp(s, 0) >= 0 && cmp(s, 1) <= 0;\n}\nPolygon\
    \ convex_intersect(Polygon P, Polygon Q) {\n    const int n = P.size(), m = Q.size();\n\
    \    int a = 0, b = 0, aa = 0, ba = 0;\n    enum { Pin, Qin, Unknown } in = Unknown;\n\
    \    Polygon R;\n    do {\n        int a1 = (a+n-1) % n, b1 = (b+m-1) % m;\n \
    \       double C = (P[a] - P[a1]) % (Q[b] - Q[b1]);\n        double A = (P[a1]\
    \ - Q[b]) % (P[a] - Q[b]);\n        double B = (Q[b1] - P[a]) % (Q[b] - P[a]);\n\
    \        Point r;\n        if (intersect_1pt(P[a1], P[a], Q[b1], Q[b], r)) {\n\
    \            if (in == Unknown) aa = ba = 0;\n            R.push_back( r );\n\
    \            in = B > 0 ? Pin : A > 0 ? Qin : in;\n        }\n        if (C ==\
    \ 0 && B == 0 && A == 0) {\n            if (in == Pin) { b = (b + 1) % m; ++ba;\
    \ }\n            else            { a = (a + 1) % m; ++aa; }\n        } else if\
    \ (C >= 0) {\n            if (A > 0) { if (in == Pin) R.push_back(P[a]); a = (a+1)%n;\
    \ ++aa; }\n            else       { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m;\
    \ ++ba; }\n        } else {\n            if (B > 0) { if (in == Qin) R.push_back(Q[b]);\
    \ b = (b+1)%m; ++ba; }\n            else       { if (in == Pin) R.push_back(P[a]);\
    \ a = (a+1)%n; ++aa; }\n        }\n    } while ( (aa < n || ba < m) && aa < 2*n\
    \ && ba < 2*m );\n    if (in == Unknown) {\n        if (in_convex(Q, P[0])) return\
    \ P;\n        if (in_convex(P, Q[0])) return Q;\n    }\n    return R;\n}\n\n//\
    \ Find the diameter of polygon.\n// Rotating callipers\ndouble convex_diameter(Polygon\
    \ pt) {\n    const int n = pt.size();\n    int is = 0, js = 0;\n    for (int i\
    \ = 1; i < n; ++i) {\n        if (pt[i].y > pt[is].y) is = i;\n        if (pt[i].y\
    \ < pt[js].y) js = i;\n    }\n    double maxd = (pt[is]-pt[js]).norm();\n    int\
    \ i, maxi, j, maxj;\n    i = maxi = is;\n    j = maxj = js;\n    do {\n      \
    \  int jj = j+1; if (jj == n) jj = 0;\n        if ((pt[i] - pt[jj]).norm() > (pt[i]\
    \ - pt[j]).norm()) j = (j+1) % n;\n        else i = (i+1) % n;\n        if ((pt[i]-pt[j]).norm()\
    \ > maxd) {\n            maxd = (pt[i]-pt[j]).norm();\n            maxi = i; maxj\
    \ = j;\n        }\n    } while (i != is || j != js);\n    return maxd; /* farthest\
    \ pair is (maxi, maxj). */\n}\n\n// Closest pair\n// Source: e-maxx.ru\n// Tested:\n\
    // - https://open.kattis.com/problems/closestpair2\n// - https://open.kattis.com/problems/closestpair1\n\
    // Notes:\n// - Sort by X first\n// - Implement compare by Y\n#define upd_ans(x,\
    \ y) {}\n#define MAXN 100\ndouble mindist = 1e20; // will be the result\nauto\
    \ cmpy = [] (const Point& a, const Point& b) {\n    return a.y < b.y;\n};\nvoid\
    \ rec(int l, int r, Point a[]) {\n    if (r - l <= 3) {\n        for (int i=l;\
    \ i<=r; ++i)\n            for (int j=i+1; j<=r; ++j)\n                    upd_ans(a[i],\
    \ a[j]);\n        sort(a+l, a+r+1, cmpy);\n        return;\n    }\n\n    int m\
    \ = (l + r) >> 1;\n    int midx = a[m].x;\n    rec(l, m, a), rec(m+1, r, a);\n\
    \    static Point t[MAXN];\n    merge(a+l, a+m+1, a+m+1, a+r+1, t, cmpy);\n  \
    \  copy(t, t+r-l+1, a+l);\n\n    int tsz = 0;\n    for (int i=l; i<=r; ++i)\n\
    \        if (fabs(a[i].x - midx) < mindist) {\n            for (int j=tsz-1; j>=0\
    \ && a[i].y - t[j].y < mindist; --j)\n                upd_ans(a[i], t[j]);\n \
    \           t[tsz++] = a[i];\n        }\n}\n\n// Pick theorem\n// Given non-intersecting\
    \ polygon.\n// S = area\n// I = number of integer points strictly Inside\n// B\
    \ = number of points on sides of polygon\n// S = I + B/2 - 1\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/polygon.h
  requiredBy:
  - Geometry/polygon.cpp
  timestamp: '2022-01-11 00:18:26+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Geometry/tests/polygon_in_convex.test.cpp
  - Geometry/tests/polygon_in_polygon.test.cpp
  - Geometry/tests/polygon_is_convex.test.cpp
  - Geometry/tests/polygon_area.test.cpp
documentation_of: Geometry/polygon.h
layout: document
redirect_from:
- /library/Geometry/polygon.h
- /library/Geometry/polygon.h.html
title: Geometry/polygon.h
---
