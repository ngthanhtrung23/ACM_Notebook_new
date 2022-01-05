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
  bundledCode: "#line 1 \"Math/NumberTheory/PrimitiveRoot.h\"\n// Primitive root of\
    \ modulo n is integer g iff for all a < n & gcd(a, n) == 1, there exist k: g^k\
    \ = a mod n\n// k is called discrete log of a (in case P is prime, can find in\
    \ O(sqrt(P)) by noting that (P-1) is divisible by k)\n//\n// Exist if:\n// - n\
    \ is 1, 2, 4\n// - n = p^k for odd prime p\n// - n = 2*p^k for odd prime p\nint\
    \ powmod (int a, int b, int p) {\n    int res = 1;\n    while (b)\n        if\
    \ (b & 1)\n            res = int (res * 1ll * a % p),  --b;\n        else\n  \
    \          a = int (a * 1ll * a % p),  b >>= 1;\n    return res;\n}\n \nint generator\
    \ (int p) {\n    vector<int> fact;\n    int phi = p-1,  n = phi;\n    for (int\
    \ i=2; i*i<=n; ++i)\n        if (n % i == 0) {\n            fact.push_back (i);\n\
    \            while (n % i == 0)\n                n /= i;\n        }\n    if (n\
    \ > 1)\n        fact.push_back (n);\n \n    for (int res=2; res<=p; ++res) {\n\
    \        bool ok = true;\n        for (size_t i=0; i<fact.size() && ok; ++i)\n\
    \            ok &= powmod (res, phi / fact[i], p) != 1;\n        if (ok)  return\
    \ res;\n    }\n    return -1;\n}\n"
  code: "// Primitive root of modulo n is integer g iff for all a < n & gcd(a, n)\
    \ == 1, there exist k: g^k = a mod n\n// k is called discrete log of a (in case\
    \ P is prime, can find in O(sqrt(P)) by noting that (P-1) is divisible by k)\n\
    //\n// Exist if:\n// - n is 1, 2, 4\n// - n = p^k for odd prime p\n// - n = 2*p^k\
    \ for odd prime p\nint powmod (int a, int b, int p) {\n    int res = 1;\n    while\
    \ (b)\n        if (b & 1)\n            res = int (res * 1ll * a % p),  --b;\n\
    \        else\n            a = int (a * 1ll * a % p),  b >>= 1;\n    return res;\n\
    }\n \nint generator (int p) {\n    vector<int> fact;\n    int phi = p-1,  n =\
    \ phi;\n    for (int i=2; i*i<=n; ++i)\n        if (n % i == 0) {\n          \
    \  fact.push_back (i);\n            while (n % i == 0)\n                n /= i;\n\
    \        }\n    if (n > 1)\n        fact.push_back (n);\n \n    for (int res=2;\
    \ res<=p; ++res) {\n        bool ok = true;\n        for (size_t i=0; i<fact.size()\
    \ && ok; ++i)\n            ok &= powmod (res, phi / fact[i], p) != 1;\n      \
    \  if (ok)  return res;\n    }\n    return -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/PrimitiveRoot.h
  requiredBy: []
  timestamp: '2016-03-13 16:40:38+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NumberTheory/PrimitiveRoot.h
layout: document
redirect_from:
- /library/Math/NumberTheory/PrimitiveRoot.h
- /library/Math/NumberTheory/PrimitiveRoot.h.html
title: Math/NumberTheory/PrimitiveRoot.h
---
