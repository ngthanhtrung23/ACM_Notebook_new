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
    - https://codeforces.com/submissions/Yuu
  bundledCode: "#line 1 \"Misc/container_pipe_utils.h\"\n// Container operations,\
    \ idea from https://codeforces.com/submissions/Yuu {{{\ntemplate<typename T> struct\
    \ accumulator_type { using type = T; };\ntemplate<> struct accumulator_type<int32_t>\
    \ { using type = int64_t; };\ntemplate<> struct accumulator_type<uint32_t> { using\
    \ type = uint64_t; };\ntemplate<> struct accumulator_type<int64_t> { using type\
    \ = __int128_t; };\ntemplate<> struct accumulator_type<uint64_t> { using type\
    \ = __uint128_t; };\n\nenum ReduceOperator { MIN, MAX, CNT_MAX };\ntemplate<typename\
    \ Container>\nauto operator | (const Container& a, ReduceOperator op) {\n    switch\
    \ (op) {\n        case MIN:\n            return *min_element(a.begin(), a.end());\n\
    \        case MAX:\n            return *max_element(a.begin(), a.end());\n   \
    \     case CNT_MAX:\n            auto ma = *max_element(a.begin(), a.end());\n\
    \            int cnt = 0;\n            for (const auto& elem : a) cnt += elem\
    \ == ma;\n            return cnt;\n    }\n    assert(false);\n}\nenum SumOperator\
    \ { SUM, SUM_XOR };\ntemplate<typename Container>\nauto operator | (const Container&\
    \ a, SumOperator op) {\n    typename accumulator_type<typename Container::value_type>::type\
    \ sum{};\n    switch (op) {\n        case SUM:\n            for (const auto& elem\
    \ : a) sum += elem;\n            return sum;\n        case SUM_XOR:\n        \
    \    for (const auto& elem : a) sum ^= elem;\n            return sum;\n    }\n\
    \    assert(false);\n}\nenum ComparableOperator { SORT };\ntemplate<typename Container>\n\
    Container& operator | (Container& a, ComparableOperator op) {\n    __typeof(a)\
    \ values;\n    switch (op) {\n        case SORT:\n            std::sort(a.begin(),\
    \ a.end());\n            break;\n    }\n    return a;\n}\nenum TransformOperator\
    \ { ADD_1, PREFIX_SUM, PREFIX_SUM_XOR, REVERSE, SUB_1, COMPRESS };\ntemplate<typename\
    \ Container>\nContainer& operator | (Container& a, TransformOperator op) {\n \
    \   __typeof(a) values;\n    switch (op) {\n        case ADD_1:\n            for\
    \ (auto& elem : a) elem += 1;\n            break;\n        case COMPRESS:\n  \
    \          values = a;\n            std::sort(values.begin(), values.end());\n\
    \            values.erase(std::unique(values.begin(), values.end()), values.end());\n\
    \            for (auto& value : a) value = std::lower_bound(values.begin(), values.end(),\
    \ value) - values.begin();\n            break;\n        case PREFIX_SUM:\n   \
    \         std::partial_sum(a.begin(), a.end(), a.begin());\n            break;\n\
    \        case PREFIX_SUM_XOR:\n            std::partial_sum(a.begin(), a.end(),\
    \ a.begin(), [] (int x, int y) { return x ^ y; });\n            break;\n     \
    \   case REVERSE:\n            std::reverse(a.begin(), a.end());\n           \
    \ break;\n        case SUB_1:\n            for (auto& elem : a) elem -= 1;\n \
    \           break;\n    }\n    return a;\n}\nenum IOOperator { IN, OUT_ONE_PER_LINE,\
    \ OUT_1_LINE };\ntemplate<typename Container>\nContainer& operator | (Container&\
    \ a, IOOperator op) {\n    switch (op) {\n        case IN:\n            for (auto&\
    \ elem : a) cin >> elem;\n            break;\n        case OUT_1_LINE:\n     \
    \       for (const auto& elem : a) cout << elem << ' ';\n            break;\n\
    \        case OUT_ONE_PER_LINE:\n            for (const auto& elem : a) cout <<\
    \ elem << '\\n';\n            break;\n    }\n    return a;\n}\n// }}}\n"
  code: "// Container operations, idea from https://codeforces.com/submissions/Yuu\
    \ {{{\ntemplate<typename T> struct accumulator_type { using type = T; };\ntemplate<>\
    \ struct accumulator_type<int32_t> { using type = int64_t; };\ntemplate<> struct\
    \ accumulator_type<uint32_t> { using type = uint64_t; };\ntemplate<> struct accumulator_type<int64_t>\
    \ { using type = __int128_t; };\ntemplate<> struct accumulator_type<uint64_t>\
    \ { using type = __uint128_t; };\n\nenum ReduceOperator { MIN, MAX, CNT_MAX };\n\
    template<typename Container>\nauto operator | (const Container& a, ReduceOperator\
    \ op) {\n    switch (op) {\n        case MIN:\n            return *min_element(a.begin(),\
    \ a.end());\n        case MAX:\n            return *max_element(a.begin(), a.end());\n\
    \        case CNT_MAX:\n            auto ma = *max_element(a.begin(), a.end());\n\
    \            int cnt = 0;\n            for (const auto& elem : a) cnt += elem\
    \ == ma;\n            return cnt;\n    }\n    assert(false);\n}\nenum SumOperator\
    \ { SUM, SUM_XOR };\ntemplate<typename Container>\nauto operator | (const Container&\
    \ a, SumOperator op) {\n    typename accumulator_type<typename Container::value_type>::type\
    \ sum{};\n    switch (op) {\n        case SUM:\n            for (const auto& elem\
    \ : a) sum += elem;\n            return sum;\n        case SUM_XOR:\n        \
    \    for (const auto& elem : a) sum ^= elem;\n            return sum;\n    }\n\
    \    assert(false);\n}\nenum ComparableOperator { SORT };\ntemplate<typename Container>\n\
    Container& operator | (Container& a, ComparableOperator op) {\n    __typeof(a)\
    \ values;\n    switch (op) {\n        case SORT:\n            std::sort(a.begin(),\
    \ a.end());\n            break;\n    }\n    return a;\n}\nenum TransformOperator\
    \ { ADD_1, PREFIX_SUM, PREFIX_SUM_XOR, REVERSE, SUB_1, COMPRESS };\ntemplate<typename\
    \ Container>\nContainer& operator | (Container& a, TransformOperator op) {\n \
    \   __typeof(a) values;\n    switch (op) {\n        case ADD_1:\n            for\
    \ (auto& elem : a) elem += 1;\n            break;\n        case COMPRESS:\n  \
    \          values = a;\n            std::sort(values.begin(), values.end());\n\
    \            values.erase(std::unique(values.begin(), values.end()), values.end());\n\
    \            for (auto& value : a) value = std::lower_bound(values.begin(), values.end(),\
    \ value) - values.begin();\n            break;\n        case PREFIX_SUM:\n   \
    \         std::partial_sum(a.begin(), a.end(), a.begin());\n            break;\n\
    \        case PREFIX_SUM_XOR:\n            std::partial_sum(a.begin(), a.end(),\
    \ a.begin(), [] (int x, int y) { return x ^ y; });\n            break;\n     \
    \   case REVERSE:\n            std::reverse(a.begin(), a.end());\n           \
    \ break;\n        case SUB_1:\n            for (auto& elem : a) elem -= 1;\n \
    \           break;\n    }\n    return a;\n}\nenum IOOperator { IN, OUT_ONE_PER_LINE,\
    \ OUT_1_LINE };\ntemplate<typename Container>\nContainer& operator | (Container&\
    \ a, IOOperator op) {\n    switch (op) {\n        case IN:\n            for (auto&\
    \ elem : a) cin >> elem;\n            break;\n        case OUT_1_LINE:\n     \
    \       for (const auto& elem : a) cout << elem << ' ';\n            break;\n\
    \        case OUT_ONE_PER_LINE:\n            for (const auto& elem : a) cout <<\
    \ elem << '\\n';\n            break;\n    }\n    return a;\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/container_pipe_utils.h
  requiredBy: []
  timestamp: '2023-01-04 02:50:55+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/container_pipe_utils.h
layout: document
redirect_from:
- /library/Misc/container_pipe_utils.h
- /library/Misc/container_pipe_utils.h.html
title: Misc/container_pipe_utils.h
---