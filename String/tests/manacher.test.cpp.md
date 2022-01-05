---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/manacher.h
    title: String/manacher.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"String/tests/manacher.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"String/manacher.h\"\
    \n// Return <even_len, odd_len>\n// - even_len[i] = length of longest palindrome\
    \ centered at [i, i+1]\n// - odd_len[i] = length of longest palindrome centered\
    \ at i\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/enumerate_palindromes\n\
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
    \    return res;\n}\n#line 7 \"String/tests/manacher.test.cpp\"\n\n#define REP(i,\
    \ a) for (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x) ((int)(x).size())\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    string s; cin\
    \ >> s;\n    auto [even, odd] = manacher(s);\n\n    REP(i,SZ(s)) {\n        cout\
    \ << odd[i] << ' ';\n        if (i+1 < SZ(s)) cout << even[i] << ' ';\n    }\n\
    \    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../manacher.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x)\
    \ ((int)(x).size())\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    string s; cin >> s;\n    auto [even, odd] = manacher(s);\n\n    REP(i,SZ(s))\
    \ {\n        cout << odd[i] << ' ';\n        if (i+1 < SZ(s)) cout << even[i]\
    \ << ' ';\n    }\n    cout << endl;\n    return 0;\n}\n"
  dependsOn:
  - String/manacher.h
  isVerificationFile: true
  path: String/tests/manacher.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 05:58:33+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: String/tests/manacher.test.cpp
layout: document
redirect_from:
- /verify/String/tests/manacher.test.cpp
- /verify/String/tests/manacher.test.cpp.html
title: String/tests/manacher.test.cpp
---
