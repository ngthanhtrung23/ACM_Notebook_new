---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/persistent_dsu.test.cpp
    title: DataStructure/test/persistent_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
    - https://oj.vnoi.info/problem/hello22_schoolplan)
  bundledCode: "#line 1 \"DataStructure/PersistentDSU.h\"\n// PersistentDSU\n//\n\
    // Notes:\n// - this doesn't support delete edge operation, so isn't enough to\n\
    //   solve dynamic connectivity problem.\n// - it has high mem and time usage,\
    \ so be careful (both TLE and MLE on\n//   https://oj.vnoi.info/problem/hello22_schoolplan)\n\
    //\n// Tested:\n// - https://judge.yosupo.jp/problem/persistent_unionfind\nstruct\
    \ PersistentDSU {\n    int n;\n    using Arr = PersistentArray<int>;\n\n    PersistentDSU(int\
    \ _n) : n(_n) {\n        roots.emplace_back(A.build(std::vector<int> (n, -1)));\n\
    \    }\n\n    int find(int version, int u) {\n        // Note that we can't do\
    \ path compression here\n        int p = A.get(roots[version], u);\n        return\
    \ p < 0 ? u : find(version, p);\n    }\n\n    // Note that this will always create\
    \ a new version,\n    // regardless of whether u and v was previously in same\
    \ component.\n    bool merge(int version, int u, int v) {\n        u = find(version,\
    \ u);\n        v = find(version, v);\n        auto ptr = roots[version];\n   \
    \     if (u != v) {\n            int sz_u = -A.get(ptr, u), sz_v = -A.get(ptr,\
    \ v);\n            if (sz_u < sz_v) swap(u, v);\n            // sz[u] >= sz[v]\n\
    \            ptr = A.set(ptr, u, -sz_u - sz_v);\n            ptr = A.set(ptr,\
    \ v, u);\n        }\n\n        roots.emplace_back(ptr);\n        return u != v;\n\
    \    }\n\n    int component_size(int version, int u) {\n        return -A.get(roots[version],\
    \ find(version, u));\n    }\n\n    bool same_component(int version, int u, int\
    \ v) {\n        return find(version, u) == find(version, v);\n    }\n\n    Arr\
    \ A;\n    vector<Arr::Node*> roots;\n};\n\n"
  code: "// PersistentDSU\n//\n// Notes:\n// - this doesn't support delete edge operation,\
    \ so isn't enough to\n//   solve dynamic connectivity problem.\n// - it has high\
    \ mem and time usage, so be careful (both TLE and MLE on\n//   https://oj.vnoi.info/problem/hello22_schoolplan)\n\
    //\n// Tested:\n// - https://judge.yosupo.jp/problem/persistent_unionfind\nstruct\
    \ PersistentDSU {\n    int n;\n    using Arr = PersistentArray<int>;\n\n    PersistentDSU(int\
    \ _n) : n(_n) {\n        roots.emplace_back(A.build(std::vector<int> (n, -1)));\n\
    \    }\n\n    int find(int version, int u) {\n        // Note that we can't do\
    \ path compression here\n        int p = A.get(roots[version], u);\n        return\
    \ p < 0 ? u : find(version, p);\n    }\n\n    // Note that this will always create\
    \ a new version,\n    // regardless of whether u and v was previously in same\
    \ component.\n    bool merge(int version, int u, int v) {\n        u = find(version,\
    \ u);\n        v = find(version, v);\n        auto ptr = roots[version];\n   \
    \     if (u != v) {\n            int sz_u = -A.get(ptr, u), sz_v = -A.get(ptr,\
    \ v);\n            if (sz_u < sz_v) swap(u, v);\n            // sz[u] >= sz[v]\n\
    \            ptr = A.set(ptr, u, -sz_u - sz_v);\n            ptr = A.set(ptr,\
    \ v, u);\n        }\n\n        roots.emplace_back(ptr);\n        return u != v;\n\
    \    }\n\n    int component_size(int version, int u) {\n        return -A.get(roots[version],\
    \ find(version, u));\n    }\n\n    bool same_component(int version, int u, int\
    \ v) {\n        return find(version, u) == find(version, v);\n    }\n\n    Arr\
    \ A;\n    vector<Arr::Node*> roots;\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentDSU.h
  requiredBy: []
  timestamp: '2022-01-02 20:29:22+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/persistent_dsu.test.cpp
documentation_of: DataStructure/PersistentDSU.h
layout: document
redirect_from:
- /library/DataStructure/PersistentDSU.h
- /library/DataStructure/PersistentDSU.h.html
title: DataStructure/PersistentDSU.h
---
