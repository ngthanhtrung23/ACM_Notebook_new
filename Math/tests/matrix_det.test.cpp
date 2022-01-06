#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

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
    Matrix<modint998244353> a(n, n);
    REP(i,n) REP(j,n) {
        int x = IO::get<int>();
        a[i][j] = x;
    }
    auto tmp = a.gauss();
    cout << tmp.det().val() << endl;
    return 0;
}
