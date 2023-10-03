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
    - https://oj.vnoi.info/problem/sqrt_e
  bundledCode: "#line 1 \"DataStructure/Mo/TreeMoAlgorithmWithUpdates.h\"\n// NOTE:\n\
    // - Query type must be a pair of vertices: <u, v>, specifying a path from u ->\
    \ v\n// - Add / Rem functions:\n//   - If ids appear twice -> MUST treat as 0\
    \ time\n// - Updates must be set: A(u) = val\n// - When implementing Update(...)\
    \ -> void:\n//   we need to handle the case where we update an index that is inside\n\
    //   [cur_l, cur_r]\n//\n// Tested:\n// - https://oj.vnoi.info/problem/sqrt_e\n\
    //\n// Mo's algorithm on tree with updates {{{\ntemplate<\n    typename QueryT,\n\
    \    typename ResultT,\n    typename Add,     // add(id) -> void\n    typename\
    \ Rem,     // rem(id) -> void\n    typename Update,  // update(id, old_val, new_val,\
    \ cur_l, cur_r) -> void\n    typename Get      // get(QueryT) -> ResultT\n>\n\
    struct TreeMoAlgorithmWithUpdates {\n    TreeMoAlgorithmWithUpdates(const vector<vector<int>>&\
    \ _g, int root)\n            : n(_g.size()), g(_g),\n            parent(n), depth(n),\
    \ sz(n),\n            dfs_number(0), nxt(n), in(n), out(n), flattened(n * 2)\n\
    \    {\n        assert(0 <= root && root < n);\n\n        // init parent, depth,\
    \ sz\n        // also move most heavy child of u to g[u][0]\n        depth[root]\
    \ = 0;\n        dfs_sz(root, -1);\n\n        // init nxt, in, out\n        nxt[root]\
    \ = root;\n        dfs_hld(root);\n    }\n\n    vector<ResultT> solve(\n     \
    \       const vector<QueryT>& orig_queries,\n            Add add, Rem rem, Update\
    \ update, Get get) {\n        // Separate update and get queries\n        vector<TreeUpdate>\
    \ updates;\n        vector<TreeGet> gets;\n        for (const auto& query : orig_queries)\
    \ {\n            if (query.typ == QueryType::GET) {\n                int u = query.u,\
    \ v = query.v;\n                assert(0 <= u && u < n);\n                assert(0\
    \ <= v && v < n);\n                if (in[u] > in[v]) swap(u, v);\n          \
    \      assert(in[u] <= in[v]);\n\n                int p = lca(u, v);\n\n     \
    \           gets.push_back(TreeGet {\n                    p,\n               \
    \     p == u ? in[u] : out[u],\n                    in[v],\n                 \
    \   u,\n                    query.id,\n                });\n            } else\
    \ {\n                updates.push_back(TreeUpdate {\n                    query.u,\n\
    \                    query.new_val,\n                    query.old_val,\n    \
    \                query.id,\n                });\n            }\n        }\n\n\
    \        // Sort queries\n        int S = max<int> (1, cbrtl(n + 0.5));\n    \
    \    S = S * S;\n        std::sort(gets.begin(), gets.end(), [&] (const TreeGet&\
    \ q1, const TreeGet& q2) {\n            int l1 = q1.l / S;\n            int l2\
    \ = q2.l / S;\n            if (l1 != l2) return l1 < l2;\n\n            int r1\
    \ = q1.r / S;\n            int r2 = q2.r / S;\n            if (r1 != r2) return\
    \ (l1 % 2 == 0) ? r1 < r2 : r1 > r2;\n\n            return (r1 % 2 == 0)\n   \
    \                 ? q1.id < q2.id\n                    : q1.id > q2.id;\n    \
    \    });\n\n        // Process queries\n        vector<ResultT> res(orig_queries.size());\n\
    \        int cur_l = -1, cur_r = -1, cur_update = -1;\n        for (const auto&\
    \ query : gets) {\n            // move to [l, r]\n            if (cur_l < 0) {\n\
    \                for (int i = query.l; i <= query.r; ++i) add(flattened[i]);\n\
    \                cur_l = query.l, cur_r = query.r;\n            } else {\n   \
    \             while (cur_l > query.l) add(flattened[--cur_l]);\n             \
    \   while (cur_r < query.r) add(flattened[++cur_r]);\n                while (cur_r\
    \ > query.r) rem(flattened[cur_r--]);\n                while (cur_l < query.l)\
    \ rem(flattened[cur_l++]);\n            }\n            \n            // process\
    \ updates\n            // should we update more?\n            while (cur_update\
    \ + 1 < (int) updates.size()\n                    && updates[cur_update + 1].id\
    \ < query.id) {\n                ++cur_update;\n                update(\n    \
    \                updates[cur_update].u,\n                    updates[cur_update].old_val,\n\
    \                    updates[cur_update].new_val,\n                    cur_l,\
    \ cur_r);\n            }\n            // should we update less?\n            while\
    \ (cur_update >= 0 && updates[cur_update].id > query.id) {\n                update(\n\
    \                    updates[cur_update].u,\n                    updates[cur_update].new_val,\n\
    \                    updates[cur_update].old_val,\n                    cur_l,\
    \ cur_r);\n                --cur_update;\n            }\n\n            if (query.p\
    \ != query.u) add(query.p);\n\n            res[query.id] = get(orig_queries[query.id]);\n\
    \n            if (query.p != query.u) rem(query.p);\n        }\n        return\
    \ res;\n    }\n\n    struct TreeGet {\n        int p;\n        int l, r, u;\n\
    \        int id;\n    };\n    struct TreeUpdate {\n        int u;\n        int\
    \ new_val, old_val;\n        int id;\n    };\n\n    int lca(int u, int v) const\
    \ {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n    \
    \    while (true) {\n            if (in[u] > in[v]) swap(u, v); // in[u] <= in[v]\n\
    \            if (nxt[u] == nxt[v]) return u;\n            v = parent[nxt[v]];\n\
    \        }\n    }\n\n    int n;\n    vector<vector<int>> g;\n    vector<int> parent;\n\
    \    vector<int> depth;\n    vector<int> sz;\n    int dfs_number;\n    vector<int>\
    \ nxt;\n\n    vector<int> in, out;\n    vector<int> flattened;\n\n    void dfs_sz(int\
    \ u, int fu) {\n        parent[u] = fu;\n        sz[u] = 1;\n        // remove\
    \ parent from adjacency list\n        auto it = std::find(g[u].begin(), g[u].end(),\
    \ fu);\n        if (it != g[u].end()) g[u].erase(it);\n\n        for (int& v :\
    \ g[u]) {\n            depth[v] = depth[u] + 1;\n            dfs_sz(v, u);\n\n\
    \            sz[u] += sz[v];\n            if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);\n\
    \        }\n    }\n\n    void dfs_hld(int u) {\n        flattened[in[u] = dfs_number++]\
    \ = u;\n        for (int v : g[u]) {\n            nxt[v] = (v == g[u][0] ? nxt[u]\
    \ : v);\n            dfs_hld(v);\n        }\n        flattened[out[u] = dfs_number++]\
    \ = u;\n    }\n};\n// }}}\n\n// Example query type\nenum QueryType { GET = 0,\
    \ UPDATE = 1 };\n \nstruct Query {\n    int u, v;              // For get: path\
    \ u -> v\n    int new_val, old_val;  // For update: set a[u] = val (old value\
    \ = old_val)\n    int id;\n    QueryType typ;\n};\n"
  code: "// NOTE:\n// - Query type must be a pair of vertices: <u, v>, specifying\
    \ a path from u -> v\n// - Add / Rem functions:\n//   - If ids appear twice ->\
    \ MUST treat as 0 time\n// - Updates must be set: A(u) = val\n// - When implementing\
    \ Update(...) -> void:\n//   we need to handle the case where we update an index\
    \ that is inside\n//   [cur_l, cur_r]\n//\n// Tested:\n// - https://oj.vnoi.info/problem/sqrt_e\n\
    //\n// Mo's algorithm on tree with updates {{{\ntemplate<\n    typename QueryT,\n\
    \    typename ResultT,\n    typename Add,     // add(id) -> void\n    typename\
    \ Rem,     // rem(id) -> void\n    typename Update,  // update(id, old_val, new_val,\
    \ cur_l, cur_r) -> void\n    typename Get      // get(QueryT) -> ResultT\n>\n\
    struct TreeMoAlgorithmWithUpdates {\n    TreeMoAlgorithmWithUpdates(const vector<vector<int>>&\
    \ _g, int root)\n            : n(_g.size()), g(_g),\n            parent(n), depth(n),\
    \ sz(n),\n            dfs_number(0), nxt(n), in(n), out(n), flattened(n * 2)\n\
    \    {\n        assert(0 <= root && root < n);\n\n        // init parent, depth,\
    \ sz\n        // also move most heavy child of u to g[u][0]\n        depth[root]\
    \ = 0;\n        dfs_sz(root, -1);\n\n        // init nxt, in, out\n        nxt[root]\
    \ = root;\n        dfs_hld(root);\n    }\n\n    vector<ResultT> solve(\n     \
    \       const vector<QueryT>& orig_queries,\n            Add add, Rem rem, Update\
    \ update, Get get) {\n        // Separate update and get queries\n        vector<TreeUpdate>\
    \ updates;\n        vector<TreeGet> gets;\n        for (const auto& query : orig_queries)\
    \ {\n            if (query.typ == QueryType::GET) {\n                int u = query.u,\
    \ v = query.v;\n                assert(0 <= u && u < n);\n                assert(0\
    \ <= v && v < n);\n                if (in[u] > in[v]) swap(u, v);\n          \
    \      assert(in[u] <= in[v]);\n\n                int p = lca(u, v);\n\n     \
    \           gets.push_back(TreeGet {\n                    p,\n               \
    \     p == u ? in[u] : out[u],\n                    in[v],\n                 \
    \   u,\n                    query.id,\n                });\n            } else\
    \ {\n                updates.push_back(TreeUpdate {\n                    query.u,\n\
    \                    query.new_val,\n                    query.old_val,\n    \
    \                query.id,\n                });\n            }\n        }\n\n\
    \        // Sort queries\n        int S = max<int> (1, cbrtl(n + 0.5));\n    \
    \    S = S * S;\n        std::sort(gets.begin(), gets.end(), [&] (const TreeGet&\
    \ q1, const TreeGet& q2) {\n            int l1 = q1.l / S;\n            int l2\
    \ = q2.l / S;\n            if (l1 != l2) return l1 < l2;\n\n            int r1\
    \ = q1.r / S;\n            int r2 = q2.r / S;\n            if (r1 != r2) return\
    \ (l1 % 2 == 0) ? r1 < r2 : r1 > r2;\n\n            return (r1 % 2 == 0)\n   \
    \                 ? q1.id < q2.id\n                    : q1.id > q2.id;\n    \
    \    });\n\n        // Process queries\n        vector<ResultT> res(orig_queries.size());\n\
    \        int cur_l = -1, cur_r = -1, cur_update = -1;\n        for (const auto&\
    \ query : gets) {\n            // move to [l, r]\n            if (cur_l < 0) {\n\
    \                for (int i = query.l; i <= query.r; ++i) add(flattened[i]);\n\
    \                cur_l = query.l, cur_r = query.r;\n            } else {\n   \
    \             while (cur_l > query.l) add(flattened[--cur_l]);\n             \
    \   while (cur_r < query.r) add(flattened[++cur_r]);\n                while (cur_r\
    \ > query.r) rem(flattened[cur_r--]);\n                while (cur_l < query.l)\
    \ rem(flattened[cur_l++]);\n            }\n            \n            // process\
    \ updates\n            // should we update more?\n            while (cur_update\
    \ + 1 < (int) updates.size()\n                    && updates[cur_update + 1].id\
    \ < query.id) {\n                ++cur_update;\n                update(\n    \
    \                updates[cur_update].u,\n                    updates[cur_update].old_val,\n\
    \                    updates[cur_update].new_val,\n                    cur_l,\
    \ cur_r);\n            }\n            // should we update less?\n            while\
    \ (cur_update >= 0 && updates[cur_update].id > query.id) {\n                update(\n\
    \                    updates[cur_update].u,\n                    updates[cur_update].new_val,\n\
    \                    updates[cur_update].old_val,\n                    cur_l,\
    \ cur_r);\n                --cur_update;\n            }\n\n            if (query.p\
    \ != query.u) add(query.p);\n\n            res[query.id] = get(orig_queries[query.id]);\n\
    \n            if (query.p != query.u) rem(query.p);\n        }\n        return\
    \ res;\n    }\n\n    struct TreeGet {\n        int p;\n        int l, r, u;\n\
    \        int id;\n    };\n    struct TreeUpdate {\n        int u;\n        int\
    \ new_val, old_val;\n        int id;\n    };\n\n    int lca(int u, int v) const\
    \ {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n    \
    \    while (true) {\n            if (in[u] > in[v]) swap(u, v); // in[u] <= in[v]\n\
    \            if (nxt[u] == nxt[v]) return u;\n            v = parent[nxt[v]];\n\
    \        }\n    }\n\n    int n;\n    vector<vector<int>> g;\n    vector<int> parent;\n\
    \    vector<int> depth;\n    vector<int> sz;\n    int dfs_number;\n    vector<int>\
    \ nxt;\n\n    vector<int> in, out;\n    vector<int> flattened;\n\n    void dfs_sz(int\
    \ u, int fu) {\n        parent[u] = fu;\n        sz[u] = 1;\n        // remove\
    \ parent from adjacency list\n        auto it = std::find(g[u].begin(), g[u].end(),\
    \ fu);\n        if (it != g[u].end()) g[u].erase(it);\n\n        for (int& v :\
    \ g[u]) {\n            depth[v] = depth[u] + 1;\n            dfs_sz(v, u);\n\n\
    \            sz[u] += sz[v];\n            if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);\n\
    \        }\n    }\n\n    void dfs_hld(int u) {\n        flattened[in[u] = dfs_number++]\
    \ = u;\n        for (int v : g[u]) {\n            nxt[v] = (v == g[u][0] ? nxt[u]\
    \ : v);\n            dfs_hld(v);\n        }\n        flattened[out[u] = dfs_number++]\
    \ = u;\n    }\n};\n// }}}\n\n// Example query type\nenum QueryType { GET = 0,\
    \ UPDATE = 1 };\n \nstruct Query {\n    int u, v;              // For get: path\
    \ u -> v\n    int new_val, old_val;  // For update: set a[u] = val (old value\
    \ = old_val)\n    int id;\n    QueryType typ;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Mo/TreeMoAlgorithmWithUpdates.h
  requiredBy: []
  timestamp: '2023-10-03 00:47:04-07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Mo/TreeMoAlgorithmWithUpdates.h
layout: document
redirect_from:
- /library/DataStructure/Mo/TreeMoAlgorithmWithUpdates.h
- /library/DataStructure/Mo/TreeMoAlgorithmWithUpdates.h.html
title: DataStructure/Mo/TreeMoAlgorithmWithUpdates.h
---
