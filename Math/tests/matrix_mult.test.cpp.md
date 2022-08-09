---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Matrix.h
    title: Math/Matrix.h
  - icon: ':heavy_check_mark:'
    path: buffered_reader.h
    title: buffered_reader.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ buffered_reader.h: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"../../atcoder/modint.hpp\"\nusing namespace std;\n\
    using namespace atcoder;\n\n#include \"../Matrix.h\"\n#include \"../../buffered_reader.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n \
    \   int m = IO::get<int>();\n    int k = IO::get<int>();\n    Matrix<modint998244353>\
    \ a(n, m);\n    Matrix<modint998244353> b(m, k);\n    REP(i,n) REP(j,m) {\n  \
    \      int x = IO::get<int>();\n        a[i][j] = x;\n    }\n    REP(i,m) REP(j,k)\
    \ {\n        int x = IO::get<int>();\n        b[i][j] = x;\n    }\n    auto c\
    \ = a * b;\n    REP(i,n) {\n        REP(j,k) cout << c[i][j].val() << ' ';\n \
    \       cout << '\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - Math/Matrix.h
  - buffered_reader.h
  isVerificationFile: true
  path: Math/tests/matrix_mult.test.cpp
  requiredBy: []
  timestamp: '2022-08-09 14:38:08+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/matrix_mult.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/matrix_mult.test.cpp
- /verify/Math/tests/matrix_mult.test.cpp.html
title: Math/tests/matrix_mult.test.cpp
---