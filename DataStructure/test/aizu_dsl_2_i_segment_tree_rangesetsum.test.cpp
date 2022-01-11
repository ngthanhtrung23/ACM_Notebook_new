#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include "../../template.h"
#include "../LazySegTree.h"

void solve() {
    int n, q; cin >> n >> q;
    vector<RangeSetAddMinSumOps::S> nodes;
    REP(i,n) nodes.push_back(RangeSetAddMinSumOps::S{0, 0, 1});
    LazySegTree<
        RangeSetAddMinSumOps::S,
        RangeSetAddMinSumOps::op,
        RangeSetAddMinSumOps::e,
        RangeSetAddMinSumOps::F,
        RangeSetAddMinSumOps::mapping,
        RangeSetAddMinSumOps::composition,
        RangeSetAddMinSumOps::id
    > st(nodes);
    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int l, r, val; cin >> l >> r >> val;
            ++r;
            st.apply(l, r, RangeSetAddMinSumOps::F { val, 0 });
        } else {
            int l, r; cin >> l >> r;
            ++r;
            cout << st.prod(l, r).sum << '\n';
        }
    }
}
