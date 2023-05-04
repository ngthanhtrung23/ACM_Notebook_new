---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/modint.h
    title: Math/modint.h
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: String/SuffixArray.h
    title: String/SuffixArray.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: String/tests/aizu_alds_14_b_string_hash.test.cpp
    title: String/tests/aizu_alds_14_b_string_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/lcp.test.cpp
    title: String/tests/lcp.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/suffix_array.test.cpp
    title: String/tests/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/suffix_array_queries.test.cpp
    title: String/tests/suffix_array_queries.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/yukicoder_1408_string_hash_lcp.test.cpp
    title: String/tests/yukicoder_1408_string_hash_lcp.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/zfunc_hash.test.cpp
    title: String/tests/zfunc_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://oj.vnoi.info/problem/dtksub
    - https://oj.vnoi.info/problem/paliny
    - https://oj.vnoi.info/problem/substr
    - https://oj.vnoi.info/problem/vostr
  bundledCode: "#line 1 \"Math/modint.h\"\n// ModInt {{{\ntemplate<int MD> struct\
    \ ModInt {\n    using ll = long long;\n    int x;\n\n    constexpr ModInt() :\
    \ x(0) {}\n    constexpr ModInt(ll v) { _set(v % MD + MD); }\n    constexpr static\
    \ int mod() { return MD; }\n    constexpr explicit operator bool() const { return\
    \ x != 0; }\n\n    constexpr ModInt operator + (const ModInt& a) const {\n   \
    \     return ModInt()._set((ll) x + a.x);\n    }\n    constexpr ModInt operator\
    \ - (const ModInt& a) const {\n        return ModInt()._set((ll) x - a.x + MD);\n\
    \    }\n    constexpr ModInt operator * (const ModInt& a) const {\n        return\
    \ ModInt()._set((ll) x * a.x % MD);\n    }\n    constexpr ModInt operator / (const\
    \ ModInt& a) const {\n        return ModInt()._set((ll) x * a.inv().x % MD);\n\
    \    }\n    constexpr ModInt operator - () const {\n        return ModInt()._set(MD\
    \ - x);\n    }\n\n    constexpr ModInt& operator += (const ModInt& a) { return\
    \ *this = *this + a; }\n    constexpr ModInt& operator -= (const ModInt& a) {\
    \ return *this = *this - a; }\n    constexpr ModInt& operator *= (const ModInt&\
    \ a) { return *this = *this * a; }\n    constexpr ModInt& operator /= (const ModInt&\
    \ a) { return *this = *this / a; }\n\n    friend constexpr ModInt operator + (ll\
    \ a, const ModInt& b) {\n        return ModInt()._set(a % MD + b.x);\n    }\n\
    \    friend constexpr ModInt operator - (ll a, const ModInt& b) {\n        return\
    \ ModInt()._set(a % MD - b.x + MD);\n    }\n    friend constexpr ModInt operator\
    \ * (ll a, const ModInt& b) {\n        return ModInt()._set(a % MD * b.x % MD);\n\
    \    }\n    friend constexpr ModInt operator / (ll a, const ModInt& b) {\n   \
    \     return ModInt()._set(a % MD * b.inv().x % MD);\n    }\n\n    constexpr bool\
    \ operator == (const ModInt& a) const { return x == a.x; }\n    constexpr bool\
    \ operator != (const ModInt& a) const { return x != a.x; }\n\n    friend std::istream&\
    \ operator >> (std::istream& is, ModInt& x) {\n        ll val; is >> val;\n  \
    \      x = ModInt(val);\n        return is;\n    }\n    constexpr friend std::ostream&\
    \ operator << (std::ostream& os, const ModInt& x) {\n        return os << x.x;\n\
    \    }\n\n    constexpr ModInt pow(ll k) const {\n        ModInt ans = 1, tmp\
    \ = x;\n        while (k) {\n            if (k & 1) ans *= tmp;\n            tmp\
    \ *= tmp;\n            k >>= 1;\n        }\n        return ans;\n    }\n\n   \
    \ constexpr ModInt inv() const {\n        if (x < 1000111) {\n            _precalc(1000111);\n\
    \            return invs[x];\n        }\n        int a = x, b = MD, ax = 1, bx\
    \ = 0;\n        while (b) {\n            int q = a/b, t = a%b;\n            a\
    \ = b; b = t;\n            t = ax - bx*q;\n            ax = bx; bx = t;\n    \
    \    }\n        assert(a == 1);\n        if (ax < 0) ax += MD;\n        return\
    \ ax;\n    }\n\n    static std::vector<ModInt> factorials, inv_factorials, invs;\n\
    \    constexpr static void _precalc(int n) {\n        if (factorials.empty())\
    \ {\n            factorials = {1};\n            inv_factorials = {1};\n      \
    \      invs = {0};\n        }\n        if (n > MD) n = MD;\n        int old_sz\
    \ = factorials.size();\n        if (n <= old_sz) return;\n\n        factorials.resize(n);\n\
    \        inv_factorials.resize(n);\n        invs.resize(n);\n\n        for (int\
    \ i = old_sz; i < n; ++i) factorials[i] = factorials[i-1] * i;\n        inv_factorials[n-1]\
    \ = factorials.back().pow(MD - 2);\n        for (int i = n - 2; i >= old_sz; --i)\
    \ inv_factorials[i] = inv_factorials[i+1] * (i+1);\n        for (int i = n-1;\
    \ i >= old_sz; --i) invs[i] = inv_factorials[i] * factorials[i-1];\n    }\n\n\
    \    static int get_primitive_root() {\n        static int primitive_root = 0;\n\
    \        if (!primitive_root) {\n            primitive_root = [&]() {\n      \
    \          std::set<int> fac;\n                int v = MD - 1;\n             \
    \   for (ll i = 2; i * i <= v; i++)\n                    while (v % i == 0) fac.insert(i),\
    \ v /= i;\n                if (v > 1) fac.insert(v);\n                for (int\
    \ g = 1; g < MD; g++) {\n                    bool ok = true;\n               \
    \     for (auto i : fac)\n                        if (ModInt(g).pow((MD - 1) /\
    \ i) == 1) {\n                            ok = false;\n                      \
    \      break;\n                        }\n                    if (ok) return g;\n\
    \                }\n                return -1;\n            }();\n        }\n\
    \        return primitive_root;\n    }\n\n    static ModInt C(int n, int k) {\n\
    \        _precalc(n + 1);\n        return factorials[n] * inv_factorials[k] *\
    \ inv_factorials[n-k];\n    }\n    \nprivate:\n    // Internal, DO NOT USE.\n\
    \    // val must be in [0, 2*MD)\n    constexpr inline __attribute__((always_inline))\
    \ ModInt& _set(ll v) {\n        x = v >= MD ? v - MD : v;\n        return *this;\n\
    \    }\n};\ntemplate <int MD> std::vector<ModInt<MD>> ModInt<MD>::factorials =\
    \ {1};\ntemplate <int MD> std::vector<ModInt<MD>> ModInt<MD>::inv_factorials =\
    \ {1};\ntemplate <int MD> std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n//\
    \ }}}\n#line 2 \"String/hash.h\"\n\n// Hash {{{\n// Usage:\n// HashGenerator g(MAX_LENGTH)\n\
    //\n// auto h = g.hash(s)\n// g.equals(s, h, l1, r1, s, h, l2, r2)\n// g.cmp(s,\
    \ h, l1, r1, s, h, l2, r2)\n//\n// Tested:\n// - https://oj.vnoi.info/problem/substr\n\
    // - https://oj.vnoi.info/problem/paliny  - max palin / binary search\n// - https://oj.vnoi.info/problem/dtksub\
    \  - hash<Hash> for unordered_map\n// - https://oj.vnoi.info/problem/vostr   -\
    \ cmp\n\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\nstruct Hash\
    \ {\n    long long x;\n    modular y;\n\n    Hash operator + (const Hash& a) const\
    \ { return Hash{x + a.x, y + a.y}; }\n    Hash operator - (const Hash& a) const\
    \ { return Hash{x - a.x, y - a.y}; }\n    Hash operator * (const Hash& a) const\
    \ { return Hash{x * a.x, y * a.y}; }\n    Hash operator * (int k) const { return\
    \ Hash{x*k, y*k}; }\n\n    Hash& operator += (const Hash& a) { return *this =\
    \ *this + a; }\n    Hash& operator -= (const Hash& a) { return *this = *this -\
    \ a; }\n    Hash& operator *= (const Hash& a) { return *this = *this * a; }\n\
    };\nbool operator == (const Hash& a, const Hash& b) {\n    return a.x == b.x &&\
    \ a.y == b.y;\n}\nbool operator < (const Hash& a, const Hash& b) {\n    if (a.x\
    \ != b.x) return a.x < b.x;\n    return a.y.x < b.y.x;\n}\nstd::ostream& operator\
    \ << (std::ostream& out, const Hash& h) {\n    out << '(' << h.x << \", \" <<\
    \ h.y << ')';\n    return out;\n}\n\n// hash function for std::unordered_map\n\
    namespace std {\n    template<>\n    struct hash<Hash> {\n        public:\n  \
    \          size_t operator() (const Hash& h) const {\n                return h.x\
    \ * 1000000009 + h.y.x;\n            }\n    };\n}\n\nstruct HashGenerator {\n\
    \    HashGenerator(int maxLen, int base = 311) {\n        p.resize(maxLen + 1);\n\
    \        p[0] = {1, 1};\n        for (int i = 1; i <= maxLen; i++) {\n       \
    \     p[i] = p[i-1] * base;\n        }\n    }\n\n    template<typename Container>\n\
    \    std::vector<Hash> hash(const Container& s) const {\n        std::vector<Hash>\
    \ res(s.size());\n        for (size_t i = 0; i < s.size(); i++) {\n          \
    \  res[i] = p[i] * (int) s[i];\n        }\n        std::partial_sum(res.begin(),\
    \ res.end(), res.begin());\n        return res;\n    }\n\n    Hash getHash(const\
    \ std::vector<Hash>& h, int l, int r) const {\n        return __getHash(h, l,\
    \ r) * p[p.size() - 1 - l];\n    }\n\n    // compare [l1, r1] vs [l2, r2]\n  \
    \  bool equals(\n            const std::vector<Hash>& h1, int l1, int r1,\n  \
    \          const std::vector<Hash>& h2, int l2, int r2) const {\n        assert(0\
    \ <= l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0 <= l2 && l2 <=\
    \ r2 && r2 < (int) h2.size());\n        if (r1 - l1 != r2 - l2) return false;\n\
    \n        return getHash(h1, l1, r1) == getHash(h2, l2, r2);\n    }\n\n    //\
    \ Returns length of max common prefix of h1[l1, r1] and h2[l2, r2]\n    // length\
    \ = 0 -> first character of 2 substrings are different.\n    int maxCommonPrefix(\n\
    \            const std::vector<Hash>& h1, int l1, int r1,\n            const std::vector<Hash>&\
    \ h2, int l2, int r2) const {\n        assert(0 <= l1 && l1 <= r1 && r1 < (int)\
    \ h1.size());\n        assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());\n\n\
    \        int len1 = r1 - l1 + 1;\n        int len2 = r2 - l2 + 1;\n\n        int\
    \ res = -1, left = 0, right = std::min(len1, len2) - 1;\n        while (left <=\
    \ right) {\n            int mid = (left + right) / 2;\n            if (equals(h1,\
    \ l1, l1 + mid, h2, l2, l2 + mid)) {\n                res = mid;\n           \
    \     left = mid + 1;\n            } else {\n                right = mid - 1;\n\
    \            }\n        }\n        return res + 1;\n        /* C++20\n       \
    \ auto r = std::views::iota(0, std::min(len1, len2));\n        auto res = std::ranges::partition_point(\n\
    \                r,\n                [&] (int mid) {\n                    return\
    \ equals(h1, l1, l1+mid, h2, l2, l2+mid);\n                });\n        return\
    \ *res;\n         */\n    }\n\n    // compare s1[l1, r1] and s2[l2, r2]\n    template<typename\
    \ Container1, typename Container2>\n    int cmp(\n            const Container1&\
    \ s1, const std::vector<Hash>& h1, int l1, int r1,\n            const Container2&\
    \ s2, const std::vector<Hash>& h2, int l2, int r2) const {\n        assert(0 <=\
    \ l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0 <= l2 && l2 <= r2\
    \ && r2 < (int) h2.size());\n\n        int commonPrefixLen = maxCommonPrefix(h1,\
    \ l1, r1, h2, l2, r2);\n        char c1 = (l1 + commonPrefixLen <= r1) ? s1[l1\
    \ + commonPrefixLen] : 0;\n        char c2 = (l2 + commonPrefixLen <= r2) ? s2[l2\
    \ + commonPrefixLen] : 0;\n\n        return (c1 == c2) ? 0 : ((c1 < c2) ? -1 :\
    \ 1);\n    }\n\nprivate:\n    std::vector<Hash> p;\n\n    // DO NOT USE, this\
    \ doesn't divide by p[l]\n    Hash __getHash(const std::vector<Hash>& h, int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r < (int) h.size());\n  \
    \      return h[r] - (l == 0 ? Hash{0, 0} : h[l-1]);\n    }\n};\n// }}}\n"
  code: "#include \"../Math/modint.h\"\n\n// Hash {{{\n// Usage:\n// HashGenerator\
    \ g(MAX_LENGTH)\n//\n// auto h = g.hash(s)\n// g.equals(s, h, l1, r1, s, h, l2,\
    \ r2)\n// g.cmp(s, h, l1, r1, s, h, l2, r2)\n//\n// Tested:\n// - https://oj.vnoi.info/problem/substr\n\
    // - https://oj.vnoi.info/problem/paliny  - max palin / binary search\n// - https://oj.vnoi.info/problem/dtksub\
    \  - hash<Hash> for unordered_map\n// - https://oj.vnoi.info/problem/vostr   -\
    \ cmp\n\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\nstruct Hash\
    \ {\n    long long x;\n    modular y;\n\n    Hash operator + (const Hash& a) const\
    \ { return Hash{x + a.x, y + a.y}; }\n    Hash operator - (const Hash& a) const\
    \ { return Hash{x - a.x, y - a.y}; }\n    Hash operator * (const Hash& a) const\
    \ { return Hash{x * a.x, y * a.y}; }\n    Hash operator * (int k) const { return\
    \ Hash{x*k, y*k}; }\n\n    Hash& operator += (const Hash& a) { return *this =\
    \ *this + a; }\n    Hash& operator -= (const Hash& a) { return *this = *this -\
    \ a; }\n    Hash& operator *= (const Hash& a) { return *this = *this * a; }\n\
    };\nbool operator == (const Hash& a, const Hash& b) {\n    return a.x == b.x &&\
    \ a.y == b.y;\n}\nbool operator < (const Hash& a, const Hash& b) {\n    if (a.x\
    \ != b.x) return a.x < b.x;\n    return a.y.x < b.y.x;\n}\nstd::ostream& operator\
    \ << (std::ostream& out, const Hash& h) {\n    out << '(' << h.x << \", \" <<\
    \ h.y << ')';\n    return out;\n}\n\n// hash function for std::unordered_map\n\
    namespace std {\n    template<>\n    struct hash<Hash> {\n        public:\n  \
    \          size_t operator() (const Hash& h) const {\n                return h.x\
    \ * 1000000009 + h.y.x;\n            }\n    };\n}\n\nstruct HashGenerator {\n\
    \    HashGenerator(int maxLen, int base = 311) {\n        p.resize(maxLen + 1);\n\
    \        p[0] = {1, 1};\n        for (int i = 1; i <= maxLen; i++) {\n       \
    \     p[i] = p[i-1] * base;\n        }\n    }\n\n    template<typename Container>\n\
    \    std::vector<Hash> hash(const Container& s) const {\n        std::vector<Hash>\
    \ res(s.size());\n        for (size_t i = 0; i < s.size(); i++) {\n          \
    \  res[i] = p[i] * (int) s[i];\n        }\n        std::partial_sum(res.begin(),\
    \ res.end(), res.begin());\n        return res;\n    }\n\n    Hash getHash(const\
    \ std::vector<Hash>& h, int l, int r) const {\n        return __getHash(h, l,\
    \ r) * p[p.size() - 1 - l];\n    }\n\n    // compare [l1, r1] vs [l2, r2]\n  \
    \  bool equals(\n            const std::vector<Hash>& h1, int l1, int r1,\n  \
    \          const std::vector<Hash>& h2, int l2, int r2) const {\n        assert(0\
    \ <= l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0 <= l2 && l2 <=\
    \ r2 && r2 < (int) h2.size());\n        if (r1 - l1 != r2 - l2) return false;\n\
    \n        return getHash(h1, l1, r1) == getHash(h2, l2, r2);\n    }\n\n    //\
    \ Returns length of max common prefix of h1[l1, r1] and h2[l2, r2]\n    // length\
    \ = 0 -> first character of 2 substrings are different.\n    int maxCommonPrefix(\n\
    \            const std::vector<Hash>& h1, int l1, int r1,\n            const std::vector<Hash>&\
    \ h2, int l2, int r2) const {\n        assert(0 <= l1 && l1 <= r1 && r1 < (int)\
    \ h1.size());\n        assert(0 <= l2 && l2 <= r2 && r2 < (int) h2.size());\n\n\
    \        int len1 = r1 - l1 + 1;\n        int len2 = r2 - l2 + 1;\n\n        int\
    \ res = -1, left = 0, right = std::min(len1, len2) - 1;\n        while (left <=\
    \ right) {\n            int mid = (left + right) / 2;\n            if (equals(h1,\
    \ l1, l1 + mid, h2, l2, l2 + mid)) {\n                res = mid;\n           \
    \     left = mid + 1;\n            } else {\n                right = mid - 1;\n\
    \            }\n        }\n        return res + 1;\n        /* C++20\n       \
    \ auto r = std::views::iota(0, std::min(len1, len2));\n        auto res = std::ranges::partition_point(\n\
    \                r,\n                [&] (int mid) {\n                    return\
    \ equals(h1, l1, l1+mid, h2, l2, l2+mid);\n                });\n        return\
    \ *res;\n         */\n    }\n\n    // compare s1[l1, r1] and s2[l2, r2]\n    template<typename\
    \ Container1, typename Container2>\n    int cmp(\n            const Container1&\
    \ s1, const std::vector<Hash>& h1, int l1, int r1,\n            const Container2&\
    \ s2, const std::vector<Hash>& h2, int l2, int r2) const {\n        assert(0 <=\
    \ l1 && l1 <= r1 && r1 < (int) h1.size());\n        assert(0 <= l2 && l2 <= r2\
    \ && r2 < (int) h2.size());\n\n        int commonPrefixLen = maxCommonPrefix(h1,\
    \ l1, r1, h2, l2, r2);\n        char c1 = (l1 + commonPrefixLen <= r1) ? s1[l1\
    \ + commonPrefixLen] : 0;\n        char c2 = (l2 + commonPrefixLen <= r2) ? s2[l2\
    \ + commonPrefixLen] : 0;\n\n        return (c1 == c2) ? 0 : ((c1 < c2) ? -1 :\
    \ 1);\n    }\n\nprivate:\n    std::vector<Hash> p;\n\n    // DO NOT USE, this\
    \ doesn't divide by p[l]\n    Hash __getHash(const std::vector<Hash>& h, int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r < (int) h.size());\n  \
    \      return h[r] - (l == 0 ? Hash{0, 0} : h[l-1]);\n    }\n};\n// }}}\n"
  dependsOn:
  - Math/modint.h
  isVerificationFile: false
  path: String/hash.h
  requiredBy:
  - String/SuffixArray.h
  timestamp: '2022-12-29 17:34:35+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - String/tests/suffix_array_queries.test.cpp
  - String/tests/lcp.test.cpp
  - String/tests/yukicoder_1408_string_hash_lcp.test.cpp
  - String/tests/aizu_alds_14_b_string_hash.test.cpp
  - String/tests/suffix_array.test.cpp
  - String/tests/zfunc_hash.test.cpp
documentation_of: String/hash.h
layout: document
redirect_from:
- /library/String/hash.h
- /library/String/hash.h.html
title: String/hash.h
---
