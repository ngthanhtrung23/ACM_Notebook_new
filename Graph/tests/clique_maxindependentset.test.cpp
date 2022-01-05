#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include <bits/stdc++.h>
using namespace std;

#include "../MaxClique.h"

bool edge[44][44];

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    REP(i,m) {
        int u, v; cin >> u >> v;
        edge[u][v] = edge[v][u] = 1;
    }

    MaxClique g(n);
    REP(i,n) REP(j,n) if (!edge[i][j] && i != j) {
        g.addEdge(i, j);
    }

    auto res = g.solve();
    cout << res.size() << endl;
    for (int x : res) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
