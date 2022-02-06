#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include "../../template.h"
#include "../LCA.h"

void solve() {
    ios::sync_with_stdio(0); cin.tie(0);
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

    LCA lca(n, adj, 0);

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca.lca(u, v) << '\n';
    }
}
