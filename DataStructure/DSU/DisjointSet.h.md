---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/mst.h
    title: Graph/mst.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_1_a_dsu.test.cpp
    title: DataStructure/test/aizu_dsl_1_a_dsu.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/dsu.test.cpp
    title: DataStructure/test/dsu.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/tests/aizu_grl_2_a_mst.test.cpp
    title: Graph/tests/aizu_grl_2_a_mst.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/DSU/DisjointSet.h\"\n// DisjointSet {{{\n\
    struct DSU {\n    vector<int> lab;\n\n    DSU(int n) : lab(n+1, -1) {}\n\n   \
    \ int getRoot(int u) {\n        if (lab[u] < 0) return u;\n        return lab[u]\
    \ = getRoot(lab[u]);\n    }\n\n    bool merge(int u, int v) {\n        u = getRoot(u);\
    \ v = getRoot(v);\n        if (u == v) return false;\n        if (lab[u] > lab[v])\
    \ swap(u, v);\n        lab[u] += lab[v];\n        lab[v] = u;\n        return\
    \ true;\n    }\n\n    bool same_component(int u, int v) {\n        return getRoot(u)\
    \ == getRoot(v);\n    }\n\n    int component_size(int u) {\n        return -lab[getRoot(u)];\n\
    \    }\n};\n// }}}\n"
  code: "// DisjointSet {{{\nstruct DSU {\n    vector<int> lab;\n\n    DSU(int n)\
    \ : lab(n+1, -1) {}\n\n    int getRoot(int u) {\n        if (lab[u] < 0) return\
    \ u;\n        return lab[u] = getRoot(lab[u]);\n    }\n\n    bool merge(int u,\
    \ int v) {\n        u = getRoot(u); v = getRoot(v);\n        if (u == v) return\
    \ false;\n        if (lab[u] > lab[v]) swap(u, v);\n        lab[u] += lab[v];\n\
    \        lab[v] = u;\n        return true;\n    }\n\n    bool same_component(int\
    \ u, int v) {\n        return getRoot(u) == getRoot(v);\n    }\n\n    int component_size(int\
    \ u) {\n        return -lab[getRoot(u)];\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DSU/DisjointSet.h
  requiredBy:
  - Graph/mst.h
  timestamp: '2023-01-07 01:46:12+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/dsu.test.cpp
  - DataStructure/test/aizu_dsl_1_a_dsu.test.cpp
  - Graph/tests/aizu_grl_2_a_mst.test.cpp
documentation_of: DataStructure/DSU/DisjointSet.h
layout: document
redirect_from:
- /library/DataStructure/DSU/DisjointSet.h
- /library/DataStructure/DSU/DisjointSet.h.html
title: DataStructure/DSU/DisjointSet.h
---
