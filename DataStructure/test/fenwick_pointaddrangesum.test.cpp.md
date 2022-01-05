---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick.h
    title: DataStructure/Fenwick.h
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../Fenwick.h\"\
    \n#include \"../../buffered_reader.h\"\n\n#define REP(i, a) for (int i = 0, _##i\
    \ = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n = IO::get_int<int>();\n    int q = IO::get_int<int>();\n\n    Fenwick<long\
    \ long> f(n);\n    REP(i,n) {\n        int x = IO::get_int<int>();\n        f.update(i,\
    \ x);\n    }\n\n    while (q--) {\n        int typ = IO::get_int<int>();\n   \
    \     if (typ == 0) {\n            int u = IO::get_int<int>();\n            int\
    \ val = IO::get_int<int>();\n            f.update(u, val);\n        } else if\
    \ (typ == 1) {\n            int l = IO::get_int<int>();\n            int r = IO::get_int<int>();\n\
    \            cout << f.get(l, r) << '\\n';\n        } else {\n            assert(false);\n\
    \        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/Fenwick.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/fenwick_pointaddrangesum.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 23:25:36+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/fenwick_pointaddrangesum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/fenwick_pointaddrangesum.test.cpp
- /verify/DataStructure/test/fenwick_pointaddrangesum.test.cpp.html
title: DataStructure/test/fenwick_pointaddrangesum.test.cpp
---
