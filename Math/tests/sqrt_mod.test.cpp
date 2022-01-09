#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <bits/stdc++.h>
using namespace std;

// for 64-bit, use mt19937_64
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_rand(long long r) {
    return uniform_int_distribution<long long> (0, r-1)(rng);
}

#include "../NumberTheory/SqrtMod.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        long long n, p; cin >> n >> p;
        long long res = sqrtMod(n, p);
        cout << res << '\n';
    }
    return 0;
}
