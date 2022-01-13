---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/DisjointSet.h
    title: DataStructure/DisjointSet.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Graph/tests/aizu_grl_2_a_mst.test.cpp
    title: Graph/tests/aizu_grl_2_a_mst.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/mst.h\"\n// MST. 0-based index\n//\n// Returns:\n\
    // {mst cost, edges in mst}\n//\n// If graph is not connected, returns forest\
    \ (number of edges will be < n-1)\n\n#line 2 \"DataStructure/DisjointSet.h\"\n\
    struct DSU {\n    vector<int> lab;\n\n    DSU(int n) : lab(n+1, -1) {}\n\n   \
    \ int getRoot(int u) {\n        if (lab[u] < 0) return u;\n        return lab[u]\
    \ = getRoot(lab[u]);\n    }\n\n    bool merge(int u, int v) {\n        u = getRoot(u);\
    \ v = getRoot(v);\n        if (u == v) return false;\n        if (lab[u] > lab[v])\
    \ swap(u, v);\n        lab[u] += lab[v];\n        lab[v] = u;\n        return\
    \ true;\n    }\n\n    bool same_component(int u, int v) {\n        return getRoot(u)\
    \ == getRoot(v);\n    }\n\n    int component_size(int u) {\n        return -lab[getRoot(u)];\n\
    \    }\n};\n#line 9 \"Graph/mst.h\"\nusing ll = long long;\nstruct Edge {\n  \
    \  int u, v;\n    ll c;\n};\nbool operator < (const Edge& a, const Edge& b) {\n\
    \    return a.c < b.c;\n}\nstd::pair<ll, std::vector<Edge>> mst(\n        int\
    \ n,\n        std::vector<Edge> edges) {\n    std::sort(edges.begin(), edges.end());\n\
    \n    DSU dsu(n);\n    ll total = 0;\n    vector<Edge> tree;\n    for (const auto&\
    \ e : edges) {\n        const auto [u, v, c] = e;\n        if (dsu.merge(u, v))\
    \ {\n            total += c;\n            tree.push_back(e);\n        }\n    }\n\
    \    return {total, tree};\n}\n"
  code: "// MST. 0-based index\n//\n// Returns:\n// {mst cost, edges in mst}\n//\n\
    // If graph is not connected, returns forest (number of edges will be < n-1)\n\
    \n#include \"../DataStructure/DisjointSet.h\"\nusing ll = long long;\nstruct Edge\
    \ {\n    int u, v;\n    ll c;\n};\nbool operator < (const Edge& a, const Edge&\
    \ b) {\n    return a.c < b.c;\n}\nstd::pair<ll, std::vector<Edge>> mst(\n    \
    \    int n,\n        std::vector<Edge> edges) {\n    std::sort(edges.begin(),\
    \ edges.end());\n\n    DSU dsu(n);\n    ll total = 0;\n    vector<Edge> tree;\n\
    \    for (const auto& e : edges) {\n        const auto [u, v, c] = e;\n      \
    \  if (dsu.merge(u, v)) {\n            total += c;\n            tree.push_back(e);\n\
    \        }\n    }\n    return {total, tree};\n}\n"
  dependsOn:
  - DataStructure/DisjointSet.h
  isVerificationFile: false
  path: Graph/mst.h
  requiredBy: []
  timestamp: '2022-01-11 13:11:25+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Graph/tests/aizu_grl_2_a_mst.test.cpp
documentation_of: Graph/mst.h
layout: document
redirect_from:
- /library/Graph/mst.h
- /library/Graph/mst.h.html
title: Graph/mst.h
---
