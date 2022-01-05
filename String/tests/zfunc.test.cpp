#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;

#include "../zfunc.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    for (auto x : zfunc(s)) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
