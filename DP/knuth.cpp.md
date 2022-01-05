---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/blog/entry/8219
  bundledCode: "#line 1 \"DP/knuth.cpp\"\n// http://codeforces.com/blog/entry/8219\n\
    // Original Recurrence:\n//   dp[i][j] = min(dp[i][k] + dp[k][j]) + C[i][j]  \
    \ for k = i+1..j-1\n// Necessary & Sufficient Conditions:\n//   A[i][j-1] <= A[i][j]\
    \ <= A[i+1][j]\n//   with A[i][j] = smallest k that gives optimal answer\n// Also\
    \ applicable if the following conditions are met:\n//   1. C[a][c] + C[b][d] <=\
    \ C[a][d] + C[b][c] (quadrangle inequality)\n//   2. C[b][c] <= C[a][d]      \
    \               (monotonicity)\n//   for all a <= b <= c <= d\n// To use:\n//\
    \   Calculate dp[i][i] and A[i][i]\n//\n//   FOR(len = 1..n-1)\n//     FOR(i =\
    \ 1..n-len) {\n//       j = i + len\n//       FOR(k = A[i][j-1]..A[i+1][j])\n\
    //         update(dp[i][j])\n//     }\n\n// OPTCUT\n#line 1 \"template.h\"\n#include\
    \ <bits/stdc++.h>\n\n#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define\
    \ FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a);\
    \ i<_a; i++)\n#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it !=\
    \ a.end(); ++it)\n\n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl;\
    \ }\n#define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' ';\
    \ cout << endl; }\n#define PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout <<\
    \ a[_] << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\nusing namespace\
    \ std;\n\nint main() {\n    return 0;\n}\n\n#line 23 \"DP/knuth.cpp\"\n\nconst\
    \ int MN = 2011;\nint a[MN], dp[MN][MN], C[MN][MN], A[MN][MN];\nint n;\n\nvoid\
    \ solve() {\n    cin >> n; FOR(i,1,n) { cin >> a[i]; a[i] += a[i-1]; }\n    FOR(i,1,n)\
    \ FOR(j,i,n) C[i][j] = a[j] - a[i-1];\n\n    FOR(i,1,n) dp[i][i] = 0, A[i][i]\
    \ = i;\n\n    FOR(len,1,n-1)\n        FOR(i,1,n-len) {\n            int j = i\
    \ + len;\n            dp[i][j] = 2000111000;\n            FOR(k,A[i][j-1],A[i+1][j])\
    \ {\n                int cur = dp[i][k-1] + dp[k][j] + C[i][j];\n            \
    \    if (cur < dp[i][j]) {\n                    dp[i][j] = cur;\n            \
    \        A[i][j] = k;\n                }\n            }\n        }\n    cout <<\
    \ dp[1][n] << endl;\n}\n"
  code: "// http://codeforces.com/blog/entry/8219\n// Original Recurrence:\n//   dp[i][j]\
    \ = min(dp[i][k] + dp[k][j]) + C[i][j]   for k = i+1..j-1\n// Necessary & Sufficient\
    \ Conditions:\n//   A[i][j-1] <= A[i][j] <= A[i+1][j]\n//   with A[i][j] = smallest\
    \ k that gives optimal answer\n// Also applicable if the following conditions\
    \ are met:\n//   1. C[a][c] + C[b][d] <= C[a][d] + C[b][c] (quadrangle inequality)\n\
    //   2. C[b][c] <= C[a][d]                     (monotonicity)\n//   for all a\
    \ <= b <= c <= d\n// To use:\n//   Calculate dp[i][i] and A[i][i]\n//\n//   FOR(len\
    \ = 1..n-1)\n//     FOR(i = 1..n-len) {\n//       j = i + len\n//       FOR(k\
    \ = A[i][j-1]..A[i+1][j])\n//         update(dp[i][j])\n//     }\n\n// OPTCUT\n\
    #include \"../template.h\"\n\nconst int MN = 2011;\nint a[MN], dp[MN][MN], C[MN][MN],\
    \ A[MN][MN];\nint n;\n\nvoid solve() {\n    cin >> n; FOR(i,1,n) { cin >> a[i];\
    \ a[i] += a[i-1]; }\n    FOR(i,1,n) FOR(j,i,n) C[i][j] = a[j] - a[i-1];\n\n  \
    \  FOR(i,1,n) dp[i][i] = 0, A[i][i] = i;\n\n    FOR(len,1,n-1)\n        FOR(i,1,n-len)\
    \ {\n            int j = i + len;\n            dp[i][j] = 2000111000;\n      \
    \      FOR(k,A[i][j-1],A[i+1][j]) {\n                int cur = dp[i][k-1] + dp[k][j]\
    \ + C[i][j];\n                if (cur < dp[i][j]) {\n                    dp[i][j]\
    \ = cur;\n                    A[i][j] = k;\n                }\n            }\n\
    \        }\n    cout << dp[1][n] << endl;\n}\n"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DP/knuth.cpp
  requiredBy: []
  timestamp: '2015-10-24 16:54:51+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/knuth.cpp
layout: document
redirect_from:
- /library/DP/knuth.cpp
- /library/DP/knuth.cpp.html
title: DP/knuth.cpp
---
