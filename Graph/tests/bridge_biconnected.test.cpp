#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <bits/stdc++.h>
using namespace std;

#include "../DfsTree/BridgeArticulation.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
#define SZ(x) ((int)(x).size())

void dfs(int u,
        const vector<vector<int>>& g,
        const set<pair<int,int>>& bridges,
        vector<int>& comp,
        vector<bool>& visited) {
    visited[u] = true;
    comp.push_back(u);

    for (int v : g[u]) {
        if (visited[v]) continue;
        if (bridges.count({v, u}) || bridges.count({u, v})) continue;

        dfs(v, g, bridges, comp, visited);
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    // read edges
    vector<vector<int>> g(n);
    REP(eid,m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    UndirectedDfs tree(g);
    set<pair<int,int>> bridges(tree.bridges.begin(), tree.bridges.end());

    vector<bool> visited(n, false);
    vector<vector<int>> components;
    REP(i,n) {
        if (!visited[i]) {
            vector<int> comp;
            dfs(i, g, bridges, comp, visited);
            components.push_back(comp);
        }
    }
    cout << SZ(components) << endl;
    for (auto&& comp : components) {
        cout << SZ(comp);
        for (int x : comp) cout << ' ' << x;
        cout << endl;
    }
    return 0;
}
