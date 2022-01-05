#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include <bits/stdc++.h>
using namespace std;

#include "../Prime/PrimePi.h"

int32_t main() {
    long long n; cin >> n;
    cout << prime_pi(n) << endl;
    return 0;
}
