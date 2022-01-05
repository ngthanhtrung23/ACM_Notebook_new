---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.h
    title: Graph/dijkstra.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"bits/stdc++.h\"\nusing namespace std;\n\n#include \"../dijkstra.h\"\n\n#define\
    \ SZ(x) ((int)(x).size())\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i;\
    \ ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int\
    \ n, m, s, t; cin >> n >> m >> s >> t;\n\n    // read edges\n    vector<vector<pair<int,ll>>>\
    \ g(n);\n    while (m--) {\n        int u, v, c; cin >> u >> v >> c;\n       \
    \ g[u].push_back({v, c});\n    }\n\n    // output\n    auto [dist, path] = dijkstra(g,\
    \ s, t);\n    if (dist == INF) {\n        cout << -1 << endl;\n        return\
    \ 0;\n    }\n\n    cout << dist << ' ' << SZ(path) - 1 << '\\n';\n    REP(i,SZ(path)-1)\
    \ {\n        cout << path[i] << ' ' << path[i+1] << '\\n';\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - Graph/dijkstra.h
  isVerificationFile: true
  path: Graph/tests/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 03:02:41+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/dijkstra.test.cpp
- /verify/Graph/tests/dijkstra.test.cpp.html
title: Graph/tests/dijkstra.test.cpp
---
