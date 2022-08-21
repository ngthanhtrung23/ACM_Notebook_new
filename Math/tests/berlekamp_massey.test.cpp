#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include <bits/stdc++.h>
using namespace std;

#include "../modint.h"

using modular = ModInt<998244353>;

#include "../LinearRecurrence_BerlekampMassey.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
#define SZ(x) ((int)(x).size())

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<modular> a(n);
    REP(i,n) cin >> a[i];

    vector<modular> c = berlekampMassey<modular>(a);
    cout << SZ(c) << endl;
    for (auto x : c) cout << x << ' ';
    cout << endl;
    return 0;
}
