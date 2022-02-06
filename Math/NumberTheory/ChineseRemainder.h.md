---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/NumberTheory/ExtendedEuclid.h
    title: Math/NumberTheory/ExtendedEuclid.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/ntt_any_mod_2.test.cpp
    title: Math/tests/ntt_any_mod_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://oj.vnoi.info/problem/icpc21_mt_d
    - https://open.kattis.com/problems/generalchineseremainder
  bundledCode: "#line 1 \"Math/NumberTheory/ChineseRemainder.h\"\n// Solve linear\
    \ congruences equation:\n// - a[i] * x = b[i] MOD m[i] (mi don't need to be co-prime)\n\
    // Tested:\n// - https://open.kattis.com/problems/generalchineseremainder\n//\
    \ - https://oj.vnoi.info/problem/icpc21_mt_d\n#line 1 \"Math/NumberTheory/ExtendedEuclid.h\"\
    \n// D\xF9ng Extended Euclid \u0111\u1EC3 t\xECm nghi\u1EC7m c\u1EE7a ph\u01B0\
    \u01A1ng tr\xECnh ax + by = gcd(a, b).\n// Gi\u1EA3 s\u1EED k\u1EBFt qu\u1EA3\
    \ tr\u1EA3 v\u1EC1 l\xE0 (x0, y0), h\u1ECD nghi\u1EC7m c\u1EE7a ph\u01B0\u01A1\
    ng tr\xECnh s\u1EBD l\xE0 (x_0+kb/d,y_0-ka/d) v\u1EDBi k\u2208Z.\n// Ph\u01B0\u01A1\
    ng tr\xECnh t\u1ED5ng qu\xE1t ax + by = d ch\u1EC9 c\xF3 nghi\u1EC7m khi d chia\
    \ h\u1EBFt cho gcd(a, b).\n// a x + b y = gcd(a, b)\ntemplate<typename T>\nT extgcd(T\
    \ a, T b, T &x, T &y) {\n    T g = a; x = 1; y = 0;\n    if (b != 0) g = extgcd(b,\
    \ a % b, y, x), y -= (a / b) * x;\n    return g;\n}\n#line 7 \"Math/NumberTheory/ChineseRemainder.h\"\
    \ntemplate<typename T>\nbool linearCongruences(\n        const vector<T> &a,\n\
    \        const vector<T> &b,\n        const vector<T> &m,\n        T &x,\n   \
    \     T &M\n) {\n    int n = a.size();\n    x = 0; M = 1;\n    for (int i = 0;\
    \ i < n; i++) {\n        T a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];\n \
    \       T y, t, g = extgcd<T>(a_, m_, y, t);\n        if (b_ % g) return false;\n\
    \        b_ /= g; m_ /= g;\n        x += M * (y * b_ % m_);\n        M *= m_;\n\
    \    }\n    x = (x + M) % M;\n    return true;\n}\n"
  code: "// Solve linear congruences equation:\n// - a[i] * x = b[i] MOD m[i] (mi\
    \ don't need to be co-prime)\n// Tested:\n// - https://open.kattis.com/problems/generalchineseremainder\n\
    // - https://oj.vnoi.info/problem/icpc21_mt_d\n#include \"ExtendedEuclid.h\"\n\
    template<typename T>\nbool linearCongruences(\n        const vector<T> &a,\n \
    \       const vector<T> &b,\n        const vector<T> &m,\n        T &x,\n    \
    \    T &M\n) {\n    int n = a.size();\n    x = 0; M = 1;\n    for (int i = 0;\
    \ i < n; i++) {\n        T a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];\n \
    \       T y, t, g = extgcd<T>(a_, m_, y, t);\n        if (b_ % g) return false;\n\
    \        b_ /= g; m_ /= g;\n        x += M * (y * b_ % m_);\n        M *= m_;\n\
    \    }\n    x = (x + M) % M;\n    return true;\n}\n"
  dependsOn:
  - Math/NumberTheory/ExtendedEuclid.h
  isVerificationFile: false
  path: Math/NumberTheory/ChineseRemainder.h
  requiredBy: []
  timestamp: '2022-02-06 13:20:09+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/ntt_any_mod_2.test.cpp
documentation_of: Math/NumberTheory/ChineseRemainder.h
layout: document
redirect_from:
- /library/Math/NumberTheory/ChineseRemainder.h
- /library/Math/NumberTheory/ChineseRemainder.h.html
title: Math/NumberTheory/ChineseRemainder.h
---
