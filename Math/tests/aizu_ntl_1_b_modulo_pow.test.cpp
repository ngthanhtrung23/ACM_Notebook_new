#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../../template.h"
#include "../modint.h"

const int MOD = 1e9 + 7;
using modular = ModInt<MOD>;

void solve() {
    modular m; int k; cin >> m >> k;
    cout << m.pow(k) << endl;
}
