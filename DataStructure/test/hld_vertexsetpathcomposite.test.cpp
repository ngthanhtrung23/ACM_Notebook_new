#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <bits/stdc++.h>
using namespace std;

#include "../SegTree.h"
#include "../../Math/modint.h"
#include "../HeavyLight_adamant.h"

using modular = ModInt<998244353>;

// SegTree ops
struct F {
    modular a, b;
};
F op(const F& l, const F& r) {
    return F{
        l.a*r.a,
        r.a*l.b + r.b
    };
}

struct Node {
    F forward, backward;
};

Node op(Node l, Node r) {
    return Node {
        op(l.forward, r.forward),
        op(r.backward, l.backward)
    };
}

Node e() {
    return Node {
        F{1, 0},
        F{1, 0}
    };
}

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<F> fs(n);
    REP(i,n) {
        int a, b; cin >> a >> b;
        fs[i] = {a, b};
    }

    vector<vector<int>> g(n);
    REP(i,n-1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    HLD hld(g, 0);

    vector<Node> nodes;
    REP(i,n) {
        auto f = fs[hld.order[i]];
        nodes.push_back({f, f});
    }
    SegTree<Node, op, e> tree(nodes);

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int p, a, b; cin >> p >> a >> b;
            tree.set(hld.in[p], {{a, b}, {a, b}});
        } else {
            int start, end, x; cin >> start >> end >> x;

            auto segments = hld.getSegments(start, end);
            F res {1, 0};
            for (auto [u, v] : segments) {
                if (hld.in[u] <= hld.in[v]) {
                    res = op(res, tree.prod(hld.in[u], hld.in[v] + 1).forward);
                } else {
                    res = op(res, tree.prod(hld.in[v], hld.in[u] + 1).backward);
                }
            }
            cout << (res.a * modular(x) + res.b) << '\n';
        }
    }
    return 0;
}
