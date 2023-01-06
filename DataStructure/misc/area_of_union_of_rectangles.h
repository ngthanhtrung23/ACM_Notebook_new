#include "../LazySegTree.h"

// Area of union of rectangles {{{
namespace area_of_union_of_rectangles {
    using ll = long long;
    const int INF = std::numeric_limits<int>::max() / 2;

    struct Rect {
        int x1, y1, x2, y2;
    };
    istream& operator >> (istream& cin, Rect& r) {
        cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        return cin;
    }

    struct S {
        int min_cnt;
        ll sum;
    };
    S op(S x, S y) {
        if (x.min_cnt < y.min_cnt) return x;
        if (y.min_cnt < x.min_cnt) return y;
        return { x.min_cnt, x.sum + y.sum };
    }
    S e() { return { INF, 0 }; }
    S mapping(int f, S s) { return { s.min_cnt + f, s.sum }; }
    int composition(int f, int g) { return f + g; }
    int id() { return 0; }
    using ST = LazySegTree<S, op, e, int, mapping, composition, id>;

    ll solve(const std::vector<Rect>& rects) {
        if (rects.empty()) return ll(0);

        const int n = rects.size();
        std::vector<std::tuple<int, int, int, int>> events; events.reserve(2*n);
        std::vector<int> ys; ys.reserve(2*n);

        for (const auto& r : rects) {
            events.emplace_back(r.x1, r.y1, r.y2, +1);
            events.emplace_back(r.x2, r.y1, r.y2, -1);
            ys.push_back(r.y1);
            ys.push_back(r.y2);
        }
        std::sort(events.begin(), events.end(), [] (const auto& e1, const auto& e2) {
                return std::get<0>(e1) < std::get<0>(e2); });
        std::sort(ys.begin(), ys.end());
        ys.erase(std::unique(ys.begin(), ys.end()), ys.end());

        const int nys = ys.size();
        std::vector<S> init(nys - 1);
        for (int i = 0; i < nys - 1; ++i) {
            init[i] = { 0, ys[i+1] - ys[i] };
        }
        ST st(init);

        ll res = 0;
        ll lx = std::get<0>(events.front());  // events[i-1].x
        for (int i = 0; lx != std::get<0>(events.back());) {
            for (;; ++i) {
                auto [xi, d, u, add] = events[i];
                if (xi != lx) break;
                int ly = std::lower_bound(ys.begin(), ys.end(), d) - ys.begin();
                int ry = std::lower_bound(ys.begin(), ys.end(), u) - ys.begin();
                st.apply(ly, ry, add);
            }
            ll rx = std::get<0> (events[i]);
            auto [min_cnt, sum] = st.all_prod();
            res += (rx - lx) * (ys.back() - ys.front() - (min_cnt == 0 ? sum : ll(0)));
            lx = rx;
        }
        return res;
    }
}
// }}}
