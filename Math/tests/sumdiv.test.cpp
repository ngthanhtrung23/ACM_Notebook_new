#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <bits/stdc++.h>
using namespace std;

#include "../SumDiv_SumMod.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        ll n, m, a, b; cin >> n >> m >> a >> b;
        cout << sum_div(b, a, m, n) << '\n';
    }
    return 0;
}

