---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    #line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b);\
    \ i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a)\
    \ for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x)\
    \ { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a\
    \ << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n)\
    \ { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define\
    \ sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n// Copied from\
    \ https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\ntemplate<class\
    \ U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {\n   \
    \ return out << '(' << p.first << \", \" << p.second << ')';\n}\n\ntemplate<class\
    \ Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
    \ string>::value, ostream&>::type\noperator << (ostream& out, const Con& con)\
    \ {\n    out << '{';\n    for (auto beg = con.begin(), it = beg; it != con.end();\
    \ it++) {\n        out << (it == beg ? \"\" : \", \") << *it;\n    }\n    return\
    \ out << '}';\n}\ntemplate<size_t i, class T> ostream& print_tuple_utils(ostream&\
    \ out, const T& tup) {\n    if constexpr(i == tuple_size<T>::value) return out\
    \ << \")\"; \n    else return print_tuple_utils<i + 1, T>(out << (i ? \", \" :\
    \ \"(\") << get<i>(tup), tup); \n}\ntemplate<class ...U> ostream& operator <<\
    \ (ostream& out, const tuple<U...>& t) {\n    return print_tuple_utils<0, tuple<U...>>(out,\
    \ t);\n}\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r) {\n    return uniform_int_distribution<long long>\
    \ (0, r-1)(rng);\n}\n\nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    solve();\n    return 0;\n}\n#line 18 \"DP/divide_conquer.cpp\"\
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
  timestamp: '2022-01-10 03:15:26+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/divide_conquer.cpp
layout: document
redirect_from:
- /library/DP/divide_conquer.cpp
- /library/DP/divide_conquer.cpp.html
title: DP/divide_conquer.cpp
---
