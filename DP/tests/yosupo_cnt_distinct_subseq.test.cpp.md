---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/cnt_distinct_subseq.h
    title: DP/cnt_distinct_subseq.h
  - icon: ':question:'
    path: Math/modint.h
    title: Math/modint.h
  - icon: ':heavy_check_mark:'
    path: Misc/compress.h
    title: Misc/compress.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_subsequences
    links:
    - https://judge.yosupo.jp/problem/number_of_subsequences
  bundledCode: "#line 1 \"DP/tests/yosupo_cnt_distinct_subseq.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\n\n#line\
    \ 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b);\
    \ i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a)\
    \ for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x)\
    \ { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a\
    \ << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n)\
    \ { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define\
    \ sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n// Copied from\
    \ https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\ntemplate<class\
    \ U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {\n   \
    \ return out << '(' << p.first << \", \" << p.second << ')';\n}\n\ntemplate<class\
    \ Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Misc/compress.h\"\n// Compressor {{{\n\
    /* Example usage:\n    auto compressor = CompressorBuilder<T>{vs}.build();\n \
    \   int x = compessor.must_eq(vs[0]);\n    compressor.compress_inplace(vs);\n\
    */\n// Based on https://suisen-cp.github.io/cp-library-cpp/library/util/coordinate_compressor.hpp\n\
    template<typename T>\nstruct CompressorBuilder {\n    // Do not use directly.\
    \ Use builder.build()\n    struct Compressor {\n        // Number of unique keys\n\
    \        int size() const { return xs.size(); }\n\n        void compress_inplace(std::vector<T>&\
    \ vals) {\n            for (int& val : vals) {\n                val = must_eq(val);\n\
    \            }\n        }\n\n        [[nodiscard]] std::vector<T> compress(const\
    \ std::vector<T>& vals) {\n            std::vector<T> res(vals.size());\n    \
    \        for (int i = 0; i < static_cast<int> (res.size()); ++i) {\n         \
    \       res[i] = must_eq(vals[i]);\n            }\n            return res;\n \
    \       }\n\n        bool has_key(const T& key) const {\n            return std::binary_search(xs.begin(),\
    \ xs.end(), key);\n        }\n\n#define LB(key) std::lower_bound(xs.begin(), xs.end(),\
    \ key)\n#define UB(key) std::upper_bound(xs.begin(), xs.end(), key)\n        std::optional<int>\
    \ eq(const T& key) {\n            auto it = LB(key);\n            return it ==\
    \ xs.end() ? std::nullopt : std::optional<int>{it - xs.begin()};\n        }\n\
    \        std::optional<int> geq(const T& key) {\n            auto it = LB(key);\n\
    \            return it == xs.end() ? std::nullopt : std::optional<int>{it - xs.begin()};\n\
    \        }\n        std::optional<int> gt(const T& key) {\n            auto it\
    \ = UB(key);\n            return it == xs.end() ? std::nullopt : std::optional<int>{it\
    \ - xs.begin()};\n        }\n        std::optional<int> leq(const T& key) {\n\
    \            auto it = UB(key);\n            return it == xs.begin() ? std::nullopt\
    \ : std::optional<int>{it - xs.begin() - 1};\n        }\n        std::optional<int>\
    \ lt(const T& key) {\n            auto it = LB(key);\n            return it ==\
    \ xs.begin() ? std::nullopt : std::optional<int>{it - xs.begin() - 1};\n     \
    \   }\n\n        // throw exception if no such key is found\n        int must_eq(const\
    \ T& key) {\n            auto it = LB(key);\n            assert(it != xs.end());\n\
    \            return it - xs.begin();\n        }\n        // throw exception if\
    \ no such key is found\n        int must_geq(const T& key) {\n            auto\
    \ it = LB(key);\n            assert(it != xs.end());\n            return it -\
    \ xs.begin();\n        }\n        // throw exception if no such key is found\n\
    \        int must_gt(const T& key) {\n            auto it = UB(key);\n       \
    \     assert(it != xs.end());\n            return it - xs.begin();\n        }\n\
    \        // throw exception if no such key is found\n        int must_leq(const\
    \ T& key) {\n            auto it = UB(key);\n            assert(it != xs.begin());\n\
    \            return it - xs.begin() - 1;\n        }\n        // throw exception\
    \ if no such key is found\n        int must_lt(const T& key) {\n            auto\
    \ it = LB(key);\n            assert(it != xs.begin());\n            return it\
    \ - xs.begin() - 1;\n        }\n#undef LB\n#undef UB\n\n        std::vector<T>\
    \ xs;\n    };\n\n    auto build() {\n        std::sort(xs.begin(), xs.end());\n\
    \        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n        return\
    \ Compressor{xs};\n    }\n\n    void add(const T& key) { xs.push_back(key); }\n\
    \    void add(T&& key) { xs.push_back(std::move(key)); }\n\n    std::vector<T>\
    \ xs;\n};\n// }}}\n#line 2 \"DP/cnt_distinct_subseq.h\"\n\n// Returns number of\
    \ distinct, non-empty subsequences {{{\n// T = type of input elements\n// OutT\
    \ = type of output (e.g. ModInt)\ntemplate<typename T, typename OutT>\nOutT cnt_distinct_subsequences(std::vector<T>\
    \ a) {\n    auto compressor = CompressorBuilder<T>{a}.build();\n    compressor.compress_inplace(a);\n\
    \n    std::vector<OutT> f(a.size() + 1);\n    std::vector<int> last(a.size() +\
    \ 1, -1);\n    f[0] = 1;\n    for (size_t i = 0; i < a.size(); ++i) {\n      \
    \  f[i+1] = f[i] * 2;\n        if (last[a[i]] >= 0) f[i+1] -= f[last[a[i]]];\n\
    \        last[a[i]] = i;\n    }\n    return f.back() - 1;\n}\n// }}}\n#line 1\
    \ \"Math/modint.h\"\n// ModInt {{{\ntemplate<int MD> struct ModInt {\n    using\
    \ ll = long long;\n    int x;\n\n    constexpr ModInt() : x(0) {}\n    constexpr\
    \ ModInt(ll v) { _set(v % MD + MD); }\n    constexpr static int mod() { return\
    \ MD; }\n    constexpr explicit operator bool() const { return x != 0; }\n\n \
    \   constexpr ModInt operator + (const ModInt& a) const {\n        return ModInt()._set((ll)\
    \ x + a.x);\n    }\n    constexpr ModInt operator - (const ModInt& a) const {\n\
    \        return ModInt()._set((ll) x - a.x + MD);\n    }\n    constexpr ModInt\
    \ operator * (const ModInt& a) const {\n        return ModInt()._set((ll) x *\
    \ a.x % MD);\n    }\n    constexpr ModInt operator / (const ModInt& a) const {\n\
    \        return ModInt()._set((ll) x * a.inv().x % MD);\n    }\n    constexpr\
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
    \    }\n\n    static ModInt C(int n, int k) {\n        _precalc(n + 1);\n    \
    \    return factorials[n] * inv_factorials[k] * inv_factorials[n-k];\n    }\n\
    \    \nprivate:\n    // Internal, DO NOT USE.\n    // val must be in [0, 2*MD)\n\
    \    constexpr inline __attribute__((always_inline)) ModInt& _set(ll v) {\n  \
    \      x = v >= MD ? v - MD : v;\n        return *this;\n    }\n};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::factorials = {1};\ntemplate <int MD>\
    \ std::vector<ModInt<MD>> ModInt<MD>::inv_factorials = {1};\ntemplate <int MD>\
    \ std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n// }}}\n#line 6 \"DP/tests/yosupo_cnt_distinct_subseq.test.cpp\"\
    \n\nconst int MOD = 998244353;\nusing mint = ModInt<MOD>;\n\nvoid solve() {\n\
    \    int n; cin >> n;\n    vector<int> a(n);\n    REP(i,n) cin >> a[i];\n\n  \
    \  cout << cnt_distinct_subsequences<int, mint> (a) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\
    \n\n#include \"../../template.h\"\n#include \"../cnt_distinct_subseq.h\"\n#include\
    \ \"../../Math/modint.h\"\n\nconst int MOD = 998244353;\nusing mint = ModInt<MOD>;\n\
    \nvoid solve() {\n    int n; cin >> n;\n    vector<int> a(n);\n    REP(i,n) cin\
    \ >> a[i];\n\n    cout << cnt_distinct_subsequences<int, mint> (a) << endl;\n\
    }\n"
  dependsOn:
  - template.h
  - DP/cnt_distinct_subseq.h
  - Misc/compress.h
  - Math/modint.h
  isVerificationFile: true
  path: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
  requiredBy: []
  timestamp: '2022-12-29 17:34:35+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
layout: document
redirect_from:
- /verify/DP/tests/yosupo_cnt_distinct_subseq.test.cpp
- /verify/DP/tests/yosupo_cnt_distinct_subseq.test.cpp.html
title: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
---
