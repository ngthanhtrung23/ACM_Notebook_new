#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include "../../template.h"
#include "../basic.h"

bool orthogonal(const Line& l1, const Line& l2) {
    Point a(l1.a, l1.b);
    Point b(l2.a, l2.b);
    return cmp(a * b, 0) == 0;
}

void solve() {
    int q; cin >> q;
    while (q--) {
        Point a, b, c, d; cin >> a >> b >> c >> d;
        Line l1(a, b), l2(c, d);

        if (areParallel(l1, l2)) cout << 2;
        else if (orthogonal(l1, l2)) cout << 1;
        else cout << 0;
        cout << endl;
    }
}
