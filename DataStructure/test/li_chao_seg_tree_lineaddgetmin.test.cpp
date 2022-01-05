#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <bits/stdc++.h>
using namespace std;

#include "../LiChaoSegTree.h"

using ll = long long;
struct Query {
    int typ;
    ll a, b;
};

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;

    vector<Query> queries;
    vector<ll> xs;

    while (n--) {
        ll a, b; cin >> a >> b;
        queries.push_back({0, a, b});
    }

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            ll a, b; cin >> a >> b;
            queries.push_back({0, a, b});
        } else {
            ll x; cin >> x;
            queries.push_back({1, x, 0});
            xs.push_back(x);
        }
    }
    LiChao<ll, __int128_t> tree(xs);

    for (auto [typ, a, b] : queries) {
        if (typ == 0) {
            tree.add_line(a, b, 0);
        } else {
            auto res = tree.get(a);
            assert(res.is_valid);
            cout << (long long) res.minval << '\n';
        }
    }
    return 0;
}
