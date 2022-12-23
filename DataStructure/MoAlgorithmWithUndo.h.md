---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://www.spoj.com/problems/FREQ2/
    - https://www.spoj.com/problems/KDOMINO/
    - https://www.spoj.com/problems/ZQUERY/
  bundledCode: "#line 1 \"DataStructure/MoAlgorithmWithUndo.h\"\n// Notes:\n// - queries\
    \ are [l, r]\n// - add(int array_id) -> void \n// - undo() -> void\n// - get(QueryT\
    \ query) -> ResultT\n//\n// Tested:\n// - https://www.spoj.com/problems/FREQ2/\
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
    \ decltype(get)>\n//        (n, queries, add, undo, get);\n// }}}\n\n"
  code: "// Notes:\n// - queries are [l, r]\n// - add(int array_id) -> void \n// -\
    \ undo() -> void\n// - get(QueryT query) -> ResultT\n//\n// Tested:\n// - https://www.spoj.com/problems/FREQ2/\
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
    \ decltype(get)>\n//        (n, queries, add, undo, get);\n// }}}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/MoAlgorithmWithUndo.h
  requiredBy: []
  timestamp: '2022-12-24 01:16:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/MoAlgorithmWithUndo.h
layout: document
redirect_from:
- /library/DataStructure/MoAlgorithmWithUndo.h
- /library/DataStructure/MoAlgorithmWithUndo.h.html
title: DataStructure/MoAlgorithmWithUndo.h
---
