#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <bits/stdc++.h>
#include "../../atcoder/modint.hpp"
using namespace std;
using namespace atcoder;

#include "../Matrix.h"
#include "../../buffered_reader.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = IO::get<int>();
    int m = IO::get<int>();
    int k = IO::get<int>();
    Matrix<modint998244353> a(n, m);
    Matrix<modint998244353> b(m, k);
    REP(i,n) REP(j,m) {
        int x = IO::get<int>();
        a[i][j] = x;
    }
    REP(i,m) REP(j,k) {
        int x = IO::get<int>();
        b[i][j] = x;
    }
    auto c = a * b;
    REP(i,n) {
        REP(j,k) cout << c[i][j].val() << ' ';
        cout << '\n';
    }
    return 0;
}
