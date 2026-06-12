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
    - https://codeforces.com/blog/entry/43230
    - https://www.spoj.com/problems/COT2/
  bundledCode: "#line 1 \"DataStructure/Mo/TreeMoAlgorithm.h\"\n// NOTE:\n// - Query\
    \ type must be a pair of vertices: <u, v>, specifying a path from u -> v\n// -\
    \ Add / Rem functions:\n//   - If ids appear twice -> MUST treat as 0 time\n//\n\
    // Resource:\n// - https://codeforces.com/blog/entry/43230\n//\n// Tested:\n//\
    \ - https://www.spoj.com/problems/COT2/\n//\n// Mo's algorithm on tree {{{\ntemplate<typename\
    \ ResultT, typename Add, typename Rem, typename Get>\nstruct TreeMoAlgorithm {\n\
    \    TreeMoAlgorithm(const vector<vector<int>>& _g, int root)\n            : n(_g.size()),\
    \ g(_g),\n            parent(n), depth(n), sz(n),\n            dfs_number(0),\
    \ nxt(n), in(n), out(n), flattened(n * 2)\n    {\n        assert(0 <= root &&\
    \ root < n);\n\n        // init parent, depth, sz\n        // also move most heavy\
    \ child of u to g[u][0]\n        depth[root] = 0;\n        dfs_sz(root, -1);\n\
    \n        // init nxt, in, out\n        nxt[root] = root;\n        dfs_hld(root);\n\
    \    }\n\n    vector<ResultT> solve(\n            const vector<pair<int,int>>&\
    \ orig_queries,\n            Add add, Rem rem, Get get) {\n        int q = orig_queries.size();\n\
    \        vector<ResultT> res(q);\n\n        // Convert to tree queries\n     \
    \   vector<TreeQuery> queries(q);\n        for (int i = 0; i < q; ++i) {\n   \
    \         auto [u, v] = orig_queries[i];\n            assert(0 <= u && u < n);\n\
    \            assert(0 <= v && v < n);\n\n            if (in[u] > in[v]) swap(u,\
    \ v);\n            assert(in[u] <= in[v]);\n\n            queries[i].p = lca(u,\
    \ v);\n            if (queries[i].p == u) queries[i].l = in[u], queries[i].r =\
    \ in[v];\n            else queries[i].l = out[u], queries[i].r = in[v];\n    \
    \        queries[i].u = u;\n        }\n     \n        // Sort queries in increasing\
    \ order of (left / SQRT, right)\n        int S = sqrt(n);\n        if (S < 1)\
    \ S = 1;\n     \n        vector<int> query_ids(q);\n        std::iota(query_ids.begin(),\
    \ query_ids.end(), 0);\n        std::sort(query_ids.begin(), query_ids.end(),\
    \ [&] (int q1, int q2) {\n            int bucket1 = queries[q1].l / S;\n     \
    \       int bucket2 = queries[q2].l / S;\n            if (bucket1 != bucket2)\
    \ return bucket1 < bucket2;\n            else {\n                return bucket1\
    \ % 2\n                        ? (queries[q1].r > queries[q2].r)\n           \
    \             : (queries[q1].r < queries[q2].r);\n            }\n        });\n\
    \n        // Answer queries\n        int cur_l = -1, cur_r = -1;\n        for\
    \ (int qid : query_ids) {\n            // move to this range\n            if (cur_l\
    \ < 0) {\n                for (int i = queries[qid].l; i <= queries[qid].r; ++i)\
    \ {\n                    add(flattened[i]);\n                }\n             \
    \   cur_l = queries[qid].l, cur_r = queries[qid].r;\n            } else {\n  \
    \              while (cur_l > queries[qid].l) add(flattened[--cur_l]);\n     \
    \           while (cur_r < queries[qid].r) add(flattened[++cur_r]);\n        \
    \        while (cur_r > queries[qid].r) rem(flattened[cur_r--]);\n           \
    \     while (cur_l < queries[qid].l) rem(flattened[cur_l++]);\n            }\n\
    \n            if (queries[qid].p != queries[qid].u) add(queries[qid].p);\n\n \
    \           res[qid] = get(orig_queries[qid]);\n\n            if (queries[qid].p\
    \ != queries[qid].u) rem(queries[qid].p);\n        }\n        return res;\n  \
    \  }\n\n    struct TreeQuery {\n        int p;\n        int l, r, u;\n    };\n\
    \n    int lca(int u, int v) const {\n        assert(0 <= u && u < n);\n      \
    \  assert(0 <= v && v < n);\n        while (true) {\n            if (in[u] > in[v])\
    \ swap(u, v); // in[u] <= in[v]\n            if (nxt[u] == nxt[v]) return u;\n\
    \            v = parent[nxt[v]];\n        }\n    }\n\n    int n;\n    vector<vector<int>>\
    \ g;\n    vector<int> parent;\n    vector<int> depth;\n    vector<int> sz;\n \
    \   int dfs_number;\n    vector<int> nxt;\n\n    vector<int> in, out;\n    vector<int>\
    \ flattened;\n\n    void dfs_sz(int u, int fu) {\n        parent[u] = fu;\n  \
    \      sz[u] = 1;\n        // remove parent from adjacency list\n        auto\
    \ it = std::find(g[u].begin(), g[u].end(), fu);\n        if (it != g[u].end())\
    \ g[u].erase(it);\n\n        for (int& v : g[u]) {\n            depth[v] = depth[u]\
    \ + 1;\n            dfs_sz(v, u);\n\n            sz[u] += sz[v];\n           \
    \ if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);\n        }\n    }\n\n    void dfs_hld(int\
    \ u) {\n        flattened[in[u] = dfs_number++] = u;\n        for (int v : g[u])\
    \ {\n            nxt[v] = (v == g[u][0] ? nxt[u] : v);\n            dfs_hld(v);\n\
    \        }\n        flattened[out[u] = dfs_number++] = u;\n    }\n};\n// }}}\n"
  code: "// NOTE:\n// - Query type must be a pair of vertices: <u, v>, specifying\
    \ a path from u -> v\n// - Add / Rem functions:\n//   - If ids appear twice ->\
    \ MUST treat as 0 time\n//\n// Resource:\n// - https://codeforces.com/blog/entry/43230\n\
    //\n// Tested:\n// - https://www.spoj.com/problems/COT2/\n//\n// Mo's algorithm\
    \ on tree {{{\ntemplate<typename ResultT, typename Add, typename Rem, typename\
    \ Get>\nstruct TreeMoAlgorithm {\n    TreeMoAlgorithm(const vector<vector<int>>&\
    \ _g, int root)\n            : n(_g.size()), g(_g),\n            parent(n), depth(n),\
    \ sz(n),\n            dfs_number(0), nxt(n), in(n), out(n), flattened(n * 2)\n\
    \    {\n        assert(0 <= root && root < n);\n\n        // init parent, depth,\
    \ sz\n        // also move most heavy child of u to g[u][0]\n        depth[root]\
    \ = 0;\n        dfs_sz(root, -1);\n\n        // init nxt, in, out\n        nxt[root]\
    \ = root;\n        dfs_hld(root);\n    }\n\n    vector<ResultT> solve(\n     \
    \       const vector<pair<int,int>>& orig_queries,\n            Add add, Rem rem,\
    \ Get get) {\n        int q = orig_queries.size();\n        vector<ResultT> res(q);\n\
    \n        // Convert to tree queries\n        vector<TreeQuery> queries(q);\n\
    \        for (int i = 0; i < q; ++i) {\n            auto [u, v] = orig_queries[i];\n\
    \            assert(0 <= u && u < n);\n            assert(0 <= v && v < n);\n\n\
    \            if (in[u] > in[v]) swap(u, v);\n            assert(in[u] <= in[v]);\n\
    \n            queries[i].p = lca(u, v);\n            if (queries[i].p == u) queries[i].l\
    \ = in[u], queries[i].r = in[v];\n            else queries[i].l = out[u], queries[i].r\
    \ = in[v];\n            queries[i].u = u;\n        }\n     \n        // Sort queries\
    \ in increasing order of (left / SQRT, right)\n        int S = sqrt(n);\n    \
    \    if (S < 1) S = 1;\n     \n        vector<int> query_ids(q);\n        std::iota(query_ids.begin(),\
    \ query_ids.end(), 0);\n        std::sort(query_ids.begin(), query_ids.end(),\
    \ [&] (int q1, int q2) {\n            int bucket1 = queries[q1].l / S;\n     \
    \       int bucket2 = queries[q2].l / S;\n            if (bucket1 != bucket2)\
    \ return bucket1 < bucket2;\n            else {\n                return bucket1\
    \ % 2\n                        ? (queries[q1].r > queries[q2].r)\n           \
    \             : (queries[q1].r < queries[q2].r);\n            }\n        });\n\
    \n        // Answer queries\n        int cur_l = -1, cur_r = -1;\n        for\
    \ (int qid : query_ids) {\n            // move to this range\n            if (cur_l\
    \ < 0) {\n                for (int i = queries[qid].l; i <= queries[qid].r; ++i)\
    \ {\n                    add(flattened[i]);\n                }\n             \
    \   cur_l = queries[qid].l, cur_r = queries[qid].r;\n            } else {\n  \
    \              while (cur_l > queries[qid].l) add(flattened[--cur_l]);\n     \
    \           while (cur_r < queries[qid].r) add(flattened[++cur_r]);\n        \
    \        while (cur_r > queries[qid].r) rem(flattened[cur_r--]);\n           \
    \     while (cur_l < queries[qid].l) rem(flattened[cur_l++]);\n            }\n\
    \n            if (queries[qid].p != queries[qid].u) add(queries[qid].p);\n\n \
    \           res[qid] = get(orig_queries[qid]);\n\n            if (queries[qid].p\
    \ != queries[qid].u) rem(queries[qid].p);\n        }\n        return res;\n  \
    \  }\n\n    struct TreeQuery {\n        int p;\n        int l, r, u;\n    };\n\
    \n    int lca(int u, int v) const {\n        assert(0 <= u && u < n);\n      \
    \  assert(0 <= v && v < n);\n        while (true) {\n            if (in[u] > in[v])\
    \ swap(u, v); // in[u] <= in[v]\n            if (nxt[u] == nxt[v]) return u;\n\
    \            v = parent[nxt[v]];\n        }\n    }\n\n    int n;\n    vector<vector<int>>\
    \ g;\n    vector<int> parent;\n    vector<int> depth;\n    vector<int> sz;\n \
    \   int dfs_number;\n    vector<int> nxt;\n\n    vector<int> in, out;\n    vector<int>\
    \ flattened;\n\n    void dfs_sz(int u, int fu) {\n        parent[u] = fu;\n  \
    \      sz[u] = 1;\n        // remove parent from adjacency list\n        auto\
    \ it = std::find(g[u].begin(), g[u].end(), fu);\n        if (it != g[u].end())\
    \ g[u].erase(it);\n\n        for (int& v : g[u]) {\n            depth[v] = depth[u]\
    \ + 1;\n            dfs_sz(v, u);\n\n            sz[u] += sz[v];\n           \
    \ if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);\n        }\n    }\n\n    void dfs_hld(int\
    \ u) {\n        flattened[in[u] = dfs_number++] = u;\n        for (int v : g[u])\
    \ {\n            nxt[v] = (v == g[u][0] ? nxt[u] : v);\n            dfs_hld(v);\n\
    \        }\n        flattened[out[u] = dfs_number++] = u;\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Mo/TreeMoAlgorithm.h
  requiredBy: []
  timestamp: '2023-10-03 15:03:18-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Mo/TreeMoAlgorithm.h
layout: document
redirect_from:
- /library/DataStructure/Mo/TreeMoAlgorithm.h
- /library/DataStructure/Mo/TreeMoAlgorithm.h.html
title: DataStructure/Mo/TreeMoAlgorithm.h
---
