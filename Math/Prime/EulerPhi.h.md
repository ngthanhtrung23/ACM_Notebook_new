---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_1_d_euler_phi.test.cpp
    title: Math/tests/aizu_ntl_1_d_euler_phi.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/euler_phi_stress.test.cpp
    title: Math/tests/euler_phi_stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.spoj.com/problems/ETFS/
  bundledCode: "#line 1 \"Math/Prime/EulerPhi.h\"\nlong long eulerPhi(long long n)\
    \ { // = n (1-1/p1) ... (1-1/pn)\n    if (n == 0) return 0;\n    long long ans\
    \ = n;\n    for (int x = 2; x*x <= n; ++x) {\n        if (n % x == 0) {\n    \
    \        ans -= ans / x;\n            while (n % x == 0) n /= x;\n        }\n\
    \    }\n    if (n > 1) ans -= ans / n;\n    return ans;\n}\n// LookUp Version\n\
    const int N = 1000000;\nint eulerPhi_lookup(int n) {\n    static int lookup =\
    \ 0, p[N], f[N];\n    if (!lookup) {\n        REP(i,N) p[i] = 1, f[i] = i;\n \
    \       for (int i = 2; i < N; ++i) {\n            if (p[i]) {\n            f[i]\
    \ -= f[i] / i;\n                for (int j = i+i; j < N; j+=i)\n             \
    \       p[j] = 0, f[j] -= f[j] / i;\n            }\n        }\n        lookup\
    \ = 1;\n    }\n    return f[n];\n}\n\n// Segmented sieve version, compute phi(i)\
    \ for i in [l, r]\n// Tested: https://www.spoj.com/problems/ETFS/\nnamespace EulerPhiSegmented\
    \ {\nvector<int> primes;    // NOTE: must initialize this\nconst int N = 100111;\
    \  // >= r - l + 1\n\nlong long phi[N], val[N];  // phi[i-l] = euler_phi(i)\n\
    void eulerPhi_segmentedSieve(long long l, long long r) {\n    assert(!primes.empty());\
    \  // must precompute primes upto sqrt(r)\n\n    for (auto i = l; i <= r; ++i)\
    \ {\n        phi[i-l] = i;\n        val[i-l] = i;\n    }\n    \n    for (auto\
    \ p : primes) {\n        if (p > r) break;\n        long long first = (l / p)\
    \ * p;\n        if (first < l) first += p;\n\n        while (first <= r) {\n \
    \           phi[first - l] -= phi[first - l] / p;\n            while (val[first\
    \ - l] % p == 0) val[first - l] /= p;\n            first += p;\n        }\n  \
    \  }\n\n    for (auto i = l; i <= r; ++i) {\n        if (val[i-l] > 1) {\n   \
    \         phi[i-l] -= phi[i-l] / val[i-l];\n        }\n    }\n}\n}\n"
  code: "long long eulerPhi(long long n) { // = n (1-1/p1) ... (1-1/pn)\n    if (n\
    \ == 0) return 0;\n    long long ans = n;\n    for (int x = 2; x*x <= n; ++x)\
    \ {\n        if (n % x == 0) {\n            ans -= ans / x;\n            while\
    \ (n % x == 0) n /= x;\n        }\n    }\n    if (n > 1) ans -= ans / n;\n   \
    \ return ans;\n}\n// LookUp Version\nconst int N = 1000000;\nint eulerPhi_lookup(int\
    \ n) {\n    static int lookup = 0, p[N], f[N];\n    if (!lookup) {\n        REP(i,N)\
    \ p[i] = 1, f[i] = i;\n        for (int i = 2; i < N; ++i) {\n            if (p[i])\
    \ {\n            f[i] -= f[i] / i;\n                for (int j = i+i; j < N; j+=i)\n\
    \                    p[j] = 0, f[j] -= f[j] / i;\n            }\n        }\n \
    \       lookup = 1;\n    }\n    return f[n];\n}\n\n// Segmented sieve version,\
    \ compute phi(i) for i in [l, r]\n// Tested: https://www.spoj.com/problems/ETFS/\n\
    namespace EulerPhiSegmented {\nvector<int> primes;    // NOTE: must initialize\
    \ this\nconst int N = 100111;  // >= r - l + 1\n\nlong long phi[N], val[N];  //\
    \ phi[i-l] = euler_phi(i)\nvoid eulerPhi_segmentedSieve(long long l, long long\
    \ r) {\n    assert(!primes.empty());  // must precompute primes upto sqrt(r)\n\
    \n    for (auto i = l; i <= r; ++i) {\n        phi[i-l] = i;\n        val[i-l]\
    \ = i;\n    }\n    \n    for (auto p : primes) {\n        if (p > r) break;\n\
    \        long long first = (l / p) * p;\n        if (first < l) first += p;\n\n\
    \        while (first <= r) {\n            phi[first - l] -= phi[first - l] /\
    \ p;\n            while (val[first - l] % p == 0) val[first - l] /= p;\n     \
    \       first += p;\n        }\n    }\n\n    for (auto i = l; i <= r; ++i) {\n\
    \        if (val[i-l] > 1) {\n            phi[i-l] -= phi[i-l] / val[i-l];\n \
    \       }\n    }\n}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Prime/EulerPhi.h
  requiredBy: []
  timestamp: '2022-12-19 21:18:52+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/aizu_ntl_1_d_euler_phi.test.cpp
  - Math/tests/euler_phi_stress.test.cpp
documentation_of: Math/Prime/EulerPhi.h
layout: document
redirect_from:
- /library/Math/Prime/EulerPhi.h
- /library/Math/Prime/EulerPhi.h.html
title: Math/Prime/EulerPhi.h
---
