#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"

// Given point p and circle c. p is outside c. Find all tangents and print tangent points on c.

#include "../../template.h"
#include "../basic.h"
#include "../circle.h"

#define ERROR 1e-6

void solve() {
    cout << (fixed) << setprecision(10);
    Point p;
    Circle c;
    cin >> p >> c;
    auto ls = tangents(Circle(p, 0.0), c);
    vector<Point> ps;
    for (auto l : ls) {
        auto cur = intersection(l, c);
        assert(!cur.empty());
        ps.insert(ps.end(), cur.begin(), cur.end());
    }
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());

    assert(ps.size() > 0);
    if (ps.size() == 1) ps.push_back(ps[0]);
    sort(ps.begin(), ps.end());

    cout << ps[0] << endl << ps[1] << endl;
}
