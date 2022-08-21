---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DP/tests/aizu_dpl_1_d_lis.test.cpp
    title: DP/tests/aizu_dpl_1_d_lis.test.cpp
  - icon: ':heavy_check_mark:'
    path: DP/tests/yosupo_lis.test.cpp
    title: DP/tests/yosupo_lis.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://codeforces.com/blog/entry/13225
  bundledCode: "#line 1 \"DP/lis.h\"\n// Source: http://codeforces.com/blog/entry/13225\n\
    // Non-strict.\n\nint lis_non_strict(const vector<int>& a) {\n    multiset<int>\
    \ s;\n    for (int x : a) {\n        s.insert(x);\n        auto it = s.upper_bound(x);\n\
    \n        if (it != s.end())\n            s.erase(it);\n    }\n    return s.size();\n\
    }\n\n// Strict.\nint lis_strict(const vector<int>& a) {\n    multiset<int> s;\n\
    \    for (int x : a) {\n        s.insert(x);\n        auto it = s.lower_bound(x);\n\
    \        it++;\n        \n        if (it != s.end())\n            s.erase(it);\n\
    \    }\n    return s.size();\n}\n\n// Return indices of LIS (strict)\nvector<int>\
    \ lis_strict_trace(const vector<int>& a) {\n    int n = (int) a.size();\n    vector<int>\
    \ b(n+1, 0), f(n, 0);\n    int answer = 0;\n    for (int i = 0; i < n; i++) {\n\
    \        f[i] = lower_bound(b.begin() + 1, b.begin()+answer+1, a[i]) - b.begin();\n\
    \        answer = max(answer, f[i]);\n        b[f[i]] = a[i];\n    }\n\n    int\
    \ require = answer;\n    vector<int> T;\n    for (int i = n-1; i >= 0; i--) {\n\
    \        if (f[i] == require) {\n            T.push_back(i);\n            require--;\n\
    \        }\n    }\n    reverse(T.begin(), T.end());\n    return T;\n}\n"
  code: "// Source: http://codeforces.com/blog/entry/13225\n// Non-strict.\n\nint\
    \ lis_non_strict(const vector<int>& a) {\n    multiset<int> s;\n    for (int x\
    \ : a) {\n        s.insert(x);\n        auto it = s.upper_bound(x);\n\n      \
    \  if (it != s.end())\n            s.erase(it);\n    }\n    return s.size();\n\
    }\n\n// Strict.\nint lis_strict(const vector<int>& a) {\n    multiset<int> s;\n\
    \    for (int x : a) {\n        s.insert(x);\n        auto it = s.lower_bound(x);\n\
    \        it++;\n        \n        if (it != s.end())\n            s.erase(it);\n\
    \    }\n    return s.size();\n}\n\n// Return indices of LIS (strict)\nvector<int>\
    \ lis_strict_trace(const vector<int>& a) {\n    int n = (int) a.size();\n    vector<int>\
    \ b(n+1, 0), f(n, 0);\n    int answer = 0;\n    for (int i = 0; i < n; i++) {\n\
    \        f[i] = lower_bound(b.begin() + 1, b.begin()+answer+1, a[i]) - b.begin();\n\
    \        answer = max(answer, f[i]);\n        b[f[i]] = a[i];\n    }\n\n    int\
    \ require = answer;\n    vector<int> T;\n    for (int i = n-1; i >= 0; i--) {\n\
    \        if (f[i] == require) {\n            T.push_back(i);\n            require--;\n\
    \        }\n    }\n    reverse(T.begin(), T.end());\n    return T;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/lis.h
  requiredBy: []
  timestamp: '2022-08-14 03:46:56+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DP/tests/aizu_dpl_1_d_lis.test.cpp
  - DP/tests/yosupo_lis.test.cpp
documentation_of: DP/lis.h
layout: document
redirect_from:
- /library/DP/lis.h
- /library/DP/lis.h.html
title: DP/lis.h
---
