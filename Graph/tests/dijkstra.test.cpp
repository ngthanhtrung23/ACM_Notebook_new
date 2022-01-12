#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>
using namespace std;

#include "../dijkstra.h"

#define SZ(x) ((int)(x).size())
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, s, t; cin >> n >> m >> s >> t;

    // read edges
    vector<vector<pair<int,ll>>> g(n);
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    // output
    auto [dist, path] = dijkstra(g, s, t);
    if (dist == INF) {
        cout << -1 << endl;
        return 0;
    }

    cout << dist << ' ' << SZ(path) - 1 << '\n';
    REP(i,SZ(path)-1) {
        cout << path[i] << ' ' << path[i+1] << '\n';
    }
    return 0;
}
