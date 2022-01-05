---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/dynamic_hull.h
    title: DP/dynamic_hull.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../dynamic_hull.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin >> n >> q;\n\
    \    HullDynamic hull;\n    REP(i,n) {\n        long long a, b; cin >> a >> b;\n\
    \        hull.insert_line(-a, -b);\n    }\n    REP(i,q) {\n        int typ; cin\
    \ >> typ;\n        if (typ == 0) {\n            long long a, b; cin >> a >> b;\n\
    \            hull.insert_line(-a, -b);\n        } else {\n            long long\
    \ x; cin >> x;\n            cout << -hull.eval(x) << '\\n';\n        }\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - DP/dynamic_hull.h
  isVerificationFile: true
  path: DP/tests/dynamic_hull_lineaddgetmin.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 02:20:31+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DP/tests/dynamic_hull_lineaddgetmin.test.cpp
layout: document
redirect_from:
- /verify/DP/tests/dynamic_hull_lineaddgetmin.test.cpp
- /verify/DP/tests/dynamic_hull_lineaddgetmin.test.cpp.html
title: DP/tests/dynamic_hull_lineaddgetmin.test.cpp
---
