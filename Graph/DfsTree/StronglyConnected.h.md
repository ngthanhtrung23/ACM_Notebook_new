---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp
    title: Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp
  - icon: ':x:'
    path: Graph/tests/aizu_grl_4_a_strongly_connected_cycle_check.test.cpp
    title: Graph/tests/aizu_grl_4_a_strongly_connected_cycle_check.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/tests/strongly_connected.test.cpp
    title: Graph/tests/strongly_connected.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/tests/two_sat.test.cpp
    title: Graph/tests/two_sat.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"Graph/DfsTree/StronglyConnected.h\"\n// Index from 0\n//\
    \ Usage:\n// DirectedDfs tree;\n// Now you can use tree.scc\n//\n// Note: reverse(tree.scc)\
    \ is topo sorted\n//\n// Tested:\n// - (requires scc to be topo sorted) https://judge.yosupo.jp/problem/scc\n\
    struct DirectedDfs {\n    vector<vector<int>> g;\n    int n;\n    vector<int>\
    \ num, low, current, S;\n    int counter;\n    vector<int> comp_ids;\n    vector<\
    \ vector<int> > scc;\n\n    DirectedDfs(const vector<vector<int>>& _g) : g(_g),\
    \ n(g.size()),\n            num(n, -1), low(n, 0), current(n, 0), counter(0),\
    \ comp_ids(n, -1) {\n        for (int i = 0; i < n; i++) {\n            if (num[i]\
    \ == -1) dfs(i);\n        }\n    }\n\n    void dfs(int u) {\n        low[u] =\
    \ num[u] = counter++;\n        S.push_back(u);\n        current[u] = 1;\n    \
    \    for (auto v : g[u]) {\n            if (num[v] == -1) dfs(v);\n          \
    \  if (current[v]) low[u] = min(low[u], low[v]);\n        }\n        if (low[u]\
    \ == num[u]) {\n            scc.push_back(vector<int>());\n            while (1)\
    \ {\n                int v = S.back(); S.pop_back(); current[v] = 0;\n       \
    \         scc.back().push_back(v);\n                comp_ids[v] = ((int) scc.size())\
    \ - 1;\n                if (u == v) break;\n            }\n        }\n    }\n\
    };\n"
  code: "// Index from 0\n// Usage:\n// DirectedDfs tree;\n// Now you can use tree.scc\n\
    //\n// Note: reverse(tree.scc) is topo sorted\n//\n// Tested:\n// - (requires\
    \ scc to be topo sorted) https://judge.yosupo.jp/problem/scc\nstruct DirectedDfs\
    \ {\n    vector<vector<int>> g;\n    int n;\n    vector<int> num, low, current,\
    \ S;\n    int counter;\n    vector<int> comp_ids;\n    vector< vector<int> > scc;\n\
    \n    DirectedDfs(const vector<vector<int>>& _g) : g(_g), n(g.size()),\n     \
    \       num(n, -1), low(n, 0), current(n, 0), counter(0), comp_ids(n, -1) {\n\
    \        for (int i = 0; i < n; i++) {\n            if (num[i] == -1) dfs(i);\n\
    \        }\n    }\n\n    void dfs(int u) {\n        low[u] = num[u] = counter++;\n\
    \        S.push_back(u);\n        current[u] = 1;\n        for (auto v : g[u])\
    \ {\n            if (num[v] == -1) dfs(v);\n            if (current[v]) low[u]\
    \ = min(low[u], low[v]);\n        }\n        if (low[u] == num[u]) {\n       \
    \     scc.push_back(vector<int>());\n            while (1) {\n               \
    \ int v = S.back(); S.pop_back(); current[v] = 0;\n                scc.back().push_back(v);\n\
    \                comp_ids[v] = ((int) scc.size()) - 1;\n                if (u\
    \ == v) break;\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/DfsTree/StronglyConnected.h
  requiredBy: []
  timestamp: '2022-01-09 22:41:11+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Graph/tests/two_sat.test.cpp
  - Graph/tests/strongly_connected.test.cpp
  - Graph/tests/aizu_grl_4_a_strongly_connected_cycle_check.test.cpp
  - Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp
documentation_of: Graph/DfsTree/StronglyConnected.h
layout: document
redirect_from:
- /library/Graph/DfsTree/StronglyConnected.h
- /library/Graph/DfsTree/StronglyConnected.h.html
title: Graph/DfsTree/StronglyConnected.h
---
