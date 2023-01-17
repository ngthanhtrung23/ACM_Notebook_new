---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DP/coin_exchange.h\"\n// Returns number of ways we can exchange\
    \ k using set of coins {{{\ntemplate<typename T>\nT coin_exchange(int k, std::vector<int>\
    \ coins) {\n    std::vector<T> f(k + 1);\n    f[0] = 1;\n    for (int coin : coins)\
    \ {\n        for (int i = coin; i <= k; ++i) {\n            f[i] += f[i-coin];\n\
    \        }\n    }\n    return f.back();\n}\n// }}}\n"
  code: "// Returns number of ways we can exchange k using set of coins {{{\ntemplate<typename\
    \ T>\nT coin_exchange(int k, std::vector<int> coins) {\n    std::vector<T> f(k\
    \ + 1);\n    f[0] = 1;\n    for (int coin : coins) {\n        for (int i = coin;\
    \ i <= k; ++i) {\n            f[i] += f[i-coin];\n        }\n    }\n    return\
    \ f.back();\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/coin_exchange.h
  requiredBy: []
  timestamp: '2023-01-17 11:24:16+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/coin_exchange.h
layout: document
redirect_from:
- /library/DP/coin_exchange.h
- /library/DP/coin_exchange.h.html
title: DP/coin_exchange.h
---
