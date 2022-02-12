---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegTree.h
    title: DataStructure/LazySegTree.h
  - icon: ':heavy_check_mark:'
    path: Math/modulo_anta.h
    title: Math/modulo_anta.h
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/LazySegTree.h\"\
    \n// Lazy Segment Tree, copied from AtCoder\n// Source: https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
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
    \     all_apply(2*k+1, lz[k]);\n        lz[k] = id();\n    }\n};\n\n//////////\
    \ BELOW: EXAMPLES\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
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
    \   return F { NOT_SET, 0 };\n    }\n};\n#line 1 \"Math/modulo_anta.h\"\n// Modified\
    \ from anta's code\n// Not tested with MOD > 10^9 + 7.\n// Slow?\n//\n// Tested:\n\
    // - https://codeforces.com/gym/101383 - F (MOD = 1e9+7, +, *)\n\n// ??? somehow\
    \ this is 2.5x slower on https://judge.yosupo.jp/problem/matrix_product\ninline\
    \ void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d, unsigned\
    \ &out_m) {\n    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;\n\
    #ifdef __GNUC__\n    asm(\n        \"divl %4; \\n\\t\"\n        : \"=a\" (d),\
    \ \"=d\" (m)\n        : \"d\" (xh), \"a\" (xl), \"r\" (y)\n    );\n#else\n   \
    \ __asm {\n        mov edx, dword ptr[xh];\n        mov eax, dword ptr[xl];\n\
    \        div dword ptr[y];\n        mov dword ptr[d], eax;\n        mov dword\
    \ ptr[m], edx;\n    };\n#endif\n    out_d = d; out_m = m;\n}\n\ntemplate<int MOD>\n\
    struct ModInt {\n    unsigned x;\n\n    constexpr ModInt() : x(0) { }\n    constexpr\
    \ ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD;\
    \ x = sigt; }\n\n#define COMPAREOP(OP) bool constexpr operator OP(ModInt b) const\
    \ { return x OP b.x; }\n    COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>)\
    \ COMPAREOP(<=) COMPAREOP(>=)\n#undef COMPAREOP\n\n    ModInt operator-() const\
    \ { return ModInt(x ? MOD - x : 0); }\n\n    ModInt constexpr& operator+=(ModInt\
    \ that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }\n    ModInt constexpr&\
    \ operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this;\
    \ }\n    ModInt &operator*=(ModInt that) {\n        unsigned dummy;\n        fasterLLDivMod((unsigned\
    \ long long)x * that.x, MOD, dummy, x);\n        return *this;\n    }\n    ModInt\
    \ operator*(ModInt that) const {\n        ModInt res;\n        unsigned dummy;\n\
    \        fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, res.x);\n\
    \        return res;\n    }\n    ModInt operator+(ModInt that) const { return\
    \ ModInt(*this) += that; }\n    ModInt operator-(ModInt that) const { return ModInt(*this)\
    \ -= that; }\n\n    // Below: copied from user202729_, not tested.\n    ModInt\
    \ inv() const {\n        int a = x, b = MOD, ax = 1, bx = 0;\n        while (b)\
    \ {\n            int q = a/b, t = a%b;\n            a = b; b = t;\n          \
    \  t = ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a ==\
    \ 1);\n        if (ax < 0) ax += MOD;\n        return ax;\n    }\n    ModInt&\
    \ operator /= (ModInt m) { return (*this) *= m.inv(); }\n    ModInt operator /\
    \ (ModInt that) const { return ModInt(*this) /= that; }\n};\n\ntemplate<int MOD>\n\
    ModInt<MOD> power(ModInt<MOD> n, long long k) {\n    if (k == 0) return ModInt<MOD>\
    \ (1);\n    ModInt<MOD> res(1);\n    while (k > 0) {\n        if (k & 1) res =\
    \ res * n;\n        n = n * n;\n        k >>= 1;\n    }\n    return res;\n}\n\n\
    /* Example:\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\nstd::ostream&\
    \ operator << (std::ostream& cout, const modular& m) {\n    cout << m.x;\n   \
    \ return cout;\n}\nstd::istream& operator >> (std::istream& cin, modular& m) {\n\
    \    cin >> m.x;\n    return cin;\n}\n*/\n#line 2 \"buffered_reader.h\"\nnamespace\
    \ IO {\n    const int BUFSIZE = 1<<14;\n    char buf[BUFSIZE + 1], *inp = buf;\n\
    \n    bool reacheof;\n    char get_char() {\n        if (!*inp && !reacheof) {\n\
    \            memset(buf, 0, sizeof buf);\n            int tmp = fread(buf, 1,\
    \ BUFSIZE, stdin);\n            if (tmp != BUFSIZE) reacheof = true;\n       \
    \     inp = buf;\n        }\n        return *inp++;\n    }\n    template<typename\
    \ T>\n    T get() {\n        int neg = 0;\n        T res = 0;\n        char c\
    \ = get_char();\n        while (!std::isdigit(c) && c != '-' && c != '+') c =\
    \ get_char();\n        if (c == '+') { neg = 0; }\n        else if (c == '-')\
    \ { neg = 1; }\n        else res = c - '0';\n\n        c = get_char();\n     \
    \   while (std::isdigit(c)) {\n            res = res * 10 + (c - '0');\n     \
    \       c = get_char();\n        }\n        return neg ? -res : res;\n    }\n\
    };\n#line 9 \"DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp\"\n\
    \nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\nstruct Node {\n    modular sum, sz;\n};\nstruct Lazy {\n    modular a, b;\n\
    };\n\nNode op(Node l, Node r) {\n    return Node {\n        l.sum + r.sum,\n \
    \       l.sz + r.sz\n    };\n}\nNode e() {\n    return Node{0, 0};\n}\n\nNode\
    \ apply(Lazy f, Node node) {\n    return Node{\n        f.a * node.sum + f.b *\
    \ node.sz,\n        node.sz\n    };\n}\nLazy combine(Lazy g, Lazy f) {\n    return\
    \ Lazy {\n        f.a * g.a,\n        g.a * f.b + g.b\n    };\n}\nLazy id() {\n\
    \    return Lazy{1, 0};\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, q; cin >> n >> q;\n    vector<Node> nodes(n);\n    for (auto& node\
    \ : nodes) {\n        cin >> node.sum;\n        node.sz = 1;\n    }\n    LazySegTree<Node,\
    \ op, e, Lazy, apply, combine, id> st(nodes);\n\n    while (q--) {\n        int\
    \ typ; cin >> typ;\n        if (typ == 0) {\n            int l, r;\n         \
    \   Lazy f;\n            cin >> l >> r >> f.a >> f.b;\n            st.apply(l,\
    \ r, f);\n        } else {\n            int l, r; cin >> l >> r;\n           \
    \ cout << st.prod(l, r).sum << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../LazySegTree.h\"\
    \n#include \"../../Math/modulo_anta.h\"\n#include \"../../buffered_reader.h\"\n\
    \nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\nstruct Node {\n    modular sum, sz;\n};\nstruct Lazy {\n    modular a, b;\n\
    };\n\nNode op(Node l, Node r) {\n    return Node {\n        l.sum + r.sum,\n \
    \       l.sz + r.sz\n    };\n}\nNode e() {\n    return Node{0, 0};\n}\n\nNode\
    \ apply(Lazy f, Node node) {\n    return Node{\n        f.a * node.sum + f.b *\
    \ node.sz,\n        node.sz\n    };\n}\nLazy combine(Lazy g, Lazy f) {\n    return\
    \ Lazy {\n        f.a * g.a,\n        g.a * f.b + g.b\n    };\n}\nLazy id() {\n\
    \    return Lazy{1, 0};\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, q; cin >> n >> q;\n    vector<Node> nodes(n);\n    for (auto& node\
    \ : nodes) {\n        cin >> node.sum;\n        node.sz = 1;\n    }\n    LazySegTree<Node,\
    \ op, e, Lazy, apply, combine, id> st(nodes);\n\n    while (q--) {\n        int\
    \ typ; cin >> typ;\n        if (typ == 0) {\n            int l, r;\n         \
    \   Lazy f;\n            cin >> l >> r >> f.a >> f.b;\n            st.apply(l,\
    \ r, f);\n        } else {\n            int l, r; cin >> l >> r;\n           \
    \ cout << st.prod(l, r).sum << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/LazySegTree.h
  - Math/modulo_anta.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
  requiredBy: []
  timestamp: '2022-01-12 13:12:33+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
- /verify/DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp.html
title: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
---
