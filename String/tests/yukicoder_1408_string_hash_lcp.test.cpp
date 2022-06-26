#define PROBLEM "https://yukicoder.me/problems/1408"

#include "../../template.h"
#include "../hash.h"
#define SZ(x) ((int)(x).size())

HashGenerator g(1000111);
void solve() {
    int n; std::cin >> n;

    std::vector<std::vector<Hash>> hs;
    for (int i = 0; i < n; i++) {
        std::string s; std::cin >> s;

        hs.push_back(g.hash(s));
    }

    int m;
    long long x, d, res = 0;
    std::cin >> m >> x >> d;

    while (m--) {
        int i = x / (n - 1);
        int j = x % (n - 1);
        if (i <= j) ++j;
        x = (x + d) % (n * (n-1LL));

        res += g.maxCommonPrefix(
                hs[i], 0, SZ(hs[i]) - 1,
                hs[j], 0, SZ(hs[j]) - 1);
    }
    std::cout << res << '\n';
}
