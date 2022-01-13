---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DP/count_inversions.h
    title: DP/count_inversions.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
    title: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Misc/compress.h\"\n// Compress vector vs, and return the\
    \ compressed vector\n// Returned values in [0, k-1] where k = number of different\
    \ values\ntemplate<typename V>\nV compress(V vs) {\n    auto vals = vs;\n    sort(vals.begin(),\
    \ vals.end());\n    vals.erase(unique(vals.begin(), vals.end()), vals.end());\n\
    \n    for (auto& v : vs) {\n        v = lower_bound(vals.begin(), vals.end(),\
    \ v) - vals.begin();\n    }\n    return vs;\n}\n"
  code: "// Compress vector vs, and return the compressed vector\n// Returned values\
    \ in [0, k-1] where k = number of different values\ntemplate<typename V>\nV compress(V\
    \ vs) {\n    auto vals = vs;\n    sort(vals.begin(), vals.end());\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n\n    for (auto& v : vs) {\n        v = lower_bound(vals.begin(),\
    \ vals.end(), v) - vals.begin();\n    }\n    return vs;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/compress.h
  requiredBy:
  - DP/count_inversions.h
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
documentation_of: Misc/compress.h
layout: document
redirect_from:
- /library/Misc/compress.h
- /library/Misc/compress.h.html
title: Misc/compress.h
---
