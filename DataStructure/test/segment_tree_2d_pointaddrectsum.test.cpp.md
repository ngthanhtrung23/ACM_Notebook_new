---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree.h
    title: DataStructure/SegTree.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree2D.h
    title: DataStructure/SegTree2D.h
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ buffered_reader.h: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../buffered_reader.h\"\
    \n#include \"../SegTree2D.h\"\n\n#define REP(i, a) for (int i = 0, _##i = (a);\
    \ i < _##i; ++i)\n\ntemplate<typename T>\nstruct Query {\n    static const int\
    \ ADD = 0;\n    static const int QUERY = 1;\n\n    int typ;  // ADD or QUERY\n\
    \    int x, y;\n    int x2, y2;  // for QUERY: [x1, x2-1] * [y1, y2-1]\n\n   \
    \ T weight;\n};\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n = IO::get<int>();\n    int q = IO::get<int>();\n\n    using ll = long\
    \ long;\n    vector<Query<ll>> queries;\n    REP(i,n) {\n        int x = IO::get<int>();\n\
    \        int y = IO::get<int>();\n        ll val = IO::get<ll>();\n        queries.push_back({Query<ll>::ADD,\
    \ x, y, -1, -1, val});\n    }\n\n    REP(i,q) {\n        int typ = IO::get<int>();\n\
    \        if (typ == 0) {\n            int x = IO::get<int>();\n            int\
    \ y = IO::get<int>();\n            ll val = IO::get<ll>();\n            queries.push_back({Query<ll>::ADD,\
    \ x, y, -1, -1, val});\n        } else {\n            int x = IO::get<int>();\n\
    \            int y = IO::get<int>();\n            int x2 = IO::get<int>();\n \
    \           int y2 = IO::get<int>();\n            queries.push_back({Query<ll>::QUERY,\
    \ x, y, x2, y2, 0});\n        }\n    }\n\n    using P = pair<int,int>;\n    vector<P>\
    \ points;\n    for (auto query : queries) {\n        if (query.typ == Query<ll>::ADD)\
    \ {\n            points.push_back({query.x, query.y});\n        }\n    }\n\n \
    \   SegTree2D<ll, SumSegTreeOp::op, SumSegTreeOp::e, int> st(points);\n    for\
    \ (auto query : queries) {\n        if (query.typ == Query<ll>::ADD) {\n     \
    \       P p{query.x, query.y};\n            st.set(p, st.get(p) + query.weight);\n\
    \        } else {\n            cout << st.prod(P{query.x, query.y}, P{query.x2,\
    \ query.y2}) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - buffered_reader.h
  - DataStructure/SegTree2D.h
  - DataStructure/SegTree.h
  isVerificationFile: true
  path: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
  requiredBy: []
  timestamp: '2022-08-09 14:38:08+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
- /verify/DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp.html
title: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
---
