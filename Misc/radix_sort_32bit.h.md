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
  bundledCode: "#line 1 \"Misc/radix_sort_32bit.h\"\n// Note: Doesn't handle negative\
    \ numbers\nvoid radix_sort(std::vector<uint32_t>& arr) {\n    const uint32_t FULL_MASK\
    \ = (1<<16) - 1;\n    auto get1 = [] (uint32_t x) { return x & FULL_MASK; };\n\
    \    auto get2 = [] (uint32_t x) { return x >> 16; };\n\n    std::vector<int>\
    \ cnt1(1<<16, 0);  // frequencies of low bits\n    std::vector<int> cnt2(1<<16,\
    \ 0);  // frequencies of high bits\n    for (auto x : arr) {\n        cnt1[get1(x)]++;\n\
    \        cnt2[get2(x)]++;\n    }\n    std::partial_sum(cnt1.begin(), cnt1.end(),\
    \ cnt1.begin());\n    std::partial_sum(cnt2.begin(), cnt2.end(), cnt2.begin());\n\
    \n    int n = arr.size();\n    std::vector<uint32_t> tmp(n);\n    for (int i =\
    \ n-1; i >= 0; --i) tmp[--cnt1[get1(arr[i])]] = arr[i];\n    for (int i = n-1;\
    \ i >= 0; --i) arr[--cnt2[get2(tmp[i])]] = tmp[i];\n}\n"
  code: "// Note: Doesn't handle negative numbers\nvoid radix_sort(std::vector<uint32_t>&\
    \ arr) {\n    const uint32_t FULL_MASK = (1<<16) - 1;\n    auto get1 = [] (uint32_t\
    \ x) { return x & FULL_MASK; };\n    auto get2 = [] (uint32_t x) { return x >>\
    \ 16; };\n\n    std::vector<int> cnt1(1<<16, 0);  // frequencies of low bits\n\
    \    std::vector<int> cnt2(1<<16, 0);  // frequencies of high bits\n    for (auto\
    \ x : arr) {\n        cnt1[get1(x)]++;\n        cnt2[get2(x)]++;\n    }\n    std::partial_sum(cnt1.begin(),\
    \ cnt1.end(), cnt1.begin());\n    std::partial_sum(cnt2.begin(), cnt2.end(), cnt2.begin());\n\
    \n    int n = arr.size();\n    std::vector<uint32_t> tmp(n);\n    for (int i =\
    \ n-1; i >= 0; --i) tmp[--cnt1[get1(arr[i])]] = arr[i];\n    for (int i = n-1;\
    \ i >= 0; --i) arr[--cnt2[get2(tmp[i])]] = tmp[i];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/radix_sort_32bit.h
  requiredBy: []
  timestamp: '2022-12-24 01:20:44+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/radix_sort_32bit.h
layout: document
redirect_from:
- /library/Misc/radix_sort_32bit.h
- /library/Misc/radix_sort_32bit.h.html
title: Misc/radix_sort_32bit.h
---
