---
data:
  _extendedDependsOn: []
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
    \ - https://oj.vnoi.info/problem/icpc21_mt_d\ntemplate<typename T>\nbool linearCongruences(\n\
    \        const vector<T> &a,\n        const vector<T> &b,\n        const vector<T>\
    \ &m,\n        T &x,\n        T &M\n) {\n    int n = a.size();\n    x = 0; M =\
    \ 1;\n    for (int i = 0; i < n; i++) {\n        T a_ = a[i] * M, b_ = b[i] -\
    \ a[i] * x, m_ = m[i];\n        T y, t, g = extgcd<T>(a_, m_, y, t);\n       \
    \ if (b_ % g) return false;\n        b_ /= g; m_ /= g;\n        x += M * (y *\
    \ b_ % m_);\n        M *= m_;\n    }\n    x = (x + M) % M;\n    return true;\n\
    }\n"
  code: "// Solve linear congruences equation:\n// - a[i] * x = b[i] MOD m[i] (mi\
    \ don't need to be co-prime)\n// Tested:\n// - https://open.kattis.com/problems/generalchineseremainder\n\
    // - https://oj.vnoi.info/problem/icpc21_mt_d\ntemplate<typename T>\nbool linearCongruences(\n\
    \        const vector<T> &a,\n        const vector<T> &b,\n        const vector<T>\
    \ &m,\n        T &x,\n        T &M\n) {\n    int n = a.size();\n    x = 0; M =\
    \ 1;\n    for (int i = 0; i < n; i++) {\n        T a_ = a[i] * M, b_ = b[i] -\
    \ a[i] * x, m_ = m[i];\n        T y, t, g = extgcd<T>(a_, m_, y, t);\n       \
    \ if (b_ % g) return false;\n        b_ /= g; m_ /= g;\n        x += M * (y *\
    \ b_ % m_);\n        M *= m_;\n    }\n    x = (x + M) % M;\n    return true;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/ChineseRemainder.h
  requiredBy: []
  timestamp: '2022-01-06 17:46:09+08:00'
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
