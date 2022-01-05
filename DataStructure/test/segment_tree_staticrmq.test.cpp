#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>
using namespace std;

#include "../SegTree.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    REP(i,n) cin >> a[i];

    SegTree<int, MinSegTreeOp::op, MinSegTreeOp::e> st(a);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.prod(l, r) << '\n';
    }
    return 0;
}
