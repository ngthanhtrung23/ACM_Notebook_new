---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/DfsTree/BridgeArticulation.h
    title: Graph/DfsTree/BridgeArticulation.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"Graph/tests/aizu_grl_3_b_bridge.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/DfsTree/BridgeArticulation.h\"\
    \n// Assume already have undirected graph vector< vector<int> > G with V vertices\n\
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
    \ num[v]);\n        }\n    }\n};\n#line 7 \"Graph/tests/aizu_grl_3_b_bridge.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin >> n >> m;\n\
    \    vector<vector<int>> g(n);\n    REP(i,m) {\n        int u, v; cin >> u >>\
    \ v;\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\n    UndirectedDfs\
    \ tree(g);\n    auto bridges = tree.bridges;\n\n    for (auto& [u, v] : bridges)\
    \ {\n        if (u > v) swap(u, v);\n    }\n    sort(bridges.begin(), bridges.end());\n\
    \n    for (auto [u, v] : bridges) {\n        cout << u << ' ' << v << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../DfsTree/BridgeArticulation.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin >> n >> m;\n\
    \    vector<vector<int>> g(n);\n    REP(i,m) {\n        int u, v; cin >> u >>\
    \ v;\n        g[u].push_back(v);\n        g[v].push_back(u);\n    }\n\n    UndirectedDfs\
    \ tree(g);\n    auto bridges = tree.bridges;\n\n    for (auto& [u, v] : bridges)\
    \ {\n        if (u > v) swap(u, v);\n    }\n    sort(bridges.begin(), bridges.end());\n\
    \n    for (auto [u, v] : bridges) {\n        cout << u << ' ' << v << endl;\n\
    \    }\n}\n"
  dependsOn:
  - Graph/DfsTree/BridgeArticulation.h
  isVerificationFile: true
  path: Graph/tests/aizu_grl_3_b_bridge.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 21:41:41+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/aizu_grl_3_b_bridge.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/aizu_grl_3_b_bridge.test.cpp
- /verify/Graph/tests/aizu_grl_3_b_bridge.test.cpp.html
title: Graph/tests/aizu_grl_3_b_bridge.test.cpp
---
