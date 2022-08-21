---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree.h
    title: DataStructure/SegTree.h
  - icon: ':question:'
    path: Math/modint.h
    title: Math/modint.h
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
    \  return 0;\n    }\n};\n\n// Example\n// SegTree<int, MaxSegTreeOp::op, MaxSegTreeOp::e>\
    \ seg_tree(a);\n// SegTree<int, MinSegTreeOp::op, MinSegTreeOp::e> seg_tree(a);\n\
    // }}}\n#line 1 \"Math/modint.h\"\n// ModInt {{{\ntemplate<int MD> struct ModInt\
    \ {\n    using ll = long long;\n    int x;\n\n    constexpr ModInt() : x(0) {}\n\
    \    constexpr ModInt(ll v) { _set(v % MD + MD); }\n    constexpr static int mod()\
    \ { return MD; }\n    constexpr explicit operator bool() const { return x != 0;\
    \ }\n\n    constexpr ModInt operator + (const ModInt& a) const {\n        return\
    \ ModInt()._set((ll) x + a.x);\n    }\n    constexpr ModInt operator - (const\
    \ ModInt& a) const {\n        return ModInt()._set((ll) x - a.x + MD);\n    }\n\
    \    constexpr ModInt operator * (const ModInt& a) const {\n        return ModInt()._set((ll)\
    \ x * a.x % MD);\n    }\n    constexpr ModInt operator / (const ModInt& a) const\
    \ {\n        return ModInt()._set((ll) x * a.inv().x % MD);\n    }\n    constexpr\
    \ ModInt operator - () const {\n        return ModInt()._set(MD - x);\n    }\n\
    \n    constexpr ModInt& operator += (const ModInt& a) { return *this = *this +\
    \ a; }\n    constexpr ModInt& operator -= (const ModInt& a) { return *this = *this\
    \ - a; }\n    constexpr ModInt& operator *= (const ModInt& a) { return *this =\
    \ *this * a; }\n    constexpr ModInt& operator /= (const ModInt& a) { return *this\
    \ = *this / a; }\n\n    friend constexpr ModInt operator + (ll a, const ModInt&\
    \ b) {\n        return ModInt()._set(a % MD + b.x);\n    }\n    friend constexpr\
    \ ModInt operator - (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD - b.x + MD);\n    }\n    friend constexpr ModInt operator * (ll a, const\
    \ ModInt& b) {\n        return ModInt()._set(a % MD * b.x % MD);\n    }\n    friend\
    \ constexpr ModInt operator / (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD * b.inv().x % MD);\n    }\n\n    constexpr bool operator == (const ModInt&\
    \ a) const { return x == a.x; }\n    constexpr bool operator != (const ModInt&\
    \ a) const { return x != a.x; }\n\n    friend std::istream& operator >> (std::istream&\
    \ is, ModInt& x) {\n        ll val; is >> val;\n        x = ModInt(val);\n   \
    \     return is;\n    }\n    constexpr friend std::ostream& operator << (std::ostream&\
    \ os, const ModInt& x) {\n        return os << x.x;\n    }\n\n    constexpr ModInt\
    \ pow(ll k) const {\n        ModInt ans = 1, tmp = x;\n        while (k) {\n \
    \           if (k & 1) ans *= tmp;\n            tmp *= tmp;\n            k >>=\
    \ 1;\n        }\n        return ans;\n    }\n\n    constexpr ModInt inv() const\
    \ {\n        if (x < 1000111) {\n            _precalc(1000111);\n            return\
    \ invs[x];\n        }\n        int a = x, b = MD, ax = 1, bx = 0;\n        while\
    \ (b) {\n            int q = a/b, t = a%b;\n            a = b; b = t;\n      \
    \      t = ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a\
    \ == 1);\n        if (ax < 0) ax += MD;\n        return ax;\n    }\n\n    static\
    \ std::vector<ModInt> factorials, inv_factorials, invs;\n    constexpr static\
    \ void _precalc(int n) {\n        if (factorials.empty()) {\n            factorials\
    \ = {1};\n            inv_factorials = {1};\n            invs = {0};\n       \
    \ }\n        if (n > MD) n = MD;\n        int old_sz = factorials.size();\n  \
    \      if (n <= old_sz) return;\n\n        factorials.resize(n);\n        inv_factorials.resize(n);\n\
    \        invs.resize(n);\n\n        for (int i = old_sz; i < n; ++i) factorials[i]\
    \ = factorials[i-1] * i;\n        inv_factorials[n-1] = factorials.back().pow(MD\
    \ - 2);\n        for (int i = n - 2; i >= old_sz; --i) inv_factorials[i] = inv_factorials[i+1]\
    \ * (i+1);\n        for (int i = n-1; i >= old_sz; --i) invs[i] = inv_factorials[i]\
    \ * factorials[i-1];\n    }\n\n    static int get_primitive_root() {\n       \
    \ static int primitive_root = 0;\n        if (!primitive_root) {\n           \
    \ primitive_root = [&]() {\n                std::set<int> fac;\n             \
    \   int v = MD - 1;\n                for (ll i = 2; i * i <= v; i++)\n       \
    \             while (v % i == 0) fac.insert(i), v /= i;\n                if (v\
    \ > 1) fac.insert(v);\n                for (int g = 1; g < MD; g++) {\n      \
    \              bool ok = true;\n                    for (auto i : fac)\n     \
    \                   if (ModInt(g).pow((MD - 1) / i) == 1) {\n                \
    \            ok = false;\n                            break;\n               \
    \         }\n                    if (ok) return g;\n                }\n      \
    \          return -1;\n            }();\n        }\n        return primitive_root;\n\
    \    }\n    \nprivate:\n    // Internal, DO NOT USE.\n    // val must be in [0,\
    \ 2*MD)\n    constexpr inline __attribute__((always_inline)) ModInt& _set(ll v)\
    \ {\n        x = v >= MD ? v - MD : v;\n        return *this;\n    }\n};\ntemplate\
    \ <int MD> std::vector<ModInt<MD>> ModInt<MD>::factorials = {1};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::inv_factorials = {1};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n// }}}\n#line 1 \"buffered_reader.h\"\
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
    \ ? -res : res;\n    }\n};\n// }}}\n#line 9 \"DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp\"\
    \n\nusing modular = ModInt<998244353>;\n\nstruct Func {\n    modular a, b;\n};\n\
    \nFunc op(Func l, Func r) {\n    return Func{\n        l.a * r.a,\n        r.a\
    \ * l.b + r.b\n    };\n}\nFunc e() {\n    return Func{1, 0};\n}\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n \
    \   int q = IO::get<int>();\n    vector<Func> funcs(n);\n    for (auto& f : funcs)\
    \ {\n        int a = IO::get<int>();\n        int b = IO::get<int>();\n      \
    \  f = {a, b};\n    }\n\n    SegTree<Func, op, e> seg_tree(funcs);\n    while\
    \ (q--) {\n        int typ = IO::get<int>();\n        if (typ == 0) {\n      \
    \      int pos = IO::get<int>();\n            int a = IO::get<int>();\n      \
    \      int b = IO::get<int>();\n            seg_tree.set(pos, {a, b});\n     \
    \   } else {\n            int l = IO::get<int>();\n            int r = IO::get<int>();\n\
    \            auto f = seg_tree.prod(l, r);\n            modular x(IO::get<int>());\n\
    \            cout << f.a * x + f.b << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../SegTree.h\"\
    \n#include \"../../Math/modint.h\"\n#include \"../../buffered_reader.h\"\n\nusing\
    \ modular = ModInt<998244353>;\n\nstruct Func {\n    modular a, b;\n};\n\nFunc\
    \ op(Func l, Func r) {\n    return Func{\n        l.a * r.a,\n        r.a * l.b\
    \ + r.b\n    };\n}\nFunc e() {\n    return Func{1, 0};\n}\n\nint32_t main() {\n\
    \    ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n    int\
    \ q = IO::get<int>();\n    vector<Func> funcs(n);\n    for (auto& f : funcs) {\n\
    \        int a = IO::get<int>();\n        int b = IO::get<int>();\n        f =\
    \ {a, b};\n    }\n\n    SegTree<Func, op, e> seg_tree(funcs);\n    while (q--)\
    \ {\n        int typ = IO::get<int>();\n        if (typ == 0) {\n            int\
    \ pos = IO::get<int>();\n            int a = IO::get<int>();\n            int\
    \ b = IO::get<int>();\n            seg_tree.set(pos, {a, b});\n        } else\
    \ {\n            int l = IO::get<int>();\n            int r = IO::get<int>();\n\
    \            auto f = seg_tree.prod(l, r);\n            modular x(IO::get<int>());\n\
    \            cout << f.a * x + f.b << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  dependsOn:
  - DataStructure/SegTree.h
  - Math/modint.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  requiredBy: []
  timestamp: '2022-08-21 23:32:29+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
- /verify/DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp.html
title: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
---
