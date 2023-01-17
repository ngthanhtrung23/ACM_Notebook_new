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
  bundledCode: "#line 1 \"DP/knapsack.h\"\n// Knapsack 01 {{{\n// Select subset of\
    \ items, such that sum(weights) <= capacity\n// and sum(values) is maximum\nint\
    \ knapsack01(\n        int capacity,\n        const std::vector<int>& weights,\n\
    \        const std::vector<int>& values) {\n    int n = weights.size();\n    std::vector<int>\
    \ f(capacity + 1, 0);\n    for (int i = 0; i < n; ++i) {\n        for (int j =\
    \ capacity; j >= weights[i]; --j) {\n            f[j] = max(f[j], f[j-weights[i]]\
    \ + values[i]);\n        }\n    }\n\n    return *max_element(f.begin(), f.end());\n\
    }\n// }}}\n"
  code: "// Knapsack 01 {{{\n// Select subset of items, such that sum(weights) <=\
    \ capacity\n// and sum(values) is maximum\nint knapsack01(\n        int capacity,\n\
    \        const std::vector<int>& weights,\n        const std::vector<int>& values)\
    \ {\n    int n = weights.size();\n    std::vector<int> f(capacity + 1, 0);\n \
    \   for (int i = 0; i < n; ++i) {\n        for (int j = capacity; j >= weights[i];\
    \ --j) {\n            f[j] = max(f[j], f[j-weights[i]] + values[i]);\n       \
    \ }\n    }\n\n    return *max_element(f.begin(), f.end());\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/knapsack.h
  requiredBy: []
  timestamp: '2023-01-17 11:24:16+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/knapsack.h
layout: document
redirect_from:
- /library/DP/knapsack.h
- /library/DP/knapsack.h.html
title: DP/knapsack.h
---
