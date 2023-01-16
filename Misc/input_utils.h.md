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
  bundledCode: "#line 1 \"Misc/input_utils.h\"\n/// GRAPHS, 1-based index\n// undirected\
    \ graph, N M u1 v1 u2 v2 ... {{{\nint n, m; cin >> n >> m;\nvector<vector<int>>\
    \ g(n);\nfor (int i = 0; i < m; ++i) {\n    int u, v; cin >> u >> v;\n    --u;\
    \ --v;\n    g[u].push_back(v);\n    g[v].push_back(u);\n}\n// }}}\n// directed\
    \ graph, N M u1 v1 u2 v2 ... {{{\nint n, m; cin >> n >> m;\nvector<vector<int>>\
    \ g(n);\nfor (int i = 0; i < m; ++i) {\n    int u, v; cin >> u >> v;\n    --u;\
    \ --v;\n    g[u].push_back(v);\n}\n// }}}\n// tree N u1 v1 u2 v2 ... {{{\nint\
    \ n; cin >> n;\nvector<vector<int>> g(n);\nfor (int i = 1; i < n; ++i) {\n   \
    \ int u, v; cin >> u >> v;\n    --u; --v;\n    g[u].push_back(v);\n    g[v].push_back(u);\n\
    }\n// }}}\n\n"
  code: "/// GRAPHS, 1-based index\n// undirected graph, N M u1 v1 u2 v2 ... {{{\n\
    int n, m; cin >> n >> m;\nvector<vector<int>> g(n);\nfor (int i = 0; i < m; ++i)\
    \ {\n    int u, v; cin >> u >> v;\n    --u; --v;\n    g[u].push_back(v);\n   \
    \ g[v].push_back(u);\n}\n// }}}\n// directed graph, N M u1 v1 u2 v2 ... {{{\n\
    int n, m; cin >> n >> m;\nvector<vector<int>> g(n);\nfor (int i = 0; i < m; ++i)\
    \ {\n    int u, v; cin >> u >> v;\n    --u; --v;\n    g[u].push_back(v);\n}\n\
    // }}}\n// tree N u1 v1 u2 v2 ... {{{\nint n; cin >> n;\nvector<vector<int>> g(n);\n\
    for (int i = 1; i < n; ++i) {\n    int u, v; cin >> u >> v;\n    --u; --v;\n \
    \   g[u].push_back(v);\n    g[v].push_back(u);\n}\n// }}}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/input_utils.h
  requiredBy: []
  timestamp: '2023-01-16 20:41:27+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/input_utils.h
layout: document
redirect_from:
- /library/Misc/input_utils.h
- /library/Misc/input_utils.h.html
title: Misc/input_utils.h
---
