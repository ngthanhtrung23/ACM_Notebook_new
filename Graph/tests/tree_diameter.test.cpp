#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <bits/stdc++.h>
using namespace std;

#include "../tree_diameter.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
#define SZ(x) ((int)(x).size())

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<pair<int,int>>> g(n);
    REP(i,n-1) {
        int u, v, cost; cin >> u >> v >> cost;
        g[u].emplace_back(v, cost);
        g[v].emplace_back(u, cost);
    }

    auto [length, path] = get_diameter(g);
    cout << length << ' ' << SZ(path) << endl;
    for (int x : path) cout << x << ' ';
    cout << endl;
    return 0;
}
