---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Misc/vec_utils.h\"\n// Vec utils {{{\n// Given vector `a`,\
    \ commpute next[i] = position of next occurrence of a[i]\n// Returns -1 if no\
    \ next occurrence\ntemplate<typename Container>\nstd::vector<int> getNext(const\
    \ Container& a) {\n    std::map<int, int> cur;\n    std::vector<int> res(a.size());\n\
    \    int n = a.size();\n\n    for (int i = n - 1; i >= 0; --i) {\n        res[i]\
    \ = cur.count(a[i]) ? cur[a[i]] : -1;\n        cur[a[i]] = i;\n    }\n\n    return\
    \ res;\n}\n// Given vector `a`, commpute prev[i] = position of previous occurrence\
    \ of a[i]\n// Returns -1 if no previous occurrence\ntemplate<typename Container>\n\
    std::vector<int> getPrev(const Container& a) {\n    std::map<int, int> cur;\n\
    \    std::vector<int> res(a.size());\n    int n = a.size();\n\n    for (int i\
    \ = 0; i < n; ++i) {\n        res[i] = cur.count(a[i]) ? cur[a[i]] : -1;\n   \
    \     cur[a[i]] = i;\n    }\n\n    return res;\n}\n// }}}\n"
  code: "// Vec utils {{{\n// Given vector `a`, commpute next[i] = position of next\
    \ occurrence of a[i]\n// Returns -1 if no next occurrence\ntemplate<typename Container>\n\
    std::vector<int> getNext(const Container& a) {\n    std::map<int, int> cur;\n\
    \    std::vector<int> res(a.size());\n    int n = a.size();\n\n    for (int i\
    \ = n - 1; i >= 0; --i) {\n        res[i] = cur.count(a[i]) ? cur[a[i]] : -1;\n\
    \        cur[a[i]] = i;\n    }\n\n    return res;\n}\n// Given vector `a`, commpute\
    \ prev[i] = position of previous occurrence of a[i]\n// Returns -1 if no previous\
    \ occurrence\ntemplate<typename Container>\nstd::vector<int> getPrev(const Container&\
    \ a) {\n    std::map<int, int> cur;\n    std::vector<int> res(a.size());\n   \
    \ int n = a.size();\n\n    for (int i = 0; i < n; ++i) {\n        res[i] = cur.count(a[i])\
    \ ? cur[a[i]] : -1;\n        cur[a[i]] = i;\n    }\n\n    return res;\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/vec_utils.h
  requiredBy: []
  timestamp: '2022-10-04 22:36:53-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/vec_utils.h
layout: document
redirect_from:
- /library/Misc/vec_utils.h
- /library/Misc/vec_utils.h.html
title: Misc/vec_utils.h
---
