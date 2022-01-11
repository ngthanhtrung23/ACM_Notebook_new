---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/DfsTree/StronglyConnected.h
    title: Graph/DfsTree/StronglyConnected.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
  bundledCode: "#line 1 \"Graph/tests/strongly_connected_cycle_check.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
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
    \ (0, r-1)(rng);\n}\n\nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    solve();\n    return 0;\n}\n#line 1 \"Graph/DfsTree/StronglyConnected.h\"\
    \n// Index from 0\n// Usage:\n// DirectedDfs tree;\n// Now you can use tree.scc\n\
    //\n// Note: reverse(tree.scc) is topo sorted\n//\n// Tested:\n// - (requires\
    \ scc to be topo sorted) https://judge.yosupo.jp/problem/scc\nstruct DirectedDfs\
    \ {\n    vector<vector<int>> g;\n    int n;\n    vector<int> num, low, current,\
    \ S;\n    int counter;\n    vector<int> comp_ids;\n    vector< vector<int> > scc;\n\
    \n    DirectedDfs(const vector<vector<int>>& _g) : g(_g), n(g.size()),\n     \
    \       num(n, -1), low(n, 0), current(n, 0), counter(0), comp_ids(n, -1) {\n\
    \        for (int i = 0; i < n; i++) {\n            if (num[i] == -1) dfs(i);\n\
    \        }\n    }\n\n    void dfs(int u) {\n        low[u] = num[u] = counter++;\n\
    \        S.push_back(u);\n        current[u] = 1;\n        for (auto v : g[u])\
    \ {\n            if (num[v] == -1) dfs(v);\n            if (current[v]) low[u]\
    \ = min(low[u], low[v]);\n        }\n        if (low[u] == num[u]) {\n       \
    \     scc.push_back(vector<int>());\n            while (1) {\n               \
    \ int v = S.back(); S.pop_back(); current[v] = 0;\n                scc.back().push_back(v);\n\
    \                comp_ids[v] = ((int) scc.size()) - 1;\n                if (u\
    \ == v) break;\n            }\n        }\n    }\n};\n#line 5 \"Graph/tests/strongly_connected_cycle_check.test.cpp\"\
    \n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    vector<vector<int>> g(n);\n\
    \    while (m--) {\n        int u, v; cin >> u >> v;\n        g[u].push_back(v);\n\
    \    }\n    DirectedDfs tree(g);\n    for (auto comp : tree.scc) {\n        if\
    \ (comp.size() > 1) {\n            cout << 1 << endl;\n            return;\n \
    \       }\n    }\n    cout << 0 << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include \"../../template.h\"\n#include \"../DfsTree/StronglyConnected.h\"\
    \n\nvoid solve() {\n    int n, m; cin >> n >> m;\n    vector<vector<int>> g(n);\n\
    \    while (m--) {\n        int u, v; cin >> u >> v;\n        g[u].push_back(v);\n\
    \    }\n    DirectedDfs tree(g);\n    for (auto comp : tree.scc) {\n        if\
    \ (comp.size() > 1) {\n            cout << 1 << endl;\n            return;\n \
    \       }\n    }\n    cout << 0 << endl;\n}\n"
  dependsOn:
  - template.h
  - Graph/DfsTree/StronglyConnected.h
  isVerificationFile: true
  path: Graph/tests/strongly_connected_cycle_check.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 18:29:44+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/strongly_connected_cycle_check.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/strongly_connected_cycle_check.test.cpp
- /verify/Graph/tests/strongly_connected_cycle_check.test.cpp.html
title: Graph/tests/strongly_connected_cycle_check.test.cpp
---
