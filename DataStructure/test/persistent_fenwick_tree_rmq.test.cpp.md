---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/PartiallyPersistentFenwick.h
    title: DataStructure/PartiallyPersistentFenwick.h
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"DataStructure/test/persistent_fenwick_tree_rmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 1 \"template.h\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define FOR(i,a,b) for(int\
    \ i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b;\
    \ i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a) for(__typeof(a.begin())\
    \ it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x) { cout << #x << \"\
    \ = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n)\
    \ cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n) { cout << #a << \" =\
    \ \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\n\
    \n// For printing pair, container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
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
    \  solve();\n    return 0;\n}\n#line 1 \"DataStructure/PartiallyPersistentFenwick.h\"\
    \n// NOTE:\n// - 0-based index\n// - for updates: time must be in increasing order\n\
    // - Update: O(log), Get: O(log^2)\n//\n// Partially Persistent FenwickTree {{{\n\
    template<\n    typename T  // need to support operators + - <\n> struct PartiallyPersistentFenwick\
    \ {\n    PartiallyPersistentFenwick(int _n) : n(_n), f(_n + 1) {\n        for\
    \ (int i = 0; i <= n; ++i) {\n            f[i].emplace_back(INT_MIN, T{});\n \
    \       }\n    }\n\n    // a[u] += val\n    void update(int time, int u, T val)\
    \ {\n        assert(0 <= u && u < n);\n        assert(last_updated_time <= time);\n\
    \        last_updated_time = time;\n        ++u;\n        for (; u <= n; u +=\
    \ u & -u) {\n            f[u].emplace_back(time, f[u].back().second + val);\n\
    \        }\n    }\n\n    // return a[0] + .. + a[u-1]\n    T get(int time, int\
    \ u) const {\n        assert(0 <= u && u <= n);\n        T res{};\n        for\
    \ (; u > 0; u -= u & -u) {\n            auto it = lower_bound(f[u].begin(), f[u].end(),\
    \ make_pair(time+1, T{}));\n            res = res + prev(it)->second;\n      \
    \  }\n        return res;\n    }\n\n    // return a[l] + .. + a[r-1]\n    T get(int\
    \ time, int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n \
    \       if (l == r) return T{};  // empty\n        return get(time, r) - get(time,\
    \ l);\n    }\n\n    int n;\n    int last_updated_time = INT_MIN;\n    vector<vector<pair<int,\
    \ T>>> f;  // (time, data)\n};\n// }}}\n#line 4 \"DataStructure/test/persistent_fenwick_tree_rmq.test.cpp\"\
    \n\nstruct Data {\n    int x;\n    Data() : x(INT_MAX) {}\n    Data(int _x) :\
    \ x(_x) {}\n};\nData operator + (const Data& a, const Data& b) {\n    return Data{min(a.x,\
    \ b.x)};\n}\nbool operator < (const Data&, const Data&) {\n    return false;\n\
    }\n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    vector<int> a(n);\n   \
    \ REP(i,n) cin >> a[i];\n\n    PartiallyPersistentFenwick<Data> fen(n);\n    FORD(i,n-1,0)\
    \ fen.update(n-i, i, Data{a[i]});\n\n    while (q--) {\n        int l, r; cin\
    \ >> l >> r;\n        auto res = fen.get(n-l, r);\n        cout << res.x << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../../template.h\"\n#include \"../PartiallyPersistentFenwick.h\"\n\nstruct Data\
    \ {\n    int x;\n    Data() : x(INT_MAX) {}\n    Data(int _x) : x(_x) {}\n};\n\
    Data operator + (const Data& a, const Data& b) {\n    return Data{min(a.x, b.x)};\n\
    }\nbool operator < (const Data&, const Data&) {\n    return false;\n}\n\nvoid\
    \ solve() {\n    int n, q; cin >> n >> q;\n    vector<int> a(n);\n    REP(i,n)\
    \ cin >> a[i];\n\n    PartiallyPersistentFenwick<Data> fen(n);\n    FORD(i,n-1,0)\
    \ fen.update(n-i, i, Data{a[i]});\n\n    while (q--) {\n        int l, r; cin\
    \ >> l >> r;\n        auto res = fen.get(n-l, r);\n        cout << res.x << '\\\
    n';\n    }\n}\n"
  dependsOn:
  - template.h
  - DataStructure/PartiallyPersistentFenwick.h
  isVerificationFile: true
  path: DataStructure/test/persistent_fenwick_tree_rmq.test.cpp
  requiredBy: []
  timestamp: '2022-12-26 20:29:27+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/persistent_fenwick_tree_rmq.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/persistent_fenwick_tree_rmq.test.cpp
- /verify/DataStructure/test/persistent_fenwick_tree_rmq.test.cpp.html
title: DataStructure/test/persistent_fenwick_tree_rmq.test.cpp
---
