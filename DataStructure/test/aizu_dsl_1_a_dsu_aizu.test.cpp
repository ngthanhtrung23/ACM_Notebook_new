#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "../DisjointSet.h"

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        int typ, x, y; cin >> typ >> x >> y;
        if (typ == 0) dsu.merge(x, y);
        else cout << dsu.same_component(x, y) << '\n';
    }
}
