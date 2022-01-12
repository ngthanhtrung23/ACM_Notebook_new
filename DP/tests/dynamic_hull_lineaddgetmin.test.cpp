#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <bits/stdc++.h>
using namespace std;

#include "../dynamic_hull.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    HullDynamic hull;
    REP(i,n) {
        long long a, b; cin >> a >> b;
        hull.insert_line(-a, -b);
    }
    REP(i,q) {
        int typ; cin >> typ;
        if (typ == 0) {
            long long a, b; cin >> a >> b;
            hull.insert_line(-a, -b);
        } else {
            long long x; cin >> x;
            cout << -hull.eval(x) << '\n';
        }
    }
    return 0;
}
