#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../LazySegTree.h"
#include "../../Math/modint.h"
#include "../../buffered_reader.h"

using modular = ModInt<998244353>;

struct Node {
    modular sum, sz;
};
struct Lazy {
    modular a, b;
};

Node op(Node l, Node r) {
    return Node {
        l.sum + r.sum,
        l.sz + r.sz
    };
}
Node e() {
    return Node{0, 0};
}

Node apply(Lazy f, Node node) {
    return Node{
        f.a * node.sum + f.b * node.sz,
        node.sz
    };
}
Lazy combine(Lazy g, Lazy f) {
    return Lazy {
        f.a * g.a,
        g.a * f.b + g.b
    };
}
Lazy id() {
    return Lazy{1, 0};
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<Node> nodes(n);
    for (auto& node : nodes) {
        cin >> node.sum;
        node.sz = 1;
    }
    LazySegTree<Node, op, e, Lazy, apply, combine, id> st(nodes);

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int l, r;
            Lazy f;
            cin >> l >> r >> f.a >> f.b;
            st.apply(l, r, f);
        } else {
            int l, r; cin >> l >> r;
            cout << st.prod(l, r).sum << '\n';
        }
    }
    return 0;
}
