---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_grl_5_c_lca.test.cpp
    title: DataStructure/test/aizu_grl_5_c_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/lca.test.cpp
    title: DataStructure/test/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"DataStructure/LCA.h\"\n// LCA\n// Notes:\n// - Index from\
    \ 0\n// - Cannot use for queries like min edge in path u -> v\n//\n// Tested:\n\
    // - https://judge.yosupo.jp/problem/lca\nstruct LCA {\n    const int n;\n   \
    \ vector<vector<int>> adj;\n    const int root;\n    using P = pair<int,int>;\n\
    \    static P f(P x, P y) { return std::min(x, y); }\n\n    LCA(int _n, const\
    \ vector<vector<int>>& _adj, int _root)\n            : n(_n), adj(_adj), root(_root)\
    \ {\n        assert(0 <= root && root < n);\n        id.resize(n);\n        depth.resize(n);\n\
    \        order.reserve(2 * n);\n        dfs(root, -1, 0);\n        rmq = RMQ<P,\
    \ f>(order);\n    }\n\n    int lca(int u, int v) {\n        assert(0 <= u && u\
    \ < n);\n        assert(0 <= v && v < n);\n\n        int x = id[u], y = id[v];\n\
    \        if (x > y) std::swap(x, y);\n        return rmq.get(x, y+1).second;\n\
    \    }\n\n// private:\n    vector<int> id, depth;\n    vector<P> order;\n    RMQ<P,\
    \ f> rmq;\n\n    void dfs(int u, int fu, int d) {\n        id[u] = order.size();\n\
    \        depth[u] = d;\n        order.emplace_back(d, u);\n        for (int v\
    \ : adj[u]) {\n            if (v == fu) continue;\n            dfs(v, u, d + 1);\n\
    \            order.emplace_back(d, u);\n        }\n    }\n};\n"
  code: "// LCA\n// Notes:\n// - Index from 0\n// - Cannot use for queries like min\
    \ edge in path u -> v\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/lca\n\
    struct LCA {\n    const int n;\n    vector<vector<int>> adj;\n    const int root;\n\
    \    using P = pair<int,int>;\n    static P f(P x, P y) { return std::min(x, y);\
    \ }\n\n    LCA(int _n, const vector<vector<int>>& _adj, int _root)\n         \
    \   : n(_n), adj(_adj), root(_root) {\n        assert(0 <= root && root < n);\n\
    \        id.resize(n);\n        depth.resize(n);\n        order.reserve(2 * n);\n\
    \        dfs(root, -1, 0);\n        rmq = RMQ<P, f>(order);\n    }\n\n    int\
    \ lca(int u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v\
    \ && v < n);\n\n        int x = id[u], y = id[v];\n        if (x > y) std::swap(x,\
    \ y);\n        return rmq.get(x, y+1).second;\n    }\n\n// private:\n    vector<int>\
    \ id, depth;\n    vector<P> order;\n    RMQ<P, f> rmq;\n\n    void dfs(int u,\
    \ int fu, int d) {\n        id[u] = order.size();\n        depth[u] = d;\n   \
    \     order.emplace_back(d, u);\n        for (int v : adj[u]) {\n            if\
    \ (v == fu) continue;\n            dfs(v, u, d + 1);\n            order.emplace_back(d,\
    \ u);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LCA.h
  requiredBy: []
  timestamp: '2021-12-29 18:21:32+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/lca.test.cpp
  - DataStructure/test/aizu_grl_5_c_lca.test.cpp
documentation_of: DataStructure/LCA.h
layout: document
redirect_from:
- /library/DataStructure/LCA.h
- /library/DataStructure/LCA.h.html
title: DataStructure/LCA.h
---
