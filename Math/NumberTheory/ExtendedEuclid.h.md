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
  bundledCode: "#line 1 \"Math/NumberTheory/ExtendedEuclid.h\"\n// D\xF9ng Extended\
    \ Euclid \u0111\u1EC3 t\xECm nghi\u1EC7m c\u1EE7a ph\u01B0\u01A1ng tr\xECnh ax\
    \ + by = gcd(a, b).\n// Gi\u1EA3 s\u1EED k\u1EBFt qu\u1EA3 tr\u1EA3 v\u1EC1 l\xE0\
    \ (x0, y0), h\u1ECD nghi\u1EC7m c\u1EE7a ph\u01B0\u01A1ng tr\xECnh s\u1EBD l\xE0\
    \ (x_0+kb/d,y_0-ka/d) v\u1EDBi k\u2208Z.\n// Ph\u01B0\u01A1ng tr\xECnh t\u1ED5\
    ng qu\xE1t ax + by = d ch\u1EC9 c\xF3 nghi\u1EC7m khi d chia h\u1EBFt cho gcd(a,\
    \ b).\n// a x + b y = gcd(a, b)\nint extgcd(int a, int b, int &x, int &y) {\n\
    \    int g = a; x = 1; y = 0;\n    if (b != 0) g = extgcd(b, a % b, y, x), y -=\
    \ (a / b) * x;\n    return g;\n}\n"
  code: "// D\xF9ng Extended Euclid \u0111\u1EC3 t\xECm nghi\u1EC7m c\u1EE7a ph\u01B0\
    \u01A1ng tr\xECnh ax + by = gcd(a, b).\n// Gi\u1EA3 s\u1EED k\u1EBFt qu\u1EA3\
    \ tr\u1EA3 v\u1EC1 l\xE0 (x0, y0), h\u1ECD nghi\u1EC7m c\u1EE7a ph\u01B0\u01A1\
    ng tr\xECnh s\u1EBD l\xE0 (x_0+kb/d,y_0-ka/d) v\u1EDBi k\u2208Z.\n// Ph\u01B0\u01A1\
    ng tr\xECnh t\u1ED5ng qu\xE1t ax + by = d ch\u1EC9 c\xF3 nghi\u1EC7m khi d chia\
    \ h\u1EBFt cho gcd(a, b).\n// a x + b y = gcd(a, b)\nint extgcd(int a, int b,\
    \ int &x, int &y) {\n    int g = a; x = 1; y = 0;\n    if (b != 0) g = extgcd(b,\
    \ a % b, y, x), y -= (a / b) * x;\n    return g;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/ExtendedEuclid.h
  requiredBy: []
  timestamp: '2015-02-02 18:15:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NumberTheory/ExtendedEuclid.h
layout: document
redirect_from:
- /library/Math/NumberTheory/ExtendedEuclid.h
- /library/Math/NumberTheory/ExtendedEuclid.h.html
title: Math/NumberTheory/ExtendedEuclid.h
---
