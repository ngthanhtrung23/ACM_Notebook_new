#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"

#include "../../template.h"
#include "../LazySegTree.h"
#include "../HeavyLight_adamant.h"

using ll = long long;
struct S {
    ll sum, sz;
};

S op(S l, S r) {
    return S { l.sum + r.sum, l.sz + r.sz };
}
S e() { return S {0, 0}; }

S mapping(ll f, S s) {
    return S { s.sum + s.sz * f, s.sz };
}
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }


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
    vector<S> nodes;
    for (int i = 0; i < n; i++) nodes.push_back(S{0, 1});
    LazySegTree<S, op, e, ll, mapping, composition, id> st(nodes);

    int q; cin >> q;
    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int u, val; cin >> u >> val;
            hld.apply_path(u, 0, true, [&] (int l, int r) {
                st.apply(l, r + 1, val);
            });
        } else {
            int u; cin >> u;
            cout << hld.prod_path_commutative<S, op, e>(
                    0, u, true, [&] (int l, int r) {
                        return st.prod(l, r+1);
                    }).sum << '\n';
        }
    }
}
