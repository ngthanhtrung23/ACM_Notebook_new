#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <bits/stdc++.h>
using namespace std;

#include "../Matrix.h"
#include "../../buffered_reader.h"
#include "../modint.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
using modular = ModInt<998244353>;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = IO::get<int>();
    int m = IO::get<int>();
    int k = IO::get<int>();
    Matrix<modular> a(n, m);
    Matrix<modular> b(m, k);
    for (auto& x : a.x) x = IO::get<modular>();
    for (auto& x : b.x) x = IO::get<modular>();

    auto c = a * b;
    REP(i,n) {
        REP(j,k) cout << c[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
