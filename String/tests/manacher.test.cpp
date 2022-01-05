#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <bits/stdc++.h>
using namespace std;

#include "../manacher.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
#define SZ(x) ((int)(x).size())

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    auto [even, odd] = manacher(s);

    REP(i,SZ(s)) {
        cout << odd[i] << ' ';
        if (i+1 < SZ(s)) cout << even[i] << ' ';
    }
    cout << endl;
    return 0;
}
