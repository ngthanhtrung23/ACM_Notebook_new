// NOTE:
// - 0-based index
// - for updates: time must be in increasing order
// - Update: O(log), Get: O(log^2)
//
// Partially Persistent FenwickTree {{{
template<
    typename T  // need to support operators + - <
> struct PartiallyPersistentFenwick {
    PartiallyPersistentFenwick(int _n) : n(_n), f(_n + 1) {
        for (int i = 0; i <= n; ++i) {
            f[i].emplace_back(INT_MIN, T{});
        }
    }

    // a[u] += val
    void update(int time, int u, T val) {
        assert(0 <= u && u < n);
        assert(last_updated_time <= time);
        last_updated_time = time;
        ++u;
        for (; u <= n; u += u & -u) {
            f[u].emplace_back(time, f[u].back().second + val);
        }
    }

    // return a[0] + .. + a[u-1]
    T get(int time, int u) const {
        assert(0 <= u && u <= n);
        T res{};
        for (; u > 0; u -= u & -u) {
            auto it = lower_bound(f[u].begin(), f[u].end(), make_pair(time+1, T{}));
            res = res + prev(it)->second;
        }
        return res;
    }

    // return a[l] + .. + a[r-1]
    T get(int time, int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return T{};  // empty
        return get(time, r) - get(time, l);
    }

    int n;
    int last_updated_time = INT_MIN;
    vector<vector<pair<int, T>>> f;  // (time, data)
};
// }}}
