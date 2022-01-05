---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/WaveletMatrix.h
    title: DataStructure/WaveletMatrix.h
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../WaveletMatrix.h\"\
    \n#include \"../../buffered_reader.h\"\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n, q; cin >> n >> q;\n    vector<int> a(n);\n    for (int&\
    \ x : a) cin >> x;\n\n    WaveletMatrix wm(a);\n    while (q--) {\n        int\
    \ l, r, k; cin >> l >> r >> k;\n        cout << wm.k_th(l, r, k) << '\\n';\n \
    \   }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/WaveletMatrix.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/wavelet_matrix_rangekthsmallest.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 00:00:20+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/wavelet_matrix_rangekthsmallest.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/wavelet_matrix_rangekthsmallest.test.cpp
- /verify/DataStructure/test/wavelet_matrix_rangekthsmallest.test.cpp.html
title: DataStructure/test/wavelet_matrix_rangekthsmallest.test.cpp
---
