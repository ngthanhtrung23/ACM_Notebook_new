---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/MoAlgorithm.h
    title: DataStructure/MoAlgorithm.h
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"DataStructure/test/mo_algorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 1 \"template.h\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"DataStructure/MoAlgorithm.h\"\n// Notes:\n\
    // - queries are [l, r]\n// - add(int array_id) -> void \n// - remove(int array_id)\
    \ -> void\n// - get(QueryT query) -> ResultT\n//\n// Tested:\n// - https://www.spoj.com/problems/KDOMINO/\
    \ (submission ID: 30602374)\n// - https://www.spoj.com/problems/FREQ2 (submission\
    \ ID: 30602401)\n//\n// Mo algorithm {{{\ntemplate<typename QueryT, typename ResultT,\
    \ typename Add, typename Rem, typename Get>\nvector<ResultT> mo(int n, std::vector<QueryT>\
    \ queries, Add add, Rem rem, Get get) {\n    int q = queries.size();\n    std::vector<ResultT>\
    \ res(q);\n \n    // Sort queries in increasing order of (left / SQRT, right)\n\
    \    int S = sqrt(n);\n    if (S < 1) S = 1;\n \n    std::vector<int> query_ids(q);\n\
    \    std::iota(query_ids.begin(), query_ids.end(), 0);\n    std::sort(query_ids.begin(),\
    \ query_ids.end(), [&] (int q1, int q2) {\n            int bucket1 = queries[q1].l\
    \ / S;\n            int bucket2 = queries[q2].l / S;\n            if (bucket1\
    \ != bucket2) return bucket1 < bucket2;\n            else {\n                return\
    \ bucket1 % 2\n                        ? (queries[q1].r > queries[q2].r)\n   \
    \                     : (queries[q1].r < queries[q2].r);\n            }\n    \
    \    });\n \n    // Answer queries\n    int cur_l = -1, cur_r = -1;\n    for (int\
    \ qid : query_ids) {\n        // move to this range\n        if (cur_l < 0) {\n\
    \            for (int i = queries[qid].l; i <= queries[qid].r; ++i) {\n      \
    \          add(i);\n            }\n            cur_l = queries[qid].l, cur_r =\
    \ queries[qid].r;\n        } else {\n            while (cur_l > queries[qid].l)\
    \ add(--cur_l);\n            while (cur_r < queries[qid].r) add(++cur_r);\n  \
    \          while (cur_r > queries[qid].r) rem(cur_r--);\n            while (cur_l\
    \ < queries[qid].l) rem(cur_l++);\n        }\n \n        res[qid] = get(queries[qid]);\n\
    \    }\n    return res;\n}\n \n// Example\nstruct Query {\n    int l, r;  // QueryT\
    \ must have l, r\n};\nostream& operator << (ostream& cout, const Query& q) {\n\
    \    cout << \"Query: [\" << q.l << \", \" << q.r << \"]\";\n    return cout;\n\
    }\n// Usage\n// auto res = mo<Query, int, decltype(add), decltype(rem), decltype(get)>\n\
    //        (n, queries, add, rem, get);\n// }}}\n#line 5 \"DataStructure/test/mo_algorithm.test.cpp\"\
    \n\nvoid solve() {\n    int n, q; cin >> n >> q;\n    vector<int> a(n); REP(i,n)\
    \ cin >> a[i];\n\n    vector<Query> queries(q);\n    REP(i,q) {\n        cin >>\
    \ queries[i].l >> queries[i].r;\n        queries[i].r--;\n    }\n\n    int sum\
    \ = 0;\n    auto add = [&] (int id) { sum += a[id]; };\n    auto rem = [&] (int\
    \ id) { sum -= a[id]; };\n    auto get = [&] ([[maybe_unused]] const Query& _)\
    \ { return sum; };\n\n    auto res = mo<Query, int, decltype(add), decltype(rem),\
    \ decltype(get)>\n        (n, queries, add, rem, get);\n    for (int r : res)\
    \ cout << r << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../template.h\"\n#include \"../MoAlgorithm.h\"\n\nvoid solve() {\n\
    \    int n, q; cin >> n >> q;\n    vector<int> a(n); REP(i,n) cin >> a[i];\n\n\
    \    vector<Query> queries(q);\n    REP(i,q) {\n        cin >> queries[i].l >>\
    \ queries[i].r;\n        queries[i].r--;\n    }\n\n    int sum = 0;\n    auto\
    \ add = [&] (int id) { sum += a[id]; };\n    auto rem = [&] (int id) { sum -=\
    \ a[id]; };\n    auto get = [&] ([[maybe_unused]] const Query& _) { return sum;\
    \ };\n\n    auto res = mo<Query, int, decltype(add), decltype(rem), decltype(get)>\n\
    \        (n, queries, add, rem, get);\n    for (int r : res) cout << r << '\\\
    n';\n}\n"
  dependsOn:
  - template.h
  - DataStructure/MoAlgorithm.h
  isVerificationFile: true
  path: DataStructure/test/mo_algorithm.test.cpp
  requiredBy: []
  timestamp: '2022-12-26 16:49:24+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: DataStructure/test/mo_algorithm.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/mo_algorithm.test.cpp
- /verify/DataStructure/test/mo_algorithm.test.cpp.html
title: DataStructure/test/mo_algorithm.test.cpp
---
