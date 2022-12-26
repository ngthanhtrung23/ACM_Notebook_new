---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/blog/entry/8219
    - https://oj.vnoi.info/problem/icpc22_mn_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template.h:\
    \ line -1: no such header\n"
  code: "// http://codeforces.com/blog/entry/8219\n// Original Recurrence:\n//   dp[i][j]\
    \ = min(dp[i][k] + dp[k][j]) + C[i][j]   for k = i+1..j-1\n// Necessary & Sufficient\
    \ Conditions:\n//   A[i][j-1] <= A[i][j] <= A[i+1][j]\n//   with A[i][j] = smallest\
    \ k that gives optimal answer\n// Also applicable if the following conditions\
    \ are met:\n//   1. C[a][c] + C[b][d] <= C[a][d] + C[b][c] (quadrangle inequality)\n\
    //   2. C[b][c] <= C[a][d]                     (monotonicity)\n//   for all a\
    \ <= b <= c <= d\n// To use:\n//   Calculate dp[i][i] and A[i][i]\n//\n//   FOR(len\
    \ = 1..n-1)\n//     FOR(i = 1..n-len) {\n//       j = i + len\n//       FOR(k\
    \ = A[i][j-1]..A[i+1][j])\n//         update(dp[i][j])\n//     }\n// \n// There\
    \ is another type of Knuth in https://oj.vnoi.info/problem/icpc22_mn_c\n// - f[i][j]\
    \ = min(f[i-1][last] + cost[last+1][j])\n// - cost satisfies quandrangle inequality\n\
    //   FOR(i, 1, k)\n//     FORD(j, n, 1)\n//       FOR(last, opt[i-1][j], opt[i][j+1])\n\
    //         update f[i][j] and A[i][j] using f[i-1][last] + cost[last+1][j]\n\n\
    // OPTCUT\n#include \"../template.h\"\n\nconst int MN = 2011;\nint a[MN], dp[MN][MN],\
    \ C[MN][MN], A[MN][MN];\nint n;\n\nvoid solve() {\n    cin >> n; FOR(i,1,n) {\
    \ cin >> a[i]; a[i] += a[i-1]; }\n    FOR(i,1,n) FOR(j,i,n) C[i][j] = a[j] - a[i-1];\n\
    \n    FOR(i,1,n) dp[i][i] = 0, A[i][i] = i;\n\n    FOR(len,1,n-1)\n        FOR(i,1,n-len)\
    \ {\n            int j = i + len;\n            dp[i][j] = 2000111000;\n      \
    \      FOR(k,A[i][j-1],A[i+1][j]) {\n                int cur = dp[i][k-1] + dp[k][j]\
    \ + C[i][j];\n                if (cur < dp[i][j]) {\n                    dp[i][j]\
    \ = cur;\n                    A[i][j] = k;\n                }\n            }\n\
    \        }\n    cout << dp[1][n] << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/optimizations/knuth.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/optimizations/knuth.cpp
layout: document
redirect_from:
- /library/DP/optimizations/knuth.cpp
- /library/DP/optimizations/knuth.cpp.html
title: DP/optimizations/knuth.cpp
---
