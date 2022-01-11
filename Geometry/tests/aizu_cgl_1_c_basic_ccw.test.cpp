#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include "../../template.h"
#include "../basic.h"

void solve() {
    Point a, b; cin >> a >> b;
    int q; cin >> q;
    while (q--) {
        Point c; cin >> c;
        auto t = ccw(a, b, c);
        if (t == 0) {
            if (onSegment(a, b, c)) cout << "ON_SEGMENT\n";
            else if (onSegment(c, b, a)) cout << "ONLINE_BACK\n";
            else cout << "ONLINE_FRONT\n";
        } else if (t < 0) cout << "CLOCKWISE\n";
        else cout << "COUNTER_CLOCKWISE\n";
    }
}
