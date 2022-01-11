#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"

// Given 2 circles. Find all common tangents, and print tangent points on c1

#include "../../template.h"
#include "../basic.h"
#include "../circle.h"

#define ERROR 1e-6

void solve() {
    cout << (fixed) << setprecision(10);
    Circle c1, c2; cin >> c1 >> c2;
    auto ts = tangents(c1, c2);
    vector<Point> ps;

    for (auto t : ts) {
        auto cur = intersection(t, c1);
        assert(!cur.empty());
        ps.insert(ps.end(), cur.begin(), cur.end());
    }
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());

    for (auto p : ps) cout << p << endl;
}
