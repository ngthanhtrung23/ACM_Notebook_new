#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include "../../template.h"
#include "../Prime/EulerPhi.h"

using ll = long long;
void solve() {
    ll n; cin >> n;
    if (n < N) {
        assert(eulerPhi(n) == eulerPhi_lookup(n));
    }
    cout << eulerPhi(n) << endl;
}
