---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentArray.h
    title: DataStructure/PersistentArray.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentDSU.h
    title: DataStructure/PersistentDSU.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../PersistentArray.h\"\
    \n#include \"../PersistentDSU.h\"\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n, q; cin >> n >> q;\n\n    PersistentDSU dsu(n);\n\n \
    \   while (q--) {\n        int typ, version; cin >> typ >> version;\n        int\
    \ u, v; cin >> u >> v;\n\n        if (typ == 0) {\n            dsu.merge(version\
    \ + 1, u, v);\n        } else {\n            // create extra version, since the\
    \ input format requires it..\n            dsu.merge(version + 1, 0, 0);\n    \
    \        cout << dsu.same_component(version + 1, u, v) << '\\n';\n        }\n\
    \    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/PersistentArray.h
  - DataStructure/PersistentDSU.h
  isVerificationFile: true
  path: DataStructure/test/persistent_dsu.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 02:48:27+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/persistent_dsu.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/persistent_dsu.test.cpp
- /verify/DataStructure/test/persistent_dsu.test.cpp.html
title: DataStructure/test/persistent_dsu.test.cpp
---
