#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_big_integers"

#include "bits/stdc++.h"
using namespace std;

#include "../bigint.h"

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        BigInt a, b; cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
