---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Misc/tests/pipe_utils.test.cpp
    title: Misc/tests/pipe_utils.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/submissions/Yuu
  bundledCode: "#line 1 \"Misc/container_pipe_utils.h\"\n// Container operations,\
    \ idea from https://codeforces.com/submissions/Yuu {{{\ntemplate<typename T> struct\
    \ accumulator_type { using type = T; };\ntemplate<> struct accumulator_type<int32_t>\
    \ { using type = int64_t; };\ntemplate<> struct accumulator_type<uint32_t> { using\
    \ type = uint64_t; };\ntemplate<> struct accumulator_type<int64_t> { using type\
    \ = __int128_t; };\ntemplate<> struct accumulator_type<uint64_t> { using type\
    \ = __uint128_t; };\n\nenum ReduceOp { MIN, MAX };\ntemplate<typename Container>\n\
    auto operator | (const Container& a, ReduceOp op) {\n    switch (op) {\n     \
    \   case MIN:\n            return *min_element(a.begin(), a.end());\n        case\
    \ MAX:\n            return *max_element(a.begin(), a.end());\n    }\n    assert(false);\n\
    }\nenum SumOp { SUM, SUM_XOR };\ntemplate<typename Container>\nauto operator |\
    \ (const Container& a, SumOp op) {\n    typename accumulator_type<typename Container::value_type>::type\
    \ sum{};\n    switch (op) {\n        case SUM:\n            for (const auto& elem\
    \ : a) sum += elem;\n            return sum;\n        case SUM_XOR:\n        \
    \    for (const auto& elem : a) sum ^= elem;\n            return sum;\n    }\n\
    \    assert(false);\n}\nenum ComparableOp { SORT };\ntemplate<typename Container>\n\
    Container& operator | (Container& a, ComparableOp op) {\n    __typeof(a) values;\n\
    \    switch (op) {\n        case SORT:\n            std::sort(a.begin(), a.end());\n\
    \            break;\n    }\n    return a;\n}\nenum TransformOp { ADD_1, PREFIX_SUM,\
    \ PREFIX_SUM_XOR, REVERSE, SUB_1, COMPRESS };\ntemplate<typename Container>\n\
    Container& operator | (Container& a, TransformOp op) {\n    __typeof(a) values;\n\
    \    switch (op) {\n        case ADD_1:\n            for (auto& elem : a) elem\
    \ += 1;\n            break;\n        case COMPRESS:\n            values = a;\n\
    \            std::sort(values.begin(), values.end());\n            values.erase(std::unique(values.begin(),\
    \ values.end()), values.end());\n            for (auto& value : a) value = std::lower_bound(values.begin(),\
    \ values.end(), value) - values.begin();\n            break;\n        case PREFIX_SUM:\n\
    \            std::partial_sum(a.begin(), a.end(), a.begin());\n            break;\n\
    \        case PREFIX_SUM_XOR:\n            std::partial_sum(a.begin(), a.end(),\
    \ a.begin(), [] (int x, int y) { return x ^ y; });\n            break;\n     \
    \   case REVERSE:\n            std::reverse(a.begin(), a.end());\n           \
    \ break;\n        case SUB_1:\n            for (auto& elem : a) elem -= 1;\n \
    \           break;\n    }\n    return a;\n}\nenum IOp { IN };\ntemplate<typename\
    \ Container>\nContainer& operator | (Container& a, IOp op) {\n    switch (op)\
    \ {\n        case IN:\n            for (auto& elem : a) cin >> elem;\n       \
    \     break;\n    }\n    return a;\n}\nenum OOp { OUT_ONE_PER_LINE, OUT_1_LINE\
    \ };\ntemplate<typename Container>\nContainer& operator | (Container& a, OOp op)\
    \ {\n    switch (op) {\n        case OUT_1_LINE:\n            for (size_t i =\
    \ 0; i < a.size(); ++i) {\n                if (i > 0) cout << ' ';\n         \
    \       cout << a[i];\n            }\n            break;\n        case OUT_ONE_PER_LINE:\n\
    \            for (const auto& elem : a) cout << elem << '\\n';\n            break;\n\
    \    }\n    return a;\n}\n// }}}\n"
  code: "// Container operations, idea from https://codeforces.com/submissions/Yuu\
    \ {{{\ntemplate<typename T> struct accumulator_type { using type = T; };\ntemplate<>\
    \ struct accumulator_type<int32_t> { using type = int64_t; };\ntemplate<> struct\
    \ accumulator_type<uint32_t> { using type = uint64_t; };\ntemplate<> struct accumulator_type<int64_t>\
    \ { using type = __int128_t; };\ntemplate<> struct accumulator_type<uint64_t>\
    \ { using type = __uint128_t; };\n\nenum ReduceOp { MIN, MAX };\ntemplate<typename\
    \ Container>\nauto operator | (const Container& a, ReduceOp op) {\n    switch\
    \ (op) {\n        case MIN:\n            return *min_element(a.begin(), a.end());\n\
    \        case MAX:\n            return *max_element(a.begin(), a.end());\n   \
    \ }\n    assert(false);\n}\nenum SumOp { SUM, SUM_XOR };\ntemplate<typename Container>\n\
    auto operator | (const Container& a, SumOp op) {\n    typename accumulator_type<typename\
    \ Container::value_type>::type sum{};\n    switch (op) {\n        case SUM:\n\
    \            for (const auto& elem : a) sum += elem;\n            return sum;\n\
    \        case SUM_XOR:\n            for (const auto& elem : a) sum ^= elem;\n\
    \            return sum;\n    }\n    assert(false);\n}\nenum ComparableOp { SORT\
    \ };\ntemplate<typename Container>\nContainer& operator | (Container& a, ComparableOp\
    \ op) {\n    __typeof(a) values;\n    switch (op) {\n        case SORT:\n    \
    \        std::sort(a.begin(), a.end());\n            break;\n    }\n    return\
    \ a;\n}\nenum TransformOp { ADD_1, PREFIX_SUM, PREFIX_SUM_XOR, REVERSE, SUB_1,\
    \ COMPRESS };\ntemplate<typename Container>\nContainer& operator | (Container&\
    \ a, TransformOp op) {\n    __typeof(a) values;\n    switch (op) {\n        case\
    \ ADD_1:\n            for (auto& elem : a) elem += 1;\n            break;\n  \
    \      case COMPRESS:\n            values = a;\n            std::sort(values.begin(),\
    \ values.end());\n            values.erase(std::unique(values.begin(), values.end()),\
    \ values.end());\n            for (auto& value : a) value = std::lower_bound(values.begin(),\
    \ values.end(), value) - values.begin();\n            break;\n        case PREFIX_SUM:\n\
    \            std::partial_sum(a.begin(), a.end(), a.begin());\n            break;\n\
    \        case PREFIX_SUM_XOR:\n            std::partial_sum(a.begin(), a.end(),\
    \ a.begin(), [] (int x, int y) { return x ^ y; });\n            break;\n     \
    \   case REVERSE:\n            std::reverse(a.begin(), a.end());\n           \
    \ break;\n        case SUB_1:\n            for (auto& elem : a) elem -= 1;\n \
    \           break;\n    }\n    return a;\n}\nenum IOp { IN };\ntemplate<typename\
    \ Container>\nContainer& operator | (Container& a, IOp op) {\n    switch (op)\
    \ {\n        case IN:\n            for (auto& elem : a) cin >> elem;\n       \
    \     break;\n    }\n    return a;\n}\nenum OOp { OUT_ONE_PER_LINE, OUT_1_LINE\
    \ };\ntemplate<typename Container>\nContainer& operator | (Container& a, OOp op)\
    \ {\n    switch (op) {\n        case OUT_1_LINE:\n            for (size_t i =\
    \ 0; i < a.size(); ++i) {\n                if (i > 0) cout << ' ';\n         \
    \       cout << a[i];\n            }\n            break;\n        case OUT_ONE_PER_LINE:\n\
    \            for (const auto& elem : a) cout << elem << '\\n';\n            break;\n\
    \    }\n    return a;\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/container_pipe_utils.h
  requiredBy: []
  timestamp: '2023-05-21 16:46:44+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Misc/tests/pipe_utils.test.cpp
documentation_of: Misc/container_pipe_utils.h
layout: document
redirect_from:
- /library/Misc/container_pipe_utils.h
- /library/Misc/container_pipe_utils.h.html
title: Misc/container_pipe_utils.h
---
