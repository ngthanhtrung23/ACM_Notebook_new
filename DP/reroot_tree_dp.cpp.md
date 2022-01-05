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
    - https://cses.fi/problemset/task/1132/
    - https://oj.vnoi.info/problem/icpc21_mn_h
  bundledCode: "#line 1 \"DP/reroot_tree_dp.cpp\"\n// Reroot tree DP\n//\n// e.g.\
    \ We need to compute:\n// - f[u] = longest path starting from u, going inside\
    \ subtree(u)\n// - g[u] = longest path starting from u, going outside subtree(u)\n\
    //\n// We can easily compute f[u] using normal tree DP.\n// To compute g:\n//\
    \ - Init g[0]\n// - Current node = u\n// - Maintain some data structure to store\
    \ f[children(u)]\n// - Use this data structure to compute f[v]\n// - Call dfs(v)\n\
    //\n// Tested:\n// - CSES Tree Distance I: https://cses.fi/problemset/task/1132/\n\
    // - https://oj.vnoi.info/problem/icpc21_mn_h\n\nconst int MN = 200111;\nint g[MN];\
    \  // longest path from u, outside subtree(u)\nint f[MN];  // longest path from\
    \ u, inside subtree(u)\nint parent[MN];\nvector<int> adj[MN];\nvector<int> paths_from_u[MN];\n\
    \n// compute f[u]\nvoid dfs1(int u, int fu) {\n    parent[u] = fu;\n    f[u] =\
    \ 0;\n    for (int v : adj[u]) {\n        if (v == fu) continue;\n\n        dfs1(v,\
    \ u);\n        f[u] = max(f[u], f[v] + 1);\n    }\n}\n\n// compute g[u], using\
    \ reroot tree DP\nvoid dfs2(int u, int fu) {\n    // prefix and suffix max, for\
    \ f(children(u))\n    vector<int> left, right;\n    for (int v : adj[u]) {\n \
    \       if (v == fu) {\n            left.push_back(g[u]);\n        } else {\n\
    \            left.push_back(f[v] + 1);\n        }\n    }\n    right = left;\n\
    \    for (int i = 1; i < SZ(left); i++) {\n        left[i] = max(left[i-1], left[i]);\n\
    \    }\n    for (int i = SZ(right) - 2; i >= 0; i--) {\n        right[i] = max(right[i+1],\
    \ right[i]);\n    }\n\n    // compute g(children)\n    REP(i,SZ(adj[u])) {\n \
    \       int v = adj[u][i];\n        if (v == fu) continue;\n\n        // v ->\
    \ u\n        g[v] = 1;\n        // v -> u -> left of v\n        if (i > 0) g[v]\
    \ = max(g[v], left[i-1] + 1);\n        if (i+1 < SZ(adj[u])) g[v] = max(g[v],\
    \ right[i+1] + 1);\n\n        dfs2(v, u);\n    }\n}\n\nint main() {\n    // init\
    \ g\n    dfs1(root, -1);\n    dfs2(root, -1);\n}\n"
  code: "// Reroot tree DP\n//\n// e.g. We need to compute:\n// - f[u] = longest path\
    \ starting from u, going inside subtree(u)\n// - g[u] = longest path starting\
    \ from u, going outside subtree(u)\n//\n// We can easily compute f[u] using normal\
    \ tree DP.\n// To compute g:\n// - Init g[0]\n// - Current node = u\n// - Maintain\
    \ some data structure to store f[children(u)]\n// - Use this data structure to\
    \ compute f[v]\n// - Call dfs(v)\n//\n// Tested:\n// - CSES Tree Distance I: https://cses.fi/problemset/task/1132/\n\
    // - https://oj.vnoi.info/problem/icpc21_mn_h\n\nconst int MN = 200111;\nint g[MN];\
    \  // longest path from u, outside subtree(u)\nint f[MN];  // longest path from\
    \ u, inside subtree(u)\nint parent[MN];\nvector<int> adj[MN];\nvector<int> paths_from_u[MN];\n\
    \n// compute f[u]\nvoid dfs1(int u, int fu) {\n    parent[u] = fu;\n    f[u] =\
    \ 0;\n    for (int v : adj[u]) {\n        if (v == fu) continue;\n\n        dfs1(v,\
    \ u);\n        f[u] = max(f[u], f[v] + 1);\n    }\n}\n\n// compute g[u], using\
    \ reroot tree DP\nvoid dfs2(int u, int fu) {\n    // prefix and suffix max, for\
    \ f(children(u))\n    vector<int> left, right;\n    for (int v : adj[u]) {\n \
    \       if (v == fu) {\n            left.push_back(g[u]);\n        } else {\n\
    \            left.push_back(f[v] + 1);\n        }\n    }\n    right = left;\n\
    \    for (int i = 1; i < SZ(left); i++) {\n        left[i] = max(left[i-1], left[i]);\n\
    \    }\n    for (int i = SZ(right) - 2; i >= 0; i--) {\n        right[i] = max(right[i+1],\
    \ right[i]);\n    }\n\n    // compute g(children)\n    REP(i,SZ(adj[u])) {\n \
    \       int v = adj[u][i];\n        if (v == fu) continue;\n\n        // v ->\
    \ u\n        g[v] = 1;\n        // v -> u -> left of v\n        if (i > 0) g[v]\
    \ = max(g[v], left[i-1] + 1);\n        if (i+1 < SZ(adj[u])) g[v] = max(g[v],\
    \ right[i+1] + 1);\n\n        dfs2(v, u);\n    }\n}\n\nint main() {\n    // init\
    \ g\n    dfs1(root, -1);\n    dfs2(root, -1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/reroot_tree_dp.cpp
  requiredBy: []
  timestamp: '2021-12-22 01:48:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/reroot_tree_dp.cpp
layout: document
redirect_from:
- /library/DP/reroot_tree_dp.cpp
- /library/DP/reroot_tree_dp.cpp.html
title: DP/reroot_tree_dp.cpp
---
