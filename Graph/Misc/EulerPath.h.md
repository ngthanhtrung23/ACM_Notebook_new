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
    - https://codeforces.com/problemsets/acmsguru/problem/99999/101
    - https://oj.vnoi.info/problem/tour2509
  bundledCode: "#line 1 \"Graph/Misc/EulerPath.h\"\n// NOTES:\n// - For directed ->\
    \ see EulerPathDirected.h\n//\n// Tested:\n// - SGU 101: https://codeforces.com/problemsets/acmsguru/problem/99999/101\n\
    // - https://oj.vnoi.info/problem/tour2509\nstruct EulerUndirected {\n    EulerUndirected(int\
    \ _n) : n(_n), m(0), adj(_n), deg(_n, 0) {}\n\n    void add_edge(int u, int v)\
    \ {\n        adj[u].push_front(Edge(v));\n        auto it1 = adj[u].begin();\n\
    \        adj[v].push_front(Edge(u));\n        auto it2 = adj[v].begin();\n\n \
    \       it1->rev = it2;\n        it2->rev = it1;\n\n        ++deg[u];\n      \
    \  ++deg[v];\n        ++m;\n    }\n\n    std::pair<bool, std::vector<int>> solve()\
    \ {\n        int cntOdd = 0;\n        int start = -1;\n        for (int i = 0;\
    \ i < n; i++) {\n            if (deg[i] % 2) {\n                ++cntOdd;\n  \
    \              if (cntOdd > 2) return {false, {}};\n\n                if (start\
    \ < 0) start = i;\n            }\n        }\n\n        // no odd vertex -> start\
    \ from any vertex with positive degree\n        if (start < 0) {\n           \
    \ for (int i = 0; i < n; i++) {\n                if (deg[i]) {\n             \
    \       start = i;\n                    break;\n                }\n          \
    \  }\n            if (start < 0) {\n                // no edge -> empty path\n\
    \                return {true, {}};\n            }\n        }\n\n        std::vector<int>\
    \ path;\n        find_path(start, path);\n\n        if (m + 1 != static_cast<int>\
    \ (path.size())) {\n            return {false, {}};\n        }\n\n        return\
    \ {true, path};\n    }\n\n    struct Edge {\n        int to;\n        std::list<Edge>::iterator\
    \ rev;\n\n        Edge(int _to) : to(_to) {}\n    };\n\n//private:\n    int n,\
    \ m;\n    std::vector<std::list<Edge>> adj;\n    std::vector<int> deg;\n\n   \
    \ void find_path(int v, std::vector<int>& path) {\n        while (adj[v].size()\
    \ > 0) {\n            int next = adj[v].front().to;\n            adj[next].erase(adj[v].front().rev);\n\
    \            adj[v].pop_front();\n            find_path(next, path);\n       \
    \ }\n        path.push_back(v);\n    }\n};\n"
  code: "// NOTES:\n// - For directed -> see EulerPathDirected.h\n//\n// Tested:\n\
    // - SGU 101: https://codeforces.com/problemsets/acmsguru/problem/99999/101\n\
    // - https://oj.vnoi.info/problem/tour2509\nstruct EulerUndirected {\n    EulerUndirected(int\
    \ _n) : n(_n), m(0), adj(_n), deg(_n, 0) {}\n\n    void add_edge(int u, int v)\
    \ {\n        adj[u].push_front(Edge(v));\n        auto it1 = adj[u].begin();\n\
    \        adj[v].push_front(Edge(u));\n        auto it2 = adj[v].begin();\n\n \
    \       it1->rev = it2;\n        it2->rev = it1;\n\n        ++deg[u];\n      \
    \  ++deg[v];\n        ++m;\n    }\n\n    std::pair<bool, std::vector<int>> solve()\
    \ {\n        int cntOdd = 0;\n        int start = -1;\n        for (int i = 0;\
    \ i < n; i++) {\n            if (deg[i] % 2) {\n                ++cntOdd;\n  \
    \              if (cntOdd > 2) return {false, {}};\n\n                if (start\
    \ < 0) start = i;\n            }\n        }\n\n        // no odd vertex -> start\
    \ from any vertex with positive degree\n        if (start < 0) {\n           \
    \ for (int i = 0; i < n; i++) {\n                if (deg[i]) {\n             \
    \       start = i;\n                    break;\n                }\n          \
    \  }\n            if (start < 0) {\n                // no edge -> empty path\n\
    \                return {true, {}};\n            }\n        }\n\n        std::vector<int>\
    \ path;\n        find_path(start, path);\n\n        if (m + 1 != static_cast<int>\
    \ (path.size())) {\n            return {false, {}};\n        }\n\n        return\
    \ {true, path};\n    }\n\n    struct Edge {\n        int to;\n        std::list<Edge>::iterator\
    \ rev;\n\n        Edge(int _to) : to(_to) {}\n    };\n\n//private:\n    int n,\
    \ m;\n    std::vector<std::list<Edge>> adj;\n    std::vector<int> deg;\n\n   \
    \ void find_path(int v, std::vector<int>& path) {\n        while (adj[v].size()\
    \ > 0) {\n            int next = adj[v].front().to;\n            adj[next].erase(adj[v].front().rev);\n\
    \            adj[v].pop_front();\n            find_path(next, path);\n       \
    \ }\n        path.push_back(v);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Misc/EulerPath.h
  requiredBy: []
  timestamp: '2022-07-23 02:15:42+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Misc/EulerPath.h
layout: document
redirect_from:
- /library/Graph/Misc/EulerPath.h
- /library/Graph/Misc/EulerPath.h.html
title: Graph/Misc/EulerPath.h
---
