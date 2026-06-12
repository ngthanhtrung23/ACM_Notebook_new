---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU/DSU_rollback.h
    title: DataStructure/DSU/DSU_rollback.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/gym/100551/problem/A
    - https://www.spoj.com/problems/DYNACON2/
  bundledCode: "#line 1 \"DataStructure/DSU/DSU_rollback.h\"\n// Tested:\n// - (dynamic\
    \ connectivity) https://codeforces.com/gym/100551/problem/A\n// - (used for directed\
    \ MST) https://judge.yosupo.jp/problem/directedmst\n//\n// 0-based\n// DSU with\
    \ rollback {{{\nstruct Data {\n    int time, u, par;  // before `time`, `par`\
    \ = par[u]\n};\n\nstruct DSU {\n    vector<int> par;\n    vector<Data> change;\n\
    \n    DSU(int n) : par(n + 5, -1) {}\n\n    // find root of x.\n    // if par[x]\
    \ < 0 then x is a root, and its tree has -par[x] nodes\n    int getRoot(int x)\
    \ {\n        while (par[x] >= 0)\n            x = par[x];\n        return x;\n\
    \    }\n\n    bool same_component(int u, int v) {\n        return getRoot(u) ==\
    \ getRoot(v);\n    }\n\n    // join components containing x and y.\n    // t should\
    \ be current time. We use it to update `change`.\n    bool join(int x, int y,\
    \ int t) {\n        x = getRoot(x);\n        y = getRoot(y);\n        if (x ==\
    \ y) return false;\n\n        //union by rank\n        if (par[x] < par[y]) swap(x,\
    \ y); \n        //now x's tree has less nodes than y's tree\n        change.push_back({t,\
    \ y, par[y]});\n        par[y] += par[x];\n        change.push_back({t, x, par[x]});\n\
    \        par[x] = y;\n        return true;\n    }\n\n    // rollback all changes\
    \ at time > t.\n    void rollback(int t) {\n        while (!change.empty() &&\
    \ change.back().time > t) {\n            par[change.back().u] = change.back().par;\n\
    \            change.pop_back();\n        }\n    }\n};\n// }}}\n#line 2 \"DataStructure/DSU/DSU_dynamic_connectivity.h\"\
    \n\n// Index from 0\n// Tested:\n// - https://codeforces.com/gym/100551/problem/A\n\
    // - https://www.spoj.com/problems/DYNACON2/\n//\n// Dynamic connectivity {{{\n\
    namespace DynamicConnectivity {\n    enum QueryType { ADD, REM, IS_CONNECTED,\
    \ N_COMPONENTS };\n    struct Query {\n        QueryType typ;\n        int u,\
    \ v;\n    };\n\n    // Segment tree: for each node maintaining [l, r], store all\
    \ the\n    // edges covering all times between l and r.\n    vector<vector<pair<int,int>>>\
    \ edges;\n    vector<Query> queries;\n\n    void update(int i, int l, int r, int\
    \ u, int v, const pair<int,int>& e) {\n        if (v < l || r < u) return;\n \
    \       if (u <= l && r <= v) {\n            edges[i].push_back(e);\n        \
    \    return;\n        }\n        int mid = (l + r) / 2;\n        update(i*2, l,\
    \ mid, u, v, e);\n        update(i*2+1, mid+1, r, u, v, e);\n    }\n\n    void\
    \ dfs(\n            int i, int l, int r,\n            int current_time, int n_connected_components,\n\
    \            DSU& dsu,\n            vector<int>& res) {\n        for (auto [u,\
    \ v] : edges[i]) {\n            if (!dsu.same_component(u, v)) {\n           \
    \     --n_connected_components;\n            }\n            dsu.join(u, v, current_time);\n\
    \        }\n\n        if (l == r) {\n            if (queries[l].typ == IS_CONNECTED)\
    \ {\n                int u = queries[l].u, v = queries[l].v;\n               \
    \ res[l] = dsu.same_component(u, v);\n            } else if (queries[l].typ ==\
    \ N_COMPONENTS) {\n                res[l] = n_connected_components;\n        \
    \    }\n            return;\n        }\n\n        int mid = (l + r) / 2;\n   \
    \     dfs(i*2, l, mid, current_time + 1, n_connected_components, dsu, res);\n\
    \        dsu.rollback(current_time);\n        dfs(i*2+1, mid+1, r, current_time\
    \ + 1, n_connected_components, dsu, res);\n    }\n\n    // Returns: vector of\
    \ length |Q|\n    // The i-th element is answer for i-th query\n    //     -1\
    \ if the i-th query is ADD or REM\n    vector<int> solve(int n, const vector<Query>&\
    \ _queries) {\n        queries = _queries;\n        edges.clear();\n        edges.resize(4\
    \ * queries.size());\n\n        map<pair<int,int>, int> addTimes;\n\n        int\
    \ q = queries.size();\n        for (int i = 0; i < q; ++i) {\n            const\
    \ auto& query = queries[i];\n            if (query.typ == ADD) {\n           \
    \     int u = query.u, v = query.v;\n                if (u > v) swap(u, v);\n\
    \                auto p = make_pair(u, v);\n                assert(!addTimes.count(p));\n\
    \n                addTimes[p] = i;\n            } else if (query.typ == REM) {\n\
    \                int u = query.u, v = query.v;\n                if (u > v) swap(u,\
    \ v);\n                auto p = make_pair(u, v);\n                assert(addTimes.count(p));\n\
    \n                update(1, 0, q-1, addTimes[p], i, p);\n\n                addTimes.erase(p);\n\
    \            }\n        }\n        for (const auto& [e, startTime] : addTimes)\
    \ {\n            update(1, 0, q-1, startTime, q-1, e);\n        }\n\n        vector<int>\
    \ res(queries.size(), -1);\n        if (q > 0) {\n            DSU dsu(n);\n  \
    \          dfs(1, 0, q-1, 0, n, dsu, res);\n        }\n        return res;\n \
    \   }\n}\n// }}}\n"
  code: "#include \"DSU_rollback.h\"\n\n// Index from 0\n// Tested:\n// - https://codeforces.com/gym/100551/problem/A\n\
    // - https://www.spoj.com/problems/DYNACON2/\n//\n// Dynamic connectivity {{{\n\
    namespace DynamicConnectivity {\n    enum QueryType { ADD, REM, IS_CONNECTED,\
    \ N_COMPONENTS };\n    struct Query {\n        QueryType typ;\n        int u,\
    \ v;\n    };\n\n    // Segment tree: for each node maintaining [l, r], store all\
    \ the\n    // edges covering all times between l and r.\n    vector<vector<pair<int,int>>>\
    \ edges;\n    vector<Query> queries;\n\n    void update(int i, int l, int r, int\
    \ u, int v, const pair<int,int>& e) {\n        if (v < l || r < u) return;\n \
    \       if (u <= l && r <= v) {\n            edges[i].push_back(e);\n        \
    \    return;\n        }\n        int mid = (l + r) / 2;\n        update(i*2, l,\
    \ mid, u, v, e);\n        update(i*2+1, mid+1, r, u, v, e);\n    }\n\n    void\
    \ dfs(\n            int i, int l, int r,\n            int current_time, int n_connected_components,\n\
    \            DSU& dsu,\n            vector<int>& res) {\n        for (auto [u,\
    \ v] : edges[i]) {\n            if (!dsu.same_component(u, v)) {\n           \
    \     --n_connected_components;\n            }\n            dsu.join(u, v, current_time);\n\
    \        }\n\n        if (l == r) {\n            if (queries[l].typ == IS_CONNECTED)\
    \ {\n                int u = queries[l].u, v = queries[l].v;\n               \
    \ res[l] = dsu.same_component(u, v);\n            } else if (queries[l].typ ==\
    \ N_COMPONENTS) {\n                res[l] = n_connected_components;\n        \
    \    }\n            return;\n        }\n\n        int mid = (l + r) / 2;\n   \
    \     dfs(i*2, l, mid, current_time + 1, n_connected_components, dsu, res);\n\
    \        dsu.rollback(current_time);\n        dfs(i*2+1, mid+1, r, current_time\
    \ + 1, n_connected_components, dsu, res);\n    }\n\n    // Returns: vector of\
    \ length |Q|\n    // The i-th element is answer for i-th query\n    //     -1\
    \ if the i-th query is ADD or REM\n    vector<int> solve(int n, const vector<Query>&\
    \ _queries) {\n        queries = _queries;\n        edges.clear();\n        edges.resize(4\
    \ * queries.size());\n\n        map<pair<int,int>, int> addTimes;\n\n        int\
    \ q = queries.size();\n        for (int i = 0; i < q; ++i) {\n            const\
    \ auto& query = queries[i];\n            if (query.typ == ADD) {\n           \
    \     int u = query.u, v = query.v;\n                if (u > v) swap(u, v);\n\
    \                auto p = make_pair(u, v);\n                assert(!addTimes.count(p));\n\
    \n                addTimes[p] = i;\n            } else if (query.typ == REM) {\n\
    \                int u = query.u, v = query.v;\n                if (u > v) swap(u,\
    \ v);\n                auto p = make_pair(u, v);\n                assert(addTimes.count(p));\n\
    \n                update(1, 0, q-1, addTimes[p], i, p);\n\n                addTimes.erase(p);\n\
    \            }\n        }\n        for (const auto& [e, startTime] : addTimes)\
    \ {\n            update(1, 0, q-1, startTime, q-1, e);\n        }\n\n        vector<int>\
    \ res(queries.size(), -1);\n        if (q > 0) {\n            DSU dsu(n);\n  \
    \          dfs(1, 0, q-1, 0, n, dsu, res);\n        }\n        return res;\n \
    \   }\n}\n// }}}\n"
  dependsOn:
  - DataStructure/DSU/DSU_rollback.h
  isVerificationFile: false
  path: DataStructure/DSU/DSU_dynamic_connectivity.h
  requiredBy: []
  timestamp: '2023-01-07 01:46:12+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/DSU/DSU_dynamic_connectivity.h
layout: document
redirect_from:
- /library/DataStructure/DSU/DSU_dynamic_connectivity.h
- /library/DataStructure/DSU/DSU_dynamic_connectivity.h.html
title: DataStructure/DSU/DSU_dynamic_connectivity.h
---
