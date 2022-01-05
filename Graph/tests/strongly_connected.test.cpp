#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>
using namespace std;

#include "../DfsTree/StronglyConnected.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
#define SZ(x) ((int)(x).size())

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    REP(i,m) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    DirectedDfs tree(g);

    reverse(tree.scc.begin(), tree.scc.end());
    cout << SZ(tree.scc) << endl;
    for (auto comp : tree.scc) {
        cout << comp.size();
        for (int x : comp) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}
