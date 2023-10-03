// NOTE:
// - Query type must be a pair of vertices: <u, v>, specifying a path from u -> v
// - Add / Rem functions:
//   - If ids appear twice -> MUST treat as 0 time
// - Updates must be set: A(u) = val
// - When implementing Update(...) -> void:
//   we need to handle the case where we update an index that is inside
//   [cur_l, cur_r]
//
// Tested:
// - https://oj.vnoi.info/problem/sqrt_e
//
// Mo's algorithm on tree with updates {{{
template<
    typename QueryT,
    typename ResultT,
    typename Add,     // add(id) -> void
    typename Rem,     // rem(id) -> void
    typename Update,  // update(id, old_val, new_val, cur_l, cur_r) -> void
    typename Get      // get(QueryT) -> ResultT
>
struct TreeMoAlgorithmWithUpdates {
    TreeMoAlgorithmWithUpdates(const vector<vector<int>>& _g, int root)
            : n(_g.size()), g(_g),
            parent(n), depth(n), sz(n),
            dfs_number(0), nxt(n), in(n), out(n), flattened(n * 2)
    {
        assert(0 <= root && root < n);

        // init parent, depth, sz
        // also move most heavy child of u to g[u][0]
        depth[root] = 0;
        dfs_sz(root, -1);

        // init nxt, in, out
        nxt[root] = root;
        dfs_hld(root);
    }

    vector<ResultT> solve(
            const vector<QueryT>& orig_queries,
            Add add, Rem rem, Update update, Get get) {
        // Separate update and get queries
        vector<TreeUpdate> updates;
        vector<TreeGet> gets;
        for (const auto& query : orig_queries) {
            if (query.typ == QueryType::GET) {
                int u = query.u, v = query.v;
                assert(0 <= u && u < n);
                assert(0 <= v && v < n);
                if (in[u] > in[v]) swap(u, v);
                assert(in[u] <= in[v]);

                int p = lca(u, v);

                gets.push_back(TreeGet {
                    p,
                    p == u ? in[u] : out[u],
                    in[v],
                    u,
                    query.id,
                });
            } else {
                updates.push_back(TreeUpdate {
                    query.u,
                    query.new_val,
                    query.old_val,
                    query.id,
                });
            }
        }

        // Sort queries
        int S = max<int> (1, cbrtl(n + 0.5));
        S = S * S;
        std::sort(gets.begin(), gets.end(), [&] (const TreeGet& q1, const TreeGet& q2) {
            int l1 = q1.l / S;
            int l2 = q2.l / S;
            if (l1 != l2) return l1 < l2;

            int r1 = q1.r / S;
            int r2 = q2.r / S;
            if (r1 != r2) return (l1 % 2 == 0) ? r1 < r2 : r1 > r2;

            return (r1 % 2 == 0)
                    ? q1.id < q2.id
                    : q1.id > q2.id;
        });

        // Process queries
        vector<ResultT> res(orig_queries.size());
        int cur_l = -1, cur_r = -1, cur_update = -1;
        for (const auto& query : gets) {
            // move to [l, r]
            if (cur_l < 0) {
                for (int i = query.l; i <= query.r; ++i) add(flattened[i]);
                cur_l = query.l, cur_r = query.r;
            } else {
                while (cur_l > query.l) add(flattened[--cur_l]);
                while (cur_r < query.r) add(flattened[++cur_r]);
                while (cur_r > query.r) rem(flattened[cur_r--]);
                while (cur_l < query.l) rem(flattened[cur_l++]);
            }
            
            // process updates
            // should we update more?
            while (cur_update + 1 < (int) updates.size()
                    && updates[cur_update + 1].id < query.id) {
                ++cur_update;
                update(
                    updates[cur_update].u,
                    updates[cur_update].old_val,
                    updates[cur_update].new_val,
                    cur_l, cur_r);
            }
            // should we update less?
            while (cur_update >= 0 && updates[cur_update].id > query.id) {
                update(
                    updates[cur_update].u,
                    updates[cur_update].new_val,
                    updates[cur_update].old_val,
                    cur_l, cur_r);
                --cur_update;
            }

            if (query.p != query.u) add(query.p);

            res[query.id] = get(orig_queries[query.id]);

            if (query.p != query.u) rem(query.p);
        }
        return res;
    }

    struct TreeGet {
        int p;
        int l, r, u;
        int id;
    };
    struct TreeUpdate {
        int u;
        int new_val, old_val;
        int id;
    };

    int lca(int u, int v) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        while (true) {
            if (in[u] > in[v]) swap(u, v); // in[u] <= in[v]
            if (nxt[u] == nxt[v]) return u;
            v = parent[nxt[v]];
        }
    }

    int n;
    vector<vector<int>> g;
    vector<int> parent;
    vector<int> depth;
    vector<int> sz;
    int dfs_number;
    vector<int> nxt;

    vector<int> in, out;
    vector<int> flattened;

    void dfs_sz(int u, int fu) {
        parent[u] = fu;
        sz[u] = 1;
        // remove parent from adjacency list
        auto it = std::find(g[u].begin(), g[u].end(), fu);
        if (it != g[u].end()) g[u].erase(it);

        for (int& v : g[u]) {
            depth[v] = depth[u] + 1;
            dfs_sz(v, u);

            sz[u] += sz[v];
            if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
        }
    }

    void dfs_hld(int u) {
        flattened[in[u] = dfs_number++] = u;
        for (int v : g[u]) {
            nxt[v] = (v == g[u][0] ? nxt[u] : v);
            dfs_hld(v);
        }
        flattened[out[u] = dfs_number++] = u;
    }
};
// }}}

// Example query type
enum QueryType { GET = 0, UPDATE = 1 };
 
struct Query {
    int u, v;              // For get: path u -> v
    int new_val, old_val;  // For update: set a[u] = val (old value = old_val)
    int id;
    QueryType typ;
};
