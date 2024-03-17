---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU/DisjointSet.h
    title: DataStructure/DSU/DisjointSet.h
  - icon: ':heavy_check_mark:'
    path: Graph/mst.h
    title: Graph/mst.h
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
    PROBLEM: https://judge.yosupo.jp/problem/minimum_spanning_tree
    links:
    - https://judge.yosupo.jp/problem/minimum_spanning_tree
  bundledCode: "#line 1 \"Graph/tests/yosupo_mst.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Graph/mst.h\"\n// MST. 0-based index\n\
    //\n// Returns:\n// {mst cost, edges in mst}\n//\n// If graph is not connected,\
    \ returns forest (number of edges will be < n-1)\n\n#line 1 \"DataStructure/DSU/DisjointSet.h\"\
    \n// DisjointSet {{{\nstruct DSU {\n    vector<int> lab;\n\n    DSU(int n) : lab(n+1,\
    \ -1) {}\n\n    int getRoot(int u) {\n        if (lab[u] < 0) return u;\n    \
    \    return lab[u] = getRoot(lab[u]);\n    }\n\n    bool merge(int u, int v) {\n\
    \        u = getRoot(u); v = getRoot(v);\n        if (u == v) return false;\n\
    \        if (lab[u] > lab[v]) swap(u, v);\n        lab[u] += lab[v];\n       \
    \ lab[v] = u;\n        return true;\n    }\n\n    bool same_component(int u, int\
    \ v) {\n        return getRoot(u) == getRoot(v);\n    }\n\n    int component_size(int\
    \ u) {\n        return -lab[getRoot(u)];\n    }\n};\n// }}}\n#line 9 \"Graph/mst.h\"\
    \n\n// MST {{{\nusing ll = long long;\ntemplate<typename EdgeT>\nstd::pair<ll,\
    \ std::vector<EdgeT>> mst(\n        int n,\n        std::vector<EdgeT> edges)\
    \ {\n    std::sort(edges.begin(), edges.end());\n\n    DSU dsu(n + 1);  // tolerate\
    \ 1-based index\n    ll total = 0;\n    vector<EdgeT> tree;\n    for (const auto&\
    \ e : edges) {\n        if (dsu.merge(e.u, e.v)) {\n            total += e.c;\n\
    \            tree.push_back(e);\n        }\n    }\n    return {total, tree};\n\
    }\nstruct Edge {\n    int u, v;\n    ll c;\n};\nbool operator < (const Edge& a,\
    \ const Edge& b) {\n    return a.c < b.c;\n}\nostream& operator << (ostream& out,\
    \ const Edge& e) {\n    out << e.u << \" - \" << e.v << \" [\" << e.c << ']';\n\
    \    return out;\n}\n// }}}\n#line 5 \"Graph/tests/yosupo_mst.test.cpp\"\n\nstruct\
    \ E : Edge {\n    int id;\n};\n\nvoid solve() {\n    int n, m; cin >> n >> m;\n\
    \    vector<E> edges(m);\n    REP(i,m) {\n        auto& e = edges[i];\n      \
    \  cin >> e.u >> e.v >> e.c;\n        e.id = i;\n    }\n    auto g = mst<E>(n,\
    \ edges);\n    cout << g.first << '\\n';\n    for (auto& e : g.second) cout <<\
    \ e.id << ' ';\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\
    \n\n#include \"../../template.h\"\n#include \"../mst.h\"\n\nstruct E : Edge {\n\
    \    int id;\n};\n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    vector<E>\
    \ edges(m);\n    REP(i,m) {\n        auto& e = edges[i];\n        cin >> e.u >>\
    \ e.v >> e.c;\n        e.id = i;\n    }\n    auto g = mst<E>(n, edges);\n    cout\
    \ << g.first << '\\n';\n    for (auto& e : g.second) cout << e.id << ' ';\n  \
    \  cout << '\\n';\n}\n"
  dependsOn:
  - template.h
  - Graph/mst.h
  - DataStructure/DSU/DisjointSet.h
  isVerificationFile: true
  path: Graph/tests/yosupo_mst.test.cpp
  requiredBy: []
  timestamp: '2024-03-17 02:51:32+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/yosupo_mst.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/yosupo_mst.test.cpp
- /verify/Graph/tests/yosupo_mst.test.cpp.html
title: Graph/tests/yosupo_mst.test.cpp
---