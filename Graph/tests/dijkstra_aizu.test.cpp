#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "../dijkstra.h"

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, start; cin >> n >> m >> start;
    vector< vector<pair<int, ll>> > g(n);
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
    auto [dist, trace] = dijkstra(g, start);
    for (auto d : dist) {
        if (d == INF) cout << "INF\n";
        else cout << d << '\n';
    }
    return 0;
}
