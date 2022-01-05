#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"

#include <bits/stdc++.h>
using namespace std;

#include "../nim_product.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        ull x, y; cin >> x >> y;
        cout << mult(x, y) << '\n';
    }
    return 0;
}
