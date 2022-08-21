---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modulo_anta.h
    title: Math/modulo_anta.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: String/tests/aizu_alds_14_b_string_hash.test.cpp
    title: String/tests/aizu_alds_14_b_string_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/yukicoder_1408_string_hash_lcp.test.cpp
    title: String/tests/yukicoder_1408_string_hash_lcp.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://oj.vnoi.info/problem/dtksub
    - https://oj.vnoi.info/problem/paliny
    - https://oj.vnoi.info/problem/substr
    - https://oj.vnoi.info/problem/vostr
  bundledCode: "#line 1 \"String/hash.h\"\n// Usage:\n// HashGenerator g(MAX_LENGTH)\n\
    //\n// auto h = g.hash(s)\n// g.equals(s, h, l1, r1, s, h, l2, r2)\n// g.cmp(s,\
    \ h, l1, r1, s, h, l2, r2)\n//\n// Tested:\n// - https://oj.vnoi.info/problem/substr\n\
    // - https://oj.vnoi.info/problem/paliny  - max palin / binary search\n// - https://oj.vnoi.info/problem/dtksub\
    \  - hash<Hash> for unordered_map\n// - https://oj.vnoi.info/problem/vostr   -\
    \ cmp\n\n#line 1 \"Math/modulo_anta.h\"\n// Modified from anta's code\n// Not\
    \ tested with MOD > 10^9 + 7.\n// Slow?\n//\n// Tested:\n// - https://codeforces.com/gym/101383\
    \ - F (MOD = 1e9+7, +, *)\n\n// ??? somehow this is 2.5x slower on https://judge.yosupo.jp/problem/matrix_product\n\
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
    template<int MOD>\nstd::ostream& operator << (std::ostream& cout, const ModInt<MOD>&\
    \ m) {\n    cout << m.x;\n    return cout;\n}\ntemplate<int MOD>\nstd::istream&\
    \ operator >> (std::istream& cin, ModInt<MOD>& m) {\n    cin >> m.x;\n    return\
    \ cin;\n}\n\n/* Example:\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\
    */\n#line 15 \"String/hash.h\"\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\
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
    \        return h[r] - (l == 0 ? Hash{0, 0} : h[l-1]);\n    }\n};\n"
  code: "// Usage:\n// HashGenerator g(MAX_LENGTH)\n//\n// auto h = g.hash(s)\n//\
    \ g.equals(s, h, l1, r1, s, h, l2, r2)\n// g.cmp(s, h, l1, r1, s, h, l2, r2)\n\
    //\n// Tested:\n// - https://oj.vnoi.info/problem/substr\n// - https://oj.vnoi.info/problem/paliny\
    \  - max palin / binary search\n// - https://oj.vnoi.info/problem/dtksub  - hash<Hash>\
    \ for unordered_map\n// - https://oj.vnoi.info/problem/vostr   - cmp\n\n#include\
    \ \"../Math/modulo_anta.h\"\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\
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
    \        return h[r] - (l == 0 ? Hash{0, 0} : h[l-1]);\n    }\n};\n"
  dependsOn:
  - Math/modulo_anta.h
  isVerificationFile: false
  path: String/hash.h
  requiredBy: []
  timestamp: '2022-08-21 18:30:35+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - String/tests/yukicoder_1408_string_hash_lcp.test.cpp
  - String/tests/aizu_alds_14_b_string_hash.test.cpp
documentation_of: String/hash.h
layout: document
redirect_from:
- /library/String/hash.h
- /library/String/hash.h.html
title: String/hash.h
---
