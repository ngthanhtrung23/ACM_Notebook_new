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
    - https://oj.vnoi.info/problem/icpc22_mn_c
  bundledCode: "#line 1 \"DP/optimizations/knuth.cpp\"\n// http://codeforces.com/blog/entry/8219\n\
    // Original Recurrence:\n//   dp[i][j] = min(dp[i][k] + dp[k][j]) + C[i][j]  \
    \ for k = i+1..j-1\n// Necessary & Sufficient Conditions:\n//   A[i][j-1] <= A[i][j]\
    \ <= A[i+1][j]\n//   with A[i][j] = smallest k that gives optimal answer\n// Also\
    \ applicable if the following conditions are met:\n//   1. C[a][c] + C[b][d] <=\
    \ C[a][d] + C[b][c] (quadrangle inequality)\n//   2. C[b][c] <= C[a][d]      \
    \               (monotonicity)\n//   for all a <= b <= c <= d\n// To use:\n//\
    \   Calculate dp[i][i] and A[i][i]\n//\n//   FOR(len = 1..n-1)\n//     FOR(i =\
    \ 1..n-len) {\n//       j = i + len\n//       FOR(k = A[i][j-1]..A[i+1][j])\n\
    //         update(dp[i][j])\n//     }\n// \n// There is another type of Knuth\
    \ in https://oj.vnoi.info/problem/icpc22_mn_c\n// - f[i][j] = min(f[i-1][last]\
    \ + cost[last+1][j])\n// - cost satisfies quandrangle inequality\n//   FOR(i,\
    \ 1, k)\n//     FORD(j, n, 1)\n//       FOR(last, opt[i-1][j], opt[i][j+1])\n\
    //         update f[i][j] and A[i][j] using f[i-1][last] + cost[last+1][j]\n\n\
    // OPTCUT\n#line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int\
    \ i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n\
    #define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\
    \n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n)\
    \ { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define\
    \ PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl;\
    \ }\n\n#define sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n//\
    \ Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
    template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>&\
    \ p) {\n    return out << '(' << p.first << \", \" << p.second << ')';\n}\n\n\
    template<class Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
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
    \ (0, r-1)(rng);\n}\n\ntemplate<typename T>\nvector<T> read_vector(int n) {\n\
    \    vector<T> res(n);\n    for (int& x : res) cin >> x;\n    return res;\n}\n\
    \nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n  \
    \  solve();\n    return 0;\n}\n#line 31 \"DP/optimizations/knuth.cpp\"\n\nconst\
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
    \ = A[i][j-1]..A[i+1][j])\n//         update(dp[i][j])\n//     }\n// \n// There\
    \ is another type of Knuth in https://oj.vnoi.info/problem/icpc22_mn_c\n// - f[i][j]\
    \ = min(f[i-1][last] + cost[last+1][j])\n// - cost satisfies quandrangle inequality\n\
    //   FOR(i, 1, k)\n//     FORD(j, n, 1)\n//       FOR(last, opt[i-1][j], opt[i][j+1])\n\
    //         update f[i][j] and A[i][j] using f[i-1][last] + cost[last+1][j]\n\n\
    // OPTCUT\n#include \"../../template.h\"\n\nconst int MN = 2011;\nint a[MN], dp[MN][MN],\
    \ C[MN][MN], A[MN][MN];\nint n;\n\nvoid solve() {\n    cin >> n; FOR(i,1,n) {\
    \ cin >> a[i]; a[i] += a[i-1]; }\n    FOR(i,1,n) FOR(j,i,n) C[i][j] = a[j] - a[i-1];\n\
    \n    FOR(i,1,n) dp[i][i] = 0, A[i][i] = i;\n\n    FOR(len,1,n-1)\n        FOR(i,1,n-len)\
    \ {\n            int j = i + len;\n            dp[i][j] = 2000111000;\n      \
    \      FOR(k,A[i][j-1],A[i+1][j]) {\n                int cur = dp[i][k-1] + dp[k][j]\
    \ + C[i][j];\n                if (cur < dp[i][j]) {\n                    dp[i][j]\
    \ = cur;\n                    A[i][j] = k;\n                }\n            }\n\
    \        }\n    cout << dp[1][n] << endl;\n}\n"
  dependsOn:
  - template.h
  isVerificationFile: false
  path: DP/optimizations/knuth.cpp
  requiredBy: []
  timestamp: '2022-12-26 18:28:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/optimizations/knuth.cpp
layout: document
redirect_from:
- /library/DP/optimizations/knuth.cpp
- /library/DP/optimizations/knuth.cpp.html
title: DP/optimizations/knuth.cpp
---
