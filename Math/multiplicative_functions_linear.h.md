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
    - https://codeforces.com/blog/entry/54090
  bundledCode: "#line 1 \"Math/multiplicative_functions_linear.h\"\n// This is only\
    \ for calculating multiplicative functions\n// If we need a fast sieve, see SieveFast.h\n\
    // From https://codeforces.com/blog/entry/54090\nconst int MN = 2e7;\nvector<int>\
    \ primes;\n\n// Euler Phi {{{\nbool is_composite[MAXN];\nint phi[MAXN];\n\nvoid\
    \ linear_sieve_phi(int n) {\n    memset(is_composite, false, sizeof is_composite);\n\
    \    primes.clear();\n \n    phi[1] = 1;\n    for (int i = 2; i < n; ++i) {\n\
    \        if (!is_composite[i]) {\n            prime.push_back(i);\n          \
    \  phi[i] = i - 1; // i is prime\n        }\n        for (int j = 0; j < prime.size\
    \ () && i * prime[j] < n; ++j) {\n            is_composite[i * prime[j]] = true;\n\
    \            if (i % prime[j] == 0) {\n                phi[i * prime[j]] = phi[i]\
    \ * prime[j]; //prime[j] divides i\n                break;\n            } else\
    \ {\n                phi[i * prime[j]] = phi[i] * phi[prime[j]]; //prime[j] does\
    \ not divide i\n            }\n        }\n    }\n}\n// }}}\n\n// Number of divisors\
    \ {{{\nint cnt_divisors[MN + 11];  // call linear_sieve_divisors(n+1) to init\n\
    int cnt[MN + 11];\nvoid linear_sieve_divisors(int n) {  // init range [1, n-1]\n\
    \    memset(is_composite, false, sizeof is_composite);\n    primes.clear();\n\n\
    \    cnt_divisors[1] = 1;\n    for (int i = 2; i < n; ++i) {\n        if (!is_composite[i])\
    \ {\n            primes.push_back(i);\n            cnt[i] = 1;\n            cnt_divisors[i]\
    \ = 2;\n        }\n        for (int j = 0; j < (int) primes.size() && i * primes[j]\
    \ < n; ++j) {\n            int ip = i * primes[j];\n            is_composite[ip]\
    \ = true;\n            if (i % primes[j] == 0) {\n                cnt[ip] = cnt[i]\
    \ + 1;\n                cnt_divisors[ip] = cnt_divisors[i] / (cnt[i] + 1) * (cnt[i]\
    \ + 2);\n            } else {\n                cnt[ip] = 1;\n                cnt_divisors[ip]\
    \ = 2 * cnt_divisors[i];\n            }\n        }\n    }\n}\n// }}}\n"
  code: "// This is only for calculating multiplicative functions\n// If we need a\
    \ fast sieve, see SieveFast.h\n// From https://codeforces.com/blog/entry/54090\n\
    const int MN = 2e7;\nvector<int> primes;\n\n// Euler Phi {{{\nbool is_composite[MAXN];\n\
    int phi[MAXN];\n\nvoid linear_sieve_phi(int n) {\n    memset(is_composite, false,\
    \ sizeof is_composite);\n    primes.clear();\n \n    phi[1] = 1;\n    for (int\
    \ i = 2; i < n; ++i) {\n        if (!is_composite[i]) {\n            prime.push_back(i);\n\
    \            phi[i] = i - 1; // i is prime\n        }\n        for (int j = 0;\
    \ j < prime.size () && i * prime[j] < n; ++j) {\n            is_composite[i *\
    \ prime[j]] = true;\n            if (i % prime[j] == 0) {\n                phi[i\
    \ * prime[j]] = phi[i] * prime[j]; //prime[j] divides i\n                break;\n\
    \            } else {\n                phi[i * prime[j]] = phi[i] * phi[prime[j]];\
    \ //prime[j] does not divide i\n            }\n        }\n    }\n}\n// }}}\n\n\
    // Number of divisors {{{\nint cnt_divisors[MN + 11];  // call linear_sieve_divisors(n+1)\
    \ to init\nint cnt[MN + 11];\nvoid linear_sieve_divisors(int n) {  // init range\
    \ [1, n-1]\n    memset(is_composite, false, sizeof is_composite);\n    primes.clear();\n\
    \n    cnt_divisors[1] = 1;\n    for (int i = 2; i < n; ++i) {\n        if (!is_composite[i])\
    \ {\n            primes.push_back(i);\n            cnt[i] = 1;\n            cnt_divisors[i]\
    \ = 2;\n        }\n        for (int j = 0; j < (int) primes.size() && i * primes[j]\
    \ < n; ++j) {\n            int ip = i * primes[j];\n            is_composite[ip]\
    \ = true;\n            if (i % primes[j] == 0) {\n                cnt[ip] = cnt[i]\
    \ + 1;\n                cnt_divisors[ip] = cnt_divisors[i] / (cnt[i] + 1) * (cnt[i]\
    \ + 2);\n            } else {\n                cnt[ip] = 1;\n                cnt_divisors[ip]\
    \ = 2 * cnt_divisors[i];\n            }\n        }\n    }\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/multiplicative_functions_linear.h
  requiredBy: []
  timestamp: '2022-12-25 01:23:17+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/multiplicative_functions_linear.h
layout: document
redirect_from:
- /library/Math/multiplicative_functions_linear.h
- /library/Math/multiplicative_functions_linear.h.html
title: Math/multiplicative_functions_linear.h
---
