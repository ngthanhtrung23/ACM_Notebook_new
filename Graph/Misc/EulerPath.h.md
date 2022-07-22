---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/Misc/EulerPath.cpp
    title: Graph/Misc/EulerPath.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Misc/EulerPath.h\"\n// NOTES:\n// - When choosing\
    \ starting vertex (for calling find_path), make sure deg[start] > 0.\n// - If\
    \ find Euler path, starting vertex must have odd degree.\n// - Check no solution:\
    \ SZ(path) == nEdge + 1.\n// - For directed -> see EulerPathDirected.h\n//\n//\
    \ Tested:\n// - SGU 101 (undirected).\nstruct Edge {\n    int to;\n    list<Edge>::iterator\
    \ rev;\n\n    Edge(int to) :to(to) {}\n};\n\nconst int MN = 100111;\nlist<Edge>\
    \ adj[MN];\nvector<int> path; // our result\n\nvoid find_path(int v) {\n    while(adj[v].size()\
    \ > 0) {\n        int vn = adj[v].front().to;\n        adj[vn].erase(adj[v].front().rev);\n\
    \        adj[v].pop_front();\n        find_path(vn);\n    }\n    path.push_back(v);\n\
    }\n\nvoid add_edge(int a, int b) {\n    adj[a].push_front(Edge(b));\n    auto\
    \ ita = adj[a].begin();\n    adj[b].push_front(Edge(a));\n    auto itb = adj[b].begin();\n\
    \    ita->rev = itb;\n    itb->rev = ita;\n}\n"
  code: "// NOTES:\n// - When choosing starting vertex (for calling find_path), make\
    \ sure deg[start] > 0.\n// - If find Euler path, starting vertex must have odd\
    \ degree.\n// - Check no solution: SZ(path) == nEdge + 1.\n// - For directed ->\
    \ see EulerPathDirected.h\n//\n// Tested:\n// - SGU 101 (undirected).\nstruct\
    \ Edge {\n    int to;\n    list<Edge>::iterator rev;\n\n    Edge(int to) :to(to)\
    \ {}\n};\n\nconst int MN = 100111;\nlist<Edge> adj[MN];\nvector<int> path; //\
    \ our result\n\nvoid find_path(int v) {\n    while(adj[v].size() > 0) {\n    \
    \    int vn = adj[v].front().to;\n        adj[vn].erase(adj[v].front().rev);\n\
    \        adj[v].pop_front();\n        find_path(vn);\n    }\n    path.push_back(v);\n\
    }\n\nvoid add_edge(int a, int b) {\n    adj[a].push_front(Edge(b));\n    auto\
    \ ita = adj[a].begin();\n    adj[b].push_front(Edge(a));\n    auto itb = adj[b].begin();\n\
    \    ita->rev = itb;\n    itb->rev = ita;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Misc/EulerPath.h
  requiredBy:
  - Graph/Misc/EulerPath.cpp
  timestamp: '2022-07-23 01:36:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Misc/EulerPath.h
layout: document
redirect_from:
- /library/Graph/Misc/EulerPath.h
- /library/Graph/Misc/EulerPath.h.html
title: Graph/Misc/EulerPath.h
---
