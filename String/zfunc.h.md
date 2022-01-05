---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: String/tests/zfunc.test.cpp
    title: String/tests/zfunc.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
    - https://oj.vnoi.info/problem/substr
  bundledCode: "#line 1 \"String/zfunc.h\"\n// z[i] = length of longest common prefix\
    \ of s[0..N] and s[i..N]\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/zalgorithm\n\
    // - (string matching) https://oj.vnoi.info/problem/substr\nvector<int> zfunc(string\
    \ s) {\n    int n = (int) s.length();\n    vector<int> z(n);\n    z[0] = n;\n\
    \    for (int i = 1, l = 0, r = 0; i < n; ++i) {\n        if (i <= r)\n      \
    \      z[i] = min(r - i + 1, z[i - l]);\n        while (i + z[i] < n && s[z[i]]\
    \ == s[i + z[i]])\n            ++z[i];\n        if (i + z[i] - 1 > r)\n      \
    \      l = i, r = i + z[i] - 1;\n    }\n    return z;\n}\n\n// Examples:\n// Find\
    \ all occurrences of p in t\n\n/**\n    string s = p + \"_\" + t;\n    auto z\
    \ = zfunc(s);\n\n    REP(i,SZ(t)) {\n        if (z[i + SZ(p) + 1] == SZ(p)) {\n\
    \            cout << 1+i << ' ';\n        }\n    }\n    cout << endl;\n*/\n"
  code: "// z[i] = length of longest common prefix of s[0..N] and s[i..N]\n//\n//\
    \ Tested:\n// - https://judge.yosupo.jp/problem/zalgorithm\n// - (string matching)\
    \ https://oj.vnoi.info/problem/substr\nvector<int> zfunc(string s) {\n    int\
    \ n = (int) s.length();\n    vector<int> z(n);\n    z[0] = n;\n    for (int i\
    \ = 1, l = 0, r = 0; i < n; ++i) {\n        if (i <= r)\n            z[i] = min(r\
    \ - i + 1, z[i - l]);\n        while (i + z[i] < n && s[z[i]] == s[i + z[i]])\n\
    \            ++z[i];\n        if (i + z[i] - 1 > r)\n            l = i, r = i\
    \ + z[i] - 1;\n    }\n    return z;\n}\n\n// Examples:\n// Find all occurrences\
    \ of p in t\n\n/**\n    string s = p + \"_\" + t;\n    auto z = zfunc(s);\n\n\
    \    REP(i,SZ(t)) {\n        if (z[i + SZ(p) + 1] == SZ(p)) {\n            cout\
    \ << 1+i << ' ';\n        }\n    }\n    cout << endl;\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: String/zfunc.h
  requiredBy: []
  timestamp: '2021-12-30 03:03:55+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - String/tests/zfunc.test.cpp
documentation_of: String/zfunc.h
layout: document
redirect_from:
- /library/String/zfunc.h
- /library/String/zfunc.h.html
title: String/zfunc.h
---
