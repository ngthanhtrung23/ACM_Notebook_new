#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include "../../template.h"
#include "../SegTree.h"
#include "../HeavyLight_adamant.h"

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    REP(i,n) {
        int k; cin >> k;
        while (k--) {
            int j; cin >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    HLD hld(adj, 0);
    SegTree<ll, SumSegTreeOp::op, SumSegTreeOp::e> st(n);

    int q; cin >> q;
    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int u, val; cin >> u >> val;
            hld.apply_path(u, hld.parent[u], true, [&] (int l, int r) {
                st.set(l, st.get(l) + val);
            });
        } else {
            int u; cin >> u;
            cout << hld.prod_path_commutative<ll, SumSegTreeOp::op, SumSegTreeOp::e>(
                    0, u, true, [&] (int l, int r) {
                        return st.prod(l, r+1);
                    }) << '\n';
        }
    }
}
