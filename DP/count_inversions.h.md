---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick.h
    title: DataStructure/Fenwick.h
  - icon: ':heavy_check_mark:'
    path: Misc/compress.h
    title: Misc/compress.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
    title: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Misc/compress.h\"\n// Compress vector vs, and return the\
    \ compressed vector\n// Returned values in [0, k-1] where k = number of different\
    \ values\ntemplate<typename V>\nV compress(V vs) {\n    auto vals = vs;\n    sort(vals.begin(),\
    \ vals.end());\n    vals.erase(unique(vals.begin(), vals.end()), vals.end());\n\
    \n    for (auto& v : vs) {\n        v = lower_bound(vals.begin(), vals.end(),\
    \ v) - vals.begin();\n    }\n    return vs;\n}\n#line 1 \"DataStructure/Fenwick.h\"\
    \n// 1D Fenwick\n// 0 based index\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/static_range_sum\n\
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
    \ }\n\n    int n;\n    vector<T> f;\n};\n#line 3 \"DP/count_inversions.h\"\n\n\
    // Given vector vs, return number of inversions\ntemplate<typename T>\nlong long\
    \ count_inversions(vector<T> vs) {\n    int n = vs.size();\n    vs = compress(vs);\n\
    \    Fenwick<int> bit(n);\n\n    long long res = 0;\n    for (auto v : vs) {\n\
    \        res += bit.get(v+1, n);\n        bit.update(v, +1);\n    }\n    return\
    \ res;\n}\n"
  code: "#include \"../Misc/compress.h\"\n#include \"../DataStructure/Fenwick.h\"\n\
    \n// Given vector vs, return number of inversions\ntemplate<typename T>\nlong\
    \ long count_inversions(vector<T> vs) {\n    int n = vs.size();\n    vs = compress(vs);\n\
    \    Fenwick<int> bit(n);\n\n    long long res = 0;\n    for (auto v : vs) {\n\
    \        res += bit.get(v+1, n);\n        bit.update(v, +1);\n    }\n    return\
    \ res;\n}\n"
  dependsOn:
  - Misc/compress.h
  - DataStructure/Fenwick.h
  isVerificationFile: false
  path: DP/count_inversions.h
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
documentation_of: DP/count_inversions.h
layout: document
redirect_from:
- /library/DP/count_inversions.h
- /library/DP/count_inversions.h.html
title: DP/count_inversions.h
---
