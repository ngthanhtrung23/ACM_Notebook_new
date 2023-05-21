---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DataStructure/misc/area_of_union_of_rectangles.h
    title: DataStructure/misc/area_of_union_of_rectangles.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_2_d_segment_tree_rangeset.test.cpp
    title: DataStructure/test/aizu_dsl_2_d_segment_tree_rangeset.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_2_e_segment_tree_rangeadd.test.cpp
    title: DataStructure/test/aizu_dsl_2_e_segment_tree_rangeadd.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_2_f_segment_tree_rangesetmin.test.cpp
    title: DataStructure/test/aizu_dsl_2_f_segment_tree_rangesetmin.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_2_g_segment_tree_rangeaddsum.test.cpp
    title: DataStructure/test/aizu_dsl_2_g_segment_tree_rangeaddsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_2_h_segment_tree_rangeaddmin.test.cpp
    title: DataStructure/test/aizu_dsl_2_h_segment_tree_rangeaddmin.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_2_i_segment_tree_rangesetsum.test.cpp
    title: DataStructure/test/aizu_dsl_2_i_segment_tree_rangesetsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp
    title: DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/area_of_union_of_rectangles.test.cpp
    title: DataStructure/test/area_of_union_of_rectangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_rangeaffinepointget.test.cpp
    title: DataStructure/test/segment_tree_rangeaffinepointget.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
    title: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.github.io/ac-library/master/document_en/lazysegtree.html
    - https://atcoder.jp/contests/practice2/tasks/practice2_l
    - https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
    - https://judge.yosupo.jp/problem/range_affine_range_sum
    - https://oj.vnoi.info/problem/lites
    - https://oj.vnoi.info/problem/qmax2
    - https://oj.vnoi.info/problem/segtree_itladder
    - https://oj.vnoi.info/problem/segtree_itmix
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"DataStructure/LazySegTree.h\"\n// Lazy Segment Tree, copied\
    \ from AtCoder {{{\n// Source: https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    // Doc: https://atcoder.github.io/ac-library/master/document_en/lazysegtree.html\n\
    //\n// Notes:\n// - Index of elements from 0\n// - Range queries are [l, r-1]\n\
    // - composition(f, g) should return f(g())\n//\n// Tested:\n// - https://oj.vnoi.info/problem/qmax2\n\
    // - https://oj.vnoi.info/problem/lites\n// - (range set, add, mult, sum) https://oj.vnoi.info/problem/segtree_itmix\n\
    // - (range add (i-L)*A + B, sum) https://oj.vnoi.info/problem/segtree_itladder\n\
    // - https://atcoder.jp/contests/practice2/tasks/practice2_l\n// - https://judge.yosupo.jp/problem/range_affine_range_sum\n\
    \nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\ntemplate<\n    class S,                 // node data\
    \ type\n    S (*op) (S, S),          // combine 2 nodes\n    S (*e) (),      \
    \         // identity element\n    class F,                 // lazy propagation\
    \ tag\n    S (*mapping) (F, S),     // apply tag F on a node\n    F (*composition)\
    \ (F, F), // combine 2 tags\n    F (*id)()                // identity tag\n>\n\
    struct LazySegTree {\n    LazySegTree() : LazySegTree(0) {}\n    explicit LazySegTree(int\
    \ n) : LazySegTree(vector<S>(n, e())) {}\n    explicit LazySegTree(const vector<S>&\
    \ v) : _n((int) v.size()) {\n        log = ceil_pow2(_n);\n        size = 1 <<\
    \ log;\n        d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \n    // 0 <= p < n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n\n    // 0 <= p < n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      return d[p];\n    }\n\n    // Get product in range [l, r-1]\n    // 0 <=\
    \ l <= r <= n\n    // For empty segment (l == r) -> return e()\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    S sml = e(), smr = e();\n        while (l < r) {\n            if (l & 1)\
    \ sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n    \
    \        l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() {\n        return d[1];\n    }\n\n    // 0 <= p < n\n\
    \    void apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] =\
    \ mapping(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n\n    // Apply f on all elements in range [l, r-1]\n    // 0 <= l <= r\
    \ <= n\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if (l == r) return;\n\n        l += size;\n        r += size;\n\
    \n        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n\n        {\n            int l2 = l, r2 = r;\n            while (l\
    \ < r) {\n                if (l & 1) all_apply(l++, f);\n                if (r\
    \ & 1) all_apply(--r, f);\n                l >>= 1;\n                r >>= 1;\n\
    \            }\n            l = l2;\n            r = r2;\n        }\n\n      \
    \  for (int i = 1; i <= log; i++) {\n            if (((l >> i) << i) != l) update(l\
    \ >> i);\n            if (((r >> i) << i) != r) update((r - 1) >> i);\n      \
    \  }\n    }\n\n    // Binary search on SegTree to find largest r:\n    //    f(op(a[l]\
    \ .. a[r-1])) = true   (assuming empty array is always true)\n    //    f(op(a[l]\
    \ .. a[r])) = false    (assuming op(..., a[n]), which is out of bound, is always\
    \ false)\n    template <bool (*g)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n   \
    \     if (l == _n) return _n;\n        l += size;\n        for (int i = log; i\
    \ >= 1; i--) push(l >> i);\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!g(op(sm, d[l]))) {\n               \
    \ while (l < size) {\n                    push(l);\n                    l = (2\
    \ * l);\n                    if (g(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    // Binary search on SegTree to find smallest l:\n\
    \    //    f(op(a[l] .. a[r-1])) = true      (assuming empty array is always true)\n\
    \    //    f(op(a[l-1] .. a[r-1])) = false   (assuming op(a[-1], ..), which is\
    \ out of bound, is always false)\n    template <bool (*g)(S)> int min_left(int\
    \ r) {\n        return min_left(r, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int min_left(int r, G g) {\n        assert(0 <= r && r <= _n);\n \
    \       assert(g(e()));\n        if (r == 0) return 0;\n        r += size;\n \
    \       for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!g(op(d[r], sm))) {\n                while (r < size) {\n   \
    \                 push(r);\n                    r = (2 * r + 1);\n           \
    \         if (g(op(d[r], sm))) {\n                        sm = op(d[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = op(d[r], sm);\n\
    \        } while ((r & -r) != r);\n        return 0;\n    }\n\n\nprivate:\n  \
    \  int _n, size, log;\n    vector<S> d;\n    vector<F> lz;\n\n    void update(int\
    \ k) {\n        d[k] = op(d[2*k], d[2*k+1]);\n    }\n    void all_apply(int k,\
    \ F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(2*k, lz[k]);\n   \
    \     all_apply(2*k+1, lz[k]);\n        lz[k] = id();\n    }\n};\n// }}}\n\n//\
    \ Examples {{{\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n// supports:\n\
    // - set a(l -> r) to val; val > NOT_SET\n// - add a(l -> r) += val\n// - find\
    \ sum a(l -> r)\n// - find min a(l -> r)\nstruct RangeSetAddMinSumOps {\n    struct\
    \ S { long long sum, min, sz; };\n    static S op(S l, S r) { return S { l.sum\
    \ + r.sum, min(l.min, r.min), l.sz + r.sz }; }\n    static S e() { return S {0LL,\
    \ INT_MAX, 0}; }\n\n    static const long long NOT_SET = -1000111000;\n    struct\
    \ F { long long set, add; };\n\n    static S mapping(F f, S s) {\n        if (f.set\
    \ == NOT_SET) {\n            return S {\n                s.sum + f.add * s.sz,\n\
    \                s.min + f.add,\n                s.sz,\n            };\n     \
    \   }\n        return S {\n            (f.set + f.add) * s.sz,\n            f.set\
    \ + f.add,\n            s.sz,\n        };\n    }\n    static F composition(F f,\
    \ F g) {\n        if (f.set == NOT_SET) {\n            return F { g.set, g.add\
    \ + f.add };\n        }\n        return f;\n    }\n    static F id() {\n     \
    \   return F { NOT_SET, 0 };\n    }\n};\n// }}}\n"
  code: "// Lazy Segment Tree, copied from AtCoder {{{\n// Source: https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    // Doc: https://atcoder.github.io/ac-library/master/document_en/lazysegtree.html\n\
    //\n// Notes:\n// - Index of elements from 0\n// - Range queries are [l, r-1]\n\
    // - composition(f, g) should return f(g())\n//\n// Tested:\n// - https://oj.vnoi.info/problem/qmax2\n\
    // - https://oj.vnoi.info/problem/lites\n// - (range set, add, mult, sum) https://oj.vnoi.info/problem/segtree_itmix\n\
    // - (range add (i-L)*A + B, sum) https://oj.vnoi.info/problem/segtree_itladder\n\
    // - https://atcoder.jp/contests/practice2/tasks/practice2_l\n// - https://judge.yosupo.jp/problem/range_affine_range_sum\n\
    \nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\ntemplate<\n    class S,                 // node data\
    \ type\n    S (*op) (S, S),          // combine 2 nodes\n    S (*e) (),      \
    \         // identity element\n    class F,                 // lazy propagation\
    \ tag\n    S (*mapping) (F, S),     // apply tag F on a node\n    F (*composition)\
    \ (F, F), // combine 2 tags\n    F (*id)()                // identity tag\n>\n\
    struct LazySegTree {\n    LazySegTree() : LazySegTree(0) {}\n    explicit LazySegTree(int\
    \ n) : LazySegTree(vector<S>(n, e())) {}\n    explicit LazySegTree(const vector<S>&\
    \ v) : _n((int) v.size()) {\n        log = ceil_pow2(_n);\n        size = 1 <<\
    \ log;\n        d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \n    // 0 <= p < n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n\n    // 0 <= p < n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      return d[p];\n    }\n\n    // Get product in range [l, r-1]\n    // 0 <=\
    \ l <= r <= n\n    // For empty segment (l == r) -> return e()\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    S sml = e(), smr = e();\n        while (l < r) {\n            if (l & 1)\
    \ sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n    \
    \        l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() {\n        return d[1];\n    }\n\n    // 0 <= p < n\n\
    \    void apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] =\
    \ mapping(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n\n    // Apply f on all elements in range [l, r-1]\n    // 0 <= l <= r\
    \ <= n\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if (l == r) return;\n\n        l += size;\n        r += size;\n\
    \n        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n\n        {\n            int l2 = l, r2 = r;\n            while (l\
    \ < r) {\n                if (l & 1) all_apply(l++, f);\n                if (r\
    \ & 1) all_apply(--r, f);\n                l >>= 1;\n                r >>= 1;\n\
    \            }\n            l = l2;\n            r = r2;\n        }\n\n      \
    \  for (int i = 1; i <= log; i++) {\n            if (((l >> i) << i) != l) update(l\
    \ >> i);\n            if (((r >> i) << i) != r) update((r - 1) >> i);\n      \
    \  }\n    }\n\n    // Binary search on SegTree to find largest r:\n    //    f(op(a[l]\
    \ .. a[r-1])) = true   (assuming empty array is always true)\n    //    f(op(a[l]\
    \ .. a[r])) = false    (assuming op(..., a[n]), which is out of bound, is always\
    \ false)\n    template <bool (*g)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n   \
    \     if (l == _n) return _n;\n        l += size;\n        for (int i = log; i\
    \ >= 1; i--) push(l >> i);\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!g(op(sm, d[l]))) {\n               \
    \ while (l < size) {\n                    push(l);\n                    l = (2\
    \ * l);\n                    if (g(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    // Binary search on SegTree to find smallest l:\n\
    \    //    f(op(a[l] .. a[r-1])) = true      (assuming empty array is always true)\n\
    \    //    f(op(a[l-1] .. a[r-1])) = false   (assuming op(a[-1], ..), which is\
    \ out of bound, is always false)\n    template <bool (*g)(S)> int min_left(int\
    \ r) {\n        return min_left(r, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int min_left(int r, G g) {\n        assert(0 <= r && r <= _n);\n \
    \       assert(g(e()));\n        if (r == 0) return 0;\n        r += size;\n \
    \       for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!g(op(d[r], sm))) {\n                while (r < size) {\n   \
    \                 push(r);\n                    r = (2 * r + 1);\n           \
    \         if (g(op(d[r], sm))) {\n                        sm = op(d[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = op(d[r], sm);\n\
    \        } while ((r & -r) != r);\n        return 0;\n    }\n\n\nprivate:\n  \
    \  int _n, size, log;\n    vector<S> d;\n    vector<F> lz;\n\n    void update(int\
    \ k) {\n        d[k] = op(d[2*k], d[2*k+1]);\n    }\n    void all_apply(int k,\
    \ F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(2*k, lz[k]);\n   \
    \     all_apply(2*k+1, lz[k]);\n        lz[k] = id();\n    }\n};\n// }}}\n\n//\
    \ Examples {{{\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n// supports:\n\
    // - set a(l -> r) to val; val > NOT_SET\n// - add a(l -> r) += val\n// - find\
    \ sum a(l -> r)\n// - find min a(l -> r)\nstruct RangeSetAddMinSumOps {\n    struct\
    \ S { long long sum, min, sz; };\n    static S op(S l, S r) { return S { l.sum\
    \ + r.sum, min(l.min, r.min), l.sz + r.sz }; }\n    static S e() { return S {0LL,\
    \ INT_MAX, 0}; }\n\n    static const long long NOT_SET = -1000111000;\n    struct\
    \ F { long long set, add; };\n\n    static S mapping(F f, S s) {\n        if (f.set\
    \ == NOT_SET) {\n            return S {\n                s.sum + f.add * s.sz,\n\
    \                s.min + f.add,\n                s.sz,\n            };\n     \
    \   }\n        return S {\n            (f.set + f.add) * s.sz,\n            f.set\
    \ + f.add,\n            s.sz,\n        };\n    }\n    static F composition(F f,\
    \ F g) {\n        if (f.set == NOT_SET) {\n            return F { g.set, g.add\
    \ + f.add };\n        }\n        return f;\n    }\n    static F id() {\n     \
    \   return F { NOT_SET, 0 };\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LazySegTree.h
  requiredBy:
  - DataStructure/misc/area_of_union_of_rectangles.h
  timestamp: '2022-08-09 14:38:08+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/aizu_dsl_2_g_segment_tree_rangeaddsum.test.cpp
  - DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp
  - DataStructure/test/aizu_dsl_2_i_segment_tree_rangesetsum.test.cpp
  - DataStructure/test/aizu_dsl_2_e_segment_tree_rangeadd.test.cpp
  - DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
  - DataStructure/test/aizu_dsl_2_d_segment_tree_rangeset.test.cpp
  - DataStructure/test/area_of_union_of_rectangles.test.cpp
  - DataStructure/test/segment_tree_rangeaffinepointget.test.cpp
  - DataStructure/test/aizu_dsl_2_f_segment_tree_rangesetmin.test.cpp
  - DataStructure/test/aizu_dsl_2_h_segment_tree_rangeaddmin.test.cpp
documentation_of: DataStructure/LazySegTree.h
layout: document
redirect_from:
- /library/DataStructure/LazySegTree.h
- /library/DataStructure/LazySegTree.h.html
title: DataStructure/LazySegTree.h
---
