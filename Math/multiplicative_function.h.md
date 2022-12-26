---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/cnt_divisors_stress.test.cpp
    title: Math/tests/cnt_divisors_stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1713
  bundledCode: "#line 1 \"Math/multiplicative_function.h\"\n// NOTE: calculate upto\
    \ N-1\n//\n// Multiplicative function {{{\ntemplate<int N>\nstruct MultiplicativeFunction\
    \ {\n    // Init sieve and pk\n    MultiplicativeFunction() {\n        // Init\
    \ sieve\n        for (int i = 2; i*i < N; i++) {\n            if (!sieve[i]) {\n\
    \                for (int j = i*i; j < N; j += i) {\n                    sieve[j]\
    \ = i;\n                }\n            }\n        }\n\n        // Init pk\n  \
    \      for (int i = 2; i < N; i++) {\n            if (!sieve[i]) {\n         \
    \       pk[i] = {i, 1};\n            } else {\n                int p = sieve[i];\n\
    \n                if (pk[i/p].first == p) { // i = p^k\n                    pk[i]\
    \ = {p, pk[i/p].second + 1};\n                } else {\n                    pk[i]\
    \ = {-1, 0};\n                }\n            }\n        }\n    }\n\n    // Tested:\
    \ https://cses.fi/problemset/task/1713\n    array<int, N> divisors() {\n     \
    \   array<int, N> res;\n        res[1] = 1;\n\n        for (int i = 2; i < N;\
    \ i++) {\n            if (pk[i].first > 0) {  // i = p^k\n                res[i]\
    \ = pk[i].second + 1;\n            } else {\n                // i = u * v, gcd(u,\
    \ v) = 1\n                int u = i, v = 1;\n                int p = sieve[i];\n\
    \                while (u % p == 0) {\n                    u /= p;\n         \
    \           v *= p;\n                }\n                res[i] = res[u] * res[v];\n\
    \            }\n        }\n\n        return res;\n    }\n\n// private:\n    //\
    \ sieve[i] == 0 if i is prime,\n    // sieve[i] = any prime factor p otherwise\n\
    \    array<int, N> sieve = {0};\n\n    // pk[i] = {p, k} if i == p^k\n    // pk[i]\
    \ = {-1, 0} otherwise\n    array<pair<int,int>, N> pk;\n};\n// }}}\n"
  code: "// NOTE: calculate upto N-1\n//\n// Multiplicative function {{{\ntemplate<int\
    \ N>\nstruct MultiplicativeFunction {\n    // Init sieve and pk\n    MultiplicativeFunction()\
    \ {\n        // Init sieve\n        for (int i = 2; i*i < N; i++) {\n        \
    \    if (!sieve[i]) {\n                for (int j = i*i; j < N; j += i) {\n  \
    \                  sieve[j] = i;\n                }\n            }\n        }\n\
    \n        // Init pk\n        for (int i = 2; i < N; i++) {\n            if (!sieve[i])\
    \ {\n                pk[i] = {i, 1};\n            } else {\n                int\
    \ p = sieve[i];\n\n                if (pk[i/p].first == p) { // i = p^k\n    \
    \                pk[i] = {p, pk[i/p].second + 1};\n                } else {\n\
    \                    pk[i] = {-1, 0};\n                }\n            }\n    \
    \    }\n    }\n\n    // Tested: https://cses.fi/problemset/task/1713\n    array<int,\
    \ N> divisors() {\n        array<int, N> res;\n        res[1] = 1;\n\n       \
    \ for (int i = 2; i < N; i++) {\n            if (pk[i].first > 0) {  // i = p^k\n\
    \                res[i] = pk[i].second + 1;\n            } else {\n          \
    \      // i = u * v, gcd(u, v) = 1\n                int u = i, v = 1;\n      \
    \          int p = sieve[i];\n                while (u % p == 0) {\n         \
    \           u /= p;\n                    v *= p;\n                }\n        \
    \        res[i] = res[u] * res[v];\n            }\n        }\n\n        return\
    \ res;\n    }\n\n// private:\n    // sieve[i] == 0 if i is prime,\n    // sieve[i]\
    \ = any prime factor p otherwise\n    array<int, N> sieve = {0};\n\n    // pk[i]\
    \ = {p, k} if i == p^k\n    // pk[i] = {-1, 0} otherwise\n    array<pair<int,int>,\
    \ N> pk;\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/multiplicative_function.h
  requiredBy: []
  timestamp: '2022-12-26 20:16:27+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/cnt_divisors_stress.test.cpp
documentation_of: Math/multiplicative_function.h
layout: document
redirect_from:
- /library/Math/multiplicative_function.h
- /library/Math/multiplicative_function.h.html
title: Math/multiplicative_function.h
---
