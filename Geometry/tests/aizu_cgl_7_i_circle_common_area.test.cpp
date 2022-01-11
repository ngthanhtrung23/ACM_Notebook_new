#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_I"

// Find common area of 2 circles

#include "../../template.h"
#include "../basic.h"
#include "../circle.h"

#define ERROR 1e-6

void solve() {
    cout << (fixed) << setprecision(10);
    Circle c1, c2; cin >> c1 >> c2;
    cout << commonCircleArea(c1, c2) << endl;
}
