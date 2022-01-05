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
    - https://oj.vnoi.info/problem/vcoldwat
    - https://oj.vnoi.info/problem/vmunch
  bundledCode: "#line 1 \"Graph/bfs.h\"\n// BFS\n// Index from 0\n// Directed\n//\n\
    // Tested:\n// - https://oj.vnoi.info/problem/vmunch\n// - https://oj.vnoi.info/problem/vcoldwat\n\
    struct Graph {\n    Graph(int n) : g(n) {}\n\n    void add_edge(int u, int v)\
    \ {\n        g[u].push_back(v);\n    }\n\n    // return shortest distance from\
    \ start -> target\n    // If no path -> returns -1\n    int bfs(int start, int\
    \ target) {\n        auto dist = _bfs(start, target);\n        return dist[target];\n\
    \    }\n\n    // return: dist: vector<int>, dist[u] = shortest distance from start\
    \ -> u\n    vector<int> bfs(int start) {\n        return _bfs(start, -1);\n  \
    \  }\n\n// private:\n\n    // Start BFS from start, and stop when reaching target.\n\
    \    // Returns distance\n    vector<int> _bfs(int start, int target) {\n    \
    \    queue<int> qu;\n        vector<int> dist(g.size(), -1);\n\n        dist[start]\
    \ = 0;\n        qu.push(start);\n\n        while (!qu.empty()) {\n           \
    \ auto u = qu.front(); qu.pop();\n            if (u == target) {\n           \
    \     break;\n            }\n\n            for (const auto& v : g[u]) {\n    \
    \            if (dist[v] == -1) {\n                    dist[v] = dist[u] + 1;\n\
    \                    qu.push(v);\n                }\n            }\n        }\n\
    \n        return dist;\n    }\n    vector<vector<int>> g;\n};\n"
  code: "// BFS\n// Index from 0\n// Directed\n//\n// Tested:\n// - https://oj.vnoi.info/problem/vmunch\n\
    // - https://oj.vnoi.info/problem/vcoldwat\nstruct Graph {\n    Graph(int n) :\
    \ g(n) {}\n\n    void add_edge(int u, int v) {\n        g[u].push_back(v);\n \
    \   }\n\n    // return shortest distance from start -> target\n    // If no path\
    \ -> returns -1\n    int bfs(int start, int target) {\n        auto dist = _bfs(start,\
    \ target);\n        return dist[target];\n    }\n\n    // return: dist: vector<int>,\
    \ dist[u] = shortest distance from start -> u\n    vector<int> bfs(int start)\
    \ {\n        return _bfs(start, -1);\n    }\n\n// private:\n\n    // Start BFS\
    \ from start, and stop when reaching target.\n    // Returns distance\n    vector<int>\
    \ _bfs(int start, int target) {\n        queue<int> qu;\n        vector<int> dist(g.size(),\
    \ -1);\n\n        dist[start] = 0;\n        qu.push(start);\n\n        while (!qu.empty())\
    \ {\n            auto u = qu.front(); qu.pop();\n            if (u == target)\
    \ {\n                break;\n            }\n\n            for (const auto& v :\
    \ g[u]) {\n                if (dist[v] == -1) {\n                    dist[v] =\
    \ dist[u] + 1;\n                    qu.push(v);\n                }\n         \
    \   }\n        }\n\n        return dist;\n    }\n    vector<vector<int>> g;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bfs.h
  requiredBy: []
  timestamp: '2022-01-05 21:06:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bfs.h
layout: document
redirect_from:
- /library/Graph/bfs.h
- /library/Graph/bfs.h.html
title: Graph/bfs.h
---
