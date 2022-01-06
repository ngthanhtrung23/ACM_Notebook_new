---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DisjointSet.h
    title: DataStructure/DisjointSet.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"DataStructure/test/dsu_aizu.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"DataStructure/DisjointSet.h\"\
    \nstruct DSU {\n    vector<int> lab;\n\n    DSU(int n) : lab(n+1, -1) {}\n\n \
    \   int getRoot(int u) {\n        if (lab[u] < 0) return u;\n        return lab[u]\
    \ = getRoot(lab[u]);\n    }\n\n    bool merge(int u, int v) {\n        u = getRoot(u);\
    \ v = getRoot(v);\n        if (u == v) return false;\n        if (lab[u] > lab[v])\
    \ swap(u, v);\n        lab[u] += lab[v];\n        lab[v] = u;\n        return\
    \ true;\n    }\n\n    bool same_component(int u, int v) {\n        return getRoot(u)\
    \ == getRoot(v);\n    }\n\n    int component_size(int u) {\n        return -lab[getRoot(u)];\n\
    \    }\n};\n#line 7 \"DataStructure/test/dsu_aizu.test.cpp\"\n\nint main() {\n\
    \    int n, q; cin >> n >> q;\n    DSU dsu(n);\n    while (q--) {\n        int\
    \ typ, x, y; cin >> typ >> x >> y;\n        if (typ == 0) dsu.merge(x, y);\n \
    \       else cout << dsu.same_component(x, y) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../DisjointSet.h\"\
    \n\nint main() {\n    int n, q; cin >> n >> q;\n    DSU dsu(n);\n    while (q--)\
    \ {\n        int typ, x, y; cin >> typ >> x >> y;\n        if (typ == 0) dsu.merge(x,\
    \ y);\n        else cout << dsu.same_component(x, y) << '\\n';\n    }\n}\n"
  dependsOn:
  - DataStructure/DisjointSet.h
  isVerificationFile: true
  path: DataStructure/test/dsu_aizu.test.cpp
  requiredBy: []
  timestamp: '2022-01-07 04:54:04+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/dsu_aizu.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/dsu_aizu.test.cpp
- /verify/DataStructure/test/dsu_aizu.test.cpp.html
title: DataStructure/test/dsu_aizu.test.cpp
---
