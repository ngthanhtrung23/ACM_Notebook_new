---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree.h
    title: DataStructure/SegTree.h
  - icon: ':question:'
    path: Math/modulo_anta.h
    title: Math/modulo_anta.h
  - icon: ':heavy_check_mark:'
    path: buffered_reader.h
    title: buffered_reader.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/SegTree.h\"\
    \n// SegTree, copied from AtCoder library\n// AtCoder doc: https://atcoder.github.io/ac-library/master/document_en/segtree.html\n\
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
    \n    void update(int k) {\n        d[k] = op(d[2*k], d[2*k+1]);\n    }\n};\n\n\
    // Examples: Commonly used SegTree ops: max / min / sum\nstruct MaxSegTreeOp {\n\
    \    static int op(int x, int y) {\n        return max(x, y);\n    }\n    static\
    \ int e() {\n        return INT_MIN;\n    }\n};\n\nstruct MinSegTreeOp {\n   \
    \ static int op(int x, int y) {\n        return min(x, y);\n    }\n    static\
    \ int e() {\n        return INT_MAX;\n    }\n};\n\nstruct SumSegTreeOp {\n   \
    \ static long long op(long long x, long long y) {\n        return x + y;\n   \
    \ }\n    static long long e() {\n        return 0;\n    }\n};\n\n// Example\n\
    // SegTree<int, MaxSegTreeOp::f, MaxSegTreeOp::e> seg_tree(a);\n// SegTree<int,\
    \ MinSegTreeOp::f, MinSegTreeOp::e> seg_tree(a);\n#line 1 \"Math/modulo_anta.h\"\
    \n// Modified from anta's code\n// Not tested with MOD > 10^9 + 7.\n// Slow?\n\
    //\n// Tested:\n// - https://codeforces.com/gym/101383 - F (MOD = 1e9+7, +, *)\n\
    \n// ??? somehow this is 2.5x slower on https://judge.yosupo.jp/problem/matrix_product\n\
    inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d,\
    \ unsigned &out_m) {\n    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x,\
    \ d, m;\n#ifdef __GNUC__\n    asm(\n        \"divl %4; \\n\\t\"\n        : \"\
    =a\" (d), \"=d\" (m)\n        : \"d\" (xh), \"a\" (xl), \"r\" (y)\n    );\n#else\n\
    \    __asm {\n        mov edx, dword ptr[xh];\n        mov eax, dword ptr[xl];\n\
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
    };\n#line 9 \"DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp\"\
    \n\nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\nstruct Func {\n    modular a, b;\n};\n\nFunc op(Func l, Func r) {\n    return\
    \ Func{\n        l.a * r.a,\n        r.a * l.b + r.b\n    };\n}\nFunc e() {\n\
    \    return Func{1, 0};\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n = IO::get<int>();\n    int q = IO::get<int>();\n    vector<Func> funcs(n);\n\
    \    for (auto& f : funcs) {\n        int a = IO::get<int>();\n        int b =\
    \ IO::get<int>();\n        f = {a, b};\n    }\n\n    SegTree<Func, op, e> seg_tree(funcs);\n\
    \    while (q--) {\n        int typ = IO::get<int>();\n        if (typ == 0) {\n\
    \            int pos = IO::get<int>();\n            int a = IO::get<int>();\n\
    \            int b = IO::get<int>();\n            seg_tree.set(pos, {a, b});\n\
    \        } else {\n            int l = IO::get<int>();\n            int r = IO::get<int>();\n\
    \            auto f = seg_tree.prod(l, r);\n            modular x(IO::get<int>());\n\
    \            cout << f.a * x + f.b << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../SegTree.h\"\
    \n#include \"../../Math/modulo_anta.h\"\n#include \"../../buffered_reader.h\"\n\
    \nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\nstruct Func {\n    modular a, b;\n};\n\nFunc op(Func l, Func r) {\n    return\
    \ Func{\n        l.a * r.a,\n        r.a * l.b + r.b\n    };\n}\nFunc e() {\n\
    \    return Func{1, 0};\n}\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n = IO::get<int>();\n    int q = IO::get<int>();\n    vector<Func> funcs(n);\n\
    \    for (auto& f : funcs) {\n        int a = IO::get<int>();\n        int b =\
    \ IO::get<int>();\n        f = {a, b};\n    }\n\n    SegTree<Func, op, e> seg_tree(funcs);\n\
    \    while (q--) {\n        int typ = IO::get<int>();\n        if (typ == 0) {\n\
    \            int pos = IO::get<int>();\n            int a = IO::get<int>();\n\
    \            int b = IO::get<int>();\n            seg_tree.set(pos, {a, b});\n\
    \        } else {\n            int l = IO::get<int>();\n            int r = IO::get<int>();\n\
    \            auto f = seg_tree.prod(l, r);\n            modular x(IO::get<int>());\n\
    \            cout << f.a * x + f.b << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  dependsOn:
  - DataStructure/SegTree.h
  - Math/modulo_anta.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  requiredBy: []
  timestamp: '2022-01-12 13:12:33+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
- /verify/DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp.html
title: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
---
