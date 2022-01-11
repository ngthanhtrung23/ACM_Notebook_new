---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/DfsTree/StronglyConnected.h
    title: Graph/DfsTree/StronglyConnected.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/DfsTree/StronglyConnected.h\"\
    \n// Index from 0\n// Usage:\n// DirectedDfs tree;\n// Now you can use tree.scc\n\
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
    \ == v) break;\n            }\n        }\n    }\n};\n#line 7 \"Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin\
    \ >> n >> m;\n    vector<vector<int>> g(n);\n    while (m--) {\n        int u,\
    \ v; cin >> u >> v;\n        g[u].push_back(v);\n    }\n    DirectedDfs tree(g);\n\
    \n    int q; cin >> q;\n    while (q--) {\n        int u, v; cin >> u >> v;\n\
    \        cout << (tree.comp_ids[u] == tree.comp_ids[v]) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../DfsTree/StronglyConnected.h\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin\
    \ >> n >> m;\n    vector<vector<int>> g(n);\n    while (m--) {\n        int u,\
    \ v; cin >> u >> v;\n        g[u].push_back(v);\n    }\n    DirectedDfs tree(g);\n\
    \n    int q; cin >> q;\n    while (q--) {\n        int u, v; cin >> u >> v;\n\
    \        cout << (tree.comp_ids[u] == tree.comp_ids[v]) << '\\n';\n    }\n}\n"
  dependsOn:
  - Graph/DfsTree/StronglyConnected.h
  isVerificationFile: true
  path: Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 21:41:41+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp
- /verify/Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp.html
title: Graph/tests/aizu_grl_3_c_strongly_connected.test.cpp
---
