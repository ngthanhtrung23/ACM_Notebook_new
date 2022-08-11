---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ.h
    title: DataStructure/RMQ.h
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ buffered_reader.h: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../RMQ.h\"\n#include \"\
    ../../buffered_reader.h\"\n\n#define REP(i, a) for (int i = 0, _##i = (a); i <\
    \ _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n \
    \   int n, q; cin >> n >> q;\n    vector<int> a(n);\n    REP(i,n) cin >> a[i];\n\
    \n    RMQ<int, _min> st(a);\n    while (q--) {\n        int l, r; cin >> l >>\
    \ r;\n        cout << st.get(l, r) << '\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/RMQ.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/rmq.test.cpp
  requiredBy: []
  timestamp: '2022-08-11 17:15:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/rmq.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/rmq.test.cpp
- /verify/DataStructure/test/rmq.test.cpp.html
title: DataStructure/test/rmq.test.cpp
---
