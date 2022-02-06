// LCA
// Notes:
// - Index from 0
// - Cannot use for queries like min edge in path u -> v
//
// Tested:
// - https://judge.yosupo.jp/problem/lca
#include "RMQ.h"
struct LCA {
    const int n;
    vector<vector<int>> adj;
    const int root;
    using P = pair<int,int>;
    static P f(P x, P y) { return std::min(x, y); }

    LCA(int _n, const vector<vector<int>>& _adj, int _root)
            : n(_n), adj(_adj), root(_root) {
        assert(0 <= root && root < n);
        id.resize(n);
        depth.resize(n);
        order.reserve(2 * n);
        dfs(root, -1, 0);
        rmq = RMQ<P, f>(order);
    }

    int lca(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);

        int x = id[u], y = id[v];
        if (x > y) std::swap(x, y);
        return rmq.get(x, y+1).second;
    }

// private:
    vector<int> id, depth;
    vector<P> order;
    RMQ<P, f> rmq;

    void dfs(int u, int fu, int d) {
        id[u] = order.size();
        depth[u] = d;
        order.emplace_back(d, u);
        for (int v : adj[u]) {
            if (v == fu) continue;
            dfs(v, u, d + 1);
            order.emplace_back(d, u);
        }
    }
};
