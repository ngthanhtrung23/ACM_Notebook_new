#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <bits/stdc++.h>
using namespace std;

#include "../WaveletMatrix.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    WaveletMatrix<int> wm(a);
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        cout << wm.range_count(l, r, x, x+1) << '\n';
    }
    return 0;
}
