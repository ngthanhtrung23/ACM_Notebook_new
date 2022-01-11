#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include "../../template.h"
#include "../lis.h"

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;
    cout << lis_strict(a) << endl;
}
