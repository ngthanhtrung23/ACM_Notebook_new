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
    - https://www.spoj.com/problems/ADAUNIQ/
  bundledCode: "#line 1 \"DataStructure/MoAlgorithmWithUpdates.h\"\n// Tested:\n//\
    \ - https://www.spoj.com/problems/ADAUNIQ/\n//\n// Notes:\n// - Updates must be\
    \ set: A(u) = val\n// - When implementing Update(id, new_value, cur_l, cur_r)\
    \ -> void:\n//   [cur_l, cur_r] = current segment\n//   we need to handle the\
    \ case where we update an index that is inside\n//   [cur_l, cur_r]\n//\n// Mo\
    \ algorithm with updates {{{\nenum QueryType { GET = 0, UPDATE = 1 };\n\nstruct\
    \ Query {\n    int l, r;             // For get\n    int u, val, old_val;  //\
    \ For update\n    int id;\n    QueryType typ;\n};\n\ntemplate<typename Add, typename\
    \ Rem, typename Update, typename Get>\nvoid mo_with_updates(\n        int n, const\
    \ vector<Query>& queries,\n        Add add, Rem rem, Update update, Get get) {\n\
    \    // Separate update and get queries\n    vector<Query> updates, gets;\n  \
    \  for (const auto& query : queries) {\n        if (query.typ == QueryType::UPDATE)\
    \ updates.push_back(query);\n        else gets.push_back(query);\n    }\n\n  \
    \  // Sort queries\n    int S = std::max<int>(1, cbrtl(n + 0.5));\n    S = S *\
    \ S;\n\n    sort(gets.begin(), gets.end(), [&] (const Query& q1, const Query&\
    \ q2) {\n            int l1 = q1.l / S;\n            int l2 = q2.l / S;\n    \
    \        if (l1 != l2) return l1 < l2;\n\n            int r1 = q1.r / S;\n   \
    \         int r2 = q2.r / S;\n            if (r1 != r2) return (l1 % 2 == 0) ?\
    \ r1 < r2 : r1 > r2;\n\n            return (r1 % 2 == 0)\n                   \
    \ ? q1.id < q2.id\n                    : q1.id > q2.id;\n            });\n\n \
    \   // Process queries\n    int cur_l = -1, cur_r = -1, cur_update = -1;\n   \
    \ for (const auto& query : gets) {\n        // move to [l, r]\n        if (cur_l\
    \ < 0) {\n            for (int i = query.l; i <= query.r; ++i) add(i);\n     \
    \       cur_l = query.l;\n            cur_r = query.r;\n        } else {\n   \
    \         while (cur_l > query.l) add(--cur_l);\n            while (cur_r < query.r)\
    \ add(++cur_r);\n            while (cur_r > query.r) rem(cur_r--);\n         \
    \   while (cur_l < query.l) rem(cur_l++);\n        }\n\n        // process updates\n\
    \        // should we update more?\n        while (cur_update + 1 < (int) updates.size()\n\
    \                && updates[cur_update + 1].id < query.id) {\n            ++cur_update;\n\
    \            update(updates[cur_update].u, updates[cur_update].val, cur_l, cur_r);\n\
    \        }\n        // should we update less?\n        while (cur_update >= 0\
    \ && updates[cur_update].id > query.id) {\n            update(updates[cur_update].u,\
    \ updates[cur_update].old_val, cur_l, cur_r);\n            --cur_update;\n   \
    \     }\n\n        get(query);\n    }\n}\n// }}}\n"
  code: "// Tested:\n// - https://www.spoj.com/problems/ADAUNIQ/\n//\n// Notes:\n\
    // - Updates must be set: A(u) = val\n// - When implementing Update(id, new_value,\
    \ cur_l, cur_r) -> void:\n//   [cur_l, cur_r] = current segment\n//   we need\
    \ to handle the case where we update an index that is inside\n//   [cur_l, cur_r]\n\
    //\n// Mo algorithm with updates {{{\nenum QueryType { GET = 0, UPDATE = 1 };\n\
    \nstruct Query {\n    int l, r;             // For get\n    int u, val, old_val;\
    \  // For update\n    int id;\n    QueryType typ;\n};\n\ntemplate<typename Add,\
    \ typename Rem, typename Update, typename Get>\nvoid mo_with_updates(\n      \
    \  int n, const vector<Query>& queries,\n        Add add, Rem rem, Update update,\
    \ Get get) {\n    // Separate update and get queries\n    vector<Query> updates,\
    \ gets;\n    for (const auto& query : queries) {\n        if (query.typ == QueryType::UPDATE)\
    \ updates.push_back(query);\n        else gets.push_back(query);\n    }\n\n  \
    \  // Sort queries\n    int S = std::max<int>(1, cbrtl(n + 0.5));\n    S = S *\
    \ S;\n\n    sort(gets.begin(), gets.end(), [&] (const Query& q1, const Query&\
    \ q2) {\n            int l1 = q1.l / S;\n            int l2 = q2.l / S;\n    \
    \        if (l1 != l2) return l1 < l2;\n\n            int r1 = q1.r / S;\n   \
    \         int r2 = q2.r / S;\n            if (r1 != r2) return (l1 % 2 == 0) ?\
    \ r1 < r2 : r1 > r2;\n\n            return (r1 % 2 == 0)\n                   \
    \ ? q1.id < q2.id\n                    : q1.id > q2.id;\n            });\n\n \
    \   // Process queries\n    int cur_l = -1, cur_r = -1, cur_update = -1;\n   \
    \ for (const auto& query : gets) {\n        // move to [l, r]\n        if (cur_l\
    \ < 0) {\n            for (int i = query.l; i <= query.r; ++i) add(i);\n     \
    \       cur_l = query.l;\n            cur_r = query.r;\n        } else {\n   \
    \         while (cur_l > query.l) add(--cur_l);\n            while (cur_r < query.r)\
    \ add(++cur_r);\n            while (cur_r > query.r) rem(cur_r--);\n         \
    \   while (cur_l < query.l) rem(cur_l++);\n        }\n\n        // process updates\n\
    \        // should we update more?\n        while (cur_update + 1 < (int) updates.size()\n\
    \                && updates[cur_update + 1].id < query.id) {\n            ++cur_update;\n\
    \            update(updates[cur_update].u, updates[cur_update].val, cur_l, cur_r);\n\
    \        }\n        // should we update less?\n        while (cur_update >= 0\
    \ && updates[cur_update].id > query.id) {\n            update(updates[cur_update].u,\
    \ updates[cur_update].old_val, cur_l, cur_r);\n            --cur_update;\n   \
    \     }\n\n        get(query);\n    }\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/MoAlgorithmWithUpdates.h
  requiredBy: []
  timestamp: '2022-12-22 10:28:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/MoAlgorithmWithUpdates.h
layout: document
redirect_from:
- /library/DataStructure/MoAlgorithmWithUpdates.h
- /library/DataStructure/MoAlgorithmWithUpdates.h.html
title: DataStructure/MoAlgorithmWithUpdates.h
---
