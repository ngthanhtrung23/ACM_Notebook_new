---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick2D.h
    title: DataStructure/Fenwick2D.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../Fenwick2D.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin >> n >> q;\n\n\
    \    vector<Query<long long>> queries;\n    REP(i,n) {\n        int x, y, val;\
    \ cin >> x >> y >> val;\n        queries.push_back({Query<long long>::ADD, x,\
    \ y, -1, -1, val});\n    }\n\n    REP(i,q) {\n        int typ; cin >> typ;\n \
    \       if (typ == 0) {\n            int x, y, val; cin >> x >> y >> val;\n  \
    \          queries.push_back({Query<long long>::ADD, x, y, -1, -1, val});\n  \
    \      } else {\n            int x, y, x2, y2; cin >> x >> y >> x2 >> y2;\n  \
    \          queries.push_back({Query<long long>::QUERY, x, y, x2, y2, 0});\n  \
    \      }\n    }\n\n    Fenwick2D<long long> f;\n    auto res = f.solve(queries);\n\
    \    for (auto r : res) cout << r << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/Fenwick2D.h
  isVerificationFile: true
  path: DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 03:05:50+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
- /verify/DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp.html
title: DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
---
