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
  bundledCode: "#line 1 \"Math/modulo.h\"\n/**\n * When MOD < 2^63, use following\
    \ mulMod:\n * Source: https://en.wikipedia.org/wiki/Modular_arithmetic#Example_implementations\n\
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
    \    b = b >> 1;\n        a = mulMod(a, a, m);\n    }\n    return r;\n}\n\n"
  code: "/**\n * When MOD < 2^63, use following mulMod:\n * Source: https://en.wikipedia.org/wiki/Modular_arithmetic#Example_implementations\n\
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
    \    b = b >> 1;\n        a = mulMod(a, a, m);\n    }\n    return r;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modulo.h
  requiredBy: []
  timestamp: '2018-10-15 11:00:44+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/modulo.h
layout: document
redirect_from:
- /library/Math/modulo.h
- /library/Math/modulo.h.html
title: Math/modulo.h
---
