---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/link_cut_tree_addpathsum.test.cpp
    title: DataStructure/test/link_cut_tree_addpathsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/link_cut_tree_vertexaddsubtreesum.test.cpp
    title: DataStructure/test/link_cut_tree_vertexaddsubtreesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
    title: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/67637?#comment-650424
    - https://codeforces.com/blog/entry/75885
    - https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    - https://oj.vnoi.info/problem/icpc22_mn_b
    - https://www.spoj.com/problems/DYNACON1/
  bundledCode: "#line 1 \"DataStructure/LinkCutTree.h\"\n// copied from https://codeforces.com/blog/entry/75885\n\
    // - Index from 1\n// - T needs to support + operation\n//   For subtree queries\
    \ -> requires - operation\n//   --> see this comment for how to handle it: https://codeforces.com/blog/entry/67637?#comment-650424\n\
    // - Not using template here, since inheritance becomes very ugly\n// - Doesn't\
    \ support lazy update (so no subtree updates)\n// - For query on *edge* weights\
    \ (instead of vertex weights)\n//   --> for each edge, add a new node in LinkCut\
    \ tree.\n//       See https://oj.vnoi.info/problem/icpc22_mn_b for example\n//\n\
    // Tested:\n// - https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum\n\
    // - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\n\
    // - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\n// -\
    \ (edge weights) https://oj.vnoi.info/problem/icpc22_mn_b\n// - (link, cut, connected)\
    \ https://www.spoj.com/problems/DYNACON1/\n\n// Add this for path queries only\n\
    // #define PATH_QUERIES_ONLY\n\n// TODO: Specify T\n// using T = long long;\n\
    // Link Cut Tree {{{\n// SplayTree {{{\nstruct SplayTree { // can we replace SplayTreeById\
    \ and use this only?\n    struct Node {\n        array<int, 2> child = {0, 0};\n\
    \        int parent = 0;\n\n        // Path aggregates\n        // - path[0] =\
    \ go from left -> right\n        // - path[1] = go from right -> left\n      \
    \  array<T, 2> path;  // default to T constructor\n        T self;\n\n       \
    \ // Subtree aggregates\n        T sub, vir;\n\n        bool reverse = false;\n\
    \    };\n    vector<Node> nodes;\n\n    SplayTree(int n) : nodes(n + 1) {}\n\n\
    \    void splay(int x) {\n        for (pushDown(x); ~getDirection(x); ) {\n  \
    \          int y = nodes[x].parent;\n            int z = nodes[y].parent;\n  \
    \          pushDown(z);\n            pushDown(y);\n            pushDown(x);\n\
    \            int dx = getDirection(x);\n            int dy = getDirection(y);\n\
    \            if (~dy) rotate(dx != dy ? x : y);\n            rotate(x);\n    \
    \    }\n    }\n\n// private:\n    // Return t where nodes[parent(x)].child[t]\
    \ == x\n    int getDirection(int x) {\n        int p = nodes[x].parent;\n    \
    \    if (!p) return -1;\n        return nodes[p].child[0] == x ? 0 : nodes[p].child[1]\
    \ == x ? 1 : -1;\n    }\n\n    /**\n     * Before:\n     *    z\n     *    |\n\
    \     *    y\n     *   /\n     *  x\n     *   \\\n     *   xchild\n     * \n \
    \    * After:\n     *    z\n     *    |\n     *    x\n     *     \\\n     *  \
    \    y\n     *     /\n     *   xchild\n     */\n    void rotate(int x) {\n   \
    \     int y = nodes[x].parent, dx = getDirection(x);\n        int z = nodes[y].parent,\
    \ dy = getDirection(y);\n\n        setChild(y, nodes[x].child[!dx], dx);\n   \
    \     setChild(x, y, !dx);\n        if (~dy) setChild(z, x, dy);\n        nodes[x].parent\
    \ = z;\n    }\n\n    void pushDown(int x) {\n        if (!x) return;\n       \
    \ if (nodes[x].reverse) {\n            auto [l, r] = nodes[x].child;\n       \
    \     nodes[l].reverse ^= 1;\n            nodes[r].reverse ^= 1;\n\n         \
    \   swap(nodes[x].child[0], nodes[x].child[1]);\n            swap(nodes[x].path[0],\
    \ nodes[x].path[1]);\n            nodes[x].reverse = false;\n        }\n    }\n\
    \n    void pushUp(int x) {\n        auto [l, r] = nodes[x].child;\n        pushDown(l);\
    \ pushDown(r);\n\n        nodes[x].path[0] = nodes[l].path[0] + nodes[x].self\
    \ + nodes[r].path[0];\n        nodes[x].path[1] = nodes[r].path[1] + nodes[x].self\
    \ + nodes[l].path[1];\n\n        nodes[x].sub = nodes[x].vir + nodes[l].sub +\
    \ nodes[r].sub + nodes[x].self;\n    }\n\n    void setChild(int x, int y, int\
    \ dir) {\n        nodes[x].child[dir] = y;\n        nodes[y].parent = x;\n   \
    \     pushUp(x);\n    }\n};\n// }}}\n\nstruct LinkCut : SplayTree {\n    LinkCut(int\
    \ n) : SplayTree(n) {}\n\n    bool is_connected(int u, int v) {\n        return\
    \ LCA(u, v) > 0;\n    }\n\n    void link(int u, int v) {\n        reroot(u);\n\
    \        access(v);\n\n        nodes[v].vir = nodes[v].vir + nodes[u].sub;\n \
    \       nodes[u].parent = v;\n        pushUp(v);\n    }\n\n    void cut(int u,\
    \ int v) {\n        reroot(u);\n        access(v);\n\n        nodes[v].child[0]\
    \ = nodes[u].parent = 0;\n        pushUp(v);\n    }\n\n    // Returns 0 if u and\
    \ v are not connected\n    int LCA(int u, int v) {\n        if (u == v) return\
    \ u;\n        access(u);\n        int ret = access(v);\n        return nodes[u].parent\
    \ ? ret : 0;\n    }\n\n    T getPath(int u, int v) {\n        reroot(u);\n   \
    \     access(v);\n        return nodes[v].path[1];\n    }\n\n    void set(int\
    \ u, T val) {\n        access(u);\n        nodes[u].self = val;\n        pushUp(u);\n\
    \    }\n\n    T get(int u) {\n        return nodes[u].self;\n    }\n\n    // Get\
    \ aggregate of subtree(u). v is parent of u. There must exist edge(v, u) (?)\n\
    \    T getSubtree(int u, int v) {\n        reroot(v); access(u);\n        return\
    \ nodes[u].vir + nodes[u].self;\n    }\n\n// private:\n    void reroot(int x)\
    \ {\n        access(x);\n        nodes[x].reverse ^= 1;\n        pushDown(x);\n\
    \    }\n\n    int access(int x) {\n        int u = x, v = 0;\n        for (; u;\
    \ v = u, u = nodes[u].parent) {\n            splay(u);\n            int& ov =\
    \ nodes[u].child[1];\n            nodes[u].vir = nodes[u].vir + nodes[ov].sub;\n\
    #ifndef PATH_QUERIES_ONLY\n            // T requires subtract for subtree queries\n\
    \            nodes[u].vir -= nodes[v].sub;\n#endif\n\n            ov = v; pushUp(u);\n\
    \        }\n        return splay(x), v;\n    }\n};\n// }}}\n\n// Example for custom\
    \ type: // https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\
    \ {{{\n// Since T doesn't support subtract -> comment out line\n//   nodes[u].vir\
    \ -= nodes[v].sub\n/**\nstruct T {\n    modular a, b;\n\n    T() : a(1), b(0)\
    \ {}\n    T(modular _a, modular _b) : a(_a), b(_b) {}\n\n    // return f(g())\n\
    \    T operator + (const T& g) const {\n        return T {\n            a * g.a,\n\
    \            a * g.b + b,\n        };\n    }\n\n    T operator += (const T& g)\
    \ {\n        b = a * g.b + b;\n        a = a * g.a;\n        return *this;\n \
    \   }\n};\n*/\n// }}}\n"
  code: "// copied from https://codeforces.com/blog/entry/75885\n// - Index from 1\n\
    // - T needs to support + operation\n//   For subtree queries -> requires - operation\n\
    //   --> see this comment for how to handle it: https://codeforces.com/blog/entry/67637?#comment-650424\n\
    // - Not using template here, since inheritance becomes very ugly\n// - Doesn't\
    \ support lazy update (so no subtree updates)\n// - For query on *edge* weights\
    \ (instead of vertex weights)\n//   --> for each edge, add a new node in LinkCut\
    \ tree.\n//       See https://oj.vnoi.info/problem/icpc22_mn_b for example\n//\n\
    // Tested:\n// - https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum\n\
    // - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\n\
    // - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\n// -\
    \ (edge weights) https://oj.vnoi.info/problem/icpc22_mn_b\n// - (link, cut, connected)\
    \ https://www.spoj.com/problems/DYNACON1/\n\n// Add this for path queries only\n\
    // #define PATH_QUERIES_ONLY\n\n// TODO: Specify T\n// using T = long long;\n\
    // Link Cut Tree {{{\n// SplayTree {{{\nstruct SplayTree { // can we replace SplayTreeById\
    \ and use this only?\n    struct Node {\n        array<int, 2> child = {0, 0};\n\
    \        int parent = 0;\n\n        // Path aggregates\n        // - path[0] =\
    \ go from left -> right\n        // - path[1] = go from right -> left\n      \
    \  array<T, 2> path;  // default to T constructor\n        T self;\n\n       \
    \ // Subtree aggregates\n        T sub, vir;\n\n        bool reverse = false;\n\
    \    };\n    vector<Node> nodes;\n\n    SplayTree(int n) : nodes(n + 1) {}\n\n\
    \    void splay(int x) {\n        for (pushDown(x); ~getDirection(x); ) {\n  \
    \          int y = nodes[x].parent;\n            int z = nodes[y].parent;\n  \
    \          pushDown(z);\n            pushDown(y);\n            pushDown(x);\n\
    \            int dx = getDirection(x);\n            int dy = getDirection(y);\n\
    \            if (~dy) rotate(dx != dy ? x : y);\n            rotate(x);\n    \
    \    }\n    }\n\n// private:\n    // Return t where nodes[parent(x)].child[t]\
    \ == x\n    int getDirection(int x) {\n        int p = nodes[x].parent;\n    \
    \    if (!p) return -1;\n        return nodes[p].child[0] == x ? 0 : nodes[p].child[1]\
    \ == x ? 1 : -1;\n    }\n\n    /**\n     * Before:\n     *    z\n     *    |\n\
    \     *    y\n     *   /\n     *  x\n     *   \\\n     *   xchild\n     * \n \
    \    * After:\n     *    z\n     *    |\n     *    x\n     *     \\\n     *  \
    \    y\n     *     /\n     *   xchild\n     */\n    void rotate(int x) {\n   \
    \     int y = nodes[x].parent, dx = getDirection(x);\n        int z = nodes[y].parent,\
    \ dy = getDirection(y);\n\n        setChild(y, nodes[x].child[!dx], dx);\n   \
    \     setChild(x, y, !dx);\n        if (~dy) setChild(z, x, dy);\n        nodes[x].parent\
    \ = z;\n    }\n\n    void pushDown(int x) {\n        if (!x) return;\n       \
    \ if (nodes[x].reverse) {\n            auto [l, r] = nodes[x].child;\n       \
    \     nodes[l].reverse ^= 1;\n            nodes[r].reverse ^= 1;\n\n         \
    \   swap(nodes[x].child[0], nodes[x].child[1]);\n            swap(nodes[x].path[0],\
    \ nodes[x].path[1]);\n            nodes[x].reverse = false;\n        }\n    }\n\
    \n    void pushUp(int x) {\n        auto [l, r] = nodes[x].child;\n        pushDown(l);\
    \ pushDown(r);\n\n        nodes[x].path[0] = nodes[l].path[0] + nodes[x].self\
    \ + nodes[r].path[0];\n        nodes[x].path[1] = nodes[r].path[1] + nodes[x].self\
    \ + nodes[l].path[1];\n\n        nodes[x].sub = nodes[x].vir + nodes[l].sub +\
    \ nodes[r].sub + nodes[x].self;\n    }\n\n    void setChild(int x, int y, int\
    \ dir) {\n        nodes[x].child[dir] = y;\n        nodes[y].parent = x;\n   \
    \     pushUp(x);\n    }\n};\n// }}}\n\nstruct LinkCut : SplayTree {\n    LinkCut(int\
    \ n) : SplayTree(n) {}\n\n    bool is_connected(int u, int v) {\n        return\
    \ LCA(u, v) > 0;\n    }\n\n    void link(int u, int v) {\n        reroot(u);\n\
    \        access(v);\n\n        nodes[v].vir = nodes[v].vir + nodes[u].sub;\n \
    \       nodes[u].parent = v;\n        pushUp(v);\n    }\n\n    void cut(int u,\
    \ int v) {\n        reroot(u);\n        access(v);\n\n        nodes[v].child[0]\
    \ = nodes[u].parent = 0;\n        pushUp(v);\n    }\n\n    // Returns 0 if u and\
    \ v are not connected\n    int LCA(int u, int v) {\n        if (u == v) return\
    \ u;\n        access(u);\n        int ret = access(v);\n        return nodes[u].parent\
    \ ? ret : 0;\n    }\n\n    T getPath(int u, int v) {\n        reroot(u);\n   \
    \     access(v);\n        return nodes[v].path[1];\n    }\n\n    void set(int\
    \ u, T val) {\n        access(u);\n        nodes[u].self = val;\n        pushUp(u);\n\
    \    }\n\n    T get(int u) {\n        return nodes[u].self;\n    }\n\n    // Get\
    \ aggregate of subtree(u). v is parent of u. There must exist edge(v, u) (?)\n\
    \    T getSubtree(int u, int v) {\n        reroot(v); access(u);\n        return\
    \ nodes[u].vir + nodes[u].self;\n    }\n\n// private:\n    void reroot(int x)\
    \ {\n        access(x);\n        nodes[x].reverse ^= 1;\n        pushDown(x);\n\
    \    }\n\n    int access(int x) {\n        int u = x, v = 0;\n        for (; u;\
    \ v = u, u = nodes[u].parent) {\n            splay(u);\n            int& ov =\
    \ nodes[u].child[1];\n            nodes[u].vir = nodes[u].vir + nodes[ov].sub;\n\
    #ifndef PATH_QUERIES_ONLY\n            // T requires subtract for subtree queries\n\
    \            nodes[u].vir -= nodes[v].sub;\n#endif\n\n            ov = v; pushUp(u);\n\
    \        }\n        return splay(x), v;\n    }\n};\n// }}}\n\n// Example for custom\
    \ type: // https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\
    \ {{{\n// Since T doesn't support subtract -> comment out line\n//   nodes[u].vir\
    \ -= nodes[v].sub\n/**\nstruct T {\n    modular a, b;\n\n    T() : a(1), b(0)\
    \ {}\n    T(modular _a, modular _b) : a(_a), b(_b) {}\n\n    // return f(g())\n\
    \    T operator + (const T& g) const {\n        return T {\n            a * g.a,\n\
    \            a * g.b + b,\n        };\n    }\n\n    T operator += (const T& g)\
    \ {\n        b = a * g.b + b;\n        a = a * g.a;\n        return *this;\n \
    \   }\n};\n*/\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LinkCutTree.h
  requiredBy: []
  timestamp: '2022-12-24 01:16:58+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/link_cut_tree_vertexaddsubtreesum.test.cpp
  - DataStructure/test/link_cut_tree_addpathsum.test.cpp
  - DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
documentation_of: DataStructure/LinkCutTree.h
layout: document
redirect_from:
- /library/DataStructure/LinkCutTree.h
- /library/DataStructure/LinkCutTree.h.html
title: DataStructure/LinkCutTree.h
---
