---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/SumDiv_SumMod.h
    title: Math/SumDiv_SumMod.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"Math/tests/sumdiv.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Math/SumDiv_SumMod.h\"\
    \n// Copied from https://judge.yosupo.jp/submission/15864\n// Tested:\n// - https://judge.yosupo.jp/problem/sum_of_floor_of_linear\n\
    \nusing ll = long long;\nll sum(ll n) {\n    return n * (n-1) / 2;\n}\n// sum(\
    \ (a + d*i) / m ) for i in [0, n-1]\nll sum_div(ll a, ll d, ll m, ll n) {\n  \
    \  ll res = d / m * sum(n) + a / m * n;\n    d %= m, a %= m;\n    if (!d) return\
    \ res;\n    ll to = (n * d + a) / m;\n    return res + (n - 1) * to - sum_div(m\
    \ - 1 - a, m, d, to);\n}\n// sum( (a + d*i) % m ) for i in [0, n-1]\nll sum_mod(ll\
    \ a, ll d, ll m, ll n) {\n  a = ((a % m) + m) % m, d = ((d % m) + m) % m;\n  return\
    \ n * a + d * sum(n) - m * sum_div(a, d, m, n);\n}\n#line 7 \"Math/tests/sumdiv.test.cpp\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int ntest;\
    \ cin >> ntest;\n    while (ntest--) {\n        ll n, m, a, b; cin >> n >> m >>\
    \ a >> b;\n        cout << sum_div(b, a, m, n) << '\\n';\n    }\n    return 0;\n\
    }\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../SumDiv_SumMod.h\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int ntest;\
    \ cin >> ntest;\n    while (ntest--) {\n        ll n, m, a, b; cin >> n >> m >>\
    \ a >> b;\n        cout << sum_div(b, a, m, n) << '\\n';\n    }\n    return 0;\n\
    }\n\n"
  dependsOn:
  - Math/SumDiv_SumMod.h
  isVerificationFile: true
  path: Math/tests/sumdiv.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 04:47:02+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/sumdiv.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/sumdiv.test.cpp
- /verify/Math/tests/sumdiv.test.cpp.html
title: Math/tests/sumdiv.test.cpp
---
