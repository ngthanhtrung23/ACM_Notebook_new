---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Graph/Misc/EulerPath.h
    title: Graph/Misc/EulerPath.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b)\
    \ for(int i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a;\
    \ i++)\n#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end();\
    \ ++it)\n\n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl; }\n\
    #define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout\
    \ << endl; }\n#define PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout << a[_]\
    \ << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\n\n// For printing pair,\
    \ container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Graph/Misc/EulerPath.h\"\n// NOTES:\n\
    // - When choosing starting vertex (for calling find_path), make sure deg[start]\
    \ > 0.\n// - If find Euler path, starting vertex must have odd degree.\n// - Check\
    \ no solution: SZ(path) == nEdge + 1.\n// - For directed -> see EulerPathDirected.h\n\
    //\n// Tested:\n// - SGU 101 (undirected).\nstruct Edge {\n    int to;\n    list<Edge>::iterator\
    \ rev;\n\n    Edge(int to) :to(to) {}\n};\n\nconst int MN = 100111;\nlist<Edge>\
    \ adj[MN];\nvector<int> path; // our result\n\nvoid find_path(int v) {\n    while(adj[v].size()\
    \ > 0) {\n        int vn = adj[v].front().to;\n        adj[vn].erase(adj[v].front().rev);\n\
    \        adj[v].pop_front();\n        find_path(vn);\n    }\n    path.push_back(v);\n\
    }\n\nvoid add_edge(int a, int b) {\n    adj[a].push_front(Edge(b));\n    auto\
    \ ita = adj[a].begin();\n    adj[b].push_front(Edge(a));\n    auto itb = adj[b].begin();\n\
    \    ita->rev = itb;\n    itb->rev = ita;\n}\n#line 3 \"Graph/Misc/EulerPath.cpp\"\
    \n\nint main() {\n    add_edge(1, 2);\n    add_edge(2, 3);\n    add_edge(3, 4);\n\
    \    add_edge(4, 1);\n    add_edge(1, 3);\n\n    find_path(1);\n    PR0(path,\
    \ path.size());\n}\n"
  code: "#include \"template.h\"\n#include \"Graph/Misc/EulerPath.h\"\n\nint main()\
    \ {\n    add_edge(1, 2);\n    add_edge(2, 3);\n    add_edge(3, 4);\n    add_edge(4,\
    \ 1);\n    add_edge(1, 3);\n\n    find_path(1);\n    PR0(path, path.size());\n\
    }\n"
  dependsOn:
  - template.h
  - Graph/Misc/EulerPath.h
  isVerificationFile: false
  path: Graph/Misc/EulerPath.cpp
  requiredBy: []
  timestamp: '2022-07-23 01:36:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Misc/EulerPath.cpp
layout: document
redirect_from:
- /library/Graph/Misc/EulerPath.cpp
- /library/Graph/Misc/EulerPath.cpp.html
title: Graph/Misc/EulerPath.cpp
---
