---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/bigint.h
    title: Math/bigint.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/addition_of_big_integers
    links:
    - https://judge.yosupo.jp/problem/addition_of_big_integers
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/addition_of_big_integers\"\
    \n\n#include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../bigint.h\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int ntest; cin\
    \ >> ntest;\n    while (ntest--) {\n        BigInt a, b; cin >> a >> b;\n    \
    \    cout << a + b << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - Math/bigint.h
  isVerificationFile: true
  path: Math/tests/yosupo_bigint_add.test.cpp
  requiredBy: []
  timestamp: '2023-10-03 01:03:14-07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/yosupo_bigint_add.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/yosupo_bigint_add.test.cpp
- /verify/Math/tests/yosupo_bigint_add.test.cpp.html
title: Math/tests/yosupo_bigint_add.test.cpp
---
