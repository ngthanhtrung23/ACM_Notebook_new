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
    - https://codeforces.com/gym/100551/submission/68858439
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"DataStructure/DSU_rollback.h\"\n// Tested:\n// - https://codeforces.com/gym/100551/submission/68858439\n\
    // - (used for directed MST) https://judge.yosupo.jp/problem/directedmst\n//\n\
    // 0-based\nstruct Data {\n    int time, u, par;  // before `time`, `par` = par[u]\n\
    };\n\nstruct DSU {\n    vector<int> par;\n    vector<Data> change;\n\n    void\
    \ init(int n) {\n        par = vector<int> (n + 5, -1);\n        change.clear();\n\
    \    }\n\n    // find root of x.\n    // if par[x] < 0 then x is a root, and its\
    \ tree has -par[x] nodes\n    int getRoot(int x) {\n        while (par[x] >= 0)\n\
    \            x = par[x];\n        return x;\n    }\n\n    // join components containing\
    \ x and y.\n    // t should be current time. We use it to update `change`.\n \
    \   void join(int x, int y, int t) {\n        x = getRoot(x);\n        y = getRoot(y);\n\
    \        //union by rank\n        if (par[x] < par[y]) swap(x, y); \n        //now\
    \ x's tree has less nodes than y's tree\n        change.push_back({t, y, par[y]});\n\
    \        par[y] += par[x];\n        change.push_back({t, x, par[x]});\n      \
    \  par[x] = y;\n    }\n\n    // rollback all changes at time > t.\n    void rollback(int\
    \ t) {\n        while (!change.empty() && change.back().time > t) {\n        \
    \    par[change.back().u] = change.back().par;\n            change.pop_back();\n\
    \        }\n    }\n};\n"
  code: "// Tested:\n// - https://codeforces.com/gym/100551/submission/68858439\n\
    // - (used for directed MST) https://judge.yosupo.jp/problem/directedmst\n//\n\
    // 0-based\nstruct Data {\n    int time, u, par;  // before `time`, `par` = par[u]\n\
    };\n\nstruct DSU {\n    vector<int> par;\n    vector<Data> change;\n\n    void\
    \ init(int n) {\n        par = vector<int> (n + 5, -1);\n        change.clear();\n\
    \    }\n\n    // find root of x.\n    // if par[x] < 0 then x is a root, and its\
    \ tree has -par[x] nodes\n    int getRoot(int x) {\n        while (par[x] >= 0)\n\
    \            x = par[x];\n        return x;\n    }\n\n    // join components containing\
    \ x and y.\n    // t should be current time. We use it to update `change`.\n \
    \   void join(int x, int y, int t) {\n        x = getRoot(x);\n        y = getRoot(y);\n\
    \        //union by rank\n        if (par[x] < par[y]) swap(x, y); \n        //now\
    \ x's tree has less nodes than y's tree\n        change.push_back({t, y, par[y]});\n\
    \        par[y] += par[x];\n        change.push_back({t, x, par[x]});\n      \
    \  par[x] = y;\n    }\n\n    // rollback all changes at time > t.\n    void rollback(int\
    \ t) {\n        while (!change.empty() && change.back().time > t) {\n        \
    \    par[change.back().u] = change.back().par;\n            change.pop_back();\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DSU_rollback.h
  requiredBy: []
  timestamp: '2021-12-31 14:01:16+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/DSU_rollback.h
layout: document
redirect_from:
- /library/DataStructure/DSU_rollback.h
- /library/DataStructure/DSU_rollback.h.html
title: DataStructure/DSU_rollback.h
---
