---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://mathworld.wolfram.com/images/eps-gif/SphericalCoordinates_1201.gif
  bundledCode: "#line 1 \"Geometry/spherical.h\"\nstruct Point3 {\n    double x, y,\
    \ z;\n\n    Point3(Spherical P) {\n        x = P.r * cos(P.theta) * sin(P.phi);\n\
    \        y = P.r * sin(P.theta) * sin(P.phi);\n        z = P.r * cos(P.phi);\n\
    \    }\n};\n\n// http://mathworld.wolfram.com/images/eps-gif/SphericalCoordinates_1201.gif\n\
    struct Spherical {\n    double r,\n        theta, // 0 <= theta < 2*PI\n     \
    \   phi;   // 0 <= phi <= PI\n\n    Spherical(Point3 P) {\n        r = sqrt(P.x*P.x\
    \ + P.y*P.y + P.z*P.z);\n        theta = atan(P.y / P.x); if (theta < 0) theta\
    \ += 2 * PI;\n        phi = acos(P.z / r);\n    }\n};\n"
  code: "struct Point3 {\n    double x, y, z;\n\n    Point3(Spherical P) {\n     \
    \   x = P.r * cos(P.theta) * sin(P.phi);\n        y = P.r * sin(P.theta) * sin(P.phi);\n\
    \        z = P.r * cos(P.phi);\n    }\n};\n\n// http://mathworld.wolfram.com/images/eps-gif/SphericalCoordinates_1201.gif\n\
    struct Spherical {\n    double r,\n        theta, // 0 <= theta < 2*PI\n     \
    \   phi;   // 0 <= phi <= PI\n\n    Spherical(Point3 P) {\n        r = sqrt(P.x*P.x\
    \ + P.y*P.y + P.z*P.z);\n        theta = atan(P.y / P.x); if (theta < 0) theta\
    \ += 2 * PI;\n        phi = acos(P.z / r);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/spherical.h
  requiredBy: []
  timestamp: '2014-10-07 04:14:22+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/spherical.h
layout: document
redirect_from:
- /library/Geometry/spherical.h
- /library/Geometry/spherical.h.html
title: Geometry/spherical.h
---
