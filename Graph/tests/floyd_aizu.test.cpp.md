---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/floyd.h
    title: Graph/floyd.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"Graph/tests/floyd_aizu.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/floyd.h\"\
    \n// Tested:\n// - https://cses.fi/problemset/task/1672/\n// - (trace) https://oj.vnoi.info/problem/floyd\n\
    using ll = long long;\nconst ll INF = 4e18;\nstruct Floyd {\n    Floyd(int _n,\
    \ const std::vector<std::vector<ll>> _c) : n(_n), c(_c), trace(n) {\n        for\
    \ (int i = 0; i < n; i++) {\n            trace[i] = std::vector<int> (n, -1);\n\
    \            for (int j = 0; j < n; j++) {\n                if (c[i][j] == INF)\
    \ trace[i][j] = -1;\n                else trace[i][j] = i;\n            }\n  \
    \      }\n\n        for (int k = 0; k < n; k++) {\n            for (int i = 0;\
    \ i < n; i++) {\n                for (int j = 0; j < n; j++) {\n             \
    \       if (c[i][j] > c[i][k] + c[k][j]) {\n                        c[i][j] =\
    \ c[i][k] + c[k][j];\n                        trace[i][j] = trace[k][j];\n   \
    \                 }\n                }\n            }\n        }\n    }\n\n  \
    \  // Return {distance, path}\n    // If no path -> returns {-1, {}}\n    std::pair<int,\
    \ std::vector<int>> get_path(int start, int target) {\n        if (trace[start][target]\
    \ == -1) return {-1, {}};\n\n        std::vector<int> path;\n        for (int\
    \ u = target; u != start; u = trace[start][u]) {\n            path.push_back(u);\n\
    \        }\n        path.push_back(start);\n        reverse(path.begin(), path.end());\n\
    \        return {c[start][target], path};\n    }\n\n    int n;\n    std::vector<std::vector<ll>>\
    \ c;\n    std::vector<std::vector<int>> trace;\n};\n\n#line 7 \"Graph/tests/floyd_aizu.test.cpp\"\
    \n\nint main() {\n    int n, m; cin >> n >> m;\n    vector<vector<ll>> c(n, vector<ll>\
    \ (n, INF));\n    for (int i = 0; i < n; i++) c[i][i] = 0;\n\n    while (m--)\
    \ {\n        int u, v; ll cost; cin >> u >> v >> cost;\n        c[u][v] = min(c[u][v],\
    \ cost);\n    }\n\n    Floyd f(n, c);\n    for (int i = 0; i < n; i++) {\n   \
    \     if (f.c[i][i] < 0) {\n            cout << \"NEGATIVE CYCLE\" << endl;\n\
    \            return 0;\n        }\n    }\n    for (int i = 0; i < n; i++) {\n\
    \        for (int j = 0; j < n; j++) {\n            if (f.c[i][j] == INF) cout\
    \ << \"INF\";\n            else cout << f.c[i][j];\n            cout << ' ';\n\
    \        }\n        cout << endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../floyd.h\"\n\
    \nint main() {\n    int n, m; cin >> n >> m;\n    vector<vector<ll>> c(n, vector<ll>\
    \ (n, INF));\n    for (int i = 0; i < n; i++) c[i][i] = 0;\n\n    while (m--)\
    \ {\n        int u, v; ll cost; cin >> u >> v >> cost;\n        c[u][v] = min(c[u][v],\
    \ cost);\n    }\n\n    Floyd f(n, c);\n    for (int i = 0; i < n; i++) {\n   \
    \     if (f.c[i][i] < 0) {\n            cout << \"NEGATIVE CYCLE\" << endl;\n\
    \            return 0;\n        }\n    }\n    for (int i = 0; i < n; i++) {\n\
    \        for (int j = 0; j < n; j++) {\n            if (f.c[i][j] == INF) cout\
    \ << \"INF\";\n            else cout << f.c[i][j];\n            cout << ' ';\n\
    \        }\n        cout << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - Graph/floyd.h
  isVerificationFile: true
  path: Graph/tests/floyd_aizu.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 23:55:11+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Graph/tests/floyd_aizu.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/floyd_aizu.test.cpp
- /verify/Graph/tests/floyd_aizu.test.cpp.html
title: Graph/tests/floyd_aizu.test.cpp
---
