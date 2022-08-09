// SegTree, copied from AtCoder library {{{
// AtCoder doc: https://atcoder.github.io/ac-library/master/document_en/segtree.html
//
// Notes:
// - Index of elements from 0 -> n-1
// - Range queries are [l, r-1]
//
// Tested:
// - (binary search) https://atcoder.jp/contests/practice2/tasks/practice2_j
// - https://oj.vnoi.info/problem/gss
// - https://oj.vnoi.info/problem/nklineup
// - (max_right & min_left for delete position queries) https://oj.vnoi.info/problem/segtree_itstr
// - https://judge.yosupo.jp/problem/point_add_range_sum
// - https://judge.yosupo.jp/problem/point_set_range_composite
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

template<
    class T,  // data type for nodes
    T (*op) (T, T),  // operator to combine 2 nodes
    T (*e)() // identity element
>
struct SegTree {
    SegTree() : SegTree(0) {}
    explicit SegTree(int n) : SegTree(vector<T> (n, e())) {}
    explicit SegTree(const vector<T>& v) : _n((int) v.size()) {
        log = ceil_pow2(_n);
        size = 1<<log;
        d = vector<T> (2*size, e());

        for (int i = 0; i < _n; i++) d[size+i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    // 0 <= p < n
    void set(int p, T x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    // 0 <= p < n
    T get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    // Get product in range [l, r-1]
    // 0 <= l <= r <= n
    // For empty segment (l == r) -> return e()
    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        T sml = e(), smr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    T all_prod() const {
        return d[1];
    }

    // Binary search on SegTree to find largest r:
    //    f(op(a[l] .. a[r-1])) = true   (assuming empty array is always true)
    //    f(op(a[l] .. a[r])) = false    (assuming op(..., a[n]), which is out of bound, is always false)
    template <bool (*f)(T)> int max_right(int l) const {
        return max_right(l, [](T x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        T sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    // Binary search on SegTree to find smallest l:
    //    f(op(a[l] .. a[r-1])) = true      (assuming empty array is always true)
    //    f(op(a[l-1] .. a[r-1])) = false   (assuming op(a[-1], ..), which is out of bound, is always false)
    template <bool (*f)(T)> int min_left(int r) const {
        return min_left(r, [](T x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        T sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    int _n, size, log;
    vector<T> d;

    void update(int k) {
        d[k] = op(d[2*k], d[2*k+1]);
    }
};
// }}}

// SegTree examples {{{
// Examples: Commonly used SegTree ops: max / min / sum
struct MaxSegTreeOp {
    static int op(int x, int y) {
        return max(x, y);
    }
    static int e() {
        return INT_MIN;
    }
};

struct MinSegTreeOp {
    static int op(int x, int y) {
        return min(x, y);
    }
    static int e() {
        return INT_MAX;
    }
};

struct SumSegTreeOp {
    static long long op(long long x, long long y) {
        return x + y;
    }
    static long long e() {
        return 0;
    }
};

// Example
// SegTree<int, MaxSegTreeOp::op, MaxSegTreeOp::e> seg_tree(a);
// SegTree<int, MinSegTreeOp::op, MinSegTreeOp::e> seg_tree(a);
// }}}
