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
    - https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "#line 1 \"Graph/Misc/find_triangles.h\"\n// Find all cycles of length\
    \ 3 (a.k.a. triangles)\n// Complexity: O(N + M*sqrt(M))\n//\n// Index from 0\n\
    //\n// Tested:\n// - https://judge.yosupo.jp/problem/enumerate_triangles\nvector<\
    \ tuple<int,int,int> > find_all_triangles(\n        int n,\n        vector<pair<int,int>>\
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
    \ good[j] = false;\n    }\n    return res;\n}\n"
  code: "// Find all cycles of length 3 (a.k.a. triangles)\n// Complexity: O(N + M*sqrt(M))\n\
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
    \ good[j] = false;\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Misc/find_triangles.h
  requiredBy: []
  timestamp: '2021-12-30 19:55:26+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Misc/find_triangles.h
layout: document
redirect_from:
- /library/Graph/Misc/find_triangles.h
- /library/Graph/Misc/find_triangles.h.html
title: Graph/Misc/find_triangles.h
---
