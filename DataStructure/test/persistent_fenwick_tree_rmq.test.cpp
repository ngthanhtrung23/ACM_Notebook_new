#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../template.h"
#include "../Fenwick/PartiallyPersistentFenwick.h"

struct Data {
    int x;
    Data() : x(INT_MAX) {}
    Data(int _x) : x(_x) {}
};
Data operator + (const Data& a, const Data& b) {
    return Data{min(a.x, b.x)};
}
bool operator < (const Data&, const Data&) {
    return false;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    REP(i,n) cin >> a[i];

    PartiallyPersistentFenwick<Data> fen(n);
    FORD(i,n-1,0) fen.update(n-i, i, Data{a[i]});

    while (q--) {
        int l, r; cin >> l >> r;
        auto res = fen.get(n-l, r);
        cout << res.x << '\n';
    }
}
