---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree.h
    title: DataStructure/SegTree.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"DataStructure/test/aizu_dsl_2_a_segment_tree_rmq_update.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int\
    \ i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n\
    #define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\
    \n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n)\
    \ { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define\
    \ PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl;\
    \ }\n\n#define sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n//\
    \ Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
    template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>&\
    \ p) {\n    return out << '(' << p.first << \", \" << p.second << ')';\n}\n\n\
    template<class Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
    \ string>::value, ostream&>::type\noperator << (ostream& out, const Con& con)\
    \ {\n    out << '{';\n    for (auto beg = con.begin(), it = beg; it != con.end();\
    \ it++) {\n        out << (it == beg ? \"\" : \", \") << *it;\n    }\n    return\
    \ out << '}';\n}\ntemplate<size_t i, class T> ostream& print_tuple_utils(ostream&\
    \ out, const T& tup) {\n    if constexpr(i == tuple_size<T>::value) return out\
    \ << \")\"; \n    else return print_tuple_utils<i + 1, T>(out << (i ? \", \" :\
    \ \"(\") << get<i>(tup), tup); \n}\ntemplate<class ...U> ostream& operator <<\
    \ (ostream& out, const tuple<U...>& t) {\n    return print_tuple_utils<0, tuple<U...>>(out,\
    \ t);\n}\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r) {\n    return uniform_int_distribution<long long>\
    \ (0, r-1)(rng);\n}\n\ntemplate<typename T>\nvector<T> read_vector(int n) {\n\
    \    vector<T> res(n);\n    for (int& x : res) cin >> x;\n    return res;\n}\n\
    \nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n  \
    \  solve();\n    return 0;\n}\n#line 1 \"DataStructure/SegTree.h\"\n// SegTree,\
    \ copied from AtCoder library {{{\n// AtCoder doc: https://atcoder.github.io/ac-library/master/document_en/segtree.html\n\
    //\n// Notes:\n// - Index of elements from 0 -> n-1\n// - Range queries are [l,\
    \ r-1]\n//\n// Tested:\n// - (binary search) https://atcoder.jp/contests/practice2/tasks/practice2_j\n\
    // - https://oj.vnoi.info/problem/gss\n// - https://oj.vnoi.info/problem/nklineup\n\
    // - (max_right & min_left for delete position queries) https://oj.vnoi.info/problem/segtree_itstr\n\
    // - https://judge.yosupo.jp/problem/point_add_range_sum\n// - https://judge.yosupo.jp/problem/point_set_range_composite\n\
    int ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\ntemplate<\n    class T,  // data type for nodes\n\
    \    T (*op) (T, T),  // operator to combine 2 nodes\n    T (*e)() // identity\
    \ element\n>\nstruct SegTree {\n    SegTree() : SegTree(0) {}\n    explicit SegTree(int\
    \ n) : SegTree(vector<T> (n, e())) {}\n    explicit SegTree(const vector<T>& v)\
    \ : _n((int) v.size()) {\n        log = ceil_pow2(_n);\n        size = 1<<log;\n\
    \        d = vector<T> (2*size, e());\n\n        for (int i = 0; i < _n; i++)\
    \ d[size+i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n         \
    \   update(i);\n        }\n    }\n\n    // 0 <= p < n\n    void set(int p, T x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p] = x;\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    // 0 <=\
    \ p < n\n    T get(int p) const {\n        assert(0 <= p && p < _n);\n       \
    \ return d[p + size];\n    }\n\n    // Get product in range [l, r-1]\n    // 0\
    \ <= l <= r <= n\n    // For empty segment (l == r) -> return e()\n    T prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n        T sml\
    \ = e(), smr = e();\n        l += size;\n        r += size;\n        while (l\
    \ < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1)\
    \ smr = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n       \
    \ }\n        return op(sml, smr);\n    }\n\n    T all_prod() const {\n       \
    \ return d[1];\n    }\n\n    // Binary search on SegTree to find largest r:\n\
    \    //    f(op(a[l] .. a[r-1])) = true   (assuming empty array is always true)\n\
    \    //    f(op(a[l] .. a[r])) = false    (assuming op(..., a[n]), which is out\
    \ of bound, is always false)\n    template <bool (*f)(T)> int max_right(int l)\
    \ const {\n        return max_right(l, [](T x) { return f(x); });\n    }\n   \
    \ template <class F> int max_right(int l, F f) const {\n        assert(0 <= l\
    \ && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n   \
    \     l += size;\n        T sm = e();\n        do {\n            while (l % 2\
    \ == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while (l\
    \ < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    // Binary search\
    \ on SegTree to find smallest l:\n    //    f(op(a[l] .. a[r-1])) = true     \
    \ (assuming empty array is always true)\n    //    f(op(a[l-1] .. a[r-1])) = false\
    \   (assuming op(a[-1], ..), which is out of bound, is always false)\n    template\
    \ <bool (*f)(T)> int min_left(int r) const {\n        return min_left(r, [](T\
    \ x) { return f(x); });\n    }\n    template <class F> int min_left(int r, F f)\
    \ const {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n     \
    \   if (r == 0) return 0;\n        r += size;\n        T sm = e();\n        do\
    \ {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n       \
    \     if (!f(op(d[r], sm))) {\n                while (r < size) {\n          \
    \          r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n    \
    \                    sm = op(d[r], sm);\n                        r--;\n      \
    \              }\n                }\n                return r + 1 - size;\n  \
    \          }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\nprivate:\n    int _n, size, log;\n    vector<T> d;\n\
    \n    void update(int k) {\n        d[k] = op(d[2*k], d[2*k+1]);\n    }\n};\n\
    // }}}\n\n// SegTree examples {{{\n// Examples: Commonly used SegTree ops: max\
    \ / min / sum\nstruct MaxSegTreeOp {\n    static int op(int x, int y) {\n    \
    \    return max(x, y);\n    }\n    static int e() {\n        return INT_MIN;\n\
    \    }\n};\n\nstruct MinSegTreeOp {\n    static int op(int x, int y) {\n     \
    \   return min(x, y);\n    }\n    static int e() {\n        return INT_MAX;\n\
    \    }\n};\n\nstruct SumSegTreeOp {\n    static long long op(long long x, long\
    \ long y) {\n        return x + y;\n    }\n    static long long e() {\n      \
    \  return 0;\n    }\n};\n\n// Example\n// SegTree<int, MaxSegTreeOp::op, MaxSegTreeOp::e>\
    \ seg_tree(a);\n// SegTree<int, MinSegTreeOp::op, MinSegTreeOp::e> seg_tree(a);\n\
    // }}}\n#line 5 \"DataStructure/test/aizu_dsl_2_a_segment_tree_rmq_update.test.cpp\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    SegTree<int, MinSegTreeOp::op,\
    \ MinSegTreeOp::e> st(n);\n    while (q--) {\n        int typ; cin >> typ;\n \
    \       if (typ == 0) {\n            int pos, val; cin >> pos >> val;\n      \
    \      st.set(pos, val);\n        } else {\n            int l, r; cin >> l >>\
    \ r;\n            cout << st.prod(l, r+1) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include \"../../template.h\"\n#include \"../SegTree.h\"\n\nvoid solve() {\n\
    \    int n, q; cin >> n >> q;\n    SegTree<int, MinSegTreeOp::op, MinSegTreeOp::e>\
    \ st(n);\n    while (q--) {\n        int typ; cin >> typ;\n        if (typ ==\
    \ 0) {\n            int pos, val; cin >> pos >> val;\n            st.set(pos,\
    \ val);\n        } else {\n            int l, r; cin >> l >> r;\n            cout\
    \ << st.prod(l, r+1) << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - template.h
  - DataStructure/SegTree.h
  isVerificationFile: true
  path: DataStructure/test/aizu_dsl_2_a_segment_tree_rmq_update.test.cpp
  requiredBy: []
  timestamp: '2022-08-09 14:38:08+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/aizu_dsl_2_a_segment_tree_rmq_update.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/aizu_dsl_2_a_segment_tree_rmq_update.test.cpp
- /verify/DataStructure/test/aizu_dsl_2_a_segment_tree_rmq_update.test.cpp.html
title: DataStructure/test/aizu_dsl_2_a_segment_tree_rmq_update.test.cpp
---
