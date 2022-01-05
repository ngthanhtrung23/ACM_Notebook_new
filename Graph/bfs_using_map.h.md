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
    - https://oj.vnoi.info/problem/vmunch
  bundledCode: "#line 1 \"Graph/bfs_using_map.h\"\n// BFS using map, so extra log\
    \ factor\n//\n// Tested:\n// - https://oj.vnoi.info/problem/vmunch\ntemplate<typename\
    \ T>\nstruct Graph {\n    void add_edge(const T& u, const T& v) {\n        g[u].push_back(v);\n\
    \    }\n\n    // return shortest distance from start -> target\n    // If no path\
    \ -> returns -1\n    int bfs(const T& start, const T& target) {\n        queue<T>\
    \ qu;\n        map<T, int> dist;\n\n        dist[start] = 0;\n        qu.push(start);\n\
    \n        while (!qu.empty()) {\n            auto u = qu.front(); qu.pop();\n\
    \            if (u == target) {\n                return dist[u];\n           \
    \ }\n\n            for (const auto& v : g[u]) {\n                if (!dist.count(v))\
    \ {\n                    dist[v] = dist[u] + 1;\n                    qu.push(v);\n\
    \                }\n            }\n        }\n\n        return -1;\n    }\n\n\
    // private:\n    map<T, vector<T>> g;\n};\n"
  code: "// BFS using map, so extra log factor\n//\n// Tested:\n// - https://oj.vnoi.info/problem/vmunch\n\
    template<typename T>\nstruct Graph {\n    void add_edge(const T& u, const T& v)\
    \ {\n        g[u].push_back(v);\n    }\n\n    // return shortest distance from\
    \ start -> target\n    // If no path -> returns -1\n    int bfs(const T& start,\
    \ const T& target) {\n        queue<T> qu;\n        map<T, int> dist;\n\n    \
    \    dist[start] = 0;\n        qu.push(start);\n\n        while (!qu.empty())\
    \ {\n            auto u = qu.front(); qu.pop();\n            if (u == target)\
    \ {\n                return dist[u];\n            }\n\n            for (const\
    \ auto& v : g[u]) {\n                if (!dist.count(v)) {\n                 \
    \   dist[v] = dist[u] + 1;\n                    qu.push(v);\n                }\n\
    \            }\n        }\n\n        return -1;\n    }\n\n// private:\n    map<T,\
    \ vector<T>> g;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bfs_using_map.h
  requiredBy: []
  timestamp: '2022-01-05 21:06:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bfs_using_map.h
layout: document
redirect_from:
- /library/Graph/bfs_using_map.h
- /library/Graph/bfs_using_map.h.html
title: Graph/bfs_using_map.h
---
