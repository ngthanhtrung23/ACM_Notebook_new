---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/bfs.test.cpp
    title: Graph/tests/bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1667/
    - https://oj.vnoi.info/problem/vcoldwat
    - https://oj.vnoi.info/problem/vmunch
  bundledCode: "#line 1 \"Graph/bfs.h\"\n// BFS\n// Index from 0\n// Directed\n//\n\
    // Tested:\n// - https://oj.vnoi.info/problem/vmunch\n// - https://oj.vnoi.info/problem/vcoldwat\n\
    // - (trace) https://cses.fi/problemset/task/1667/\nstruct Graph {\n    Graph(int\
    \ n) : g(n) {}\n\n    void add_edge(int u, int v) {\n        g[u].push_back(v);\n\
    \    }\n\n    // return\n    // - shortest distance from start -> target\n   \
    \ // - path\n    // If no path -> returns -1\n    pair<int, vector<int>> bfs(int\
    \ start, int target) {\n        auto [dist, trace] = _bfs(start, target);\n  \
    \      if (dist[target] < 0) {\n            return {dist[target], {}};\n     \
    \   }\n        vector<int> path;\n        for (int u = target; u != start; u =\
    \ trace[u]) {\n            path.push_back(u);\n        }\n        path.push_back(start);\n\
    \        reverse(path.begin(), path.end());\n        return {dist[target], path};\n\
    \    }\n\n    // return: dist: vector<int>, dist[u] = shortest distance from start\
    \ -> u\n    vector<int> bfs(int start) {\n        return _bfs(start, -1).first;\n\
    \    }\n\n// private:\n\n    // Start BFS from start, and stop when reaching target.\n\
    \    // Returns {distance, trace}\n    pair<vector<int>, vector<int>> _bfs(int\
    \ start, int target) {\n        queue<int> qu;\n        vector<int> dist(g.size(),\
    \ -1);\n        vector<int> trace(g.size(), -1);\n\n        dist[start] = 0;\n\
    \        qu.push(start);\n\n        while (!qu.empty()) {\n            auto u\
    \ = qu.front(); qu.pop();\n            if (u == target) {\n                break;\n\
    \            }\n\n            for (const auto& v : g[u]) {\n                if\
    \ (dist[v] == -1) {\n                    dist[v] = dist[u] + 1;\n            \
    \        trace[v] = u;\n                    qu.push(v);\n                }\n \
    \           }\n        }\n\n        return {dist, trace};\n    }\n    vector<vector<int>>\
    \ g;\n};\n"
  code: "// BFS\n// Index from 0\n// Directed\n//\n// Tested:\n// - https://oj.vnoi.info/problem/vmunch\n\
    // - https://oj.vnoi.info/problem/vcoldwat\n// - (trace) https://cses.fi/problemset/task/1667/\n\
    struct Graph {\n    Graph(int n) : g(n) {}\n\n    void add_edge(int u, int v)\
    \ {\n        g[u].push_back(v);\n    }\n\n    // return\n    // - shortest distance\
    \ from start -> target\n    // - path\n    // If no path -> returns -1\n    pair<int,\
    \ vector<int>> bfs(int start, int target) {\n        auto [dist, trace] = _bfs(start,\
    \ target);\n        if (dist[target] < 0) {\n            return {dist[target],\
    \ {}};\n        }\n        vector<int> path;\n        for (int u = target; u !=\
    \ start; u = trace[u]) {\n            path.push_back(u);\n        }\n        path.push_back(start);\n\
    \        reverse(path.begin(), path.end());\n        return {dist[target], path};\n\
    \    }\n\n    // return: dist: vector<int>, dist[u] = shortest distance from start\
    \ -> u\n    vector<int> bfs(int start) {\n        return _bfs(start, -1).first;\n\
    \    }\n\n// private:\n\n    // Start BFS from start, and stop when reaching target.\n\
    \    // Returns {distance, trace}\n    pair<vector<int>, vector<int>> _bfs(int\
    \ start, int target) {\n        queue<int> qu;\n        vector<int> dist(g.size(),\
    \ -1);\n        vector<int> trace(g.size(), -1);\n\n        dist[start] = 0;\n\
    \        qu.push(start);\n\n        while (!qu.empty()) {\n            auto u\
    \ = qu.front(); qu.pop();\n            if (u == target) {\n                break;\n\
    \            }\n\n            for (const auto& v : g[u]) {\n                if\
    \ (dist[v] == -1) {\n                    dist[v] = dist[u] + 1;\n            \
    \        trace[v] = u;\n                    qu.push(v);\n                }\n \
    \           }\n        }\n\n        return {dist, trace};\n    }\n    vector<vector<int>>\
    \ g;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bfs.h
  requiredBy: []
  timestamp: '2022-01-07 13:52:12+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/bfs.test.cpp
documentation_of: Graph/bfs.h
layout: document
redirect_from:
- /library/Graph/bfs.h
- /library/Graph/bfs.h.html
title: Graph/bfs.h
---
