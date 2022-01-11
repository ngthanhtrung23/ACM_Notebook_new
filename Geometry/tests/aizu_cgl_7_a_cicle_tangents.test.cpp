#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

// Given 2 circles, return how many common tangents

#include "../../template.h"
#include "../basic.h"
#include "../circle.h"

void solve() {
    Circle c1, c2; cin >> c1 >> c2;
    cout << tangents(c1, c2).size() << endl;
}
