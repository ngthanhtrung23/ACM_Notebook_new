#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C"

#include "../../template.h"
#include "../basic.h"
#include "../polygon.h"

#define ERROR 1e-6

void solve() {
    int n; cin >> n;
    Polygon p(n);
    REP(i,n) cin >> p[i];

    cout << (fixed) << setprecision(10);
    int q; cin >> q;
    while (q--) {
        Point a, b; cin >> a >> b;
        Line l(a, b);
        cout << area(polygon_cut(p, l)) << '\n';
    }
}
