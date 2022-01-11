#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include "../../template.h"
#include "../DfsTree/BridgeArticulation.h"

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    REP(i,m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    UndirectedDfs tree(g);
    auto res = tree.articulation_points;
    sort(res.begin(), res.end());
    for (int r : res) cout << r << '\n';
}
