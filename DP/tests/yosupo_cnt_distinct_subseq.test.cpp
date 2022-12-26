#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"

#include "../../template.h"
#include "../cnt_distinct_subseq.h"
#include "../../Math/modint.h"

const int MOD = 998244353;
using mint = ModInt<MOD>;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    REP(i,n) cin >> a[i];

    cout << cnt_distinct_subsequences<int, mint> (a) << endl;
}
