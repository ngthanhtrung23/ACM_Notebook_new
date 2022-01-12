#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../Fenwick.h"
#include "../../buffered_reader.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = IO::get<int>();
    int q = IO::get<int>();

    Fenwick<long long> f(n);
    REP(i,n) {
        int x = IO::get<int>();
        f.update(i, x);
    }

    while (q--) {
        int l = IO::get<int>();
        int r = IO::get<int>();
        cout << f.get(l, r) << '\n';
    }
    return 0;
}
