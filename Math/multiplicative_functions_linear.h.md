---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/cnt_divisors_stress.test.cpp
    title: Math/tests/cnt_divisors_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/euler_phi_stress.test.cpp
    title: Math/tests/euler_phi_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/smallest_prime_factor_stress.test.cpp
    title: Math/tests/smallest_prime_factor_stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/54090
  bundledCode: "#line 1 \"Math/multiplicative_functions_linear.h\"\n// This is only\
    \ for calculating multiplicative functions\n// If we need a fast sieve, see SieveFast.h\n\
    // From https://codeforces.com/blog/entry/54090\nnamespace linear_sieve {\nconst\
    \ int MN = 2e7;\nvector<int> primes;\n\nint smallest_p[MN];  // smallest_p[n]\
    \ = smallest prime factor of n\nvoid linear_sieve_smallest_prime_factor(int n)\
    \ {\n    primes.clear();\n    memset(smallest_p, 0, sizeof smallest_p);\n\n  \
    \  for (int i = 2; i < n; ++i) {\n        if (!smallest_p[i]) primes.push_back(i);\n\
    \        for (int j = 0; j < int(primes.size()) && i * primes[j] < n; ++j) {\n\
    \            smallest_p[i * primes[j]] = primes[j];\n            if (i % primes[j]\
    \ == 0) break;\n        }\n    }\n}\n\n// Euler Phi {{{\nbool is_composite[MN];\n\
    int phi[MN];\n\nvoid linear_sieve_phi(int n) {\n    memset(is_composite, false,\
    \ sizeof is_composite);\n    primes.clear();\n \n    phi[1] = 1;\n    for (int\
    \ i = 2; i < n; ++i) {\n        if (!is_composite[i]) {\n            primes.push_back(i);\n\
    \            phi[i] = i - 1; // i is prime\n        }\n        for (int j = 0;\
    \ j < (int) primes.size() && i * primes[j] < n; ++j) {\n            is_composite[i\
    \ * primes[j]] = true;\n            if (i % primes[j] == 0) {\n              \
    \  phi[i * primes[j]] = phi[i] * primes[j]; //primes[j] divides i\n          \
    \      break;\n            } else {\n                phi[i * primes[j]] = phi[i]\
    \ * phi[primes[j]]; //primes[j] does not divide i\n            }\n        }\n\
    \    }\n}\n// }}}\n\n// Number of divisors {{{\nint cnt_divisors[MN + 11];  //\
    \ call linear_sieve_divisors(n+1) to init\nint cnt[MN + 11];           // power\
    \ of smallest prime factor of i\nvoid linear_sieve_divisors(int n) {  // init\
    \ range [1, n-1]\n    memset(is_composite, false, sizeof is_composite);\n    primes.clear();\n\
    \n    cnt_divisors[1] = 1;\n    for (int i = 2; i < n; ++i) {\n        if (!is_composite[i])\
    \ {\n            primes.push_back(i);\n            cnt[i] = 1;\n            cnt_divisors[i]\
    \ = 2;\n        }\n        for (int j = 0; j < (int) primes.size() && i * primes[j]\
    \ < n; ++j) {\n            int ip = i * primes[j];\n            is_composite[ip]\
    \ = true;\n            if (i % primes[j] == 0) {\n                cnt[ip] = cnt[i]\
    \ + 1;\n                cnt_divisors[ip] = cnt_divisors[i] / (cnt[i] + 1) * (cnt[i]\
    \ + 2);\n            } else {\n                cnt[ip] = 1;\n                cnt_divisors[ip]\
    \ = 2 * cnt_divisors[i];\n            }\n        }\n    }\n}\n// }}}\n\n}\n"
  code: "// This is only for calculating multiplicative functions\n// If we need a\
    \ fast sieve, see SieveFast.h\n// From https://codeforces.com/blog/entry/54090\n\
    namespace linear_sieve {\nconst int MN = 2e7;\nvector<int> primes;\n\nint smallest_p[MN];\
    \  // smallest_p[n] = smallest prime factor of n\nvoid linear_sieve_smallest_prime_factor(int\
    \ n) {\n    primes.clear();\n    memset(smallest_p, 0, sizeof smallest_p);\n\n\
    \    for (int i = 2; i < n; ++i) {\n        if (!smallest_p[i]) primes.push_back(i);\n\
    \        for (int j = 0; j < int(primes.size()) && i * primes[j] < n; ++j) {\n\
    \            smallest_p[i * primes[j]] = primes[j];\n            if (i % primes[j]\
    \ == 0) break;\n        }\n    }\n}\n\n// Euler Phi {{{\nbool is_composite[MN];\n\
    int phi[MN];\n\nvoid linear_sieve_phi(int n) {\n    memset(is_composite, false,\
    \ sizeof is_composite);\n    primes.clear();\n \n    phi[1] = 1;\n    for (int\
    \ i = 2; i < n; ++i) {\n        if (!is_composite[i]) {\n            primes.push_back(i);\n\
    \            phi[i] = i - 1; // i is prime\n        }\n        for (int j = 0;\
    \ j < (int) primes.size() && i * primes[j] < n; ++j) {\n            is_composite[i\
    \ * primes[j]] = true;\n            if (i % primes[j] == 0) {\n              \
    \  phi[i * primes[j]] = phi[i] * primes[j]; //primes[j] divides i\n          \
    \      break;\n            } else {\n                phi[i * primes[j]] = phi[i]\
    \ * phi[primes[j]]; //primes[j] does not divide i\n            }\n        }\n\
    \    }\n}\n// }}}\n\n// Number of divisors {{{\nint cnt_divisors[MN + 11];  //\
    \ call linear_sieve_divisors(n+1) to init\nint cnt[MN + 11];           // power\
    \ of smallest prime factor of i\nvoid linear_sieve_divisors(int n) {  // init\
    \ range [1, n-1]\n    memset(is_composite, false, sizeof is_composite);\n    primes.clear();\n\
    \n    cnt_divisors[1] = 1;\n    for (int i = 2; i < n; ++i) {\n        if (!is_composite[i])\
    \ {\n            primes.push_back(i);\n            cnt[i] = 1;\n            cnt_divisors[i]\
    \ = 2;\n        }\n        for (int j = 0; j < (int) primes.size() && i * primes[j]\
    \ < n; ++j) {\n            int ip = i * primes[j];\n            is_composite[ip]\
    \ = true;\n            if (i % primes[j] == 0) {\n                cnt[ip] = cnt[i]\
    \ + 1;\n                cnt_divisors[ip] = cnt_divisors[i] / (cnt[i] + 1) * (cnt[i]\
    \ + 2);\n            } else {\n                cnt[ip] = 1;\n                cnt_divisors[ip]\
    \ = 2 * cnt_divisors[i];\n            }\n        }\n    }\n}\n// }}}\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/multiplicative_functions_linear.h
  requiredBy: []
  timestamp: '2023-01-16 13:01:49+07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/euler_phi_stress.test.cpp
  - Math/tests/cnt_divisors_stress.test.cpp
  - Math/tests/smallest_prime_factor_stress.test.cpp
documentation_of: Math/multiplicative_functions_linear.h
layout: document
redirect_from:
- /library/Math/multiplicative_functions_linear.h
- /library/Math/multiplicative_functions_linear.h.html
title: Math/multiplicative_functions_linear.h
---
