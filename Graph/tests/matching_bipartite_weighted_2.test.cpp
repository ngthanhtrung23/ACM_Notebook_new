#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <bits/stdc++.h>
using namespace std;

#include "../Matching/Hungarian_short.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
long long c[N][N];

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i,n) REP(j,n) cin >> c[i][j];

    auto [cost, matchL] = Hungarian<long long>(n, n, c);
    cout << cost << endl;
    for (int m : matchL) cout << m << ' ';
    cout << endl;
    return 0;
}
