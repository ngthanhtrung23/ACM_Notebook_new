---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/topo_sort.h
    title: Graph/topo_sort.h
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"Graph/tests/aizu_grl_4_b_topo_sort.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\n\n#line\
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
    \ (0, r-1)(rng);\n}\n\ntemplate<typename T>\nvector<T> read_vector(int n) {\n\
    \    vector<T> res(n);\n    for (int& x : res) cin >> x;\n    return res;\n}\n\
    \nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n  \
    \  solve();\n    return 0;\n}\n#line 1 \"Graph/topo_sort.h\"\n// Topo sort\n//\
    \ returns: <has topo sort?, topo order>\n//\n// Notes:\n// - To find lexicographically\
    \ min -> change queue<int> qu to set\n//\n// Tested:\n// - https://cses.fi/problemset/task/1679/\n\
    // - https://cses.fi/problemset/task/1757/\nstd::pair<bool, std::vector<int>>\
    \ topo_sort(const std::vector<std::vector<int>>& g) {\n    int n = g.size();\n\
    \    // init in_deg\n    std::vector<int> in_deg(n, 0);\n    for (int u = 0; u\
    \ < n; u++) {\n        for (int v : g[u]) {\n            in_deg[v]++;\n      \
    \  }\n    }\n\n    // find topo order\n    std::vector<int> res;\n    std::queue<int>\
    \ qu;\n    for (int u = 0; u < n; u++) {\n        if (in_deg[u] == 0) {\n    \
    \        qu.push(u);\n        }\n    }\n\n    while (!qu.empty()) {\n        int\
    \ u = qu.front(); qu.pop();\n        res.push_back(u);\n        for (int v : g[u])\
    \ {\n            in_deg[v]--;\n            if (in_deg[v] == 0) {\n           \
    \     qu.push(v);\n            }\n        }\n    }\n\n    if ((int) res.size()\
    \ < n) {\n        return {false, {}};\n    }\n    return {true, res};\n}\n#line\
    \ 5 \"Graph/tests/aizu_grl_4_b_topo_sort.test.cpp\"\n\nvoid solve() {\n    int\
    \ n, m; std::cin >> n >> m;\n    std::vector<std::vector<int>> g(n);\n    while\
    \ (m--) {\n        int u, v; std::cin >> u >> v;\n        g[u].push_back(v);\n\
    \    }\n\n    auto [_, order] = topo_sort(g);\n    for (int u : order) std::cout\
    \ << u << '\\n';\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n\n#include \"../../template.h\"\n#include \"../topo_sort.h\"\n\nvoid solve()\
    \ {\n    int n, m; std::cin >> n >> m;\n    std::vector<std::vector<int>> g(n);\n\
    \    while (m--) {\n        int u, v; std::cin >> u >> v;\n        g[u].push_back(v);\n\
    \    }\n\n    auto [_, order] = topo_sort(g);\n    for (int u : order) std::cout\
    \ << u << '\\n';\n}\n"
  dependsOn:
  - template.h
  - Graph/topo_sort.h
  isVerificationFile: true
  path: Graph/tests/aizu_grl_4_b_topo_sort.test.cpp
  requiredBy: []
  timestamp: '2022-08-09 14:52:23+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Graph/tests/aizu_grl_4_b_topo_sort.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/aizu_grl_4_b_topo_sort.test.cpp
- /verify/Graph/tests/aizu_grl_4_b_topo_sort.test.cpp.html
title: Graph/tests/aizu_grl_4_b_topo_sort.test.cpp
---
