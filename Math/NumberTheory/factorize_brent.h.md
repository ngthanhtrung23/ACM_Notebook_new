---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Misc/int128.h
    title: Misc/int128.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/factorize
    - https://www.spoj.com/problems/FACT1/
  bundledCode: "#line 1 \"Math/NumberTheory/factorize_brent.h\"\n// This seems to\
    \ only work fine for random test cases\n// - AC (20 digits) https://www.spoj.com/problems/FACT1/\n\
    // - TLE https://judge.yosupo.jp/problem/factorize\n\n// brent {{{\n#line 1 \"\
    Misc/int128.h\"\n// i128 helper functions {{{\nusing i128 = __int128_t;\ni128\
    \ str2i128(std::string str) {\n    i128 ret = 0;\n    bool minus = false;\n  \
    \  for (auto c : str) {\n        if (c == '-')\n            minus = true;\n  \
    \      else\n            ret = ret * 10 + c - '0';\n    }\n    return minus ?\
    \ -ret : ret;\n}\nstd::istream &operator>>(std::istream &is, i128 &x) {\n    std::string\
    \ s;\n    return is >> s, x = str2i128(s), is;\n}\nstd::ostream &operator<<(std::ostream\
    \ &os, const i128 &x) {\n    i128 tmp = x;\n    if (tmp == 0) return os << 0;\n\
    \    std::vector<int> ds;\n    if (tmp < 0) {\n        os << '-';\n        while\
    \ (tmp) {\n            int d = tmp % 10;\n            if (d > 0) d -= 10;\n  \
    \          ds.emplace_back(-d), tmp = (tmp - d) / 10;\n        }\n    } else {\n\
    \        while (tmp) ds.emplace_back(tmp % 10), tmp /= 10;\n    }\n    std::reverse(ds.begin(),\
    \ ds.end());\n    for (auto i : ds) os << i;\n    return os;\n}\ni128 my_abs(i128\
    \ n) {\n    if (n < 0) return -n;\n    return n;\n}\ni128 gcd(i128 a, i128 b)\
    \ {\n    if (b == 0) return a;\n    return gcd(b, a % b);\n}\n// Count trailing\
    \ zeroes\nint ctz128(i128 n) {\n    if (!n) return 128;\n \n    if (!static_cast<uint64_t>(n))\
    \ {\n        return __builtin_ctzll(static_cast<uint64_t>(n >> 64)) + 64;\n  \
    \  } else {\n        return __builtin_ctzll(static_cast<uint64_t>(n));\n    }\n\
    }\n// }}}\n\n#line 7 \"Math/NumberTheory/factorize_brent.h\"\n\ni128 brute(i128\
    \ n) {\n    for (int i=2; i*i <= n; ++i) {\n        if (n % i == 0) return i;\n\
    \    }\n    return n;\n}\n\n// returns random int in range [1, n-1]\ni128 rand(i128\
    \ n) {\n    return rng() % (n-1) + 1;\n}\n\n// return one divisor of n\ni128 brent(i128\
    \ n) {\n    if (n % 2 == 0) return 2;\n    if (n < 200) return brute(n);\n\n \
    \   i128 y = rand(n), c = rand(n), m = rand(n);\n    auto sq_c = [c, n] (auto\
    \ y) {\n        return ((y*y) % n + c) % n;\n    };\n\n    i128 g = 1, r = 1,\
    \ q = 1, x, ys;\n\n    while (g == 1) {\n        x = y;\n        for (int i =\
    \ 0; i < r; ++i) y = sq_c(y);\n\n        int64_t k = 0;\n        while (k < r\
    \ && g == 1) {\n            ys = y;\n            for (int i = 0; i < min(m, r-k);\
    \ ++i) {\n                y = sq_c(y);\n                q = q * my_abs(x - y)\
    \ % n;\n            }\n            g = gcd(q, n);\n            k += m;\n     \
    \   }\n        r *= 2;\n    }\n\n    if (g == n) {\n        while (true) {\n \
    \           ys = sq_c(ys);\n            g = gcd(my_abs(x - ys), n);\n        \
    \    if (g > 1) break;\n        }\n    }\n    return g;\n}\n\nvoid factorize(i128\
    \ n, vector<i128>& fs) {\n    if (n == 1) return;\n\n    auto divisor = brent(n);\n\
    \    if (divisor == n) {\n        fs.push_back(divisor);\n        return;\n  \
    \  }\n\n    factorize(divisor, fs);\n    factorize(n/divisor, fs);\n}\n\nvector<i128>\
    \ factorize(i128 a) {\n    if (a == 1) return {};\n\n    vector<i128> res;\n \
    \   factorize(a, res);\n    sort(res.begin(), res.end());\n    return res;\n}\n\
    // }}}\n"
  code: "// This seems to only work fine for random test cases\n// - AC (20 digits)\
    \ https://www.spoj.com/problems/FACT1/\n// - TLE https://judge.yosupo.jp/problem/factorize\n\
    \n// brent {{{\n#include \"../../Misc/int128.h\"\n\ni128 brute(i128 n) {\n   \
    \ for (int i=2; i*i <= n; ++i) {\n        if (n % i == 0) return i;\n    }\n \
    \   return n;\n}\n\n// returns random int in range [1, n-1]\ni128 rand(i128 n)\
    \ {\n    return rng() % (n-1) + 1;\n}\n\n// return one divisor of n\ni128 brent(i128\
    \ n) {\n    if (n % 2 == 0) return 2;\n    if (n < 200) return brute(n);\n\n \
    \   i128 y = rand(n), c = rand(n), m = rand(n);\n    auto sq_c = [c, n] (auto\
    \ y) {\n        return ((y*y) % n + c) % n;\n    };\n\n    i128 g = 1, r = 1,\
    \ q = 1, x, ys;\n\n    while (g == 1) {\n        x = y;\n        for (int i =\
    \ 0; i < r; ++i) y = sq_c(y);\n\n        int64_t k = 0;\n        while (k < r\
    \ && g == 1) {\n            ys = y;\n            for (int i = 0; i < min(m, r-k);\
    \ ++i) {\n                y = sq_c(y);\n                q = q * my_abs(x - y)\
    \ % n;\n            }\n            g = gcd(q, n);\n            k += m;\n     \
    \   }\n        r *= 2;\n    }\n\n    if (g == n) {\n        while (true) {\n \
    \           ys = sq_c(ys);\n            g = gcd(my_abs(x - ys), n);\n        \
    \    if (g > 1) break;\n        }\n    }\n    return g;\n}\n\nvoid factorize(i128\
    \ n, vector<i128>& fs) {\n    if (n == 1) return;\n\n    auto divisor = brent(n);\n\
    \    if (divisor == n) {\n        fs.push_back(divisor);\n        return;\n  \
    \  }\n\n    factorize(divisor, fs);\n    factorize(n/divisor, fs);\n}\n\nvector<i128>\
    \ factorize(i128 a) {\n    if (a == 1) return {};\n\n    vector<i128> res;\n \
    \   factorize(a, res);\n    sort(res.begin(), res.end());\n    return res;\n}\n\
    // }}}\n"
  dependsOn:
  - Misc/int128.h
  isVerificationFile: false
  path: Math/NumberTheory/factorize_brent.h
  requiredBy: []
  timestamp: '2022-11-27 00:04:55+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NumberTheory/factorize_brent.h
layout: document
redirect_from:
- /library/Math/NumberTheory/factorize_brent.h
- /library/Math/NumberTheory/factorize_brent.h.html
title: Math/NumberTheory/factorize_brent.h
---
