#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <bits/stdc++.h>
using namespace std;

#include "../Polynomial/NTT_chemthan.h"

NTT<998244353, 1<<20> ntt;

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n); REP(i,n) cin >> a[i];
    vector<int> b(m); REP(i,m) cin >> b[i];

    auto c = ntt.multiply(a, b);
    for (int x : c) cout << x << ' ';
    cout << endl;
    return 0;
}
