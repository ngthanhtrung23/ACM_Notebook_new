#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <bits/stdc++.h>
using namespace std;

#include "../LiChaoSegTree.h"

using ll = long long;
struct Query {
    int typ;
    ll l, r, a, b;
};

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;

    vector<Query> queries;
    vector<ll> xs;

    while (n--) {
        ll l, r, a, b; cin >> l >> r >> a >> b;
        queries.push_back({0, l, r, a, b});
    }

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            ll l, r, a, b; cin >> l >> r >> a >> b;
            queries.push_back({0, l, r, a, b});
        } else {
            ll x; cin >> x;
            queries.push_back({1, x, 0, 0, 0});
            xs.push_back(x);
        }
    }
    LiChao<ll, __int128_t> tree(xs);

    for (auto [typ, l, r, a, b] : queries) {
        if (typ == 0) {
            tree.add_segment(l, r, a, b, 0);
        } else {
            auto res = tree.get(l);
            if (res.is_valid) {
                cout << (long long) res.minval << '\n';
            } else {
                cout << "INFINITY\n";
            }
        }
    }
    return 0;
}
