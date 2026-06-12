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
  bundledCode: "#line 1 \"Math/NumberTheory/FactorialMod.h\"\nint factmod (int n,\
    \ int p) { // n!, excluding p^k of course\n    int res = 1;\n    while (n > 1)\
    \ {\n        res = (res * ((n/p) % 2 ? p-1 : 1)) % p;\n        for (int i=2; i<=n%p;\
    \ ++i)\n            res = (res * i) % p;\n        n /= p;\n    }\n    return res\
    \ % p;\n}\n"
  code: "int factmod (int n, int p) { // n!, excluding p^k of course\n    int res\
    \ = 1;\n    while (n > 1) {\n        res = (res * ((n/p) % 2 ? p-1 : 1)) % p;\n\
    \        for (int i=2; i<=n%p; ++i)\n            res = (res * i) % p;\n      \
    \  n /= p;\n    }\n    return res % p;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/FactorialMod.h
  requiredBy: []
  timestamp: '2015-02-02 18:15:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NumberTheory/FactorialMod.h
layout: document
redirect_from:
- /library/Math/NumberTheory/FactorialMod.h
- /library/Math/NumberTheory/FactorialMod.h.html
title: Math/NumberTheory/FactorialMod.h
---
