---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/lca.test.cpp
    title: DataStructure/test/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/rmq.test.cpp
    title: DataStructure/test/rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"DataStructure/RMQ.h\"\n// Sparse table\n// Usage:\n// RMQ<int,\
    \ _min> st(v);\n//\n// Note:\n// - doesn't work for empty range\n//\n// Tested:\n\
    // - https://judge.yosupo.jp/problem/staticrmq\ntemplate<class T, T (*op) (T,\
    \ T)> struct RMQ {\n    RMQ() = default;\n    RMQ(const vector<T>& v) : t{v} {\n\
    \        for (int k = 1, n = (int) v.size(); (1<<k) <= n; ++k) {\n           \
    \ t.emplace_back(n - (1<<k) + 1);\n            for (int i = 0; i + (1<<k) <= n;\
    \ ++i) {\n                t[k][i] = op(t[k-1][i], t[k-1][i + (1<<(k-1))]);\n \
    \           }\n        }\n    }\n\n    // get range [l, r-1]\n    // doesn't work\
    \ for empty range\n    T get(int l, int r) const {\n        assert(l < r);\n \
    \       int k = __lg(r - l);\n        return op(t[k][l], t[k][r - (1<<k)]);\n\
    \    }\n\nprivate:\n    vector<vector<T>> t;\n};\ntemplate<class T> T _min(T a,\
    \ T b) { return b < a ? b : a; }\ntemplate<class T> T _max(T a, T b) { return\
    \ a < b ? b : a; }\n"
  code: "// Sparse table\n// Usage:\n// RMQ<int, _min> st(v);\n//\n// Note:\n// -\
    \ doesn't work for empty range\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/staticrmq\n\
    template<class T, T (*op) (T, T)> struct RMQ {\n    RMQ() = default;\n    RMQ(const\
    \ vector<T>& v) : t{v} {\n        for (int k = 1, n = (int) v.size(); (1<<k) <=\
    \ n; ++k) {\n            t.emplace_back(n - (1<<k) + 1);\n            for (int\
    \ i = 0; i + (1<<k) <= n; ++i) {\n                t[k][i] = op(t[k-1][i], t[k-1][i\
    \ + (1<<(k-1))]);\n            }\n        }\n    }\n\n    // get range [l, r-1]\n\
    \    // doesn't work for empty range\n    T get(int l, int r) const {\n      \
    \  assert(l < r);\n        int k = __lg(r - l);\n        return op(t[k][l], t[k][r\
    \ - (1<<k)]);\n    }\n\nprivate:\n    vector<vector<T>> t;\n};\ntemplate<class\
    \ T> T _min(T a, T b) { return b < a ? b : a; }\ntemplate<class T> T _max(T a,\
    \ T b) { return a < b ? b : a; }\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RMQ.h
  requiredBy: []
  timestamp: '2021-12-29 18:21:32+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/lca.test.cpp
  - DataStructure/test/rmq.test.cpp
documentation_of: DataStructure/RMQ.h
layout: document
redirect_from:
- /library/DataStructure/RMQ.h
- /library/DataStructure/RMQ.h.html
title: DataStructure/RMQ.h
---
