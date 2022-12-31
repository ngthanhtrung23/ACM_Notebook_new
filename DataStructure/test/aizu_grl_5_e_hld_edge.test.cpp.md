---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/HeavyLight_adamant.h
    title: DataStructure/HeavyLight_adamant.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegTree.h
    title: DataStructure/LazySegTree.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E
  bundledCode: "#line 1 \"DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"DataStructure/LazySegTree.h\"\n// Lazy\
    \ Segment Tree, copied from AtCoder {{{\n// Source: https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    // Doc: https://atcoder.github.io/ac-library/master/document_en/lazysegtree.html\n\
    //\n// Notes:\n// - Index of elements from 0\n// - Range queries are [l, r-1]\n\
    // - composition(f, g) should return f(g())\n//\n// Tested:\n// - https://oj.vnoi.info/problem/qmax2\n\
    // - https://oj.vnoi.info/problem/lites\n// - (range set, add, mult, sum) https://oj.vnoi.info/problem/segtree_itmix\n\
    // - (range add (i-L)*A + B, sum) https://oj.vnoi.info/problem/segtree_itladder\n\
    // - https://atcoder.jp/contests/practice2/tasks/practice2_l\n// - https://judge.yosupo.jp/problem/range_affine_range_sum\n\
    \nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\ntemplate<\n    class S,                 // node data\
    \ type\n    S (*op) (S, S),          // combine 2 nodes\n    S (*e) (),      \
    \         // identity element\n    class F,                 // lazy propagation\
    \ tag\n    S (*mapping) (F, S),     // apply tag F on a node\n    F (*composition)\
    \ (F, F), // combine 2 tags\n    F (*id)()                // identity tag\n>\n\
    struct LazySegTree {\n    LazySegTree() : LazySegTree(0) {}\n    explicit LazySegTree(int\
    \ n) : LazySegTree(vector<S>(n, e())) {}\n    explicit LazySegTree(const vector<S>&\
    \ v) : _n((int) v.size()) {\n        log = ceil_pow2(_n);\n        size = 1 <<\
    \ log;\n        d = std::vector<S>(2 * size, e());\n        lz = std::vector<F>(size,\
    \ id());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for\
    \ (int i = size - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\
    \n    // 0 <= p < n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n\n    // 0 <= p < n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n  \
    \      return d[p];\n    }\n\n    // Get product in range [l, r-1]\n    // 0 <=\
    \ l <= r <= n\n    // For empty segment (l == r) -> return e()\n    S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l ==\
    \ r) return e();\n\n        l += size;\n        r += size;\n\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n    \
    \    S sml = e(), smr = e();\n        while (l < r) {\n            if (l & 1)\
    \ sml = op(sml, d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n    \
    \        l >>= 1;\n            r >>= 1;\n        }\n\n        return op(sml, smr);\n\
    \    }\n\n    S all_prod() {\n        return d[1];\n    }\n\n    // 0 <= p < n\n\
    \    void apply(int p, F f) {\n        assert(0 <= p && p < _n);\n        p +=\
    \ size;\n        for (int i = log; i >= 1; i--) push(p >> i);\n        d[p] =\
    \ mapping(f, d[p]);\n        for (int i = 1; i <= log; i++) update(p >> i);\n\
    \    }\n\n    // Apply f on all elements in range [l, r-1]\n    // 0 <= l <= r\
    \ <= n\n    void apply(int l, int r, F f) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if (l == r) return;\n\n        l += size;\n        r += size;\n\
    \n        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n\n        {\n            int l2 = l, r2 = r;\n            while (l\
    \ < r) {\n                if (l & 1) all_apply(l++, f);\n                if (r\
    \ & 1) all_apply(--r, f);\n                l >>= 1;\n                r >>= 1;\n\
    \            }\n            l = l2;\n            r = r2;\n        }\n\n      \
    \  for (int i = 1; i <= log; i++) {\n            if (((l >> i) << i) != l) update(l\
    \ >> i);\n            if (((r >> i) << i) != r) update((r - 1) >> i);\n      \
    \  }\n    }\n\n    // Binary search on SegTree to find largest r:\n    //    f(op(a[l]\
    \ .. a[r-1])) = true   (assuming empty array is always true)\n    //    f(op(a[l]\
    \ .. a[r])) = false    (assuming op(..., a[n]), which is out of bound, is always\
    \ false)\n    template <bool (*g)(S)> int max_right(int l) {\n        return max_right(l,\
    \ [](S x) { return g(x); });\n    }\n    template <class G> int max_right(int\
    \ l, G g) {\n        assert(0 <= l && l <= _n);\n        assert(g(e()));\n   \
    \     if (l == _n) return _n;\n        l += size;\n        for (int i = log; i\
    \ >= 1; i--) push(l >> i);\n        S sm = e();\n        do {\n            while\
    \ (l % 2 == 0) l >>= 1;\n            if (!g(op(sm, d[l]))) {\n               \
    \ while (l < size) {\n                    push(l);\n                    l = (2\
    \ * l);\n                    if (g(op(sm, d[l]))) {\n                        sm\
    \ = op(sm, d[l]);\n                        l++;\n                    }\n     \
    \           }\n                return l - size;\n            }\n            sm\
    \ = op(sm, d[l]);\n            l++;\n        } while ((l & -l) != l);\n      \
    \  return _n;\n    }\n\n    // Binary search on SegTree to find smallest l:\n\
    \    //    f(op(a[l] .. a[r-1])) = true      (assuming empty array is always true)\n\
    \    //    f(op(a[l-1] .. a[r-1])) = false   (assuming op(a[-1], ..), which is\
    \ out of bound, is always false)\n    template <bool (*g)(S)> int min_left(int\
    \ r) {\n        return min_left(r, [](S x) { return g(x); });\n    }\n    template\
    \ <class G> int min_left(int r, G g) {\n        assert(0 <= r && r <= _n);\n \
    \       assert(g(e()));\n        if (r == 0) return 0;\n        r += size;\n \
    \       for (int i = log; i >= 1; i--) push((r - 1) >> i);\n        S sm = e();\n\
    \        do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\
    \            if (!g(op(d[r], sm))) {\n                while (r < size) {\n   \
    \                 push(r);\n                    r = (2 * r + 1);\n           \
    \         if (g(op(d[r], sm))) {\n                        sm = op(d[r], sm);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - size;\n            }\n            sm = op(d[r], sm);\n\
    \        } while ((r & -r) != r);\n        return 0;\n    }\n\n\nprivate:\n  \
    \  int _n, size, log;\n    vector<S> d;\n    vector<F> lz;\n\n    void update(int\
    \ k) {\n        d[k] = op(d[2*k], d[2*k+1]);\n    }\n    void all_apply(int k,\
    \ F f) {\n        d[k] = mapping(f, d[k]);\n        if (k < size) lz[k] = composition(f,\
    \ lz[k]);\n    }\n    void push(int k) {\n        all_apply(2*k, lz[k]);\n   \
    \     all_apply(2*k+1, lz[k]);\n        lz[k] = id();\n    }\n};\n// }}}\n\n//\
    \ Examples {{{\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n// supports:\n\
    // - set a(l -> r) to val; val > NOT_SET\n// - add a(l -> r) += val\n// - find\
    \ sum a(l -> r)\n// - find min a(l -> r)\nstruct RangeSetAddMinSumOps {\n    struct\
    \ S { long long sum, min, sz; };\n    static S op(S l, S r) { return S { l.sum\
    \ + r.sum, min(l.min, r.min), l.sz + r.sz }; }\n    static S e() { return S {0LL,\
    \ INT_MAX, 0}; }\n\n    static const long long NOT_SET = -1000111000;\n    struct\
    \ F { long long set, add; };\n\n    static S mapping(F f, S s) {\n        if (f.set\
    \ == NOT_SET) {\n            return S {\n                s.sum + f.add * s.sz,\n\
    \                s.min + f.add,\n                s.sz,\n            };\n     \
    \   }\n        return S {\n            (f.set + f.add) * s.sz,\n            f.set\
    \ + f.add,\n            s.sz,\n        };\n    }\n    static F composition(F f,\
    \ F g) {\n        if (f.set == NOT_SET) {\n            return F { g.set, g.add\
    \ + f.add };\n        }\n        return f;\n    }\n    static F id() {\n     \
    \   return F { NOT_SET, 0 };\n    }\n};\n// }}}\n#line 1 \"DataStructure/HeavyLight_adamant.h\"\
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
    // }}}\n#line 6 \"DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp\"\n\nusing\
    \ ll = long long;\nstruct S {\n    ll sum, sz;\n};\n\nS op(S l, S r) {\n    return\
    \ S { l.sum + r.sum, l.sz + r.sz };\n}\nS e() { return S {0, 0}; }\n\nS mapping(ll\
    \ f, S s) {\n    return S { s.sum + s.sz * f, s.sz };\n}\nll composition(ll f,\
    \ ll g) { return f + g; }\nll id() { return 0; }\n\n\nvoid solve() {\n    int\
    \ n; cin >> n;\n    vector<vector<int>> adj(n);\n    REP(i,n) {\n        int k;\
    \ cin >> k;\n        while (k--) {\n            int j; cin >> j;\n           \
    \ adj[i].push_back(j);\n            adj[j].push_back(i);\n        }\n    }\n\n\
    \    HLD hld(adj, 0);\n    vector<S> nodes;\n    for (int i = 0; i < n; i++) nodes.push_back(S{0,\
    \ 1});\n    LazySegTree<S, op, e, ll, mapping, composition, id> st(nodes);\n\n\
    \    int q; cin >> q;\n    while (q--) {\n        int typ; cin >> typ;\n     \
    \   if (typ == 0) {\n            int u, val; cin >> u >> val;\n            hld.apply_path(u,\
    \ 0, true, [&] (int l, int r) {\n                st.apply(l, r + 1, val);\n  \
    \          });\n        } else {\n            int u; cin >> u;\n            cout\
    \ << hld.prod_path_commutative<S, op, e>(\n                    0, u, true, [&]\
    \ (int l, int r) {\n                        return st.prod(l, r+1);\n        \
    \            }).sum << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E\"\
    \n\n#include \"../../template.h\"\n#include \"../LazySegTree.h\"\n#include \"\
    ../HeavyLight_adamant.h\"\n\nusing ll = long long;\nstruct S {\n    ll sum, sz;\n\
    };\n\nS op(S l, S r) {\n    return S { l.sum + r.sum, l.sz + r.sz };\n}\nS e()\
    \ { return S {0, 0}; }\n\nS mapping(ll f, S s) {\n    return S { s.sum + s.sz\
    \ * f, s.sz };\n}\nll composition(ll f, ll g) { return f + g; }\nll id() { return\
    \ 0; }\n\n\nvoid solve() {\n    int n; cin >> n;\n    vector<vector<int>> adj(n);\n\
    \    REP(i,n) {\n        int k; cin >> k;\n        while (k--) {\n           \
    \ int j; cin >> j;\n            adj[i].push_back(j);\n            adj[j].push_back(i);\n\
    \        }\n    }\n\n    HLD hld(adj, 0);\n    vector<S> nodes;\n    for (int\
    \ i = 0; i < n; i++) nodes.push_back(S{0, 1});\n    LazySegTree<S, op, e, ll,\
    \ mapping, composition, id> st(nodes);\n\n    int q; cin >> q;\n    while (q--)\
    \ {\n        int typ; cin >> typ;\n        if (typ == 0) {\n            int u,\
    \ val; cin >> u >> val;\n            hld.apply_path(u, 0, true, [&] (int l, int\
    \ r) {\n                st.apply(l, r + 1, val);\n            });\n        } else\
    \ {\n            int u; cin >> u;\n            cout << hld.prod_path_commutative<S,\
    \ op, e>(\n                    0, u, true, [&] (int l, int r) {\n            \
    \            return st.prod(l, r+1);\n                    }).sum << '\\n';\n \
    \       }\n    }\n}\n"
  dependsOn:
  - template.h
  - DataStructure/LazySegTree.h
  - DataStructure/HeavyLight_adamant.h
  isVerificationFile: true
  path: DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:16:58+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp
- /verify/DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp.html
title: DataStructure/test/aizu_grl_5_e_hld_edge.test.cpp
---
