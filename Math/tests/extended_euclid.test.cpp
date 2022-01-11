#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../../template.h"
#include "../NumberTheory/ExtendedEuclid.h"

using ll = long long;
void solve() {
    ll a, b; cin >> a >> b;
    ll x, y;
    extgcd(a, b, x, y);
    cout << x << ' ' << y << endl;
}
