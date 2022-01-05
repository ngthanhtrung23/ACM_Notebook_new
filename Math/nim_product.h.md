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
    - https://judge.yosupo.jp/problem/nim_product_64
    - https://judge.yosupo.jp/submission/64825
    - https://oj.vnoi.info/problem/winstrat
  bundledCode: "#line 1 \"Math/nim_product.h\"\n// Nim product\n// Works for 0 <=\
    \ x, y < 2^64\n//\n// Copied from https://judge.yosupo.jp/submission/64825\n//\n\
    // Tested:\n// - https://oj.vnoi.info/problem/winstrat\n// - https://judge.yosupo.jp/problem/nim_product_64\n\
    using ull = unsigned long long;\null _naive_rec(ull x, ull y) {\n    if (x ==\
    \ 0 || y == 0) return 0;\n    if (x < y) swap(x, y);\n    if (y == 1) return x;\n\
    \n    for (int shift = 32; ; shift /= 2) {\n        ull mask = (1ull << shift)\
    \ - 1;\n        if (y >> shift) {\n            ull v00 = _naive_rec(x & mask,\
    \ y & mask);\n            ull v01 = _naive_rec(x & mask, y >> shift);\n      \
    \      ull v10 = _naive_rec(x >> shift, y & mask);\n            ull v11 = _naive_rec(x\
    \ >> shift, y >> shift);\n            return v00 ^ ((v01 ^ v10 ^ v11) << shift)\
    \ ^ _naive_rec(v11, 1ULL << (shift - 1));\n        } else if (x >> shift) {\n\
    \            return (_naive_rec(x >> shift, y) << shift) ^ _naive_rec(x & mask,\
    \ y);\n        }\n    }\n}\nconst array<array<unsigned, 256>, 256> smalls = []()\
    \ {\n    array<array<unsigned, 256>, 256> res;\n    for (int i = 0; i < 256; i++)\
    \ {\n        for (int j = 0; j < 256; j++) {\n            res[i][j] = _naive_rec(i,\
    \ j);\n        }\n    }\n    return res;\n}();\nconst array<array<array<ull, 256>,\
    \ 8>, 8> f = []() {\n    array<array<array<ull, 256>, 8>, 8> res;\n    for (int\
    \ d = 0; d < 8; d++) {\n        for (int e = 0; e < 8; e++) {\n            ull\
    \ p = _naive_rec(1ull << (8*d), 1ull << (8*e));\n            for (int i = 0; i\
    \ < 256; i++) res[d][e][i] = _naive_rec(p, i);\n        }\n    }\n    return res;\n\
    }();\n\null mult(ull x, ull y) {\n    ull res = 0;\n    for (int d = 0; d < 8;\
    \ d++) {\n        for (int e = 0; e < 8; e++) {\n            res ^= f[d][e][smalls[(x\
    \ >> (d * 8)) & 255][(y >> (e * 8)) & 255]];\n        }\n    }\n    return res;\n\
    }\n\n"
  code: "// Nim product\n// Works for 0 <= x, y < 2^64\n//\n// Copied from https://judge.yosupo.jp/submission/64825\n\
    //\n// Tested:\n// - https://oj.vnoi.info/problem/winstrat\n// - https://judge.yosupo.jp/problem/nim_product_64\n\
    using ull = unsigned long long;\null _naive_rec(ull x, ull y) {\n    if (x ==\
    \ 0 || y == 0) return 0;\n    if (x < y) swap(x, y);\n    if (y == 1) return x;\n\
    \n    for (int shift = 32; ; shift /= 2) {\n        ull mask = (1ull << shift)\
    \ - 1;\n        if (y >> shift) {\n            ull v00 = _naive_rec(x & mask,\
    \ y & mask);\n            ull v01 = _naive_rec(x & mask, y >> shift);\n      \
    \      ull v10 = _naive_rec(x >> shift, y & mask);\n            ull v11 = _naive_rec(x\
    \ >> shift, y >> shift);\n            return v00 ^ ((v01 ^ v10 ^ v11) << shift)\
    \ ^ _naive_rec(v11, 1ULL << (shift - 1));\n        } else if (x >> shift) {\n\
    \            return (_naive_rec(x >> shift, y) << shift) ^ _naive_rec(x & mask,\
    \ y);\n        }\n    }\n}\nconst array<array<unsigned, 256>, 256> smalls = []()\
    \ {\n    array<array<unsigned, 256>, 256> res;\n    for (int i = 0; i < 256; i++)\
    \ {\n        for (int j = 0; j < 256; j++) {\n            res[i][j] = _naive_rec(i,\
    \ j);\n        }\n    }\n    return res;\n}();\nconst array<array<array<ull, 256>,\
    \ 8>, 8> f = []() {\n    array<array<array<ull, 256>, 8>, 8> res;\n    for (int\
    \ d = 0; d < 8; d++) {\n        for (int e = 0; e < 8; e++) {\n            ull\
    \ p = _naive_rec(1ull << (8*d), 1ull << (8*e));\n            for (int i = 0; i\
    \ < 256; i++) res[d][e][i] = _naive_rec(p, i);\n        }\n    }\n    return res;\n\
    }();\n\null mult(ull x, ull y) {\n    ull res = 0;\n    for (int d = 0; d < 8;\
    \ d++) {\n        for (int e = 0; e < 8; e++) {\n            res ^= f[d][e][smalls[(x\
    \ >> (d * 8)) & 255][(y >> (e * 8)) & 255]];\n        }\n    }\n    return res;\n\
    }\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/nim_product.h
  requiredBy: []
  timestamp: '2021-12-31 16:23:34+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/nim_product.h
layout: document
redirect_from:
- /library/Math/nim_product.h
- /library/Math/nim_product.h.html
title: Math/nim_product.h
---
