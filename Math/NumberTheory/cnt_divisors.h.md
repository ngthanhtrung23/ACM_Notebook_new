---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/NumberTheory/Pollard.h
    title: Math/NumberTheory/Pollard.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/cnt_divisors_stress.test.cpp
    title: Math/tests/cnt_divisors_stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.spoj.com/problems/NUMDIV/
  bundledCode: "#line 1 \"Math/NumberTheory/Pollard.h\"\n// Pollard {{{\n// Copied\
    \ from https://judge.yosupo.jp/submission/61447\n// O(N^0.25)\n//\n// Tested:\n\
    // - (up to 10^18; 200 tests) https://judge.yosupo.jp/problem/factorize\n// -\
    \ https://oj.vnoi.info/problem/icpc21_beta_l\n// - https://www.spoj.com/problems/FACT0/\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    ll mult(ll x, ll y, ll md) {\n    ull q = (ld)x * y / md;\n    ll res = ((ull)x\
    \ * y - q * md);\n    if (res >= md) res -= md;\n    if (res < 0) res += md;\n\
    \    return res;\n}\n\nll powMod(ll x, ll p, ll md) {\n    if (p == 0) return\
    \ 1;\n    if (p & 1) return mult(x, powMod(x, p - 1, md), md);\n    return powMod(mult(x,\
    \ x, md), p / 2, md);\n}\n\nbool checkMillerRabin(ll x, ll md, ll s, int k) {\n\
    \    x = powMod(x, s, md);\n    if (x == 1) return true;\n    while(k--) {\n \
    \       if (x == md - 1) return true;\n        x = mult(x, x, md);\n        if\
    \ (x == 1) return false;\n    }\n    return false;\n}\nbool isPrime(ll x) {\n\
    \    if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n    if (x % 2 ==\
    \ 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n    if (x < 121)\
    \ return x > 1;\n    ll s = x - 1;\n    int k = 0;\n    while(s % 2 == 0) {\n\
    \        s >>= 1;\n        k++;\n    }\n    if (x < 1LL << 32) {\n        for\
    \ (ll z : {2, 7, 61}) {\n            if (!checkMillerRabin(z, x, s, k)) return\
    \ false;\n        }\n    } else {\n        for (ll z : {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\n            if (!checkMillerRabin(z, x, s, k)) return\
    \ false;\n        }\n    }\n    return true;\n}\n\nll gcd(ll x, ll y) {\n    return\
    \ y == 0 ? x : gcd(y, x % y);\n}\n\nvoid pollard(ll x, vector<ll> &ans) {\n  \
    \  if (isPrime(x)) {\n        ans.push_back(x);\n        return;\n    }\n    ll\
    \ c = 1;\n    while(true) {\n        c = 1 + get_rand(x - 1);\n        auto f\
    \ = [&](ll y) {\n            ll res = mult(y, y, x) + c;\n            if (res\
    \ >= x) res -= x;\n            return res;\n        };\n        ll y = 2;\n  \
    \      int B = 100;\n        int len = 1;\n        ll g = 1;\n        while(g\
    \ == 1) {\n            ll z = y;\n            for (int i = 0; i < len; i++) {\n\
    \                z = f(z);\n            }\n            ll zs = -1;\n         \
    \   int lft = len;\n            while(g == 1 && lft > 0) {\n                zs\
    \ = z;\n                ll p = 1;\n                for (int i = 0; i < B && i\
    \ < lft; i++) {\n                    p = mult(p, abs(z - y), x);\n           \
    \         z = f(z);\n                }\n                g = gcd(p, x);\n     \
    \           lft -= B;\n            }\n            if (g == 1) {\n            \
    \    y = z;\n                len <<= 1;\n                continue;\n         \
    \   }\n            if (g == x) {\n                g = 1;\n                z =\
    \ zs;\n                while(g == 1) {\n                    g = gcd(abs(z - y),\
    \ x);\n                    z = f(z);\n                }\n            }\n     \
    \       if (g == x) break;\n            assert(g != 1);\n            pollard(g,\
    \ ans);\n            pollard(x / g, ans);\n            return;\n        }\n  \
    \  }\n}\n// return list of all prime factors of x (can have duplicates)\nvector<ll>\
    \ factorize(ll x) {\n    vector<ll> ans;\n    for (ll p : {2, 3, 5, 7, 11, 13,\
    \ 17, 19}) {\n        while(x % p == 0) {\n            x /= p;\n            ans.push_back(p);\n\
    \        }\n    }\n    if (x != 1) {\n        pollard(x, ans);\n    }\n    sort(ans.begin(),\
    \ ans.end());\n    return ans;\n}\n// return pairs of (p, k) where x = product(p^k)\n\
    vector<pair<ll, int>> factorize_pk(ll x) {\n    auto ps = factorize(x);\n    ll\
    \ last = -1, cnt = 0;\n    vector<pair<ll, int>> res;\n    for (auto p : ps) {\n\
    \        if (p == last) ++cnt;\n        else {\n            if (last > 0) res.emplace_back(last,\
    \ cnt);\n            last = p;\n            cnt = 1;\n        }\n    }\n    if\
    \ (cnt > 0) {\n        res.emplace_back(last, cnt);\n    }\n    return res;\n\
    }\n// }}}\n#line 2 \"Math/NumberTheory/cnt_divisors.h\"\n\n// Tested: https://www.spoj.com/problems/NUMDIV/\n\
    int64_t cnt_divisors(int64_t n) {\n    assert(n > 0);\n    auto ps = factorize(n);\n\
    \    int cnt_ps = ps.size();\n    int i = 0;\n    int64_t res = 1;\n    while\
    \ (i < cnt_ps) {\n        int j = i;\n        while (j+1 < cnt_ps && ps[j+1] ==\
    \ ps[j]) ++j;\n        res *= j - i + 2;\n        i = j + 1;\n    }\n    return\
    \ res;\n}\n"
  code: "#include \"Pollard.h\"\n\n// Tested: https://www.spoj.com/problems/NUMDIV/\n\
    int64_t cnt_divisors(int64_t n) {\n    assert(n > 0);\n    auto ps = factorize(n);\n\
    \    int cnt_ps = ps.size();\n    int i = 0;\n    int64_t res = 1;\n    while\
    \ (i < cnt_ps) {\n        int j = i;\n        while (j+1 < cnt_ps && ps[j+1] ==\
    \ ps[j]) ++j;\n        res *= j - i + 2;\n        i = j + 1;\n    }\n    return\
    \ res;\n}\n"
  dependsOn:
  - Math/NumberTheory/Pollard.h
  isVerificationFile: false
  path: Math/NumberTheory/cnt_divisors.h
  requiredBy: []
  timestamp: '2022-12-26 20:16:27+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/cnt_divisors_stress.test.cpp
documentation_of: Math/NumberTheory/cnt_divisors.h
layout: document
redirect_from:
- /library/Math/NumberTheory/cnt_divisors.h
- /library/Math/NumberTheory/cnt_divisors.h.html
title: Math/NumberTheory/cnt_divisors.h
---
