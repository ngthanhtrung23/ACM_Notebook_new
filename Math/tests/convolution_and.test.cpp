#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include <bits/stdc++.h>
using namespace std;

#include "../Polynomial/xorFFT.h"

long long a[1<<20], b[1<<20];
const int MOD = 998244353;

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    n = 1 << n;
    REP(i,n) cin >> a[i];
    REP(i,n) cin >> b[i];

    andFFT(a, n, MOD, 0);
    andFFT(b, n, MOD, 0);
    REP(i,n) a[i] = a[i] * b[i] % MOD;

    andFFT(a, n, MOD, 1);

    REP(i,n) cout << a[i] << ' ';
    cout << endl;

    return 0;
}
