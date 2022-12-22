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
    \ from https://codeforces.com/submissions/Yuu {{{\nenum ReduceOperator { MIN,\
    \ MAX };\ntemplate<typename Container>\nauto operator | (const Container& a, ReduceOperator\
    \ op) {\n\tswitch (op) {\n\t\tcase MIN:\n\t\t\treturn *min_element(a.begin(),\
    \ a.end());\n\t\tcase MAX:\n\t\t\treturn *max_element(a.begin(), a.end());\n\t\
    \tdefault:\n\t\t\tcerr << \"OP NOT DEFINED\" << endl;\n            assert(false);\n\
    \t}\n}\nenum TransformOperator { PREFIX_SUM };\ntemplate<typename Container>\n\
    auto operator | (Container& a, TransformOperator op) {\n    switch (op) {\n  \
    \      case PREFIX_SUM:\n            std::partial_sum(a.begin(), a.end(), a.begin());\n\
    \            break;\n        default:\n\t\t\tcerr << \"OP NOT DEFINED\" << endl;\n\
    \            assert(false);\n    }\n    return a;\n}\nenum IOOperator { IN, OUT_ONE_PER_LINE\
    \ };\ntemplate<typename Container>\nauto operator | (Container& a, IOOperator\
    \ op) {\n    switch (op) {\n        case IN:\n            for (auto& elem : a)\
    \ cin >> elem;\n            break;\n        case OUT_ONE_PER_LINE:\n         \
    \   for (const auto& elem : a) cout << elem << '\\n';\n            break;\n  \
    \      default:\n\t\t\tcerr << \"OP NOT DEFINED\" << endl;\n            assert(false);\n\
    \    }\n    return a;\n}\n// }}}\n"
  code: "// Container operations, from https://codeforces.com/submissions/Yuu {{{\n\
    enum ReduceOperator { MIN, MAX };\ntemplate<typename Container>\nauto operator\
    \ | (const Container& a, ReduceOperator op) {\n\tswitch (op) {\n\t\tcase MIN:\n\
    \t\t\treturn *min_element(a.begin(), a.end());\n\t\tcase MAX:\n\t\t\treturn *max_element(a.begin(),\
    \ a.end());\n\t\tdefault:\n\t\t\tcerr << \"OP NOT DEFINED\" << endl;\n       \
    \     assert(false);\n\t}\n}\nenum TransformOperator { PREFIX_SUM };\ntemplate<typename\
    \ Container>\nauto operator | (Container& a, TransformOperator op) {\n    switch\
    \ (op) {\n        case PREFIX_SUM:\n            std::partial_sum(a.begin(), a.end(),\
    \ a.begin());\n            break;\n        default:\n\t\t\tcerr << \"OP NOT DEFINED\"\
    \ << endl;\n            assert(false);\n    }\n    return a;\n}\nenum IOOperator\
    \ { IN, OUT_ONE_PER_LINE };\ntemplate<typename Container>\nauto operator | (Container&\
    \ a, IOOperator op) {\n    switch (op) {\n        case IN:\n            for (auto&\
    \ elem : a) cin >> elem;\n            break;\n        case OUT_ONE_PER_LINE:\n\
    \            for (const auto& elem : a) cout << elem << '\\n';\n            break;\n\
    \        default:\n\t\t\tcerr << \"OP NOT DEFINED\" << endl;\n            assert(false);\n\
    \    }\n    return a;\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/container_pipe_utils.h
  requiredBy: []
  timestamp: '2022-12-22 10:28:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/container_pipe_utils.h
layout: document
redirect_from:
- /library/Misc/container_pipe_utils.h
- /library/Misc/container_pipe_utils.h.html
title: Misc/container_pipe_utils.h
---
