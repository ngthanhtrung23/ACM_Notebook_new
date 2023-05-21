---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/NumberTheory/ChineseRemainder.h
    title: Math/NumberTheory/ChineseRemainder.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_1_e_extended_euclid.test.cpp
    title: Math/tests/aizu_ntl_1_e_extended_euclid.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/ntt_chemthan_any_mod_2.test.cpp
    title: Math/tests/ntt_chemthan_any_mod_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/NumberTheory/ExtendedEuclid.h\"\n// D\xF9ng Extended\
    \ Euclid \u0111\u1EC3 t\xECm nghi\u1EC7m c\u1EE7a ph\u01B0\u01A1ng tr\xECnh ax\
    \ + by = gcd(a, b).\n// Gi\u1EA3 s\u1EED k\u1EBFt qu\u1EA3 tr\u1EA3 v\u1EC1 l\xE0\
    \ (x0, y0), h\u1ECD nghi\u1EC7m c\u1EE7a ph\u01B0\u01A1ng tr\xECnh s\u1EBD l\xE0\
    \ (x_0+kb/d,y_0-ka/d) v\u1EDBi k\u2208Z.\n// Ph\u01B0\u01A1ng tr\xECnh t\u1ED5\
    ng qu\xE1t ax + by = d ch\u1EC9 c\xF3 nghi\u1EC7m khi d chia h\u1EBFt cho gcd(a,\
    \ b).\n// a x + b y = gcd(a, b)\ntemplate<typename T>\nT extgcd(T a, T b, T &x,\
    \ T &y) {\n    T g = a; x = 1; y = 0;\n    if (b != 0) g = extgcd(b, a % b, y,\
    \ x), y -= (a / b) * x;\n    return g;\n}\n"
  code: "// D\xF9ng Extended Euclid \u0111\u1EC3 t\xECm nghi\u1EC7m c\u1EE7a ph\u01B0\
    \u01A1ng tr\xECnh ax + by = gcd(a, b).\n// Gi\u1EA3 s\u1EED k\u1EBFt qu\u1EA3\
    \ tr\u1EA3 v\u1EC1 l\xE0 (x0, y0), h\u1ECD nghi\u1EC7m c\u1EE7a ph\u01B0\u01A1\
    ng tr\xECnh s\u1EBD l\xE0 (x_0+kb/d,y_0-ka/d) v\u1EDBi k\u2208Z.\n// Ph\u01B0\u01A1\
    ng tr\xECnh t\u1ED5ng qu\xE1t ax + by = d ch\u1EC9 c\xF3 nghi\u1EC7m khi d chia\
    \ h\u1EBFt cho gcd(a, b).\n// a x + b y = gcd(a, b)\ntemplate<typename T>\nT extgcd(T\
    \ a, T b, T &x, T &y) {\n    T g = a; x = 1; y = 0;\n    if (b != 0) g = extgcd(b,\
    \ a % b, y, x), y -= (a / b) * x;\n    return g;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/ExtendedEuclid.h
  requiredBy:
  - Math/NumberTheory/ChineseRemainder.h
  timestamp: '2022-01-06 17:46:09+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/aizu_ntl_1_e_extended_euclid.test.cpp
  - Math/tests/ntt_chemthan_any_mod_2.test.cpp
documentation_of: Math/NumberTheory/ExtendedEuclid.h
layout: document
redirect_from:
- /library/Math/NumberTheory/ExtendedEuclid.h
- /library/Math/NumberTheory/ExtendedEuclid.h.html
title: Math/NumberTheory/ExtendedEuclid.h
---
