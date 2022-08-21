#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../Math/modint.h"
#include "../splay_tree.h"

using modular = ModInt<998244353>;

struct S {
    long long sum, sz;
};
struct F {
    long long a, b;
};
using Node = node_t<int, S, F>;

const int MOD = 998244353;
S op(S left, int key, S right) {
    return S {
        (left.sum + key + right.sum) % MOD,
        left.sz + 1 + right.sz,
    };
}
pair<int, S> e() {
    return {0, {0, 0}};
}
pair<int, S> mapping(F f, Node* node) {
    return {
        (f.a * node->key + f.b) % MOD,
        S {
            (f.a * node->data.sum + f.b * node->data.sz) % MOD,
            node->data.sz,
        }
    };
}
F composition(F f, F g) {
    return F {
        f.a * g.a % MOD,
        (f.a * g.b + f.b) % MOD,
    };
}
F id() {
    return F {1, 0};
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> keys(n);
    for (auto& key : keys) cin >> key;

    SplayTreeById<
        int,
        S,
        op,
        e,
        F,
        mapping,
        composition,
        id
    > tree(keys);

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int pos, val; cin >> pos >> val;
            tree.insert(pos, val);
        } else if (typ == 1) {
            int pos; cin >> pos;
            tree.erase(pos);
        } else if (typ == 2) {
            int l, r; cin >> l >> r;
            tree.reverse(l, r);
        } else if (typ == 3) {
            int l, r, a, b; cin >> l >> r >> a >> b;
            tree.apply(l, r, F{a, b});
        } else {
            assert(typ == 4);
            int l, r; cin >> l >> r;
            printf("%lld\n", tree.prod(l, r).sum);
        }
    }
    return 0;
}
