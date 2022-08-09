---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ buffered_reader.h: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../HeavyLight_adamant.h\"\n#include \"../../buffered_reader.h\"\
    \n\n#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n\nint32_t\
    \ main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n\
    \    int q = IO::get<int>();\n    vector<vector<int>> adj(n);\n    FOR(i,1,n-1)\
    \ {\n        int pi = IO::get<int>();\n        adj[pi].push_back(i);\n    }\n\n\
    \    HLD hld(adj, 0);\n\n    while (q--) {\n        int u = IO::get<int>();\n\
    \        int v = IO::get<int>();\n\n        cout << hld.lca(u, v) << '\\n';\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/HeavyLight_adamant.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/hld_lca.test.cpp
  requiredBy: []
  timestamp: '2022-08-09 14:38:08+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/hld_lca.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/hld_lca.test.cpp
- /verify/DataStructure/test/hld_lca.test.cpp.html
title: DataStructure/test/hld_lca.test.cpp
---
