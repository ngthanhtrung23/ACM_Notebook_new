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
    links:
    - https://open.kattis.com/problems/eulerianpath
  bundledCode: "#line 1 \"Graph/Misc/EulerPath.h\"\n// NOTES:\n// - When choosing\
    \ starting vertex (for calling find_path), make sure deg[start] > 0.\n// - If\
    \ find Euler path, starting vertex must have odd degree.\n// - Check no solution:\
    \ SZ(path) == nEdge + 1.\n//\n// Tested:\n// - https://open.kattis.com/problems/eulerianpath\
    \ (directed)\n// - SGU 101 (undirected).\n//\n// If directed:\n// - Edge --> int\n\
    // - add_edge(int a, int b) { adj[a].push_back(b); }\n// - Check for no solution:\n\
    // - - for all u, |in_deg[u] - out_deg[u]| <= 1\n// - - At most 1 vertex with\
    \ in_deg[u] - out_deg[u] = 1\n// - - At most 1 vertex with out_deg[u] - in_deg[u]\
    \ = 1 (start vertex)\n// - - BFS from start vertex, all vertices u with out_deg[u]\
    \ > 0 must be visited\nstruct Edge {\n    int to;\n    list<Edge>::iterator rev;\n\
    \n    Edge(int to) :to(to) {}\n};\n\nconst int MN = 100111;\nlist<Edge> adj[MN];\n\
    vector<int> path; // our result\n\nvoid find_path(int v) {\n    while(adj[v].size()\
    \ > 0) {\n        int vn = adj[v].front().to;\n        adj[vn].erase(adj[v].front().rev);\n\
    \        adj[v].pop_front();\n        find_path(vn);\n    }\n    path.push_back(v);\n\
    }\n\nvoid add_edge(int a, int b) {\n    adj[a].push_front(Edge(b));\n    auto\
    \ ita = adj[a].begin();\n    adj[b].push_front(Edge(a));\n    auto itb = adj[b].begin();\n\
    \    ita->rev = itb;\n    itb->rev = ita;\n}\n\n"
  code: "// NOTES:\n// - When choosing starting vertex (for calling find_path), make\
    \ sure deg[start] > 0.\n// - If find Euler path, starting vertex must have odd\
    \ degree.\n// - Check no solution: SZ(path) == nEdge + 1.\n//\n// Tested:\n//\
    \ - https://open.kattis.com/problems/eulerianpath (directed)\n// - SGU 101 (undirected).\n\
    //\n// If directed:\n// - Edge --> int\n// - add_edge(int a, int b) { adj[a].push_back(b);\
    \ }\n// - Check for no solution:\n// - - for all u, |in_deg[u] - out_deg[u]| <=\
    \ 1\n// - - At most 1 vertex with in_deg[u] - out_deg[u] = 1\n// - - At most 1\
    \ vertex with out_deg[u] - in_deg[u] = 1 (start vertex)\n// - - BFS from start\
    \ vertex, all vertices u with out_deg[u] > 0 must be visited\nstruct Edge {\n\
    \    int to;\n    list<Edge>::iterator rev;\n\n    Edge(int to) :to(to) {}\n};\n\
    \nconst int MN = 100111;\nlist<Edge> adj[MN];\nvector<int> path; // our result\n\
    \nvoid find_path(int v) {\n    while(adj[v].size() > 0) {\n        int vn = adj[v].front().to;\n\
    \        adj[vn].erase(adj[v].front().rev);\n        adj[v].pop_front();\n   \
    \     find_path(vn);\n    }\n    path.push_back(v);\n}\n\nvoid add_edge(int a,\
    \ int b) {\n    adj[a].push_front(Edge(b));\n    auto ita = adj[a].begin();\n\
    \    adj[b].push_front(Edge(a));\n    auto itb = adj[b].begin();\n    ita->rev\
    \ = itb;\n    itb->rev = ita;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Misc/EulerPath.h
  requiredBy:
  - Graph/Misc/EulerPath.cpp
  timestamp: '2018-04-29 22:35:03+02:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Misc/EulerPath.h
layout: document
redirect_from:
- /library/Graph/Misc/EulerPath.h
- /library/Graph/Misc/EulerPath.h.html
title: Graph/Misc/EulerPath.h
---
