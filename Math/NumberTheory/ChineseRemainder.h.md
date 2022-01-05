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
    - https://oj.vnoi.info/problem/icpc21_mt_d
    - https://open.kattis.com/problems/generalchineseremainder
  bundledCode: "#line 1 \"Math/NumberTheory/ChineseRemainder.h\"\n// Solve linear\
    \ congruences equation:\n// - a[i] * x = b[i] MOD m[i] (mi don't need to be co-prime)\n\
    // Tested:\n// - https://open.kattis.com/problems/generalchineseremainder\n//\
    \ - https://oj.vnoi.info/problem/icpc21_mt_d\nbool linearCongruences(\n      \
    \  const vector<long long> &a,\n        const vector<long long> &b,\n        const\
    \ vector<long long> &m,\n        long long &x,\n        long long &M\n) {\n  \
    \  long long n = a.size();\n    x = 0; M = 1;\n    REP(i, n) {\n        long long\
    \ a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];\n        long long y, t, g =\
    \ extgcd(a_, m_, y, t);\n        if (b_ % g) return false;\n        b_ /= g; m_\
    \ /= g;\n        x += M * (y * b_ % m_);\n        M *= m_;\n    }\n    x = (x\
    \ + M) % M;\n    return true;\n}\n"
  code: "// Solve linear congruences equation:\n// - a[i] * x = b[i] MOD m[i] (mi\
    \ don't need to be co-prime)\n// Tested:\n// - https://open.kattis.com/problems/generalchineseremainder\n\
    // - https://oj.vnoi.info/problem/icpc21_mt_d\nbool linearCongruences(\n     \
    \   const vector<long long> &a,\n        const vector<long long> &b,\n       \
    \ const vector<long long> &m,\n        long long &x,\n        long long &M\n)\
    \ {\n    long long n = a.size();\n    x = 0; M = 1;\n    REP(i, n) {\n       \
    \ long long a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];\n        long long\
    \ y, t, g = extgcd(a_, m_, y, t);\n        if (b_ % g) return false;\n       \
    \ b_ /= g; m_ /= g;\n        x += M * (y * b_ % m_);\n        M *= m_;\n    }\n\
    \    x = (x + M) % M;\n    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/ChineseRemainder.h
  requiredBy: []
  timestamp: '2021-12-13 17:33:56+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NumberTheory/ChineseRemainder.h
layout: document
redirect_from:
- /library/Math/NumberTheory/ChineseRemainder.h
- /library/Math/NumberTheory/ChineseRemainder.h.html
title: Math/NumberTheory/ChineseRemainder.h
---
