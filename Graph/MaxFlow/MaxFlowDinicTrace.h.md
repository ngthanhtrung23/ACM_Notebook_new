---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://open.kattis.com/problems/maxflow
  bundledCode: "#line 1 \"Graph/MaxFlow/MaxFlowDinicTrace.h\"\n// Source: e-maxx.ru\n\
    // Tested with: VOJ - NKFLOW, VOJ - MCQUERY (Gomory Hu)\n\n// Usage:\n// MaxFlow\
    \ flow(n)\n// For each edge: flow.addEdge(u, v, c, edge_id)  // edge_id for trace\n\
    // flow.getMaxFlow(s, t)\n// flow.trace() --> edges in minimum cut\n// Index from\
    \ 0\n\n// Tested:\n// - https://open.kattis.com/problems/maxflow\n// - GCJ 2021\
    \ R3 - B\nconst int INF = 1000111000111000111LL;\n \nstruct Edge {\n    int a,\
    \ b, cap, flow, id;\n};\n\nstruct MaxFlow {\n    int n, s, t;\n    vector<int>\
    \ d, ptr, q;\n    vector< Edge > e;\n    vector< vector<int> > g;\n\n    MaxFlow(int\
    \ _n) : n(_n), d(_n), ptr(_n), q(_n), g(_n) {\n        e.clear();\n        REP(i,n)\
    \ {\n            g[i].clear();\n            ptr[i] = 0;\n        }\n    }\n\n\
    \    void addEdge(int a, int b, int cap, int id) { // one-direction\n        Edge\
    \ e1 = { a, b, cap, 0, id };\n        Edge e2 = { b, a, 0, 0, id };\n        g[a].push_back(\
    \ (int) e.size() );\n        e.push_back(e1);\n        g[b].push_back( (int) e.size()\
    \ );\n        e.push_back(e2);\n    }\n    int getMaxFlow(int _s, int _t) {\n\
    \        s = _s; t = _t;\n        int flow = 0;\n        for (;;) {\n        \
    \    if (!bfs()) break;\n            REP(i,n) ptr[i] = 0;\n            while (int\
    \ pushed = dfs(s, INF))\n                flow += pushed;\n        }\n        return\
    \ flow;\n    }\n\n    vector<int> trace() {\n        bfs();\n        vector<int>\
    \ res;\n        for(auto edge : e) {\n            if (d[edge.a] >= 0 && d[edge.b]\
    \ < 0 && edge.cap > 0) {\n                res.push_back(edge.id);\n          \
    \  }\n        }\n        return res;\n    }\n\nprivate:\n    bool bfs() {\n  \
    \      int qh = 0, qt = 0;\n        q[qt++] = s;\n        REP(i,n) d[i] = -1;\n\
    \        d[s] = 0;\n\n        while (qh < qt && d[t] == -1) {\n            int\
    \ v = q[qh++];\n            REP(i,g[v].size()) {\n                int id = g[v][i],\
    \ to = e[id].b;\n                if (d[to] == -1 && e[id].flow < e[id].cap) {\n\
    \                    q[qt++] = to;\n                    d[to] = d[v] + 1;\n  \
    \              }\n            }\n        }\n        return d[t] != -1;\n    }\n\
    \n    int dfs (int v, int flow) {\n        if (!flow) return 0;\n        if (v\
    \ == t) return flow;\n        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {\n\
    \            int id = g[v][ptr[v]],\n                to = e[id].b;\n         \
    \   if (d[to] != d[v] + 1) continue;\n            int pushed = dfs(to, min(flow,\
    \ e[id].cap - e[id].flow));\n            if (pushed) {\n                e[id].flow\
    \ += pushed;\n                e[id^1].flow -= pushed;\n                return\
    \ pushed;\n            }\n        }\n        return 0;\n    }\n};\n\n"
  code: "// Source: e-maxx.ru\n// Tested with: VOJ - NKFLOW, VOJ - MCQUERY (Gomory\
    \ Hu)\n\n// Usage:\n// MaxFlow flow(n)\n// For each edge: flow.addEdge(u, v, c,\
    \ edge_id)  // edge_id for trace\n// flow.getMaxFlow(s, t)\n// flow.trace() -->\
    \ edges in minimum cut\n// Index from 0\n\n// Tested:\n// - https://open.kattis.com/problems/maxflow\n\
    // - GCJ 2021 R3 - B\nconst int INF = 1000111000111000111LL;\n \nstruct Edge {\n\
    \    int a, b, cap, flow, id;\n};\n\nstruct MaxFlow {\n    int n, s, t;\n    vector<int>\
    \ d, ptr, q;\n    vector< Edge > e;\n    vector< vector<int> > g;\n\n    MaxFlow(int\
    \ _n) : n(_n), d(_n), ptr(_n), q(_n), g(_n) {\n        e.clear();\n        REP(i,n)\
    \ {\n            g[i].clear();\n            ptr[i] = 0;\n        }\n    }\n\n\
    \    void addEdge(int a, int b, int cap, int id) { // one-direction\n        Edge\
    \ e1 = { a, b, cap, 0, id };\n        Edge e2 = { b, a, 0, 0, id };\n        g[a].push_back(\
    \ (int) e.size() );\n        e.push_back(e1);\n        g[b].push_back( (int) e.size()\
    \ );\n        e.push_back(e2);\n    }\n    int getMaxFlow(int _s, int _t) {\n\
    \        s = _s; t = _t;\n        int flow = 0;\n        for (;;) {\n        \
    \    if (!bfs()) break;\n            REP(i,n) ptr[i] = 0;\n            while (int\
    \ pushed = dfs(s, INF))\n                flow += pushed;\n        }\n        return\
    \ flow;\n    }\n\n    vector<int> trace() {\n        bfs();\n        vector<int>\
    \ res;\n        for(auto edge : e) {\n            if (d[edge.a] >= 0 && d[edge.b]\
    \ < 0 && edge.cap > 0) {\n                res.push_back(edge.id);\n          \
    \  }\n        }\n        return res;\n    }\n\nprivate:\n    bool bfs() {\n  \
    \      int qh = 0, qt = 0;\n        q[qt++] = s;\n        REP(i,n) d[i] = -1;\n\
    \        d[s] = 0;\n\n        while (qh < qt && d[t] == -1) {\n            int\
    \ v = q[qh++];\n            REP(i,g[v].size()) {\n                int id = g[v][i],\
    \ to = e[id].b;\n                if (d[to] == -1 && e[id].flow < e[id].cap) {\n\
    \                    q[qt++] = to;\n                    d[to] = d[v] + 1;\n  \
    \              }\n            }\n        }\n        return d[t] != -1;\n    }\n\
    \n    int dfs (int v, int flow) {\n        if (!flow) return 0;\n        if (v\
    \ == t) return flow;\n        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {\n\
    \            int id = g[v][ptr[v]],\n                to = e[id].b;\n         \
    \   if (d[to] != d[v] + 1) continue;\n            int pushed = dfs(to, min(flow,\
    \ e[id].cap - e[id].flow));\n            if (pushed) {\n                e[id].flow\
    \ += pushed;\n                e[id^1].flow -= pushed;\n                return\
    \ pushed;\n            }\n        }\n        return 0;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaxFlow/MaxFlowDinicTrace.h
  requiredBy: []
  timestamp: '2022-01-08 03:48:10+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/MaxFlow/MaxFlowDinicTrace.h
layout: document
redirect_from:
- /library/Graph/MaxFlow/MaxFlowDinicTrace.h
- /library/Graph/MaxFlow/MaxFlowDinicTrace.h.html
title: Graph/MaxFlow/MaxFlowDinicTrace.h
---
