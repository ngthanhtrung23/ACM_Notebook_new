#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <bits/stdc++.h>
using namespace std;

#include "../find_triangles.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<long long> xs(n);
    REP(i,n) cin >> xs[i];

    vector<pair<int,int>> edges(m);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
    }

    auto res = find_all_triangles(n, edges);
    long long sum = 0;
    const int MOD = 998244353;
    for (auto [i, j, k] : res) {
        sum = (sum + xs[i] * xs[j] % MOD * xs[k]) % MOD;
    }
    cout << sum << endl;
    return 0;
}
