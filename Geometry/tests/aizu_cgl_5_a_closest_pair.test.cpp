#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"

#include "../../template.h"
#include "../basic.h"
#include "../closest_pair.h"

#define ERROR 1e-6

void solve() {
    cout << (fixed) << setprecision(10);
    int n; cin >> n;
    vector<P<double>> a(n);
    for (auto& p : a) cin >> p;

    auto [dist, ps] = closest_pair(a);
    cout << dist << endl;
}
