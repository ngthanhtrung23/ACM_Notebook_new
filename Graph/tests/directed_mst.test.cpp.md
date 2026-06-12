---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU/DSU_rollback.h
    title: DataStructure/DSU/DSU_rollback.h
  - icon: ':heavy_check_mark:'
    path: Graph/DirectedMST.h
    title: Graph/DirectedMST.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/directedmst
    links:
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"Graph/tests/directed_mst.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/directedmst\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"Graph/DirectedMST.h\"\n// include DSU_rollback.h\n\
    \n// Directed MST\n// Index from 0\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/directedmst\n\
    \n#line 1 \"DataStructure/DSU/DSU_rollback.h\"\n// Tested:\n// - (dynamic connectivity)\
    \ https://codeforces.com/gym/100551/problem/A\n// - (used for directed MST) https://judge.yosupo.jp/problem/directedmst\n\
    //\n// 0-based\n// DSU with rollback {{{\nstruct Data {\n    int time, u, par;\
    \  // before `time`, `par` = par[u]\n};\n\nstruct DSU {\n    vector<int> par;\n\
    \    vector<Data> change;\n\n    DSU(int n) : par(n + 5, -1) {}\n\n    // find\
    \ root of x.\n    // if par[x] < 0 then x is a root, and its tree has -par[x]\
    \ nodes\n    int getRoot(int x) {\n        while (par[x] >= 0)\n            x\
    \ = par[x];\n        return x;\n    }\n\n    bool same_component(int u, int v)\
    \ {\n        return getRoot(u) == getRoot(v);\n    }\n\n    // join components\
    \ containing x and y.\n    // t should be current time. We use it to update `change`.\n\
    \    bool join(int x, int y, int t) {\n        x = getRoot(x);\n        y = getRoot(y);\n\
    \        if (x == y) return false;\n\n        //union by rank\n        if (par[x]\
    \ < par[y]) swap(x, y); \n        //now x's tree has less nodes than y's tree\n\
    \        change.push_back({t, y, par[y]});\n        par[y] += par[x];\n      \
    \  change.push_back({t, x, par[x]});\n        par[x] = y;\n        return true;\n\
    \    }\n\n    // rollback all changes at time > t.\n    void rollback(int t) {\n\
    \        while (!change.empty() && change.back().time > t) {\n            par[change.back().u]\
    \ = change.back().par;\n            change.pop_back();\n        }\n    }\n};\n\
    // }}}\n#line 10 \"Graph/DirectedMST.h\"\nusing ll = long long;\nstruct Edge {\n\
    \    int u, v;  // directed, u -> v\n    ll cost;\n};\nstruct HeapNode {  // lazy\
    \ skew heap node\n    Edge key;\n    HeapNode *l, *r;\n    ll delta;\n\n    void\
    \ prop() {\n        key.cost += delta;\n        if (l) l->delta += delta;\n  \
    \      if (r) r->delta += delta;\n        delta = 0;\n    }\n    Edge top() {\n\
    \        prop();\n        return key;\n    }\n};\nHeapNode* merge(HeapNode *a,\
    \ HeapNode *b) {\n    if (!a) return b;\n    if (!b) return a;\n    a->prop();\
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
    \ par[i] = in[i].u;\n    return {res, par};\n}\n#line 7 \"Graph/tests/directed_mst.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m, root; cin >> n >>\
    \ m >> root;\n    vector<Edge> edges(m);\n    for (auto& e : edges) {\n      \
    \  cin >> e.u >> e.v >> e.cost;\n    }\n    auto [total, par] = directed_mst(n,\
    \ root, edges);\n    cout << total << endl;\n    REP(i,n) cout << (i == root ?\
    \ root : par[i]) << ' ';\n    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../DirectedMST.h\"\n\n#define\
    \ REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main() {\n \
    \   ios::sync_with_stdio(0); cin.tie(0);\n    int n, m, root; cin >> n >> m >>\
    \ root;\n    vector<Edge> edges(m);\n    for (auto& e : edges) {\n        cin\
    \ >> e.u >> e.v >> e.cost;\n    }\n    auto [total, par] = directed_mst(n, root,\
    \ edges);\n    cout << total << endl;\n    REP(i,n) cout << (i == root ? root\
    \ : par[i]) << ' ';\n    cout << endl;\n    return 0;\n}\n"
  dependsOn:
  - Graph/DirectedMST.h
  - DataStructure/DSU/DSU_rollback.h
  isVerificationFile: true
  path: Graph/tests/directed_mst.test.cpp
  requiredBy: []
  timestamp: '2023-01-07 01:46:12+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/directed_mst.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/directed_mst.test.cpp
- /verify/Graph/tests/directed_mst.test.cpp.html
title: Graph/tests/directed_mst.test.cpp
---
