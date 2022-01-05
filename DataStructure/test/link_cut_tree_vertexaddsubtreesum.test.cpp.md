---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/LinkCutTree.h
    title: DataStructure/LinkCutTree.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
    \n\n#include \"bits/stdc++.h\"\nusing namespace std;\n\nusing T = long long;\n\
    #include \"../LinkCutTree.h\"\n\n#define FOR(i, a, b) for (int i = (a), _##i =\
    \ (b); i <= _##i; ++i)\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i;\
    \ ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\n    int\
    \ n, q; cin >> n >> q;\n    LinkCut tree(n);\n    FOR(i,1,n) {\n        int x;\
    \ cin >> x;\n        tree.set(i, x);\n    }\n    REP(i,n-1) {\n        int u,\
    \ v; cin >> u >> v;\n        ++u; ++v;\n        tree.link(u, v);\n    }\n\n  \
    \  while (q--) {\n        int typ; cin >> typ;\n        if (typ == 0) {  // delete\
    \ (u, v), add(w, x)\n            int u, v, w, x; cin >> u >> v >> w >> x;\n  \
    \          ++u; ++v;\n            ++w; ++x;\n            tree.cut(u, v);\n   \
    \         tree.link(w, x);\n        } else if (typ == 1) {  // a[p] += x\n   \
    \         int p, x; cin >> p >> x;\n            ++p;\n            tree.set(p,\
    \ tree.get(p) + x);\n        } else if (typ == 2) {  // get sum of subtree(u).\
    \ v is parent of u\n            int u, v; cin >> u >> v;\n            ++u; ++v;\n\
    \            cout << tree.getSubtree(u, v) << '\\n';\n        }\n    }\n    return\
    \ 0;\n}\n\n"
  dependsOn:
  - DataStructure/LinkCutTree.h
  isVerificationFile: true
  path: DataStructure/test/link_cut_tree_vertexaddsubtreesum.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 01:34:06+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: DataStructure/test/link_cut_tree_vertexaddsubtreesum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/link_cut_tree_vertexaddsubtreesum.test.cpp
- /verify/DataStructure/test/link_cut_tree_vertexaddsubtreesum.test.cpp.html
title: DataStructure/test/link_cut_tree_vertexaddsubtreesum.test.cpp
---
