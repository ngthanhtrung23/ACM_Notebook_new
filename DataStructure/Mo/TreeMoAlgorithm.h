// NOTE:
// - Query type must be a pair of vertices: <u, v>, specifying a path from u -> v
// - Add / Rem functions:
//   - If ids appear twice -> MUST treat as 0 time
//
// Resource:
// - https://codeforces.com/blog/entry/43230
//
// Tested:
// - https://www.spoj.com/problems/COT2/
//
// Mo's algorithm on tree {{{
template<typename ResultT, typename Add, typename Rem, typename Get>
struct TreeMoAlgorithm {
    TreeMoAlgorithm(const vector<vector<int>>& _g, int root)
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
            const vector<pair<int,int>>& orig_queries,
            Add add, Rem rem, Get get) {
        int q = orig_queries.size();
        vector<ResultT> res(q);

        // Convert to tree queries
        vector<TreeQuery> queries(q);
        for (int i = 0; i < q; ++i) {
            auto [u, v] = orig_queries[i];
            assert(0 <= u && u < n);
            assert(0 <= v && v < n);

            if (in[u] > in[v]) swap(u, v);
            assert(in[u] <= in[v]);

            queries[i].p = lca(u, v);
            if (queries[i].p == u) queries[i].l = in[u], queries[i].r = in[v];
            else queries[i].l = out[u], queries[i].r = in[v];
            queries[i].u = u;
        }
     
        // Sort queries in increasing order of (left / SQRT, right)
        int S = sqrt(n);
        if (S < 1) S = 1;
     
        vector<int> query_ids(q);
        std::iota(query_ids.begin(), query_ids.end(), 0);
        std::sort(query_ids.begin(), query_ids.end(), [&] (int q1, int q2) {
            int bucket1 = queries[q1].l / S;
            int bucket2 = queries[q2].l / S;
            if (bucket1 != bucket2) return bucket1 < bucket2;
            else {
                return bucket1 % 2
                        ? (queries[q1].r > queries[q2].r)
                        : (queries[q1].r < queries[q2].r);
            }
        });

        // Answer queries
        int cur_l = -1, cur_r = -1;
        for (int qid : query_ids) {
            // move to this range
            if (cur_l < 0) {
                for (int i = queries[qid].l; i <= queries[qid].r; ++i) {
                    add(flattened[i]);
                }
                cur_l = queries[qid].l, cur_r = queries[qid].r;
            } else {
                while (cur_l > queries[qid].l) add(flattened[--cur_l]);
                while (cur_r < queries[qid].r) add(flattened[++cur_r]);
                while (cur_r > queries[qid].r) rem(flattened[cur_r--]);
                while (cur_l < queries[qid].l) rem(flattened[cur_l++]);
            }

            if (queries[qid].p != queries[qid].u) add(queries[qid].p);

            res[qid] = get(orig_queries[qid]);

            if (queries[qid].p != queries[qid].u) rem(queries[qid].p);
        }
        return res;
    }

    struct TreeQuery {
        int p;
        int l, r, u;
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
