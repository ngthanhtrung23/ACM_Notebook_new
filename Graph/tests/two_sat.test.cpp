#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <bits/stdc++.h>
using namespace std;

#include "../2sat.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string wtf; cin >> wtf >> wtf;
    int n, m; cin >> n >> m;
    TwoSatSolver solver(n);
    while (m--) {
        int x, y; cin >> x >> y >> wtf;
        solver.x_or_y_constraint(x > 0, std::abs(x) - 1, y > 0, std::abs(y) - 1);
    }
    auto [has_solution, sol] = solver.solve();
    if (has_solution) {
        cout << "s SATISFIABLE" << endl;
        cout << "v ";
        REP(i,n) {
            if (sol[i]) cout << i+1;
            else cout << "-" << (i+1);
            cout << ' ';
        }
        cout << 0 << endl;
    } else {
        cout << "s UNSATISFIABLE" << endl;
    }
    return 0;
}
