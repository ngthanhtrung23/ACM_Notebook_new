#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include "../../template.h"
#include "../basic.h"
#include "../polygon.h"

void solve() {
    int n; cin >> n;
    Polygon g(n);
    for (auto& p : g) cin >> p;
    ConvexHull(g);
    int idx = 0;
    FOR(i,1,n-1) if (cmpy(g[i], g[idx])) idx = i;

    cout << g.size() << endl;
    REP(i,g.size()) cout << (fixed) << setprecision(0) << g[(idx + i) % g.size()] << '\n';
}
