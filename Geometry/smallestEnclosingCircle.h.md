---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Geometry/SPOJ_ALIENS.cpp
    title: Geometry/SPOJ_ALIENS.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://oj.vnoi.info/problem/icpc22_mt_l
    - https://www.acmicpc.net/problem/2626
    - https://www.spoj.com/problems/ALIENS/
    - https://www.spoj.com/problems/QCJ4/
  bundledCode: "#line 1 \"Geometry/smallestEnclosingCircle.h\"\n// Smallest enclosing\
    \ circle:\n// Given N points. Find the smallest circle enclosing these points.\n\
    // Amortized complexity: O(N)\n//\n// Tested:\n// - https://www.spoj.com/problems/ALIENS/\n\
    // - https://www.spoj.com/problems/QCJ4/\n// - https://www.acmicpc.net/problem/2626\n\
    // - https://oj.vnoi.info/problem/icpc22_mt_l\n\nstruct SmallestEnclosingCircle\
    \ {\n    Circle getCircle(vector<Point> points) {\n        assert(!points.empty());\n\
    \n        random_shuffle(points.begin(), points.end());\n        Circle c(points[0],\
    \ 0);\n        int n = points.size();\n\n        for (int i = 1; i < n; i++)\n\
    \            if ((points[i] - c).len() > c.r + EPS)\n            {\n         \
    \       c = Circle(points[i], 0);\n                for (int j = 0; j < i; j++)\n\
    \                    if ((points[j] - c).len() > c.r + EPS)\n                \
    \    {\n                        c = Circle((points[i] + points[j]) / 2, (points[i]\
    \ - points[j]).len() / 2);\n                        for (int k = 0; k < j; k++)\n\
    \                            if ((points[k] - c).len() > c.r + EPS)\n        \
    \                        c = getCircumcircle(points[i], points[j], points[k]);\n\
    \                    }\n            }\n\n        return c;\n    }\n\n    // NOTE:\
    \ This code work only when a, b, c are not collinear and no 2 points are same\
    \ --> DO NOT\n    // copy and use in other cases.\n    Circle getCircumcircle(Point\
    \ a, Point b, Point c) {\n        assert(a != b && b != c && a != c);\n      \
    \  assert(ccw(a, b, c));\n\n        double d = 2.0 * (a.x * (b.y - c.y) + b.x\
    \ * (c.y - a.y) + c.x * (a.y - b.y));\n        assert(fabs(d) > EPS);\n      \
    \  double x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y\
    \ - b.y)) / d;\n        double y = (a.norm() * (c.x - b.x) + b.norm() * (a.x -\
    \ c.x) + c.norm() * (b.x - a.x)) / d;\n        Point p(x, y);\n        return\
    \ Circle(p, (p - a).len());\n    }\n};\n"
  code: "// Smallest enclosing circle:\n// Given N points. Find the smallest circle\
    \ enclosing these points.\n// Amortized complexity: O(N)\n//\n// Tested:\n// -\
    \ https://www.spoj.com/problems/ALIENS/\n// - https://www.spoj.com/problems/QCJ4/\n\
    // - https://www.acmicpc.net/problem/2626\n// - https://oj.vnoi.info/problem/icpc22_mt_l\n\
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
    \        return Circle(p, (p - a).len());\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/smallestEnclosingCircle.h
  requiredBy:
  - Geometry/SPOJ_ALIENS.cpp
  timestamp: '2022-10-24 15:47:24+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/smallestEnclosingCircle.h
layout: document
redirect_from:
- /library/Geometry/smallestEnclosingCircle.h
- /library/Geometry/smallestEnclosingCircle.h.html
title: Geometry/smallestEnclosingCircle.h
---
