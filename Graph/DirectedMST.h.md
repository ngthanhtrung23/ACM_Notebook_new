---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/aizu_grl_2_b_directed_mst.test.cpp
    title: Graph/tests/aizu_grl_2_b_directed_mst.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/tests/directed_mst.test.cpp
    title: Graph/tests/directed_mst.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"Graph/DirectedMST.h\"\n// include DSU_rollback.h\n\n// Directed\
    \ MST\n// Index from 0\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/directedmst\n\
    \nusing ll = long long;\nstruct Edge {\n    int u, v;  // directed, u -> v\n \
    \   ll cost;\n};\nstruct HeapNode {  // lazy skew heap node\n    Edge key;\n \
    \   HeapNode *l, *r;\n    ll delta;\n\n    void prop() {\n        key.cost +=\
    \ delta;\n        if (l) l->delta += delta;\n        if (r) r->delta += delta;\n\
    \        delta = 0;\n    }\n    Edge top() {\n        prop();\n        return\
    \ key;\n    }\n};\nHeapNode* merge(HeapNode *a, HeapNode *b) {\n    if (!a) return\
    \ b;\n    if (!b) return a;\n    a->prop(); b->prop();\n    if (a->key.cost >\
    \ b->key.cost) swap(a, b);\n    swap(a->l, (a->r = merge(b, a->r)));\n    return\
    \ a;\n}\nvoid pop(HeapNode *&a) {\n    a->prop();\n    a = merge(a->l, a->r);\n\
    }\n\n// return {cost, parent[i]}\n// parent[root] = -1\n// Not found -> return\
    \ {-1, {}}\npair<ll, vector<int>> directed_mst(int n, int root, vector<Edge>&\
    \ edges) {\n    DSU dsu(n);\n    int dsu_time = 0;\n    vector<HeapNode*> heap(n);\n\
    \    for (const Edge& e : edges) {\n        heap[e.v] = merge(heap[e.v], new HeapNode{e});\n\
    \    }\n\n    ll res = 0;\n    vector<int> seen(n, -1), path(n);\n    seen[root]\
    \ = root;\n    vector<Edge> Q(n), in(n, {-1, -1});\n    deque<tuple<int, int,\
    \ vector<Edge>>> cycs;\n    for (int s = 0; s < n; ++s) {\n        int u = s,\
    \ qi = 0, w;\n        while (seen[u] < 0) {\n            if (!heap[u]) return\
    \ {-1, {}};\n            Edge e = heap[u]->top();\n            heap[u]->delta\
    \ -= e.cost;\n            pop(heap[u]);\n            Q[qi] = e;\n            path[qi++]\
    \ = u;\n            seen[u] = s;\n            res += e.cost;\n            u =\
    \ dsu.getRoot(e.u);\n\n            if (seen[u] == s) {\n                HeapNode*\
    \ cyc = 0;\n                int end = qi;\n                int time = dsu_time;\n\
    \                do {\n                    cyc = merge(cyc, heap[w = path[--qi]]);\n\
    \                } while (dsu.join(u, w, ++dsu_time));\n\n                u =\
    \ dsu.getRoot(u);\n                heap[u] = cyc;\n                seen[u] = -1;\n\
    \                cycs.push_front({u, time, {&Q[qi], &Q[end]}});\n            }\n\
    \        }\n        for (int i = 0; i < qi; i++) in[dsu.getRoot(Q[i].v)] = Q[i];\n\
    \    }\n\n    for (auto& [u, t, comp] : cycs) {\n        dsu.rollback(t);\n  \
    \      Edge inEdge = in[u];\n        for (auto& e : comp) in[dsu.getRoot(e.v)]\
    \ = e;\n        in[dsu.getRoot(inEdge.v)] = inEdge;\n    }\n\n    vector<int>\
    \ par(n);\n    for (int i = 0; i < n; i++) par[i] = in[i].u;\n    return {res,\
    \ par};\n}\n"
  code: "// include DSU_rollback.h\n\n// Directed MST\n// Index from 0\n//\n// Tested:\n\
    // - https://judge.yosupo.jp/problem/directedmst\n\nusing ll = long long;\nstruct\
    \ Edge {\n    int u, v;  // directed, u -> v\n    ll cost;\n};\nstruct HeapNode\
    \ {  // lazy skew heap node\n    Edge key;\n    HeapNode *l, *r;\n    ll delta;\n\
    \n    void prop() {\n        key.cost += delta;\n        if (l) l->delta += delta;\n\
    \        if (r) r->delta += delta;\n        delta = 0;\n    }\n    Edge top()\
    \ {\n        prop();\n        return key;\n    }\n};\nHeapNode* merge(HeapNode\
    \ *a, HeapNode *b) {\n    if (!a) return b;\n    if (!b) return a;\n    a->prop();\
    \ b->prop();\n    if (a->key.cost > b->key.cost) swap(a, b);\n    swap(a->l, (a->r\
    \ = merge(b, a->r)));\n    return a;\n}\nvoid pop(HeapNode *&a) {\n    a->prop();\n\
    \    a = merge(a->l, a->r);\n}\n\n// return {cost, parent[i]}\n// parent[root]\
    \ = -1\n// Not found -> return {-1, {}}\npair<ll, vector<int>> directed_mst(int\
    \ n, int root, vector<Edge>& edges) {\n    DSU dsu(n);\n    int dsu_time = 0;\n\
    \    vector<HeapNode*> heap(n);\n    for (const Edge& e : edges) {\n        heap[e.v]\
    \ = merge(heap[e.v], new HeapNode{e});\n    }\n\n    ll res = 0;\n    vector<int>\
    \ seen(n, -1), path(n);\n    seen[root] = root;\n    vector<Edge> Q(n), in(n,\
    \ {-1, -1});\n    deque<tuple<int, int, vector<Edge>>> cycs;\n    for (int s =\
    \ 0; s < n; ++s) {\n        int u = s, qi = 0, w;\n        while (seen[u] < 0)\
    \ {\n            if (!heap[u]) return {-1, {}};\n            Edge e = heap[u]->top();\n\
    \            heap[u]->delta -= e.cost;\n            pop(heap[u]);\n          \
    \  Q[qi] = e;\n            path[qi++] = u;\n            seen[u] = s;\n       \
    \     res += e.cost;\n            u = dsu.getRoot(e.u);\n\n            if (seen[u]\
    \ == s) {\n                HeapNode* cyc = 0;\n                int end = qi;\n\
    \                int time = dsu_time;\n                do {\n                \
    \    cyc = merge(cyc, heap[w = path[--qi]]);\n                } while (dsu.join(u,\
    \ w, ++dsu_time));\n\n                u = dsu.getRoot(u);\n                heap[u]\
    \ = cyc;\n                seen[u] = -1;\n                cycs.push_front({u, time,\
    \ {&Q[qi], &Q[end]}});\n            }\n        }\n        for (int i = 0; i <\
    \ qi; i++) in[dsu.getRoot(Q[i].v)] = Q[i];\n    }\n\n    for (auto& [u, t, comp]\
    \ : cycs) {\n        dsu.rollback(t);\n        Edge inEdge = in[u];\n        for\
    \ (auto& e : comp) in[dsu.getRoot(e.v)] = e;\n        in[dsu.getRoot(inEdge.v)]\
    \ = inEdge;\n    }\n\n    vector<int> par(n);\n    for (int i = 0; i < n; i++)\
    \ par[i] = in[i].u;\n    return {res, par};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/DirectedMST.h
  requiredBy: []
  timestamp: '2022-01-06 04:18:39+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/aizu_grl_2_b_directed_mst.test.cpp
  - Graph/tests/directed_mst.test.cpp
documentation_of: Graph/DirectedMST.h
layout: document
redirect_from:
- /library/Graph/DirectedMST.h
- /library/Graph/DirectedMST.h.html
title: Graph/DirectedMST.h
---
