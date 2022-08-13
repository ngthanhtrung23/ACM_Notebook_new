---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU_weighted.h
    title: DataStructure/DSU_weighted.h
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"DataStructure/DSU_weighted.h\"\ntemplate<class\
    \ S>\nstruct WeightedDSU {\n    std::vector<int> lab;\n    std::vector<S> w; \
    \ // relative to parent\n\n    WeightedDSU(int n) : lab(n, -1), w(n) {}\n\n  \
    \  int getRoot(int u) {\n        if (lab[u] < 0) return u;\n        return getRoot(lab[u]);\n\
    \    }\n\n    int weight(int u) {\n        if (lab[u] < 0) return w[u];\n    \
    \    return w[u] + weight(lab[u]);\n    }\n\n    // weight(t) = weight(s) + diff\n\
    \    // returns false if contradicts\n    bool merge(int s, int t, S diff) {\n\
    \        // jump to root\n        diff = diff + weight(s) - weight(t);\n     \
    \   s = getRoot(s);\n        t = getRoot(t);\n        if (s == t) return diff\
    \ == 0;\n        if (lab[s] > lab[t]) {\n            std::swap(s, t);\n      \
    \      diff = -diff;\n        }\n        lab[s] += lab[t];\n        lab[t] = s;\n\
    \        w[t] = diff;\n        return true;\n    }\n};\n#line 5 \"DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    WeightedDSU<long long> dsu(n);\n\
    \    while (q--) {\n        int typ; cin >> typ;\n        if (typ == 0) {\n  \
    \          int x, y, z; cin >> x >> y >> z;\n            // f[y] = f[x] + z\n\
    \            dsu.merge(x, y, z);\n        } else {\n            int x, y; cin\
    \ >> x >> y;\n            if (dsu.getRoot(x) == dsu.getRoot(y)) {\n          \
    \      cout << dsu.weight(y) - dsu.weight(x) << '\\n';\n            } else {\n\
    \                cout << \"?\\n\";\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include \"../../template.h\"\n#include \"../DSU_weighted.h\"\n\nvoid solve()\
    \ {\n    int n, q; cin >> n >> q;\n    WeightedDSU<long long> dsu(n);\n    while\
    \ (q--) {\n        int typ; cin >> typ;\n        if (typ == 0) {\n           \
    \ int x, y, z; cin >> x >> y >> z;\n            // f[y] = f[x] + z\n         \
    \   dsu.merge(x, y, z);\n        } else {\n            int x, y; cin >> x >> y;\n\
    \            if (dsu.getRoot(x) == dsu.getRoot(y)) {\n                cout <<\
    \ dsu.weight(y) - dsu.weight(x) << '\\n';\n            } else {\n            \
    \    cout << \"?\\n\";\n            }\n        }\n    }\n}\n"
  dependsOn:
  - template.h
  - DataStructure/DSU_weighted.h
  isVerificationFile: true
  path: DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp
- /verify/DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp.html
title: DataStructure/test/aizu_dsl_1_b_dsu_weighted.test.cpp
---
