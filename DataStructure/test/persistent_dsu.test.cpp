#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../DSU_persistent.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;

    PersistentDSU dsu(n);

    while (q--) {
        int typ, version; cin >> typ >> version;
        int u, v; cin >> u >> v;

        if (typ == 0) {
            dsu.merge(version + 1, u, v);
        } else {
            // create extra version, since the input format requires it..
            dsu.merge(version + 1, 0, 0);
            cout << dsu.same_component(version + 1, u, v) << '\n';
        }
    }
    return 0;
}
