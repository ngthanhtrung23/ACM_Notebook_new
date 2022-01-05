#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>
using namespace std;

#include "../RMQ.h"
#include "../../buffered_reader.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    REP(i,n) cin >> a[i];

    RMQ<int, _min> st(a);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.get(l, r) << '\n';
    }
    return 0;
}
