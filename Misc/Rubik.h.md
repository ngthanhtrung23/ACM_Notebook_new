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
  bundledCode: "#line 1 \"Misc/Rubik.h\"\n// \u0110\u1EBFm s\u1ED1 l\u1EA7n l\u1EB7\
    p l\u1EA1i chu\u1ED7i thao t\xE1c xoay rubik \u0111\u1EC3 n\xF3 quay tr\u1EDF\
    \ l\u1EA1i tr\u1EA1ng th\xE1i ban \u0111\u1EA7u\n// U (tr\xEAn), D (d\u01B0\u1EDB\
    i), L (tr\xE1i), R (ph\u1EA3i), F (tr\u01B0\u1EDBc), B (sau)\n// Ch\u1EEF th\u01B0\
    \u1EDDng l\xE0 xoay 90 \u0111\u1ED9 theo chi\u1EC1u kim \u0111\u1ED3ng h\u1ED3\
    , ch\u1EEF hoa l\xE0 xoay 90 \u0111\u1ED9 ng\u01B0\u1EE3c chi\u1EC1u kim \u0111\
    \u1ED3ng h\u1ED3\n\nint r[][8] = { { 1, 2, 3, 6, 9, 8, 7, 4 }, { 28, 29, 30, 33,\
    \ 36, 35, 34, 31 },\n        { 37, 38, 39, 42, 45, 44, 43, 40 }, { 19, 20, 21,\
    \ 24, 27, 26, 25, 22 },\n        { 46, 47, 48, 51, 54, 53, 52, 49 }, { 10, 11,\
    \ 12, 15, 18, 17, 16, 13 } };\n\nint c[][12] = { { 21, 20, 19, 10, 13, 16, 43,\
    \ 44, 45, 54, 51, 48 },\n                { 25, 26, 27, 46, 49, 52, 39, 38, 37,\
    \ 18, 15, 12 },\n                { 34, 35, 36, 52, 53, 54, 7, 8, 9, 16, 17, 18\
    \ },\n                { 3, 2, 1, 48, 47, 46, 30, 29, 28, 12, 11, 10 },\n     \
    \           { 27, 24, 21, 1, 4, 7, 45, 42, 39, 36, 33, 30 },\n               \
    \ { 19, 22, 25, 28, 31, 34, 37, 40, 43, 9, 6, 3 } };\n\nint a[55], flag[55], b[55];\n\
    \nvoid duyet(int x) {\n    For(i, 1, 54) b[i] = a[i];\n    Rep(i, 8) b[r[x][i]]\
    \ = a[r[x][(i + 6) % 8]];\n    Rep(i, 12) b[c[x][i]] = a[c[x][(i + 9) % 12]];\n\
    \    For(i, 1, 54) a[i] = b[i];\n}\n\nll rubik(string query) {\n    string s =\
    \ \"\";\n    Rep(i, sz(query)) {\n        if (query[i] >= 'a' && query[i] <= 'z')\
    \ {\n            query[i] += 'A' - 'a';\n            s.pb(query[i]); s.pb(query[i]);\
    \ s.pb(query[i]);\n        } else s.push_back(query[i]);\n    }\n\n    For(i,\
    \ 1, 54) a[i] = i;\n    ms(flag, 0);\n\n    Rep(i, sz(s)) {\n        if (s[i]\
    \ == 'U') duyet(0);\n        else if (s[i] == 'D') duyet(1);\n        else if\
    \ (s[i] == 'L') duyet(2);\n        else if (s[i] == 'R') duyet(3);\n        else\
    \ if (s[i] == 'F') duyet(4);\n        else duyet(5);\n    }\n\n    ll ret = 1;\n\
    \    For(i, 1, 54) if (!flag[i]) {\n        int t = i;\n        ll nhan = 1;\n\
    \        flag[i] = 1;\n\n        while (flag[a[t]] == 0) {\n            t = a[t];\n\
    \            flag[t] = 1;\n            nhan++;\n        }\n\n        ret = lcm(ret,\
    \ nhan);\n    }\n\n    return ret - 1;\n}\n"
  code: "// \u0110\u1EBFm s\u1ED1 l\u1EA7n l\u1EB7p l\u1EA1i chu\u1ED7i thao t\xE1\
    c xoay rubik \u0111\u1EC3 n\xF3 quay tr\u1EDF l\u1EA1i tr\u1EA1ng th\xE1i ban\
    \ \u0111\u1EA7u\n// U (tr\xEAn), D (d\u01B0\u1EDBi), L (tr\xE1i), R (ph\u1EA3\
    i), F (tr\u01B0\u1EDBc), B (sau)\n// Ch\u1EEF th\u01B0\u1EDDng l\xE0 xoay 90 \u0111\
    \u1ED9 theo chi\u1EC1u kim \u0111\u1ED3ng h\u1ED3, ch\u1EEF hoa l\xE0 xoay 90\
    \ \u0111\u1ED9 ng\u01B0\u1EE3c chi\u1EC1u kim \u0111\u1ED3ng h\u1ED3\n\nint r[][8]\
    \ = { { 1, 2, 3, 6, 9, 8, 7, 4 }, { 28, 29, 30, 33, 36, 35, 34, 31 },\n      \
    \  { 37, 38, 39, 42, 45, 44, 43, 40 }, { 19, 20, 21, 24, 27, 26, 25, 22 },\n \
    \       { 46, 47, 48, 51, 54, 53, 52, 49 }, { 10, 11, 12, 15, 18, 17, 16, 13 }\
    \ };\n\nint c[][12] = { { 21, 20, 19, 10, 13, 16, 43, 44, 45, 54, 51, 48 },\n\
    \                { 25, 26, 27, 46, 49, 52, 39, 38, 37, 18, 15, 12 },\n       \
    \         { 34, 35, 36, 52, 53, 54, 7, 8, 9, 16, 17, 18 },\n                {\
    \ 3, 2, 1, 48, 47, 46, 30, 29, 28, 12, 11, 10 },\n                { 27, 24, 21,\
    \ 1, 4, 7, 45, 42, 39, 36, 33, 30 },\n                { 19, 22, 25, 28, 31, 34,\
    \ 37, 40, 43, 9, 6, 3 } };\n\nint a[55], flag[55], b[55];\n\nvoid duyet(int x)\
    \ {\n    For(i, 1, 54) b[i] = a[i];\n    Rep(i, 8) b[r[x][i]] = a[r[x][(i + 6)\
    \ % 8]];\n    Rep(i, 12) b[c[x][i]] = a[c[x][(i + 9) % 12]];\n    For(i, 1, 54)\
    \ a[i] = b[i];\n}\n\nll rubik(string query) {\n    string s = \"\";\n    Rep(i,\
    \ sz(query)) {\n        if (query[i] >= 'a' && query[i] <= 'z') {\n          \
    \  query[i] += 'A' - 'a';\n            s.pb(query[i]); s.pb(query[i]); s.pb(query[i]);\n\
    \        } else s.push_back(query[i]);\n    }\n\n    For(i, 1, 54) a[i] = i;\n\
    \    ms(flag, 0);\n\n    Rep(i, sz(s)) {\n        if (s[i] == 'U') duyet(0);\n\
    \        else if (s[i] == 'D') duyet(1);\n        else if (s[i] == 'L') duyet(2);\n\
    \        else if (s[i] == 'R') duyet(3);\n        else if (s[i] == 'F') duyet(4);\n\
    \        else duyet(5);\n    }\n\n    ll ret = 1;\n    For(i, 1, 54) if (!flag[i])\
    \ {\n        int t = i;\n        ll nhan = 1;\n        flag[i] = 1;\n\n      \
    \  while (flag[a[t]] == 0) {\n            t = a[t];\n            flag[t] = 1;\n\
    \            nhan++;\n        }\n\n        ret = lcm(ret, nhan);\n    }\n\n  \
    \  return ret - 1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Rubik.h
  requiredBy: []
  timestamp: '2015-02-02 18:18:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Rubik.h
layout: document
redirect_from:
- /library/Misc/Rubik.h
- /library/Misc/Rubik.h.html
title: Misc/Rubik.h
---
