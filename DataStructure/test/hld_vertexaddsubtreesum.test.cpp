#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../SegTree.h"
#include "../HeavyLight_adamant.h"

#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    REP(i,n) cin >> a[i];

    vector<vector<int>> g(n);
    FOR(i,1,n-1) {
        int p; cin >> p;
        g[p].push_back(i);
    }

    HLD hld(g, 0);

    vector<long long> nodes;
    REP(i,n) {
        nodes.push_back(a[hld.order[i]]);
    }
    SegTree<long long, SumSegTreeOp::op, SumSegTreeOp::e> tree(nodes);

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int p, x; cin >> p >> x;
            tree.set(hld.in[p], tree.get(hld.in[p]) + x);
        } else {
            int u; cin >> u;
            cout << hld.prod_subtree_commutative<long long> (
                    u, false,
                    [&] (int l, int r) {
                        return tree.prod(l, r + 1);
                    }) << '\n';
        }
    }
    return 0;
}
