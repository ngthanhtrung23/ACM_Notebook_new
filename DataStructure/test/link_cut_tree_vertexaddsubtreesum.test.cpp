#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum"

#include <bits/stdc++.h>
using namespace std;

using T = long long;
#include "../LinkCutTree.h"

#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    LinkCut tree(n);
    FOR(i,1,n) {
        int x; cin >> x;
        tree.set(i, x);
    }
    REP(i,n-1) {
        int u, v; cin >> u >> v;
        ++u; ++v;
        tree.link(u, v);
    }

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {  // delete (u, v), add(w, x)
            int u, v, w, x; cin >> u >> v >> w >> x;
            ++u; ++v;
            ++w; ++x;
            tree.cut(u, v);
            tree.link(w, x);
        } else if (typ == 1) {  // a[p] += x
            int p, x; cin >> p >> x;
            ++p;
            tree.set(p, tree.get(p) + x);
        } else if (typ == 2) {  // get sum of subtree(u). v is parent of u
            int u, v; cin >> u >> v;
            ++u; ++v;
            cout << tree.getSubtree(u, v) << '\n';
        }
    }
    return 0;
}

