---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/floyd.h
    title: Graph/floyd.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"Graph/tests/floyd_aizu.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"template.h\"\n\
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
    \ (0, r-1)(rng);\n}\n#line 1 \"Graph/floyd.h\"\n// Tested:\n// - https://cses.fi/problemset/task/1672/\n\
    // - (trace) https://oj.vnoi.info/problem/floyd\nusing ll = long long;\nconst\
    \ ll INF = 4e18;\nstruct Floyd {\n    Floyd(int _n, const std::vector<std::vector<ll>>\
    \ _c) : n(_n), c(_c), trace(n) {\n        for (int i = 0; i < n; i++) {\n    \
    \        trace[i] = std::vector<int> (n, -1);\n            for (int j = 0; j <\
    \ n; j++) {\n                if (c[i][j] == INF) trace[i][j] = -1;\n         \
    \       else trace[i][j] = i;\n            }\n        }\n\n        for (int k\
    \ = 0; k < n; k++) {\n            for (int i = 0; i < n; i++) {\n            \
    \    for (int j = 0; j < n; j++) {\n                    if (c[i][k] != INF &&\
    \ c[k][j] != INF && c[i][j] > c[i][k] + c[k][j]) {\n                        c[i][j]\
    \ = c[i][k] + c[k][j];\n                        trace[i][j] = trace[k][j];\n \
    \                   }\n                }\n            }\n        }\n    }\n\n\
    \    // Return {distance, path}\n    // If no path -> returns {-1, {}}\n    std::pair<ll,\
    \ std::vector<int>> get_path(int start, int target) {\n        if (trace[start][target]\
    \ == -1) return {-1, {}};\n\n        std::vector<int> path;\n        for (int\
    \ u = target; u != start; u = trace[start][u]) {\n            path.push_back(u);\n\
    \        }\n        path.push_back(start);\n        reverse(path.begin(), path.end());\n\
    \        return {c[start][target], path};\n    }\n\n    int n;\n    std::vector<std::vector<ll>>\
    \ c;\n    std::vector<std::vector<int>> trace;\n};\n\n#line 8 \"Graph/tests/floyd_aizu.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, m; cin\
    \ >> n >> m;\n    vector<vector<ll>> c(n, vector<ll> (n, INF));\n    for (int\
    \ i = 0; i < n; i++) c[i][i] = 0;\n\n    while (m--) {\n        int u, v; ll cost;\
    \ cin >> u >> v >> cost;\n        c[u][v] = min(c[u][v], cost);\n    }\n\n   \
    \ Floyd f(n, c);\n    for (int i = 0; i < n; i++) {\n        if (f.c[i][i] < 0)\
    \ {\n            cout << \"NEGATIVE CYCLE\" << endl;\n            return 0;\n\
    \        }\n    }\n    for (int i = 0; i < n; i++) {\n        for (int j = 0;\
    \ j < n; j++) {\n            if (f.c[i][j] == INF) cout << \"INF\";\n        \
    \    else cout << f.c[i][j];\n            cout << (j == n-1 ? '\\n' : ' ');\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../template.h\"\
    \n#include \"../floyd.h\"\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, m; cin >> n >> m;\n    vector<vector<ll>> c(n, vector<ll> (n, INF));\n\
    \    for (int i = 0; i < n; i++) c[i][i] = 0;\n\n    while (m--) {\n        int\
    \ u, v; ll cost; cin >> u >> v >> cost;\n        c[u][v] = min(c[u][v], cost);\n\
    \    }\n\n    Floyd f(n, c);\n    for (int i = 0; i < n; i++) {\n        if (f.c[i][i]\
    \ < 0) {\n            cout << \"NEGATIVE CYCLE\" << endl;\n            return\
    \ 0;\n        }\n    }\n    for (int i = 0; i < n; i++) {\n        for (int j\
    \ = 0; j < n; j++) {\n            if (f.c[i][j] == INF) cout << \"INF\";\n   \
    \         else cout << f.c[i][j];\n            cout << (j == n-1 ? '\\n' : ' ');\n\
    \        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - template.h
  - Graph/floyd.h
  isVerificationFile: true
  path: Graph/tests/floyd_aizu.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 00:30:04+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/tests/floyd_aizu.test.cpp
layout: document
redirect_from:
- /verify/Graph/tests/floyd_aizu.test.cpp
- /verify/Graph/tests/floyd_aizu.test.cpp.html
title: Graph/tests/floyd_aizu.test.cpp
---
