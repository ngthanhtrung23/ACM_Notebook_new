#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include "../../template.h"
#include "../hash.h"
#define SZ(x) ((int)(x).size())

HashGenerator g(1000111);
void solve() {
    std::string a, b; std::cin >> a >> b;

    auto hb = g.hash(b);
    auto ha = g.hash(a);

    for (int i = 0; i + SZ(b) <= SZ(a); i++) {
        if (g.equals(hb, 0, SZ(b) - 1,
                    ha, i, i + SZ(b) - 1)) {
            std::cout << i << '\n';
        }
    }
}
