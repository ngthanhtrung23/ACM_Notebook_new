#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <bits/stdc++.h>
using namespace std;

#include "../WaveletMatrix.h"
#include "../../buffered_reader.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    WaveletMatrix<int> wm(a);
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        cout << wm.k_th(l, r, k) << '\n';
    }
    return 0;
}
