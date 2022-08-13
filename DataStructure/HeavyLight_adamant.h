// HeavyLight {{{
// Index from 0
// Best used with SegTree.h
//
// Usage:
// HLD hld(g, root);
// // build segment tree. Note that we must use hld.order[i]
// vector<T> nodes;
// for (int i = 0; i < n; i++)
//   nodes.push_back(initial_value[hld.order[i]])
// SegTree<S, op, e> st(nodes);
//
// // Update path
// hld.apply_path(from, to, is_edge_or_vertex, [&] (int l, int r) {
//   st.apply(l, r+1, F);
// });
//
// // Query path
// hld.prod_path_commutative<S, op, e> (from, to, is_edge_or_vertex, [&] (int l, int r) {
//   return st.prod(l, r+1);
// });
//
// Tested:
// - (vertex, path) https://judge.yosupo.jp/problem/vertex_add_path_sum
// - (vertex, path, non-commutative) https://judge.yosupo.jp/problem/vertex_set_path_composite
// - (vertex, subtree) https://judge.yosupo.jp/problem/vertex_add_subtree_sum
// - (vertex, path, non-commutative, 1-index) https://oj.vnoi.info/problem/icpc21_mt_l
// - (vertex, path) https://oj.vnoi.info/problem/qtree3
//
// - (edge, path) https://oj.vnoi.info/problem/qtreex
// - (edge, path) https://oj.vnoi.info/problem/lubenica
// - (edge, path) https://oj.vnoi.info/problem/pwalk
// - (edge, path, lazy) https://oj.vnoi.info/problem/kbuild
// - (edge, path, lazy) https://oj.vnoi.info/problem/onbridge
//
// - (lca) https://oj.vnoi.info/problem/fselect
// - (kth_parent) https://cses.fi/problemset/task/1687
struct HLD {
    HLD(const vector<vector<int>>& _g, int root)
            : n(_g.size()), g(_g),
            parent(n), depth(n), sz(n),
            dfs_number(0), nxt(n), in(n), out(n), order(n)
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

    int lca(int u, int v) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        while (true) {
            if (in[u] > in[v]) swap(u, v); // in[u] <= in[v]
            if (nxt[u] == nxt[v]) return u;
            v = parent[nxt[v]];
        }
    }

    // return k-th parent
    // if no such parent -> return -1
    int kth_parent(int u, int k) const {
        assert(0 <= u && u < n);
        if (depth[u] < k) return -1;

        while (true) {
            int v = nxt[u];
            if (in[u] - k >= in[v]) return order[in[u] - k];
            k -= in[u] - in[v] + 1;
            u = parent[v];
        }
    }

    // return k-th vertex on path from u -> v (0 <= k)
    // if k > distance -> return -1
    int kth_vertex_on_path(int u, int v, int k) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);

        int l = lca(u, v);
        int ul = depth[u] - depth[l];
        if (k <= ul) return kth_parent(u, k);
        k -= ul;
        int vl = depth[v] - depth[l];
        if (k <= vl) return kth_parent(v, vl - k);
        return -1;
    }

    int dist(int u, int v) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        int l = lca(u, v);
        return depth[u] + depth[v] - 2*depth[l];
    }

    // apply f on vertices on path [u, v]
    // edge = true -> apply on edge
    //
    // f(l, r) should update segment tree [l, r] INCLUSIVE
    void apply_path(int u, int v, bool edge, const function<void(int, int)> &f) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        if (u == v && edge) return;

        while (true) {
            if (in[u] > in[v]) swap(u, v); // in[u] <= in[v]
            if (nxt[u] == nxt[v]) break;
            f(in[nxt[v]], in[v]);
            v = parent[nxt[v]];
        }
        if (u == v && edge) return;
        f(in[u] + edge, in[v]);
    }

    // get prod of path u -> v
    // edge = true -> get on edges
    //
    // f(l, r) should query segment tree [l, r] INCLUSIVE
    // f must be commutative. For non-commutative, use getSegments below
    template<class S, S (*op) (S, S), S (*e)()>
    S prod_path_commutative(
            int u, int v, bool edge,
            const function<S(int, int)>& f) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        if (u == v && edge) {
            return e();
        }
        S su = e(), sv = e();
        while (true) {
            if (in[u] > in[v]) { swap(u, v); swap(su, sv); }
            if (nxt[u] == nxt[v]) break;
            sv = op(sv, f(in[nxt[v]], in[v]));
            v = parent[nxt[v]];
        }
        if (u == v && edge) {
            return op(su, sv);
        } else {
            return op(su, op(sv, f(in[u] + edge, in[v])));
        }
    }

    // f(l, r) modify seg_tree [l, r] INCLUSIVE
    void apply_subtree(int u, bool edge, const function<void(int, int)>& f) {
        assert(0 <= u && u < n);
        f(in[u] + edge, out[u] - 1);
    }

    // f(l, r) queries seg_tree [l, r] INCLUSIVE
    template<class S>
    S prod_subtree_commutative(int u, bool edge, const function<S(S, S)>& f) {
        assert(0 <= u && u < n);
        return f(in[u] + edge, out[u] - 1);
    }

    // Useful when functions are non-commutative
    // Return all segments on path from u -> v
    // For this problem, the order (u -> v is different from v -> u)
    vector< pair<int,int> > getSegments(int u, int v) const {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        vector< pair<int,int> > upFromU, upFromV;

        int fu = nxt[u], fv = nxt[v];
        while (fu != fv) {  // u and v are on different chains
            if (depth[fu] >= depth[fv]) { // move u up
                upFromU.push_back({u, fu});
                u = parent[fu];
                fu = nxt[u];
            } else { // move v up
                upFromV.push_back({fv, v});
                v = parent[fv];
                fv = nxt[v];
            }
        }
        upFromU.push_back({u, v});
        reverse(upFromV.begin(), upFromV.end());
        upFromU.insert(upFromU.end(), upFromV.begin(), upFromV.end());
        return upFromU;
    }

    // return true if u is ancestor
    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }

// private:
    int n;
    vector<vector<int>> g;
    vector<int> parent;   // par[u] = parent of u. par[root] = -1
    vector<int> depth;    // depth[u] = distance from root -> u
    vector<int> sz;       // sz[u] = size of subtree rooted at u
    int dfs_number;
    vector<int> nxt;      // nxt[u] = vertex on heavy path of u, nearest to root
    vector<int> in, out;  // subtree(u) is in range [in[u], out[u]-1]
    vector<int> order;    // euler tour

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
        order[dfs_number] = u;
        in[u] = dfs_number++;

        for (int v : g[u]) {
            nxt[v] = (v == g[u][0] ? nxt[u] : v);
            dfs_hld(v);
        }
        out[u] = dfs_number;
    }
};
// }}}
