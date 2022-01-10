#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"

#include "../../template.h"
#include "../basic.h"

void solve() {
    int q; cin >> q;
    cout << (fixed) << setprecision(9);
    while (q--) {
        Point a, b; cin >> a >> b;
        Point c, d; cin >> c >> d;
        Point t;

        if (segmentIntersect(a, b, c, d)) cout << "0\n";
        else {
            cout << min(
                    distToLineSegment(a, c, d, t),
                    distToLineSegment(b, c, d, t)) << '\n';
        }
    }
}
