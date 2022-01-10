#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"

#include "../../template.h"
#include "../basic.h"
#include "../polygon.h"

void solve() {
    int n; cin >> n;
    vector<P<long long>> P(n);
    for (auto& p : P) cin >> p;
    long long res = signed_area2(P);
    cout << (fixed) << setprecision(1) << std::abs(res / 2.0) << endl;
}
