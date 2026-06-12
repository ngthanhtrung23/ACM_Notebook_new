---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/gym/100739/problem/G
  bundledCode: "#line 1 \"DataStructure/HeavyLight.cpp\"\n// Tested:\n// - http://codeforces.com/gym/100739/problem/G\n\
    //\n// Notes:\n// - Index from 1\n// - dfn: vertex id --> position\n// --> for\
    \ point query, only need to visit(dfn[u])\n// --> for range query, use query(u,\
    \ v)\n// Author: zimpha\n#include <bits/stdc++.h>\nusing namespace std;\nconst\
    \ int MN = 100111;\nvector<int> G[MN];\nint sz[MN], dep[MN], fa[MN];\nint dfn[MN],\
    \ top[MN];\nint n, id;\n\n// Operations on segment tree\nint querySeg(int i, int\
    \ l, int r, int u, int v) {return 0;}\n\nvoid dfs1(int u, int f = 0) {\n    sz[u]\
    \ = 1; fa[u] = f;\n    for (auto &v: G[u]) if (v != f) {\n        dep[v] = dep[u]\
    \ + 1;\n        dfs1(v, u); sz[u] += sz[v];\n    }\n}\n\nvoid dfs2(int u, int\
    \ chain, int f = 0) {\n    int son(-1); dfn[u] = ++id; top[u] = chain;\n    for\
    \ (auto &v: G[u]) if (v != f) {\n        if (son == -1 || sz[son] < sz[v]) son\
    \ = v;\n    }\n    if (~son) dfs2(son, chain, u);\n    for (auto &v: G[u]) if\
    \ (v != f && v != son) {\n        dfs2(v, v, u);\n    }\n}\n\nint query(int u,\
    \ int v) {\n    int res = 0;\n    int fu = top[u], fv = top[v];\n    while (fu\
    \ != fv) {\n        if (dep[fu] < dep[fv]) swap(u, v), swap(fu, fv);\n       \
    \ res += querySeg(1, 1, n, dfn[fu], dfn[u]);\n        u = fa[fu], fu = top[u];\n\
    \    }\n    if (dep[u] > dep[v]) swap(u, v);\n    res += querySeg(1, 1, n, dfn[u],\
    \ dfn[v]);\n    return res;\n}\n\nint main() {\n    dfs1(1);\n    id = 0;\n  \
    \  dfs2(1, 1);\n}\n\n"
  code: "// Tested:\n// - http://codeforces.com/gym/100739/problem/G\n//\n// Notes:\n\
    // - Index from 1\n// - dfn: vertex id --> position\n// --> for point query, only\
    \ need to visit(dfn[u])\n// --> for range query, use query(u, v)\n// Author: zimpha\n\
    #include <bits/stdc++.h>\nusing namespace std;\nconst int MN = 100111;\nvector<int>\
    \ G[MN];\nint sz[MN], dep[MN], fa[MN];\nint dfn[MN], top[MN];\nint n, id;\n\n\
    // Operations on segment tree\nint querySeg(int i, int l, int r, int u, int v)\
    \ {return 0;}\n\nvoid dfs1(int u, int f = 0) {\n    sz[u] = 1; fa[u] = f;\n  \
    \  for (auto &v: G[u]) if (v != f) {\n        dep[v] = dep[u] + 1;\n        dfs1(v,\
    \ u); sz[u] += sz[v];\n    }\n}\n\nvoid dfs2(int u, int chain, int f = 0) {\n\
    \    int son(-1); dfn[u] = ++id; top[u] = chain;\n    for (auto &v: G[u]) if (v\
    \ != f) {\n        if (son == -1 || sz[son] < sz[v]) son = v;\n    }\n    if (~son)\
    \ dfs2(son, chain, u);\n    for (auto &v: G[u]) if (v != f && v != son) {\n  \
    \      dfs2(v, v, u);\n    }\n}\n\nint query(int u, int v) {\n    int res = 0;\n\
    \    int fu = top[u], fv = top[v];\n    while (fu != fv) {\n        if (dep[fu]\
    \ < dep[fv]) swap(u, v), swap(fu, fv);\n        res += querySeg(1, 1, n, dfn[fu],\
    \ dfn[u]);\n        u = fa[fu], fu = top[u];\n    }\n    if (dep[u] > dep[v])\
    \ swap(u, v);\n    res += querySeg(1, 1, n, dfn[u], dfn[v]);\n    return res;\n\
    }\n\nint main() {\n    dfs1(1);\n    id = 0;\n    dfs2(1, 1);\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/HeavyLight.cpp
  requiredBy: []
  timestamp: '2021-12-17 19:15:32+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/HeavyLight.cpp
layout: document
redirect_from:
- /library/DataStructure/HeavyLight.cpp
- /library/DataStructure/HeavyLight.cpp.html
title: DataStructure/HeavyLight.cpp
---
