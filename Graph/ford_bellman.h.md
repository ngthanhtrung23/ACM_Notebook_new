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
    - https://cses.fi/problemset/task/1673
  bundledCode: "#line 1 \"Graph/ford_bellman.h\"\n// Ford Bellman, O(N*M)\n// Tested:\n\
    // - https://cses.fi/problemset/task/1673\nusing ll = long long;\nconst ll INF\
    \ = 4e18;\nstruct Edge { int u, v; ll cost; }; // one-direction\n\n// Returns\
    \ {is distance to target bounded?, shortest distance from start -> target}\nstd::pair<bool,\
    \ ll> ford_bellman(int n, int start, int target, const vector<Edge>& edges) {\n\
    \    int m = edges.size();\n    std::vector<ll> f(n, INF);\n    f[start] = 0;\n\
    \ \n    // Init f\n    for (int turn = 0; turn < m; turn++) {\n        for (auto\
    \ [u, v, cost] : edges) {\n            if (f[u] != INF && f[v] > f[u] + cost)\
    \ {\n                f[v] = f[u] + cost;\n            }\n        }\n    }\n \n\
    \    // Find all unbounded vertices\n    auto cur_f = f;\n    for (int turn =\
    \ 0; turn < m; turn++) {\n        for (auto [u, v, cost] : edges) {\n        \
    \    if (f[u] != INF && f[v] > f[u] + cost) {\n                f[v] = f[u] + cost;\n\
    \            }\n        }\n    }\n \n    // Set all unbounded vertices to -INF\n\
    \    for (int i = 0; i < n; i++) {\n        if (f[i] != cur_f[i]) {\n        \
    \    f[i] = -INF;\n        }\n    }\n \n    // Re-update all f\n    for (int turn\
    \ = 0; turn < m; turn++) {\n        for (auto [u, v, cost] : edges) {\n      \
    \      if (f[u] != INF && f[v] > f[u] + cost) {\n                f[v] = f[u] +\
    \ cost;\n            }\n        }\n    }\n    return {f[target] == cur_f[target],\
    \ f[target]};\n}\n"
  code: "// Ford Bellman, O(N*M)\n// Tested:\n// - https://cses.fi/problemset/task/1673\n\
    using ll = long long;\nconst ll INF = 4e18;\nstruct Edge { int u, v; ll cost;\
    \ }; // one-direction\n\n// Returns {is distance to target bounded?, shortest\
    \ distance from start -> target}\nstd::pair<bool, ll> ford_bellman(int n, int\
    \ start, int target, const vector<Edge>& edges) {\n    int m = edges.size();\n\
    \    std::vector<ll> f(n, INF);\n    f[start] = 0;\n \n    // Init f\n    for\
    \ (int turn = 0; turn < m; turn++) {\n        for (auto [u, v, cost] : edges)\
    \ {\n            if (f[u] != INF && f[v] > f[u] + cost) {\n                f[v]\
    \ = f[u] + cost;\n            }\n        }\n    }\n \n    // Find all unbounded\
    \ vertices\n    auto cur_f = f;\n    for (int turn = 0; turn < m; turn++) {\n\
    \        for (auto [u, v, cost] : edges) {\n            if (f[u] != INF && f[v]\
    \ > f[u] + cost) {\n                f[v] = f[u] + cost;\n            }\n     \
    \   }\n    }\n \n    // Set all unbounded vertices to -INF\n    for (int i = 0;\
    \ i < n; i++) {\n        if (f[i] != cur_f[i]) {\n            f[i] = -INF;\n \
    \       }\n    }\n \n    // Re-update all f\n    for (int turn = 0; turn < m;\
    \ turn++) {\n        for (auto [u, v, cost] : edges) {\n            if (f[u] !=\
    \ INF && f[v] > f[u] + cost) {\n                f[v] = f[u] + cost;\n        \
    \    }\n        }\n    }\n    return {f[target] == cur_f[target], f[target]};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ford_bellman.h
  requiredBy: []
  timestamp: '2022-01-07 16:03:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/ford_bellman.h
layout: document
redirect_from:
- /library/Graph/ford_bellman.h
- /library/Graph/ford_bellman.h.html
title: Graph/ford_bellman.h
---
