#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include <bits/stdc++.h>
using namespace std;

#include "../Prime/SieveFast.h"

int n, a, b, cnt = 0, cnt_mod = 0;
vector<int> ps;
void newPrime(int p) {
    if (p > n) {
        cout << cnt << ' ' << ps.size() << '\n';
        for (int x : ps) cout << x << ' ';
        exit(0);
    }
    if (cnt_mod == b) ps.push_back(p);
    ++cnt;
    ++cnt_mod;
    if (cnt_mod == a) cnt_mod = 0;
}

int32_t main() {
    cin >> n >> a >> b;
    sieve(1'000'000'000, newPrime);
    return 0;
}
