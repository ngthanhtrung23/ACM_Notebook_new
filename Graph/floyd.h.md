---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/floyd_aizu.test.cpp
    title: Graph/tests/floyd_aizu.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1672/
    - https://oj.vnoi.info/problem/floyd
  bundledCode: "#line 1 \"Graph/floyd.h\"\n// Tested:\n// - https://cses.fi/problemset/task/1672/\n\
    // - (trace) https://oj.vnoi.info/problem/floyd\nusing ll = long long;\nconst\
    \ ll INF = 4e18;\nstruct Floyd {\n    Floyd(int _n, const std::vector<std::vector<ll>>\
    \ _c) : n(_n), c(_c), trace(n) {\n        for (int i = 0; i < n; i++) {\n    \
    \        trace[i] = std::vector<int> (n, -1);\n            for (int j = 0; j <\
    \ n; j++) {\n                if (c[i][j] == INF) trace[i][j] = -1;\n         \
    \       else trace[i][j] = i;\n            }\n        }\n\n        for (int k\
    \ = 0; k < n; k++) {\n            for (int i = 0; i < n; i++) {\n            \
    \    for (int j = 0; j < n; j++) {\n                    if (c[i][k] != INF &&\
    \ c[k][j] != INF && c[i][j] > c[i][k] + c[k][j]) {\n                        c[i][j]\
    \ = c[i][k] + c[k][j];\n                        trace[i][j] = trace[k][j];\n \
    \                   }\n                }\n            }\n        }\n    }\n\n\
    \    // Return {distance, path}\n    // If no path -> returns {-1, {}}\n    std::pair<ll,\
    \ std::vector<int>> get_path(int start, int target) {\n        if (trace[start][target]\
    \ == -1) return {-1, {}};\n\n        std::vector<int> path;\n        for (int\
    \ u = target; u != start; u = trace[start][u]) {\n            path.push_back(u);\n\
    \        }\n        path.push_back(start);\n        reverse(path.begin(), path.end());\n\
    \        return {c[start][target], path};\n    }\n\n    int n;\n    std::vector<std::vector<ll>>\
    \ c;\n    std::vector<std::vector<int>> trace;\n};\n\n"
  code: "// Tested:\n// - https://cses.fi/problemset/task/1672/\n// - (trace) https://oj.vnoi.info/problem/floyd\n\
    using ll = long long;\nconst ll INF = 4e18;\nstruct Floyd {\n    Floyd(int _n,\
    \ const std::vector<std::vector<ll>> _c) : n(_n), c(_c), trace(n) {\n        for\
    \ (int i = 0; i < n; i++) {\n            trace[i] = std::vector<int> (n, -1);\n\
    \            for (int j = 0; j < n; j++) {\n                if (c[i][j] == INF)\
    \ trace[i][j] = -1;\n                else trace[i][j] = i;\n            }\n  \
    \      }\n\n        for (int k = 0; k < n; k++) {\n            for (int i = 0;\
    \ i < n; i++) {\n                for (int j = 0; j < n; j++) {\n             \
    \       if (c[i][k] != INF && c[k][j] != INF && c[i][j] > c[i][k] + c[k][j]) {\n\
    \                        c[i][j] = c[i][k] + c[k][j];\n                      \
    \  trace[i][j] = trace[k][j];\n                    }\n                }\n    \
    \        }\n        }\n    }\n\n    // Return {distance, path}\n    // If no path\
    \ -> returns {-1, {}}\n    std::pair<ll, std::vector<int>> get_path(int start,\
    \ int target) {\n        if (trace[start][target] == -1) return {-1, {}};\n\n\
    \        std::vector<int> path;\n        for (int u = target; u != start; u =\
    \ trace[start][u]) {\n            path.push_back(u);\n        }\n        path.push_back(start);\n\
    \        reverse(path.begin(), path.end());\n        return {c[start][target],\
    \ path};\n    }\n\n    int n;\n    std::vector<std::vector<ll>> c;\n    std::vector<std::vector<int>>\
    \ trace;\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/floyd.h
  requiredBy: []
  timestamp: '2022-01-10 00:09:25+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/floyd_aizu.test.cpp
documentation_of: Graph/floyd.h
layout: document
redirect_from:
- /library/Graph/floyd.h
- /library/Graph/floyd.h.html
title: Graph/floyd.h
---
