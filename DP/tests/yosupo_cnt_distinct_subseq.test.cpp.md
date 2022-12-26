---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Math/ModInt.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\
    \n\n#include \"../../template.h\"\n#include \"../cnt_distinct_subseq.h\"\n#include\
    \ \"../../Math/ModInt.h\"\n\nconst int MOD = 998244353;\nusing mint = ModInt<MOD>;\n\
    \nvoid solve() {\n    int n; cin >> n;\n    vector<int> a(n);\n    REP(i,n) cin\
    \ >> a[i];\n\n    cout << cnt_distinct_subsequences<int, mint> (a) << endl;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
layout: document
redirect_from:
- /verify/DP/tests/yosupo_cnt_distinct_subseq.test.cpp
- /verify/DP/tests/yosupo_cnt_distinct_subseq.test.cpp.html
title: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
---
