#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"

#include "../../template.h"
#include "../basic.h"
#include "../polygon.h"

#define ERROR 1e-6

void solve() {
    int n; cin >> n;
    Polygon a(n);
    REP(i,n) cin >> a[i];

    cout << (fixed) << setprecision(10) << convex_diameter(a).first << endl;
}
