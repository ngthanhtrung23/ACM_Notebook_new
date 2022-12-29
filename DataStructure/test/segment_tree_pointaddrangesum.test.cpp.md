---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree.h
    title: DataStructure/SegTree.h
  - icon: ':question:'
    path: buffered_reader.h
    title: buffered_reader.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"DataStructure/test/segment_tree_pointaddrangesum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/SegTree.h\"\
    \n// SegTree, copied from AtCoder library {{{\n// AtCoder doc: https://atcoder.github.io/ac-library/master/document_en/segtree.html\n\
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
    \  return 0;\n    }\n};\n\n// using STMax = SegTree<int, MaxSegTreeOp::op, MaxSegTreeOp::e>;\n\
    // using STMin = SegTree<int, MinSegTreeOp::op, MinSegTreeOp::e>;\n// using STSum\
    \ = SegTree<int, SumSegTreeOp::op, SumSegTreeOp::e>;\n// }}}\n#line 1 \"buffered_reader.h\"\
    \n// Buffered reader {{{\nnamespace IO {\n    const int BUFSIZE = 1<<14;\n   \
    \ char buf[BUFSIZE + 1], *inp = buf;\n\n    bool reacheof;\n    char get_char()\
    \ {\n        if (!*inp && !reacheof) {\n            memset(buf, 0, sizeof buf);\n\
    \            int tmp = fread(buf, 1, BUFSIZE, stdin);\n            if (tmp !=\
    \ BUFSIZE) reacheof = true;\n            inp = buf;\n        }\n        return\
    \ *inp++;\n    }\n    template<typename T>\n    T get() {\n        int neg = 0;\n\
    \        T res = 0;\n        char c = get_char();\n        while (!std::isdigit(c)\
    \ && c != '-' && c != '+') c = get_char();\n        if (c == '+') { neg = 0; }\n\
    \        else if (c == '-') { neg = 1; }\n        else res = c - '0';\n\n    \
    \    c = get_char();\n        while (std::isdigit(c)) {\n            res = res\
    \ * 10 + (c - '0');\n            c = get_char();\n        }\n        return neg\
    \ ? -res : res;\n    }\n};\n// Helper methods\nint ri() {\n    return IO::get<int>();\n\
    }\n// }}}\n#line 8 \"DataStructure/test/segment_tree_pointaddrangesum.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin >> n >> q;\n\
    \    vector<long long> a(n);\n    for (auto& x : a) cin >> x;\n\n    SegTree<long\
    \ long, SumSegTreeOp::op, SumSegTreeOp::e> seg_tree(a);\n\n    while (q--) {\n\
    \        int typ; cin >> typ;\n        if (typ == 0) {\n            int pos, val;\
    \ cin >> pos >> val;\n            seg_tree.set(pos, seg_tree.get(pos) + val);\n\
    \        } else {\n            int l, r; cin >> l >> r;\n            cout << seg_tree.prod(l,\
    \ r) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../SegTree.h\"\n\
    #include \"../../buffered_reader.h\"\n\n#define REP(i, a) for (int i = 0, _##i\
    \ = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, q; cin >> n >> q;\n    vector<long long> a(n);\n    for (auto& x :\
    \ a) cin >> x;\n\n    SegTree<long long, SumSegTreeOp::op, SumSegTreeOp::e> seg_tree(a);\n\
    \n    while (q--) {\n        int typ; cin >> typ;\n        if (typ == 0) {\n \
    \           int pos, val; cin >> pos >> val;\n            seg_tree.set(pos, seg_tree.get(pos)\
    \ + val);\n        } else {\n            int l, r; cin >> l >> r;\n          \
    \  cout << seg_tree.prod(l, r) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/SegTree.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 14:26:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/segment_tree_pointaddrangesum.test.cpp
- /verify/DataStructure/test/segment_tree_pointaddrangesum.test.cpp.html
title: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
---
