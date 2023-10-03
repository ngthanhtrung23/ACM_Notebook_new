#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../template.h"
#include "../Mo/MoAlgorithm.h"

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); REP(i,n) cin >> a[i];

    vector<Query> queries(q);
    REP(i,q) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].r--;
    }

    int64_t sum = 0;
    auto add = [&] (int id) { sum += a[id]; };
    auto rem = [&] (int id) { sum -= a[id]; };
    auto get = [&] ([[maybe_unused]] const Query& _) { return sum; };

    auto res = mo<Query, int64_t, decltype(add), decltype(rem), decltype(get)>
        (n, queries, add, rem, get);
    for (auto r : res) cout << r << '\n';
}
