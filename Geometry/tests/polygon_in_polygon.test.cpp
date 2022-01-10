#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

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
        auto res = in_polygon(g, p);
        cout << res << '\n';
    }
}
