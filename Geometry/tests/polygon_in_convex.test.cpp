#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412"

#include "../../template.h"
#include "../basic.h"
#include "../polygon.h"

void solve() {
    int n; cin >> n;
    Polygon g(n);
    for (auto& p : g) cin >> p;

    int q; cin >> q;
    while (q--) {
        Point p; cin >> p;
        p = p - (p / 10000.0);
        cout << (in_convex(g, p) ? 1 : 0) << '\n';
    }
}
