---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/MaxFlow/MaxFlowHLPP.h
    title: Graph/MaxFlow/MaxFlowHLPP.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/MaxFlow/MaxFlowHLPP.h\"\
    \n// Copied from https://gist.github.com/Chillee/ad2110fc17af453fb6fc3357a78cfd28\n\
    //\n// More about it in https://codeforces.com/blog/entry/66006\n//\n// Notes:\n\
    // - large arrays in struct. Do not put MaxFlow variable in main\n// - cannot\
    \ recover flow\n//\n// Tested:\n// - https://oj.vnoi.info/problem/fflow\n// -\
    \ https://www.spoj.com/problems/FASTFLOW/\n// - https://loj.ac/p/127\n\n// MaxFlow\
    \ {{{\ntemplate <int MAXN, class T = int> struct MaxFlow {\n    MaxFlow() {}\n\
    \n    const T INF = numeric_limits<T>::max();\n    struct edge {\n        int\
    \ to, rev;\n        T f;\n    };\n\n    int t = -1;\n    vector<edge> adj[MAXN];\n\
    \    vector<int> lst[MAXN], gap[MAXN];\n    T excess[MAXN];\n    int highest,\
    \ height[MAXN], cnt[MAXN], work;\n    void addEdge(int from, int to, int f, bool\
    \ isDirected = true) {\n        adj[from].push_back({to, (int)adj[to].size(),\
    \ f});\n        adj[to].push_back({from, ((int)adj[from].size()) - 1, isDirected\
    \ ? 0 : f});\n    }\n    void updHeight(int v, int nh) {\n        work++;\n  \
    \      if (height[v] != MAXN)\n            cnt[height[v]]--;\n        height[v]\
    \ = nh;\n        if (nh == MAXN)\n            return;\n        cnt[nh]++, highest\
    \ = nh;\n        gap[nh].push_back(v);\n        if (excess[v] > 0)\n         \
    \   lst[nh].push_back(v);\n    }\n    void globalRelabel() {\n        work = 0;\n\
    \        fill(height, height + MAXN, MAXN);\n        fill(cnt, cnt + MAXN, 0);\n\
    \        for (int i = 0; i < highest; i++)\n            lst[i].clear(), gap[i].clear();\n\
    \        height[t] = 0;\n        queue<int> q({t});\n        while (!q.empty())\
    \ {\n            int v = q.front();\n            q.pop();\n            for (auto\
    \ &e : adj[v])\n                if (height[e.to] == MAXN && adj[e.to][e.rev].f\
    \ > 0)\n                    q.push(e.to), updHeight(e.to, height[v] + 1);\n  \
    \          highest = height[v];\n        }\n    }\n    void push(int v, edge &e)\
    \ {\n        if (excess[e.to] == 0)\n            lst[height[e.to]].push_back(e.to);\n\
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
    \ + INF;\n    }\n};\n// }}}\n#line 7 \"Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp\"\
    \n\nMaxFlow<111, int> flow;\n\nint main() {\n    ios_base::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n, m; cin >> n >> m;\n\n    while (m--) {\n        int\
    \ u, v, c; cin >> u >> v >> c;\n        flow.addEdge(u, v, c);\n    }\n    cout\
    \ << flow.getMaxFlow(0, n-1) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../MaxFlow/MaxFlowHLPP.h\"\
    \n\nMaxFlow<111, int> flow;\n\nint main() {\n    ios_base::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n, m; cin >> n >> m;\n\n    while (m--) {\n        int\
    \ u, v, c; cin >> u >> v >> c;\n        flow.addEdge(u, v, c);\n    }\n    cout\
    \ << flow.getMaxFlow(0, n-1) << endl;\n}\n"
  dependsOn:
  - Graph/MaxFlow/MaxFlowHLPP.h
  isVerificationFile: true
  path: Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp
  requiredBy: []
  timestamp: '2023-01-07 01:46:12+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp
- /verify/Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp.html
title: Graph/tests/aizu_grl_6_a_maxflow_hlpp.test.cpp
---
