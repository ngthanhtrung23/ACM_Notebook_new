---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_1_d_euler_phi.test.cpp
    title: Math/tests/aizu_ntl_1_d_euler_phi.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ = 1;\n    }\n    return f[n];\n}\n"
  code: "long long eulerPhi(long long n) { // = n (1-1/p1) ... (1-1/pn)\n    if (n\
    \ == 0) return 0;\n    long long ans = n;\n    for (int x = 2; x*x <= n; ++x)\
    \ {\n        if (n % x == 0) {\n            ans -= ans / x;\n            while\
    \ (n % x == 0) n /= x;\n        }\n    }\n    if (n > 1) ans -= ans / n;\n   \
    \ return ans;\n}\n// LookUp Version\nconst int N = 1000000;\nint eulerPhi_lookup(int\
    \ n) {\n    static int lookup = 0, p[N], f[N];\n    if (!lookup) {\n        REP(i,N)\
    \ p[i] = 1, f[i] = i;\n        for (int i = 2; i < N; ++i) {\n            if (p[i])\
    \ {\n            f[i] -= f[i] / i;\n                for (int j = i+i; j < N; j+=i)\n\
    \                    p[j] = 0, f[j] -= f[j] / i;\n            }\n        }\n \
    \       lookup = 1;\n    }\n    return f[n];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Prime/EulerPhi.h
  requiredBy: []
  timestamp: '2022-01-11 20:18:36+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/aizu_ntl_1_d_euler_phi.test.cpp
documentation_of: Math/Prime/EulerPhi.h
layout: document
redirect_from:
- /library/Math/Prime/EulerPhi.h
- /library/Math/Prime/EulerPhi.h.html
title: Math/Prime/EulerPhi.h
---
