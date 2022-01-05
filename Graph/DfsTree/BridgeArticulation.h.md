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
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"Graph/DfsTree/BridgeArticulation.h\"\n// Assume already\
    \ have undirected graph vector< vector<int> > G with V vertices\n// Vertex index\
    \ from 0\n// Usage:\n// UndirectedDfs tree;\n// Then you can use tree.bridges\
    \ and tree.cuts\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/two_edge_connected_components\n\
    int n;\nvector<vector<int>> g;\nstruct UndirectedDfs {\n    vector<int> low, num,\
    \ parent;\n    vector<bool> articulation;\n    int counter, root, children;\n\n\
    \    vector< pair<int,int> > bridges;\n    vector<int> cuts;\n    map<pair<int,int>,\
    \ int> cnt_edges;\n\n    UndirectedDfs() : low(n, 0), num(n, -1), parent(n, 0),\
    \ articulation(n, false),\n            counter(0), children(0) {\n        for\
    \ (int u = 0; u < n; u++) {\n            for (int v : g[u]) {\n              \
    \  cnt_edges[{u, v}] += 1;\n                cnt_edges[{v, u}] += 1;\n        \
    \    }\n        }\n        for(int i = 0; i < n; ++i) if (num[i] == -1) {\n  \
    \          root = i; children = 0;\n            dfs(i);\n            articulation[root]\
    \ = (children > 1);\n        }\n        for(int i = 0; i < n; ++i)\n         \
    \   if (articulation[i]) cuts.push_back(i);\n    }\nprivate:\n    void dfs(int\
    \ u) {\n        low[u] = num[u] = counter++;\n        for (int v : g[u]) {\n \
    \           if (num[v] == -1) {\n                parent[v] = u;\n            \
    \    if (u == root) children++;\n                dfs(v);\n                if (low[v]\
    \ >= num[u])\n                    articulation[u] = true;\n                if\
    \ (low[v] > num[u]) {\n                    if (cnt_edges[{u, v}] == 2) {\n   \
    \                     bridges.push_back(make_pair(u, v));\n                  \
    \  }\n                }\n                low[u] = min(low[u], low[v]);\n     \
    \       } else if (v != parent[u])\n                low[u] = min(low[u], num[v]);\n\
    \        }\n    }\n};\n"
  code: "// Assume already have undirected graph vector< vector<int> > G with V vertices\n\
    // Vertex index from 0\n// Usage:\n// UndirectedDfs tree;\n// Then you can use\
    \ tree.bridges and tree.cuts\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/two_edge_connected_components\n\
    int n;\nvector<vector<int>> g;\nstruct UndirectedDfs {\n    vector<int> low, num,\
    \ parent;\n    vector<bool> articulation;\n    int counter, root, children;\n\n\
    \    vector< pair<int,int> > bridges;\n    vector<int> cuts;\n    map<pair<int,int>,\
    \ int> cnt_edges;\n\n    UndirectedDfs() : low(n, 0), num(n, -1), parent(n, 0),\
    \ articulation(n, false),\n            counter(0), children(0) {\n        for\
    \ (int u = 0; u < n; u++) {\n            for (int v : g[u]) {\n              \
    \  cnt_edges[{u, v}] += 1;\n                cnt_edges[{v, u}] += 1;\n        \
    \    }\n        }\n        for(int i = 0; i < n; ++i) if (num[i] == -1) {\n  \
    \          root = i; children = 0;\n            dfs(i);\n            articulation[root]\
    \ = (children > 1);\n        }\n        for(int i = 0; i < n; ++i)\n         \
    \   if (articulation[i]) cuts.push_back(i);\n    }\nprivate:\n    void dfs(int\
    \ u) {\n        low[u] = num[u] = counter++;\n        for (int v : g[u]) {\n \
    \           if (num[v] == -1) {\n                parent[v] = u;\n            \
    \    if (u == root) children++;\n                dfs(v);\n                if (low[v]\
    \ >= num[u])\n                    articulation[u] = true;\n                if\
    \ (low[v] > num[u]) {\n                    if (cnt_edges[{u, v}] == 2) {\n   \
    \                     bridges.push_back(make_pair(u, v));\n                  \
    \  }\n                }\n                low[u] = min(low[u], low[v]);\n     \
    \       } else if (v != parent[u])\n                low[u] = min(low[u], num[v]);\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/DfsTree/BridgeArticulation.h
  requiredBy: []
  timestamp: '2021-12-30 14:41:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/DfsTree/BridgeArticulation.h
layout: document
redirect_from:
- /library/Graph/DfsTree/BridgeArticulation.h
- /library/Graph/DfsTree/BridgeArticulation.h.html
title: Graph/DfsTree/BridgeArticulation.h
---
