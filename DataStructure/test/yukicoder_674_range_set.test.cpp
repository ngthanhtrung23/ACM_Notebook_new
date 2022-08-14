#define PROBLEM "https://yukicoder.me/problems/no/674"

#include "../../template.h"
#include "../RangeSet.h"

void solve() {
    long long d;
    int q;
    std::cin >> d >> q;

    long long ans = 0;
    RangeSet<long long> set;
    while (q --> 0) {
        long long l, r;
        std::cin >> l >> r;
        set.insert(l, r);
        auto lr_opt = set.find_range(l);
        if (lr_opt.has_value()) {
            auto [nl, nr] = lr_opt.value();
            ans = std::max(ans, nr - nl + 1LL);
        }
        std::cout << ans << '\n';
    }
}
