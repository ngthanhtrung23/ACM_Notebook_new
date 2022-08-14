#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_4_A"

#include "../../template.h"
#include "../RangeSet.h"

void solve() {
    int n; std::cin >> n;
    std::set<int> xs;
    std::vector<std::tuple<int,int,int,int>> rects(n);
    for (auto& [x1, y1, x2, y2] : rects) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        xs.insert(x1);
        xs.insert(x2);
    }

    long long res = 0;
    for (auto it = std::next(xs.begin()); it != xs.end(); ++it) {
        int left = *std::prev(it);
        int right = *it;

        RangeSet<int> rs;
        for (auto [x1, y1, x2, y2] : rects) {
            if (x1 <= left && x2 >= right) {
                rs.insert(y1, y2 - 1);
            }
        }
        res += (right - left) * (long long) rs.n_elements();
    }
    std::cout << res << endl;
}
