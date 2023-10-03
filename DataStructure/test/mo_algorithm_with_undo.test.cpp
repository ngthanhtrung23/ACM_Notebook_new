#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../template.h"
#include "../Mo/MoAlgorithmWithUndo.h"

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); REP(i,n) cin >> a[i];

    vector<Query> queries(q);
    REP(i,q) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].r--;
    }

    int64_t sum = 0;
    stack<int> nums;

    auto add = [&] (int id) {
        sum += a[id];
        nums.push(a[id]);
    };
    auto undo = [&] () {
        sum -= nums.top();
        nums.pop();
    };
    auto get = [&] ([[maybe_unused]] const Query& _) {
        return sum;
    };

    auto res = mo_with_undo<Query, int64_t, decltype(add), decltype(undo), decltype(get)>
        (n, queries, add, undo, get);
    for (auto r : res) cout << r << '\n';
}
