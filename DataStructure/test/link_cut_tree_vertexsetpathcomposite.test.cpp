#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include <bits/stdc++.h>
using namespace std;

#include "../../Math/modint.h"
using modular = ModInt<998244353>;

#define PATH_QUERIES_ONLY
struct T {
    modular a, b;

    T() : a(1), b(0) {}
    T(modular _a, modular _b) : a(_a), b(_b) {}

    // return f(g())
    T operator + (const T& g) const {
        return T {
            a * g.a,
            a * g.b + b,
        };
    }

    T operator += (const T& g) {
        b = a * g.b + b;
        a = a * g.a;
        return *this;
    }
};
#include "../LinkCutTree.h"

#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    LinkCut tree(n);

    FOR(i,1,n) {
        modular a, b; cin >> a >> b;
        tree.set(i, T{a, b});
    }

    REP(i,n-1) {
        int u, v; cin >> u >> v;
        ++u; ++v;
        tree.link(u, v);
    }

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {  // remove (u, v), add (w, x)
            int u, v, w, x; cin >> u >> v >> w >> x;
            ++u; ++v;
            ++w; ++x;
            tree.cut(u, v);
            tree.link(w, x);
        } else if (typ == 1) {  // set f(p) = cx + d
            int p; cin >> p;
            ++p;
            modular c, d; cin >> c >> d;
            tree.set(p, T{c, d});
        } else if (typ == 2) {  // get path (u, v) and apply f(x)
            int u, v; cin >> u >> v;
            ++u; ++v;
            modular x; cin >> x;

            auto f = tree.getPath(u, v);
            cout << f.a * x + f.b << '\n';
        }
    }
    return 0;
}
