#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include <bits/stdc++.h>
using namespace std;

#include "../modint.h"
#include "../Polynomial/FormalPowerSeries.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
using mint = ModInt<1'000'000'007>;

int32_t main() {
    int n, m; std::cin >> n >> m;
    FormalPowerSeries<mint> a(n), b(m);
    for (auto& val : a) std::cin >> val;
    for (auto& val : b) std::cin >> val;

    auto c = a * b;
    for (auto val : c) std::cout << val << ' ';
    std::cout << std::endl;
    return 0;
}
