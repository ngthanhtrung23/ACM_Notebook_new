#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <bits/stdc++.h>
using namespace std;

#include "../SuffixArray.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
#define SZ(x) ((int)(x).size())

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    long long res = SZ(s) * (long long)(SZ(s) + 1) / 2;
    SuffixArray sa(s);
    for (int x : sa.LCP) {
        res -= x;
    }
    cout << res << endl;
    return 0;
}
