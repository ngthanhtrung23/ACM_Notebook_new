#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"

#include "../../template.h"
#include "../left_nearest_smaller.h"

long long largestHistogram(const vector<int>& a) {
    int n = a.size();
    auto left = leftNearestSmaller(a);
    auto right = rightNearestSmaller(a);

    long long res = 0;
    for (int i = 0; i < n; i++) {
        int l = left[i] + 1;
        int r = right[i] - 1;
        res = max(res, a[i] * (r - l + 1LL));
    }
    return res;
}

void solve() {
    int n_row, n_col; cin >> n_row >> n_col;
    vector<vector<int>> a(n_row, vector<int> (n_col));
    for (auto& row : a) {
        for (auto& x : row) {
            cin >> x;
            x = 1 - x;
        }
    }

    long long res = 0;
    for (int r = 0; r < n_row; r++) {
        if (r > 0) {
            for (int c = 0; c < n_col; c++) {
                if (a[r][c]) a[r][c] = a[r-1][c] + 1;
                else a[r][c] = 0;
            }
        }
        res = max(res, largestHistogram(a[r]));
    }
    cout << res << endl;
}
