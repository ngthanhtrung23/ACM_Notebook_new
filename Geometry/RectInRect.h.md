---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/RectInRect.h\"\n// Checks if rectangle of sides\
    \ x,y fits inside one of sides X,Y\n// Not tested with doubles but should work\
    \ fine :)\n// Code as written rejects rectangles that just touch.\nbool rect_in_rect(int\
    \ X, int Y, int x, int y) {\n    if (Y > X) swap(Y, X);\n    if (y > x) swap(y,\
    \ x);\n    double diagonal = sqrt(double(X)*X + double(Y)*Y);\n    if (x < X &&\
    \ y < Y) return true;\n    else if (y >= Y || x >= diagonal) return false;\n \
    \   else {\n        double w, theta, tMin = PI/4, tMax = PI/2;\n        while\
    \ (tMax - tMin > EPS) {\n            theta = (tMax + tMin)/2.0;\n            w\
    \ = (Y-x*cos(theta))/sin(theta);\n            if (w < 0 || x * sin(theta) + w\
    \ * cos(theta) < X) tMin = theta;\n            else tMax = theta;\n        }\n\
    \        return (w > y);\n    }\n}\n"
  code: "// Checks if rectangle of sides x,y fits inside one of sides X,Y\n// Not\
    \ tested with doubles but should work fine :)\n// Code as written rejects rectangles\
    \ that just touch.\nbool rect_in_rect(int X, int Y, int x, int y) {\n    if (Y\
    \ > X) swap(Y, X);\n    if (y > x) swap(y, x);\n    double diagonal = sqrt(double(X)*X\
    \ + double(Y)*Y);\n    if (x < X && y < Y) return true;\n    else if (y >= Y ||\
    \ x >= diagonal) return false;\n    else {\n        double w, theta, tMin = PI/4,\
    \ tMax = PI/2;\n        while (tMax - tMin > EPS) {\n            theta = (tMax\
    \ + tMin)/2.0;\n            w = (Y-x*cos(theta))/sin(theta);\n            if (w\
    \ < 0 || x * sin(theta) + w * cos(theta) < X) tMin = theta;\n            else\
    \ tMax = theta;\n        }\n        return (w > y);\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/RectInRect.h
  requiredBy: []
  timestamp: '2015-10-03 11:58:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/RectInRect.h
layout: document
redirect_from:
- /library/Geometry/RectInRect.h
- /library/Geometry/RectInRect.h.html
title: Geometry/RectInRect.h
---
