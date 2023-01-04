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
    - https://www.spoj.com/problems/FASTFLOW/
    - https://www.spoj.com/problems/FFLOW/
    - https://www.spoj.com/problems/MATCHING/
  bundledCode: "#line 1 \"Graph/MaxFlow/MaxFlowLMH.h\"\n// NOTE:\n// - MaxFlowHLPP\
    \ is probably faster\n// - UNDIRECTED ONLY (for directed seems there's some infinite\
    \ loop)\n// - Index from 0\n//\n// Tested:\n// - https://www.spoj.com/problems/FFLOW/\
    \ (undirected)\n// - https://www.spoj.com/problems/FASTFLOW/ (undirected)\n//\
    \ - https://www.spoj.com/problems/MATCHING/ (matching)\n//\n// Max flow LMH {{{\n\
    struct Edge {\n    int u, v, c, f;\n    int next;\n};\n \nstruct MaxFlow {\n \
    \   int n, s, t;\n    vector< Edge > edges;\n    vector<int> head, current, h,\
    \ avail;\n    vector<long long> excess;\n \n    MaxFlow(int _n) : n(_n), head(n,\
    \ -1), current(n, -1), h(n), avail(n), excess(n) {\n        edges.clear();\n \
    \   }\n \n    void addEdgeUndirected(int u, int v, int c) {\n        Edge xuoi\
    \ = {u, v, c, 0, head[u]};\n        head[u] = edges.size(); edges.push_back(xuoi);\n\
    \        Edge nguoc = {v, u, c, 0, head[v]};\n        head[v] = edges.size();\
    \ edges.push_back(nguoc);\n    }\n \n    long long getFlow(int _s, int _t) {\n\
    \        s = _s; t = _t;\n        init();\n \n        int now = 0;\n        queue<int>\
    \ qu[2];\n        for (int x = 0; x < n; ++x)\n            if (x != s && x !=\
    \ t && excess[x] > 0)\n                qu[now].push(x);\n        \n        globalLabeling();\n\
    \ \n        int cnt = 0;\n        while (!qu[now].empty()) {\n            while\
    \ (!qu[1-now].empty()) qu[1-now].pop();\n \n            while (!qu[now].empty())\
    \ {\n                int x = qu[now].front(); qu[now].pop();\n               \
    \ while (current[x] >= 0) {\n                    int p = current[x];\n       \
    \             if (edges[p].c > edges[p].f && h[edges[p].u] > h[edges[p].v]) {\n\
    \                        bool need = (edges[p].v != s && edges[p].v != t && !excess[edges[p].v]);\n\
    \                        push(current[x]);\n                        if (need)\
    \ qu[1-now].push(edges[p].v);\n                        if (!excess[x]) break;\n\
    \                    }\n                    current[x] = edges[current[x]].next;\n\
    \                }\n                \n                if (excess[x] > 0) {\n \
    \                   lift(x);\n                    current[x] = head[x];\n    \
    \                qu[1-now].push(x);\n                    cnt++;\n            \
    \        if (cnt == n) {\n                        globalLabeling();\n        \
    \                cnt=0;\n                    }\n                }\n          \
    \  }\n            now = 1 - now;\n        }\n        return excess[t];\n    }\n\
    \ \nprivate:\n    void init() {\n        current = head;\n \n        int p = head[s];\n\
    \        while (p >= 0) {\n            edges[p].f = edges[p].c;\n            edges[p^1].f\
    \ -= edges[p].c;\n            excess[edges[p].v] += edges[p].c;\n            excess[s]\
    \ -= edges[p].c;\n            p = edges[p].next;\n        }\n        std::fill(h.begin(),\
    \ h.end(), 1);\n        h[s] = n; h[t] = 0;\n    }\n \n    void push(int i) {\n\
    \        long long delta = min(excess[edges[i].u], (long long) edges[i].c - edges[i].f);\n\
    \        edges[i].f += delta; edges[i^1].f -= delta;\n        excess[edges[i].u]\
    \ -= delta;\n        excess[edges[i].v] += delta;\n    }\n \n    void lift(int\
    \ u) {\n        int minH = 2 * n;\n        int p = head[u];\n        while (p>=0)\
    \ {\n            if (edges[p].c > edges[p].f)\n                minH = min(minH,\
    \ h[edges[p].v]);\n            p = edges[p].next;\n        }\n        h[u] = minH\
    \ + 1;\n    }\n \n    void globalLabeling() {\n        std::fill(avail.begin(),\
    \ avail.end(), 1);\n        std::fill(h.begin(), h.end(), 0);\n        h[s] =\
    \ n; h[t] = 0;\n        queue<int> q; q.push(t); avail[t] = false;\n \n      \
    \  while (!q.empty()) {\n            int x = q.front(); q.pop();\n           \
    \ int p = head[x];\n            while (p >= 0) {\n                int pp = p^1;\n\
    \                if (avail[edges[pp].u] && edges[pp].f < edges[pp].c) {\n    \
    \                h[edges[pp].u] = h[x] + 1;\n                    avail[edges[pp].u]\
    \ = 0;\n                    q.push(edges[pp].u);\n                }\n        \
    \        p = edges[p].next;\n            }\n            if (q.empty() && avail[s])\
    \ {\n                avail[s] = false;\n                q.push(s);\n         \
    \   }\n        }\n        current = head;\n    }\n};\n// }}}\n"
  code: "// NOTE:\n// - MaxFlowHLPP is probably faster\n// - UNDIRECTED ONLY (for\
    \ directed seems there's some infinite loop)\n// - Index from 0\n//\n// Tested:\n\
    // - https://www.spoj.com/problems/FFLOW/ (undirected)\n// - https://www.spoj.com/problems/FASTFLOW/\
    \ (undirected)\n// - https://www.spoj.com/problems/MATCHING/ (matching)\n//\n\
    // Max flow LMH {{{\nstruct Edge {\n    int u, v, c, f;\n    int next;\n};\n \n\
    struct MaxFlow {\n    int n, s, t;\n    vector< Edge > edges;\n    vector<int>\
    \ head, current, h, avail;\n    vector<long long> excess;\n \n    MaxFlow(int\
    \ _n) : n(_n), head(n, -1), current(n, -1), h(n), avail(n), excess(n) {\n    \
    \    edges.clear();\n    }\n \n    void addEdgeUndirected(int u, int v, int c)\
    \ {\n        Edge xuoi = {u, v, c, 0, head[u]};\n        head[u] = edges.size();\
    \ edges.push_back(xuoi);\n        Edge nguoc = {v, u, c, 0, head[v]};\n      \
    \  head[v] = edges.size(); edges.push_back(nguoc);\n    }\n \n    long long getFlow(int\
    \ _s, int _t) {\n        s = _s; t = _t;\n        init();\n \n        int now\
    \ = 0;\n        queue<int> qu[2];\n        for (int x = 0; x < n; ++x)\n     \
    \       if (x != s && x != t && excess[x] > 0)\n                qu[now].push(x);\n\
    \        \n        globalLabeling();\n \n        int cnt = 0;\n        while (!qu[now].empty())\
    \ {\n            while (!qu[1-now].empty()) qu[1-now].pop();\n \n            while\
    \ (!qu[now].empty()) {\n                int x = qu[now].front(); qu[now].pop();\n\
    \                while (current[x] >= 0) {\n                    int p = current[x];\n\
    \                    if (edges[p].c > edges[p].f && h[edges[p].u] > h[edges[p].v])\
    \ {\n                        bool need = (edges[p].v != s && edges[p].v != t &&\
    \ !excess[edges[p].v]);\n                        push(current[x]);\n         \
    \               if (need) qu[1-now].push(edges[p].v);\n                      \
    \  if (!excess[x]) break;\n                    }\n                    current[x]\
    \ = edges[current[x]].next;\n                }\n                \n           \
    \     if (excess[x] > 0) {\n                    lift(x);\n                   \
    \ current[x] = head[x];\n                    qu[1-now].push(x);\n            \
    \        cnt++;\n                    if (cnt == n) {\n                       \
    \ globalLabeling();\n                        cnt=0;\n                    }\n \
    \               }\n            }\n            now = 1 - now;\n        }\n    \
    \    return excess[t];\n    }\n \nprivate:\n    void init() {\n        current\
    \ = head;\n \n        int p = head[s];\n        while (p >= 0) {\n           \
    \ edges[p].f = edges[p].c;\n            edges[p^1].f -= edges[p].c;\n        \
    \    excess[edges[p].v] += edges[p].c;\n            excess[s] -= edges[p].c;\n\
    \            p = edges[p].next;\n        }\n        std::fill(h.begin(), h.end(),\
    \ 1);\n        h[s] = n; h[t] = 0;\n    }\n \n    void push(int i) {\n       \
    \ long long delta = min(excess[edges[i].u], (long long) edges[i].c - edges[i].f);\n\
    \        edges[i].f += delta; edges[i^1].f -= delta;\n        excess[edges[i].u]\
    \ -= delta;\n        excess[edges[i].v] += delta;\n    }\n \n    void lift(int\
    \ u) {\n        int minH = 2 * n;\n        int p = head[u];\n        while (p>=0)\
    \ {\n            if (edges[p].c > edges[p].f)\n                minH = min(minH,\
    \ h[edges[p].v]);\n            p = edges[p].next;\n        }\n        h[u] = minH\
    \ + 1;\n    }\n \n    void globalLabeling() {\n        std::fill(avail.begin(),\
    \ avail.end(), 1);\n        std::fill(h.begin(), h.end(), 0);\n        h[s] =\
    \ n; h[t] = 0;\n        queue<int> q; q.push(t); avail[t] = false;\n \n      \
    \  while (!q.empty()) {\n            int x = q.front(); q.pop();\n           \
    \ int p = head[x];\n            while (p >= 0) {\n                int pp = p^1;\n\
    \                if (avail[edges[pp].u] && edges[pp].f < edges[pp].c) {\n    \
    \                h[edges[pp].u] = h[x] + 1;\n                    avail[edges[pp].u]\
    \ = 0;\n                    q.push(edges[pp].u);\n                }\n        \
    \        p = edges[p].next;\n            }\n            if (q.empty() && avail[s])\
    \ {\n                avail[s] = false;\n                q.push(s);\n         \
    \   }\n        }\n        current = head;\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaxFlow/MaxFlowLMH.h
  requiredBy: []
  timestamp: '2023-01-04 14:38:22+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/MaxFlow/MaxFlowLMH.h
layout: document
redirect_from:
- /library/Graph/MaxFlow/MaxFlowLMH.h
- /library/Graph/MaxFlow/MaxFlowLMH.h.html
title: Graph/MaxFlow/MaxFlowLMH.h
---
