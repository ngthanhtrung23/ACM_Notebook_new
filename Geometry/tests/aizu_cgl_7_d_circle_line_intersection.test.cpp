#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"

// Given circle and line. Print intersection points (there are always >= 1)

#include "../../template.h"
#include "../basic.h"
#include "../circle.h"

#define ERROR 1e-6

void solve() {
    Circle c; cin >> c;
    int q; cin >> q;
    cout << (fixed) << setprecision(10);
    while (q--) {
        Point a, b; cin >> a >> b;
        Line l(a, b);
        auto ps = intersection(l, c);
        if (ps.size() == 1) ps.push_back(ps[0]);
        sort(ps.begin(), ps.end());
        cout << ps[0] << ' ' << ps[1] << endl;
    }
}
