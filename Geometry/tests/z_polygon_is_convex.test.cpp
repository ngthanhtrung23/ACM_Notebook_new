#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"

#include "../../template.h"
#include "../basic.h"
#include "../polygon.h"

void solve() {
    int n; cin >> n;
    vector<P<long long>> g(n);
    for (auto& p : g) cin >> p;
    cout << (is_convex(g) ? 1 : 0) << endl;
}
