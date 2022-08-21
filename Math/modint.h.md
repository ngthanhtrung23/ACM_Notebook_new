---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: String/hash.h
    title: String/hash.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/hld_vertexsetpathcomposite.test.cpp
    title: DataStructure/test/hld_vertexsetpathcomposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
    title: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
    title: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
    title: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/splay_tree.test.cpp
    title: DataStructure/test/splay_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_1_b_modulo_pow.test.cpp
    title: Math/tests/aizu_ntl_1_b_modulo_pow.test.cpp
  - icon: ':x:'
    path: Math/tests/berlekamp_massey.test.cpp
    title: Math/tests/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/matrix_mult.test.cpp
    title: Math/tests/matrix_mult.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/aizu_alds_14_b_string_hash.test.cpp
    title: String/tests/aizu_alds_14_b_string_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/yukicoder_1408_string_hash_lcp.test.cpp
    title: String/tests/yukicoder_1408_string_hash_lcp.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/modint.h\"\n// ModInt {{{\ntemplate<int MD> struct\
    \ ModInt {\n    using ll = long long;\n    int x;\n\n    constexpr ModInt() :\
    \ x(0) {}\n    constexpr ModInt(ll v) { _set(v % MD + MD); }\n    constexpr explicit\
    \ operator bool() const { return x != 0; }\n\n    constexpr ModInt operator +\
    \ (const ModInt& a) const {\n        return ModInt()._set((ll) x + a.x);\n   \
    \ }\n    constexpr ModInt operator - (const ModInt& a) const {\n        return\
    \ ModInt()._set((ll) x - a.x + MD);\n    }\n    constexpr ModInt operator * (const\
    \ ModInt& a) const {\n        return ModInt()._set((ll) x * a.x % MD);\n    }\n\
    \    constexpr ModInt operator / (const ModInt& a) const {\n        return ModInt()._set((ll)\
    \ x * a.inv().x % MD);\n    }\n    constexpr ModInt operator - () const {\n  \
    \      return ModInt()._set(MD - x);\n    }\n\n    constexpr ModInt& operator\
    \ += (const ModInt& a) { return *this = *this + a; }\n    constexpr ModInt& operator\
    \ -= (const ModInt& a) { return *this = *this - a; }\n    constexpr ModInt& operator\
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
    \ {\n        if (factorials.empty()) [[unlikely]] {\n            factorials =\
    \ {1};\n            inv_factorials = {1};\n            invs = {0};\n        }\n\
    \        if (n > MD) n = MD;\n        int old_sz = factorials.size();\n      \
    \  if (n <= old_sz) return;\n\n        factorials.resize(n);\n        inv_factorials.resize(n);\n\
    \        invs.resize(n);\n\n        for (int i = old_sz; i < n; ++i) factorials[i]\
    \ = factorials[i-1] * i;\n        inv_factorials[n-1] = factorials.back().pow(MD\
    \ - 2);\n        for (int i = n - 2; i >= old_sz; --i) inv_factorials[i] = inv_factorials[i+1]\
    \ * (i+1);\n        for (int i = n-1; i >= old_sz; --i) invs[i] = inv_factorials[i]\
    \ * factorials[i-1];\n    }\n    \nprivate:\n    // Internal, DO NOT USE.\n  \
    \  // val must be in [0, 2*MD)\n    constexpr inline __attribute__((always_inline))\
    \ ModInt& _set(ll v) {\n        x = v >= MD ? v - MD : v;\n        return *this;\n\
    \    }\n};\n// }}}\n"
  code: "// ModInt {{{\ntemplate<int MD> struct ModInt {\n    using ll = long long;\n\
    \    int x;\n\n    constexpr ModInt() : x(0) {}\n    constexpr ModInt(ll v) {\
    \ _set(v % MD + MD); }\n    constexpr explicit operator bool() const { return\
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
    \ [[unlikely]] {\n            factorials = {1};\n            inv_factorials =\
    \ {1};\n            invs = {0};\n        }\n        if (n > MD) n = MD;\n    \
    \    int old_sz = factorials.size();\n        if (n <= old_sz) return;\n\n   \
    \     factorials.resize(n);\n        inv_factorials.resize(n);\n        invs.resize(n);\n\
    \n        for (int i = old_sz; i < n; ++i) factorials[i] = factorials[i-1] * i;\n\
    \        inv_factorials[n-1] = factorials.back().pow(MD - 2);\n        for (int\
    \ i = n - 2; i >= old_sz; --i) inv_factorials[i] = inv_factorials[i+1] * (i+1);\n\
    \        for (int i = n-1; i >= old_sz; --i) invs[i] = inv_factorials[i] * factorials[i-1];\n\
    \    }\n    \nprivate:\n    // Internal, DO NOT USE.\n    // val must be in [0,\
    \ 2*MD)\n    constexpr inline __attribute__((always_inline)) ModInt& _set(ll v)\
    \ {\n        x = v >= MD ? v - MD : v;\n        return *this;\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint.h
  requiredBy:
  - String/hash.h
  timestamp: '2022-08-21 20:08:44+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - String/tests/yukicoder_1408_string_hash_lcp.test.cpp
  - String/tests/aizu_alds_14_b_string_hash.test.cpp
  - DataStructure/test/splay_tree.test.cpp
  - DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
  - DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
  - DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  - DataStructure/test/hld_vertexsetpathcomposite.test.cpp
  - Math/tests/matrix_mult.test.cpp
  - Math/tests/aizu_ntl_1_b_modulo_pow.test.cpp
  - Math/tests/berlekamp_massey.test.cpp
documentation_of: Math/modint.h
layout: document
redirect_from:
- /library/Math/modint.h
- /library/Math/modint.h.html
title: Math/modint.h
---
