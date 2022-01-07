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
    - https://cses.fi/problemset/task/1193/
    - https://oj.vnoi.info/problem/vmunch
  bundledCode: "#line 1 \"Graph/bfs_using_map.h\"\n// BFS using map, so extra log\
    \ factor\n//\n// Note:\n// - Can use unordered_map for small speed improvement\n\
    //   (see unordered_map_pair.h for how to implement hash for other types)\n//\n\
    // Tested:\n// - https://oj.vnoi.info/problem/vmunch\n// - https://cses.fi/problemset/task/1193/\n\
    template<typename T>\nstruct Graph {\n    void add_edge(const T& u, const T& v)\
    \ {\n        g[u].push_back(v);\n    }\n\n    // return\n    // - shortest distance\
    \ from start -> target\n    // - path\n    // If no path -> returns {-1, {}}\n\
    \    std::pair<int, std::vector<T>> bfs(const T& start, const T& target) {\n \
    \       queue<T> qu;\n        std::map<T, int> dist;\n        std::map<T, T> trace;\n\
    \n        dist[start] = 0;\n        qu.push(start);\n\n        while (!qu.empty())\
    \ {\n            auto u = qu.front(); qu.pop();\n            if (u == target)\
    \ {\n                std::vector<T> path;\n                for (auto cur = target;\
    \ cur != start; cur = trace[cur]) {\n                    path.push_back(cur);\n\
    \                }\n                path.push_back(start);\n                reverse(path.begin(),\
    \ path.end());\n                return {dist[u], path};\n            }\n\n   \
    \         for (const auto& v : g[u]) {\n                if (!dist.count(v)) {\n\
    \                    dist[v] = dist[u] + 1;\n                    trace[v] = u;\n\
    \                    qu.push(v);\n                }\n            }\n        }\n\
    \n        return {-1, {}};\n    }\n\n// private:\n    map<T, vector<T>> g;\n};\n"
  code: "// BFS using map, so extra log factor\n//\n// Note:\n// - Can use unordered_map\
    \ for small speed improvement\n//   (see unordered_map_pair.h for how to implement\
    \ hash for other types)\n//\n// Tested:\n// - https://oj.vnoi.info/problem/vmunch\n\
    // - https://cses.fi/problemset/task/1193/\ntemplate<typename T>\nstruct Graph\
    \ {\n    void add_edge(const T& u, const T& v) {\n        g[u].push_back(v);\n\
    \    }\n\n    // return\n    // - shortest distance from start -> target\n   \
    \ // - path\n    // If no path -> returns {-1, {}}\n    std::pair<int, std::vector<T>>\
    \ bfs(const T& start, const T& target) {\n        queue<T> qu;\n        std::map<T,\
    \ int> dist;\n        std::map<T, T> trace;\n\n        dist[start] = 0;\n    \
    \    qu.push(start);\n\n        while (!qu.empty()) {\n            auto u = qu.front();\
    \ qu.pop();\n            if (u == target) {\n                std::vector<T> path;\n\
    \                for (auto cur = target; cur != start; cur = trace[cur]) {\n \
    \                   path.push_back(cur);\n                }\n                path.push_back(start);\n\
    \                reverse(path.begin(), path.end());\n                return {dist[u],\
    \ path};\n            }\n\n            for (const auto& v : g[u]) {\n        \
    \        if (!dist.count(v)) {\n                    dist[v] = dist[u] + 1;\n \
    \                   trace[v] = u;\n                    qu.push(v);\n         \
    \       }\n            }\n        }\n\n        return {-1, {}};\n    }\n\n// private:\n\
    \    map<T, vector<T>> g;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/bfs_using_map.h
  requiredBy: []
  timestamp: '2022-01-07 13:20:04+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bfs_using_map.h
layout: document
redirect_from:
- /library/Graph/bfs_using_map.h
- /library/Graph/bfs_using_map.h.html
title: Graph/bfs_using_map.h
---
