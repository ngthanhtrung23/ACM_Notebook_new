#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"

#include "../../template.h"
#include "../basic.h"

#define ERROR 1e-9

void solve() {
    cout << (fixed) << setprecision(10);
    Point a, b; cin >> a >> b;
    int q; cin >> q;
    while (q--) {
        Point p; cin >> p;
        Point projection;
        distToLine(p, a, b, projection);
        Point reflection = projection * 2 - p;
        cout << reflection << '\n';
    }
}
