#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../../template.h"
#include "../LazySegTree.h"
#include "../../Math/modint.h"
#include "../../buffered_reader.h"

using mint = ModInt<998244353>;

struct Node {
    mint sum, sz;
};
struct Lazy {
    mint a, b;
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

void solve() {
    int n = IO::get<int>();
    int q = IO::get<int>();
    vector<Node> nodes(n);
    REP(i,n) {
        nodes[i] = {IO::get<int>(), 1};
    }
    LazySegTree<Node, op, e, Lazy, apply, combine, id> st(nodes);
    while (q--) {
        int typ = IO::get<int>();
        if (typ == 1) {
            int pos = IO::get<int>();
            cout << st.get(pos).sum << '\n';
        } else {
            int l = IO::get<int>();
            int r = IO::get<int>();
            Lazy f;
            f.a = IO::get<int>();
            f.b = IO::get<int>();
            st.apply(l, r, f);
        }
    }
}
