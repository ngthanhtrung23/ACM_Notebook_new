---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/aizu_grl_2_b_directed_mst.test.cpp
    title: Graph/tests/aizu_grl_2_b_directed_mst.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/tests/directed_mst.test.cpp
    title: Graph/tests/directed_mst.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/gym/100551/submission/68858439
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"DataStructure/DSU_rollback.h\"\n// Tested:\n// - https://codeforces.com/gym/100551/submission/68858439\n\
    // - (used for directed MST) https://judge.yosupo.jp/problem/directedmst\n//\n\
    // 0-based\nstruct Data {\n    int time, u, par;  // before `time`, `par` = par[u]\n\
    };\n\nstruct DSU {\n    vector<int> par;\n    vector<Data> change;\n\n    DSU(int\
    \ n) : par(n + 5, -1) {}\n\n    // find root of x.\n    // if par[x] < 0 then\
    \ x is a root, and its tree has -par[x] nodes\n    int getRoot(int x) {\n    \
    \    while (par[x] >= 0)\n            x = par[x];\n        return x;\n    }\n\n\
    \    // join components containing x and y.\n    // t should be current time.\
    \ We use it to update `change`.\n    bool join(int x, int y, int t) {\n      \
    \  x = getRoot(x);\n        y = getRoot(y);\n        if (x == y) return false;\n\
    \n        //union by rank\n        if (par[x] < par[y]) swap(x, y); \n       \
    \ //now x's tree has less nodes than y's tree\n        change.push_back({t, y,\
    \ par[y]});\n        par[y] += par[x];\n        change.push_back({t, x, par[x]});\n\
    \        par[x] = y;\n        return true;\n    }\n\n    // rollback all changes\
    \ at time > t.\n    void rollback(int t) {\n        while (!change.empty() &&\
    \ change.back().time > t) {\n            par[change.back().u] = change.back().par;\n\
    \            change.pop_back();\n        }\n    }\n};\n"
  code: "// Tested:\n// - https://codeforces.com/gym/100551/submission/68858439\n\
    // - (used for directed MST) https://judge.yosupo.jp/problem/directedmst\n//\n\
    // 0-based\nstruct Data {\n    int time, u, par;  // before `time`, `par` = par[u]\n\
    };\n\nstruct DSU {\n    vector<int> par;\n    vector<Data> change;\n\n    DSU(int\
    \ n) : par(n + 5, -1) {}\n\n    // find root of x.\n    // if par[x] < 0 then\
    \ x is a root, and its tree has -par[x] nodes\n    int getRoot(int x) {\n    \
    \    while (par[x] >= 0)\n            x = par[x];\n        return x;\n    }\n\n\
    \    // join components containing x and y.\n    // t should be current time.\
    \ We use it to update `change`.\n    bool join(int x, int y, int t) {\n      \
    \  x = getRoot(x);\n        y = getRoot(y);\n        if (x == y) return false;\n\
    \n        //union by rank\n        if (par[x] < par[y]) swap(x, y); \n       \
    \ //now x's tree has less nodes than y's tree\n        change.push_back({t, y,\
    \ par[y]});\n        par[y] += par[x];\n        change.push_back({t, x, par[x]});\n\
    \        par[x] = y;\n        return true;\n    }\n\n    // rollback all changes\
    \ at time > t.\n    void rollback(int t) {\n        while (!change.empty() &&\
    \ change.back().time > t) {\n            par[change.back().u] = change.back().par;\n\
    \            change.pop_back();\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DSU_rollback.h
  requiredBy: []
  timestamp: '2022-01-06 04:18:39+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/aizu_grl_2_b_directed_mst.test.cpp
  - Graph/tests/directed_mst.test.cpp
documentation_of: DataStructure/DSU_rollback.h
layout: document
redirect_from:
- /library/DataStructure/DSU_rollback.h
- /library/DataStructure/DSU_rollback.h.html
title: DataStructure/DSU_rollback.h
---
