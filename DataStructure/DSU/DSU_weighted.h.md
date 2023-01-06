---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp
    title: DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/DSU/DSU_weighted.h\"\ntemplate<class S>\n\
    struct WeightedDSU {\n    std::vector<int> lab;\n    std::vector<S> w;  // relative\
    \ to parent\n\n    WeightedDSU(int n) : lab(n, -1), w(n) {}\n\n    int getRoot(int\
    \ u) {\n        if (lab[u] < 0) return u;\n        return getRoot(lab[u]);\n \
    \   }\n\n    int weight(int u) {\n        if (lab[u] < 0) return w[u];\n     \
    \   return w[u] + weight(lab[u]);\n    }\n\n    // weight(t) = weight(s) + diff\n\
    \    // returns false if contradicts\n    bool merge(int s, int t, S diff) {\n\
    \        // jump to root\n        diff = diff + weight(s) - weight(t);\n     \
    \   s = getRoot(s);\n        t = getRoot(t);\n        if (s == t) return diff\
    \ == 0;\n        if (lab[s] > lab[t]) {\n            std::swap(s, t);\n      \
    \      diff = -diff;\n        }\n        lab[s] += lab[t];\n        lab[t] = s;\n\
    \        w[t] = diff;\n        return true;\n    }\n};\n"
  code: "template<class S>\nstruct WeightedDSU {\n    std::vector<int> lab;\n    std::vector<S>\
    \ w;  // relative to parent\n\n    WeightedDSU(int n) : lab(n, -1), w(n) {}\n\n\
    \    int getRoot(int u) {\n        if (lab[u] < 0) return u;\n        return getRoot(lab[u]);\n\
    \    }\n\n    int weight(int u) {\n        if (lab[u] < 0) return w[u];\n    \
    \    return w[u] + weight(lab[u]);\n    }\n\n    // weight(t) = weight(s) + diff\n\
    \    // returns false if contradicts\n    bool merge(int s, int t, S diff) {\n\
    \        // jump to root\n        diff = diff + weight(s) - weight(t);\n     \
    \   s = getRoot(s);\n        t = getRoot(t);\n        if (s == t) return diff\
    \ == 0;\n        if (lab[s] > lab[t]) {\n            std::swap(s, t);\n      \
    \      diff = -diff;\n        }\n        lab[s] += lab[t];\n        lab[t] = s;\n\
    \        w[t] = diff;\n        return true;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DSU/DSU_weighted.h
  requiredBy: []
  timestamp: '2023-01-07 01:46:12+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp
documentation_of: DataStructure/DSU/DSU_weighted.h
layout: document
redirect_from:
- /library/DataStructure/DSU/DSU_weighted.h
- /library/DataStructure/DSU/DSU_weighted.h.html
title: DataStructure/DSU/DSU_weighted.h
---
