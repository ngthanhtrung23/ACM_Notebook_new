---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp
    title: Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/tests/tree_diameter.test.cpp
    title: Graph/tests/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"Graph/tree_diameter.h\"\n// Tree diameter (weighted)\n//\
    \ Index from 0\n// Return {length, path}\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/tree_diameter\n\
    using ll = long long;\npair<ll, vector<int>> get_diameter(const vector<vector<pair<int,int>>>&\
    \ g) {\n    int n = g.size();\n    vector<ll> dist(n);\n    vector<int> parent(n);\n\
    \n    function<void(int, int, ll)> dfs = [&] (int u, int fu, ll cur_dist) {\n\
    \        dist[u] = cur_dist;\n        parent[u] = fu;\n        for (auto [v, cost]\
    \ : g[u]) if (v != fu) {\n            dfs(v, u, cur_dist + cost);\n        }\n\
    \    };\n    dfs(0, -1, 0);\n    // r = furthest node from root\n    int r = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n    dfs(r, -1, 0);\n    // r->s = longest path\n\
    \    int s = max_element(dist.begin(), dist.end()) - dist.begin();\n\n    vector<int>\
    \ path;\n    for (int x = s; x >= 0; x = parent[x]) path.push_back(x);\n\n   \
    \ return {dist[s], path};\n}\n"
  code: "// Tree diameter (weighted)\n// Index from 0\n// Return {length, path}\n\
    //\n// Tested:\n// - https://judge.yosupo.jp/problem/tree_diameter\nusing ll =\
    \ long long;\npair<ll, vector<int>> get_diameter(const vector<vector<pair<int,int>>>&\
    \ g) {\n    int n = g.size();\n    vector<ll> dist(n);\n    vector<int> parent(n);\n\
    \n    function<void(int, int, ll)> dfs = [&] (int u, int fu, ll cur_dist) {\n\
    \        dist[u] = cur_dist;\n        parent[u] = fu;\n        for (auto [v, cost]\
    \ : g[u]) if (v != fu) {\n            dfs(v, u, cur_dist + cost);\n        }\n\
    \    };\n    dfs(0, -1, 0);\n    // r = furthest node from root\n    int r = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n    dfs(r, -1, 0);\n    // r->s = longest path\n\
    \    int s = max_element(dist.begin(), dist.end()) - dist.begin();\n\n    vector<int>\
    \ path;\n    for (int x = s; x >= 0; x = parent[x]) path.push_back(x);\n\n   \
    \ return {dist[s], path};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/tree_diameter.h
  requiredBy: []
  timestamp: '2021-12-31 14:19:54+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp
  - Graph/tests/tree_diameter.test.cpp
documentation_of: Graph/tree_diameter.h
layout: document
redirect_from:
- /library/Graph/tree_diameter.h
- /library/Graph/tree_diameter.h.html
title: Graph/tree_diameter.h
---
