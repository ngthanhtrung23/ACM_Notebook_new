---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp
    title: Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: Misc/tests/aizu_dpl_3_c_largest_histogram.test.cpp
    title: Misc/tests/aizu_dpl_3_c_largest_histogram.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1142
    - https://cses.fi/problemset/task/1645
    - https://oj.vnoi.info/problem/kagain
  bundledCode: "#line 1 \"Misc/left_nearest_smaller.h\"\n// Tested:\n// - https://cses.fi/problemset/task/1645\n\
    // - https://cses.fi/problemset/task/1142\n// - https://oj.vnoi.info/problem/kagain\n\
    //\n// return:\n// - left[i] = largest j such that\n//      j < i\n//      a[j]\
    \ < a[i]\n// - no such j -> left[i] = -1\nvector<int> leftNearestSmaller(const\
    \ vector<int>& a) {\n    int n = a.size();\n    vector<int> left(n);\n    stack<int>\
    \ st;  // positions of candidates, A is increasing\n    st.push(-1);\n    for\
    \ (int i = 0; i < n; i++) {\n        while (st.top() >= 0 && a[st.top()] >= a[i])\
    \ st.pop();\n        left[i] = st.top();\n        st.push(i);\n    }\n    return\
    \ left;\n}\n\n// return:\n// - right[i] = smallest j such that:\n//      j > i\n\
    //      a[j] < a[i]\n// - no such j -> right[i] = n\nvector<int> rightNearestSmaller(const\
    \ vector<int>& a) {\n    int n = a.size();\n    vector<int> right(n);\n    stack<int>\
    \ st;   // positions of candidates, A is increasing\n    st.push(n);\n    for\
    \ (int i = n-1; i >= 0; i--) {\n        while (st.top() < n && a[st.top()] >=\
    \ a[i]) st.pop();\n        right[i] = st.top();\n        st.push(i);\n    }\n\
    \    return right;\n}\n"
  code: "// Tested:\n// - https://cses.fi/problemset/task/1645\n// - https://cses.fi/problemset/task/1142\n\
    // - https://oj.vnoi.info/problem/kagain\n//\n// return:\n// - left[i] = largest\
    \ j such that\n//      j < i\n//      a[j] < a[i]\n// - no such j -> left[i] =\
    \ -1\nvector<int> leftNearestSmaller(const vector<int>& a) {\n    int n = a.size();\n\
    \    vector<int> left(n);\n    stack<int> st;  // positions of candidates, A is\
    \ increasing\n    st.push(-1);\n    for (int i = 0; i < n; i++) {\n        while\
    \ (st.top() >= 0 && a[st.top()] >= a[i]) st.pop();\n        left[i] = st.top();\n\
    \        st.push(i);\n    }\n    return left;\n}\n\n// return:\n// - right[i]\
    \ = smallest j such that:\n//      j > i\n//      a[j] < a[i]\n// - no such j\
    \ -> right[i] = n\nvector<int> rightNearestSmaller(const vector<int>& a) {\n \
    \   int n = a.size();\n    vector<int> right(n);\n    stack<int> st;   // positions\
    \ of candidates, A is increasing\n    st.push(n);\n    for (int i = n-1; i >=\
    \ 0; i--) {\n        while (st.top() < n && a[st.top()] >= a[i]) st.pop();\n \
    \       right[i] = st.top();\n        st.push(i);\n    }\n    return right;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/left_nearest_smaller.h
  requiredBy: []
  timestamp: '2022-01-09 02:17:25+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Misc/tests/aizu_dpl_3_c_largest_histogram.test.cpp
  - Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp
documentation_of: Misc/left_nearest_smaller.h
layout: document
redirect_from:
- /library/Misc/left_nearest_smaller.h
- /library/Misc/left_nearest_smaller.h.html
title: Misc/left_nearest_smaller.h
---
