---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/MoAlgorithmWithUndo.h
    title: DataStructure/MoAlgorithmWithUndo.h
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"DataStructure/test/mo_algorithm_with_undo.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 1 \"template.h\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"DataStructure/MoAlgorithmWithUndo.h\"\
    \n// Notes:\n// - queries are [l, r]\n// - add(int array_id) -> void \n// - undo()\
    \ -> void\n// - get(QueryT query) -> ResultT\n//\n// Tested:\n// - https://www.spoj.com/problems/FREQ2/\
    \ (submission ID: 30602190)\n// - https://www.spoj.com/problems/KDOMINO/ (submission\
    \ ID: 30602247)\n// - https://www.spoj.com/problems/ZQUERY/\n//\n// Mo algorithm\
    \ with undo DS {{{\ntemplate<typename QueryT, typename ResultT, typename Add,\
    \ typename Undo, typename Get>\nvector<ResultT> mo_with_undo(int n, std::vector<QueryT>\
    \ queries, Add add, Undo undo, Get get) {\n    int s = max((int) 1, (int) sqrt(n\
    \ + 0.5));\n    int q = queries.size();\n    vector<ResultT> res(q);\n\n    //\
    \ For each block, stores vector of (query, id)\n    std::vector<std::vector<int>>\
    \ blocks(n / s + 1);\n    for (int i = 0; i < q; ++i) {\n        blocks[queries[i].l\
    \ / s].push_back(i);\n    }\n\n    // Process each block\n    int block_start\
    \ = 0, block_end = s - 1;\n    for (auto& block : blocks) {\n        sort(block.begin(),\
    \ block.end(), [&] (int q1, int q2) {\n                return queries[q1].r <\
    \ queries[q2].r;\n                });\n        int cur_r = block_end;\n      \
    \  for (int qid : block) {\n            const auto& query = queries[qid];\n  \
    \          assert(block_start <= query.l && query.l <= block_end);\n\n       \
    \     // For query that is entirely inside this block, we just process it\n  \
    \          // and then undo immediately\n            if (query.r <= block_end)\
    \ {\n                for (int i = query.l; i <= query.r; ++i) add(i);\n      \
    \          res[qid] = get(query);\n                for (int i = query.l; i <=\
    \ query.r; ++i) undo();\n                continue;\n            }\n\n        \
    \    // Order:\n            // 1. add(i) for i in block_end + 1 .. query.r\n \
    \           // 2. add(i) for i in query.l .. block_end\n            // 3. get()\n\
    \            // 4. undo() for i in query.l .. block_end => all of (2) is undo\n\
    \            for (int i = cur_r + 1; i <= query.r; ++i) add(i);\n            for\
    \ (int i = query.l; i <= block_end; ++i) add(i);\n            res[qid] = get(query);\n\
    \            for (int i = query.l; i <= block_end; ++i) undo();\n            cur_r\
    \ = query.r;\n        }\n\n        for (int i = cur_r; i > block_end; --i) undo();\n\
    \n        block_start += s;\n        block_end += s;\n    }\n    return res;\n\
    }\n\n// Example\nstruct Query {\n    int l, r;  // QueryT must have l, r\n};\n\
    // Usage\n// auto res = mo_with_undo<Query, int, decltype(add), decltype(undo),\
    \ decltype(get)>\n//        (n, queries, add, undo, get);\n// }}}\n\n#line 5 \"\
    DataStructure/test/mo_algorithm_with_undo.test.cpp\"\n\nvoid solve() {\n    int\
    \ n, q; cin >> n >> q;\n    vector<int> a(n); REP(i,n) cin >> a[i];\n\n    vector<Query>\
    \ queries(q);\n    REP(i,q) {\n        cin >> queries[i].l >> queries[i].r;\n\
    \        queries[i].r--;\n    }\n\n    int64_t sum = 0;\n    stack<int> nums;\n\
    \n    auto add = [&] (int id) {\n        sum += a[id];\n        nums.push(a[id]);\n\
    \    };\n    auto undo = [&] () {\n        sum -= nums.top();\n        nums.pop();\n\
    \    };\n    auto get = [&] ([[maybe_unused]] const Query& _) {\n        return\
    \ sum;\n    };\n\n    auto res = mo_with_undo<Query, int64_t, decltype(add), decltype(undo),\
    \ decltype(get)>\n        (n, queries, add, undo, get);\n    for (auto r : res)\
    \ cout << r << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../template.h\"\n#include \"../MoAlgorithmWithUndo.h\"\n\nvoid solve()\
    \ {\n    int n, q; cin >> n >> q;\n    vector<int> a(n); REP(i,n) cin >> a[i];\n\
    \n    vector<Query> queries(q);\n    REP(i,q) {\n        cin >> queries[i].l >>\
    \ queries[i].r;\n        queries[i].r--;\n    }\n\n    int64_t sum = 0;\n    stack<int>\
    \ nums;\n\n    auto add = [&] (int id) {\n        sum += a[id];\n        nums.push(a[id]);\n\
    \    };\n    auto undo = [&] () {\n        sum -= nums.top();\n        nums.pop();\n\
    \    };\n    auto get = [&] ([[maybe_unused]] const Query& _) {\n        return\
    \ sum;\n    };\n\n    auto res = mo_with_undo<Query, int64_t, decltype(add), decltype(undo),\
    \ decltype(get)>\n        (n, queries, add, undo, get);\n    for (auto r : res)\
    \ cout << r << '\\n';\n}\n"
  dependsOn:
  - template.h
  - DataStructure/MoAlgorithmWithUndo.h
  isVerificationFile: true
  path: DataStructure/test/mo_algorithm_with_undo.test.cpp
  requiredBy: []
  timestamp: '2022-12-26 16:55:49+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/mo_algorithm_with_undo.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/mo_algorithm_with_undo.test.cpp
- /verify/DataStructure/test/mo_algorithm_with_undo.test.cpp.html
title: DataStructure/test/mo_algorithm_with_undo.test.cpp
---
