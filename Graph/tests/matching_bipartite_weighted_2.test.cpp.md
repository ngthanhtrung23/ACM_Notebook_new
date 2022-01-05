---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Matching/Hungarian_short.h
    title: Graph/Matching/Hungarian_short.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"Graph/tests/matching_bipartite_weighted_2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"Graph/Matching/Hungarian_short.h\"\n// Copied\
    \ from https://judge.yosupo.jp/submission/16114\n//\n// Min-cost matching\n//\n\
    // Tested:\n// - https://oj.vnoi.info/problem/match2\n// - https://judge.yosupo.jp/problem/assignment\n\
    // - https://hochiminh17.kattis.com/problems/engaging\n// \n// Returns {total\
    \ weight, matches (from left)}\nconst int N = 1011;\ntemplate<typename T>\npair<T,\
    \ vector<int>> Hungarian (int n, int m, T c[][N]) {\n    vector<T> v(m), dist(m);\n\
    \    vector<int> L(n, -1), R(m, -1);\n    vector<int> index(m), prev(m);\n   \
    \ auto getc = [&] (int i, int j) {return c[i][j] - v[j];};\n\n    iota(index.begin(),\
    \ index.end(), 0);\n    for (int f = 0; f < n; ++f) {\n        for (int j = 0;\
    \ j < m; ++j) {\n            dist[j] = getc(f, j), prev[j] = f;\n        }\n \
    \       T w = 0; int j, l = 0, s = 0, t = 0;\n        while (true) {\n       \
    \     if (s == t) {\n                l = s, w = dist[index[t++]];\n          \
    \      for (int k = t; k < m; ++k) {\n                    j = index[k]; T h =\
    \ dist[j];\n                    if (h <= w) {\n                        if (h <\
    \ w) t = s, w = h;\n                        index[k] = index[t], index[t++] =\
    \ j;\n                    }\n                }\n                for (int k = s;\
    \ k < t; ++k) {\n                    j = index[k];\n                    if (R[j]\
    \ < 0) goto augment;\n                }\n            }\n            int q = index[s++],\
    \ i = R[q];\n            for (int k = t; k < m; ++k) {\n                j = index[k];\n\
    \                T h = getc(i, j) - getc(i, q) + w;\n                if (h < dist[j])\
    \ {\n                    dist[j] = h, prev[j] = i;\n                    if (h\
    \ == w) {\n                        if (R[j] < 0) goto augment;\n             \
    \           index[k] = index[t], index[t++] = j;\n                    }\n    \
    \            }\n            }\n        }\n    augment:\n        for (int k = 0;\
    \ k < l; ++k) v[index[k]] += dist[index[k]] - w;\n        int i;\n        do {\n\
    \            i = R[j] = prev[j];\n            swap(j, L[i]);\n        } while\
    \ (i != f);\n    }\n    T ret = 0;\n    for (int i = 0; i < n; ++i) ret += c[i][L[i]];\n\
    \    return {ret, L};\n}\n#line 7 \"Graph/tests/matching_bipartite_weighted_2.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\nlong long c[N][N];\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n; cin >>\
    \ n;\n    REP(i,n) REP(j,n) cin >> c[i][j];\n\n    auto [cost, matchL] = Hungarian<long\
    \ long>(n, n, c);\n    cout << cost << endl;\n    for (int m : matchL) cout <<\
    \ m << ' ';\n    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Matching/Hungarian_short.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\nlong long c[N][N];\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n; cin >>\
    \ n;\n    REP(i,n) REP(j,n) cin >> c[i][j];\n\n    auto [cost, matchL] = Hungarian<long\
    \ long>(n, n, c);\n    cout << cost << endl;\n    for (int m : matchL) cout <<\
    \ m << ' ';\n    cout << endl;\n    return 0;\n}\n"
  dependsOn:
  - Graph/Matching/Hungarian_short.h
  isVerificationFile: true
  path: Graph/tests/matching_bipartite_weighted_2.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 04:03:40+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/matching_bipartite_weighted_2.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/matching_bipartite_weighted_2.test.cpp
- /verify/Graph/tests/matching_bipartite_weighted_2.test.cpp.html
title: Graph/tests/matching_bipartite_weighted_2.test.cpp
---
