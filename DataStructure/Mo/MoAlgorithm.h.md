---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/mo_algorithm.test.cpp
    title: DataStructure/test/mo_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://www.spoj.com/problems/FREQ2
    - https://www.spoj.com/problems/KDOMINO/
  bundledCode: "#line 1 \"DataStructure/Mo/MoAlgorithm.h\"\n// Notes:\n// - queries\
    \ are [l, r]\n// - add(int array_id) -> void \n// - remove(int array_id) -> void\n\
    // - get(QueryT query) -> ResultT\n//\n// Tested:\n// - https://www.spoj.com/problems/KDOMINO/\
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
    //        (n, queries, add, rem, get);\n// }}}\n"
  code: "// Notes:\n// - queries are [l, r]\n// - add(int array_id) -> void \n// -\
    \ remove(int array_id) -> void\n// - get(QueryT query) -> ResultT\n//\n// Tested:\n\
    // - https://www.spoj.com/problems/KDOMINO/ (submission ID: 30602374)\n// - https://www.spoj.com/problems/FREQ2\
    \ (submission ID: 30602401)\n//\n// Mo algorithm {{{\ntemplate<typename QueryT,\
    \ typename ResultT, typename Add, typename Rem, typename Get>\nvector<ResultT>\
    \ mo(int n, std::vector<QueryT> queries, Add add, Rem rem, Get get) {\n    int\
    \ q = queries.size();\n    std::vector<ResultT> res(q);\n \n    // Sort queries\
    \ in increasing order of (left / SQRT, right)\n    int S = sqrt(n);\n    if (S\
    \ < 1) S = 1;\n \n    std::vector<int> query_ids(q);\n    std::iota(query_ids.begin(),\
    \ query_ids.end(), 0);\n    std::sort(query_ids.begin(), query_ids.end(), [&]\
    \ (int q1, int q2) {\n            int bucket1 = queries[q1].l / S;\n         \
    \   int bucket2 = queries[q2].l / S;\n            if (bucket1 != bucket2) return\
    \ bucket1 < bucket2;\n            else {\n                return bucket1 % 2\n\
    \                        ? (queries[q1].r > queries[q2].r)\n                 \
    \       : (queries[q1].r < queries[q2].r);\n            }\n        });\n \n  \
    \  // Answer queries\n    int cur_l = -1, cur_r = -1;\n    for (int qid : query_ids)\
    \ {\n        // move to this range\n        if (cur_l < 0) {\n            for\
    \ (int i = queries[qid].l; i <= queries[qid].r; ++i) {\n                add(i);\n\
    \            }\n            cur_l = queries[qid].l, cur_r = queries[qid].r;\n\
    \        } else {\n            while (cur_l > queries[qid].l) add(--cur_l);\n\
    \            while (cur_r < queries[qid].r) add(++cur_r);\n            while (cur_r\
    \ > queries[qid].r) rem(cur_r--);\n            while (cur_l < queries[qid].l)\
    \ rem(cur_l++);\n        }\n \n        res[qid] = get(queries[qid]);\n    }\n\
    \    return res;\n}\n \n// Example\nstruct Query {\n    int l, r;  // QueryT must\
    \ have l, r\n};\nostream& operator << (ostream& cout, const Query& q) {\n    cout\
    \ << \"Query: [\" << q.l << \", \" << q.r << \"]\";\n    return cout;\n}\n// Usage\n\
    // auto res = mo<Query, int, decltype(add), decltype(rem), decltype(get)>\n//\
    \        (n, queries, add, rem, get);\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Mo/MoAlgorithm.h
  requiredBy: []
  timestamp: '2023-10-03 00:47:04-07:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/mo_algorithm.test.cpp
documentation_of: DataStructure/Mo/MoAlgorithm.h
layout: document
redirect_from:
- /library/DataStructure/Mo/MoAlgorithm.h
- /library/DataStructure/Mo/MoAlgorithm.h.html
title: DataStructure/Mo/MoAlgorithm.h
---
