#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <bits/stdc++.h>
using namespace std;

#include "../DfsTree/StronglyConnected.h"

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    DirectedDfs tree(g);

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << (tree.comp_ids[u] == tree.comp_ids[v]) << '\n';
    }
}
