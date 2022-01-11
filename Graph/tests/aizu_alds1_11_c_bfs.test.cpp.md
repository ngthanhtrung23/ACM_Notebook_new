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
  bundledCode: "#line 1 \"Graph/tests/aizu_alds1_11_c_bfs.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/bfs.h\"\n//\
    \ BFS\n// - Index from 0\n// - Directed\n// - Supports multi-source BFS\n// -\
    \ Supports reconstruct path\n//\n// Tested:\n// - https://oj.vnoi.info/problem/vmunch\n\
    // - https://oj.vnoi.info/problem/vcoldwat\n// - (trace) https://cses.fi/problemset/task/1667/\n\
    // - (multi-source) https://cses.fi/problemset/task/1193/\nstruct Graph {\n  \
    \  Graph(int _n) : n(_n), g(n) {}\n\n    void add_edge(int u, int v) {\n     \
    \   g[u].push_back(v);\n    }\n\n    // return\n    // - shortest distance from\
    \ start -> target\n    // - path\n    // If no path -> returns -1\n    pair<int,\
    \ vector<int>> bfs(int start, int target) {\n        assert(0 <= start && start\
    \ < n);\n        assert(0 <= target && target < n);\n\n        auto [dist, trace]\
    \ = _bfs({start}, target);\n        if (dist[target] < 0) {\n            return\
    \ {dist[target], {}};\n        }\n        vector<int> path;\n        for (int\
    \ u = target; u != start; u = trace[u]) {\n            path.push_back(u);\n  \
    \      }\n        path.push_back(start);\n        reverse(path.begin(), path.end());\n\
    \        return {dist[target], path};\n    }\n\n    // return: dist: vector<int>,\
    \ dist[u] = shortest distance from start -> u\n    vector<int> bfs(int start)\
    \ {\n        assert(0 <= start && start < n);\n        return _bfs({start}, -1).first;\n\
    \    }\n\n    // multi-source BFS\n    // Return: dist[u] = shortest distance\
    \ from any source -> u\n    vector<int> bfs(vector<int> starts) {\n        return\
    \ _bfs(starts, -1).first;\n    }\n\n// private:\n\n    // Start BFS from start,\
    \ and stop when reaching target.\n    // Start = -1 -> BFS whole graph\n    //\
    \ Returns {distance, trace}\n    pair<vector<int>, vector<int>> _bfs(vector<int>\
    \ starts, int target) {\n        assert(-1 <= target && target < n);\n\n     \
    \   queue<int> qu;\n        vector<int> dist(g.size(), -1);\n        vector<int>\
    \ trace(g.size(), -1);\n\n        for (int start : starts) {\n            assert(0\
    \ <= start && start < n);\n            dist[start] = 0;\n            qu.push(start);\n\
    \        }\n\n        while (!qu.empty()) {\n            auto u = qu.front();\
    \ qu.pop();\n            if (u == target) {\n                break;\n        \
    \    }\n\n            for (const auto& v : g[u]) {\n                if (dist[v]\
    \ == -1) {\n                    dist[v] = dist[u] + 1;\n                    trace[v]\
    \ = u;\n                    qu.push(v);\n                }\n            }\n  \
    \      }\n\n        return {dist, trace};\n    }\n\n    int n;\n    vector<vector<int>>\
    \ g;\n};\n#line 7 \"Graph/tests/aizu_alds1_11_c_bfs.test.cpp\"\n\n#define REP(i,\
    \ a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n; cin >> n;\n    Graph g(n);\n\n    REP(i,n) {\n     \
    \   int u, k; cin >> u >> k;\n        --u;\n        while (k--) {\n          \
    \  int v; cin >> v;\n            --v;\n            g.add_edge(u, v);\n       \
    \ }\n    }\n    auto dist = g.bfs(0);\n    REP(i,n) {\n        cout << (i+1) <<\
    \ ' ' << dist[i] << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../bfs.h\"\n\n\
    #define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint main() {\n\
    \    ios::sync_with_stdio(0); cin.tie(0);\n    int n; cin >> n;\n    Graph g(n);\n\
    \n    REP(i,n) {\n        int u, k; cin >> u >> k;\n        --u;\n        while\
    \ (k--) {\n            int v; cin >> v;\n            --v;\n            g.add_edge(u,\
    \ v);\n        }\n    }\n    auto dist = g.bfs(0);\n    REP(i,n) {\n        cout\
    \ << (i+1) << ' ' << dist[i] << '\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - Graph/bfs.h
  isVerificationFile: true
  path: Graph/tests/aizu_alds1_11_c_bfs.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 21:41:41+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/aizu_alds1_11_c_bfs.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/aizu_alds1_11_c_bfs.test.cpp
- /verify/Graph/tests/aizu_alds1_11_c_bfs.test.cpp.html
title: Graph/tests/aizu_alds1_11_c_bfs.test.cpp
---
