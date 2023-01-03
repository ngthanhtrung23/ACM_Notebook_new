---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/matching_bipartite_weighted_2.test.cpp
    title: Graph/tests/matching_bipartite_weighted_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://hochiminh17.kattis.com/problems/engaging
    - https://judge.yosupo.jp/problem/assignment
    - https://judge.yosupo.jp/submission/16114
    - https://oj.vnoi.info/problem/match2
  bundledCode: "#line 1 \"Graph/Matching/Hungarian_short.h\"\n// Copied from https://judge.yosupo.jp/submission/16114\n\
    //\n// NOTE:\n// - Min-cost matching\n// - Index from 0\n//\n// Tested:\n// -\
    \ https://oj.vnoi.info/problem/match2\n// - https://judge.yosupo.jp/problem/assignment\n\
    // - https://hochiminh17.kattis.com/problems/engaging\n// \n// n = |left side|,\
    \ m = |right side|\n// Returns {total weight, matches (from left)}\nconst int\
    \ N = 1011;\ntemplate<typename T>\npair<T, vector<int>> Hungarian (int n, int\
    \ m, T c[][N]) {\n    vector<T> v(m), dist(m);\n    vector<int> L(n, -1), R(m,\
    \ -1);\n    vector<int> index(m), prev(m);\n    auto getc = [&] (int i, int j)\
    \ {return c[i][j] - v[j];};\n\n    iota(index.begin(), index.end(), 0);\n    for\
    \ (int f = 0; f < n; ++f) {\n        for (int j = 0; j < m; ++j) {\n         \
    \   dist[j] = getc(f, j), prev[j] = f;\n        }\n        T w = 0; int j, l =\
    \ 0, s = 0, t = 0;\n        while (true) {\n            if (s == t) {\n      \
    \          l = s, w = dist[index[t++]];\n                for (int k = t; k < m;\
    \ ++k) {\n                    j = index[k]; T h = dist[j];\n                 \
    \   if (h <= w) {\n                        if (h < w) t = s, w = h;\n        \
    \                index[k] = index[t], index[t++] = j;\n                    }\n\
    \                }\n                for (int k = s; k < t; ++k) {\n          \
    \          j = index[k];\n                    if (R[j] < 0) goto augment;\n  \
    \              }\n            }\n            int q = index[s++], i = R[q];\n \
    \           for (int k = t; k < m; ++k) {\n                j = index[k];\n   \
    \             T h = getc(i, j) - getc(i, q) + w;\n                if (h < dist[j])\
    \ {\n                    dist[j] = h, prev[j] = i;\n                    if (h\
    \ == w) {\n                        if (R[j] < 0) goto augment;\n             \
    \           index[k] = index[t], index[t++] = j;\n                    }\n    \
    \            }\n            }\n        }\n    augment:\n        for (int k = 0;\
    \ k < l; ++k) v[index[k]] += dist[index[k]] - w;\n        int i;\n        do {\n\
    \            i = R[j] = prev[j];\n            swap(j, L[i]);\n        } while\
    \ (i != f);\n    }\n    T ret = 0;\n    for (int i = 0; i < n; ++i) ret += c[i][L[i]];\n\
    \    return {ret, L};\n}\n"
  code: "// Copied from https://judge.yosupo.jp/submission/16114\n//\n// NOTE:\n//\
    \ - Min-cost matching\n// - Index from 0\n//\n// Tested:\n// - https://oj.vnoi.info/problem/match2\n\
    // - https://judge.yosupo.jp/problem/assignment\n// - https://hochiminh17.kattis.com/problems/engaging\n\
    // \n// n = |left side|, m = |right side|\n// Returns {total weight, matches (from\
    \ left)}\nconst int N = 1011;\ntemplate<typename T>\npair<T, vector<int>> Hungarian\
    \ (int n, int m, T c[][N]) {\n    vector<T> v(m), dist(m);\n    vector<int> L(n,\
    \ -1), R(m, -1);\n    vector<int> index(m), prev(m);\n    auto getc = [&] (int\
    \ i, int j) {return c[i][j] - v[j];};\n\n    iota(index.begin(), index.end(),\
    \ 0);\n    for (int f = 0; f < n; ++f) {\n        for (int j = 0; j < m; ++j)\
    \ {\n            dist[j] = getc(f, j), prev[j] = f;\n        }\n        T w =\
    \ 0; int j, l = 0, s = 0, t = 0;\n        while (true) {\n            if (s ==\
    \ t) {\n                l = s, w = dist[index[t++]];\n                for (int\
    \ k = t; k < m; ++k) {\n                    j = index[k]; T h = dist[j];\n   \
    \                 if (h <= w) {\n                        if (h < w) t = s, w =\
    \ h;\n                        index[k] = index[t], index[t++] = j;\n         \
    \           }\n                }\n                for (int k = s; k < t; ++k)\
    \ {\n                    j = index[k];\n                    if (R[j] < 0) goto\
    \ augment;\n                }\n            }\n            int q = index[s++],\
    \ i = R[q];\n            for (int k = t; k < m; ++k) {\n                j = index[k];\n\
    \                T h = getc(i, j) - getc(i, q) + w;\n                if (h < dist[j])\
    \ {\n                    dist[j] = h, prev[j] = i;\n                    if (h\
    \ == w) {\n                        if (R[j] < 0) goto augment;\n             \
    \           index[k] = index[t], index[t++] = j;\n                    }\n    \
    \            }\n            }\n        }\n    augment:\n        for (int k = 0;\
    \ k < l; ++k) v[index[k]] += dist[index[k]] - w;\n        int i;\n        do {\n\
    \            i = R[j] = prev[j];\n            swap(j, L[i]);\n        } while\
    \ (i != f);\n    }\n    T ret = 0;\n    for (int i = 0; i < n; ++i) ret += c[i][L[i]];\n\
    \    return {ret, L};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Matching/Hungarian_short.h
  requiredBy: []
  timestamp: '2023-01-04 02:50:55+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/matching_bipartite_weighted_2.test.cpp
documentation_of: Graph/Matching/Hungarian_short.h
layout: document
redirect_from:
- /library/Graph/Matching/Hungarian_short.h
- /library/Graph/Matching/Hungarian_short.h.html
title: Graph/Matching/Hungarian_short.h
---
