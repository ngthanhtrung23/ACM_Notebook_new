---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: String/tests/manacher.test.cpp
    title: String/tests/manacher.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
    - https://oj.vnoi.info/problem/paliny
  bundledCode: "#line 1 \"String/manacher.h\"\n// Manacher {{{\n// Return <even_len,\
    \ odd_len>\n// - even_len[i] = length of longest palindrome centered at [i, i+1]\n\
    // - odd_len[i] = length of longest palindrome centered at i\n//\n// Tested:\n\
    // - https://judge.yosupo.jp/problem/enumerate_palindromes\n// - https://oj.vnoi.info/problem/paliny\n\
    std::array<vector<int>, 2> manacher(const string& s) {\n    int n = s.size();\n\
    \    std::array res = {vector<int> (n+1, 0), vector<int> (n, 0)};\n\n    for (int\
    \ z = 0; z < 2; z++) {\n        for (int i = 0, l = 0, r = 0; i < n; i++) {\n\
    \            int t = r - i + !z;\n            if (i < r) res[z][i] = min(t, res[z][l\
    \ + t]);\n\n            int l2 = i - res[z][i], r2 = i + res[z][i] - !z;\n   \
    \         while (l2 && r2 + 1 < n && s[l2 - 1] == s[r2 + 1]) {\n             \
    \   ++res[z][i];\n                --l2;\n                ++r2;\n            }\n\
    \            if (r2 > r) {\n                l = l2;\n                r = r2;\n\
    \            }\n        }\n        for (int i = 0; i < n; i++) {\n           \
    \ res[z][i] = 2*res[z][i] + z;\n        }\n    }\n    res[0].erase(res[0].begin(),\
    \ res[0].begin() + 1);\n    res[0].pop_back();\n    return res;\n}\n// }}}\n"
  code: "// Manacher {{{\n// Return <even_len, odd_len>\n// - even_len[i] = length\
    \ of longest palindrome centered at [i, i+1]\n// - odd_len[i] = length of longest\
    \ palindrome centered at i\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/enumerate_palindromes\n\
    // - https://oj.vnoi.info/problem/paliny\nstd::array<vector<int>, 2> manacher(const\
    \ string& s) {\n    int n = s.size();\n    std::array res = {vector<int> (n+1,\
    \ 0), vector<int> (n, 0)};\n\n    for (int z = 0; z < 2; z++) {\n        for (int\
    \ i = 0, l = 0, r = 0; i < n; i++) {\n            int t = r - i + !z;\n      \
    \      if (i < r) res[z][i] = min(t, res[z][l + t]);\n\n            int l2 = i\
    \ - res[z][i], r2 = i + res[z][i] - !z;\n            while (l2 && r2 + 1 < n &&\
    \ s[l2 - 1] == s[r2 + 1]) {\n                ++res[z][i];\n                --l2;\n\
    \                ++r2;\n            }\n            if (r2 > r) {\n           \
    \     l = l2;\n                r = r2;\n            }\n        }\n        for\
    \ (int i = 0; i < n; i++) {\n            res[z][i] = 2*res[z][i] + z;\n      \
    \  }\n    }\n    res[0].erase(res[0].begin(), res[0].begin() + 1);\n    res[0].pop_back();\n\
    \    return res;\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/manacher.h
  requiredBy: []
  timestamp: '2022-11-01 15:19:12+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - String/tests/manacher.test.cpp
documentation_of: String/manacher.h
layout: document
redirect_from:
- /library/String/manacher.h
- /library/String/manacher.h.html
title: String/manacher.h
---
