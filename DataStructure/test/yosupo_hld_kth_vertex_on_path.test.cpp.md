---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/HeavyLight_adamant.h
    title: DataStructure/HeavyLight_adamant.h
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
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ buffered_reader.h: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../HeavyLight_adamant.h\"\
    \n#include \"../../buffered_reader.h\"\n\n#define FOR(i, a, b) for (int i = (a),\
    \ _##i = (b); i <= _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n = IO::get<int>();\n    int q = IO::get<int>();\n    vector<vector<int>>\
    \ adj(n);\n    for (int i = 0; i < n-1; ++i) {\n        int u = IO::get<int>();\n\
    \        int v = IO::get<int>();\n        adj[u].push_back(v);\n        adj[v].push_back(u);\n\
    \    }\n\n    HLD hld(adj, 0);\n\n    while (q--) {\n        int u = IO::get<int>();\n\
    \        int v = IO::get<int>();\n        int k = IO::get<int>();\n        cout\
    \ << hld.kth_vertex_on_path(u, v, k) << '\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/HeavyLight_adamant.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/yosupo_hld_kth_vertex_on_path.test.cpp
  requiredBy: []
  timestamp: '2022-08-14 04:11:09+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/yosupo_hld_kth_vertex_on_path.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/yosupo_hld_kth_vertex_on_path.test.cpp
- /verify/DataStructure/test/yosupo_hld_kth_vertex_on_path.test.cpp.html
title: DataStructure/test/yosupo_hld_kth_vertex_on_path.test.cpp
---
