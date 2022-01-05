---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/find_triangles.h
    title: Graph/find_triangles.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_triangles
    links:
    - https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "#line 1 \"Graph/tests/triangles.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/find_triangles.h\"\
    \n// Find all cycles of length 3 (a.k.a. triangles)\n// Complexity: O(N + M*sqrt(M))\n\
    //\n// Index from 0\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/enumerate_triangles\n\
    vector< tuple<int,int,int> > find_all_triangles(\n        int n,\n        vector<pair<int,int>>\
    \ edges) {\n    // Remove duplicated edges\n    sort(edges.begin(), edges.end());\n\
    \    edges.erase(unique(edges.begin(), edges.end()), edges.end());\n\n    // Compute\
    \ degs\n    vector<int> deg(n, 0);\n    for (const auto& [u, v] : edges) {\n \
    \       if (u == v) continue;\n        ++deg[u], ++deg[v];\n    }\n\n    // Add\
    \ edge (u, v) where u is 'lower' than v\n    vector<vector<int>> adj(n);\n   \
    \ for (auto [u, v] : edges) {\n        if (u == v) continue;\n        if (deg[u]\
    \ > deg[v] || (deg[u] == deg[v] && u > v)) swap(u, v);\n        adj[u].push_back(v);\n\
    \    }\n\n    // Find all triplets.\n    // If it's too slow, remove vector res\
    \ and compute answer directly\n    vector<tuple<int,int,int>> res;\n    vector<bool>\
    \ good(n, false);\n    for (int i = 0; i < n; i++) {\n        for (auto j : adj[i])\
    \ good[j] = true;\n        for (auto j : adj[i]) {\n            for (auto k :\
    \ adj[j]) {\n                if (good[k]) {\n                    res.emplace_back(i,\
    \ j, k);\n                }\n            }\n        }\n        for (auto j : adj[i])\
    \ good[j] = false;\n    }\n    return res;\n}\n#line 7 \"Graph/tests/triangles.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin >> n >> m;\n\
    \    vector<int> xs(n);\n    REP(i,n) cin >> xs[i];\n\n    vector<pair<int,int>>\
    \ edges(m);\n    for (auto& [u, v] : edges) {\n        cin >> u >> v;\n    }\n\
    \n    auto res = find_all_triangles(n, edges);\n    int sum = 0;\n    const int\
    \ MOD = 998244353;\n    for (auto [i, j, k] : res) {\n        sum = (sum + xs[i]\
    \ * xs[j] % MOD * xs[k]) % MOD;\n    }\n    cout << sum << endl;\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../find_triangles.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin >> n >> m;\n\
    \    vector<int> xs(n);\n    REP(i,n) cin >> xs[i];\n\n    vector<pair<int,int>>\
    \ edges(m);\n    for (auto& [u, v] : edges) {\n        cin >> u >> v;\n    }\n\
    \n    auto res = find_all_triangles(n, edges);\n    int sum = 0;\n    const int\
    \ MOD = 998244353;\n    for (auto [i, j, k] : res) {\n        sum = (sum + xs[i]\
    \ * xs[j] % MOD * xs[k]) % MOD;\n    }\n    cout << sum << endl;\n    return 0;\n\
    }\n"
  dependsOn:
  - Graph/find_triangles.h
  isVerificationFile: true
  path: Graph/tests/triangles.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 04:24:18+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Graph/tests/triangles.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/triangles.test.cpp
- /verify/Graph/tests/triangles.test.cpp.html
title: Graph/tests/triangles.test.cpp
---
