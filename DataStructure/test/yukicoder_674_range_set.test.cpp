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
        auto lr = set.find_range(l);
        if (lr != set.ranges.end()) {
            auto [nl, nr] = *lr;
            ans = std::max(ans, nr - nl + 1LL);
        }
        std::cout << ans << '\n';
    }
}
