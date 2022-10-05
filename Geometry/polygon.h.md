---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/polygon.cpp
    title: Geometry/polygon.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_3_a_polygon_area.test.cpp
    title: Geometry/tests/aizu_cgl_3_a_polygon_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_3_b_polygon_is_convex.test.cpp
    title: Geometry/tests/aizu_cgl_3_b_polygon_is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_3_c_polygon_in_polygon.test.cpp
    title: Geometry/tests/aizu_cgl_3_c_polygon_in_polygon.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp
    title: Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_4_b_polygon_convex_diameter.test.cpp
    title: Geometry/tests/aizu_cgl_4_b_polygon_convex_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_4_c_polygon_convex_cut.test.cpp
    title: Geometry/tests/aizu_cgl_4_c_polygon_convex_cut.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/polygon_in_convex.test.cpp
    title: Geometry/tests/polygon_in_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/z_polygon_area.test.cpp
    title: Geometry/tests/z_polygon_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/z_polygon_convexhull.test.cpp
    title: Geometry/tests/z_polygon_convexhull.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/z_polygon_is_convex.test.cpp
    title: Geometry/tests/z_polygon_is_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cses.fi/problemset/task/2195
    - https://open.kattis.com/problems/convexhull
    - https://open.kattis.com/problems/cuttingpolygon
    - https://open.kattis.com/problems/pointinpolygon
  bundledCode: "#line 1 \"Geometry/polygon.h\"\n// Polygon: convex hull, in polygon,\
    \ convex diameter ..\n// Functions with param vector<P<T>> works with both integers\
    \ and floating points\n// Functions with param Polygon works with floating points\
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
    // S = I + B/2 - 1\n"
  code: "// Polygon: convex hull, in polygon, convex diameter ..\n// Functions with\
    \ param vector<P<T>> works with both integers and floating points\n// Functions\
    \ with param Polygon works with floating points only.\n\ntypedef vector< Point\
    \ > Polygon;\n\n// Convex Hull:\n// If minimum point --> #define REMOVE_REDUNDANT\n\
    // Known issues:\n// - Max. point does not work when some points are the same.\n\
    // Tested:\n// - (min points) https://open.kattis.com/problems/convexhull\n//\
    \ - (max points) https://cses.fi/problemset/task/2195\n\n// #define REMOVE_REDUNDANT\n\
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
    // S = I + B/2 - 1\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/polygon.h
  requiredBy:
  - Geometry/polygon.cpp
  timestamp: '2022-01-12 01:07:11+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Geometry/tests/aizu_cgl_3_c_polygon_in_polygon.test.cpp
  - Geometry/tests/aizu_cgl_4_b_polygon_convex_diameter.test.cpp
  - Geometry/tests/polygon_in_convex.test.cpp
  - Geometry/tests/z_polygon_is_convex.test.cpp
  - Geometry/tests/z_polygon_area.test.cpp
  - Geometry/tests/aizu_cgl_3_a_polygon_area.test.cpp
  - Geometry/tests/aizu_cgl_3_b_polygon_is_convex.test.cpp
  - Geometry/tests/z_polygon_convexhull.test.cpp
  - Geometry/tests/aizu_cgl_4_a_polygon_convex_hull.test.cpp
  - Geometry/tests/aizu_cgl_4_c_polygon_convex_cut.test.cpp
documentation_of: Geometry/polygon.h
layout: document
redirect_from:
- /library/Geometry/polygon.h
- /library/Geometry/polygon.h.html
title: Geometry/polygon.h
---
