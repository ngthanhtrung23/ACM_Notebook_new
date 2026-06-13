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
    - https://www.spoj.com/problems/LUTRIJA/
  bundledCode: "#line 1 \"Graph/cactus.h\"\n/**\n * Tested:\n * - https://www.spoj.com/problems/LUTRIJA/\n\
    \ *\n * Cactus decomposition turns the graph into pieces called blocks:\n * -\
    \ a bridge block: one edge not in any cycle\n * - a cycle block: one whole simple\
    \ cycle\n *\n * e.g.\n * 1\n * | \\\n * |  \\\n * 2---3---4---5\n *\n * Decomposition:\n\
    \ * Block 0: cycle [1, 2, 3]\n * Block 1: bridge [3, 4]\n * Block 2: bridge [4,\
    \ 5]\n *\n * Block-cut tree:\n *       cycle(1,2,3)\n *     /    |    \\\n * \
    \   1     2     3\n *                |\n *             bridge(3,4)\n *       \
    \         |\n *                4\n *                |\n *             bridge(4,5)\n\
    \ *                |\n *                5\n *\n * Usage:\n *\n * ```\n * CactusBuilder\
    \ builder(n);\n * for (auto [u, v] : edges) { // 0-based index\n *   builder.add_edge(u,\
    \ v);\n * }\n * Cactus cactus = builder.build();\n * ```\n *\n * Typical DP pattern:\n\
    \ *\n * ```\n * function<ReturnType(int,int)> solve_vertex;\n * function<ReturnType(int,int)>\
    \ solve_block;\n *\n * solve_vertex = [&](int u, int parent_block) -> ReturnType\
    \ {\n *   for (int block_node : cactus.tree[u]) {\n *     if (block_node == parent_block)\
    \ continue;\n *\n *     ReturnType child = solve_block(cactus.block_id(block_node),\
    \ u);\n *     // Update result using child\n *   }\n * };\n *\n * solve_block\
    \ = [&](int block_id, int parent_vertex) -> ReturnType {\n *   const CactusBlock&\
    \ block = cactus.blocks[block_id];\n *   if (!block.is_cycle) { // handle bridge\n\
    \ *     int a = block.vertices[0];\n *     int b = block.vertices[1];\n *    \
    \ int child_vertex = a ^ b ^ parent_vertex;\n *   }\n *\n *   // handle cycle\n\
    \ *   for (int u : block.vertices) {\n *     if (u == parent_vertex) continue;\n\
    \ *     solve_vertex(u, N + block_id);\n *   }\n * };\n * ```\n */\n\n// Block\
    \ cut tree {{{\nstruct CactusBlock {\n    bool is_cycle;\n    vector<int> vertices;\
    \ // cycle order if is_cycle, size 2 if bridge\n};\n\nstruct Cactus {\n    int\
    \ n;\n    vector<CactusBlock> blocks;\n\n    // block-cut tree:\n    // original\
    \ vertices: 0..n-1\n    // block nodes: n..n+blocks.size()-1\n    vector<vector<int>>\
    \ tree;\n\n    bool is_vertex(int x) const { return x < n; }\n    bool is_block(int\
    \ x) const { return x >= n; }\n    int block_id(int x) const { return x - n; }\n\
    };\n\nstruct CactusBuilder {\n    int n, edge_cnt = 0;\n    vector<vector<pair<int,int>>>\
    \ adj;\n    vector<pair<int,int>> edges;\n\n    CactusBuilder(int n): n(n), adj(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        adj[u].push_back({v, edge_cnt});\n\
    \        adj[v].push_back({u, edge_cnt});\n        edges.push_back({u, v});\n\
    \        edge_cnt++;\n    }\n\n    Cactus build() {\n        vector<int> tin(n,\
    \ 0), parent(n, -1), parent_edge(n, -1);\n        vector<int> edge_in_cycle(edge_cnt,\
    \ 0);\n        vector<CactusBlock> blocks;\n        int timer = 0;\n\n       \
    \ function<void(int,int)> dfs = [&](int u, int pe) {\n            tin[u] = ++timer;\n\
    \n            for (auto [v, eid] : adj[u]) {\n                if (eid == pe) continue;\n\
    \n                if (!tin[v]) {\n                    parent[v] = u;\n       \
    \             parent_edge[v] = eid;\n                    dfs(v, eid);\n      \
    \          } else if (tin[v] < tin[u]) {\n                    vector<int> path;\n\
    \                    int x = u;\n\n                    while (x != v) {\n    \
    \                    path.push_back(x);\n                        edge_in_cycle[parent_edge[x]]\
    \ = 1;\n                        x = parent[x];\n                    }\n\n    \
    \                edge_in_cycle[eid] = 1;\n\n                    reverse(path.begin(),\
    \ path.end());\n\n                    vector<int> cyc;\n                    cyc.push_back(v);\n\
    \                    for (int y : path) cyc.push_back(y);\n\n                \
    \    blocks.push_back({true, cyc});\n                }\n            }\n      \
    \  };\n\n        REP(i, n) {\n            if (!tin[i]) dfs(i, -1);\n        }\n\
    \n        FOR(v, 0, n - 1) {\n            if (parent[v] != -1 && !edge_in_cycle[parent_edge[v]])\
    \ {\n                blocks.push_back({false, {v, parent[v]}});\n            }\n\
    \        }\n\n        vector<vector<int>> tree(n + (int)blocks.size());\n\n  \
    \      REP(i, (int)blocks.size()) {\n            int bnode = n + i;\n        \
    \    for (int v : blocks[i].vertices) {\n                tree[bnode].push_back(v);\n\
    \                tree[v].push_back(bnode);\n            }\n        }\n\n     \
    \   return Cactus{n, blocks, tree};\n    }\n};\n// }}}\n"
  code: "/**\n * Tested:\n * - https://www.spoj.com/problems/LUTRIJA/\n *\n * Cactus\
    \ decomposition turns the graph into pieces called blocks:\n * - a bridge block:\
    \ one edge not in any cycle\n * - a cycle block: one whole simple cycle\n *\n\
    \ * e.g.\n * 1\n * | \\\n * |  \\\n * 2---3---4---5\n *\n * Decomposition:\n *\
    \ Block 0: cycle [1, 2, 3]\n * Block 1: bridge [3, 4]\n * Block 2: bridge [4,\
    \ 5]\n *\n * Block-cut tree:\n *       cycle(1,2,3)\n *     /    |    \\\n * \
    \   1     2     3\n *                |\n *             bridge(3,4)\n *       \
    \         |\n *                4\n *                |\n *             bridge(4,5)\n\
    \ *                |\n *                5\n *\n * Usage:\n *\n * ```\n * CactusBuilder\
    \ builder(n);\n * for (auto [u, v] : edges) { // 0-based index\n *   builder.add_edge(u,\
    \ v);\n * }\n * Cactus cactus = builder.build();\n * ```\n *\n * Typical DP pattern:\n\
    \ *\n * ```\n * function<ReturnType(int,int)> solve_vertex;\n * function<ReturnType(int,int)>\
    \ solve_block;\n *\n * solve_vertex = [&](int u, int parent_block) -> ReturnType\
    \ {\n *   for (int block_node : cactus.tree[u]) {\n *     if (block_node == parent_block)\
    \ continue;\n *\n *     ReturnType child = solve_block(cactus.block_id(block_node),\
    \ u);\n *     // Update result using child\n *   }\n * };\n *\n * solve_block\
    \ = [&](int block_id, int parent_vertex) -> ReturnType {\n *   const CactusBlock&\
    \ block = cactus.blocks[block_id];\n *   if (!block.is_cycle) { // handle bridge\n\
    \ *     int a = block.vertices[0];\n *     int b = block.vertices[1];\n *    \
    \ int child_vertex = a ^ b ^ parent_vertex;\n *   }\n *\n *   // handle cycle\n\
    \ *   for (int u : block.vertices) {\n *     if (u == parent_vertex) continue;\n\
    \ *     solve_vertex(u, N + block_id);\n *   }\n * };\n * ```\n */\n\n// Block\
    \ cut tree {{{\nstruct CactusBlock {\n    bool is_cycle;\n    vector<int> vertices;\
    \ // cycle order if is_cycle, size 2 if bridge\n};\n\nstruct Cactus {\n    int\
    \ n;\n    vector<CactusBlock> blocks;\n\n    // block-cut tree:\n    // original\
    \ vertices: 0..n-1\n    // block nodes: n..n+blocks.size()-1\n    vector<vector<int>>\
    \ tree;\n\n    bool is_vertex(int x) const { return x < n; }\n    bool is_block(int\
    \ x) const { return x >= n; }\n    int block_id(int x) const { return x - n; }\n\
    };\n\nstruct CactusBuilder {\n    int n, edge_cnt = 0;\n    vector<vector<pair<int,int>>>\
    \ adj;\n    vector<pair<int,int>> edges;\n\n    CactusBuilder(int n): n(n), adj(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        adj[u].push_back({v, edge_cnt});\n\
    \        adj[v].push_back({u, edge_cnt});\n        edges.push_back({u, v});\n\
    \        edge_cnt++;\n    }\n\n    Cactus build() {\n        vector<int> tin(n,\
    \ 0), parent(n, -1), parent_edge(n, -1);\n        vector<int> edge_in_cycle(edge_cnt,\
    \ 0);\n        vector<CactusBlock> blocks;\n        int timer = 0;\n\n       \
    \ function<void(int,int)> dfs = [&](int u, int pe) {\n            tin[u] = ++timer;\n\
    \n            for (auto [v, eid] : adj[u]) {\n                if (eid == pe) continue;\n\
    \n                if (!tin[v]) {\n                    parent[v] = u;\n       \
    \             parent_edge[v] = eid;\n                    dfs(v, eid);\n      \
    \          } else if (tin[v] < tin[u]) {\n                    vector<int> path;\n\
    \                    int x = u;\n\n                    while (x != v) {\n    \
    \                    path.push_back(x);\n                        edge_in_cycle[parent_edge[x]]\
    \ = 1;\n                        x = parent[x];\n                    }\n\n    \
    \                edge_in_cycle[eid] = 1;\n\n                    reverse(path.begin(),\
    \ path.end());\n\n                    vector<int> cyc;\n                    cyc.push_back(v);\n\
    \                    for (int y : path) cyc.push_back(y);\n\n                \
    \    blocks.push_back({true, cyc});\n                }\n            }\n      \
    \  };\n\n        REP(i, n) {\n            if (!tin[i]) dfs(i, -1);\n        }\n\
    \n        FOR(v, 0, n - 1) {\n            if (parent[v] != -1 && !edge_in_cycle[parent_edge[v]])\
    \ {\n                blocks.push_back({false, {v, parent[v]}});\n            }\n\
    \        }\n\n        vector<vector<int>> tree(n + (int)blocks.size());\n\n  \
    \      REP(i, (int)blocks.size()) {\n            int bnode = n + i;\n        \
    \    for (int v : blocks[i].vertices) {\n                tree[bnode].push_back(v);\n\
    \                tree[v].push_back(bnode);\n            }\n        }\n\n     \
    \   return Cactus{n, blocks, tree};\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/cactus.h
  requiredBy: []
  timestamp: '2026-06-13 18:11:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/cactus.h
layout: document
redirect_from:
- /library/Graph/cactus.h
- /library/Graph/cactus.h.html
title: Graph/cactus.h
---
