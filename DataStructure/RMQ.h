// Sparse table
// Usage:
// SparseTable<int, _min> st(v);
//
// Tested:
// - https://judge.yosupo.jp/problem/staticrmq
template<class T, T (*op) (T, T)> struct SparseTable {
    SparseTable(const vector<T>& v) : t{v} {
        for (int k = 1, n = (int) v.size(); (1<<k) <= n; ++k) {
            t.emplace_back(n - (1<<k) + 1);
            for (int i = 0; i + (1<<k) <= n; ++i) {
                t[k][i] = op(t[k-1][i], t[k-1][i + (1<<(k-1))]);
            }
        }
    }

    // get range [l, r-1]
    T get(int l, int r) const {
        assert(l < r);
        int k = __lg(r - l);
        return op(t[k][l], t[k][r - (1<<k)]);
    }

private:
    vector<vector<T>> t;
};
template<class T> T _min(T a, T b) { return b < a ? b : a; }
template<class T> T _max(T a, T b) { return a < b ? b : a; }
