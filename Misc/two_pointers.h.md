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
    - https://www.spoj.com/problems/KOIREP/
  bundledCode: "#line 1 \"Misc/two_pointers.h\"\n// O(N) 2 pointers\n// Find *smallest*\
    \ substring that satisfy a predicate while minimizing a cost function\n// (when\
    \ not satisfy -> expand -> assume expand is always valid)\n//\n// - pred() = whether\
    \ current segment satisfy condition\n// - cost(l, r) = cost of [l, r]\n// - add(i)\
    \ = add i to current segment\n// - rem(i) = remove i from current segment\n//\
    \ - indices from 0 to n-1\n//\n// Returns: <best cost, left, right> where [left,\
    \ right] is substring with\n//   mincost or [-1, -1] if no solution\n//\n// Tested:\n\
    // - https://www.spoj.com/problems/KOIREP/\n//\n// Two pointers (smallest substring)\
    \ {{{\ntemplate<typename Pred, typename Cost, typename Add, typename Rem>\ntuple<long\
    \ long, int, int> two_pointers(int n, Pred pred, Cost cost, Add add, Rem rem)\
    \ {\n    tuple<long long, int, int> res {LLONG_MAX, -1, -1};\n\n    // current\
    \ window is [l, r]\n    for (int l = 0, r = -1; l < n; ++l) {\n        while (r+1\
    \ < n && !pred()) {\n            ++r;\n            add(r);\n        }\n      \
    \  if (pred()) {\n            res = min(res, {cost(l, r), l, r});\n        }\n\
    \        rem(l);\n    }\n    return res;\n}\n// }}}\n"
  code: "// O(N) 2 pointers\n// Find *smallest* substring that satisfy a predicate\
    \ while minimizing a cost function\n// (when not satisfy -> expand -> assume expand\
    \ is always valid)\n//\n// - pred() = whether current segment satisfy condition\n\
    // - cost(l, r) = cost of [l, r]\n// - add(i) = add i to current segment\n// -\
    \ rem(i) = remove i from current segment\n// - indices from 0 to n-1\n//\n// Returns:\
    \ <best cost, left, right> where [left, right] is substring with\n//   mincost\
    \ or [-1, -1] if no solution\n//\n// Tested:\n// - https://www.spoj.com/problems/KOIREP/\n\
    //\n// Two pointers (smallest substring) {{{\ntemplate<typename Pred, typename\
    \ Cost, typename Add, typename Rem>\ntuple<long long, int, int> two_pointers(int\
    \ n, Pred pred, Cost cost, Add add, Rem rem) {\n    tuple<long long, int, int>\
    \ res {LLONG_MAX, -1, -1};\n\n    // current window is [l, r]\n    for (int l\
    \ = 0, r = -1; l < n; ++l) {\n        while (r+1 < n && !pred()) {\n         \
    \   ++r;\n            add(r);\n        }\n        if (pred()) {\n            res\
    \ = min(res, {cost(l, r), l, r});\n        }\n        rem(l);\n    }\n    return\
    \ res;\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/two_pointers.h
  requiredBy: []
  timestamp: '2022-12-15 17:04:36+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/two_pointers.h
layout: document
redirect_from:
- /library/Misc/two_pointers.h
- /library/Misc/two_pointers.h.html
title: Misc/two_pointers.h
---
