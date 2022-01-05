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
    - http://codeforces.com/blog/entry/23442
  bundledCode: "#line 1 \"Math/Pure/lagrange.h\"\n// http://codeforces.com/blog/entry/23442\n\
    // Polynomial P of degree N --> need N+1 points. Let n = N+1\n// init y[i], i\
    \ = 1..n\n// init coefficient:\nFOR(i,1,n) f[i] = (x - i + MOD) % MOD;\nl[0] =\
    \ 1; FOR(i,1,n) l[i] = l[i-1] * f[i] % MOD;\nr[n+1] = 1; FORD(i,n,1) r[i] = r[i+1]\
    \ * f[i] % MOD;\n// P(x) = sum(y[i] * product((x - j) / (i - j), j=1..n, j !=\
    \ i), i=1..n)\nint res = 0;\nFOR(i,1,n) {\n\t// j < i\n\tint cur = l[i-1] * inv_gt[i\
    \ - 1] % MOD;\n\t// j > i\n\tcur = cur * r[i+1] % MOD * inv_gt[n - i] % MOD;\n\
    \tif ((n - i) % 2) cur = cur * (MOD - 1) % MOD;\n\t// add y[i] * product\n\tres\
    \ = (res + cur * y[i]) % MOD;\n}\n"
  code: "// http://codeforces.com/blog/entry/23442\n// Polynomial P of degree N -->\
    \ need N+1 points. Let n = N+1\n// init y[i], i = 1..n\n// init coefficient:\n\
    FOR(i,1,n) f[i] = (x - i + MOD) % MOD;\nl[0] = 1; FOR(i,1,n) l[i] = l[i-1] * f[i]\
    \ % MOD;\nr[n+1] = 1; FORD(i,n,1) r[i] = r[i+1] * f[i] % MOD;\n// P(x) = sum(y[i]\
    \ * product((x - j) / (i - j), j=1..n, j != i), i=1..n)\nint res = 0;\nFOR(i,1,n)\
    \ {\n\t// j < i\n\tint cur = l[i-1] * inv_gt[i - 1] % MOD;\n\t// j > i\n\tcur\
    \ = cur * r[i+1] % MOD * inv_gt[n - i] % MOD;\n\tif ((n - i) % 2) cur = cur *\
    \ (MOD - 1) % MOD;\n\t// add y[i] * product\n\tres = (res + cur * y[i]) % MOD;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Pure/lagrange.h
  requiredBy: []
  timestamp: '2016-02-13 05:15:01+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Pure/lagrange.h
layout: document
redirect_from:
- /library/Math/Pure/lagrange.h
- /library/Math/Pure/lagrange.h.html
title: Math/Pure/lagrange.h
---
