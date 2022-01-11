#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../../template.h"
#include "../SegTree.h"

void solve() {
    int n, q; cin >> n >> q;
    SegTree<long long, SumSegTreeOp::op, SumSegTreeOp::e> st(n);
    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int pos, val; cin >> pos >> val;
            --pos;
            st.set(pos, st.get(pos) + val);
        } else {
            int l, r; cin >> l >> r;
            --l;
            cout << st.prod(l, r) << '\n';
        }
    }
}
