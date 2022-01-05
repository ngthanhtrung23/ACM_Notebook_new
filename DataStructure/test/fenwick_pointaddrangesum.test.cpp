#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "bits/stdc++.h"
using namespace std;

#include "../Fenwick.h"
#include "../../buffered_reader.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = IO::get_int<int>();
    int q = IO::get_int<int>();

    Fenwick<long long> f(n);
    REP(i,n) {
        int x = IO::get_int<int>();
        f.update(i, x);
    }

    while (q--) {
        int typ = IO::get_int<int>();
        if (typ == 0) {
            int u = IO::get_int<int>();
            int val = IO::get_int<int>();
            f.update(u, val);
        } else if (typ == 1) {
            int l = IO::get_int<int>();
            int r = IO::get_int<int>();
            cout << f.get(l, r) << '\n';
        } else {
            assert(false);
        }
    }
    return 0;
}
