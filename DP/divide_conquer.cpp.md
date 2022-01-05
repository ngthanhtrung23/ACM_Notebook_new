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
    - http://codeforces.com/contest/321/problem/E
  bundledCode: "#line 1 \"DP/divide_conquer.cpp\"\n// http://codeforces.com/blog/entry/8219\n\
    // Divide and conquer optimization:\n// Original Recurrence\n//   dp[i][j] = min(dp[i-1][k]\
    \ + C[k][j]) for k < j\n// Sufficient condition:\n//   A[i][j] <= A[i][j+1]\n\
    //   where A[i][j] = smallest k that gives optimal answer\n// How to use:\n//\
    \   // compute i-th row of dp from L to R. optL <= A[i][L] <= A[i][R] <= optR\n\
    //   compute(i, L, R, optL, optR)\n//       1. special case L == R\n//       2.\
    \ let M = (L + R) / 2. Calculate dp[i][M] and opt[i][M] using O(optR - optL +\
    \ 1)\n//       3. compute(i, L, M-1, optL, opt[i][M])\n//       4. compute(i,\
    \ M+1, R, opt[i][M], optR)\n\n// Example: http://codeforces.com/contest/321/problem/E\n\
    #line 1 \"template.h\"\n#include <bits/stdc++.h>\n\n#define FOR(i,a,b) for(int\
    \ i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b;\
    \ i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a) for(__typeof(a.begin())\
    \ it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x) { cout << #x << \"\
    \ = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n)\
    \ cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n) { cout << #a << \" =\
    \ \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\n\
    using namespace std;\n\nint main() {\n    return 0;\n}\n\n#line 18 \"DP/divide_conquer.cpp\"\
    \n\nconst int MN = 4011;\nconst int inf = 1000111000;\nint n, k, cost[MN][MN],\
    \ dp[811][MN];\n\ninline int getCost(int i, int j) {\n    return cost[j][j] -\
    \ cost[j][i-1] - cost[i-1][j] + cost[i-1][i-1];\n}\n\nvoid compute(int i, int\
    \ L, int R, int optL, int optR) {\n    if (L > R) return ;\n\n    int mid = (L\
    \ + R) >> 1, savek = optL;\n    dp[i][mid] = inf;\n    FOR(k,optL,min(mid-1, optR))\
    \ {\n        int cur = dp[i-1][k] + getCost(k+1, mid);\n        if (cur < dp[i][mid])\
    \ {\n            dp[i][mid] = cur;\n            savek = k;\n        }\n    }\n\
    \    compute(i, L, mid-1, optL, savek);\n    compute(i, mid+1, R, savek, optR);\n\
    }\n\nvoid solve() {\n    cin >> n >> k;\n    FOR(i,1,n) FOR(j,1,n) {\n       \
    \ cin >> cost[i][j];\n        cost[i][j] = cost[i-1][j] + cost[i][j-1] - cost[i-1][j-1]\
    \ + cost[i][j];\n    }\n    dp[0][0] = 0;\n    FOR(i,1,n) dp[0][i] = inf;\n\n\
    \    FOR(i,1,k) {\n        compute(i, 1, n, 0, n);\n    }\n    cout << dp[k][n]\
    \ / 2 << endl;\n}\n"
  code: "// http://codeforces.com/blog/entry/8219\n// Divide and conquer optimization:\n\
    // Original Recurrence\n//   dp[i][j] = min(dp[i-1][k] + C[k][j]) for k < j\n\
    // Sufficient condition:\n//   A[i][j] <= A[i][j+1]\n//   where A[i][j] = smallest\
    \ k that gives optimal answer\n// How to use:\n//   // compute i-th row of dp\
    \ from L to R. optL <= A[i][L] <= A[i][R] <= optR\n//   compute(i, L, R, optL,\
    \ optR)\n//       1. special case L == R\n//       2. let M = (L + R) / 2. Calculate\
    \ dp[i][M] and opt[i][M] using O(optR - optL + 1)\n//       3. compute(i, L, M-1,\
    \ optL, opt[i][M])\n//       4. compute(i, M+1, R, opt[i][M], optR)\n\n// Example:\
    \ http://codeforces.com/contest/321/problem/E\n#include \"../template.h\"\n\n\
    const int MN = 4011;\nconst int inf = 1000111000;\nint n, k, cost[MN][MN], dp[811][MN];\n\
    \ninline int getCost(int i, int j) {\n    return cost[j][j] - cost[j][i-1] - cost[i-1][j]\
    \ + cost[i-1][i-1];\n}\n\nvoid compute(int i, int L, int R, int optL, int optR)\
    \ {\n    if (L > R) return ;\n\n    int mid = (L + R) >> 1, savek = optL;\n  \
    \  dp[i][mid] = inf;\n    FOR(k,optL,min(mid-1, optR)) {\n        int cur = dp[i-1][k]\
    \ + getCost(k+1, mid);\n        if (cur < dp[i][mid]) {\n            dp[i][mid]\
    \ = cur;\n            savek = k;\n        }\n    }\n    compute(i, L, mid-1, optL,\
    \ savek);\n    compute(i, mid+1, R, savek, optR);\n}\n\nvoid solve() {\n    cin\
    \ >> n >> k;\n    FOR(i,1,n) FOR(j,1,n) {\n        cin >> cost[i][j];\n      \
    \  cost[i][j] = cost[i-1][j] + cost[i][j-1] - cost[i-1][j-1] + cost[i][j];\n \
    \   }\n    dp[0][0] = 0;\n    FOR(i,1,n) dp[0][i] = inf;\n\n    FOR(i,1,k) {\n\
    \        compute(i, 1, n, 0, n);\n    }\n    cout << dp[k][n] / 2 << endl;\n}\n"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DP/divide_conquer.cpp
  requiredBy: []
  timestamp: '2017-03-17 13:20:39+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/divide_conquer.cpp
layout: document
redirect_from:
- /library/DP/divide_conquer.cpp
- /library/DP/divide_conquer.cpp.html
title: DP/divide_conquer.cpp
---
