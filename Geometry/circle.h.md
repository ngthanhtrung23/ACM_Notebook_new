---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/SPOJ_ALIENS.cpp
    title: Geometry/SPOJ_ALIENS.cpp
  - icon: ':warning:'
    path: Geometry/circle.cpp
    title: Geometry/circle.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_7_a_cicle_tangents.test.cpp
    title: Geometry/tests/aizu_cgl_7_a_cicle_tangents.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_7_d_circle_line_intersection.test.cpp
    title: Geometry/tests/aizu_cgl_7_d_circle_line_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_7_e_circle_circle_intersection.test.cpp
    title: Geometry/tests/aizu_cgl_7_e_circle_circle_intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_7_f_circle_tangent_points.test.cpp
    title: Geometry/tests/aizu_cgl_7_f_circle_tangent_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_7_g_circle_circle_tangent_points.test.cpp
    title: Geometry/tests/aizu_cgl_7_g_circle_circle_tangent_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_7_i_circle_common_area.test.cpp
    title: Geometry/tests/aizu_cgl_7_i_circle_common_area.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://codeforces.com/contest/600/problem/D
    - http://codeforces.com/gym/100803/
    - http://codeforces.com/gym/100820/
    - https://en.wikipedia.org/wiki/Circle
  bundledCode: "#line 1 \"Geometry/circle.h\"\nstruct Circle : Point {\n    double\
    \ r;\n    Circle(double _x = 0, double _y = 0, double _r = 0) : Point(_x, _y),\
    \ r(_r) {}\n    Circle(Point p, double _r) : Point(p), r(_r) {}\n    \n    bool\
    \ contains(Point p) { return (*this - p).len() <= r + EPS; }\n\n    double area()\
    \ const { return r*r*M_PI; }\n\n    // definitions in https://en.wikipedia.org/wiki/Circle\n\
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
    \ * u.r + u);\n    return res;\n}\n"
  code: "struct Circle : Point {\n    double r;\n    Circle(double _x = 0, double\
    \ _y = 0, double _r = 0) : Point(_x, _y), r(_r) {}\n    Circle(Point p, double\
    \ _r) : Point(p), r(_r) {}\n    \n    bool contains(Point p) { return (*this -\
    \ p).len() <= r + EPS; }\n\n    double area() const { return r*r*M_PI; }\n\n \
    \   // definitions in https://en.wikipedia.org/wiki/Circle\n    // assumption:\
    \ 0 <= theta <= 2*PI\n    // theta: angle in radian\n    double sector_area(double\
    \ theta) const {\n        return 0.5 * r * r * theta;\n    }\n\n    // assumption:\
    \ 0 <= theta <= 2*PI\n    // theta: angle in radian\n    double segment_area(double\
    \ theta) const {\n        return 0.5 * r * r * (theta - sin(theta));\n    }\n\
    };\nistream& operator >> (istream& cin, Circle& c) {\n    cin >> c.x >> c.y >>\
    \ c.r;\n    return cin;\n}\nostream& operator << (ostream& cout, const Circle&\
    \ c) {\n    cout << '(' << c.x << \", \" << c.y << \") \" << c.r;\n    return\
    \ cout;\n}\n\n// Find common tangents to 2 circles\n// Tested:\n// - http://codeforces.com/gym/100803/\
    \ - H\n// Helper method\nvoid tangents(Point c, double r1, double r2, vector<Line>\
    \ & ans) {\n    double r = r2 - r1;\n    double z = sqr(c.x) + sqr(c.y);\n   \
    \ double d = z - sqr(r);\n    if (d < -EPS)  return;\n    d = sqrt(fabs(d));\n\
    \    Line l((c.x * r + c.y * d) / z,\n            (c.y * r - c.x * d) / z,\n \
    \           r1);\n    ans.push_back(l);\n}\n// Actual method: returns vector containing\
    \ all common tangents\nvector<Line> tangents(Circle a, Circle b) {\n    vector<Line>\
    \ ans; ans.clear();\n    for (int i=-1; i<=1; i+=2)\n        for (int j=-1; j<=1;\
    \ j+=2)\n            tangents(b-a, a.r*i, b.r*j, ans);\n    for(int i = 0; i <\
    \ (int) ans.size(); ++i)\n        ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;\n\
    \n    vector<Line> ret;\n    for(int i = 0; i < (int) ans.size(); ++i) {\n   \
    \     if (std::none_of(ret.begin(), ret.end(), [&] (Line l) { return areSame(l,\
    \ ans[i]); })) {\n            ret.push_back(ans[i]);\n        }\n    }\n    return\
    \ ret;\n}\n\n// Circle & line intersection\n// Tested:\n// - http://codeforces.com/gym/100803/\
    \ - H\nvector<Point> intersection(Line l, Circle cir) {\n    double r = cir.r,\
    \ a = l.a, b = l.b, c = l.c + l.a*cir.x + l.b*cir.y;\n    vector<Point> res;\n\
    \n    double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);\n    if (c*c > r*r*(a*a+b*b)+EPS)\
    \ return res;\n    else if (fabs(c*c - r*r*(a*a+b*b)) < EPS) {\n        res.push_back(Point(x0,\
    \ y0) + Point(cir.x, cir.y));\n        return res;\n    } else {\n        double\
    \ d = r*r - c*c/(a*a+b*b);\n        double mult = sqrt (d / (a*a+b*b));\n    \
    \    double ax,ay,bx,by;\n        ax = x0 + b * mult;\n        bx = x0 - b * mult;\n\
    \        ay = y0 - a * mult;\n        by = y0 + a * mult;\n\n        res.push_back(Point(ax,\
    \ ay) + Point(cir.x, cir.y));\n        res.push_back(Point(bx, by) + Point(cir.x,\
    \ cir.y));\n        return res;\n    }\n}\n\n// helper functions for commonCircleArea\n\
    double cir_area_solve(double a, double b, double c) {\n    return acos((a*a +\
    \ b*b - c*c) / 2 / a / b);\n}\ndouble cir_area_cut(double a, double r) {\n   \
    \ double s1 = a * r * r / 2;\n    double s2 = sin(a) * r * r / 2;\n    return\
    \ s1 - s2;\n}\n// Tested: http://codeforces.com/contest/600/problem/D\ndouble\
    \ commonCircleArea(Circle c1, Circle c2) { //return the common area of two circle\n\
    \    if (c1.r < c2.r) swap(c1, c2);\n    double d = (c1 - c2).len();\n    if (d\
    \ + c2.r <= c1.r + EPS) return c2.r*c2.r*M_PI;\n    if (d >= c1.r + c2.r - EPS)\
    \ return 0.0;\n    double a1 = cir_area_solve(d, c1.r, c2.r);\n    double a2 =\
    \ cir_area_solve(d, c2.r, c1.r);\n    return cir_area_cut(a1*2, c1.r) + cir_area_cut(a2*2,\
    \ c2.r);\n}\n\n// Check if 2 circle intersects. Return true if 2 circles touch\n\
    bool areIntersect(Circle u, Circle v) {\n    if (cmp((u - v).len(), u.r + v.r)\
    \ > 0) return false;\n    if (cmp((u - v).len() + v.r, u.r) < 0) return false;\n\
    \    if (cmp((u - v).len() + u.r, v.r) < 0) return false;\n    return true;\n\
    }\n\n// If 2 circle touches, will return 2 (same) points\n// If 2 circle are same\
    \ --> be careful\n// Tested:\n// - http://codeforces.com/gym/100803/ - H\n// -\
    \ http://codeforces.com/gym/100820/ - I\nvector<Point> circleIntersect(Circle\
    \ u, Circle v) {\n    vector<Point> res;\n    if (!areIntersect(u, v)) return\
    \ res;\n    double d = (u - v).len();\n    double alpha = acos((u.r * u.r + d*d\
    \ - v.r * v.r) / 2.0 / u.r / d);\n\n    Point p1 = (v - u).rotate(alpha);\n  \
    \  Point p2 = (v - u).rotate(-alpha);\n    res.push_back(p1 / p1.len() * u.r +\
    \ u);\n    res.push_back(p2 / p2.len() * u.r + u);\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/circle.h
  requiredBy:
  - Geometry/circle.cpp
  - Geometry/SPOJ_ALIENS.cpp
  timestamp: '2022-01-11 12:26:06+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Geometry/tests/aizu_cgl_7_a_cicle_tangents.test.cpp
  - Geometry/tests/aizu_cgl_7_g_circle_circle_tangent_points.test.cpp
  - Geometry/tests/aizu_cgl_7_e_circle_circle_intersection.test.cpp
  - Geometry/tests/aizu_cgl_7_f_circle_tangent_points.test.cpp
  - Geometry/tests/aizu_cgl_7_d_circle_line_intersection.test.cpp
  - Geometry/tests/aizu_cgl_7_i_circle_common_area.test.cpp
documentation_of: Geometry/circle.h
layout: document
redirect_from:
- /library/Geometry/circle.h
- /library/Geometry/circle.h.html
title: Geometry/circle.h
---
