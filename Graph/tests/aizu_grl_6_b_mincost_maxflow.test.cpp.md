---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/MaxFlow/MinCostMaxFlowPR.h
    title: Graph/MaxFlow/MinCostMaxFlowPR.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"Graph/tests/aizu_grl_6_b_mincost_maxflow.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Graph/MaxFlow/MinCostMaxFlowPR.h\"\
    \n// Source: https://github.com/dacin21/dacin21_codebook/blob/master/flow/mincost_PRonly.cpp\n\
    //\n// Notes:\n// - Index from 0\n// - Costs multiplied by N --> overflow when\
    \ big cost?\n// - Does not work with floating point..\n// - DO NOT USE Edge.f\
    \ DIRECTLY. Call getFlow(e)\n//\n// Tested:\n// - https://www.infoarena.ro/problema/fmcm\n\
    // - https://open.kattis.com/problems/mincostmaxflow\n// - https://codeforces.com/blog/entry/70740\n\
    // - (trace) http://vn.spoj.com/problems/MINCOST\n// - (trace) https://cses.fi/problemset/task/2131/\n\
    \ntemplate<typename flow_t = int, typename cost_t = int>\nstruct MinCostFlow {\n\
    \    struct Edge {\n        cost_t c;\n        flow_t f;  // DO NOT USE THIS DIRECTLY.\
    \ SEE getFlow(Edge const& e)\n        int to, rev;\n        Edge(int _to, cost_t\
    \ _c, flow_t _f, int _rev) : c(_c), f(_f), to(_to), rev(_rev) {}\n    };\n\n \
    \   int N, S, T;\n    vector<vector<Edge> > G;\n    MinCostFlow(int _N, int _S,\
    \ int _T) : N(_N), S(_S), T(_T), G(_N), eps(0) {}\n\n    void addEdge(int a, int\
    \ b, flow_t cap, cost_t cost) {\n\tassert(cap >= 0);\n        assert(a >= 0 &&\
    \ a < N && b >= 0 && b < N);\n        if (a == b) { assert(cost >= 0); return;\
    \ }\n        cost *= N;\n        eps = max(eps, abs(cost));\n        G[a].emplace_back(b,\
    \ cost, cap, G[b].size());\n        G[b].emplace_back(a, -cost, 0, G[a].size()\
    \ - 1);\n    }\n\n    flow_t getFlow(Edge const &e) {\n        return G[e.to][e.rev].f;\n\
    \    }\n\n    pair<flow_t, cost_t> minCostMaxFlow() {\n        cost_t retCost\
    \ = 0;\n        for (int i = 0; i<N; ++i) {\n            for (Edge &e : G[i])\
    \ {\n                retCost += e.c*(e.f);\n            }\n        }\n       \
    \ //find max-flow\n        flow_t retFlow = max_flow();\n        h.assign(N, 0);\
    \ ex.assign(N, 0);\n        isq.assign(N, 0); cur.assign(N, 0);\n        queue<int>\
    \ q;\n        for (; eps; eps >>= scale) {\n            //refine\n           \
    \ fill(cur.begin(), cur.end(), 0);\n            for (int i = 0; i < N; ++i) {\n\
    \                for (auto &e : G[i]) {\n                    if (h[i] + e.c -\
    \ h[e.to] < 0 && e.f) push(e, e.f);\n                }\n            }\n      \
    \      for (int i = 0; i < N; ++i) {\n                if (ex[i] > 0){\n      \
    \              q.push(i);\n                    isq[i] = 1;\n                }\n\
    \            }\n            // make flow feasible\n            while (!q.empty())\
    \ {\n                int u = q.front(); q.pop();\n                isq[u]=0;\n\
    \                while (ex[u] > 0) {\n                    if (cur[u] == G[u].size())\
    \ {\n                        relabel(u);\n                    }\n            \
    \        for (unsigned int &i=cur[u], max_i = G[u].size(); i < max_i; ++i) {\n\
    \                        Edge &e = G[u][i];\n                        if (h[u]\
    \ + e.c - h[e.to] < 0) {\n                            push(e, ex[u]);\n      \
    \                      if (ex[e.to] > 0 && isq[e.to] == 0) {\n               \
    \                 q.push(e.to);\n                                isq[e.to] = 1;\n\
    \                            }\n                            if (ex[u] == 0) break;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n            if (eps > 1 && eps>>scale == 0) {\n                eps =\
    \ 1<<scale;\n            }\n        }\n        for (int i = 0; i < N; ++i) {\n\
    \            for (Edge &e : G[i]) {\n                retCost -= e.c*(e.f);\n \
    \           }\n        }\n        return make_pair(retFlow, retCost / 2 / N);\n\
    \    }\n\nprivate:\n    static constexpr cost_t INFCOST = numeric_limits<cost_t>::max()/2;\n\
    \    static constexpr int scale = 2;\n\n    cost_t eps;\n    vector<unsigned int>\
    \ isq, cur;\n    vector<flow_t> ex;\n    vector<cost_t> h;\n    vector<vector<int>\
    \ > hs;\n    vector<int> co;\n\n    void add_flow(Edge& e, flow_t f) {\n     \
    \   Edge &back = G[e.to][e.rev];\n        if (!ex[e.to] && f) {\n            hs[h[e.to]].push_back(e.to);\n\
    \        }\n        e.f -= f; ex[e.to] += f;\n        back.f += f; ex[back.to]\
    \ -= f;\n    }\n\n    void push(Edge &e, flow_t amt) {\n        if (e.f < amt)\
    \ amt = e.f;\n        e.f -= amt; ex[e.to] += amt;\n        G[e.to][e.rev].f +=\
    \ amt; ex[G[e.to][e.rev].to] -= amt;\n    }\n\n    void relabel(int vertex){\n\
    \        cost_t newHeight = -INFCOST;\n        for (unsigned int i = 0; i < G[vertex].size();\
    \ ++i){\n            Edge const&e = G[vertex][i];\n            if(e.f && newHeight\
    \ < h[e.to] - e.c){\n                newHeight = h[e.to] - e.c;\n            \
    \    cur[vertex] = i;\n            }\n        }\n        h[vertex] = newHeight\
    \ - eps;\n    }\n\n    flow_t max_flow() {\n        ex.assign(N, 0);\n       \
    \ h.assign(N, 0); hs.resize(2*N);\n        co.assign(2*N, 0); cur.assign(N, 0);\n\
    \        h[S] = N;\n        ex[T] = 1;\n        co[0] = N-1;\n        for (auto\
    \ &e : G[S]) {\n            add_flow(e, e.f);\n        }\n        if (hs[0].size())\
    \ {\n            for (int hi = 0; hi>=0;) {\n                int u = hs[hi].back();\n\
    \                hs[hi].pop_back();\n                while (ex[u] > 0) { // discharge\
    \ u\n                    if (cur[u] == G[u].size()) {\n                      \
    \  h[u] = 1e9;\n                        for(unsigned int i = 0; i < G[u].size();\
    \ ++i) {\n                            auto &e = G[u][i];\n                   \
    \         if (e.f && h[u] > h[e.to]+1) {\n                                h[u]\
    \ = h[e.to]+1, cur[u] = i;\n                            }\n                  \
    \      }\n                        if (++co[h[u]], !--co[hi] && hi < N) {\n   \
    \                         for (int i = 0; i < N; ++i) {\n                    \
    \            if (hi < h[i] && h[i] < N) {\n                                  \
    \  --co[h[i]];\n                                    h[i] = N + 1;\n          \
    \                      }\n                            }\n                    \
    \    }\n                        hi = h[u];\n                    } else if (G[u][cur[u]].f\
    \ && h[u] == h[G[u][cur[u]].to]+1) {\n                        add_flow(G[u][cur[u]],\
    \ min(ex[u], G[u][cur[u]].f));\n                    } else {\n               \
    \         ++cur[u];\n                    }\n                }\n              \
    \  while (hi>=0 && hs[hi].empty()) {\n                    --hi;\n            \
    \    }\n            }\n        }\n        return -ex[S];\n    }\n};\n#line 7 \"\
    Graph/tests/aizu_grl_6_b_mincost_maxflow.test.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n, m, fl; cin >> n >> m >> fl;\n\n    MinCostFlow<int,\
    \ int> flow(n+1, 0, n);\n    flow.addEdge(n-1, n, fl, 0);\n    while (m--) {\n\
    \        int u, v, f, c; cin >> u >> v >> f >> c;\n        flow.addEdge(u, v,\
    \ f, c);\n    }\n    auto [f, c] = flow.minCostMaxFlow();\n    if (f < fl) {\n\
    \        cout << -1 << endl;\n    } else {\n        cout << c << endl;\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../MaxFlow/MinCostMaxFlowPR.h\"\
    \n\nint main() {\n    ios_base::sync_with_stdio(0); cin.tie(0);\n    int n, m,\
    \ fl; cin >> n >> m >> fl;\n\n    MinCostFlow<int, int> flow(n+1, 0, n);\n   \
    \ flow.addEdge(n-1, n, fl, 0);\n    while (m--) {\n        int u, v, f, c; cin\
    \ >> u >> v >> f >> c;\n        flow.addEdge(u, v, f, c);\n    }\n    auto [f,\
    \ c] = flow.minCostMaxFlow();\n    if (f < fl) {\n        cout << -1 << endl;\n\
    \    } else {\n        cout << c << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - Graph/MaxFlow/MinCostMaxFlowPR.h
  isVerificationFile: true
  path: Graph/tests/aizu_grl_6_b_mincost_maxflow.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 21:41:41+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Graph/tests/aizu_grl_6_b_mincost_maxflow.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/aizu_grl_6_b_mincost_maxflow.test.cpp
- /verify/Graph/tests/aizu_grl_6_b_mincost_maxflow.test.cpp.html
title: Graph/tests/aizu_grl_6_b_mincost_maxflow.test.cpp
---
