---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/tree_diameter.h
    title: Graph/tree_diameter.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"Graph/tests/tree_diameter.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"Graph/tree_diameter.h\"\n// Index from 0\n//\
    \ g should contains both (u, v) and (v, u)\n// Return {length, path}\n//\n// Tested:\n\
    // - https://judge.yosupo.jp/problem/tree_diameter\n//\n// Tree diameter (weighted)\
    \ {{{\nusing ll = long long;\npair<ll, vector<int>> tree_diameter(const vector<vector<pair<int,int>>>&\
    \ g) {\n    int n = g.size();\n    vector<ll> dist(n);\n    vector<int> parent(n);\n\
    \n    function<void(int, int, ll)> dfs = [&] (int u, int fu, ll cur_dist) {\n\
    \        dist[u] = cur_dist;\n        parent[u] = fu;\n        for (auto [v, cost]\
    \ : g[u]) if (v != fu) {\n            dfs(v, u, cur_dist + cost);\n        }\n\
    \    };\n    dfs(0, -1, 0);\n    // r = furthest node from root\n    int r = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n    dfs(r, -1, 0);\n    // r->s = longest path\n\
    \    int s = max_element(dist.begin(), dist.end()) - dist.begin();\n\n    vector<int>\
    \ path;\n    for (int x = s; x >= 0; x = parent[x]) path.push_back(x);\n\n   \
    \ return {dist[s], path};\n}\n// }}}\n#line 7 \"Graph/tests/tree_diameter.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x)\
    \ ((int)(x).size())\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n; cin >> n;\n    vector<vector<pair<int,int>>> g(n);\n    REP(i,n-1)\
    \ {\n        int u, v, cost; cin >> u >> v >> cost;\n        g[u].emplace_back(v,\
    \ cost);\n        g[v].emplace_back(u, cost);\n    }\n\n    auto [length, path]\
    \ = tree_diameter(g);\n    cout << length << ' ' << SZ(path) << endl;\n    for\
    \ (int x : path) cout << x << ' ';\n    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../tree_diameter.h\"\n\n\
    #define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x) ((int)(x).size())\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n; cin >>\
    \ n;\n    vector<vector<pair<int,int>>> g(n);\n    REP(i,n-1) {\n        int u,\
    \ v, cost; cin >> u >> v >> cost;\n        g[u].emplace_back(v, cost);\n     \
    \   g[v].emplace_back(u, cost);\n    }\n\n    auto [length, path] = tree_diameter(g);\n\
    \    cout << length << ' ' << SZ(path) << endl;\n    for (int x : path) cout <<\
    \ x << ' ';\n    cout << endl;\n    return 0;\n}\n"
  dependsOn:
  - Graph/tree_diameter.h
  isVerificationFile: true
  path: Graph/tests/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2022-11-21 21:56:30+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/tree_diameter.test.cpp
- /verify/Graph/tests/tree_diameter.test.cpp.html
title: Graph/tests/tree_diameter.test.cpp
---
