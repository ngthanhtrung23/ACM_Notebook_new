#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <bits/stdc++.h>
using namespace std;

#include "../modint.h"
#include "../Polynomial/NTT.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
using mint = ModInt<1'000'000'007>;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<mint> a(n); REP(i,n) cin >> a[i];
    vector<mint> b(m); REP(i,m) cin >> b[i];

    auto c = multiply(a, b);
    for (const auto& val : c) cout << val << ' ';
    cout << endl;
    return 0;
}
