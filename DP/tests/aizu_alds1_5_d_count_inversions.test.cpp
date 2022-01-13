#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"

#include "../../template.h"
#include "../count_inversions.h"

void solve() {
    int n; cin >> n;
    auto a = read_vector<int> (n);

    cout << count_inversions(a) << endl;
}
