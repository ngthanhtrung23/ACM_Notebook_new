// Closest pair
//
// Tested:
// - https://open.kattis.com/problems/closestpair1
// - https://open.kattis.com/problems/closestpair2
//
// Returns: {dist, 2 points}
//
// If need point ids -> add ID to struct P
// If need exact square dist -> can compute from returned points
template<typename T>
std::pair<double, std::pair<P<T>, P<T>>> closest_pair(vector<P<T>> a) {
    int n = a.size();
    assert(n >= 2);
    double mindist = 1e20;
    std::pair<P<T>, P<T>> best_pair;
    std::vector<P<T>> t(n);
    sort(a.begin(), a.end());

    auto upd_ans = [&] (const P<T>& u, const P<T>& v) {
        double cur = (u - v).len();
        if (cur < mindist) {
            mindist = cur;
            best_pair = {u, v};
        }
    };

    std::function<void(int,int)> rec = [&] (int l, int r) {
        if (r - l <= 3) {
            for (int i = l; i < r; ++i) {
                for (int j = i + 1; j < r; ++j) {
                    upd_ans(a[i], a[j]);
                }
            }
            sort(a.begin() + l, a.begin() + r, cmpy<T>);
            return;
        }

        int m = (l + r) >> 1;
        T midx = a[m].x;
        rec(l, m);
        rec(m, r);

        std::merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmpy<T>);
        std::copy(t.begin(), t.begin() + r - l, a.begin() + l);

        int tsz = 0;
        for (int i = l; i < r; ++i) {
            if (abs(a[i].x - midx) < mindist) {
                for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                    upd_ans(a[i], t[j]);
                t[tsz++] = a[i];
            }
        }
    };
    rec(0, n);

    return {mindist, best_pair};
}
