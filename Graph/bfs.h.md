---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/aizu_alds1_11_c_bfs.test.cpp
    title: Graph/tests/aizu_alds1_11_c_bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1193/
    - https://cses.fi/problemset/task/1667/
    - https://oj.vnoi.info/problem/vcoldwat
    - https://oj.vnoi.info/problem/vmunch
  bundledCode: "#line 1 \"Graph/bfs.h\"\n// BFS {{{\n// - Index from 0\n// - Directed\n\
    // - Supports multi-source BFS\n// - Supports reconstruct path\n//\n// Tested:\n\
    // - https://oj.vnoi.info/problem/vmunch\n// - https://oj.vnoi.info/problem/vcoldwat\n\
    // - (trace) https://cses.fi/problemset/task/1667/\n// - (multi-source) https://cses.fi/problemset/task/1193/\n\
    struct Graph {\n    Graph(int _n) : n(_n), g(n) {}\n\n    void add_edge(int u,\
    \ int v, bool bi_directional = false) {\n        g[u].push_back(v);\n        if\
    \ (bi_directional) g[v].push_back(u);\n    }\n\n    // return\n    // - shortest\
    \ distance from start -> target\n    // - path\n    // If no path -> returns -1\n\
    \    pair<int, vector<int>> bfs(int start, int target) const {\n        assert(0\
    \ <= start && start < n);\n        assert(0 <= target && target < n);\n\n    \
    \    auto [dist, trace] = _bfs({start}, target);\n        if (dist[target] < 0)\
    \ {\n            return {dist[target], {}};\n        }\n        vector<int> path;\n\
    \        for (int u = target; u != start; u = trace[u]) {\n            path.push_back(u);\n\
    \        }\n        path.push_back(start);\n        reverse(path.begin(), path.end());\n\
    \        return {dist[target], path};\n    }\n\n    // return: dist: vector<int>,\
    \ dist[u] = shortest distance from start -> u\n    vector<int> bfs(int start)\
    \ const {\n        assert(0 <= start && start < n);\n        return _bfs({start},\
    \ -1).first;\n    }\n\n    // multi-source BFS\n    // Return: dist[u] = shortest\
    \ distance from any source -> u\n    vector<int> bfs(vector<int> starts) const\
    \ {\n        return _bfs(starts, -1).first;\n    }\n\n// private:\n\n    // Start\
    \ BFS from start, and stop when reaching target.\n    // Start = -1 -> BFS whole\
    \ graph\n    // Returns {distance, trace}\n    pair<vector<int>, vector<int>>\
    \ _bfs(vector<int> starts, int target) const {\n        assert(-1 <= target &&\
    \ target < n);\n\n        queue<int> qu;\n        vector<int> dist(g.size(), -1);\n\
    \        vector<int> trace(g.size(), -1);\n\n        for (int start : starts)\
    \ {\n            assert(0 <= start && start < n);\n            dist[start] = 0;\n\
    \            qu.push(start);\n        }\n\n        while (!qu.empty()) {\n   \
    \         auto u = qu.front(); qu.pop();\n            if (u == target) {\n   \
    \             break;\n            }\n\n            for (const auto& v : g[u])\
    \ {\n                if (dist[v] == -1) {\n                    dist[v] = dist[u]\
    \ + 1;\n                    trace[v] = u;\n                    qu.push(v);\n \
    \               }\n            }\n        }\n\n        return {dist, trace};\n\
    \    }\n\n    int n;\n    vector<vector<int>> g;\n};\n// }}}\n"
  code: "// BFS {{{\n// - Index from 0\n// - Directed\n// - Supports multi-source\
    \ BFS\n// - Supports reconstruct path\n//\n// Tested:\n// - https://oj.vnoi.info/problem/vmunch\n\
    // - https://oj.vnoi.info/problem/vcoldwat\n// - (trace) https://cses.fi/problemset/task/1667/\n\
    // - (multi-source) https://cses.fi/problemset/task/1193/\nstruct Graph {\n  \
    \  Graph(int _n) : n(_n), g(n) {}\n\n    void add_edge(int u, int v, bool bi_directional\
    \ = false) {\n        g[u].push_back(v);\n        if (bi_directional) g[v].push_back(u);\n\
    \    }\n\n    // return\n    // - shortest distance from start -> target\n   \
    \ // - path\n    // If no path -> returns -1\n    pair<int, vector<int>> bfs(int\
    \ start, int target) const {\n        assert(0 <= start && start < n);\n     \
    \   assert(0 <= target && target < n);\n\n        auto [dist, trace] = _bfs({start},\
    \ target);\n        if (dist[target] < 0) {\n            return {dist[target],\
    \ {}};\n        }\n        vector<int> path;\n        for (int u = target; u !=\
    \ start; u = trace[u]) {\n            path.push_back(u);\n        }\n        path.push_back(start);\n\
    \        reverse(path.begin(), path.end());\n        return {dist[target], path};\n\
    \    }\n\n    // return: dist: vector<int>, dist[u] = shortest distance from start\
    \ -> u\n    vector<int> bfs(int start) const {\n        assert(0 <= start && start\
    \ < n);\n        return _bfs({start}, -1).first;\n    }\n\n    // multi-source\
    \ BFS\n    // Return: dist[u] = shortest distance from any source -> u\n    vector<int>\
    \ bfs(vector<int> starts) const {\n        return _bfs(starts, -1).first;\n  \
    \  }\n\n// private:\n\n    // Start BFS from start, and stop when reaching target.\n\
    \    // Start = -1 -> BFS whole graph\n    // Returns {distance, trace}\n    pair<vector<int>,\
    \ vector<int>> _bfs(vector<int> starts, int target) const {\n        assert(-1\
    \ <= target && target < n);\n\n        queue<int> qu;\n        vector<int> dist(g.size(),\
    \ -1);\n        vector<int> trace(g.size(), -1);\n\n        for (int start : starts)\
    \ {\n            assert(0 <= start && start < n);\n            dist[start] = 0;\n\
    \            qu.push(start);\n        }\n\n        while (!qu.empty()) {\n   \
    \         auto u = qu.front(); qu.pop();\n            if (u == target) {\n   \
    \             break;\n            }\n\n            for (const auto& v : g[u])\
    \ {\n                if (dist[v] == -1) {\n                    dist[v] = dist[u]\
    \ + 1;\n                    trace[v] = u;\n                    qu.push(v);\n \
    \               }\n            }\n        }\n\n        return {dist, trace};\n\
    \    }\n\n    int n;\n    vector<vector<int>> g;\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bfs.h
  requiredBy: []
  timestamp: '2022-08-09 14:38:08+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/aizu_alds1_11_c_bfs.test.cpp
documentation_of: Graph/bfs.h
layout: document
redirect_from:
- /library/Graph/bfs.h
- /library/Graph/bfs.h.html
title: Graph/bfs.h
---
