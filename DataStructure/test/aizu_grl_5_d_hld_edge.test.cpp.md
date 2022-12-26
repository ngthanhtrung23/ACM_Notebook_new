---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/HeavyLight_adamant.h
    title: DataStructure/HeavyLight_adamant.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegTree.h
    title: DataStructure/SegTree.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
  bundledCode: "#line 1 \"DataStructure/test/aizu_grl_5_d_hld_edge.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n#line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int\
    \ i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n\
    #define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\
    \n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n)\
    \ { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define\
    \ PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl;\
    \ }\n\n#define sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n//\
    \ Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
    template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>&\
    \ p) {\n    return out << '(' << p.first << \", \" << p.second << ')';\n}\n\n\
    template<class Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
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
    \ (0, r-1)(rng);\n}\n\ntemplate<typename T>\nvector<T> read_vector(int n) {\n\
    \    vector<T> res(n);\n    for (int& x : res) cin >> x;\n    return res;\n}\n\
    \nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n  \
    \  solve();\n    return 0;\n}\n#line 1 \"DataStructure/SegTree.h\"\n// SegTree,\
    \ copied from AtCoder library {{{\n// AtCoder doc: https://atcoder.github.io/ac-library/master/document_en/segtree.html\n\
    //\n// Notes:\n// - Index of elements from 0 -> n-1\n// - Range queries are [l,\
    \ r-1]\n//\n// Tested:\n// - (binary search) https://atcoder.jp/contests/practice2/tasks/practice2_j\n\
    // - https://oj.vnoi.info/problem/gss\n// - https://oj.vnoi.info/problem/nklineup\n\
    // - (max_right & min_left for delete position queries) https://oj.vnoi.info/problem/segtree_itstr\n\
    // - https://judge.yosupo.jp/problem/point_add_range_sum\n// - https://judge.yosupo.jp/problem/point_set_range_composite\n\
    int ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\ntemplate<\n    class T,  // data type for nodes\n\
    \    T (*op) (T, T),  // operator to combine 2 nodes\n    T (*e)() // identity\
    \ element\n>\nstruct SegTree {\n    SegTree() : SegTree(0) {}\n    explicit SegTree(int\
    \ n) : SegTree(vector<T> (n, e())) {}\n    explicit SegTree(const vector<T>& v)\
    \ : _n((int) v.size()) {\n        log = ceil_pow2(_n);\n        size = 1<<log;\n\
    \        d = vector<T> (2*size, e());\n\n        for (int i = 0; i < _n; i++)\
    \ d[size+i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n         \
    \   update(i);\n        }\n    }\n\n    // 0 <= p < n\n    void set(int p, T x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p] = x;\n\
    \        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    // 0 <=\
    \ p < n\n    T get(int p) const {\n        assert(0 <= p && p < _n);\n       \
    \ return d[p + size];\n    }\n\n    // Get product in range [l, r-1]\n    // 0\
    \ <= l <= r <= n\n    // For empty segment (l == r) -> return e()\n    T prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= _n);\n        T sml\
    \ = e(), smr = e();\n        l += size;\n        r += size;\n        while (l\
    \ < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1)\
    \ smr = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n       \
    \ }\n        return op(sml, smr);\n    }\n\n    T all_prod() const {\n       \
    \ return d[1];\n    }\n\n    // Binary search on SegTree to find largest r:\n\
    \    //    f(op(a[l] .. a[r-1])) = true   (assuming empty array is always true)\n\
    \    //    f(op(a[l] .. a[r])) = false    (assuming op(..., a[n]), which is out\
    \ of bound, is always false)\n    template <bool (*f)(T)> int max_right(int l)\
    \ const {\n        return max_right(l, [](T x) { return f(x); });\n    }\n   \
    \ template <class F> int max_right(int l, F f) const {\n        assert(0 <= l\
    \ && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n   \
    \     l += size;\n        T sm = e();\n        do {\n            while (l % 2\
    \ == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while (l\
    \ < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    // Binary search\
    \ on SegTree to find smallest l:\n    //    f(op(a[l] .. a[r-1])) = true     \
    \ (assuming empty array is always true)\n    //    f(op(a[l-1] .. a[r-1])) = false\
    \   (assuming op(a[-1], ..), which is out of bound, is always false)\n    template\
    \ <bool (*f)(T)> int min_left(int r) const {\n        return min_left(r, [](T\
    \ x) { return f(x); });\n    }\n    template <class F> int min_left(int r, F f)\
    \ const {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n     \
    \   if (r == 0) return 0;\n        r += size;\n        T sm = e();\n        do\
    \ {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n       \
    \     if (!f(op(d[r], sm))) {\n                while (r < size) {\n          \
    \          r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n    \
    \                    sm = op(d[r], sm);\n                        r--;\n      \
    \              }\n                }\n                return r + 1 - size;\n  \
    \          }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n\
    \        return 0;\n    }\n\nprivate:\n    int _n, size, log;\n    vector<T> d;\n\
    \n    void update(int k) {\n        d[k] = op(d[2*k], d[2*k+1]);\n    }\n};\n\
    // }}}\n\n// SegTree examples {{{\n// Examples: Commonly used SegTree ops: max\
    \ / min / sum\nstruct MaxSegTreeOp {\n    static int op(int x, int y) {\n    \
    \    return max(x, y);\n    }\n    static int e() {\n        return INT_MIN;\n\
    \    }\n};\n\nstruct MinSegTreeOp {\n    static int op(int x, int y) {\n     \
    \   return min(x, y);\n    }\n    static int e() {\n        return INT_MAX;\n\
    \    }\n};\n\nstruct SumSegTreeOp {\n    static long long op(long long x, long\
    \ long y) {\n        return x + y;\n    }\n    static long long e() {\n      \
    \  return 0;\n    }\n};\n\n// using STMax = SegTree<int, MaxSegTreeOp::op, MaxSegTreeOp::e>;\n\
    // using STMin = SegTree<int, MinSegTreeOp::op, MinSegTreeOp::e>;\n// using STSum\
    \ = SegTree<int, SumSegTreeOp::op, SumSegTreeOp::e>;\n// }}}\n#line 1 \"DataStructure/HeavyLight_adamant.h\"\
    \n// Index from 0\n// Best used with SegTree.h\n//\n// Usage:\n// HLD hld(g, root);\n\
    // // build segment tree. Note that we must use hld.order[i]\n// vector<T> nodes;\n\
    // for (int i = 0; i < n; i++)\n//   nodes.push_back(initial_value[hld.order[i]])\n\
    // SegTree<S, op, e> st(nodes);\n//\n// // Update single vertex\n// st.set(hld.in[u],\
    \ new_value)\n//\n// // Update path\n// hld.apply_path(from, to, is_edge, [&]\
    \ (int l, int r) {\n//   st.apply(l, r+1, F);\n// });\n//\n// // Query path\n\
    // hld.prod_path_commutative<S, op, e> (from, to, is_edge, [&] (int l, int r)\
    \ {\n//   return st.prod(l, r+1);\n// });\n//\n// Tested:\n// - (vertex, path)\
    \ https://judge.yosupo.jp/problem/vertex_add_path_sum\n// - (vertex, path, non-commutative)\
    \ https://judge.yosupo.jp/problem/vertex_set_path_composite\n// - (vertex, subtree)\
    \ https://judge.yosupo.jp/problem/vertex_add_subtree_sum\n// - (vertex, path,\
    \ non-commutative, 1-index) https://oj.vnoi.info/problem/icpc21_mt_l\n// - (vertex,\
    \ path) https://oj.vnoi.info/problem/qtree3\n//\n// - (edge, path) https://oj.vnoi.info/problem/qtreex\n\
    // - (edge, path) https://oj.vnoi.info/problem/lubenica\n// - (edge, path) https://oj.vnoi.info/problem/pwalk\n\
    // - (edge, path, lazy) https://oj.vnoi.info/problem/kbuild\n// - (edge, path,\
    \ lazy) https://oj.vnoi.info/problem/onbridge\n//\n// - (lca) https://oj.vnoi.info/problem/fselect\n\
    // - (kth_parent) https://cses.fi/problemset/task/1687\n// HeavyLight {{{\nstruct\
    \ HLD {\n    HLD(const vector<vector<int>>& _g, int root)\n            : n(_g.size()),\
    \ g(_g),\n            parent(n), depth(n), sz(n),\n            dfs_number(0),\
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
    \            u = parent[v];\n        }\n    }\n\n    // return k-th vertex on\
    \ path from u -> v (0 <= k)\n    // if k > distance -> return -1\n    int kth_vertex_on_path(int\
    \ u, int v, int k) const {\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n\n        int l = lca(u, v);\n        int ul = depth[u] - depth[l];\n\
    \        if (k <= ul) return kth_parent(u, k);\n        k -= ul;\n        int\
    \ vl = depth[v] - depth[l];\n        if (k <= vl) return kth_parent(v, vl - k);\n\
    \        return -1;\n    }\n\n    int dist(int u, int v) const {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        int l = lca(u, v);\n\
    \        return depth[u] + depth[v] - 2*depth[l];\n    }\n\n    // apply f on\
    \ vertices on path [u, v]\n    // edge = true -> apply on edge\n    //\n    //\
    \ f(l, r) should update segment tree [l, r] INCLUSIVE\n    void apply_path(int\
    \ u, int v, bool edge, const function<void(int, int)> &f) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        if (u == v && edge)\
    \ return;\n\n        while (true) {\n            if (in[u] > in[v]) swap(u, v);\
    \ // in[u] <= in[v]\n            if (nxt[u] == nxt[v]) break;\n            f(in[nxt[v]],\
    \ in[v]);\n            v = parent[nxt[v]];\n        }\n        if (u == v && edge)\
    \ return;\n        f(in[u] + edge, in[v]);\n    }\n\n    // get prod of path u\
    \ -> v\n    // edge = true -> get on edges\n    //\n    // f(l, r) should query\
    \ segment tree [l, r] INCLUSIVE\n    // f must be commutative. For non-commutative,\
    \ use getSegments below\n    template<class S, S (*op) (S, S), S (*e)()>\n   \
    \ S prod_path_commutative(\n            int u, int v, bool edge,\n           \
    \ const function<S(int, int)>& f) const {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        if (u == v && edge) {\n           \
    \ return e();\n        }\n        S su = e(), sv = e();\n        while (true)\
    \ {\n            if (in[u] > in[v]) { swap(u, v); swap(su, sv); }\n          \
    \  if (nxt[u] == nxt[v]) break;\n            sv = op(sv, f(in[nxt[v]], in[v]));\n\
    \            v = parent[nxt[v]];\n        }\n        if (u == v && edge) {\n \
    \           return op(su, sv);\n        } else {\n            return op(su, op(sv,\
    \ f(in[u] + edge, in[v])));\n        }\n    }\n\n    // f(l, r) modify seg_tree\
    \ [l, r] INCLUSIVE\n    void apply_subtree(int u, bool edge, const function<void(int,\
    \ int)>& f) {\n        assert(0 <= u && u < n);\n        f(in[u] + edge, out[u]\
    \ - 1);\n    }\n\n    // f(l, r) queries seg_tree [l, r] INCLUSIVE\n    template<class\
    \ S>\n    S prod_subtree_commutative(int u, bool edge, const function<S(S, S)>&\
    \ f) {\n        assert(0 <= u && u < n);\n        return f(in[u] + edge, out[u]\
    \ - 1);\n    }\n\n    // Useful when functions are non-commutative\n    // Return\
    \ all segments on path from u -> v\n    // For this problem, the order (u -> v\
    \ is different from v -> u)\n    vector< pair<int,int> > getSegments(int u, int\
    \ v) const {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        vector< pair<int,int> > upFromU, upFromV;\n\n        int fu = nxt[u],\
    \ fv = nxt[v];\n        while (fu != fv) {  // u and v are on different chains\n\
    \            if (depth[fu] >= depth[fv]) { // move u up\n                upFromU.push_back({u,\
    \ fu});\n                u = parent[fu];\n                fu = nxt[u];\n     \
    \       } else { // move v up\n                upFromV.push_back({fv, v});\n \
    \               v = parent[fv];\n                fv = nxt[v];\n            }\n\
    \        }\n        upFromU.push_back({u, v});\n        reverse(upFromV.begin(),\
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
    // }}}\n#line 6 \"DataStructure/test/aizu_grl_5_d_hld_edge.test.cpp\"\n\nusing\
    \ ll = long long;\n\nvoid solve() {\n    int n; cin >> n;\n    vector<vector<int>>\
    \ adj(n);\n    REP(i,n) {\n        int k; cin >> k;\n        while (k--) {\n \
    \           int j; cin >> j;\n            adj[i].push_back(j);\n            adj[j].push_back(i);\n\
    \        }\n    }\n\n    HLD hld(adj, 0);\n    SegTree<ll, SumSegTreeOp::op, SumSegTreeOp::e>\
    \ st(n);\n\n    int q; cin >> q;\n    while (q--) {\n        int typ; cin >> typ;\n\
    \        if (typ == 0) {\n            int u, val; cin >> u >> val;\n         \
    \   hld.apply_path(u, hld.parent[u], true, [&] (int l, int r) {\n            \
    \    st.set(l, st.get(l) + val);\n            });\n        } else {\n        \
    \    int u; cin >> u;\n            cout << hld.prod_path_commutative<ll, SumSegTreeOp::op,\
    \ SumSegTreeOp::e>(\n                    0, u, true, [&] (int l, int r) {\n  \
    \                      return st.prod(l, r+1);\n                    }) << '\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n\n#include \"../../template.h\"\n#include \"../SegTree.h\"\n#include \"../HeavyLight_adamant.h\"\
    \n\nusing ll = long long;\n\nvoid solve() {\n    int n; cin >> n;\n    vector<vector<int>>\
    \ adj(n);\n    REP(i,n) {\n        int k; cin >> k;\n        while (k--) {\n \
    \           int j; cin >> j;\n            adj[i].push_back(j);\n            adj[j].push_back(i);\n\
    \        }\n    }\n\n    HLD hld(adj, 0);\n    SegTree<ll, SumSegTreeOp::op, SumSegTreeOp::e>\
    \ st(n);\n\n    int q; cin >> q;\n    while (q--) {\n        int typ; cin >> typ;\n\
    \        if (typ == 0) {\n            int u, val; cin >> u >> val;\n         \
    \   hld.apply_path(u, hld.parent[u], true, [&] (int l, int r) {\n            \
    \    st.set(l, st.get(l) + val);\n            });\n        } else {\n        \
    \    int u; cin >> u;\n            cout << hld.prod_path_commutative<ll, SumSegTreeOp::op,\
    \ SumSegTreeOp::e>(\n                    0, u, true, [&] (int l, int r) {\n  \
    \                      return st.prod(l, r+1);\n                    }) << '\\\
    n';\n        }\n    }\n}\n"
  dependsOn:
  - template.h
  - DataStructure/SegTree.h
  - DataStructure/HeavyLight_adamant.h
  isVerificationFile: true
  path: DataStructure/test/aizu_grl_5_d_hld_edge.test.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:16:58+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/aizu_grl_5_d_hld_edge.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/aizu_grl_5_d_hld_edge.test.cpp
- /verify/DataStructure/test/aizu_grl_5_d_hld_edge.test.cpp.html
title: DataStructure/test/aizu_grl_5_d_hld_edge.test.cpp
---
