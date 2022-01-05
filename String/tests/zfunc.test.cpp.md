---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/zfunc.h
    title: String/zfunc.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"String/tests/zfunc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"String/zfunc.h\"\
    \n// z[i] = length of longest common prefix of s[0..N] and s[i..N]\n//\n// Tested:\n\
    // - https://judge.yosupo.jp/problem/zalgorithm\n// - (string matching) https://oj.vnoi.info/problem/substr\n\
    vector<int> zfunc(string s) {\n    int n = (int) s.length();\n    vector<int>\
    \ z(n);\n    z[0] = n;\n    for (int i = 1, l = 0, r = 0; i < n; ++i) {\n    \
    \    if (i <= r)\n            z[i] = min(r - i + 1, z[i - l]);\n        while\
    \ (i + z[i] < n && s[z[i]] == s[i + z[i]])\n            ++z[i];\n        if (i\
    \ + z[i] - 1 > r)\n            l = i, r = i + z[i] - 1;\n    }\n    return z;\n\
    }\n\n// Examples:\n// Find all occurrences of p in t\n\n/**\n    string s = p\
    \ + \"_\" + t;\n    auto z = zfunc(s);\n\n    REP(i,SZ(t)) {\n        if (z[i\
    \ + SZ(p) + 1] == SZ(p)) {\n            cout << 1+i << ' ';\n        }\n    }\n\
    \    cout << endl;\n*/\n#line 7 \"String/tests/zfunc.test.cpp\"\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    string s; cin >> s;\n    for\
    \ (auto x : zfunc(s)) {\n        cout << x << ' ';\n    }\n    cout << '\\n';\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../zfunc.h\"\n\nint32_t\
    \ main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    string s; cin >> s;\n\
    \    for (auto x : zfunc(s)) {\n        cout << x << ' ';\n    }\n    cout <<\
    \ '\\n';\n    return 0;\n}\n"
  dependsOn:
  - String/zfunc.h
  isVerificationFile: true
  path: String/tests/zfunc.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 05:40:17+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: String/tests/zfunc.test.cpp
layout: document
redirect_from:
- /verify/String/tests/zfunc.test.cpp
- /verify/String/tests/zfunc.test.cpp.html
title: String/tests/zfunc.test.cpp
---
