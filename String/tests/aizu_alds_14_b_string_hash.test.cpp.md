---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modint.h
    title: Math/modint.h
  - icon: ':heavy_check_mark:'
    path: String/hash.h
    title: String/hash.h
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"String/tests/aizu_alds_14_b_string_hash.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"String/hash.h\"\n// Usage:\n// HashGenerator\
    \ g(MAX_LENGTH)\n//\n// auto h = g.hash(s)\n// g.equals(s, h, l1, r1, s, h, l2,\
    \ r2)\n// g.cmp(s, h, l1, r1, s, h, l2, r2)\n//\n// Tested:\n// - https://oj.vnoi.info/problem/substr\n\
    // - https://oj.vnoi.info/problem/paliny  - max palin / binary search\n// - https://oj.vnoi.info/problem/dtksub\
    \  - hash<Hash> for unordered_map\n// - https://oj.vnoi.info/problem/vostr   -\
    \ cmp\n\n#line 1 \"Math/modint.h\"\n// ModInt {{{\ntemplate<int MD> struct ModInt\
    \ {\n    using ll = long long;\n    int x;\n\n    constexpr ModInt() : x(0) {}\n\
    \    constexpr ModInt(ll v) { _set(v % MD + MD); }\n    constexpr explicit operator\
    \ bool() const { return x != 0; }\n\n    constexpr ModInt operator + (const ModInt&\
    \ a) const {\n        return ModInt()._set((ll) x + a.x);\n    }\n    constexpr\
    \ ModInt operator - (const ModInt& a) const {\n        return ModInt()._set((ll)\
    \ x - a.x + MD);\n    }\n    constexpr ModInt operator * (const ModInt& a) const\
    \ {\n        return ModInt()._set((ll) x * a.x % MD);\n    }\n    constexpr ModInt\
    \ operator / (const ModInt& a) const {\n        return ModInt()._set((ll) x *\
    \ a.inv().x % MD);\n    }\n    constexpr ModInt operator - () const {\n      \
    \  return ModInt()._set(MD - x);\n    }\n\n    constexpr ModInt& operator += (const\
    \ ModInt& a) { return *this = *this + a; }\n    constexpr ModInt& operator -=\
    \ (const ModInt& a) { return *this = *this - a; }\n    constexpr ModInt& operator\
    \ *= (const ModInt& a) { return *this = *this * a; }\n    constexpr ModInt& operator\
    \ /= (const ModInt& a) { return *this = *this / a; }\n\n    friend constexpr ModInt\
    \ operator + (ll a, const ModInt& b) {\n        return ModInt()._set(a % MD +\
    \ b.x);\n    }\n    friend constexpr ModInt operator - (ll a, const ModInt& b)\
    \ {\n        return ModInt()._set(a % MD - b.x + MD);\n    }\n    friend constexpr\
    \ ModInt operator * (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD * b.x % MD);\n    }\n    friend constexpr ModInt operator / (ll a, const\
    \ ModInt& b) {\n        return ModInt()._set(a % MD * b.inv().x % MD);\n    }\n\
    \n    constexpr bool operator == (const ModInt& a) const { return x == a.x; }\n\
    \    constexpr bool operator != (const ModInt& a) const { return x != a.x; }\n\
    \n    friend std::istream& operator >> (std::istream& is, ModInt& x) {\n     \
    \   ll val; is >> val;\n        x = ModInt(val);\n        return is;\n    }\n\
    \    constexpr friend std::ostream& operator << (std::ostream& os, const ModInt&\
    \ x) {\n        return os << x.x;\n    }\n\n    constexpr ModInt pow(ll k) const\
    \ {\n        ModInt ans = 1, tmp = x;\n        while (k) {\n            if (k\
    \ & 1) ans *= tmp;\n            tmp *= tmp;\n            k >>= 1;\n        }\n\
    \        return ans;\n    }\n\n    constexpr ModInt inv() const {\n        if\
    \ (x < 1000111) {\n            _precalc(1000111);\n            return invs[x];\n\
    \        }\n        int a = x, b = MD, ax = 1, bx = 0;\n        while (b) {\n\
    \            int q = a/b, t = a%b;\n            a = b; b = t;\n            t =\
    \ ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a == 1);\n\
    \        if (ax < 0) ax += MD;\n        return ax;\n    }\n\n    static std::vector<ModInt>\
    \ factorials, inv_factorials, invs;\n    constexpr static void _precalc(int n)\
    \ {\n        if (factorials.empty()) {\n            factorials = {1};\n      \
    \      inv_factorials = {1};\n            invs = {0};\n        }\n        if (n\
    \ > MD) n = MD;\n        int old_sz = factorials.size();\n        if (n <= old_sz)\
    \ return;\n\n        factorials.resize(n);\n        inv_factorials.resize(n);\n\
    \        invs.resize(n);\n\n        for (int i = old_sz; i < n; ++i) factorials[i]\
    \ = factorials[i-1] * i;\n        inv_factorials[n-1] = factorials.back().pow(MD\
    \ - 2);\n        for (int i = n - 2; i >= old_sz; --i) inv_factorials[i] = inv_factorials[i+1]\
    \ * (i+1);\n        for (int i = n-1; i >= old_sz; --i) invs[i] = inv_factorials[i]\
    \ * factorials[i-1];\n    }\n    \nprivate:\n    // Internal, DO NOT USE.\n  \
    \  // val must be in [0, 2*MD)\n    constexpr inline __attribute__((always_inline))\
    \ ModInt& _set(ll v) {\n        x = v >= MD ? v - MD : v;\n        return *this;\n\
    \    }\n};\ntemplate <int MD> std::vector<ModInt<MD>> ModInt<MD>::factorials =\
    \ {1};\ntemplate <int MD> std::vector<ModInt<MD>> ModInt<MD>::inv_factorials =\
    \ {1};\ntemplate <int MD> std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n//\
    \ }}}\n#line 15 \"String/hash.h\"\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\
    \nstruct Hash {\n    long long x;\n    modular y;\n\n    Hash operator + (const\
    \ Hash& a) const { return Hash{x + a.x, y + a.y}; }\n    Hash operator - (const\
    \ Hash& a) const { return Hash{x - a.x, y - a.y}; }\n    Hash operator * (const\
    \ Hash& a) const { return Hash{x * a.x, y * a.y}; }\n    Hash operator * (int\
    \ k) const { return Hash{x*k, y*k}; }\n};\nbool operator == (const Hash& a, const\
    \ Hash& b) {\n    return a.x == b.x && a.y == b.y;\n}\n\n// hash function for\
    \ std::unordered_map\nnamespace std {\n    template<>\n    struct hash<Hash> {\n\
    \        public:\n            size_t operator() (const Hash& h) const {\n    \
    \            return h.x * 1000000009 + h.y.x;\n            }\n    };\n}\n\nstruct\
    \ HashGenerator {\n    HashGenerator(int maxLen, int base = 311) {\n        p.resize(maxLen\
    \ + 1);\n        p[0] = {1, 1};\n        for (int i = 1; i <= maxLen; i++) {\n\
    \            p[i] = p[i-1] * base;\n        }\n    }\n\n    std::vector<Hash>\
    \ hash(const std::string& s) {\n        std::vector<Hash> res(s.size());\n   \
    \     for (size_t i = 0; i < s.size(); i++) {\n            res[i] = p[i] * (int)\
    \ s[i];\n        }\n        std::partial_sum(res.begin(), res.end(), res.begin());\n\
    \        return res;\n    }\n\n    Hash getHash(const std::vector<Hash>& h, int\
    \ l, int r) {\n        return __getHash(h, l, r) * p[p.size() - 1 - l];\n    }\n\
    \n    // compare [l1, r1] vs [l2, r2]\n    bool equals(\n            const std::vector<Hash>&\
    \ h1, int l1, int r1,\n            const std::vector<Hash>& h2, int l2, int r2)\
    \ {\n        assert(0 <= l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0\
    \ <= l2 && l2 <= r2 && r2 < (int) h2.size());\n\n        return getHash(h1, l1,\
    \ r1) == getHash(h2, l2, r2);\n    }\n\n    // Returns length of max common prefix\
    \ of h1[l1, r1] and h2[l2, r2]\n    // length = 0 -> first character of 2 substrings\
    \ are different.\n    int maxCommonPrefix(\n            const std::vector<Hash>&\
    \ h1, int l1, int r1,\n            const std::vector<Hash>& h2, int l2, int r2)\
    \ {\n        assert(0 <= l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0\
    \ <= l2 && l2 <= r2 && r2 < (int) h2.size());\n\n        int len1 = r1 - l1 +\
    \ 1;\n        int len2 = r2 - l2 + 1;\n\n        int res = -1, left = 0, right\
    \ = std::min(len1, len2) - 1;\n        while (left <= right) {\n            int\
    \ mid = (left + right) / 2;\n            if (equals(h1, l1, l1 + mid, h2, l2,\
    \ l2 + mid)) {\n                res = mid;\n                left = mid + 1;\n\
    \            } else {\n                right = mid - 1;\n            }\n     \
    \   }\n        return res + 1;\n        /* C++20\n        auto r = std::views::iota(0,\
    \ std::min(len1, len2));\n        auto res = std::ranges::partition_point(\n \
    \               r,\n                [&] (int mid) {\n                    return\
    \ equals(h1, l1, l1+mid, h2, l2, l2+mid);\n                });\n        return\
    \ *res;\n         */\n    }\n\n    // compare s1[l1, r1] and s2[l2, r2]\n    int\
    \ cmp(\n            const std::string& s1, const std::vector<Hash>& h1, int l1,\
    \ int r1,\n            const std::string& s2, const std::vector<Hash>& h2, int\
    \ l2, int r2) {\n        assert(0 <= l1 && l1 <= r1 && r1 < (int) h1.size());\n\
    \        assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());\n\n        int commonPrefixLen\
    \ = maxCommonPrefix(h1, l1, r1, h2, l2, r2);\n        char c1 = (l1 + commonPrefixLen\
    \ <= r1) ? s1[l1 + commonPrefixLen] : 0;\n        char c2 = (l2 + commonPrefixLen\
    \ <= r2) ? s2[l2 + commonPrefixLen] : 0;\n\n        return (c1 == c2) ? 0 : ((c1\
    \ < c2) ? -1 : 1);\n    }\n\nprivate:\n    std::vector<Hash> p;\n\n    // DO NOT\
    \ USE, this doesn't divide by p[l]\n    Hash __getHash(const std::vector<Hash>&\
    \ h, int l, int r) {\n        assert(0 <= l && l <= r && r < (int) h.size());\n\
    \        return h[r] - (l == 0 ? Hash{0, 0} : h[l-1]);\n    }\n};\n#line 5 \"\
    String/tests/aizu_alds_14_b_string_hash.test.cpp\"\n#define SZ(x) ((int)(x).size())\n\
    \nHashGenerator g(1000111);\nvoid solve() {\n    std::string a, b; std::cin >>\
    \ a >> b;\n\n    auto hb = g.hash(b);\n    auto ha = g.hash(a);\n\n    for (int\
    \ i = 0; i + SZ(b) <= SZ(a); i++) {\n        if (g.equals(hb, 0, SZ(b) - 1,\n\
    \                    ha, i, i + SZ(b) - 1)) {\n            std::cout << i << '\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include \"../../template.h\"\n#include \"../hash.h\"\n#define SZ(x) ((int)(x).size())\n\
    \nHashGenerator g(1000111);\nvoid solve() {\n    std::string a, b; std::cin >>\
    \ a >> b;\n\n    auto hb = g.hash(b);\n    auto ha = g.hash(a);\n\n    for (int\
    \ i = 0; i + SZ(b) <= SZ(a); i++) {\n        if (g.equals(hb, 0, SZ(b) - 1,\n\
    \                    ha, i, i + SZ(b) - 1)) {\n            std::cout << i << '\\\
    n';\n        }\n    }\n}\n"
  dependsOn:
  - template.h
  - String/hash.h
  - Math/modint.h
  isVerificationFile: true
  path: String/tests/aizu_alds_14_b_string_hash.test.cpp
  requiredBy: []
  timestamp: '2022-08-21 20:19:49+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: String/tests/aizu_alds_14_b_string_hash.test.cpp
layout: document
redirect_from:
- /verify/String/tests/aizu_alds_14_b_string_hash.test.cpp
- /verify/String/tests/aizu_alds_14_b_string_hash.test.cpp.html
title: String/tests/aizu_alds_14_b_string_hash.test.cpp
---
