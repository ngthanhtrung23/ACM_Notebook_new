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
    - https://judge.yosupo.jp/problem/maximum_independent_set
    - https://judge.yosupo.jp/submission/15825
  bundledCode: "#line 1 \"Graph/Misc/MaxClique.h\"\n// MaxClique\n// Copied from https://judge.yosupo.jp/submission/15825\n\
    //\n// 0-based index\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/maximum_independent_set\n\
    struct MaxClique {\n    static const int MN = 64; // change to bitset for n >\
    \ 64\n    int n, deg[MN];\n    uint64_t g[MN], ans;\n    vector<pair<int,int>>\
    \ edges;\n\n    MaxClique(int _n) : n(_n) {\n        fill(g, g+n, 0ull);\n   \
    \     fill(deg, deg+n, 0);\n        edges.clear();\n    }\n\n    // Add bi-directional\
    \ edge\n    // 0-based index\n    void addEdge(int u, int v) {\n        edges.emplace_back(u,\
    \ v);\n        ++deg[u]; ++deg[v];\n    }\n\n    vector<int> solve() {\n     \
    \   vector<int> ord(n);\n        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(),\
    \ ord.end(), [&] (int u, int v) { return deg[u] < deg[v]; });\n        vector<int>\
    \ id(n);\n        for (int i = 0; i < n; i++) id[ord[i]] = i;\n\n        for (const\
    \ auto& e : edges) {\n            int u = id[e.first], v = id[e.second];\n   \
    \         g[u] |= 1ull << v;\n            g[v] |= 1ull << u;\n        }\n    \
    \    uint64_t r = 0, p = (1ull << n) - 1;\n        ans = 0;\n        dfs(r, p);\n\
    \        vector<int> res;\n        for (int i = 0; i < n; i++) {\n           \
    \ if ((ans >> i) & 1) res.push_back(ord[i]);\n        }\n        return res;\n\
    \    }\n\n#define cnt __builtin_popcountll\n    void dfs(uint64_t r, uint64_t\
    \ p) {\n        if (p == 0) {\n            if (cnt(r) > cnt(ans)) ans = r;\n \
    \           return;\n        }\n        if (cnt(r | p) <= cnt(ans)) return;\n\
    \        int x = __builtin_ctzll(p & -p);\n        uint64_t c = p;\n        while\
    \ (c > 0) {\n            x = __builtin_ctzll(c & -c);\n            r |= 1ull <<\
    \ x;\n            dfs(r, p & g[x]);\n            r &= ~(1ull << x);\n        \
    \    p &= ~(1ull << x);\n            c ^= 1ull << x;\n        }\n    }\n};\n"
  code: "// MaxClique\n// Copied from https://judge.yosupo.jp/submission/15825\n//\n\
    // 0-based index\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/maximum_independent_set\n\
    struct MaxClique {\n    static const int MN = 64; // change to bitset for n >\
    \ 64\n    int n, deg[MN];\n    uint64_t g[MN], ans;\n    vector<pair<int,int>>\
    \ edges;\n\n    MaxClique(int _n) : n(_n) {\n        fill(g, g+n, 0ull);\n   \
    \     fill(deg, deg+n, 0);\n        edges.clear();\n    }\n\n    // Add bi-directional\
    \ edge\n    // 0-based index\n    void addEdge(int u, int v) {\n        edges.emplace_back(u,\
    \ v);\n        ++deg[u]; ++deg[v];\n    }\n\n    vector<int> solve() {\n     \
    \   vector<int> ord(n);\n        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(),\
    \ ord.end(), [&] (int u, int v) { return deg[u] < deg[v]; });\n        vector<int>\
    \ id(n);\n        for (int i = 0; i < n; i++) id[ord[i]] = i;\n\n        for (const\
    \ auto& e : edges) {\n            int u = id[e.first], v = id[e.second];\n   \
    \         g[u] |= 1ull << v;\n            g[v] |= 1ull << u;\n        }\n    \
    \    uint64_t r = 0, p = (1ull << n) - 1;\n        ans = 0;\n        dfs(r, p);\n\
    \        vector<int> res;\n        for (int i = 0; i < n; i++) {\n           \
    \ if ((ans >> i) & 1) res.push_back(ord[i]);\n        }\n        return res;\n\
    \    }\n\n#define cnt __builtin_popcountll\n    void dfs(uint64_t r, uint64_t\
    \ p) {\n        if (p == 0) {\n            if (cnt(r) > cnt(ans)) ans = r;\n \
    \           return;\n        }\n        if (cnt(r | p) <= cnt(ans)) return;\n\
    \        int x = __builtin_ctzll(p & -p);\n        uint64_t c = p;\n        while\
    \ (c > 0) {\n            x = __builtin_ctzll(c & -c);\n            r |= 1ull <<\
    \ x;\n            dfs(r, p & g[x]);\n            r &= ~(1ull << x);\n        \
    \    p &= ~(1ull << x);\n            c ^= 1ull << x;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Misc/MaxClique.h
  requiredBy: []
  timestamp: '2021-12-30 10:55:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Misc/MaxClique.h
layout: document
redirect_from:
- /library/Graph/Misc/MaxClique.h
- /library/Graph/Misc/MaxClique.h.html
title: Graph/Misc/MaxClique.h
---
