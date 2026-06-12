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
    - https://github.com/zimpha/algorithmic-library/blob/master/cpp/mathematics/pell.py
  bundledCode: "#line 1 \"Misc/int128.h\"\n// i128 helper functions {{{\nusing i128\
    \ = __int128_t;\ni128 str2i128(std::string str) {\n    i128 ret = 0;\n    bool\
    \ minus = false;\n    for (auto c : str) {\n        if (c == '-')\n          \
    \  minus = true;\n        else\n            ret = ret * 10 + c - '0';\n    }\n\
    \    return minus ? -ret : ret;\n}\nstd::istream &operator>>(std::istream &is,\
    \ i128 &x) {\n    std::string s;\n    return is >> s, x = str2i128(s), is;\n}\n\
    std::ostream &operator<<(std::ostream &os, const i128 &x) {\n    i128 tmp = x;\n\
    \    if (tmp == 0) return os << 0;\n    std::vector<int> ds;\n    if (tmp < 0)\
    \ {\n        os << '-';\n        while (tmp) {\n            int d = tmp % 10;\n\
    \            if (d > 0) d -= 10;\n            ds.emplace_back(-d), tmp = (tmp\
    \ - d) / 10;\n        }\n    } else {\n        while (tmp) ds.emplace_back(tmp\
    \ % 10), tmp /= 10;\n    }\n    std::reverse(ds.begin(), ds.end());\n    for (auto\
    \ i : ds) os << i;\n    return os;\n}\ni128 my_abs(i128 n) {\n    if (n < 0) return\
    \ -n;\n    return n;\n}\ni128 gcd(i128 a, i128 b) {\n    if (b == 0) return a;\n\
    \    return gcd(b, a % b);\n}\n// Count trailing zeroes\nint ctz128(i128 n) {\n\
    \    if (!n) return 128;\n \n    if (!static_cast<uint64_t>(n)) {\n        return\
    \ __builtin_ctzll(static_cast<uint64_t>(n >> 64)) + 64;\n    } else {\n      \
    \  return __builtin_ctzll(static_cast<uint64_t>(n));\n    }\n}\n// }}}\n\n#line\
    \ 2 \"Math/Pure/pell_equation.h\"\n\n// From https://github.com/zimpha/algorithmic-library/blob/master/cpp/mathematics/pell.py\n\
    // Find minimum solution for x^2 - d*y^2 = 1 (d <= 1000)\n// Pell equation {{{\n\
    void up(i128& ai, i128& aim, i128 alpha) {\n    i128 old_ai = ai;\n    ai = alpha\
    \ * ai + aim;\n    aim = old_ai;\n}\npair<vector<i128>,i128> pqa(i128 p0, i128\
    \ q0, int d) {\n    double sqrt_d = sqrt(d);\n    i128 p_i = p0, q_i = q0;\n \
    \   i128 p_ir = LLONG_MIN, q_ir = LLONG_MIN;\n    i128 i = -1, ir = LLONG_MIN;\n\
    \    vector<i128> alphas;\n\n    while (1) {\n        ++i;\n        double xi_i\
    \ = (p_i + sqrt_d) / q_i;\n        double xibar_i = (p_i - sqrt_d) / q_i;\n  \
    \      i128 alpha_i = xi_i + 1e-9;\n\n        if (ir == LLONG_MIN && 1 < xi_i\
    \ && -1 < xibar_i && xibar_i < 0) {\n            ir = i;\n            p_ir = p_i;\n\
    \            q_ir = q_i;\n        }\n        if (ir != LLONG_MIN && ir != i &&\
    \ p_i == p_ir && q_i == q_ir) {\n            break;\n        }\n        alphas.push_back(alpha_i);\n\
    \        p_i = alpha_i * q_i - p_i;\n        q_i = (d - p_i * p_i) / q_i;\n  \
    \  }\n    return {alphas, i - ir};\n}\n\n// return minimum solution for x^2 -\
    \ d*y^2 = 1\npair<i128,i128> pell(int d) {\n    auto [alphas, l] = pqa(0, 1, d);\n\
    \n    int index = (l % 2 == 1) ? 2*l-1 : l-1;\n\n    i128 b_i = 0, b_im = 1;\n\
    \    i128 g_i = 1, g_im = 0;\n    int pl = alphas.size() - l;\n\n    for (int\
    \ i = 0; i <= index; ++i) {\n        i128 alpha_i;\n        if (i < pl) alpha_i\
    \ = alphas[i];\n        else alpha_i = alphas[pl + (i - pl) % l];\n\n        up(b_i,\
    \ b_im, alpha_i);\n        up(g_i, g_im, alpha_i);\n    }\n    return {g_i, b_i};\n\
    }\n// }}}\n"
  code: "#include \"../../Misc/int128.h\"\n\n// From https://github.com/zimpha/algorithmic-library/blob/master/cpp/mathematics/pell.py\n\
    // Find minimum solution for x^2 - d*y^2 = 1 (d <= 1000)\n// Pell equation {{{\n\
    void up(i128& ai, i128& aim, i128 alpha) {\n    i128 old_ai = ai;\n    ai = alpha\
    \ * ai + aim;\n    aim = old_ai;\n}\npair<vector<i128>,i128> pqa(i128 p0, i128\
    \ q0, int d) {\n    double sqrt_d = sqrt(d);\n    i128 p_i = p0, q_i = q0;\n \
    \   i128 p_ir = LLONG_MIN, q_ir = LLONG_MIN;\n    i128 i = -1, ir = LLONG_MIN;\n\
    \    vector<i128> alphas;\n\n    while (1) {\n        ++i;\n        double xi_i\
    \ = (p_i + sqrt_d) / q_i;\n        double xibar_i = (p_i - sqrt_d) / q_i;\n  \
    \      i128 alpha_i = xi_i + 1e-9;\n\n        if (ir == LLONG_MIN && 1 < xi_i\
    \ && -1 < xibar_i && xibar_i < 0) {\n            ir = i;\n            p_ir = p_i;\n\
    \            q_ir = q_i;\n        }\n        if (ir != LLONG_MIN && ir != i &&\
    \ p_i == p_ir && q_i == q_ir) {\n            break;\n        }\n        alphas.push_back(alpha_i);\n\
    \        p_i = alpha_i * q_i - p_i;\n        q_i = (d - p_i * p_i) / q_i;\n  \
    \  }\n    return {alphas, i - ir};\n}\n\n// return minimum solution for x^2 -\
    \ d*y^2 = 1\npair<i128,i128> pell(int d) {\n    auto [alphas, l] = pqa(0, 1, d);\n\
    \n    int index = (l % 2 == 1) ? 2*l-1 : l-1;\n\n    i128 b_i = 0, b_im = 1;\n\
    \    i128 g_i = 1, g_im = 0;\n    int pl = alphas.size() - l;\n\n    for (int\
    \ i = 0; i <= index; ++i) {\n        i128 alpha_i;\n        if (i < pl) alpha_i\
    \ = alphas[i];\n        else alpha_i = alphas[pl + (i - pl) % l];\n\n        up(b_i,\
    \ b_im, alpha_i);\n        up(g_i, g_im, alpha_i);\n    }\n    return {g_i, b_i};\n\
    }\n// }}}\n"
  dependsOn:
  - Misc/int128.h
  isVerificationFile: false
  path: Math/Pure/pell_equation.h
  requiredBy: []
  timestamp: '2022-12-27 16:11:10+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Pure/pell_equation.h
layout: document
redirect_from:
- /library/Math/Pure/pell_equation.h
- /library/Math/Pure/pell_equation.h.html
title: Math/Pure/pell_equation.h
---
