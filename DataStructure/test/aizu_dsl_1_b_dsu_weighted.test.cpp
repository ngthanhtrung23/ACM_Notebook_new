#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include "../../template.h"
#include "../DSU_weighted.h"

void solve() {
    int n, q; cin >> n >> q;
    WeightedDSU<long long> dsu(n);
    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int x, y, z; cin >> x >> y >> z;
            // f[y] = f[x] + z
            dsu.merge(x, y, z);
        } else {
            int x, y; cin >> x >> y;
            if (dsu.getRoot(x) == dsu.getRoot(y)) {
                cout << dsu.weight(y) - dsu.weight(x) << '\n';
            } else {
                cout << "?\n";
            }
        }
    }
}
