#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../SegTree.h"
#include "../../buffered_reader.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    SegTree<long long, SumSegTreeOp::op, SumSegTreeOp::e> seg_tree(a);

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int pos, val; cin >> pos >> val;
            seg_tree.set(pos, seg_tree.get(pos) + val);
        } else {
            int l, r; cin >> l >> r;
            cout << seg_tree.prod(l, r) << '\n';
        }
    }
    return 0;
}
