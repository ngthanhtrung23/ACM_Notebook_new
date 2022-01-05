#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <bits/stdc++.h>
using namespace std;

// for 64-bit, use mt19937_64
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_rand(long long r) {
    return uniform_int_distribution<long long> (0, r-1)(rng);
}

#include "../NumberTheory/Pollard.h"

int32_t main() {
    int ntest; cin >> ntest;
    while (ntest--) {
        int n; cin >> n;
        auto f = factorize(n);
        cout << f.size();
        for (auto x : f) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}
