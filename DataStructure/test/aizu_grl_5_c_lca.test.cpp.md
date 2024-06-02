---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LCA.h
    title: DataStructure/LCA.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ.h
    title: DataStructure/RMQ.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"DataStructure/test/aizu_grl_5_c_lca.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"DataStructure/LCA.h\"\n// LCA\n// Notes:\n\
    // - Index from 0\n// - Cannot use for queries like min edge in path u -> v\n\
    //\n// Tested:\n// - https://judge.yosupo.jp/problem/lca\n#line 1 \"DataStructure/RMQ.h\"\
    \n// RMQ {{{\n//\n// Sparse table\n// Usage:\n// RMQ<int, _min> st(v);\n//\n//\
    \ Note:\n// - doesn't work for empty range\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/staticrmq\n\
    template<class T, T (*op) (T, T)> struct RMQ {\n    RMQ() = default;\n    RMQ(const\
    \ vector<T>& v) : t{v}, n{(int) v.size()} {\n        for (int k = 1; (1<<k) <=\
    \ n; ++k) {\n            t.emplace_back(n - (1<<k) + 1);\n            for (int\
    \ i = 0; i + (1<<k) <= n; ++i) {\n                t[k][i] = op(t[k-1][i], t[k-1][i\
    \ + (1<<(k-1))]);\n            }\n        }\n    }\n\n    // get range [l, r-1]\n\
    \    // doesn't work for empty range\n    T get(int l, int r) const {\n      \
    \  assert(0 <= l && l < r && r <= n);\n        int k = __lg(r - l);\n        return\
    \ op(t[k][l], t[k][r - (1<<k)]);\n    }\n\nprivate:\n    vector<vector<T>> t;\n\
    \    int n;\n};\ntemplate<class T> T _min(T a, T b) { return b < a ? b : a; }\n\
    template<class T> T _max(T a, T b) { return a < b ? b : a; }\n// }}}\n#line 9\
    \ \"DataStructure/LCA.h\"\nstruct LCA {\n    const int n;\n    vector<vector<int>>\
    \ adj;\n    const int root;\n    using P = pair<int,int>;\n    static P f(P x,\
    \ P y) { return std::min(x, y); }\n\n    LCA(int _n, const vector<vector<int>>&\
    \ _adj, int _root)\n            : n(_n), adj(_adj), root(_root) {\n        assert(0\
    \ <= root && root < n);\n        id.resize(n);\n        depth.resize(n);\n   \
    \     order.reserve(2 * n);\n        dfs(root, -1, 0);\n        rmq = RMQ<P, f>(order);\n\
    \    }\n\n    int lca(int u, int v) {\n        assert(0 <= u && u < n);\n    \
    \    assert(0 <= v && v < n);\n\n        int x = id[u], y = id[v];\n        if\
    \ (x > y) std::swap(x, y);\n        return rmq.get(x, y+1).second;\n    }\n\n\
    // private:\n    vector<int> id, depth;\n    vector<P> order;\n    RMQ<P, f> rmq;\n\
    \n    void dfs(int u, int fu, int d) {\n        id[u] = order.size();\n      \
    \  depth[u] = d;\n        order.emplace_back(d, u);\n        for (int v : adj[u])\
    \ {\n            if (v == fu) continue;\n            dfs(v, u, d + 1);\n     \
    \       order.emplace_back(d, u);\n        }\n    }\n};\n#line 5 \"DataStructure/test/aizu_grl_5_c_lca.test.cpp\"\
    \n\nvoid solve() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n; cin >>\
    \ n;\n    vector<vector<int>> adj(n);\n    REP(i,n) {\n        int k; cin >> k;\n\
    \        while (k--) {\n            int j; cin >> j;\n            adj[i].push_back(j);\n\
    \            adj[j].push_back(i);\n        }\n    }\n\n    LCA lca(n, adj, 0);\n\
    \n    int q; cin >> q;\n    while (q--) {\n        int u, v; cin >> u >> v;\n\
    \        cout << lca.lca(u, v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include \"../../template.h\"\n#include \"../LCA.h\"\n\nvoid solve() {\n \
    \   ios::sync_with_stdio(0); cin.tie(0);\n    int n; cin >> n;\n    vector<vector<int>>\
    \ adj(n);\n    REP(i,n) {\n        int k; cin >> k;\n        while (k--) {\n \
    \           int j; cin >> j;\n            adj[i].push_back(j);\n            adj[j].push_back(i);\n\
    \        }\n    }\n\n    LCA lca(n, adj, 0);\n\n    int q; cin >> q;\n    while\
    \ (q--) {\n        int u, v; cin >> u >> v;\n        cout << lca.lca(u, v) <<\
    \ '\\n';\n    }\n}\n"
  dependsOn:
  - template.h
  - DataStructure/LCA.h
  - DataStructure/RMQ.h
  isVerificationFile: true
  path: DataStructure/test/aizu_grl_5_c_lca.test.cpp
  requiredBy: []
  timestamp: '2022-08-11 17:15:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/aizu_grl_5_c_lca.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/aizu_grl_5_c_lca.test.cpp
- /verify/DataStructure/test/aizu_grl_5_c_lca.test.cpp.html
title: DataStructure/test/aizu_grl_5_c_lca.test.cpp
---
