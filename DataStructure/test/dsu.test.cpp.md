---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU/DisjointSet.h
    title: DataStructure/DSU/DisjointSet.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"DataStructure/test/dsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/DSU/DisjointSet.h\"\
    \n// DisjointSet {{{\nstruct DSU {\n    vector<int> lab;\n\n    DSU(int n) : lab(n+1,\
    \ -1) {}\n\n    int getRoot(int u) {\n        if (lab[u] < 0) return u;\n    \
    \    return lab[u] = getRoot(lab[u]);\n    }\n\n    bool merge(int u, int v) {\n\
    \        u = getRoot(u); v = getRoot(v);\n        if (u == v) return false;\n\
    \        if (lab[u] > lab[v]) swap(u, v);\n        lab[u] += lab[v];\n       \
    \ lab[v] = u;\n        return true;\n    }\n\n    bool same_component(int u, int\
    \ v) {\n        return getRoot(u) == getRoot(v);\n    }\n\n    int component_size(int\
    \ u) {\n        return -lab[getRoot(u)];\n    }\n};\n// }}}\n#line 7 \"DataStructure/test/dsu.test.cpp\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q;\
    \ cin >> n >> q;\n    DSU dsu(n);\n    while (q--) {\n        int typ, u, v; cin\
    \ >> typ >> u >> v;\n        if (typ == 0) dsu.merge(u, v);\n        else {\n\
    \            cout << (dsu.getRoot(u) == dsu.getRoot(v) ? 1 : 0) << '\\n';\n  \
    \      }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../DSU/DisjointSet.h\"\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin\
    \ >> n >> q;\n    DSU dsu(n);\n    while (q--) {\n        int typ, u, v; cin >>\
    \ typ >> u >> v;\n        if (typ == 0) dsu.merge(u, v);\n        else {\n   \
    \         cout << (dsu.getRoot(u) == dsu.getRoot(v) ? 1 : 0) << '\\n';\n     \
    \   }\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/DSU/DisjointSet.h
  isVerificationFile: true
  path: DataStructure/test/dsu.test.cpp
  requiredBy: []
  timestamp: '2023-01-07 01:46:12+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/dsu.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/dsu.test.cpp
- /verify/DataStructure/test/dsu.test.cpp.html
title: DataStructure/test/dsu.test.cpp
---
