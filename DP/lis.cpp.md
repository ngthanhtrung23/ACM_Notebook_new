---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/blog/entry/13225
  bundledCode: "#line 1 \"DP/lis.cpp\"\n// Source: http://codeforces.com/blog/entry/13225\n\
    // Non-strict.\n\nint lis_non_strict(const vector<int>& a) {\n    multiset<int>\
    \ s;\n    for (int x : a) {\n        s.insert(x);\n        auto it = s.upper_bound(x);\n\
    \n        if (it != s.end())\n            s.erase(it);\n    }\n    return s.size();\n\
    }\n\n// Strict.\nint lis_strict(const vector<int>& a) {\n    multiset<int> s;\n\
    \    for (int x : a) {\n        s.insert(x);\n        auto it = s.lower_bound(x);\n\
    \        it++;\n        \n        if (it != s.end())\n            s.erase(it);\n\
    \    }\n    return s.size();\n}\n\n// Trace\nvector<int> lis_trace(const vector<int>&\
    \ a) {\n    int n = (int) a.size();\n    vector<int> b(n+1, 0);\n    int answer\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        f[i] = lower_bound(b+1, b+answer+1,\
    \ a[i]) - b;\n        answer = max(answer, f[i]);\n        b[f[i]] = a[i];\n \
    \   }\n\n    int require = answer;\n    vector<int> T;\n    for (int i = n-1;\
    \ i >= 0; i--) {\n        if (f[i] == require) {\n            T.push_back(a[i]);\n\
    \            require--;\n        }\n    }\n    reverse(T.begin(), T.end());\n\
    \    return T;\n}\n"
  code: "// Source: http://codeforces.com/blog/entry/13225\n// Non-strict.\n\nint\
    \ lis_non_strict(const vector<int>& a) {\n    multiset<int> s;\n    for (int x\
    \ : a) {\n        s.insert(x);\n        auto it = s.upper_bound(x);\n\n      \
    \  if (it != s.end())\n            s.erase(it);\n    }\n    return s.size();\n\
    }\n\n// Strict.\nint lis_strict(const vector<int>& a) {\n    multiset<int> s;\n\
    \    for (int x : a) {\n        s.insert(x);\n        auto it = s.lower_bound(x);\n\
    \        it++;\n        \n        if (it != s.end())\n            s.erase(it);\n\
    \    }\n    return s.size();\n}\n\n// Trace\nvector<int> lis_trace(const vector<int>&\
    \ a) {\n    int n = (int) a.size();\n    vector<int> b(n+1, 0);\n    int answer\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        f[i] = lower_bound(b+1, b+answer+1,\
    \ a[i]) - b;\n        answer = max(answer, f[i]);\n        b[f[i]] = a[i];\n \
    \   }\n\n    int require = answer;\n    vector<int> T;\n    for (int i = n-1;\
    \ i >= 0; i--) {\n        if (f[i] == require) {\n            T.push_back(a[i]);\n\
    \            require--;\n        }\n    }\n    reverse(T.begin(), T.end());\n\
    \    return T;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/lis.cpp
  requiredBy: []
  timestamp: '2021-12-29 03:24:01+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/lis.cpp
layout: document
redirect_from:
- /library/DP/lis.cpp
- /library/DP/lis.cpp.html
title: DP/lis.cpp
---
