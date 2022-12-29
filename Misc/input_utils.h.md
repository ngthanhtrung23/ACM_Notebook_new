---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Misc/input_utils.h\"\n// read undirected graph, N M u1 v1\
    \ u2 v2 ... {{{\nint n, m; cin >> n >> m;\nvector<vector<int>> g(n);\nfor (int\
    \ i = 0; i < m; ++i) {\n    int u, v; cin >> u >> v;\n    --u; --v;\n    g[u].push_back(v);\n\
    \    g[v].push_back(u);\n}\n// }}}\n"
  code: "// read undirected graph, N M u1 v1 u2 v2 ... {{{\nint n, m; cin >> n >>\
    \ m;\nvector<vector<int>> g(n);\nfor (int i = 0; i < m; ++i) {\n    int u, v;\
    \ cin >> u >> v;\n    --u; --v;\n    g[u].push_back(v);\n    g[v].push_back(u);\n\
    }\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/input_utils.h
  requiredBy: []
  timestamp: '2022-12-29 17:34:35+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/input_utils.h
layout: document
redirect_from:
- /library/Misc/input_utils.h
- /library/Misc/input_utils.h.html
title: Misc/input_utils.h
---
