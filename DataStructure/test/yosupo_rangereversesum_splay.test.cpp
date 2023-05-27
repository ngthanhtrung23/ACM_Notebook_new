#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../../template.h"
#include "../splay_tree.h"

using S = int64_t;
using F = bool;
using Node = node_t<int, S, F>;

S op(S left, int key, S right) {
    return left + key + right;
}
pair<int, S> e() { return {0, 0}; }
pair<int, S> mapping([[maybe_unused]] F f, Node* node) {
    return {node->key, node->data};
}
F composition([[maybe_unused]] F f, [[maybe_unused]] F g) { return false; }
F id() { return false; }

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); REP(i,n) cin >> a[i];
    SplayTreeById<int, S, op, e, F, mapping, composition, id> tree(a);

    while (q--) {
        int typ; cin >> typ;
        int l, r; cin >> l >> r;

        if (typ == 0) tree.reverse(l, r);
        else {
            cout << tree.prod(l, r) << '\n';
        }
    }
}
