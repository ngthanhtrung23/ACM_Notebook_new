---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/Polynomial/FormalPowerSeries.h
    title: Math/Polynomial/FormalPowerSeries.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/formal_power_series_multiply.test.cpp
    title: Math/tests/formal_power_series_multiply.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/formal_power_series_multiply_any_mod.test.cpp
    title: Math/tests/formal_power_series_multiply_any_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/ntt.test.cpp
    title: Math/tests/ntt.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/ntt_any_mod.test.cpp
    title: Math/tests/ntt_any_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Polynomial/NTT.h\"\n// NTT {{{\n//\n// Faster than\
    \ NTT_chemthan.h\n//\n// Usage:\n// auto c = multiply(a, b);\n// where a and b\
    \ are vector<ModInt<ANY_MOD>>\n// (If mod is NOT NTT_PRIMES, it does 3 NTT and\
    \ combine result)\n\nconstexpr int NTT_PRIMES[] = {998244353, 167772161, 469762049};\n\
    \n// assumptions:\n// - |a| is power of 2\n// - mint::mod() is a valid NTT primes\
    \ (2^k * m + 1)\ntemplate<typename mint> void ntt(std::vector<mint>& a, bool is_inverse)\
    \ {\n    int n = a.size();\n    if (n == 1) return;\n\n    static const int mod\
    \ = mint::mod();\n    static const mint root = mint::get_primitive_root();\n \
    \   assert(__builtin_popcount(n) == 1 && (mod - 1) % n == 0);\n\n    static std::vector<mint>\
    \ w{1}, iw{1};\n    for (int m = w.size(); m < n / 2; m *= 2) {\n        mint\
    \ dw = root.pow((mod - 1) / (4 * m));\n        mint dwinv = dw.inv();\n      \
    \  w.resize(m * 2);\n        iw.resize(m * 2);\n        for (int i = 0; i < m;\
    \ ++i) {\n            w[m + i] = w[i] * dw;\n            iw[m + i] = iw[i] * dwinv;\n\
    \        }\n    }\n\n    if (!is_inverse) {\n        for (int m = n; m >>= 1;\
    \ ) {\n            for (int s = 0, k = 0; s < n; s += 2 * m, ++k) {\n        \
    \        for (int i = s; i < s + m; ++i) {\n                    mint x = a[i],\
    \ y = a[i + m] * w[k];\n                    a[i] = x + y;\n                  \
    \  a[i + m] = x - y;\n                }\n            }\n        }\n    } else\
    \ {\n        for (int m = 1; m < n; m *= 2) {\n            for (int s = 0, k =\
    \ 0; s < n; s += 2 * m, ++k) {\n                for (int i = s; i < s + m; ++i)\
    \ {\n                    mint x = a[i], y = a[i + m];\n                    a[i]\
    \ = x + y;\n                    a[i + m] = (x - y) * iw[k];\n                }\n\
    \            }\n        }\n        int n_inv = mint(n).inv().x;\n        for (auto&\
    \ v : a) v *= n_inv;\n    }\n}\n\ntemplate<typename mint>\nstd::vector<mint> ntt_multiply(int\
    \ sz, std::vector<mint> a, std::vector<mint> b) {\n    a.resize(sz);\n    b.resize(sz);\n\
    \    if (a == b) { // optimization for squaring polynomial\n        ntt(a, false);\n\
    \        b = a;\n    } else {\n        ntt(a, false);\n        ntt(b, false);\n\
    \    }\n    for (int i = 0; i < sz; ++i) a[i] *= b[i];\n    ntt(a, true);\n  \
    \  return a;\n}\n\ntemplate<int MOD, typename mint>\nstd::vector<ModInt<MOD>>\
    \ convert_mint_and_multiply(\n        int sz,\n        const std::vector<mint>&\
    \ a,\n        const std::vector<mint>& b) {\n    using mint2 = ModInt<MOD>;\n\n\
    \    std::vector<mint2> a2(a.size()), b2(b.size());\n    for (size_t i = 0; i\
    \ < a.size(); ++i) {\n        a2[i] = mint2(a[i].x);\n    }\n    for (size_t i\
    \ = 0; i < b.size(); ++i) {\n        b2[i] = mint2(b[i].x);\n    }\n    return\
    \ ntt_multiply(sz, a2, b2);\n}\n\nlong long combine(int r0, int r1, int r2, int\
    \ mod) {\n    using mint2 = ModInt<NTT_PRIMES[2]>;\n    static const long long\
    \ m01 = 1LL * NTT_PRIMES[0] * NTT_PRIMES[1];\n    static const long long m0_inv_m1\
    \ = ModInt<NTT_PRIMES[1]>(NTT_PRIMES[0]).inv().x;\n    static const long long\
    \ m01_inv_m2 = mint2(m01).inv().x;\n\n    int v1 = (m0_inv_m1 * (r1 + NTT_PRIMES[1]\
    \ - r0)) % NTT_PRIMES[1];\n    auto v2 = (mint2(r2) - r0 - mint2(NTT_PRIMES[0])\
    \ * v1) * m01_inv_m2;\n    return (r0 + 1LL * NTT_PRIMES[0] * v1 + m01 % mod *\
    \ v2.x) % mod;\n}\n\ntemplate<typename mint>\nstd::vector<mint> multiply(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\n    if (a.empty() || b.empty())\
    \ return {};\n    int sz = 1, sz_a = a.size(), sz_b = b.size();\n    while (sz\
    \ < sz_a + sz_b) sz <<= 1;\n    if (sz <= 16) {\n        std::vector<mint> res(sz_a\
    \ + sz_b - 1);\n        for (int i = 0; i < sz_a; ++i) {\n            for (int\
    \ j = 0; j < sz_b; ++j) {\n                res[i + j] += a[i] * b[j];\n      \
    \      }\n        }\n        return res;\n    }\n\n    int mod = mint::mod();\n\
    \    std::vector<mint> res;\n    if (std::find(std::begin(NTT_PRIMES), std::end(NTT_PRIMES),\
    \ mod) != std::end(NTT_PRIMES)) {\n        res = ntt_multiply(sz, a, b);\n   \
    \ } else {\n        auto c0 = convert_mint_and_multiply<NTT_PRIMES[0], mint> (sz,\
    \ a, b);\n        auto c1 = convert_mint_and_multiply<NTT_PRIMES[1], mint> (sz,\
    \ a, b);\n        auto c2 = convert_mint_and_multiply<NTT_PRIMES[2], mint> (sz,\
    \ a, b);\n\n        res.resize(sz);\n        for (int i = 0; i < sz; ++i) {\n\
    \            res[i] = combine(c0[i].x, c1[i].x, c2[i].x, mod);\n        }\n  \
    \  }\n\n    res.resize(sz_a + sz_b - 1);\n    return res;\n}\n// }}}\n"
  code: "// NTT {{{\n//\n// Faster than NTT_chemthan.h\n//\n// Usage:\n// auto c =\
    \ multiply(a, b);\n// where a and b are vector<ModInt<ANY_MOD>>\n// (If mod is\
    \ NOT NTT_PRIMES, it does 3 NTT and combine result)\n\nconstexpr int NTT_PRIMES[]\
    \ = {998244353, 167772161, 469762049};\n\n// assumptions:\n// - |a| is power of\
    \ 2\n// - mint::mod() is a valid NTT primes (2^k * m + 1)\ntemplate<typename mint>\
    \ void ntt(std::vector<mint>& a, bool is_inverse) {\n    int n = a.size();\n \
    \   if (n == 1) return;\n\n    static const int mod = mint::mod();\n    static\
    \ const mint root = mint::get_primitive_root();\n    assert(__builtin_popcount(n)\
    \ == 1 && (mod - 1) % n == 0);\n\n    static std::vector<mint> w{1}, iw{1};\n\
    \    for (int m = w.size(); m < n / 2; m *= 2) {\n        mint dw = root.pow((mod\
    \ - 1) / (4 * m));\n        mint dwinv = dw.inv();\n        w.resize(m * 2);\n\
    \        iw.resize(m * 2);\n        for (int i = 0; i < m; ++i) {\n          \
    \  w[m + i] = w[i] * dw;\n            iw[m + i] = iw[i] * dwinv;\n        }\n\
    \    }\n\n    if (!is_inverse) {\n        for (int m = n; m >>= 1; ) {\n     \
    \       for (int s = 0, k = 0; s < n; s += 2 * m, ++k) {\n                for\
    \ (int i = s; i < s + m; ++i) {\n                    mint x = a[i], y = a[i +\
    \ m] * w[k];\n                    a[i] = x + y;\n                    a[i + m]\
    \ = x - y;\n                }\n            }\n        }\n    } else {\n      \
    \  for (int m = 1; m < n; m *= 2) {\n            for (int s = 0, k = 0; s < n;\
    \ s += 2 * m, ++k) {\n                for (int i = s; i < s + m; ++i) {\n    \
    \                mint x = a[i], y = a[i + m];\n                    a[i] = x +\
    \ y;\n                    a[i + m] = (x - y) * iw[k];\n                }\n   \
    \         }\n        }\n        int n_inv = mint(n).inv().x;\n        for (auto&\
    \ v : a) v *= n_inv;\n    }\n}\n\ntemplate<typename mint>\nstd::vector<mint> ntt_multiply(int\
    \ sz, std::vector<mint> a, std::vector<mint> b) {\n    a.resize(sz);\n    b.resize(sz);\n\
    \    if (a == b) { // optimization for squaring polynomial\n        ntt(a, false);\n\
    \        b = a;\n    } else {\n        ntt(a, false);\n        ntt(b, false);\n\
    \    }\n    for (int i = 0; i < sz; ++i) a[i] *= b[i];\n    ntt(a, true);\n  \
    \  return a;\n}\n\ntemplate<int MOD, typename mint>\nstd::vector<ModInt<MOD>>\
    \ convert_mint_and_multiply(\n        int sz,\n        const std::vector<mint>&\
    \ a,\n        const std::vector<mint>& b) {\n    using mint2 = ModInt<MOD>;\n\n\
    \    std::vector<mint2> a2(a.size()), b2(b.size());\n    for (size_t i = 0; i\
    \ < a.size(); ++i) {\n        a2[i] = mint2(a[i].x);\n    }\n    for (size_t i\
    \ = 0; i < b.size(); ++i) {\n        b2[i] = mint2(b[i].x);\n    }\n    return\
    \ ntt_multiply(sz, a2, b2);\n}\n\nlong long combine(int r0, int r1, int r2, int\
    \ mod) {\n    using mint2 = ModInt<NTT_PRIMES[2]>;\n    static const long long\
    \ m01 = 1LL * NTT_PRIMES[0] * NTT_PRIMES[1];\n    static const long long m0_inv_m1\
    \ = ModInt<NTT_PRIMES[1]>(NTT_PRIMES[0]).inv().x;\n    static const long long\
    \ m01_inv_m2 = mint2(m01).inv().x;\n\n    int v1 = (m0_inv_m1 * (r1 + NTT_PRIMES[1]\
    \ - r0)) % NTT_PRIMES[1];\n    auto v2 = (mint2(r2) - r0 - mint2(NTT_PRIMES[0])\
    \ * v1) * m01_inv_m2;\n    return (r0 + 1LL * NTT_PRIMES[0] * v1 + m01 % mod *\
    \ v2.x) % mod;\n}\n\ntemplate<typename mint>\nstd::vector<mint> multiply(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\n    if (a.empty() || b.empty())\
    \ return {};\n    int sz = 1, sz_a = a.size(), sz_b = b.size();\n    while (sz\
    \ < sz_a + sz_b) sz <<= 1;\n    if (sz <= 16) {\n        std::vector<mint> res(sz_a\
    \ + sz_b - 1);\n        for (int i = 0; i < sz_a; ++i) {\n            for (int\
    \ j = 0; j < sz_b; ++j) {\n                res[i + j] += a[i] * b[j];\n      \
    \      }\n        }\n        return res;\n    }\n\n    int mod = mint::mod();\n\
    \    std::vector<mint> res;\n    if (std::find(std::begin(NTT_PRIMES), std::end(NTT_PRIMES),\
    \ mod) != std::end(NTT_PRIMES)) {\n        res = ntt_multiply(sz, a, b);\n   \
    \ } else {\n        auto c0 = convert_mint_and_multiply<NTT_PRIMES[0], mint> (sz,\
    \ a, b);\n        auto c1 = convert_mint_and_multiply<NTT_PRIMES[1], mint> (sz,\
    \ a, b);\n        auto c2 = convert_mint_and_multiply<NTT_PRIMES[2], mint> (sz,\
    \ a, b);\n\n        res.resize(sz);\n        for (int i = 0; i < sz; ++i) {\n\
    \            res[i] = combine(c0[i].x, c1[i].x, c2[i].x, mod);\n        }\n  \
    \  }\n\n    res.resize(sz_a + sz_b - 1);\n    return res;\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Polynomial/NTT.h
  requiredBy:
  - Math/Polynomial/FormalPowerSeries.h
  timestamp: '2022-08-21 23:32:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/ntt_any_mod.test.cpp
  - Math/tests/formal_power_series_multiply.test.cpp
  - Math/tests/ntt.test.cpp
  - Math/tests/formal_power_series_multiply_any_mod.test.cpp
documentation_of: Math/Polynomial/NTT.h
layout: document
redirect_from:
- /library/Math/Polynomial/NTT.h
- /library/Math/Polynomial/NTT.h.html
title: Math/Polynomial/NTT.h
---
