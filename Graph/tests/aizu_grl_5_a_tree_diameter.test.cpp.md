---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/tree_diameter.h
    title: Graph/tree_diameter.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "#line 1 \"Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Graph/tree_diameter.h\"\n// Tree diameter\
    \ (weighted)\n// Index from 0\n// Return {length, path}\n//\n// Tested:\n// -\
    \ https://judge.yosupo.jp/problem/tree_diameter\nusing ll = long long;\npair<ll,\
    \ vector<int>> get_diameter(const vector<vector<pair<int,int>>>& g) {\n    int\
    \ n = g.size();\n    vector<ll> dist(n);\n    vector<int> parent(n);\n\n    function<void(int,\
    \ int, ll)> dfs = [&] (int u, int fu, ll cur_dist) {\n        dist[u] = cur_dist;\n\
    \        parent[u] = fu;\n        for (auto [v, cost] : g[u]) if (v != fu) {\n\
    \            dfs(v, u, cur_dist + cost);\n        }\n    };\n    dfs(0, -1, 0);\n\
    \    // r = furthest node from root\n    int r = max_element(dist.begin(), dist.end())\
    \ - dist.begin();\n    dfs(r, -1, 0);\n    // r->s = longest path\n    int s =\
    \ max_element(dist.begin(), dist.end()) - dist.begin();\n\n    vector<int> path;\n\
    \    for (int x = s; x >= 0; x = parent[x]) path.push_back(x);\n\n    return {dist[s],\
    \ path};\n}\n#line 5 \"Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp\"\n\nvoid\
    \ solve() {\n    int n; cin >> n;\n    vector<vector<pair<int,int>>> g(n);\n \
    \   REP(i,n-1) {\n        int u, v, cost; cin >> u >> v >> cost;\n        g[u].emplace_back(v,\
    \ cost);\n        g[v].emplace_back(u, cost);\n    }\n\n    auto [length, path]\
    \ = get_diameter(g);\n    cout << length << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n\n#include \"../../template.h\"\n#include \"../tree_diameter.h\"\n\nvoid solve()\
    \ {\n    int n; cin >> n;\n    vector<vector<pair<int,int>>> g(n);\n    REP(i,n-1)\
    \ {\n        int u, v, cost; cin >> u >> v >> cost;\n        g[u].emplace_back(v,\
    \ cost);\n        g[v].emplace_back(u, cost);\n    }\n\n    auto [length, path]\
    \ = get_diameter(g);\n    cout << length << endl;\n}\n"
  dependsOn:
  - template.h
  - Graph/tree_diameter.h
  isVerificationFile: true
  path: Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp
- /verify/Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp.html
title: Graph/tests/aizu_grl_5_a_tree_diameter.test.cpp
---
