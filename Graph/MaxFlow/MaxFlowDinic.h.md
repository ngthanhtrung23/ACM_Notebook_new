---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/maxflow_dinic.test.cpp
    title: Graph/tests/maxflow_dinic.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://oj.vnoi.info/problem/fflow
    - https://open.kattis.com/problems/maxflow
    - https://www.lydsy.com/JudgeOnline/problem.php?id=1001
  bundledCode: "#line 1 \"Graph/MaxFlow/MaxFlowDinic.h\"\n// Source: e-maxx.ru\n//\
    \ Tested with: VOJ - NKFLOW, VOJ - MCQUERY (Gomory Hu)\n\n// Usage:\n// MaxFlow\
    \ flow(n)\n// For each edge: flow.addEdge(u, v, c)\n// Index from 0\n\n// Tested:\n\
    // - https://open.kattis.com/problems/maxflow\n// - https://www.lydsy.com/JudgeOnline/problem.php?id=1001\n\
    // - TLE on https://oj.vnoi.info/problem/fflow\nconst int INF = 1000000000;\n\
    \ \nstruct Edge {\n    int a, b, cap, flow;\n};\n\nstruct MaxFlow {\n    int n,\
    \ s, t;\n    vector<int> d, ptr, q;\n    vector< Edge > e;\n    vector< vector<int>\
    \ > g;\n\n    MaxFlow(int _n) : n(_n), d(_n), ptr(_n), q(_n), g(_n) {\n      \
    \  e.clear();\n        for (int i = 0; i < n; i++) {\n            g[i].clear();\n\
    \            ptr[i] = 0;\n        }\n    }\n\n    void addEdge(int a, int b, int\
    \ cap) {\n        Edge e1 = { a, b, cap, 0 };\n        Edge e2 = { b, a, 0, 0\
    \ };\n        g[a].push_back( (int) e.size() );\n        e.push_back(e1);\n  \
    \      g[b].push_back( (int) e.size() );\n        e.push_back(e2);\n    }\n  \
    \  int getMaxFlow(int _s, int _t) {\n        s = _s; t = _t;\n        int flow\
    \ = 0;\n        for (;;) {\n            if (!bfs()) break;\n            std::fill(ptr.begin(),\
    \ ptr.end(), 0);\n            while (int pushed = dfs(s, INF))\n             \
    \   flow += pushed;\n        }\n        return flow;\n    }\n\nprivate:\n    bool\
    \ bfs() {\n        int qh = 0, qt = 0;\n        q[qt++] = s;\n        std::fill(d.begin(),\
    \ d.end(), -1);\n        d[s] = 0;\n\n        while (qh < qt && d[t] == -1) {\n\
    \            int v = q[qh++];\n            for (int i = 0; i < (int) g[v].size();\
    \ i++) {\n                int id = g[v][i], to = e[id].b;\n                if\
    \ (d[to] == -1 && e[id].flow < e[id].cap) {\n                    q[qt++] = to;\n\
    \                    d[to] = d[v] + 1;\n                }\n            }\n   \
    \     }\n        return d[t] != -1;\n    }\n\n    int dfs (int v, int flow) {\n\
    \        if (!flow) return 0;\n        if (v == t) return flow;\n        for (;\
    \ ptr[v] < (int)g[v].size(); ++ptr[v]) {\n            int id = g[v][ptr[v]],\n\
    \                to = e[id].b;\n            if (d[to] != d[v] + 1) continue;\n\
    \            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));\n      \
    \      if (pushed) {\n                e[id].flow += pushed;\n                e[id^1].flow\
    \ -= pushed;\n                return pushed;\n            }\n        }\n     \
    \   return 0;\n    }\n};\n"
  code: "// Source: e-maxx.ru\n// Tested with: VOJ - NKFLOW, VOJ - MCQUERY (Gomory\
    \ Hu)\n\n// Usage:\n// MaxFlow flow(n)\n// For each edge: flow.addEdge(u, v, c)\n\
    // Index from 0\n\n// Tested:\n// - https://open.kattis.com/problems/maxflow\n\
    // - https://www.lydsy.com/JudgeOnline/problem.php?id=1001\n// - TLE on https://oj.vnoi.info/problem/fflow\n\
    const int INF = 1000000000;\n \nstruct Edge {\n    int a, b, cap, flow;\n};\n\n\
    struct MaxFlow {\n    int n, s, t;\n    vector<int> d, ptr, q;\n    vector< Edge\
    \ > e;\n    vector< vector<int> > g;\n\n    MaxFlow(int _n) : n(_n), d(_n), ptr(_n),\
    \ q(_n), g(_n) {\n        e.clear();\n        for (int i = 0; i < n; i++) {\n\
    \            g[i].clear();\n            ptr[i] = 0;\n        }\n    }\n\n    void\
    \ addEdge(int a, int b, int cap) {\n        Edge e1 = { a, b, cap, 0 };\n    \
    \    Edge e2 = { b, a, 0, 0 };\n        g[a].push_back( (int) e.size() );\n  \
    \      e.push_back(e1);\n        g[b].push_back( (int) e.size() );\n        e.push_back(e2);\n\
    \    }\n    int getMaxFlow(int _s, int _t) {\n        s = _s; t = _t;\n      \
    \  int flow = 0;\n        for (;;) {\n            if (!bfs()) break;\n       \
    \     std::fill(ptr.begin(), ptr.end(), 0);\n            while (int pushed = dfs(s,\
    \ INF))\n                flow += pushed;\n        }\n        return flow;\n  \
    \  }\n\nprivate:\n    bool bfs() {\n        int qh = 0, qt = 0;\n        q[qt++]\
    \ = s;\n        std::fill(d.begin(), d.end(), -1);\n        d[s] = 0;\n\n    \
    \    while (qh < qt && d[t] == -1) {\n            int v = q[qh++];\n         \
    \   for (int i = 0; i < (int) g[v].size(); i++) {\n                int id = g[v][i],\
    \ to = e[id].b;\n                if (d[to] == -1 && e[id].flow < e[id].cap) {\n\
    \                    q[qt++] = to;\n                    d[to] = d[v] + 1;\n  \
    \              }\n            }\n        }\n        return d[t] != -1;\n    }\n\
    \n    int dfs (int v, int flow) {\n        if (!flow) return 0;\n        if (v\
    \ == t) return flow;\n        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {\n\
    \            int id = g[v][ptr[v]],\n                to = e[id].b;\n         \
    \   if (d[to] != d[v] + 1) continue;\n            int pushed = dfs(to, min(flow,\
    \ e[id].cap - e[id].flow));\n            if (pushed) {\n                e[id].flow\
    \ += pushed;\n                e[id^1].flow -= pushed;\n                return\
    \ pushed;\n            }\n        }\n        return 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaxFlow/MaxFlowDinic.h
  requiredBy: []
  timestamp: '2022-01-10 00:23:15+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/maxflow_dinic.test.cpp
documentation_of: Graph/MaxFlow/MaxFlowDinic.h
layout: document
redirect_from:
- /library/Graph/MaxFlow/MaxFlowDinic.h
- /library/Graph/MaxFlow/MaxFlowDinic.h.html
title: Graph/MaxFlow/MaxFlowDinic.h
---
