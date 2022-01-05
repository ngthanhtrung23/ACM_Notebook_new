#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <bits/stdc++.h>
using namespace std;

#include "../SuffixArray.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int res = SZ(s) * (SZ(s) + 1) / 2;
    SuffixArray sa(s);
    for (int x : sa.LCP) {
        res -= x;
    }
    cout << res << endl;
    return 0;
}
