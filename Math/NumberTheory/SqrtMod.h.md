---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/sqrt_mod.test.cpp
    title: Math/tests/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
    - https://judge.yosupo.jp/submission/59210
    - https://oj.vnoi.info/problem/jacobi
    - https://oj.vnoi.info/problem/newj
  bundledCode: "#line 1 \"Math/NumberTheory/SqrtMod.h\"\n// sqrtMod(X, q), with q\
    \ is prime, returns:\n// a where a*a = X\n// -1 if no solution\n//\n// Note:\n\
    // - there are either 1 or 2 solutions, a and p - a (which can be same).\n// \
    \  This code return smaller solution\n//\n// Copied from https://judge.yosupo.jp/submission/59210\n\
    //\n// Tested:\n// - (p <= 10^9) https://judge.yosupo.jp/problem/sqrt_mod\n//\
    \ - (print all sols) https://oj.vnoi.info/problem/jacobi\n// - https://oj.vnoi.info/problem/newj\n\
    \n// sqrtMod {{{\nusing ll = long long;\nll euclid(ll x, ll y, ll &k, ll &l) {\n\
    \    if (y == 0) {\n        k = 1;\n        l = 0;\n        return x;\n    }\n\
    \    ll g = euclid(y, x % y, l, k);\n    l -= k * (x / y);\n    return g;\n}\n\
    \nll mult(ll x, ll y, ll md) {\n    return x * y % md;\n}\nll bin_pow(ll x, ll\
    \ p, ll md) {\n    if (p == 0) return 1;\n    if (p & 1) return mult(x, bin_pow(x,\
    \ p - 1, md), md);\n    return bin_pow(mult(x, x, md), p / 2, md);\n}\n\nll Cipolla(ll\
    \ X, ll q) {\n    ll pw = (q - 1) / 2;\n    int K = 60;\n    while((1LL << K)\
    \ > pw) K--;\n    while(true) {\n        ll t = get_rand(q);\n        ll a = 0,\
    \ b = 0, c = 1;\n        for (int k = K; k >= 0; k--) {\n            a = b * b\
    \ % q;\n            b = 2 * b * c % q;\n            c = (c * c + a * X) % q;\n\
    \            if (((pw >> k) & 1) == 0) continue;\n            a = b;\n       \
    \     b = (b * t + c) % q;\n            c = (c * t + a * X) % q;\n        }\n\
    \        if (b == 0) continue;\n        c = (c + q - 1) % q;\n        ll k, l;\n\
    \        euclid(b, q, k, l);\n        c = -c * k % q;\n        if (c < 0) c +=\
    \ q;\n        if (c * c % q == X) return c;\n    }\n    assert(false);\n}\n\n\
    ll sqrtMod(ll X, ll q) {\n    X %= q;\n    if (q == 2 || X == 0) return min(X,\
    \ q-X);\n    if (bin_pow(X, (q - 1) / 2, q) != 1) return -1;\n    if (q % 4 ==\
    \ 3) {\n        ll res = bin_pow(X, (q + 1) / 4, q);\n        return min(res,\
    \ q - res);\n    }\n    auto res = (Cipolla(X, q) % q + q) % q;\n    return min(res,\
    \ q-res);\n}\n// }}}\n"
  code: "// sqrtMod(X, q), with q is prime, returns:\n// a where a*a = X\n// -1 if\
    \ no solution\n//\n// Note:\n// - there are either 1 or 2 solutions, a and p -\
    \ a (which can be same).\n//   This code return smaller solution\n//\n// Copied\
    \ from https://judge.yosupo.jp/submission/59210\n//\n// Tested:\n// - (p <= 10^9)\
    \ https://judge.yosupo.jp/problem/sqrt_mod\n// - (print all sols) https://oj.vnoi.info/problem/jacobi\n\
    // - https://oj.vnoi.info/problem/newj\n\n// sqrtMod {{{\nusing ll = long long;\n\
    ll euclid(ll x, ll y, ll &k, ll &l) {\n    if (y == 0) {\n        k = 1;\n   \
    \     l = 0;\n        return x;\n    }\n    ll g = euclid(y, x % y, l, k);\n \
    \   l -= k * (x / y);\n    return g;\n}\n\nll mult(ll x, ll y, ll md) {\n    return\
    \ x * y % md;\n}\nll bin_pow(ll x, ll p, ll md) {\n    if (p == 0) return 1;\n\
    \    if (p & 1) return mult(x, bin_pow(x, p - 1, md), md);\n    return bin_pow(mult(x,\
    \ x, md), p / 2, md);\n}\n\nll Cipolla(ll X, ll q) {\n    ll pw = (q - 1) / 2;\n\
    \    int K = 60;\n    while((1LL << K) > pw) K--;\n    while(true) {\n       \
    \ ll t = get_rand(q);\n        ll a = 0, b = 0, c = 1;\n        for (int k = K;\
    \ k >= 0; k--) {\n            a = b * b % q;\n            b = 2 * b * c % q;\n\
    \            c = (c * c + a * X) % q;\n            if (((pw >> k) & 1) == 0) continue;\n\
    \            a = b;\n            b = (b * t + c) % q;\n            c = (c * t\
    \ + a * X) % q;\n        }\n        if (b == 0) continue;\n        c = (c + q\
    \ - 1) % q;\n        ll k, l;\n        euclid(b, q, k, l);\n        c = -c * k\
    \ % q;\n        if (c < 0) c += q;\n        if (c * c % q == X) return c;\n  \
    \  }\n    assert(false);\n}\n\nll sqrtMod(ll X, ll q) {\n    X %= q;\n    if (q\
    \ == 2 || X == 0) return min(X, q-X);\n    if (bin_pow(X, (q - 1) / 2, q) != 1)\
    \ return -1;\n    if (q % 4 == 3) {\n        ll res = bin_pow(X, (q + 1) / 4,\
    \ q);\n        return min(res, q - res);\n    }\n    auto res = (Cipolla(X, q)\
    \ % q + q) % q;\n    return min(res, q-res);\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/SqrtMod.h
  requiredBy: []
  timestamp: '2022-12-25 00:11:23+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/sqrt_mod.test.cpp
documentation_of: Math/NumberTheory/SqrtMod.h
layout: document
redirect_from:
- /library/Math/NumberTheory/SqrtMod.h
- /library/Math/NumberTheory/SqrtMod.h.html
title: Math/NumberTheory/SqrtMod.h
---
