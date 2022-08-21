---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LinkCutTree.h
    title: DataStructure/LinkCutTree.h
  - icon: ':heavy_check_mark:'
    path: Math/modulo_anta.h
    title: Math/modulo_anta.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "#line 1 \"DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Math/modulo_anta.h\"\
    \n// Modified from anta's code\n// Not tested with MOD > 10^9 + 7.\n// Slow?\n\
    //\n// Tested:\n// - https://codeforces.com/gym/101383 - F (MOD = 1e9+7, +, *)\n\
    \n// ??? somehow this is 2.5x slower on https://judge.yosupo.jp/problem/matrix_product\n\
    inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d,\
    \ unsigned &out_m) {\n    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x,\
    \ d, m;\n#ifdef __GNUC__\n    asm(\n        \"divl %4; \\n\\t\"\n        : \"\
    =a\" (d), \"=d\" (m)\n        : \"d\" (xh), \"a\" (xl), \"r\" (y)\n    );\n#else\n\
    \    __asm {\n        mov edx, dword ptr[xh];\n        mov eax, dword ptr[xl];\n\
    \        div dword ptr[y];\n        mov dword ptr[d], eax;\n        mov dword\
    \ ptr[m], edx;\n    };\n#endif\n    out_d = d; out_m = m;\n}\n\ntemplate<int MOD>\n\
    struct ModInt {\n    unsigned x;\n\n    constexpr ModInt() : x(0) { }\n    constexpr\
    \ ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD;\
    \ x = sigt; }\n\n#define COMPAREOP(OP) bool constexpr operator OP(ModInt b) const\
    \ { return x OP b.x; }\n    COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>)\
    \ COMPAREOP(<=) COMPAREOP(>=)\n#undef COMPAREOP\n\n    ModInt operator-() const\
    \ { return ModInt(x ? MOD - x : 0); }\n\n    ModInt constexpr& operator+=(ModInt\
    \ that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }\n    ModInt constexpr&\
    \ operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this;\
    \ }\n    ModInt &operator*=(ModInt that) {\n        unsigned dummy;\n        fasterLLDivMod((unsigned\
    \ long long)x * that.x, MOD, dummy, x);\n        return *this;\n    }\n    ModInt\
    \ operator*(ModInt that) const {\n        ModInt res;\n        unsigned dummy;\n\
    \        fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, res.x);\n\
    \        return res;\n    }\n    ModInt operator+(ModInt that) const { return\
    \ ModInt(*this) += that; }\n    ModInt operator-(ModInt that) const { return ModInt(*this)\
    \ -= that; }\n\n    // Below: copied from user202729_, not tested.\n    ModInt\
    \ inv() const {\n        int a = x, b = MOD, ax = 1, bx = 0;\n        while (b)\
    \ {\n            int q = a/b, t = a%b;\n            a = b; b = t;\n          \
    \  t = ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a ==\
    \ 1);\n        if (ax < 0) ax += MOD;\n        return ax;\n    }\n    ModInt&\
    \ operator /= (ModInt m) { return (*this) *= m.inv(); }\n    ModInt operator /\
    \ (ModInt that) const { return ModInt(*this) /= that; }\n};\n\ntemplate<int MOD>\n\
    ModInt<MOD> power(ModInt<MOD> n, long long k) {\n    if (k == 0) return ModInt<MOD>\
    \ (1);\n    ModInt<MOD> res(1);\n    while (k > 0) {\n        if (k & 1) res =\
    \ res * n;\n        n = n * n;\n        k >>= 1;\n    }\n    return res;\n}\n\n\
    template<int MOD>\nstd::ostream& operator << (std::ostream& cout, const ModInt<MOD>&\
    \ m) {\n    cout << m.x;\n    return cout;\n}\ntemplate<int MOD>\nstd::istream&\
    \ operator >> (std::istream& cin, ModInt<MOD>& m) {\n    cin >> m.x;\n    return\
    \ cin;\n}\n\n/* Example:\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\
    */\n#line 7 \"DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp\"\
    \nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\n#define PATH_QUERIES_ONLY\nstruct T {\n    modular a, b;\n\n    T() : a(1),\
    \ b(0) {}\n    T(modular _a, modular _b) : a(_a), b(_b) {}\n\n    // return f(g())\n\
    \    T operator + (const T& g) const {\n        return T {\n            a * g.a,\n\
    \            a * g.b + b,\n        };\n    }\n\n    T operator += (const T& g)\
    \ {\n        b = a * g.b + b;\n        a = a * g.a;\n        return *this;\n \
    \   }\n};\n#line 1 \"DataStructure/LinkCutTree.h\"\n// Link Cut Tree; copied from\
    \ https://codeforces.com/blog/entry/75885\n// - Index from 1\n// - T needs to\
    \ support + operation\n//   For subtree queries -> requires - operation\n//  \
    \ --> see this comment for how to handle it: https://codeforces.com/blog/entry/67637?#comment-650424\n\
    // - Not using template here, since inheritance becomes very ugly\n// - Doesn't\
    \ support lazy update (so no subtree updates)\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum\n\
    // - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\n\
    // - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\n\n//\
    \ Add this for path queries only\n// #define PATH_QUERIES_ONLY\n\n// TODO: Specify\
    \ T\n// using T = long long;\nstruct SplayTree { // can we replace SplayTreeById\
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
    \     pushUp(x);\n    }\n};\n\nstruct LinkCut : SplayTree {\n    LinkCut(int n)\
    \ : SplayTree(n) {}\n\n    void link(int u, int v) {\n        reroot(u);\n   \
    \     access(v);\n\n        nodes[v].vir += nodes[u].sub;\n        nodes[u].parent\
    \ = v;\n        pushUp(v);\n    }\n\n    void cut(int u, int v) {\n        reroot(u);\n\
    \        access(v);\n\n        nodes[v].child[0] = nodes[u].parent = 0;\n    \
    \    pushUp(v);\n    }\n\n    T getPath(int u, int v) {\n        reroot(u);\n\
    \        access(v);\n        return nodes[v].path[1];\n    }\n\n    void set(int\
    \ u, T val) {\n        access(u);\n        nodes[u].self = val;\n        pushUp(u);\n\
    \    }\n\n    T get(int u) {\n        return nodes[u].self;\n    }\n\n    // Get\
    \ aggregate of subtree(u). v is parent of u. There must exist edge(v, u) (?)\n\
    \    T getSubtree(int u, int v) {\n        reroot(v); access(u);\n        return\
    \ nodes[u].vir + nodes[u].self;\n    }\n\n// private:\n    void reroot(int x)\
    \ {\n        access(x);\n        nodes[x].reverse ^= 1;\n        pushDown(x);\n\
    \    }\n\n    int access(int x) {\n        int u = x, v = 0;\n        for (; u;\
    \ v = u, u = nodes[u].parent) {\n            splay(u);\n            int& ov =\
    \ nodes[u].child[1];\n            nodes[u].vir += nodes[ov].sub;\n#ifndef PATH_QUERIES_ONLY\n\
    \            // T requires subtract for subtree queries\n            nodes[u].vir\
    \ -= nodes[v].sub;\n#endif\n\n            ov = v; pushUp(u);\n        }\n    \
    \    return splay(x), v;\n    }\n};\n\n// Example for custom type: // https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\n\
    // Since T doesn't support subtract -> comment out line\n//   nodes[u].vir -=\
    \ nodes[v].sub\n/**\nstruct T {\n    modular a, b;\n\n    T() : a(1), b(0) {}\n\
    \    T(modular _a, modular _b) : a(_a), b(_b) {}\n\n    // return f(g())\n   \
    \ T operator + (const T& g) const {\n        return T {\n            a * g.a,\n\
    \            a * g.b + b,\n        };\n    }\n\n    T operator += (const T& g)\
    \ {\n        b = a * g.b + b;\n        a = a * g.a;\n        return *this;\n \
    \   }\n};\n*/\n#line 39 \"DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp\"\
    \n\n#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n#define\
    \ REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main() {\n \
    \   ios::sync_with_stdio(0); cin.tie(0);\n\n    int n, q; cin >> n >> q;\n   \
    \ LinkCut tree(n);\n\n    FOR(i,1,n) {\n        modular a, b; cin >> a >> b;\n\
    \        tree.set(i, T{a, b});\n    }\n\n    REP(i,n-1) {\n        int u, v; cin\
    \ >> u >> v;\n        ++u; ++v;\n        tree.link(u, v);\n    }\n\n    while\
    \ (q--) {\n        int typ; cin >> typ;\n        if (typ == 0) {  // remove (u,\
    \ v), add (w, x)\n            int u, v, w, x; cin >> u >> v >> w >> x;\n     \
    \       ++u; ++v;\n            ++w; ++x;\n            tree.cut(u, v);\n      \
    \      tree.link(w, x);\n        } else if (typ == 1) {  // set f(p) = cx + d\n\
    \            int p; cin >> p;\n            ++p;\n            modular c, d; cin\
    \ >> c >> d;\n            tree.set(p, T{c, d});\n        } else if (typ == 2)\
    \ {  // get path (u, v) and apply f(x)\n            int u, v; cin >> u >> v;\n\
    \            ++u; ++v;\n            modular x; cin >> x;\n\n            auto f\
    \ = tree.getPath(u, v);\n            cout << f.a * x + f.b << '\\n';\n       \
    \ }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../Math/modulo_anta.h\"\
    \nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\n#define PATH_QUERIES_ONLY\nstruct T {\n    modular a, b;\n\n    T() : a(1),\
    \ b(0) {}\n    T(modular _a, modular _b) : a(_a), b(_b) {}\n\n    // return f(g())\n\
    \    T operator + (const T& g) const {\n        return T {\n            a * g.a,\n\
    \            a * g.b + b,\n        };\n    }\n\n    T operator += (const T& g)\
    \ {\n        b = a * g.b + b;\n        a = a * g.a;\n        return *this;\n \
    \   }\n};\n#include \"../LinkCutTree.h\"\n\n#define FOR(i, a, b) for (int i =\
    \ (a), _##i = (b); i <= _##i; ++i)\n#define REP(i, a) for (int i = 0, _##i = (a);\
    \ i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \n    int n, q; cin >> n >> q;\n    LinkCut tree(n);\n\n    FOR(i,1,n) {\n   \
    \     modular a, b; cin >> a >> b;\n        tree.set(i, T{a, b});\n    }\n\n \
    \   REP(i,n-1) {\n        int u, v; cin >> u >> v;\n        ++u; ++v;\n      \
    \  tree.link(u, v);\n    }\n\n    while (q--) {\n        int typ; cin >> typ;\n\
    \        if (typ == 0) {  // remove (u, v), add (w, x)\n            int u, v,\
    \ w, x; cin >> u >> v >> w >> x;\n            ++u; ++v;\n            ++w; ++x;\n\
    \            tree.cut(u, v);\n            tree.link(w, x);\n        } else if\
    \ (typ == 1) {  // set f(p) = cx + d\n            int p; cin >> p;\n         \
    \   ++p;\n            modular c, d; cin >> c >> d;\n            tree.set(p, T{c,\
    \ d});\n        } else if (typ == 2) {  // get path (u, v) and apply f(x)\n  \
    \          int u, v; cin >> u >> v;\n            ++u; ++v;\n            modular\
    \ x; cin >> x;\n\n            auto f = tree.getPath(u, v);\n            cout <<\
    \ f.a * x + f.b << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - Math/modulo_anta.h
  - DataStructure/LinkCutTree.h
  isVerificationFile: true
  path: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
  requiredBy: []
  timestamp: '2022-08-21 18:30:35+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
- /verify/DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp.html
title: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
---
