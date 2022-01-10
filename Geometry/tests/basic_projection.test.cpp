#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"

#include "../../template.h"
#include "../basic.h"

void solve() {
    cout << (fixed) << setprecision(10);
    Point a, b; cin >> a >> b;
    int q; cin >> q;
    while (q--) {
        Point p; cin >> p;
        Point projection;
        distToLine(p, a, b, projection);
        cout << projection << '\n';
    }
}
