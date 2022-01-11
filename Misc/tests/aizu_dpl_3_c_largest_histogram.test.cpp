#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"

#include "../../template.h"
#include "../left_nearest_smaller.h"

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;

    auto left = leftNearestSmaller(a);
    auto right = rightNearestSmaller(a);

    long long res = 0;
    for (int i = 0; i < n; i++) {
        int l = left[i] + 1;
        int r = right[i] - 1;
        res = max(res, a[i] * (r - l + 1LL));
    }
    cout << res << endl;
}
