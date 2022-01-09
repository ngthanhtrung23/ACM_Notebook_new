#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <bits/stdc++.h>
using namespace std;

#include "../Prime/IterativeSieve.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    sieve();

    int cnt1 = 0;
    for (int i = 0; i < nprime; i++) {
        if (prime[i] > n) break;
        ++cnt1;
    }

    int cnt2 = 0;
    for (int i = 0; ; i++) {
        int id = a*i + b;
        if (id >= nprime || prime[id] > n) break;

        ++cnt2;
    }
    cout << cnt1 << ' ' << cnt2 << '\n';

    for (int i = 0; ; i++) {
        int id = a*i + b;
        if (id >= nprime || prime[id] > n) break;

        cout << prime[id] << ' ';
    }
    cout << endl;
    return 0;
}
