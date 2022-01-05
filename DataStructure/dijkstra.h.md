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
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"DataStructure/dijkstra.h\"\n// Dijkstra\n//\n// Notes:\n\
    // - Index from 0\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/shortest_path\n\
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
    \   return {f[target], path};\n}\n"
  code: "// Dijkstra\n//\n// Notes:\n// - Index from 0\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/shortest_path\n\
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
    \   return {f[target], path};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/dijkstra.h
  requiredBy: []
  timestamp: '2022-01-02 23:33:14+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/dijkstra.h
layout: document
redirect_from:
- /library/DataStructure/dijkstra.h
- /library/DataStructure/dijkstra.h.html
title: DataStructure/dijkstra.h
---
