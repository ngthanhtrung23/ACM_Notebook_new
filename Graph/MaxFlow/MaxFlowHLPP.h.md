---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp
    title: Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/66006
    - https://gist.github.com/Chillee/ad2110fc17af453fb6fc3357a78cfd28
    - https://loj.ac/p/127
    - https://oj.vnoi.info/problem/fflow
    - https://www.spoj.com/problems/FASTFLOW/
  bundledCode: "#line 1 \"Graph/MaxFlow/MaxFlowHLPP.h\"\n// Copied from https://gist.github.com/Chillee/ad2110fc17af453fb6fc3357a78cfd28\n\
    //\n// More about it in https://codeforces.com/blog/entry/66006\n//\n// Notes:\n\
    // - large arrays in struct. Do not put MaxFlow variable in main\n// - cannot\
    \ recover flow\n//\n// Tested:\n// - https://oj.vnoi.info/problem/fflow\n// -\
    \ https://www.spoj.com/problems/FASTFLOW/\n// - https://loj.ac/p/127\n\ntemplate\
    \ <int MAXN, class T = int> struct MaxFlow {\n    MaxFlow() {}\n\n    const T\
    \ INF = numeric_limits<T>::max();\n    struct edge {\n        int to, rev;\n \
    \       T f;\n    };\n\n    int t = -1;\n    vector<edge> adj[MAXN];\n    vector<int>\
    \ lst[MAXN], gap[MAXN];\n    T excess[MAXN];\n    int highest, height[MAXN], cnt[MAXN],\
    \ work;\n    void addEdge(int from, int to, int f, bool isDirected = true) {\n\
    \        adj[from].push_back({to, (int)adj[to].size(), f});\n        adj[to].push_back({from,\
    \ ((int)adj[from].size()) - 1, isDirected ? 0 : f});\n    }\n    void updHeight(int\
    \ v, int nh) {\n        work++;\n        if (height[v] != MAXN)\n            cnt[height[v]]--;\n\
    \        height[v] = nh;\n        if (nh == MAXN)\n            return;\n     \
    \   cnt[nh]++, highest = nh;\n        gap[nh].push_back(v);\n        if (excess[v]\
    \ > 0)\n            lst[nh].push_back(v);\n    }\n    void globalRelabel() {\n\
    \        work = 0;\n        fill(height, height + MAXN, MAXN);\n        fill(cnt,\
    \ cnt + MAXN, 0);\n        for (int i = 0; i < highest; i++)\n            lst[i].clear(),\
    \ gap[i].clear();\n        height[t] = 0;\n        queue<int> q({t});\n      \
    \  while (!q.empty()) {\n            int v = q.front();\n            q.pop();\n\
    \            for (auto &e : adj[v])\n                if (height[e.to] == MAXN\
    \ && adj[e.to][e.rev].f > 0)\n                    q.push(e.to), updHeight(e.to,\
    \ height[v] + 1);\n            highest = height[v];\n        }\n    }\n    void\
    \ push(int v, edge &e) {\n        if (excess[e.to] == 0)\n            lst[height[e.to]].push_back(e.to);\n\
    \        T df = min(excess[v], e.f);\n        e.f -= df, adj[e.to][e.rev].f +=\
    \ df;\n        excess[v] -= df, excess[e.to] += df;\n    }\n    void discharge(int\
    \ v) {\n        int nh = MAXN;\n        for (auto &e : adj[v]) {\n           \
    \ if (e.f > 0) {\n                if (height[v] == height[e.to] + 1) {\n     \
    \               push(v, e);\n                    if (excess[v] <= 0)\n       \
    \                 return;\n                } else\n                    nh = min(nh,\
    \ height[e.to] + 1);\n            }\n        }\n        if (cnt[height[v]] > 1)\n\
    \            updHeight(v, nh);\n        else {\n            for (int i = height[v];\
    \ i <= highest; i++) {\n                for (auto j : gap[i])\n              \
    \      updHeight(j, MAXN);\n                gap[i].clear();\n            }\n \
    \       }\n    }\n    T getMaxFlow(int s, int _t, int heur_n = MAXN) {\n     \
    \   t = _t;\n        assert(s >= 0 && t >= 0);\n        fill(begin(excess), end(excess),\
    \ 0);\n        excess[s] = INF, excess[t] = -INF;\n        globalRelabel();\n\
    \        for (auto &e : adj[s])\n            push(s, e);\n        for (; highest\
    \ >= 0; highest--) {\n            while (!lst[highest].empty()) {\n          \
    \      int v = lst[highest].back();\n                lst[highest].pop_back();\n\
    \                discharge(v);\n                if (work > 4 * heur_n)\n     \
    \               globalRelabel();\n            }\n        }\n        return excess[t]\
    \ + INF;\n    }\n};\n"
  code: "// Copied from https://gist.github.com/Chillee/ad2110fc17af453fb6fc3357a78cfd28\n\
    //\n// More about it in https://codeforces.com/blog/entry/66006\n//\n// Notes:\n\
    // - large arrays in struct. Do not put MaxFlow variable in main\n// - cannot\
    \ recover flow\n//\n// Tested:\n// - https://oj.vnoi.info/problem/fflow\n// -\
    \ https://www.spoj.com/problems/FASTFLOW/\n// - https://loj.ac/p/127\n\ntemplate\
    \ <int MAXN, class T = int> struct MaxFlow {\n    MaxFlow() {}\n\n    const T\
    \ INF = numeric_limits<T>::max();\n    struct edge {\n        int to, rev;\n \
    \       T f;\n    };\n\n    int t = -1;\n    vector<edge> adj[MAXN];\n    vector<int>\
    \ lst[MAXN], gap[MAXN];\n    T excess[MAXN];\n    int highest, height[MAXN], cnt[MAXN],\
    \ work;\n    void addEdge(int from, int to, int f, bool isDirected = true) {\n\
    \        adj[from].push_back({to, (int)adj[to].size(), f});\n        adj[to].push_back({from,\
    \ ((int)adj[from].size()) - 1, isDirected ? 0 : f});\n    }\n    void updHeight(int\
    \ v, int nh) {\n        work++;\n        if (height[v] != MAXN)\n            cnt[height[v]]--;\n\
    \        height[v] = nh;\n        if (nh == MAXN)\n            return;\n     \
    \   cnt[nh]++, highest = nh;\n        gap[nh].push_back(v);\n        if (excess[v]\
    \ > 0)\n            lst[nh].push_back(v);\n    }\n    void globalRelabel() {\n\
    \        work = 0;\n        fill(height, height + MAXN, MAXN);\n        fill(cnt,\
    \ cnt + MAXN, 0);\n        for (int i = 0; i < highest; i++)\n            lst[i].clear(),\
    \ gap[i].clear();\n        height[t] = 0;\n        queue<int> q({t});\n      \
    \  while (!q.empty()) {\n            int v = q.front();\n            q.pop();\n\
    \            for (auto &e : adj[v])\n                if (height[e.to] == MAXN\
    \ && adj[e.to][e.rev].f > 0)\n                    q.push(e.to), updHeight(e.to,\
    \ height[v] + 1);\n            highest = height[v];\n        }\n    }\n    void\
    \ push(int v, edge &e) {\n        if (excess[e.to] == 0)\n            lst[height[e.to]].push_back(e.to);\n\
    \        T df = min(excess[v], e.f);\n        e.f -= df, adj[e.to][e.rev].f +=\
    \ df;\n        excess[v] -= df, excess[e.to] += df;\n    }\n    void discharge(int\
    \ v) {\n        int nh = MAXN;\n        for (auto &e : adj[v]) {\n           \
    \ if (e.f > 0) {\n                if (height[v] == height[e.to] + 1) {\n     \
    \               push(v, e);\n                    if (excess[v] <= 0)\n       \
    \                 return;\n                } else\n                    nh = min(nh,\
    \ height[e.to] + 1);\n            }\n        }\n        if (cnt[height[v]] > 1)\n\
    \            updHeight(v, nh);\n        else {\n            for (int i = height[v];\
    \ i <= highest; i++) {\n                for (auto j : gap[i])\n              \
    \      updHeight(j, MAXN);\n                gap[i].clear();\n            }\n \
    \       }\n    }\n    T getMaxFlow(int s, int _t, int heur_n = MAXN) {\n     \
    \   t = _t;\n        assert(s >= 0 && t >= 0);\n        fill(begin(excess), end(excess),\
    \ 0);\n        excess[s] = INF, excess[t] = -INF;\n        globalRelabel();\n\
    \        for (auto &e : adj[s])\n            push(s, e);\n        for (; highest\
    \ >= 0; highest--) {\n            while (!lst[highest].empty()) {\n          \
    \      int v = lst[highest].back();\n                lst[highest].pop_back();\n\
    \                discharge(v);\n                if (work > 4 * heur_n)\n     \
    \               globalRelabel();\n            }\n        }\n        return excess[t]\
    \ + INF;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaxFlow/MaxFlowHLPP.h
  requiredBy: []
  timestamp: '2022-01-10 00:23:15+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp
documentation_of: Graph/MaxFlow/MaxFlowHLPP.h
layout: document
redirect_from:
- /library/Graph/MaxFlow/MaxFlowHLPP.h
- /library/Graph/MaxFlow/MaxFlowHLPP.h.html
title: Graph/MaxFlow/MaxFlowHLPP.h
---
