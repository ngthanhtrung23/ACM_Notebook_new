#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../Fenwick2D.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;

    vector<Query<long long>> queries;
    REP(i,n) {
        int x, y, val; cin >> x >> y >> val;
        queries.push_back({Query<long long>::ADD, x, y, -1, -1, val});
    }

    REP(i,q) {
        int typ; cin >> typ;
        if (typ == 0) {
            int x, y, val; cin >> x >> y >> val;
            queries.push_back({Query<long long>::ADD, x, y, -1, -1, val});
        } else {
            int x, y, x2, y2; cin >> x >> y >> x2 >> y2;
            queries.push_back({Query<long long>::QUERY, x, y, x2, y2, 0});
        }
    }

    Fenwick2D<long long> f;
    auto res = f.solve(queries);
    for (auto r : res) cout << r << '\n';
    return 0;
}
