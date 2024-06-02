#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include "../../template.h"
#include "../basic.h"
#include "../polygon.h"

void solve() {
    int ntest; cin >> ntest;
    while (ntest--) {
        int n; cin >> n;
        vector<P<int>> ps(n);
        for (int i = 0; i < n; ++i) cin >> ps[i];

        ConvexHull(ps);
        cout << ps.size() << '\n';
        for (const auto& p : ps) cout << p.x << ' ' << p.y << '\n';
    }
}
