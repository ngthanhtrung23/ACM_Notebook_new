#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../../template.h"
#include "../lis.h"

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;

    auto res = lis_strict_trace(a);
    std::cout << res.size() << std::endl;
    for (int i : res) std::cout << i << ' ';
    std::cout << std::endl;
}
