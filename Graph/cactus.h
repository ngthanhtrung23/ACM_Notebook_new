/**
 * Tested:
 * - https://www.spoj.com/problems/LUTRIJA/
 *
 * Cactus decomposition turns the graph into pieces called blocks:
 * - a bridge block: one edge not in any cycle
 * - a cycle block: one whole simple cycle
 *
 * e.g.
 * 1
 * | \
 * |  \
 * 2---3---4---5
 *
 * Decomposition:
 * Block 0: cycle [1, 2, 3]
 * Block 1: bridge [3, 4]
 * Block 2: bridge [4, 5]
 *
 * Block-cut tree:
 *       cycle(1,2,3)
 *     /    |    \
 *    1     2     3
 *                |
 *             bridge(3,4)
 *                |
 *                4
 *                |
 *             bridge(4,5)
 *                |
 *                5
 *
 * Usage:
 *
 * ```
 * CactusBuilder builder(n);
 * for (auto [u, v] : edges) { // 0-based index
 *   builder.add_edge(u, v);
 * }
 * Cactus cactus = builder.build();
 * ```
 *
 * Typical DP pattern:
 *
 * ```
 * function<ReturnType(int,int)> solve_vertex;
 * function<ReturnType(int,int)> solve_block;
 *
 * solve_vertex = [&](int u, int parent_block) -> ReturnType {
 *   for (int block_node : cactus.tree[u]) {
 *     if (block_node == parent_block) continue;
 *
 *     ReturnType child = solve_block(cactus.block_id(block_node), u);
 *     // Update result using child
 *   }
 * };
 *
 * solve_block = [&](int block_id, int parent_vertex) -> ReturnType {
 *   const CactusBlock& block = cactus.blocks[block_id];
 *   if (!block.is_cycle) { // handle bridge
 *     int a = block.vertices[0];
 *     int b = block.vertices[1];
 *     int child_vertex = a ^ b ^ parent_vertex;
 *   }
 *
 *   // handle cycle
 *   for (int u : block.vertices) {
 *     if (u == parent_vertex) continue;
 *     solve_vertex(u, N + block_id);
 *   }
 * };
 * ```
 */

// Block cut tree {{{
struct CactusBlock {
    bool is_cycle;
    vector<int> vertices; // cycle order if is_cycle, size 2 if bridge
};

struct Cactus {
    int n;
    vector<CactusBlock> blocks;

    // block-cut tree:
    // original vertices: 0..n-1
    // block nodes: n..n+blocks.size()-1
    vector<vector<int>> tree;

    bool is_vertex(int x) const { return x < n; }
    bool is_block(int x) const { return x >= n; }
    int block_id(int x) const { return x - n; }
};

struct CactusBuilder {
    int n, edge_cnt = 0;
    vector<vector<pair<int,int>>> adj;
    vector<pair<int,int>> edges;

    CactusBuilder(int n): n(n), adj(n) {}

    void add_edge(int u, int v) {
        adj[u].push_back({v, edge_cnt});
        adj[v].push_back({u, edge_cnt});
        edges.push_back({u, v});
        edge_cnt++;
    }

    Cactus build() {
        vector<int> tin(n, 0), parent(n, -1), parent_edge(n, -1);
        vector<int> edge_in_cycle(edge_cnt, 0);
        vector<CactusBlock> blocks;
        int timer = 0;

        function<void(int,int)> dfs = [&](int u, int pe) {
            tin[u] = ++timer;

            for (auto [v, eid] : adj[u]) {
                if (eid == pe) continue;

                if (!tin[v]) {
                    parent[v] = u;
                    parent_edge[v] = eid;
                    dfs(v, eid);
                } else if (tin[v] < tin[u]) {
                    vector<int> path;
                    int x = u;

                    while (x != v) {
                        path.push_back(x);
                        edge_in_cycle[parent_edge[x]] = 1;
                        x = parent[x];
                    }

                    edge_in_cycle[eid] = 1;

                    reverse(path.begin(), path.end());

                    vector<int> cyc;
                    cyc.push_back(v);
                    for (int y : path) cyc.push_back(y);

                    blocks.push_back({true, cyc});
                }
            }
        };

        REP(i, n) {
            if (!tin[i]) dfs(i, -1);
        }

        FOR(v, 0, n - 1) {
            if (parent[v] != -1 && !edge_in_cycle[parent_edge[v]]) {
                blocks.push_back({false, {v, parent[v]}});
            }
        }

        vector<vector<int>> tree(n + (int)blocks.size());

        REP(i, (int)blocks.size()) {
            int bnode = n + i;
            for (int v : blocks[i].vertices) {
                tree[bnode].push_back(v);
                tree[v].push_back(bnode);
            }
        }

        return Cactus{n, blocks, tree};
    }
};
// }}}
