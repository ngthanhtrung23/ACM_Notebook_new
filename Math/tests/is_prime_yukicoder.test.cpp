#define PROBLEM "https://yukicoder.me/problems/no/3030"

#include <bits/stdc++.h>
using namespace std;

#include "../../template.h"
#include "../NumberTheory/Pollard.h"

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while (q--) {
        long long n;
        cin >> n;
        cout << n << ' ' << isPrime(n) << '\n';
    }
}

