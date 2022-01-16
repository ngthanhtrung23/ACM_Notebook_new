---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/aizu_grl_3_a_articulation_points.test.cpp
    title: Graph/tests/aizu_grl_3_a_articulation_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/tests/aizu_grl_3_b_bridge.test.cpp
    title: Graph/tests/aizu_grl_3_b_bridge.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/tests/bridge_biconnected.test.cpp
    title: Graph/tests/bridge_biconnected.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"Graph/DfsTree/BridgeArticulation.h\"\n// Assume already\
    \ have undirected graph vector< vector<int> > G with V vertices\n// Vertex index\
    \ from 0\n// Usage:\n// UndirectedDfs tree;\n// Then you can use tree.bridges\
    \ and tree.articulation_points\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/two_edge_connected_components\n\
    struct UndirectedDfs {\n    vector<vector<int>> g;\n    int n;\n    vector<int>\
    \ low, num, parent;\n    vector<bool> is_articulation;\n    int counter, root,\
    \ children;\n\n    vector< pair<int,int> > bridges;\n    vector<int> articulation_points;\n\
    \    map<pair<int,int>, int> cnt_edges;\n\n    UndirectedDfs(const vector<vector<int>>&\
    \ _g) : g(_g), n(g.size()),\n            low(n, 0), num(n, -1), parent(n, 0),\
    \ is_articulation(n, false),\n            counter(0), children(0) {\n        for\
    \ (int u = 0; u < n; u++) {\n            for (int v : g[u]) {\n              \
    \  cnt_edges[{u, v}] += 1;\n            }\n        }\n        for(int i = 0; i\
    \ < n; ++i) if (num[i] == -1) {\n            root = i; children = 0;\n       \
    \     dfs(i);\n            is_articulation[root] = (children > 1);\n        }\n\
    \        for(int i = 0; i < n; ++i)\n            if (is_articulation[i]) articulation_points.push_back(i);\n\
    \    }\nprivate:\n    void dfs(int u) {\n        low[u] = num[u] = counter++;\n\
    \        for (int v : g[u]) {\n            if (num[v] == -1) {\n             \
    \   parent[v] = u;\n                if (u == root) children++;\n             \
    \   dfs(v);\n                if (low[v] >= num[u])\n                    is_articulation[u]\
    \ = true;\n                if (low[v] > num[u]) {\n                    if (cnt_edges[{u,\
    \ v}] == 1) {\n                        bridges.push_back(make_pair(u, v));\n \
    \                   }\n                }\n                low[u] = min(low[u],\
    \ low[v]);\n            } else if (v != parent[u])\n                low[u] = min(low[u],\
    \ num[v]);\n        }\n    }\n};\n"
  code: "// Assume already have undirected graph vector< vector<int> > G with V vertices\n\
    // Vertex index from 0\n// Usage:\n// UndirectedDfs tree;\n// Then you can use\
    \ tree.bridges and tree.articulation_points\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/two_edge_connected_components\n\
    struct UndirectedDfs {\n    vector<vector<int>> g;\n    int n;\n    vector<int>\
    \ low, num, parent;\n    vector<bool> is_articulation;\n    int counter, root,\
    \ children;\n\n    vector< pair<int,int> > bridges;\n    vector<int> articulation_points;\n\
    \    map<pair<int,int>, int> cnt_edges;\n\n    UndirectedDfs(const vector<vector<int>>&\
    \ _g) : g(_g), n(g.size()),\n            low(n, 0), num(n, -1), parent(n, 0),\
    \ is_articulation(n, false),\n            counter(0), children(0) {\n        for\
    \ (int u = 0; u < n; u++) {\n            for (int v : g[u]) {\n              \
    \  cnt_edges[{u, v}] += 1;\n            }\n        }\n        for(int i = 0; i\
    \ < n; ++i) if (num[i] == -1) {\n            root = i; children = 0;\n       \
    \     dfs(i);\n            is_articulation[root] = (children > 1);\n        }\n\
    \        for(int i = 0; i < n; ++i)\n            if (is_articulation[i]) articulation_points.push_back(i);\n\
    \    }\nprivate:\n    void dfs(int u) {\n        low[u] = num[u] = counter++;\n\
    \        for (int v : g[u]) {\n            if (num[v] == -1) {\n             \
    \   parent[v] = u;\n                if (u == root) children++;\n             \
    \   dfs(v);\n                if (low[v] >= num[u])\n                    is_articulation[u]\
    \ = true;\n                if (low[v] > num[u]) {\n                    if (cnt_edges[{u,\
    \ v}] == 1) {\n                        bridges.push_back(make_pair(u, v));\n \
    \                   }\n                }\n                low[u] = min(low[u],\
    \ low[v]);\n            } else if (v != parent[u])\n                low[u] = min(low[u],\
    \ num[v]);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/DfsTree/BridgeArticulation.h
  requiredBy: []
  timestamp: '2022-01-10 01:46:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/bridge_biconnected.test.cpp
  - Graph/tests/aizu_grl_3_b_bridge.test.cpp
  - Graph/tests/aizu_grl_3_a_articulation_points.test.cpp
documentation_of: Graph/DfsTree/BridgeArticulation.h
layout: document
redirect_from:
- /library/Graph/DfsTree/BridgeArticulation.h
- /library/Graph/DfsTree/BridgeArticulation.h.html
title: Graph/DfsTree/BridgeArticulation.h
---
