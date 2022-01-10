#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"

#include "../../template.h"
#include "../basic.h"
#include "../polygon.h"

void solve() {
    int n; cin >> n;
    Polygon P(n);
    for (auto& p : P) cin >> p;
    cout << (fixed) << setprecision(1) << area(P) << endl;
}
