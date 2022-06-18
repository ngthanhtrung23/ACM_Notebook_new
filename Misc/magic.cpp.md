---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Misc/magic.cpp\"\n#include <vector>\n\n// Given array D[i]\n\
    // Calculate D'[i] = sum( D[j] | j is subset of i )\nvoid sum_of_subset(std::vector<int>&\
    \ D, int K) {\n    for (int i = 0; i < K; ++i)\n        for (int mask = 0; mask\
    \ < (1 << K); ++mask)\n            if ((mask >> i) & 1) D[mask] += D[mask ^ (1\
    \ << i)];\n}\n\n// Given array D[i]\n// Calculate D'[i] = sum( D[j] | j is subset\
    \ of i )\nvoid sum_of_superset(std::vector<int>& D, int K) {\n    std::reverse(D.begin(),\
    \ D.end());\n    for (int i = 0; i < K; ++i)\n        for (int mask = 0; mask\
    \ < (1 << K); ++mask)\n            if ((mask >> i) & 1) D[mask] += D[mask ^ (1\
    \ << i)];\n    std::reverse(D.begin(), D.end());\n}\n"
  code: "#include <vector>\n\n// Given array D[i]\n// Calculate D'[i] = sum( D[j]\
    \ | j is subset of i )\nvoid sum_of_subset(std::vector<int>& D, int K) {\n   \
    \ for (int i = 0; i < K; ++i)\n        for (int mask = 0; mask < (1 << K); ++mask)\n\
    \            if ((mask >> i) & 1) D[mask] += D[mask ^ (1 << i)];\n}\n\n// Given\
    \ array D[i]\n// Calculate D'[i] = sum( D[j] | j is subset of i )\nvoid sum_of_superset(std::vector<int>&\
    \ D, int K) {\n    std::reverse(D.begin(), D.end());\n    for (int i = 0; i <\
    \ K; ++i)\n        for (int mask = 0; mask < (1 << K); ++mask)\n            if\
    \ ((mask >> i) & 1) D[mask] += D[mask ^ (1 << i)];\n    std::reverse(D.begin(),\
    \ D.end());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/magic.cpp
  requiredBy: []
  timestamp: '2022-06-19 02:44:37+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/magic.cpp
layout: document
redirect_from:
- /library/Misc/magic.cpp
- /library/Misc/magic.cpp.html
title: Misc/magic.cpp
---
