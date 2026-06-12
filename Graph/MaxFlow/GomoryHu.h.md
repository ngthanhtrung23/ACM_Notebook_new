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
    - https://oj.vnoi.info/problem/icpc21_mn_a
    - https://oj.vnoi.info/problem/mcquery
  bundledCode: "#line 1 \"Graph/MaxFlow/GomoryHu.h\"\n// Usage:\n//   GomoryHu g(n);\n\
    //   g.addEdge(u, v, c)  // 1-direction\n//   g.calc()\n//   --> g.answer[i][j]\
    \ = min cut i-j\n//\n// Note:\n// - When i -> j is not connected, answer[i][j]\
    \ = INF\n// - Used together with MaxFlowDinic.h\n//\n// Tested:\n// - https://oj.vnoi.info/problem/mcquery\n\
    // - https://oj.vnoi.info/problem/icpc21_mn_a\n\n/*\n * Find min cut between every\
    \ pair of vertices using N max_flow call (instead of N^2)\n * Not tested with\
    \ directed graph\n * Index start from 0\n */\nstruct GomoryHu {\n    int ok[MN],\
    \ cap[MN][MN];\n    int answer[MN][MN], parent[MN];\n    int n;\n    MaxFlow flow;\n\
    \n    GomoryHu(int _n) : n(_n), flow(_n) {\n        for(int i = 0; i < n; ++i)\
    \ ok[i] = parent[i] = 0;\n        for(int i = 0; i < n; ++i)\n            for(int\
    \ j = 0; j < n; ++j)\n                cap[i][j] = 0, answer[i][j] = INF;\n   \
    \ }\n\n    void addEdge(int u, int v, int c) {\n        cap[u][v] += c;\n    }\n\
    \n    void calc() {\n        for(int i = 1; i <= n-1; ++i) {\n            flow\
    \ = MaxFlow(n);\n            REP(u,n) REP(v,n)\n                if (cap[u][v])\n\
    \                    flow.addEdge(u, v, cap[u][v]);\n\n            int f = flow.getMaxFlow(i,\
    \ parent[i]);\n\n            bfs(i);\n            for(int j = i+1; j < n; ++j)\n\
    \                if (ok[j] && parent[j]==parent[i])\n                    parent[j]=i;\n\
    \            \n            answer[i][parent[i]] = answer[parent[i]][i] = f;\n\
    \            for(int j = 0; j < i; ++j)\n                answer[i][j]=answer[j][i]=min(f,answer[parent[i]][j]);\n\
    \        }\n    }\n    void bfs(int start) {\n        memset(ok,0,sizeof ok);\n\
    \        queue<int> qu;\n        qu.push(start);\n        while (!qu.empty())\
    \ {\n            int u=qu.front(); qu.pop();\n            for(int xid = 0; xid\
    \ < (int) flow.g[u].size(); ++xid) {\n                int id = flow.g[u][xid];\n\
    \                int v = flow.e[id].b, fl = flow.e[id].flow, c = flow.e[id].cap;\n\
    \                if (!ok[v] && fl < cap) {\n                    ok[v]=1;\n   \
    \                 qu.push(v);\n                }\n            }\n        }\n \
    \   }\n};\n"
  code: "// Usage:\n//   GomoryHu g(n);\n//   g.addEdge(u, v, c)  // 1-direction\n\
    //   g.calc()\n//   --> g.answer[i][j] = min cut i-j\n//\n// Note:\n// - When\
    \ i -> j is not connected, answer[i][j] = INF\n// - Used together with MaxFlowDinic.h\n\
    //\n// Tested:\n// - https://oj.vnoi.info/problem/mcquery\n// - https://oj.vnoi.info/problem/icpc21_mn_a\n\
    \n/*\n * Find min cut between every pair of vertices using N max_flow call (instead\
    \ of N^2)\n * Not tested with directed graph\n * Index start from 0\n */\nstruct\
    \ GomoryHu {\n    int ok[MN], cap[MN][MN];\n    int answer[MN][MN], parent[MN];\n\
    \    int n;\n    MaxFlow flow;\n\n    GomoryHu(int _n) : n(_n), flow(_n) {\n \
    \       for(int i = 0; i < n; ++i) ok[i] = parent[i] = 0;\n        for(int i =\
    \ 0; i < n; ++i)\n            for(int j = 0; j < n; ++j)\n                cap[i][j]\
    \ = 0, answer[i][j] = INF;\n    }\n\n    void addEdge(int u, int v, int c) {\n\
    \        cap[u][v] += c;\n    }\n\n    void calc() {\n        for(int i = 1; i\
    \ <= n-1; ++i) {\n            flow = MaxFlow(n);\n            REP(u,n) REP(v,n)\n\
    \                if (cap[u][v])\n                    flow.addEdge(u, v, cap[u][v]);\n\
    \n            int f = flow.getMaxFlow(i, parent[i]);\n\n            bfs(i);\n\
    \            for(int j = i+1; j < n; ++j)\n                if (ok[j] && parent[j]==parent[i])\n\
    \                    parent[j]=i;\n            \n            answer[i][parent[i]]\
    \ = answer[parent[i]][i] = f;\n            for(int j = 0; j < i; ++j)\n      \
    \          answer[i][j]=answer[j][i]=min(f,answer[parent[i]][j]);\n        }\n\
    \    }\n    void bfs(int start) {\n        memset(ok,0,sizeof ok);\n        queue<int>\
    \ qu;\n        qu.push(start);\n        while (!qu.empty()) {\n            int\
    \ u=qu.front(); qu.pop();\n            for(int xid = 0; xid < (int) flow.g[u].size();\
    \ ++xid) {\n                int id = flow.g[u][xid];\n                int v =\
    \ flow.e[id].b, fl = flow.e[id].flow, c = flow.e[id].cap;\n                if\
    \ (!ok[v] && fl < cap) {\n                    ok[v]=1;\n                    qu.push(v);\n\
    \                }\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaxFlow/GomoryHu.h
  requiredBy: []
  timestamp: '2021-12-21 17:51:17+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/MaxFlow/GomoryHu.h
layout: document
redirect_from:
- /library/Graph/MaxFlow/GomoryHu.h
- /library/Graph/MaxFlow/GomoryHu.h.html
title: Graph/MaxFlow/GomoryHu.h
---
