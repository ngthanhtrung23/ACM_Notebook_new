---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/count_inversions.h
    title: DP/count_inversions.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick.h
    title: DataStructure/Fenwick.h
  - icon: ':heavy_check_mark:'
    path: Misc/compress.h
    title: Misc/compress.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"DP/tests/aizu_alds1_5_d_count_inversions.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Misc/compress.h\"\n// Compress vector\
    \ vs, and return the compressed vector {{{\n// Returned values in [0, k-1] where\
    \ k = number of different values\ntemplate<typename V>\nV compress(V vs) {\n \
    \   auto vals = vs;\n    sort(vals.begin(), vals.end());\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n\n    for (auto& v : vs) {\n        v = lower_bound(vals.begin(),\
    \ vals.end(), v) - vals.begin();\n    }\n    return vs;\n}\n// }}}\n#line 1 \"\
    DataStructure/Fenwick.h\"\n// 1D Fenwick\n// 0 based index\n//\n// Tested:\n//\
    \ - https://judge.yosupo.jp/problem/static_range_sum\n// - https://judge.yosupo.jp/problem/point_add_range_sum\n\
    template<\n    typename T  // need to support operators + -\n> struct Fenwick\
    \ {\n    Fenwick(int _n) : n(_n), f(_n + 1) {}\n\n    // a[u] += val\n    void\
    \ update(int u, T val) {\n        assert(0 <= u && u < n);\n        ++u;\n   \
    \     for (; u <= n; u += u & -u) {\n            f[u] += val;\n        }\n   \
    \ }\n\n    // return a[0] + .. + a[u-1]\n    T get(int u) const {\n        assert(0\
    \ <= u && u <= n);\n        T res = 0;\n        for (; u > 0; u -= u & -u) {\n\
    \            res += f[u];\n        }\n        return res;\n    }\n\n    // return\
    \ a[l] + .. + a[r-1]\n    T get(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        if (l == r) return 0;  // empty\n        return\
    \ get(r) - get(l);\n    }\n\n    void reset() {\n        std::fill(f.begin(),\
    \ f.end(), T(0));\n    }\n\n    int n;\n    vector<T> f;\n};\n#line 3 \"DP/count_inversions.h\"\
    \n\n// Given vector vs, return number of inversions\ntemplate<typename T>\nlong\
    \ long count_inversions(vector<T> vs) {\n    int n = vs.size();\n    vs = compress(vs);\n\
    \    Fenwick<int> bit(n);\n\n    long long res = 0;\n    for (auto v : vs) {\n\
    \        res += bit.get(v+1, n);\n        bit.update(v, +1);\n    }\n    return\
    \ res;\n}\n#line 5 \"DP/tests/aizu_alds1_5_d_count_inversions.test.cpp\"\n\nvoid\
    \ solve() {\n    int n; cin >> n;\n    auto a = read_vector<int> (n);\n\n    cout\
    \ << count_inversions(a) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include \"../../template.h\"\n#include \"../count_inversions.h\"\n\nvoid\
    \ solve() {\n    int n; cin >> n;\n    auto a = read_vector<int> (n);\n\n    cout\
    \ << count_inversions(a) << endl;\n}\n"
  dependsOn:
  - template.h
  - DP/count_inversions.h
  - Misc/compress.h
  - DataStructure/Fenwick.h
  isVerificationFile: true
  path: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
  requiredBy: []
  timestamp: '2022-08-11 17:15:37+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
layout: document
redirect_from:
- /verify/DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
- /verify/DP/tests/aizu_alds1_5_d_count_inversions.test.cpp.html
title: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
---
