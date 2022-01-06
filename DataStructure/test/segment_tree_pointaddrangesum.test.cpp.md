---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree.h
    title: DataStructure/SegTree.h
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
    \n#include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../SegTree.h\"\
    \n#include \"../../buffered_reader.h\"\n\n#define REP(i, a) for (int i = 0, _##i\
    \ = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, q; cin >> n >> q;\n    vector<long long> a(n);\n    for (auto& x :\
    \ a) cin >> x;\n\n    SegTree<long long, SumSegTreeOp::op, SumSegTreeOp::e> seg_tree(a);\n\
    \n    while (q--) {\n        int typ; cin >> typ;\n        if (typ == 0) {\n \
    \           int pos, val; cin >> pos >> val;\n            seg_tree.set(pos, seg_tree.get(pos)\
    \ + val);\n        } else {\n            int l, r; cin >> l >> r;\n          \
    \  cout << seg_tree.prod(l, r) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/SegTree.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 20:02:32+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/segment_tree_pointaddrangesum.test.cpp
- /verify/DataStructure/test/segment_tree_pointaddrangesum.test.cpp.html
title: DataStructure/test/segment_tree_pointaddrangesum.test.cpp
---
