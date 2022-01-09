---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/maxflow_pr.test.cpp
    title: Graph/tests/maxflow_pr.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://vn.spoj.com/problems/FFLOW/
    - http://vn.spoj.com/problems/NKFLOW/
    - http://www.spoj.com/problems/FASTFLOW/
    - https://codeforces.com/problemset/problem/269/C
    - https://github.com/dacin21/dacin21_codebook/blob/master/flow/maxflow_short.cpp
    - https://www.lydsy.com/JudgeOnline/problem.php?id=1001.
  bundledCode: "#line 1 \"Graph/MaxFlow/MaxFlowPR.h\"\n// Push relabel in O(V^2 E^0.5)\
    \ with gap heuristic\n// Source: https://github.com/dacin21/dacin21_codebook/blob/master/flow/maxflow_short.cpp\n\
    //\n// Notes:\n// - Index from 0\n// - Does not work with unsigned types.\n//\n\
    // Usage:\n// \n// MaxFlow<int> flow(n);\n// flow.addEdge(u, v, f);  // directed\n\
    // flow.addEdge(u, v, f, f);  // undirected\n// int maxFlow = flow.getMaxFlow(s,\
    \ t);\n//\n// Tested:\n// - http://vn.spoj.com/problems/NKFLOW/ (directed)\n//\
    \ - http://vn.spoj.com/problems/FFLOW/  (undirected)\n// - http://www.spoj.com/problems/FASTFLOW/\
    \  (undirected)\n// - https://codeforces.com/problemset/problem/269/C  (with trace).\n\
    //\n// TLE on https://www.lydsy.com/JudgeOnline/problem.php?id=1001. Why? (ACed\
    \ with Dinic flow).\n\ntemplate<typename flow_t = long long>\nstruct MaxFlow {\n\
    \    struct Edge {\n        int to, rev;\n        flow_t f, c;\n    };\n    vector<vector<Edge>\
    \ > g;\n    MaxFlow(int _n) : g(_n), ec(_n), cur(_n), hs(2*_n), H(_n) {}\n\n \
    \   int addEdge(int s, int t, flow_t cap, flow_t rcap=0) {\n        if (s == t)\
    \ return -1;\n        Edge a = {t, (int)g[t].size(), 0, cap};\n        Edge b\
    \ = {s, (int)g[s].size(), 0, rcap};\n        g[s].push_back(a);\n        g[t].push_back(b);\n\
    \n        // Return ID of forward edge.\n        return b.rev;\n    }\n\n    flow_t\
    \ getMaxFlow(int s, int t) {\n        int v = g.size();\n        H[s] = v;\n \
    \       ec[t] = 1;\n        vector<int> co(2*v);\n        co[0] = v-1;\n     \
    \   for (int i = 0; i < v; ++i) {\n            cur[i] = g[i].data();\n       \
    \ }\n        for (auto &e : g[s]) {\n            add_flow(e, e.c);\n        }\n\
    \        if (hs[0].size()) {\n            for (int hi = 0; hi >= 0;) {\n     \
    \           int u = hs[hi].back();\n                hs[hi].pop_back();\n     \
    \           while (ec[u] > 0) { // discharge u\n                    if (cur[u]\
    \ == g[u].data() + g[u].size()) {\n                        H[u] = 1e9;\n     \
    \                   for (auto &e : g[u]) {\n                            if (e.c\
    \ && H[u] > H[e.to]+1) {\n                                H[u] = H[e.to]+1;\n\
    \                                cur[u] = &e;\n                            }\n\
    \                        }\n                        if (++co[H[u]], !--co[hi]\
    \ && hi < v) {\n                            for (int i = 0; i < v; ++i) {\n  \
    \                              if (hi < H[i] && H[i] < v){\n                 \
    \                   --co[H[i]];\n                                    H[i] = v\
    \ + 1;\n                                }\n                            }\n   \
    \                     }\n                        hi = H[u];\n                \
    \    } else if (cur[u]->c && H[u] == H[cur[u]->to] + 1) {\n                  \
    \      add_flow(*cur[u], min(ec[u], cur[u]->c));\n                    }\n    \
    \                else {\n                        ++cur[u];\n                 \
    \   }\n                }\n                while (hi>=0 && hs[hi].empty()) --hi;\n\
    \            }\n        }\n        return -ec[s];\n    }\n\nprivate:\n    vector<flow_t>\
    \ ec;\n    vector<Edge*> cur;\n    vector<vector<int> > hs;\n    vector<int> H;\n\
    \n    void add_flow(Edge& e, flow_t f) {\n        Edge &back = g[e.to][e.rev];\n\
    \        if (!ec[e.to] && f) {\n            hs[H[e.to]].push_back(e.to);\n   \
    \     }\n        e.f += f; e.c -= f;\n        ec[e.to] += f;\n        back.f -=\
    \ f; back.c += f;\n        ec[back.to] -= f;\n    }\n};\n"
  code: "// Push relabel in O(V^2 E^0.5) with gap heuristic\n// Source: https://github.com/dacin21/dacin21_codebook/blob/master/flow/maxflow_short.cpp\n\
    //\n// Notes:\n// - Index from 0\n// - Does not work with unsigned types.\n//\n\
    // Usage:\n// \n// MaxFlow<int> flow(n);\n// flow.addEdge(u, v, f);  // directed\n\
    // flow.addEdge(u, v, f, f);  // undirected\n// int maxFlow = flow.getMaxFlow(s,\
    \ t);\n//\n// Tested:\n// - http://vn.spoj.com/problems/NKFLOW/ (directed)\n//\
    \ - http://vn.spoj.com/problems/FFLOW/  (undirected)\n// - http://www.spoj.com/problems/FASTFLOW/\
    \  (undirected)\n// - https://codeforces.com/problemset/problem/269/C  (with trace).\n\
    //\n// TLE on https://www.lydsy.com/JudgeOnline/problem.php?id=1001. Why? (ACed\
    \ with Dinic flow).\n\ntemplate<typename flow_t = long long>\nstruct MaxFlow {\n\
    \    struct Edge {\n        int to, rev;\n        flow_t f, c;\n    };\n    vector<vector<Edge>\
    \ > g;\n    MaxFlow(int _n) : g(_n), ec(_n), cur(_n), hs(2*_n), H(_n) {}\n\n \
    \   int addEdge(int s, int t, flow_t cap, flow_t rcap=0) {\n        if (s == t)\
    \ return -1;\n        Edge a = {t, (int)g[t].size(), 0, cap};\n        Edge b\
    \ = {s, (int)g[s].size(), 0, rcap};\n        g[s].push_back(a);\n        g[t].push_back(b);\n\
    \n        // Return ID of forward edge.\n        return b.rev;\n    }\n\n    flow_t\
    \ getMaxFlow(int s, int t) {\n        int v = g.size();\n        H[s] = v;\n \
    \       ec[t] = 1;\n        vector<int> co(2*v);\n        co[0] = v-1;\n     \
    \   for (int i = 0; i < v; ++i) {\n            cur[i] = g[i].data();\n       \
    \ }\n        for (auto &e : g[s]) {\n            add_flow(e, e.c);\n        }\n\
    \        if (hs[0].size()) {\n            for (int hi = 0; hi >= 0;) {\n     \
    \           int u = hs[hi].back();\n                hs[hi].pop_back();\n     \
    \           while (ec[u] > 0) { // discharge u\n                    if (cur[u]\
    \ == g[u].data() + g[u].size()) {\n                        H[u] = 1e9;\n     \
    \                   for (auto &e : g[u]) {\n                            if (e.c\
    \ && H[u] > H[e.to]+1) {\n                                H[u] = H[e.to]+1;\n\
    \                                cur[u] = &e;\n                            }\n\
    \                        }\n                        if (++co[H[u]], !--co[hi]\
    \ && hi < v) {\n                            for (int i = 0; i < v; ++i) {\n  \
    \                              if (hi < H[i] && H[i] < v){\n                 \
    \                   --co[H[i]];\n                                    H[i] = v\
    \ + 1;\n                                }\n                            }\n   \
    \                     }\n                        hi = H[u];\n                \
    \    } else if (cur[u]->c && H[u] == H[cur[u]->to] + 1) {\n                  \
    \      add_flow(*cur[u], min(ec[u], cur[u]->c));\n                    }\n    \
    \                else {\n                        ++cur[u];\n                 \
    \   }\n                }\n                while (hi>=0 && hs[hi].empty()) --hi;\n\
    \            }\n        }\n        return -ec[s];\n    }\n\nprivate:\n    vector<flow_t>\
    \ ec;\n    vector<Edge*> cur;\n    vector<vector<int> > hs;\n    vector<int> H;\n\
    \n    void add_flow(Edge& e, flow_t f) {\n        Edge &back = g[e.to][e.rev];\n\
    \        if (!ec[e.to] && f) {\n            hs[H[e.to]].push_back(e.to);\n   \
    \     }\n        e.f += f; e.c -= f;\n        ec[e.to] += f;\n        back.f -=\
    \ f; back.c += f;\n        ec[back.to] -= f;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaxFlow/MaxFlowPR.h
  requiredBy: []
  timestamp: '2021-12-17 23:12:55+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/maxflow_pr.test.cpp
documentation_of: Graph/MaxFlow/MaxFlowPR.h
layout: document
redirect_from:
- /library/Graph/MaxFlow/MaxFlowPR.h
- /library/Graph/MaxFlow/MaxFlowPR.h.html
title: Graph/MaxFlow/MaxFlowPR.h
---
