---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/HeavyLight_adamant.h
    title: DataStructure/HeavyLight_adamant.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"DataStructure/test/hld_lca_aizu.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\n\n#line\
    \ 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b);\
    \ i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a)\
    \ for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x)\
    \ { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a\
    \ << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n)\
    \ { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define\
    \ sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n// Copied from\
    \ https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\ntemplate<class\
    \ U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {\n   \
    \ return out << '(' << p.first << \", \" << p.second << ')';\n}\n\ntemplate<class\
    \ Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
    \ string>::value, ostream&>::type\noperator << (ostream& out, const Con& con)\
    \ {\n    out << '{';\n    for (auto beg = con.begin(), it = beg; it != con.end();\
    \ it++) {\n        out << (it == beg ? \"\" : \", \") << *it;\n    }\n    return\
    \ out << '}';\n}\ntemplate<size_t i, class T> ostream& print_tuple_utils(ostream&\
    \ out, const T& tup) {\n    if constexpr(i == tuple_size<T>::value) return out\
    \ << \")\"; \n    else return print_tuple_utils<i + 1, T>(out << (i ? \", \" :\
    \ \"(\") << get<i>(tup), tup); \n}\ntemplate<class ...U> ostream& operator <<\
    \ (ostream& out, const tuple<U...>& t) {\n    return print_tuple_utils<0, tuple<U...>>(out,\
    \ t);\n}\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r) {\n    return uniform_int_distribution<long long>\
    \ (0, r-1)(rng);\n}\n\nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    solve();\n    return 0;\n}\n#line 1 \"DataStructure/HeavyLight_adamant.h\"\
    \n// HeavyLight\n// Index from 0\n// Best used with SegTree.h\n//\n// Usage:\n\
    // HLD hld(g, root);\n// // build segment tree. Note that we must use hld.order[i]\n\
    // vector<T> nodes;\n// for (int i = 0; i < n; i++)\n//   nodes.push_back(initial_value[hld.order[i]])\n\
    // SegTree<S, op, e> st(nodes);\n//\n// // Update path\n// hld.apply_path(from,\
    \ to, is_edge_or_vertex, [&] (int l, int r) {\n//   st.apply(l, r+1, F);\n// });\n\
    //\n// // Query path\n// hld.prod_path_commutative<S, op, e> (from, to, is_edge_or_vertex,\
    \ [&] (int l, int r) {\n//   return st.prod(l, r+1);\n// });\n//\n// Tested:\n\
    // - (vertex, path) https://judge.yosupo.jp/problem/vertex_add_path_sum\n// -\
    \ (vertex, path, non-commutative) https://judge.yosupo.jp/problem/vertex_set_path_composite\n\
    // - (vertex, subtree) https://judge.yosupo.jp/problem/vertex_add_subtree_sum\n\
    // - (vertex, path, non-commutative, 1-index) https://oj.vnoi.info/problem/icpc21_mt_l\n\
    // - (vertex, path) https://oj.vnoi.info/problem/qtree3\n//\n// - (edge, path)\
    \ https://oj.vnoi.info/problem/qtreex\n// - (edge, path) https://oj.vnoi.info/problem/lubenica\n\
    // - (edge, path) https://oj.vnoi.info/problem/pwalk\n// - (edge, path, lazy)\
    \ https://oj.vnoi.info/problem/kbuild\n// - (edge, path, lazy) https://oj.vnoi.info/problem/onbridge\n\
    //\n// - (lca) https://oj.vnoi.info/problem/fselect\n// - (kth_parent) https://cses.fi/problemset/task/1687\n\
    struct HLD {\n    HLD(const vector<vector<int>>& _g, int root)\n            :\
    \ n(_g.size()), g(_g),\n            parent(n), depth(n), sz(n),\n            dfs_number(0),\
    \ nxt(n), in(n), out(n), order(n)\n    {\n        assert(0 <= root && root < n);\n\
    \n        // init parent, depth, sz\n        // also move most heavy child of\
    \ u to g[u][0]\n        depth[root] = 0;\n        dfs_sz(root, -1);\n\n      \
    \  // init nxt, in, out\n        nxt[root] = root;\n        dfs_hld(root);\n \
    \   }\n\n    int lca(int u, int v) const {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        while (true) {\n            if (in[u]\
    \ > in[v]) swap(u, v); // in[u] <= in[v]\n            if (nxt[u] == nxt[v]) return\
    \ u;\n            v = parent[nxt[v]];\n        }\n    }\n\n    // return k-th\
    \ parent\n    // if no such parent -> return -1\n    int kth_parent(int u, int\
    \ k) const {\n        assert(0 <= u && u < n);\n        if (depth[u] < k) return\
    \ -1;\n\n        while (true) {\n            int v = nxt[u];\n            if (in[u]\
    \ - k >= in[v]) return order[in[u] - k];\n            k -= in[u] - in[v] + 1;\n\
    \            u = parent[v];\n        }\n    }\n\n    int dist(int u, int v) const\
    \ {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n    \
    \    int l = lca(u, v);\n        return depth[u] + depth[v] - 2*depth[l];\n  \
    \  }\n\n    // apply f on vertices on path [u, v]\n    // edge = true -> apply\
    \ on edge\n    //\n    // f(l, r) should update segment tree [l, r] INCLUSIVE\n\
    \    void apply_path(int u, int v, bool edge, const function<void(int, int)> &f)\
    \ {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n    \
    \    if (u == v && edge) return;\n\n        while (true) {\n            if (in[u]\
    \ > in[v]) swap(u, v); // in[u] <= in[v]\n            if (nxt[u] == nxt[v]) break;\n\
    \            f(in[nxt[v]], in[v]);\n            v = parent[nxt[v]];\n        }\n\
    \        if (u == v && edge) return;\n        f(in[u] + edge, in[v]);\n    }\n\
    \n    // get prod of path u -> v\n    // edge = true -> get on edges\n    //\n\
    \    // f(l, r) should query segment tree [l, r] INCLUSIVE\n    // f must be commutative.\
    \ For non-commutative, use getSegments below\n    template<class S, S (*op) (S,\
    \ S), S (*e)()>\n    S prod_path_commutative(\n            int u, int v, bool\
    \ edge,\n            const function<S(int, int)>& f) const {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        if (u == v && edge)\
    \ {\n            return e();\n        }\n        S su = e(), sv = e();\n     \
    \   while (true) {\n            if (in[u] > in[v]) { swap(u, v); swap(su, sv);\
    \ }\n            if (nxt[u] == nxt[v]) break;\n            sv = op(sv, f(in[nxt[v]],\
    \ in[v]));\n            v = parent[nxt[v]];\n        }\n        if (u == v &&\
    \ edge) {\n            return op(su, sv);\n        } else {\n            return\
    \ op(su, op(sv, f(in[u] + edge, in[v])));\n        }\n    }\n\n    // f(l, r)\
    \ modify seg_tree [l, r] INCLUSIVE\n    void apply_subtree(int u, bool edge, const\
    \ function<void(int, int)>& f) {\n        assert(0 <= u && u < n);\n        f(in[u]\
    \ + edge, out[u] - 1);\n    }\n\n    // f(l, r) queries seg_tree [l, r] INCLUSIVE\n\
    \    template<class S>\n    S prod_subtree_commutative(int u, bool edge, const\
    \ function<S(S, S)>& f) {\n        assert(0 <= u && u < n);\n        return f(in[u]\
    \ + edge, out[u] - 1);\n    }\n\n    // Useful when functions are non-commutative\n\
    \    // Return all segments on path from u -> v\n    // For this problem, the\
    \ order (u -> v is different from v -> u)\n    vector< pair<int,int> > getSegments(int\
    \ u, int v) const {\n        assert(0 <= u && u < n);\n        assert(0 <= v &&\
    \ v < n);\n        vector< pair<int,int> > upFromU, upFromV;\n\n        int fu\
    \ = nxt[u], fv = nxt[v];\n        while (fu != fv) {  // u and v are on different\
    \ chains\n            if (depth[fu] >= depth[fv]) { // move u up\n           \
    \     upFromU.push_back({u, fu});\n                u = parent[fu];\n         \
    \       fu = nxt[u];\n            } else { // move v up\n                upFromV.push_back({fv,\
    \ v});\n                v = parent[fv];\n                fv = nxt[v];\n      \
    \      }\n        }\n        upFromU.push_back({u, v});\n        reverse(upFromV.begin(),\
    \ upFromV.end());\n        upFromU.insert(upFromU.end(), upFromV.begin(), upFromV.end());\n\
    \        return upFromU;\n    }\n\n    // return true if u is ancestor\n    bool\
    \ isAncestor(int u, int v) {\n        return in[u] <= in[v] && out[v] <= out[u];\n\
    \    }\n\n// private:\n    int n;\n    vector<vector<int>> g;\n    vector<int>\
    \ parent;   // par[u] = parent of u. par[root] = -1\n    vector<int> depth;  \
    \  // depth[u] = distance from root -> u\n    vector<int> sz;       // sz[u] =\
    \ size of subtree rooted at u\n    int dfs_number;\n    vector<int> nxt;     \
    \ // nxt[u] = vertex on heavy path of u, nearest to root\n    vector<int> in,\
    \ out;  // subtree(u) is in range [in[u], out[u]-1]\n    vector<int> order;  \
    \  // euler tour\n\n    void dfs_sz(int u, int fu) {\n        parent[u] = fu;\n\
    \        sz[u] = 1;\n        // remove parent from adjacency list\n        auto\
    \ it = std::find(g[u].begin(), g[u].end(), fu);\n        if (it != g[u].end())\
    \ g[u].erase(it);\n\n        for (int& v : g[u]) {\n            depth[v] = depth[u]\
    \ + 1;\n            dfs_sz(v, u);\n\n            sz[u] += sz[v];\n           \
    \ if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);\n        }\n    }\n\n    void dfs_hld(int\
    \ u) {\n        order[dfs_number] = u;\n        in[u] = dfs_number++;\n\n    \
    \    for (int v : g[u]) {\n            nxt[v] = (v == g[u][0] ? nxt[u] : v);\n\
    \            dfs_hld(v);\n        }\n        out[u] = dfs_number;\n    }\n};\n\
    #line 5 \"DataStructure/test/hld_lca_aizu.test.cpp\"\n\nvoid solve() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n; cin >> n;\n    vector<vector<int>> adj(n);\n    REP(i,n)\
    \ {\n        int k; cin >> k;\n        while (k--) {\n            int j; cin >>\
    \ j;\n            adj[i].push_back(j);\n            adj[j].push_back(i);\n   \
    \     }\n    }\n\n    HLD hld(adj, 0);\n\n    int q; cin >> q;\n    while (q--)\
    \ {\n        int u, v; cin >> u >> v;\n        cout << hld.lca(u, v) << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include \"../../template.h\"\n#include \"../HeavyLight_adamant.h\"\n\nvoid\
    \ solve() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n; cin >> n;\n\
    \    vector<vector<int>> adj(n);\n    REP(i,n) {\n        int k; cin >> k;\n \
    \       while (k--) {\n            int j; cin >> j;\n            adj[i].push_back(j);\n\
    \            adj[j].push_back(i);\n        }\n    }\n\n    HLD hld(adj, 0);\n\n\
    \    int q; cin >> q;\n    while (q--) {\n        int u, v; cin >> u >> v;\n \
    \       cout << hld.lca(u, v) << '\\n';\n    }\n}\n"
  dependsOn:
  - template.h
  - DataStructure/HeavyLight_adamant.h
  isVerificationFile: true
  path: DataStructure/test/hld_lca_aizu.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 19:24:58+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/hld_lca_aizu.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/hld_lca_aizu.test.cpp
- /verify/DataStructure/test/hld_lca_aizu.test.cpp.html
title: DataStructure/test/hld_lca_aizu.test.cpp
---
