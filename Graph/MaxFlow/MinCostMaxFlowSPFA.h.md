---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Graph/tests/aizu_grl_6_b_mincost_maxflow_spfa.test.cpp
    title: Graph/tests/aizu_grl_6_b_mincost_maxflow_spfa.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - http://codeforces.com/gym/100213
    - http://codeforces.com/gym/100216
    - http://codeforces.com/gym/100222
    - http://www.infoarena.ro/problema/fmcm
    - https://codeforces.com/blog/entry/70740
    - https://codeforces.com/contest/277/problem/E
    - https://open.kattis.com/problems/mincostmaxflow
  bundledCode: "#line 1 \"Graph/MaxFlow/MinCostMaxFlowSPFA.h\"\n// Min Cost Max Flow\
    \ - SPFA\n// Index from 0\n// edges cap changed during find flow\n// Lots of double\
    \ comparison --> likely to fail for double\n// Example:\n// MinCostFlow mcf(n);\n\
    // mcf.addEdge(u, v, cap, cost);\n// cout << mcf.minCostFlow() << endl;\n// Tested:\n\
    // - ***TLE*** https://codeforces.com/blog/entry/70740\n// - ***TLE*** http://www.infoarena.ro/problema/fmcm\n\
    // - https://open.kattis.com/problems/mincostmaxflow\n// - http://codeforces.com/gym/100213\
    \ - A\n// - http://codeforces.com/gym/100216 - A\n// - http://codeforces.com/gym/100222\
    \ - D\n// - ACM Regional Daejeon 2014 - L (negative weights)\n// - https://codeforces.com/contest/277/problem/E\n\
    \ntemplate<class Flow=int, class Cost=int>\nstruct MinCostFlow {\n    const Flow\
    \ INF_FLOW = 1000111000;\n    const Cost INF_COST = 1000111000111000LL;\n\n  \
    \  int n, t, S, T;\n    Flow totalFlow;\n    Cost totalCost;\n    vector<int>\
    \ last, visited;\n    vector<Cost> dis;\n    struct Edge {\n        int to;\n\
    \        Flow cap;\n        Cost cost;\n        int next;\n        Edge(int _to,\
    \ Flow _cap, Cost _cost, int _next) :\n                to(_to), cap(_cap), cost(_cost),\
    \ next(_next) {}\n    };\n    vector<Edge> edges;\n\n    MinCostFlow(int _n) :\
    \ n(_n), t(0), totalFlow(0), totalCost(0), last(n, -1), visited(n, 0), dis(n,\
    \ 0) {\n        edges.clear();\n    }\n\n    int addEdge(int from, int to, Flow\
    \ cap, Cost cost) {\n        edges.push_back(Edge(to, cap, cost, last[from]));\n\
    \        last[from] = t++;\n        edges.push_back(Edge(from, 0, -cost, last[to]));\n\
    \        last[to] = t++;\n        return t - 2;\n    }\n\n    pair<Flow, Cost>\
    \ minCostFlow(int _S, int _T) {\n        S = _S; T = _T;\n        SPFA();\n  \
    \      while (1) {\n            while (1) {\n                std::fill(visited.begin(),\
    \ visited.end(), 0);\n                if (!findFlow(S, INF_FLOW)) break;\n   \
    \         }\n            if (!modifyLabel()) break;\n        }\n        return\
    \ make_pair(totalFlow, totalCost);\n    }\n\nprivate:\n    void SPFA() {\n   \
    \     std::fill(dis.begin(), dis.end(), INF_COST);\n        priority_queue< pair<Cost,int>\
    \ > Q;\n        Q.push(make_pair(dis[S]=0, S));\n        while (!Q.empty()) {\n\
    \            int x = Q.top().second;\n            Cost d = -Q.top().first;\n \
    \           Q.pop();\n            // For double: dis[x] > d + EPS\n          \
    \  if (dis[x] != d) continue;\n            for(int it = last[x]; it >= 0; it =\
    \ edges[it].next)\n                if (edges[it].cap > 0 && dis[edges[it].to]\
    \ > d + edges[it].cost)\n                    Q.push(make_pair(-(dis[edges[it].to]\
    \ = d + edges[it].cost), edges[it].to));\n        }\n        Cost disT = dis[T];\n\
    \        for (int i = 0; i < n; i++) {\n            dis[i] = disT - dis[i];\n\
    \        }\n    }\n\n    Flow findFlow(int x, Flow flow) {\n        if (x == T)\
    \ {\n            totalCost += dis[S] * flow;\n            totalFlow += flow;\n\
    \            return flow;\n        }\n        visited[x] = 1;\n        Flow now\
    \ = flow;\n        for(int it = last[x]; it >= 0; it = edges[it].next)\n     \
    \       // For double: fabs(dis[edges[it].to] + edges[it].cost - dis[x]) < EPS\n\
    \            if (edges[it].cap && !visited[edges[it].to] && dis[edges[it].to]\
    \ + edges[it].cost == dis[x]) {\n                Flow tmp = findFlow(edges[it].to,\
    \ min(now, edges[it].cap));\n                edges[it].cap -= tmp;\n         \
    \       edges[it ^ 1].cap += tmp;\n                now -= tmp;\n             \
    \   if (!now) break;\n            }\n        return flow - now;\n    }\n\n   \
    \ bool modifyLabel() {\n        Cost d = INF_COST;\n        for (int i = 0; i\
    \ < n; i++) if (visited[i])\n            for(int it = last[i]; it >= 0; it = edges[it].next)\n\
    \                if (edges[it].cap && !visited[edges[it].to])\n              \
    \      d = min(d, dis[edges[it].to] + edges[it].cost - dis[i]);\n\n        //\
    \ For double: if (d > INF_COST / 10)     INF_COST = 1e20\n        if (d == INF_COST)\
    \ return false;\n        for (int i = 0; i < n; i++) if (visited[i])\n       \
    \     dis[i] += d;\n        return true;\n    }\n};\n\n"
  code: "// Min Cost Max Flow - SPFA\n// Index from 0\n// edges cap changed during\
    \ find flow\n// Lots of double comparison --> likely to fail for double\n// Example:\n\
    // MinCostFlow mcf(n);\n// mcf.addEdge(u, v, cap, cost);\n// cout << mcf.minCostFlow()\
    \ << endl;\n// Tested:\n// - ***TLE*** https://codeforces.com/blog/entry/70740\n\
    // - ***TLE*** http://www.infoarena.ro/problema/fmcm\n// - https://open.kattis.com/problems/mincostmaxflow\n\
    // - http://codeforces.com/gym/100213 - A\n// - http://codeforces.com/gym/100216\
    \ - A\n// - http://codeforces.com/gym/100222 - D\n// - ACM Regional Daejeon 2014\
    \ - L (negative weights)\n// - https://codeforces.com/contest/277/problem/E\n\n\
    template<class Flow=int, class Cost=int>\nstruct MinCostFlow {\n    const Flow\
    \ INF_FLOW = 1000111000;\n    const Cost INF_COST = 1000111000111000LL;\n\n  \
    \  int n, t, S, T;\n    Flow totalFlow;\n    Cost totalCost;\n    vector<int>\
    \ last, visited;\n    vector<Cost> dis;\n    struct Edge {\n        int to;\n\
    \        Flow cap;\n        Cost cost;\n        int next;\n        Edge(int _to,\
    \ Flow _cap, Cost _cost, int _next) :\n                to(_to), cap(_cap), cost(_cost),\
    \ next(_next) {}\n    };\n    vector<Edge> edges;\n\n    MinCostFlow(int _n) :\
    \ n(_n), t(0), totalFlow(0), totalCost(0), last(n, -1), visited(n, 0), dis(n,\
    \ 0) {\n        edges.clear();\n    }\n\n    int addEdge(int from, int to, Flow\
    \ cap, Cost cost) {\n        edges.push_back(Edge(to, cap, cost, last[from]));\n\
    \        last[from] = t++;\n        edges.push_back(Edge(from, 0, -cost, last[to]));\n\
    \        last[to] = t++;\n        return t - 2;\n    }\n\n    pair<Flow, Cost>\
    \ minCostFlow(int _S, int _T) {\n        S = _S; T = _T;\n        SPFA();\n  \
    \      while (1) {\n            while (1) {\n                std::fill(visited.begin(),\
    \ visited.end(), 0);\n                if (!findFlow(S, INF_FLOW)) break;\n   \
    \         }\n            if (!modifyLabel()) break;\n        }\n        return\
    \ make_pair(totalFlow, totalCost);\n    }\n\nprivate:\n    void SPFA() {\n   \
    \     std::fill(dis.begin(), dis.end(), INF_COST);\n        priority_queue< pair<Cost,int>\
    \ > Q;\n        Q.push(make_pair(dis[S]=0, S));\n        while (!Q.empty()) {\n\
    \            int x = Q.top().second;\n            Cost d = -Q.top().first;\n \
    \           Q.pop();\n            // For double: dis[x] > d + EPS\n          \
    \  if (dis[x] != d) continue;\n            for(int it = last[x]; it >= 0; it =\
    \ edges[it].next)\n                if (edges[it].cap > 0 && dis[edges[it].to]\
    \ > d + edges[it].cost)\n                    Q.push(make_pair(-(dis[edges[it].to]\
    \ = d + edges[it].cost), edges[it].to));\n        }\n        Cost disT = dis[T];\n\
    \        for (int i = 0; i < n; i++) {\n            dis[i] = disT - dis[i];\n\
    \        }\n    }\n\n    Flow findFlow(int x, Flow flow) {\n        if (x == T)\
    \ {\n            totalCost += dis[S] * flow;\n            totalFlow += flow;\n\
    \            return flow;\n        }\n        visited[x] = 1;\n        Flow now\
    \ = flow;\n        for(int it = last[x]; it >= 0; it = edges[it].next)\n     \
    \       // For double: fabs(dis[edges[it].to] + edges[it].cost - dis[x]) < EPS\n\
    \            if (edges[it].cap && !visited[edges[it].to] && dis[edges[it].to]\
    \ + edges[it].cost == dis[x]) {\n                Flow tmp = findFlow(edges[it].to,\
    \ min(now, edges[it].cap));\n                edges[it].cap -= tmp;\n         \
    \       edges[it ^ 1].cap += tmp;\n                now -= tmp;\n             \
    \   if (!now) break;\n            }\n        return flow - now;\n    }\n\n   \
    \ bool modifyLabel() {\n        Cost d = INF_COST;\n        for (int i = 0; i\
    \ < n; i++) if (visited[i])\n            for(int it = last[i]; it >= 0; it = edges[it].next)\n\
    \                if (edges[it].cap && !visited[edges[it].to])\n              \
    \      d = min(d, dis[edges[it].to] + edges[it].cost - dis[i]);\n\n        //\
    \ For double: if (d > INF_COST / 10)     INF_COST = 1e20\n        if (d == INF_COST)\
    \ return false;\n        for (int i = 0; i < n; i++) if (visited[i])\n       \
    \     dis[i] += d;\n        return true;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaxFlow/MinCostMaxFlowSPFA.h
  requiredBy: []
  timestamp: '2022-01-10 00:42:12+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Graph/tests/aizu_grl_6_b_mincost_maxflow_spfa.test.cpp
documentation_of: Graph/MaxFlow/MinCostMaxFlowSPFA.h
layout: document
redirect_from:
- /library/Graph/MaxFlow/MinCostMaxFlowSPFA.h
- /library/Graph/MaxFlow/MinCostMaxFlowSPFA.h.html
title: Graph/MaxFlow/MinCostMaxFlowSPFA.h
---
