// 0-based index
// Tested:
// - https://www.spoj.com/problems/MATSUM/
//
// Fenwick 2D, small N {{{
template<
    typename T  // need to support +, -
> struct Fenwick2D {
    Fenwick2D(int _n1, int _n2) : n1(_n1), n2(_n2), f(1+n1, vector<T> (1+n2, T(0))) {}

    // a[x][y] += val
    void update(int x, int y, T val) {
        assert(0 <= x && x < n1);
        assert(0 <= y && y < n2);
        ++x; ++y;
        for (int u = x; u <= n1; u += u & -u) {
            for (int v = y; v <= n2; v += v & -v) {
                f[u][v] += val;
            }
        }
    }

    // return rect sum of [0, 0] -> [x-1, y-1]
    T get(int x, int y) const {
        assert(0 <= x && x <= n1);
        assert(0 <= y && y <= n2);
        T res(0);
        for (int u = x; u > 0; u -= u & -u) {
            for (int v = y; v > 0; v -= v & -v) {
                res += f[u][v];
            }
        }
        return res;
    }

    // returns rect sum of [x1, y1] -> [x2-1, y2-1]
    T get(int x1, int y1, int x2, int y2) const {
        assert(0 <= x1 && x1 <= x2 && x2 <= n1);
        assert(0 <= y1 && y1 <= y2 && y2 <= n2);
        if (x1 == x2 || y1 == y2) return T(0);
        return get(x2, y2) - get(x1, y2) - get(x2, y1) + get(x1, y1);
    }

    int n1, n2;
    vector<vector<T>> f;
};
// }}}
