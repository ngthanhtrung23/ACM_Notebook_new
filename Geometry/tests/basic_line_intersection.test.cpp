#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"

#include "../../template.h"
#include "../basic.h"

void solve() {
    int q; cin >> q;
    cout << (fixed) << setprecision(10);
    while (q--) {
        Point a, b; cin >> a >> b;
        Point c, d; cin >> c >> d;
        assert(segmentIntersect(a, b, c, d));
        Line l1(a, b);
        Line l2(c, d);
        Point p;
        assert(areIntersect(l1, l2, p));
        // Hack to fix exact judge
        if (std::abs(p.x) < 1e-11) p.x = 0.0;
        if (std::abs(p.y) < 1e-11) p.y = 0.0;
        cout << p << '\n';
    }
}
