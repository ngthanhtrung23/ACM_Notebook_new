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
    - https://codeforces.com/contest/1437/problem/C
  bundledCode: "#line 1 \"Graph/Matching/PerfectMatchingMinCost.h\"\n// Hungarian\
    \ Assignment\n// Note: \n// - Vertex indexed from #0\n// - Change INF and int\
    \ to long long (if needed) \n//\n// Usage:\n// - PerfectMatchingMinCost matching(n)\n\
    // - matching.AddEdge(u, v, cost)\n// - matching.GetMinCost()\n//\n// Tested:\n\
    // - SGU 210\n// - SGU 206\n// - https://codeforces.com/contest/1437/problem/C\n\
    // - GCJ 2021 - R2 D\n\nclass PerfectMatchingMinCost {\npublic:\n    PerfectMatchingMinCost(int\
    \ n = 0) {\n        N = n;\n        cost = VII(n, VI(n, INF));\n        adj =\
    \ VII(n);\n\n        trace = VI(n);\n        arg = VI(n);\n        fx = VI(n,\
    \ -INF);\n        fy = VI(n);\n        d = VI(n);\n        mx = VI(n, -1);\n \
    \       my = VI(n, -1);\n    }\n\n    void AddEdge(int x, int y, int c) {\n  \
    \      if (cost[x][y] == INF) adj[x].push_back(y);\n        if (cost[x][y] > c)\
    \ cost[x][y] = c;\n    }\n\n    int GetMinCost() {\n        for (int x = 0; x\
    \ < N; x++) {\n            initBFS(x);\n            int finish = -1;\n       \
    \     do {                \n                finish = findPath();\n           \
    \     if (finish != -1) break;\n                finish = update(x);\n        \
    \    } while (finish == -1);\n            enlarge(finish);\n        }\n      \
    \  int ret = 0;\n        for (int x = 0; x < N; x++) \n            ret += cost[x][mx[x]];\n\
    \        return ret;\n    }\n\nprivate:\n    typedef vector<int> VI;\n    typedef\
    \ vector<VI> VII;\n    const int INF = 1e9;\n\n    int N;\n    VII cost, adj;\n\
    \    VI d, fx, fy, mx, my, arg, trace;\n\n    queue<int> q;\n\n    int getCost(int\
    \ x, int y) {\n        return cost[x][y] - fx[x] - fy[y];\n    }\n\n    void initBFS(int\
    \ start) {\n        for (int i = 0; i < N; i++)\n            trace[i] = -1;\n\
    \        while (!q.empty()) q.pop();\n        q.push(start);\n        for (int\
    \ i = 0; i < N; i++)\n            d[i] = getCost(start, i), arg[i] = start;\n\
    \    }\n\n    int findPath() {\n        while (!q.empty()) {\n            int\
    \ x = q.front(); q.pop();\n            for (int i = 0; i < (int) adj[x].size();\
    \ i++) {\n                int y = adj[x][i];\n                if (trace[y] ==\
    \ -1) {\n                    int w = getCost(x, y);\n                    if (w\
    \ == 0) {\n                        trace[y] = x;\n                        if (my[y]\
    \ == -1) \n                            return y;\n                        q.push(my[y]);\n\
    \                    }\n                    if (d[y] > w) {\n                \
    \        d[y] = w;\n                        arg[y] = x;\n                    }\n\
    \                }\n            }\n        }\n        return -1;\n    }\n\n  \
    \  int update(int start) {\n        int delta = INF;\n        for (int y = 0;\
    \ y < N; y++)\n            if (trace[y] == -1)\n                delta = min(delta,\
    \ d[y]);   \n        fx[start] += delta;\n        for (int y = 0; y < N; y++)\n\
    \            if (trace[y] != -1) {\n                int x = my[y];\n         \
    \       fx[x] += delta;\n                fy[y] -= delta;\n            } \n   \
    \         else d[y] -= delta;\n        for (int y = 0; y < N; y++)\n         \
    \   if (trace[y] == -1 && d[y] == 0) {\n                trace[y] = arg[y];\n \
    \               if (my[y] == -1) \n                    return y;\n           \
    \     q.push(my[y]);\n            }\n        return -1;\n    }\n\n    void enlarge(int\
    \ finish) {\n        for (int y = finish; y != -1; ) {\n            int x = trace[y];\n\
    \            int yy = mx[x];\n            mx[x] = y;\n            my[y] = x;\n\
    \            y = yy;\n        }\n    }\n};\n"
  code: "// Hungarian Assignment\n// Note: \n// - Vertex indexed from #0\n// - Change\
    \ INF and int to long long (if needed) \n//\n// Usage:\n// - PerfectMatchingMinCost\
    \ matching(n)\n// - matching.AddEdge(u, v, cost)\n// - matching.GetMinCost()\n\
    //\n// Tested:\n// - SGU 210\n// - SGU 206\n// - https://codeforces.com/contest/1437/problem/C\n\
    // - GCJ 2021 - R2 D\n\nclass PerfectMatchingMinCost {\npublic:\n    PerfectMatchingMinCost(int\
    \ n = 0) {\n        N = n;\n        cost = VII(n, VI(n, INF));\n        adj =\
    \ VII(n);\n\n        trace = VI(n);\n        arg = VI(n);\n        fx = VI(n,\
    \ -INF);\n        fy = VI(n);\n        d = VI(n);\n        mx = VI(n, -1);\n \
    \       my = VI(n, -1);\n    }\n\n    void AddEdge(int x, int y, int c) {\n  \
    \      if (cost[x][y] == INF) adj[x].push_back(y);\n        if (cost[x][y] > c)\
    \ cost[x][y] = c;\n    }\n\n    int GetMinCost() {\n        for (int x = 0; x\
    \ < N; x++) {\n            initBFS(x);\n            int finish = -1;\n       \
    \     do {                \n                finish = findPath();\n           \
    \     if (finish != -1) break;\n                finish = update(x);\n        \
    \    } while (finish == -1);\n            enlarge(finish);\n        }\n      \
    \  int ret = 0;\n        for (int x = 0; x < N; x++) \n            ret += cost[x][mx[x]];\n\
    \        return ret;\n    }\n\nprivate:\n    typedef vector<int> VI;\n    typedef\
    \ vector<VI> VII;\n    const int INF = 1e9;\n\n    int N;\n    VII cost, adj;\n\
    \    VI d, fx, fy, mx, my, arg, trace;\n\n    queue<int> q;\n\n    int getCost(int\
    \ x, int y) {\n        return cost[x][y] - fx[x] - fy[y];\n    }\n\n    void initBFS(int\
    \ start) {\n        for (int i = 0; i < N; i++)\n            trace[i] = -1;\n\
    \        while (!q.empty()) q.pop();\n        q.push(start);\n        for (int\
    \ i = 0; i < N; i++)\n            d[i] = getCost(start, i), arg[i] = start;\n\
    \    }\n\n    int findPath() {\n        while (!q.empty()) {\n            int\
    \ x = q.front(); q.pop();\n            for (int i = 0; i < (int) adj[x].size();\
    \ i++) {\n                int y = adj[x][i];\n                if (trace[y] ==\
    \ -1) {\n                    int w = getCost(x, y);\n                    if (w\
    \ == 0) {\n                        trace[y] = x;\n                        if (my[y]\
    \ == -1) \n                            return y;\n                        q.push(my[y]);\n\
    \                    }\n                    if (d[y] > w) {\n                \
    \        d[y] = w;\n                        arg[y] = x;\n                    }\n\
    \                }\n            }\n        }\n        return -1;\n    }\n\n  \
    \  int update(int start) {\n        int delta = INF;\n        for (int y = 0;\
    \ y < N; y++)\n            if (trace[y] == -1)\n                delta = min(delta,\
    \ d[y]);   \n        fx[start] += delta;\n        for (int y = 0; y < N; y++)\n\
    \            if (trace[y] != -1) {\n                int x = my[y];\n         \
    \       fx[x] += delta;\n                fy[y] -= delta;\n            } \n   \
    \         else d[y] -= delta;\n        for (int y = 0; y < N; y++)\n         \
    \   if (trace[y] == -1 && d[y] == 0) {\n                trace[y] = arg[y];\n \
    \               if (my[y] == -1) \n                    return y;\n           \
    \     q.push(my[y]);\n            }\n        return -1;\n    }\n\n    void enlarge(int\
    \ finish) {\n        for (int y = finish; y != -1; ) {\n            int x = trace[y];\n\
    \            int yy = mx[x];\n            mx[x] = y;\n            my[y] = x;\n\
    \            y = yy;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Matching/PerfectMatchingMinCost.h
  requiredBy: []
  timestamp: '2021-05-16 00:43:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Matching/PerfectMatchingMinCost.h
layout: document
redirect_from:
- /library/Graph/Matching/PerfectMatchingMinCost.h
- /library/Graph/Matching/PerfectMatchingMinCost.h.html
title: Graph/Matching/PerfectMatchingMinCost.h
---
