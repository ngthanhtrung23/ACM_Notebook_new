#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include "../../template.h"
#include "../SegTree2D.h"

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for (auto& [x, y] : a) cin >> x >> y;

    SegTree2D<long long, SumSegTreeOp::op, SumSegTreeOp::e, int> st(a);

    for (auto p : a) st.set(p, 1);

    int q; cin >> q;
    while (q--) {
        pair<int,int> lo, hi;
        cin >> lo.first >> hi.first >> lo.second >> hi.second;
        ++hi.first;
        ++hi.second;
        cout << st.prod(lo, hi) << '\n';
    }
}
