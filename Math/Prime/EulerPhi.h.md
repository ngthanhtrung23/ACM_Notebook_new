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
  bundledCode: "#line 1 \"Math/Prime/EulerPhi.h\"\nint eulerPhi(int n) { // = n (1-1/p1)\
    \ ... (1-1/pn)\n    if (n == 0) return 0;\n    int ans = n;\n    for (int x =\
    \ 2; x*x <= n; ++x) {\n        if (n % x == 0) {\n            ans -= ans / x;\n\
    \            while (n % x == 0) n /= x;\n        }\n    }\n    if (n > 1) ans\
    \ -= ans / n;\n    return ans;\n}\n// LookUp Version\nconst int N = 1000000;\n\
    int eulerPhi(int n) {\n    static int lookup = 0, p[N], f[N];\n    if (!lookup)\
    \ {\n        REP(i,N) p[i] = 1, f[i] = i;\n        for (int i = 2; i < N; ++i)\
    \ {\n            if (p[i]) {\n            f[i] -= f[i] / i;\n                for\
    \ (int j = i+i; j < N; j+=i)\n                    p[j] = 0, f[j] -= f[j] / i;\n\
    \            }\n        }\n        lookup = 1;\n    }\n    return f[n];\n}\n"
  code: "int eulerPhi(int n) { // = n (1-1/p1) ... (1-1/pn)\n    if (n == 0) return\
    \ 0;\n    int ans = n;\n    for (int x = 2; x*x <= n; ++x) {\n        if (n %\
    \ x == 0) {\n            ans -= ans / x;\n            while (n % x == 0) n /=\
    \ x;\n        }\n    }\n    if (n > 1) ans -= ans / n;\n    return ans;\n}\n//\
    \ LookUp Version\nconst int N = 1000000;\nint eulerPhi(int n) {\n    static int\
    \ lookup = 0, p[N], f[N];\n    if (!lookup) {\n        REP(i,N) p[i] = 1, f[i]\
    \ = i;\n        for (int i = 2; i < N; ++i) {\n            if (p[i]) {\n     \
    \       f[i] -= f[i] / i;\n                for (int j = i+i; j < N; j+=i)\n  \
    \                  p[j] = 0, f[j] -= f[j] / i;\n            }\n        }\n   \
    \     lookup = 1;\n    }\n    return f[n];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Prime/EulerPhi.h
  requiredBy: []
  timestamp: '2015-10-12 09:46:07+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Prime/EulerPhi.h
layout: document
redirect_from:
- /library/Math/Prime/EulerPhi.h
- /library/Math/Prime/EulerPhi.h.html
title: Math/Prime/EulerPhi.h
---
