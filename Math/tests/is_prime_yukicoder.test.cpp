#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <bits/stdc++.h>
using namespace std;

#include "../../template.h"
#include "../NumberTheory/Pollard.h"

int main() {
    int q; cin >> q;
    while (q--) {
        long long n;
        cin >> n;
        cout << n << ' ' << isPrime(n) << '\n';
    }
}

