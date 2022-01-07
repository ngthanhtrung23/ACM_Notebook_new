---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LCA.h
    title: DataStructure/LCA.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ.h
    title: DataStructure/RMQ.h
  - icon: ':heavy_check_mark:'
    path: buffered_reader.h
    title: buffered_reader.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"DataStructure/test/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/RMQ.h\"\
    \n// Sparse table\n// Usage:\n// RMQ<int, _min> st(v);\n//\n// Note:\n// - doesn't\
    \ work for empty range\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/staticrmq\n\
    template<class T, T (*op) (T, T)> struct RMQ {\n    RMQ() = default;\n    RMQ(const\
    \ vector<T>& v) : t{v}, n{(int) v.size()} {\n        for (int k = 1; (1<<k) <=\
    \ n; ++k) {\n            t.emplace_back(n - (1<<k) + 1);\n            for (int\
    \ i = 0; i + (1<<k) <= n; ++i) {\n                t[k][i] = op(t[k-1][i], t[k-1][i\
    \ + (1<<(k-1))]);\n            }\n        }\n    }\n\n    // get range [l, r-1]\n\
    \    // doesn't work for empty range\n    T get(int l, int r) const {\n      \
    \  assert(0 <= l && l < r && r <= n);\n        int k = __lg(r - l);\n        return\
    \ op(t[k][l], t[k][r - (1<<k)]);\n    }\n\nprivate:\n    vector<vector<T>> t;\n\
    \    int n;\n};\ntemplate<class T> T _min(T a, T b) { return b < a ? b : a; }\n\
    template<class T> T _max(T a, T b) { return a < b ? b : a; }\n#line 1 \"DataStructure/LCA.h\"\
    \n// LCA\n// Notes:\n// - Index from 0\n// - Cannot use for queries like min edge\
    \ in path u -> v\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/lca\nstruct\
    \ LCA {\n    const int n;\n    vector<vector<int>> adj;\n    const int root;\n\
    \    using P = pair<int,int>;\n    static P f(P x, P y) { return std::min(x, y);\
    \ }\n\n    LCA(int _n, const vector<vector<int>>& _adj, int _root)\n         \
    \   : n(_n), adj(_adj), root(_root) {\n        assert(0 <= root && root < n);\n\
    \        id.resize(n);\n        depth.resize(n);\n        order.reserve(2 * n);\n\
    \        dfs(root, -1, 0);\n        rmq = RMQ<P, f>(order);\n    }\n\n    int\
    \ lca(int u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v\
    \ && v < n);\n\n        int x = id[u], y = id[v];\n        if (x > y) std::swap(x,\
    \ y);\n        return rmq.get(x, y+1).second;\n    }\n\n// private:\n    vector<int>\
    \ id, depth;\n    vector<P> order;\n    RMQ<P, f> rmq;\n\n    void dfs(int u,\
    \ int fu, int d) {\n        id[u] = order.size();\n        depth[u] = d;\n   \
    \     order.emplace_back(d, u);\n        for (int v : adj[u]) {\n            if\
    \ (v == fu) continue;\n            dfs(v, u, d + 1);\n            order.emplace_back(d,\
    \ u);\n        }\n    }\n};\n#line 2 \"buffered_reader.h\"\nnamespace IO {\n \
    \   const int BUFSIZE = 1<<14;\n    char buf[BUFSIZE + 1], *inp = buf;\n\n   \
    \ bool reacheof;\n    char get_char() {\n        if (!*inp && !reacheof) {\n \
    \           memset(buf, 0, sizeof buf);\n            int tmp = fread(buf, 1, BUFSIZE,\
    \ stdin);\n            if (tmp != BUFSIZE) reacheof = true;\n            inp =\
    \ buf;\n        }\n        return *inp++;\n    }\n    template<typename T>\n \
    \   T get() {\n        int neg = 0;\n        T res = 0;\n        char c = get_char();\n\
    \        while (!std::isdigit(c) && c != '-' && c != '+') c = get_char();\n  \
    \      if (c == '+') { neg = 0; }\n        else if (c == '-') { neg = 1; }\n \
    \       else res = c - '0';\n\n        c = get_char();\n        while (std::isdigit(c))\
    \ {\n            res = res * 10 + (c - '0');\n            c = get_char();\n  \
    \      }\n        return neg ? -res : res;\n    }\n};\n#line 9 \"DataStructure/test/lca.test.cpp\"\
    \n\n#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n\nint32_t\
    \ main() {\n    int n = IO::get<int>();\n    int q = IO::get<int>();\n    vector<vector<int>>\
    \ adj(n);\n    FOR(i,1,n-1) {\n        int pi = IO::get<int>();\n        adj[i].push_back(pi);\n\
    \        adj[pi].push_back(i);\n    }\n\n    LCA lca(n, adj, 0);\n\n    while\
    \ (q--) {\n        int u = IO::get<int>();\n        int v = IO::get<int>();\n\n\
    \        cout << lca.lca(u, v) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../RMQ.h\"\n#include \"../LCA.h\"\n#include\
    \ \"../../buffered_reader.h\"\n\n#define FOR(i, a, b) for (int i = (a), _##i =\
    \ (b); i <= _##i; ++i)\n\nint32_t main() {\n    int n = IO::get<int>();\n    int\
    \ q = IO::get<int>();\n    vector<vector<int>> adj(n);\n    FOR(i,1,n-1) {\n \
    \       int pi = IO::get<int>();\n        adj[i].push_back(pi);\n        adj[pi].push_back(i);\n\
    \    }\n\n    LCA lca(n, adj, 0);\n\n    while (q--) {\n        int u = IO::get<int>();\n\
    \        int v = IO::get<int>();\n\n        cout << lca.lca(u, v) << '\\n';\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/RMQ.h
  - DataStructure/LCA.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/lca.test.cpp
  requiredBy: []
  timestamp: '2022-01-07 17:45:15+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/lca.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/lca.test.cpp
- /verify/DataStructure/test/lca.test.cpp.html
title: DataStructure/test/lca.test.cpp
---
