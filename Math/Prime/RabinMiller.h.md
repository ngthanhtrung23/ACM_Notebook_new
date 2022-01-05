---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Modular_arithmetic#Example_implementations
  bundledCode: "#line 1 \"Math/Prime/RabinMiller.h\"\n// Use isPrime in Pollard.h\
    \ instead\n\ntypedef long long ll;\n\n// mulMod and powMod is same as Math/modulo.h.\n\
    // These 2 functions are duplicated here for easier copy-paste.\n\n/**\n * When\
    \ MOD < 2^63, use following mulMod:\n * Source: https://en.wikipedia.org/wiki/Modular_arithmetic#Example_implementations\n\
    \ * On computer architectures where an extended precision format with at least\
    \ 64 bits\n * of mantissa is available (such as the long double type of most x86\
    \ C compilers),\n * the following routine is faster than any algorithmic solution,\
    \ by employing the\n * trick that, by hardware, floating-point multiplication\
    \ results in the most\n * significant bits of the product kept, while integer\
    \ multiplication results in the\n * least significant bits kept\n */\nuint64_t\
    \ mulMod(uint64_t a, uint64_t b, uint64_t m) {\n    long double x;\n    uint64_t\
    \ c;\n    int64_t r;\n\n    if (a >= m) a %= m;\n    if (b >= m) b %= m;\n\n \
    \   x = a;\n    c = x * b / m;\n    r = (int64_t)(a * b - c * m) % (int64_t)m;\n\
    \    return r < 0 ? r + m : r;\n}\n\n/** Calculates a^b % m */\nuint64_t powMod(uint64_t\
    \ a, uint64_t b, uint64_t m) {\n    uint64_t r = m==1?0:1; // make it works when\
    \ m == 1.\n    while (b > 0) {\n        if (b & 1) r = mulMod(r, a, m);\n    \
    \    b = b >> 1;\n        a = mulMod(a, a, m);\n    }\n    return r;\n}\n\nbool\
    \ suspect(ll a, ll s, ll d, ll n) {\n    ll x = powMod(a, d, n);\n    if (x ==\
    \ 1) return true;\n    for (int r = 0; r < s; ++r) {\n        if (x == n - 1)\
    \ return true;\n        x = mulMod(x, x, n);\n    }\n    return false;\n}\n//\
    \ {2,7,61,-1}                      is for n < 4759123141 (= 2^32)\n// {2,3,5,7,11,13,17,19,23,-1}\
    \ is for n < 10^15 (at least)\nbool isPrime(int64_t n) {\n    if (n <= 1 || (n\
    \ > 2 && n % 2 == 0)) return false;\n    ll test[] = {2,3,5,7,11,13,17,19,23,-1};\n\
    \    ll d = n - 1, s = 0;\n    while (d % 2 == 0) ++s, d /= 2;\n    for (int i\
    \ = 0; test[i] < n && test[i] != -1; ++i)\n        if (!suspect(test[i], s, d,\
    \ n)) return false;\n    return true;\n}\n// Killer prime: 5555555557LL (fail\
    \ when not used mulMod)\n"
  code: "// Use isPrime in Pollard.h instead\n\ntypedef long long ll;\n\n// mulMod\
    \ and powMod is same as Math/modulo.h.\n// These 2 functions are duplicated here\
    \ for easier copy-paste.\n\n/**\n * When MOD < 2^63, use following mulMod:\n *\
    \ Source: https://en.wikipedia.org/wiki/Modular_arithmetic#Example_implementations\n\
    \ * On computer architectures where an extended precision format with at least\
    \ 64 bits\n * of mantissa is available (such as the long double type of most x86\
    \ C compilers),\n * the following routine is faster than any algorithmic solution,\
    \ by employing the\n * trick that, by hardware, floating-point multiplication\
    \ results in the most\n * significant bits of the product kept, while integer\
    \ multiplication results in the\n * least significant bits kept\n */\nuint64_t\
    \ mulMod(uint64_t a, uint64_t b, uint64_t m) {\n    long double x;\n    uint64_t\
    \ c;\n    int64_t r;\n\n    if (a >= m) a %= m;\n    if (b >= m) b %= m;\n\n \
    \   x = a;\n    c = x * b / m;\n    r = (int64_t)(a * b - c * m) % (int64_t)m;\n\
    \    return r < 0 ? r + m : r;\n}\n\n/** Calculates a^b % m */\nuint64_t powMod(uint64_t\
    \ a, uint64_t b, uint64_t m) {\n    uint64_t r = m==1?0:1; // make it works when\
    \ m == 1.\n    while (b > 0) {\n        if (b & 1) r = mulMod(r, a, m);\n    \
    \    b = b >> 1;\n        a = mulMod(a, a, m);\n    }\n    return r;\n}\n\nbool\
    \ suspect(ll a, ll s, ll d, ll n) {\n    ll x = powMod(a, d, n);\n    if (x ==\
    \ 1) return true;\n    for (int r = 0; r < s; ++r) {\n        if (x == n - 1)\
    \ return true;\n        x = mulMod(x, x, n);\n    }\n    return false;\n}\n//\
    \ {2,7,61,-1}                      is for n < 4759123141 (= 2^32)\n// {2,3,5,7,11,13,17,19,23,-1}\
    \ is for n < 10^15 (at least)\nbool isPrime(int64_t n) {\n    if (n <= 1 || (n\
    \ > 2 && n % 2 == 0)) return false;\n    ll test[] = {2,3,5,7,11,13,17,19,23,-1};\n\
    \    ll d = n - 1, s = 0;\n    while (d % 2 == 0) ++s, d /= 2;\n    for (int i\
    \ = 0; test[i] < n && test[i] != -1; ++i)\n        if (!suspect(test[i], s, d,\
    \ n)) return false;\n    return true;\n}\n// Killer prime: 5555555557LL (fail\
    \ when not used mulMod)\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Prime/RabinMiller.h
  requiredBy: []
  timestamp: '2021-12-19 02:05:12+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Prime/RabinMiller.h
layout: document
redirect_from:
- /library/Math/Prime/RabinMiller.h
- /library/Math/Prime/RabinMiller.h.html
title: Math/Prime/RabinMiller.h
---
