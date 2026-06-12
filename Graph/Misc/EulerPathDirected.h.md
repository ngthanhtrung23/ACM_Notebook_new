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
    - https://oj.vnoi.info/problem/vnoicup22_final_c
    - https://open.kattis.com/problems/eulerianpath
  bundledCode: "#line 1 \"Graph/Misc/EulerPathDirected.h\"\n// Tested:\n// - https://open.kattis.com/problems/eulerianpath\n\
    // - https://oj.vnoi.info/problem/vnoicup22_final_c\nstruct EulerDirected {\n\
    \    EulerDirected(int _n) : n(_n), adj(n), in_deg(n, 0), out_deg(n, 0) {}\n\n\
    \    void add_edge(int u, int v) {  // directed edge\n        assert(0 <= u &&\
    \ u < n);\n        assert(0 <= v && v < n);\n        adj[u].push_front(v);\n \
    \       in_deg[v]++;\n        out_deg[u]++;\n    }\n\n    std::pair<bool, std::vector<int>>\
    \ solve() {\n        int start = -1, last = -1;\n        for (int i = 0; i < n;\
    \ i++) {\n            // for all u, |in_deg(u) - out_deg(u)| <= 1\n          \
    \  if (std::abs(in_deg[i] - out_deg[i]) > 1) return {false, {}};\n\n         \
    \   if (out_deg[i] > in_deg[i]) {\n                // At most 1 vertex with out_deg[u]\
    \ - in_deg[u] = 1 (start vertex)\n                if (start >= 0) return {false,\
    \ {}};\n                start = i;\n            }\n\n            if (in_deg[i]\
    \ > out_deg[i]) {\n                // At most 1 vertex with in_deg[u] - out_deg[u]\
    \ = 1 (last vertex)\n                if (last >= 0) return {false, {}};\n    \
    \            last = i;\n            }\n        }\n\n        // can start at any\
    \ vertex with degree > 0\n        if (start < 0) {\n            for (int i = 0;\
    \ i < n; i++) {\n                if (in_deg[i]) {\n                    start =\
    \ i;\n                    break;\n                }\n            }\n         \
    \   // no start vertex --> all vertices have degree == 0\n            if (start\
    \ < 0) return {true, {}};\n        }\n\n        std::vector<int> path;\n     \
    \   find_path(start, path);\n        std::reverse(path.begin(), path.end());\n\
    \n        // check that we visited all vertices with degree > 0\n        std::vector<bool>\
    \ visited(n, false);\n        for (int u : path) visited[u] = true;\n\n      \
    \  for (int u = 0; u < n; u++) {\n            if (in_deg[u] && !visited[u]) {\n\
    \                return {false, {}};\n            }\n        }\n\n        return\
    \ {true, path};\n    }\n\nprivate:\n    int n;\n    std::vector<std::list<int>>\
    \ adj;\n    std::vector<int> in_deg, out_deg;\n\n    void find_path(int v, std::vector<int>&\
    \ path) {\n        while (adj[v].size() > 0) {\n            int next = adj[v].front();\n\
    \            adj[v].pop_front();\n            find_path(next, path);\n       \
    \ }\n        path.push_back(v);\n    }\n};\n"
  code: "// Tested:\n// - https://open.kattis.com/problems/eulerianpath\n// - https://oj.vnoi.info/problem/vnoicup22_final_c\n\
    struct EulerDirected {\n    EulerDirected(int _n) : n(_n), adj(n), in_deg(n, 0),\
    \ out_deg(n, 0) {}\n\n    void add_edge(int u, int v) {  // directed edge\n  \
    \      assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        adj[u].push_front(v);\n\
    \        in_deg[v]++;\n        out_deg[u]++;\n    }\n\n    std::pair<bool, std::vector<int>>\
    \ solve() {\n        int start = -1, last = -1;\n        for (int i = 0; i < n;\
    \ i++) {\n            // for all u, |in_deg(u) - out_deg(u)| <= 1\n          \
    \  if (std::abs(in_deg[i] - out_deg[i]) > 1) return {false, {}};\n\n         \
    \   if (out_deg[i] > in_deg[i]) {\n                // At most 1 vertex with out_deg[u]\
    \ - in_deg[u] = 1 (start vertex)\n                if (start >= 0) return {false,\
    \ {}};\n                start = i;\n            }\n\n            if (in_deg[i]\
    \ > out_deg[i]) {\n                // At most 1 vertex with in_deg[u] - out_deg[u]\
    \ = 1 (last vertex)\n                if (last >= 0) return {false, {}};\n    \
    \            last = i;\n            }\n        }\n\n        // can start at any\
    \ vertex with degree > 0\n        if (start < 0) {\n            for (int i = 0;\
    \ i < n; i++) {\n                if (in_deg[i]) {\n                    start =\
    \ i;\n                    break;\n                }\n            }\n         \
    \   // no start vertex --> all vertices have degree == 0\n            if (start\
    \ < 0) return {true, {}};\n        }\n\n        std::vector<int> path;\n     \
    \   find_path(start, path);\n        std::reverse(path.begin(), path.end());\n\
    \n        // check that we visited all vertices with degree > 0\n        std::vector<bool>\
    \ visited(n, false);\n        for (int u : path) visited[u] = true;\n\n      \
    \  for (int u = 0; u < n; u++) {\n            if (in_deg[u] && !visited[u]) {\n\
    \                return {false, {}};\n            }\n        }\n\n        return\
    \ {true, path};\n    }\n\nprivate:\n    int n;\n    std::vector<std::list<int>>\
    \ adj;\n    std::vector<int> in_deg, out_deg;\n\n    void find_path(int v, std::vector<int>&\
    \ path) {\n        while (adj[v].size() > 0) {\n            int next = adj[v].front();\n\
    \            adj[v].pop_front();\n            find_path(next, path);\n       \
    \ }\n        path.push_back(v);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Misc/EulerPathDirected.h
  requiredBy: []
  timestamp: '2022-07-23 01:36:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Misc/EulerPathDirected.h
layout: document
redirect_from:
- /library/Graph/Misc/EulerPathDirected.h
- /library/Graph/Misc/EulerPathDirected.h.html
title: Graph/Misc/EulerPathDirected.h
---
