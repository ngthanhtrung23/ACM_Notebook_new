---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/bfs.h
    title: Graph/bfs.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"Graph/tests/bfs.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/bfs.h\"\n\
    // BFS\n// Index from 0\n// Directed\n//\n// Tested:\n// - https://oj.vnoi.info/problem/vmunch\n\
    // - https://oj.vnoi.info/problem/vcoldwat\nstruct Graph {\n    Graph(int n) :\
    \ g(n) {}\n\n    void add_edge(int u, int v) {\n        g[u].push_back(v);\n \
    \   }\n\n    // return shortest distance from start -> target\n    // If no path\
    \ -> returns -1\n    int bfs(int start, int target) {\n        auto dist = _bfs(start,\
    \ target);\n        return dist[target];\n    }\n\n    // return: dist: vector<int>,\
    \ dist[u] = shortest distance from start -> u\n    vector<int> bfs(int start)\
    \ {\n        return _bfs(start, -1);\n    }\n\n// private:\n\n    // Start BFS\
    \ from start, and stop when reaching target.\n    // Returns distance\n    vector<int>\
    \ _bfs(int start, int target) {\n        queue<int> qu;\n        vector<int> dist(g.size(),\
    \ -1);\n\n        dist[start] = 0;\n        qu.push(start);\n\n        while (!qu.empty())\
    \ {\n            auto u = qu.front(); qu.pop();\n            if (u == target)\
    \ {\n                break;\n            }\n\n            for (const auto& v :\
    \ g[u]) {\n                if (dist[v] == -1) {\n                    dist[v] =\
    \ dist[u] + 1;\n                    qu.push(v);\n                }\n         \
    \   }\n        }\n\n        return dist;\n    }\n    vector<vector<int>> g;\n\
    };\n#line 7 \"Graph/tests/bfs.test.cpp\"\n\n#define REP(i, a) for (int i = 0,\
    \ _##i = (a); i < _##i; ++i)\n\nint main() {\n    int n; cin >> n;\n    Graph\
    \ g(n);\n\n    REP(i,n) {\n        int u, k; cin >> u >> k;\n        --u;\n  \
    \      while (k--) {\n            int v; cin >> v;\n            --v;\n       \
    \     g.add_edge(u, v);\n        }\n    }\n    auto dist = g.bfs(0);\n    REP(i,n)\
    \ {\n        cout << (i+1) << ' ' << dist[i] << '\\n';\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../bfs.h\"\n\n\
    #define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint main() {\n\
    \    int n; cin >> n;\n    Graph g(n);\n\n    REP(i,n) {\n        int u, k; cin\
    \ >> u >> k;\n        --u;\n        while (k--) {\n            int v; cin >> v;\n\
    \            --v;\n            g.add_edge(u, v);\n        }\n    }\n    auto dist\
    \ = g.bfs(0);\n    REP(i,n) {\n        cout << (i+1) << ' ' << dist[i] << '\\\
    n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - Graph/bfs.h
  isVerificationFile: true
  path: Graph/tests/bfs.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 15:25:59+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/bfs.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/bfs.test.cpp
- /verify/Graph/tests/bfs.test.cpp.html
title: Graph/tests/bfs.test.cpp
---