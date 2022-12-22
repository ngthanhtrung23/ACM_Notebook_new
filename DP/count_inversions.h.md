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
  bundledCode: "#line 1 \"Misc/compress.h\"\n// Compressor {{{\n/* Example usage:\n\
    \    auto compressor = CompressorBuilder<T>{vs}.build();\n    int x = compessor.must_eq(vs[0]);\n\
    \    compressor.compress_inplace(vs);\n*/\n// Based on https://suisen-cp.github.io/cp-library-cpp/library/util/coordinate_compressor.hpp\n\
    template<typename T>\nstruct CompressorBuilder {\n    // Do not use directly.\
    \ Use builder.build()\n    struct Compressor {\n        // Number of unique keys\n\
    \        int size() const { return xs.size(); }\n\n        void compress_inplace(std::vector<T>&\
    \ vals) {\n            for (int& val : vals) {\n                val = must_eq(val);\n\
    \            }\n        }\n\n        [[nodiscard]] std::vector<T> compress(const\
    \ std::vector<T>& vals) {\n            std::vector<T> res(vals.size());\n    \
    \        for (int i = 0; i < static_cast<int> (res.size()); ++i) {\n         \
    \       res[i] = must_eq(vals[i]);\n            }\n            return res;\n \
    \       }\n\n        bool has_key(const T& key) const {\n            return std::binary_search(xs.begin(),\
    \ xs.end(), key);\n        }\n\n#define LB(key) std::lower_bound(xs.begin(), xs.end(),\
    \ key)\n#define UB(key) std::upper_bound(xs.begin(), xs.end(), key)\n        std::optional<int>\
    \ eq(const T& key) {\n            auto it = LB(key);\n            return it ==\
    \ xs.end() ? std::nullopt : std::optional<int>{it - xs.begin()};\n        }\n\
    \        std::optional<int> geq(const T& key) {\n            auto it = LB(key);\n\
    \            return it == xs.end() ? std::nullopt : std::optional<int>{it - xs.begin()};\n\
    \        }\n        std::optional<int> gt(const T& key) {\n            auto it\
    \ = UB(key);\n            return it == xs.end() ? std::nullopt : std::optional<int>{it\
    \ - xs.begin()};\n        }\n        std::optional<int> leq(const T& key) {\n\
    \            auto it = UB(key);\n            return it == xs.begin() ? std::nullopt\
    \ : std::optional<int>{it - xs.begin() - 1};\n        }\n        std::optional<int>\
    \ lt(const T& key) {\n            auto it = LB(key);\n            return it ==\
    \ xs.begin() ? std::nullopt : std::optional<int>{it - xs.begin() - 1};\n     \
    \   }\n\n        // throw exception if no such key is found\n        int must_eq(const\
    \ T& key) {\n            auto it = LB(key);\n            assert(it != xs.end());\n\
    \            return it - xs.begin();\n        }\n        // throw exception if\
    \ no such key is found\n        int must_geq(const T& key) {\n            auto\
    \ it = LB(key);\n            assert(it != xs.end());\n            return it -\
    \ xs.begin();\n        }\n        // throw exception if no such key is found\n\
    \        int must_gt(const T& key) {\n            auto it = UB(key);\n       \
    \     assert(it != xs.end());\n            return it - xs.begin();\n        }\n\
    \        // throw exception if no such key is found\n        int must_leq(const\
    \ T& key) {\n            auto it = UB(key);\n            assert(it != xs.begin());\n\
    \            return it - xs.begin() - 1;\n        }\n        // throw exception\
    \ if no such key is found\n        int must_lt(const T& key) {\n            auto\
    \ it = LB(key);\n            assert(it != xs.begin());\n            return it\
    \ - xs.begin() - 1;\n        }\n#undef LB\n#undef UB\n\n        std::vector<T>\
    \ xs;\n    };\n\n    auto build() {\n        std::sort(xs.begin(), xs.end());\n\
    \        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n        return\
    \ Compressor{xs};\n    }\n\n    void add(const T& key) { xs.push_back(key); }\n\
    \    void add(T&& key) { xs.push_back(std::move(key)); }\n\n    std::vector<T>\
    \ xs;\n};\n// }}}\n#line 1 \"DataStructure/Fenwick.h\"\n// 1D Fenwick {{{\n//\
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
    \ }\n\n    int n;\n    vector<T> f;\n};\n// }}}\n#line 3 \"DP/count_inversions.h\"\
    \n\n// Given vector vs, return number of inversions\ntemplate<typename T>\nlong\
    \ long count_inversions(vector<T> vs) {\n    int n = vs.size();\n    auto compressor\
    \ = CompressorBuilder<T>{vs}.build();\n    compressor.compress_inplace(vs);\n\
    \    Fenwick<int> bit(n);\n\n    long long res = 0;\n    for (auto v : vs) {\n\
    \        res += bit.get(v+1, n);\n        bit.update(v, +1);\n    }\n    return\
    \ res;\n}\n"
  code: "#include \"../Misc/compress.h\"\n#include \"../DataStructure/Fenwick.h\"\n\
    \n// Given vector vs, return number of inversions\ntemplate<typename T>\nlong\
    \ long count_inversions(vector<T> vs) {\n    int n = vs.size();\n    auto compressor\
    \ = CompressorBuilder<T>{vs}.build();\n    compressor.compress_inplace(vs);\n\
    \    Fenwick<int> bit(n);\n\n    long long res = 0;\n    for (auto v : vs) {\n\
    \        res += bit.get(v+1, n);\n        bit.update(v, +1);\n    }\n    return\
    \ res;\n}\n"
  dependsOn:
  - Misc/compress.h
  - DataStructure/Fenwick.h
  isVerificationFile: false
  path: DP/count_inversions.h
  requiredBy: []
  timestamp: '2022-12-22 10:28:54+08:00'
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
