---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/DfsTree/StronglyConnected.h
    title: Graph/DfsTree/StronglyConnected.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"Graph/tests/strongly_connected.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 1 \"Graph/DfsTree/StronglyConnected.h\"\n// Index from 0\n// Usage:\n\
    // DirectedDfs tree;\n// Now you can use tree.scc\n//\n// Note: reverse(tree.scc)\
    \ is topo sorted\n//\n// Tested:\n// - (requires scc to be topo sorted) https://judge.yosupo.jp/problem/scc\n\
    struct DirectedDfs {\n    vector<vector<int>> G;\n    int V;\n    vector<int>\
    \ num, low, current, S;\n    int counter;\n    vector<int> comp_ids;\n    vector<\
    \ vector<int> > scc;\n\n    DirectedDfs(const vector<vector<int>>& _G) : G(_G),\
    \ V(G.size()),\n            num(V, -1), low(V, 0), current(V, 0), counter(0),\
    \ comp_ids(V, -1) {\n        for (int i = 0; i < V; i++) {\n            if (num[i]\
    \ == -1) dfs(i);\n        }\n    }\n\n    void dfs(int u) {\n        low[u] =\
    \ num[u] = counter++;\n        S.push_back(u);\n        current[u] = 1;\n    \
    \    for (auto v : G[u]) {\n            if (num[v] == -1) dfs(v);\n          \
    \  if (current[v]) low[u] = min(low[u], low[v]);\n        }\n        if (low[u]\
    \ == num[u]) {\n            scc.push_back(vector<int>());\n            while (1)\
    \ {\n                int v = S.back(); S.pop_back(); current[v] = 0;\n       \
    \         scc.back().push_back(v);\n                comp_ids[v] = ((int) scc.size())\
    \ - 1;\n                if (u == v) break;\n            }\n        }\n    }\n\
    };\n#line 7 \"Graph/tests/strongly_connected.test.cpp\"\n\n#define REP(i, a) for\
    \ (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x) ((int)(x).size())\n\n\
    int32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin\
    \ >> n >> m;\n    vector<vector<int>> g(n);\n    REP(i,m) {\n        int u, v;\
    \ cin >> u >> v;\n        g[u].push_back(v);\n    }\n\n    DirectedDfs tree(g);\n\
    \n    reverse(tree.scc.begin(), tree.scc.end());\n    cout << SZ(tree.scc) <<\
    \ endl;\n    for (auto comp : tree.scc) {\n        cout << comp.size();\n    \
    \    for (int x : comp) cout << ' ' << x;\n        cout << '\\n';\n    }\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../DfsTree/StronglyConnected.h\"\n\n#define\
    \ REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x) ((int)(x).size())\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin\
    \ >> n >> m;\n    vector<vector<int>> g(n);\n    REP(i,m) {\n        int u, v;\
    \ cin >> u >> v;\n        g[u].push_back(v);\n    }\n\n    DirectedDfs tree(g);\n\
    \n    reverse(tree.scc.begin(), tree.scc.end());\n    cout << SZ(tree.scc) <<\
    \ endl;\n    for (auto comp : tree.scc) {\n        cout << comp.size();\n    \
    \    for (int x : comp) cout << ' ' << x;\n        cout << '\\n';\n    }\n   \
    \ return 0;\n}\n"
  dependsOn:
  - Graph/DfsTree/StronglyConnected.h
  isVerificationFile: true
  path: Graph/tests/strongly_connected.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 21:09:50+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/strongly_connected.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/strongly_connected.test.cpp
- /verify/Graph/tests/strongly_connected.test.cpp.html
title: Graph/tests/strongly_connected.test.cpp
---
