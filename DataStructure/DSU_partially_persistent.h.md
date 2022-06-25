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
    - https://oj.vnoi.info/problem/vnoicup22_r2_c
  bundledCode: "#line 1 \"DataStructure/DSU_partially_persistent.h\"\n// Partially\
    \ persistent DSU\n//\n// Supports:\n// - Linear history (version t+1 always build\
    \ on top of version t)\n// - Query history information at version t\n//\n// Tested:\n\
    // - https://oj.vnoi.info/problem/vnoicup22_r2_c\nstruct PartiallyPersistentDSU\
    \ {\n    vector<int> lab, t_unite;\n\n    PartiallyPersistentDSU(int n)\n    \
    \        : lab(n + 1, -1), t_unite(n + 1, INT_MAX) {}\n\n    // return root\n\
    \    int getRoot(int t, int x) {\n        if (t_unite[x] > t) {\n            return\
    \ x;\n        }\n        return getRoot(t, lab[x]);\n    }\n\n    void merge(int\
    \ t, int x, int y) {\n        int root_x = getRoot(t, x);\n        int root_y\
    \ = getRoot(t, y);\n        x = root_x; y = root_y;\n        if (x == y) {\n \
    \           return;\n        }\n        if (lab[x] > lab[y]) {\n            std::swap(x,\
    \ y);\n        }\n        lab[x] += lab[y];\n        lab[y] = x;\n        t_unite[y]\
    \ = t;\n    }\n};\n"
  code: "// Partially persistent DSU\n//\n// Supports:\n// - Linear history (version\
    \ t+1 always build on top of version t)\n// - Query history information at version\
    \ t\n//\n// Tested:\n// - https://oj.vnoi.info/problem/vnoicup22_r2_c\nstruct\
    \ PartiallyPersistentDSU {\n    vector<int> lab, t_unite;\n\n    PartiallyPersistentDSU(int\
    \ n)\n            : lab(n + 1, -1), t_unite(n + 1, INT_MAX) {}\n\n    // return\
    \ root\n    int getRoot(int t, int x) {\n        if (t_unite[x] > t) {\n     \
    \       return x;\n        }\n        return getRoot(t, lab[x]);\n    }\n\n  \
    \  void merge(int t, int x, int y) {\n        int root_x = getRoot(t, x);\n  \
    \      int root_y = getRoot(t, y);\n        x = root_x; y = root_y;\n        if\
    \ (x == y) {\n            return;\n        }\n        if (lab[x] > lab[y]) {\n\
    \            std::swap(x, y);\n        }\n        lab[x] += lab[y];\n        lab[y]\
    \ = x;\n        t_unite[y] = t;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DSU_partially_persistent.h
  requiredBy: []
  timestamp: '2022-06-25 23:45:44+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/DSU_partially_persistent.h
layout: document
redirect_from:
- /library/DataStructure/DSU_partially_persistent.h
- /library/DataStructure/DSU_partially_persistent.h.html
title: DataStructure/DSU_partially_persistent.h
---
