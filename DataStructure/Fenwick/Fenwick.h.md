---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DP/count_inversions.h
    title: DP/count_inversions.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
    title: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp
    title: DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/fenwick.test.cpp
    title: DataStructure/test/fenwick.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/fenwick_pointaddrangesum.test.cpp
    title: DataStructure/test/fenwick_pointaddrangesum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"DataStructure/Fenwick/Fenwick.h\"\n// 1D Fenwick {{{\n//\
    \ 0 based index\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/static_range_sum\n\
    // - https://judge.yosupo.jp/problem/point_add_range_sum\ntemplate<\n    typename\
    \ T  // need to support operators + -\n> struct Fenwick {\n    Fenwick(int _n)\
    \ : n(_n), f(_n + 1) {}\n\n    // a[u] += val\n    void update(int u, T val) {\n\
    \        assert(0 <= u && u < n);\n        ++u;\n        for (; u <= n; u += u\
    \ & -u) {\n            f[u] += val;\n        }\n    }\n\n    // return a[0] +\
    \ .. + a[u-1]\n    T get(int u) const {\n        assert(0 <= u && u <= n);\n \
    \       T res = 0;\n        for (; u > 0; u -= u & -u) {\n            res += f[u];\n\
    \        }\n        return res;\n    }\n\n    // return a[l] + .. + a[r-1]\n \
    \   T get(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r) return 0;  // empty\n        return get(r) - get(l);\n  \
    \  }\n\n    void reset() {\n        std::fill(f.begin(), f.end(), T(0));\n   \
    \ }\n\n    int n;\n    vector<T> f;\n};\n// }}}\n"
  code: "// 1D Fenwick {{{\n// 0 based index\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/static_range_sum\n\
    // - https://judge.yosupo.jp/problem/point_add_range_sum\ntemplate<\n    typename\
    \ T  // need to support operators + -\n> struct Fenwick {\n    Fenwick(int _n)\
    \ : n(_n), f(_n + 1) {}\n\n    // a[u] += val\n    void update(int u, T val) {\n\
    \        assert(0 <= u && u < n);\n        ++u;\n        for (; u <= n; u += u\
    \ & -u) {\n            f[u] += val;\n        }\n    }\n\n    // return a[0] +\
    \ .. + a[u-1]\n    T get(int u) const {\n        assert(0 <= u && u <= n);\n \
    \       T res = 0;\n        for (; u > 0; u -= u & -u) {\n            res += f[u];\n\
    \        }\n        return res;\n    }\n\n    // return a[l] + .. + a[r-1]\n \
    \   T get(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r) return 0;  // empty\n        return get(r) - get(l);\n  \
    \  }\n\n    void reset() {\n        std::fill(f.begin(), f.end(), T(0));\n   \
    \ }\n\n    int n;\n    vector<T> f;\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Fenwick/Fenwick.h
  requiredBy:
  - DP/count_inversions.h
  timestamp: '2023-01-07 01:54:04+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/fenwick_pointaddrangesum.test.cpp
  - DataStructure/test/fenwick.test.cpp
  - DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp
  - DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
documentation_of: DataStructure/Fenwick/Fenwick.h
layout: document
redirect_from:
- /library/DataStructure/Fenwick/Fenwick.h
- /library/DataStructure/Fenwick/Fenwick.h.html
title: DataStructure/Fenwick/Fenwick.h
---
