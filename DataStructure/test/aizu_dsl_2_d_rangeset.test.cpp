#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include "../../template.h"
#include "../RangeSet.h"

void solve() {
    int n, q; cin >> n >> q;

    // bits[b] contains set of elements with bit b == 1
    std::array<RangeSet<int>, 31> bits;

    // Init all a[i] to 2^31 - 1
    for (int i = 0; i < 31; ++i) {
        bits[i].insert(0, n - 1);
    }

    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int l, r, val; cin >> l >> r >> val;
            for (int bit = 0; bit < 31; ++bit) {
                if ((val >> bit) & 1) {
                    bits[bit].insert(l, r);
                } else {
                    bits[bit].erase(l, r);
                }
            }
        } else {
            int l; cin >> l;
            int res = 0;
            for (int bit = 0; bit < 31; ++bit) {
                res |= bits[bit].contains(l) << bit;
            }
            cout << res << '\n';
        }
    }
}
