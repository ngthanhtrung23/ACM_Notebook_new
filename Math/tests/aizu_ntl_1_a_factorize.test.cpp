#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include "../../template.h"
#include "../NumberTheory/Pollard.h"

void solve() {
    int n;
    cin >> n;
    auto facs = factorize(n);
    cout << n << ':';
    for (auto x : facs) cout << ' ' << x;
    cout << '\n';
}
