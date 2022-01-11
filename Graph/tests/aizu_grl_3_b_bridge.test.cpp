#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <bits/stdc++.h>
using namespace std;

#include "../DfsTree/BridgeArticulation.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    REP(i,m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    UndirectedDfs tree(g);
    auto bridges = tree.bridges;

    for (auto& [u, v] : bridges) {
        if (u > v) swap(u, v);
    }
    sort(bridges.begin(), bridges.end());

    for (auto [u, v] : bridges) {
        cout << u << ' ' << v << endl;
    }
}
