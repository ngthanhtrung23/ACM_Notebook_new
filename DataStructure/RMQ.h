// RMQ {{{
//
// Sparse table
// Usage:
// RMQ<int, _min> st(v);
//
// Note:
// - doesn't work for empty range
//
// Tested:
// - https://judge.yosupo.jp/problem/staticrmq
template<class T, T (*op) (T, T)> struct RMQ {
    RMQ() = default;
    RMQ(const vector<T>& v) : t{v}, n{(int) v.size()} {
        for (int k = 1; (1<<k) <= n; ++k) {
            t.emplace_back(n - (1<<k) + 1);
            for (int i = 0; i + (1<<k) <= n; ++i) {
                t[k][i] = op(t[k-1][i], t[k-1][i + (1<<(k-1))]);
            }
        }
    }

    // get range [l, r-1]
    // doesn't work for empty range
    T get(int l, int r) const {
        assert(0 <= l && l < r && r <= n);
        int k = __lg(r - l);
        return op(t[k][l], t[k][r - (1<<k)]);
    }

private:
    vector<vector<T>> t;
    int n;
};
template<class T> T _min(T a, T b) { return b < a ? b : a; }
template<class T> T _max(T a, T b) { return a < b ? b : a; }
// }}}
