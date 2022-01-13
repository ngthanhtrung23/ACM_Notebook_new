---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/DfsTree/BridgeArticulation.h
    title: Graph/DfsTree/BridgeArticulation.h
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"Graph/tests/aizu_grl_3_a_articulation_points.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Graph/DfsTree/BridgeArticulation.h\"\n\
    // Assume already have undirected graph vector< vector<int> > G with V vertices\n\
    // Vertex index from 0\n// Usage:\n// UndirectedDfs tree;\n// Then you can use\
    \ tree.bridges and tree.articulation_points\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/two_edge_connected_components\n\
    struct UndirectedDfs {\n    vector<vector<int>> g;\n    int n;\n    vector<int>\
    \ low, num, parent;\n    vector<bool> is_articulation;\n    int counter, root,\
    \ children;\n\n    vector< pair<int,int> > bridges;\n    vector<int> articulation_points;\n\
    \    map<pair<int,int>, int> cnt_edges;\n\n    UndirectedDfs(const vector<vector<int>>&\
    \ _g) : g(_g), n(g.size()),\n            low(n, 0), num(n, -1), parent(n, 0),\
    \ is_articulation(n, false),\n            counter(0), children(0) {\n        for\
    \ (int u = 0; u < n; u++) {\n            for (int v : g[u]) {\n              \
    \  cnt_edges[{u, v}] += 1;\n            }\n        }\n        for(int i = 0; i\
    \ < n; ++i) if (num[i] == -1) {\n            root = i; children = 0;\n       \
    \     dfs(i);\n            is_articulation[root] = (children > 1);\n        }\n\
    \        for(int i = 0; i < n; ++i)\n            if (is_articulation[i]) articulation_points.push_back(i);\n\
    \    }\nprivate:\n    void dfs(int u) {\n        low[u] = num[u] = counter++;\n\
    \        for (int v : g[u]) {\n            if (num[v] == -1) {\n             \
    \   parent[v] = u;\n                if (u == root) children++;\n             \
    \   dfs(v);\n                if (low[v] >= num[u])\n                    is_articulation[u]\
    \ = true;\n                if (low[v] > num[u]) {\n                    if (cnt_edges[{u,\
    \ v}] == 1) {\n                        bridges.push_back(make_pair(u, v));\n \
    \                   }\n                }\n                low[u] = min(low[u],\
    \ low[v]);\n            } else if (v != parent[u])\n                low[u] = min(low[u],\
    \ num[v]);\n        }\n    }\n};\n#line 5 \"Graph/tests/aizu_grl_3_a_articulation_points.test.cpp\"\
    \n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    vector<vector<int>> g(n);\n\
    \    REP(i,m) {\n        int u, v; cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    UndirectedDfs tree(g);\n    auto res\
    \ = tree.articulation_points;\n    sort(res.begin(), res.end());\n    for (int\
    \ r : res) cout << r << '\\n';\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include \"../../template.h\"\n#include \"../DfsTree/BridgeArticulation.h\"\
    \n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    vector<vector<int>> g(n);\n\
    \    REP(i,m) {\n        int u, v; cin >> u >> v;\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n    }\n\n    UndirectedDfs tree(g);\n    auto res\
    \ = tree.articulation_points;\n    sort(res.begin(), res.end());\n    for (int\
    \ r : res) cout << r << '\\n';\n}\n"
  dependsOn:
  - template.h
  - Graph/DfsTree/BridgeArticulation.h
  isVerificationFile: true
  path: Graph/tests/aizu_grl_3_a_articulation_points.test.cpp
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/aizu_grl_3_a_articulation_points.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/aizu_grl_3_a_articulation_points.test.cpp
- /verify/Graph/tests/aizu_grl_3_a_articulation_points.test.cpp.html
title: Graph/tests/aizu_grl_3_a_articulation_points.test.cpp
---
