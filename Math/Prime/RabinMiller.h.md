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
    - https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h
    - https://oj.vnoi.info/problem/icpc22_national_c
    - https://oj.vnoi.info/src/1816262)
  bundledCode: "#line 1 \"Math/Prime/RabinMiller.h\"\n// Use isPrime in Pollard.h\
    \ instead\n\n// Tested:\n// - (up to 10^19) https://oj.vnoi.info/problem/icpc22_national_c\n\
    //\n// If TLE, try:\n// 1. If numbers are <= 7.2e18 -> use modMul from KACTL:\n\
    //    https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h\n\
    // 2. Sieve and check for small primes separately\n// 3. Check divisible by first\
    \ 50 primes (see https://oj.vnoi.info/src/1816262)\n\n#include <initializer_list>\n\
    \nusing uint = unsigned long long;\nuint mult(uint x, uint y, uint mod) {\n  \
    \  return __int128_t(x) * y % mod;\n}\n\nuint powMod(uint x, uint p, uint mod)\
    \ {\n    if (p == 0) return 1;\n    if (p % 2) return mult(x, powMod(x, p - 1,\
    \ mod), mod);\n    return powMod(mult(x, x, mod), p / 2, mod);\n}\n\nbool checkMillerRabin(uint\
    \ x, uint mod, uint s, int k) {\n    x = powMod(x, s, mod);\n    if (x == 1) return\
    \ true;\n    while(k--) {\n        if (x == mod - 1) return true;\n        x =\
    \ mult(x, x, mod);\n        if (x == 1) return false;\n    }\n    return false;\n\
    }\n\nbool is_prime(uint x) {\n    if (x == 2 || x == 3 || x == 5 || x == 7) return\
    \ true;\n    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return\
    \ false;\n    if (x < 121) return x > 1;\n\n    uint s = x - 1;\n    int k = 0;\n\
    \    while (s % 2 == 0) {\n        s /= 2;\n        k++;\n    }\n    if (x < 1LL\
    \ << 32) {\n        for (uint z : {2, 7, 61}) {\n            if (!checkMillerRabin(z,\
    \ x, s, k)) return false;\n        }\n    } else {\n        for (uint z : {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n            if (!checkMillerRabin(z,\
    \ x, s, k)) return false;\n        }\n    }\n    return true;\n}\n"
  code: "// Use isPrime in Pollard.h instead\n\n// Tested:\n// - (up to 10^19) https://oj.vnoi.info/problem/icpc22_national_c\n\
    //\n// If TLE, try:\n// 1. If numbers are <= 7.2e18 -> use modMul from KACTL:\n\
    //    https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/ModMulLL.h\n\
    // 2. Sieve and check for small primes separately\n// 3. Check divisible by first\
    \ 50 primes (see https://oj.vnoi.info/src/1816262)\n\n#include <initializer_list>\n\
    \nusing uint = unsigned long long;\nuint mult(uint x, uint y, uint mod) {\n  \
    \  return __int128_t(x) * y % mod;\n}\n\nuint powMod(uint x, uint p, uint mod)\
    \ {\n    if (p == 0) return 1;\n    if (p % 2) return mult(x, powMod(x, p - 1,\
    \ mod), mod);\n    return powMod(mult(x, x, mod), p / 2, mod);\n}\n\nbool checkMillerRabin(uint\
    \ x, uint mod, uint s, int k) {\n    x = powMod(x, s, mod);\n    if (x == 1) return\
    \ true;\n    while(k--) {\n        if (x == mod - 1) return true;\n        x =\
    \ mult(x, x, mod);\n        if (x == 1) return false;\n    }\n    return false;\n\
    }\n\nbool is_prime(uint x) {\n    if (x == 2 || x == 3 || x == 5 || x == 7) return\
    \ true;\n    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return\
    \ false;\n    if (x < 121) return x > 1;\n\n    uint s = x - 1;\n    int k = 0;\n\
    \    while (s % 2 == 0) {\n        s /= 2;\n        k++;\n    }\n    if (x < 1LL\
    \ << 32) {\n        for (uint z : {2, 7, 61}) {\n            if (!checkMillerRabin(z,\
    \ x, s, k)) return false;\n        }\n    } else {\n        for (uint z : {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n            if (!checkMillerRabin(z,\
    \ x, s, k)) return false;\n        }\n    }\n    return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Prime/RabinMiller.h
  requiredBy: []
  timestamp: '2022-11-13 20:55:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Prime/RabinMiller.h
layout: document
redirect_from:
- /library/Math/Prime/RabinMiller.h
- /library/Math/Prime/RabinMiller.h.html
title: Math/Prime/RabinMiller.h
---
