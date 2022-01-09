#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include "../../template.h"
#include "../NumberTheory/Pollard.h"

void solve() {
    int q; cin >> q;
    while (q--) {
        long long n;
        cin >> n;
        cout << n << ' ' << isPrime(n) << '\n';
    }
}

