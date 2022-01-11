#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include "../../template.h"
#include "../DfsTree/StronglyConnected.h"

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    DirectedDfs tree(g);
    for (auto comp : tree.scc) {
        if (comp.size() > 1) {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}
