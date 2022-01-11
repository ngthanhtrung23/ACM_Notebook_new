#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"

// Given 2 intersecting circles, find intersection points

#include "../../template.h"
#include "../basic.h"
#include "../circle.h"

#define ERROR 1e-6

void solve() {
    cout << (fixed) << setprecision(10);
    Circle c1, c2;
    cin >> c1 >> c2;
    auto ps = circleIntersect(c1, c2);
    assert(ps.size() > 0);
    if (ps.size() == 1) ps.push_back(ps[0]);
    sort(ps.begin(), ps.end());

    cout << ps[0] << ' ' << ps[1] << endl;
}
