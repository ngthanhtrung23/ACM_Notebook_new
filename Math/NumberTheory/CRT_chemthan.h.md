---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/ntt_chemthan_any_mod.test.cpp
    title: Math/tests/ntt_chemthan_any_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
    - https://oj.vnoi.info/problem/icpc21_mt_d
  bundledCode: "#line 1 \"Math/NumberTheory/CRT_chemthan.h\"\n// CRT {{{\n// Tested:\n\
    // - https://oj.vnoi.info/problem/icpc21_mt_d\n// - (__int128_t) https://judge.yosupo.jp/problem/convolution_mod_1000000007\n\
    template<typename T>\nstruct CRT {\n    T res;\n\n    CRT() {\n        res = 0,\
    \ prd = 1;\n    }\n    \n    // Add condition: res % p == r\n    void add(T p,\
    \ T r) {\n        res += mul(r - res % p + p, euclid(prd, p).first + p, p) * prd;\n\
    \        prd *= p;\n        if (res >= prd) res -= prd;\n    }\n\nprivate:\n \
    \   T prd;\n    T mul(T a, T b, T p) {\n        a %= p, b %= p;\n        T q =\
    \ (T) ((long double) a * b / p);\n        T r = a * b - q * p;\n        while\
    \ (r < 0) r += p;\n        while (r >= p) r -= p;\n        return r;\n    }\n\
    \    pair<T, T> euclid(T a, T b) {\n        if (!b) return make_pair(1, 0);\n\
    \        pair<T, T> r = euclid(b, a % b);\n        return make_pair(r.second,\
    \ r.first - a / b * r.second);\n    }\n};\n// }}}\n"
  code: "// CRT {{{\n// Tested:\n// - https://oj.vnoi.info/problem/icpc21_mt_d\n//\
    \ - (__int128_t) https://judge.yosupo.jp/problem/convolution_mod_1000000007\n\
    template<typename T>\nstruct CRT {\n    T res;\n\n    CRT() {\n        res = 0,\
    \ prd = 1;\n    }\n    \n    // Add condition: res % p == r\n    void add(T p,\
    \ T r) {\n        res += mul(r - res % p + p, euclid(prd, p).first + p, p) * prd;\n\
    \        prd *= p;\n        if (res >= prd) res -= prd;\n    }\n\nprivate:\n \
    \   T prd;\n    T mul(T a, T b, T p) {\n        a %= p, b %= p;\n        T q =\
    \ (T) ((long double) a * b / p);\n        T r = a * b - q * p;\n        while\
    \ (r < 0) r += p;\n        while (r >= p) r -= p;\n        return r;\n    }\n\
    \    pair<T, T> euclid(T a, T b) {\n        if (!b) return make_pair(1, 0);\n\
    \        pair<T, T> r = euclid(b, a % b);\n        return make_pair(r.second,\
    \ r.first - a / b * r.second);\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/CRT_chemthan.h
  requiredBy: []
  timestamp: '2022-08-21 23:32:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/ntt_chemthan_any_mod.test.cpp
documentation_of: Math/NumberTheory/CRT_chemthan.h
layout: document
redirect_from:
- /library/Math/NumberTheory/CRT_chemthan.h
- /library/Math/NumberTheory/CRT_chemthan.h.html
title: Math/NumberTheory/CRT_chemthan.h
---
