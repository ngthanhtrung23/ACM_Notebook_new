---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Graph/Misc/EulerPath.h
    title: Graph/Misc/EulerPath.h
  - icon: ':warning:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.h\"\n#include <bits/stdc++.h>\n\n#define FOR(i,a,b)\
    \ for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b);\
    \ i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a)\
    \ for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x)\
    \ { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a\
    \ << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n)\
    \ { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define\
    \ sqr(x) ((x) * (x))\nusing namespace std;\n\nint main() {\n    return 0;\n}\n\
    \n#line 1 \"Graph/Misc/EulerPath.h\"\n// NOTES:\n// - When choosing starting vertex\
    \ (for calling find_path), make sure deg[start] > 0.\n// - If find Euler path,\
    \ starting vertex must have odd degree.\n// - Check no solution: SZ(path) == nEdge\
    \ + 1.\n//\n// Tested:\n// - https://open.kattis.com/problems/eulerianpath (directed)\n\
    // - SGU 101 (undirected).\n//\n// If directed:\n// - Edge --> int\n// - add_edge(int\
    \ a, int b) { adj[a].push_back(b); }\n// - Check for no solution:\n// - - for\
    \ all u, |in_deg[u] - out_deg[u]| <= 1\n// - - At most 1 vertex with in_deg[u]\
    \ - out_deg[u] = 1\n// - - At most 1 vertex with out_deg[u] - in_deg[u] = 1 (start\
    \ vertex)\n// - - BFS from start vertex, all vertices u with out_deg[u] > 0 must\
    \ be visited\nstruct Edge {\n    int to;\n    list<Edge>::iterator rev;\n\n  \
    \  Edge(int to) :to(to) {}\n};\n\nconst int MN = 100111;\nlist<Edge> adj[MN];\n\
    vector<int> path; // our result\n\nvoid find_path(int v) {\n    while(adj[v].size()\
    \ > 0) {\n        int vn = adj[v].front().to;\n        adj[vn].erase(adj[v].front().rev);\n\
    \        adj[v].pop_front();\n        find_path(vn);\n    }\n    path.push_back(v);\n\
    }\n\nvoid add_edge(int a, int b) {\n    adj[a].push_front(Edge(b));\n    auto\
    \ ita = adj[a].begin();\n    adj[b].push_front(Edge(a));\n    auto itb = adj[b].begin();\n\
    \    ita->rev = itb;\n    itb->rev = ita;\n}\n\n#line 3 \"Graph/Misc/EulerPath.cpp\"\
    \n\nint main() {\n    add_edge(1, 2);\n    add_edge(2, 3);\n    add_edge(3, 4);\n\
    \    add_edge(4, 1);\n    add_edge(1, 3);\n\n    find_path(1);\n    PR0(path,\
    \ path.size());\n}\n"
  code: "#include \"template.h\"\n#include \"Graph/Misc/EulerPath.h\"\n\nint main()\
    \ {\n    add_edge(1, 2);\n    add_edge(2, 3);\n    add_edge(3, 4);\n    add_edge(4,\
    \ 1);\n    add_edge(1, 3);\n\n    find_path(1);\n    PR0(path, path.size());\n\
    }\n"
  dependsOn:
  - template.h
  - Graph/Misc/EulerPath.h
  isVerificationFile: false
  path: Graph/Misc/EulerPath.cpp
  requiredBy: []
  timestamp: '2018-04-29 22:35:03+02:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Misc/EulerPath.cpp
layout: document
redirect_from:
- /library/Graph/Misc/EulerPath.cpp
- /library/Graph/Misc/EulerPath.cpp.html
title: Graph/Misc/EulerPath.cpp
---
