#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <bits/stdc++.h>
using namespace std;

#include "../Fenwick.h"

int main() {
    int n, q; cin >> n >> q;
    Fenwick<long long> bit(n);
    while (q--) {
        int typ, x, y; cin >> typ >> x >> y;
        --x;
        if (typ == 0) bit.update(x, y);
        else cout << bit.get(x, y) << '\n';
    }
}
