---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: String/lyndon.cpp
    title: String/lyndon.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/lyndon.h\"\n// Decompose s = w1w2..wk : k max and\
    \ w1 >= w2 >= ...\n// each wi is strictly smaller than all its rotation\nvoid\
    \ lyndon(string s) {\n    int n = (int) s.length();\n    int i = 0;\n    while\
    \ (i < n) {\n        int j = i + 1, k = i;\n        while (j < n && s[k] <= s[j])\
    \ {\n            if (s[k] < s[j]) k = i;\n            else ++k;\n            ++j;\n\
    \        }\n        while (i <= k) {\n            cout << s.substr(i, j - k) <<\
    \ ' ';\n            i += j - k;\n        }\n    }\n    cout << endl;\n}\n"
  code: "// Decompose s = w1w2..wk : k max and w1 >= w2 >= ...\n// each wi is strictly\
    \ smaller than all its rotation\nvoid lyndon(string s) {\n    int n = (int) s.length();\n\
    \    int i = 0;\n    while (i < n) {\n        int j = i + 1, k = i;\n        while\
    \ (j < n && s[k] <= s[j]) {\n            if (s[k] < s[j]) k = i;\n           \
    \ else ++k;\n            ++j;\n        }\n        while (i <= k) {\n         \
    \   cout << s.substr(i, j - k) << ' ';\n            i += j - k;\n        }\n \
    \   }\n    cout << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/lyndon.h
  requiredBy:
  - String/lyndon.cpp
  timestamp: '2015-09-28 02:35:16+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/lyndon.h
layout: document
redirect_from:
- /library/String/lyndon.h
- /library/String/lyndon.h.html
title: String/lyndon.h
---
