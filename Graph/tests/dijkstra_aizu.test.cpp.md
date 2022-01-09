---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.h
    title: Graph/dijkstra.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"Graph/tests/dijkstra_aizu.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/dijkstra.h\"\n// Dijkstra\n\
    //\n// Notes:\n// - Index from 0\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/shortest_path\n\
    //\n// Param:\n// - g[u] = pair<v, cost>, adjacency list\n// - start = start vertex\n\
    // Returns:\n// - distances from start. If unreachable -> dist = INF\n// - previous\
    \ vertex. Previous[start] = start. If unreachable -> trace = -1\nusing ll = long\
    \ long;\nconst ll INF = 1e18;  // must be greater than maximum possible path\n\
    pair<vector<ll>, vector<int>> dijkstra(const vector<vector<pair<int, ll>>>& g,\
    \ int start) {\n    int n = g.size();\n    vector<ll> f(n, INF);\n    vector<int>\
    \ trace(n, -1);\n    f[start] = 0;\n    trace[start] = start;\n    using P = pair<ll,\
    \ int>;  // <distance, vertex>\n\n    // priority_queue should be faster than\
    \ set?\n    priority_queue<P, vector<P>, greater<P>> all;\n    all.push(P{0LL,\
    \ start});\n    while (!all.empty()) {\n        auto [dist, u] = all.top();\n\
    \        all.pop();\n        if (dist != f[u]) continue;\n\n        for (auto\
    \ [v, c] : g[u]) {\n            if (f[v] > f[u] + c) {\n                f[v] =\
    \ f[u] + c;\n                trace[v] = u;\n                all.push(P{f[v], v});\n\
    \            }\n        }\n    }\n\n    return {f, trace};\n}\n\n// Dijkstra from\
    \ start -> target\n// Returns:\n// - distance. If unreachable -> INF\n// - path.\
    \ If unreachable -> {}\npair<ll, vector<int>> dijkstra(const vector<vector<pair<int,\
    \ ll>>>& g, int start, int target) {\n    auto [f, trace] = dijkstra(g, start);\n\
    \    if (trace[target] < 0) {\n        return {INF, {}};\n    }\n\n    vector<int>\
    \ path;\n    for (int u = target; u != start; u = trace[u]) {\n        path.push_back(u);\n\
    \    }\n    path.push_back(start);\n    reverse(path.begin(), path.end());\n \
    \   return {f[target], path};\n}\n#line 7 \"Graph/tests/dijkstra_aizu.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m, start;\
    \ cin >> n >> m >> start;\n    vector< vector<pair<int, ll>> > g(n);\n    while\
    \ (m--) {\n        int u, v, c; cin >> u >> v >> c;\n        g[u].push_back({v,\
    \ c});\n    }\n    auto [dist, trace] = dijkstra(g, start);\n    for (auto d :\
    \ dist) {\n        if (d == INF) cout << \"INF\\n\";\n        else cout << d <<\
    \ '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../dijkstra.h\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m, start;\
    \ cin >> n >> m >> start;\n    vector< vector<pair<int, ll>> > g(n);\n    while\
    \ (m--) {\n        int u, v, c; cin >> u >> v >> c;\n        g[u].push_back({v,\
    \ c});\n    }\n    auto [dist, trace] = dijkstra(g, start);\n    for (auto d :\
    \ dist) {\n        if (d == INF) cout << \"INF\\n\";\n        else cout << d <<\
    \ '\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - Graph/dijkstra.h
  isVerificationFile: true
  path: Graph/tests/dijkstra_aizu.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 00:30:04+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/dijkstra_aizu.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/dijkstra_aizu.test.cpp
- /verify/Graph/tests/dijkstra_aizu.test.cpp.html
title: Graph/tests/dijkstra_aizu.test.cpp
---
