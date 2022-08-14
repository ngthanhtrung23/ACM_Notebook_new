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
        auto [nl, nr] = *set.find_range(l);
        ans = std::max(ans, nr - nl + 1);
        std::cout << ans << '\n';
    }
}
