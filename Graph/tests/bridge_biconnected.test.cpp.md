---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/DfsTree/BridgeArticulation.h
    title: Graph/DfsTree/BridgeArticulation.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../DfsTree/BridgeArticulation.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x)\
    \ ((int)(x).size())\n\nvoid dfs(int u,\n        const vector<vector<int>>& g,\n\
    \        const set<pair<int,int>>& bridges,\n        vector<int>& comp,\n    \
    \    vector<bool>& visited) {\n    visited[u] = true;\n    comp.push_back(u);\n\
    \n    for (int v : g[u]) {\n        if (visited[v]) continue;\n        if (bridges.count({v,\
    \ u}) || bridges.count({u, v})) continue;\n\n        dfs(v, g, bridges, comp,\
    \ visited);\n    }\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, m; cin >> n >> m;\n\n    // read edges\n    vector<vector<int>> g(n);\n\
    \    REP(eid,m) {\n        int u, v; cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    UndirectedDfs tree(g);\n    set<pair<int,int>>\
    \ bridges(tree.bridges.begin(), tree.bridges.end());\n\n    vector<bool> visited(n,\
    \ false);\n    vector<vector<int>> components;\n    REP(i,n) {\n        if (!visited[i])\
    \ {\n            vector<int> comp;\n            dfs(i, g, bridges, comp, visited);\n\
    \            components.push_back(comp);\n        }\n    }\n    cout << SZ(components)\
    \ << endl;\n    for (auto&& comp : components) {\n        cout << SZ(comp);\n\
    \        for (int x : comp) cout << ' ' << x;\n        cout << endl;\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - Graph/DfsTree/BridgeArticulation.h
  isVerificationFile: true
  path: Graph/tests/bridge_biconnected.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 21:09:50+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/bridge_biconnected.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/bridge_biconnected.test.cpp
- /verify/Graph/tests/bridge_biconnected.test.cpp.html
title: Graph/tests/bridge_biconnected.test.cpp
---
