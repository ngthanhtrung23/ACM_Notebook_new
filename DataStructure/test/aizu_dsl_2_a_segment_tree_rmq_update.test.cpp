#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../../template.h"
#include "../SegTree.h"

void solve() {
    int n, q; cin >> n >> q;
    SegTree<int, MinSegTreeOp::op, MinSegTreeOp::e> st(n);
    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int pos, val; cin >> pos >> val;
            st.set(pos, val);
        } else {
            int l, r; cin >> l >> r;
            cout << st.prod(l, r+1) << '\n';
        }
    }
}
