#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../../template.h"
#include "../Prime/RabinMiller.h"

void solve() {
    int q; cin >> q;
    while (q--) {
        int64_t n; cin >> n;
        cout << (is_prime(n) ? "Yes" : "No") << '\n';
    }
}
