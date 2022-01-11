#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include "../../template.h"
#include "../tree_diameter.h"

void solve() {
    int n; cin >> n;
    vector<vector<pair<int,int>>> g(n);
    REP(i,n-1) {
        int u, v, cost; cin >> u >> v >> cost;
        g[u].emplace_back(v, cost);
        g[v].emplace_back(u, cost);
    }

    auto [length, path] = get_diameter(g);
    cout << length << endl;
}
