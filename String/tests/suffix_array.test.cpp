#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
using namespace std;

#include "../SuffixArray.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    SuffixArray sa(s);
    for (int x : sa.SA) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
