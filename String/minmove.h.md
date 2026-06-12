---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: String/minmove.cpp
    title: String/minmove.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1110/
  bundledCode: "#line 1 \"String/minmove.h\"\n// T\xEDnh v\u1ECB tr\xED c\u1EE7a x\xE2\
    u xoay v\xF2ng c\xF3 th\u1EE9 t\u1EF1 t\u1EEB \u0111i\u1EC3n nh\u1ECF nh\u1EA5\
    t c\u1EE7a x\xE2u s[]\n// Tested:\n// - https://cses.fi/problemset/task/1110/\n\
    int minmove(string s) {\n    int n = s.length();\n    int x, y, i, j, u, v; //\
    \ x is the smallest string before string y\n    for (x = 0, y = 1; y < n; ++ y)\
    \ {\n        i = u = x;\n        j = v = y;\n        while (s[i] == s[j]) {\n\
    \            ++ u; ++ v;\n            if (++ i == n) i = 0;\n            if (++\
    \ j == n) j = 0;\n            if (i == x) break; // All strings are equal\n  \
    \      }\n        if (s[i] <= s[j]) y = v;\n        else {\n            x = y;\n\
    \            if (u > y) y = u;\n        }\n    }\n    return x;\n}\n"
  code: "// T\xEDnh v\u1ECB tr\xED c\u1EE7a x\xE2u xoay v\xF2ng c\xF3 th\u1EE9 t\u1EF1\
    \ t\u1EEB \u0111i\u1EC3n nh\u1ECF nh\u1EA5t c\u1EE7a x\xE2u s[]\n// Tested:\n\
    // - https://cses.fi/problemset/task/1110/\nint minmove(string s) {\n    int n\
    \ = s.length();\n    int x, y, i, j, u, v; // x is the smallest string before\
    \ string y\n    for (x = 0, y = 1; y < n; ++ y) {\n        i = u = x;\n      \
    \  j = v = y;\n        while (s[i] == s[j]) {\n            ++ u; ++ v;\n     \
    \       if (++ i == n) i = 0;\n            if (++ j == n) j = 0;\n           \
    \ if (i == x) break; // All strings are equal\n        }\n        if (s[i] <=\
    \ s[j]) y = v;\n        else {\n            x = y;\n            if (u > y) y =\
    \ u;\n        }\n    }\n    return x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/minmove.h
  requiredBy:
  - String/minmove.cpp
  timestamp: '2022-01-07 02:39:31+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/minmove.h
layout: document
redirect_from:
- /library/String/minmove.h
- /library/String/minmove.h.html
title: String/minmove.h
---
