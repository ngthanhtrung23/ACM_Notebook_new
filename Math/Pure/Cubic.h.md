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
  bundledCode: "#line 1 \"Math/Pure/Cubic.h\"\nconst double EPS = 1e-6;\nstruct Result\
    \ {\n    int n; // Number of solutions\n    double x[3]; // Solutions\n};\nResult\
    \ solve_cubic(double a, double b, double c, double d) {\n    long double a1 =\
    \ b/a, a2 = c/a, a3 = d/a;\n    long double q = (a1*a1 - 3*a2)/9.0, sq = -2*sqrt(q);\n\
    \    long double r = (2*a1*a1*a1 - 9*a1*a2 + 27*a3)/54.0;\n    double z = r*r-q*q*q,\
    \ theta;\n    Result s;\n    if(z <= EPS) {\n        s.n = 3; theta = acos(r/sqrt(q*q*q));\n\
    \        s.x[0] = sq*cos(theta/3.0) - a1/3.0;\n        s.x[1] = sq*cos((theta+2.0*PI)/3.0)\
    \ - a1/3.0;\n        s.x[2] = sq*cos((theta+4.0*PI)/3.0) - a1/3.0;\n    }\n  \
    \  else {\n        s.n = 1; s.x[0] = pow(sqrt(z)+fabs(r),1/3.0);\n        s.x[0]\
    \ += q/s.x[0]; s.x[0] *= (r < 0) ? 1 : -1;\n        s.x[0] -= a1/3.0;\n    }\n\
    \    return s;\n}\n"
  code: "const double EPS = 1e-6;\nstruct Result {\n    int n; // Number of solutions\n\
    \    double x[3]; // Solutions\n};\nResult solve_cubic(double a, double b, double\
    \ c, double d) {\n    long double a1 = b/a, a2 = c/a, a3 = d/a;\n    long double\
    \ q = (a1*a1 - 3*a2)/9.0, sq = -2*sqrt(q);\n    long double r = (2*a1*a1*a1 -\
    \ 9*a1*a2 + 27*a3)/54.0;\n    double z = r*r-q*q*q, theta;\n    Result s;\n  \
    \  if(z <= EPS) {\n        s.n = 3; theta = acos(r/sqrt(q*q*q));\n        s.x[0]\
    \ = sq*cos(theta/3.0) - a1/3.0;\n        s.x[1] = sq*cos((theta+2.0*PI)/3.0) -\
    \ a1/3.0;\n        s.x[2] = sq*cos((theta+4.0*PI)/3.0) - a1/3.0;\n    }\n    else\
    \ {\n        s.n = 1; s.x[0] = pow(sqrt(z)+fabs(r),1/3.0);\n        s.x[0] +=\
    \ q/s.x[0]; s.x[0] *= (r < 0) ? 1 : -1;\n        s.x[0] -= a1/3.0;\n    }\n  \
    \  return s;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Pure/Cubic.h
  requiredBy: []
  timestamp: '2019-10-13 14:36:50+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Pure/Cubic.h
layout: document
redirect_from:
- /library/Math/Pure/Cubic.h
- /library/Math/Pure/Cubic.h.html
title: Math/Pure/Cubic.h
---
