#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../DisjointSet.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        int typ, u, v; cin >> typ >> u >> v;
        if (typ == 0) dsu.merge(u, v);
        else {
            cout << (dsu.getRoot(u) == dsu.getRoot(v) ? 1 : 0) << '\n';
        }
    }
    return 0;
}
