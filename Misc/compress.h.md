---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DP/cnt_distinct_subseq.h
    title: DP/cnt_distinct_subseq.h
  - icon: ':heavy_check_mark:'
    path: DP/count_inversions.h
    title: DP/count_inversions.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick/Fenwick2D.h
    title: DataStructure/Fenwick/Fenwick2D.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
    title: DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
  - icon: ':heavy_check_mark:'
    path: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
    title: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
    title: DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/fenwick_2d_rectsum.test.cpp
    title: DataStructure/test/fenwick_2d_rectsum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://suisen-cp.github.io/cp-library-cpp/library/util/coordinate_compressor.hpp
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
    \ xs;\n};\n// }}}\n"
  code: "// Compressor {{{\n/* Example usage:\n    auto compressor = CompressorBuilder<T>{vs}.build();\n\
    \    int x = compessor.must_eq(vs[0]);\n    compressor.compress_inplace(vs);\n\
    */\n// Based on https://suisen-cp.github.io/cp-library-cpp/library/util/coordinate_compressor.hpp\n\
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
    \ xs;\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/compress.h
  requiredBy:
  - DataStructure/Fenwick/Fenwick2D.h
  - DP/cnt_distinct_subseq.h
  - DP/count_inversions.h
  timestamp: '2022-12-22 10:28:54+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
  - DataStructure/test/fenwick_2d_rectsum.test.cpp
  - DP/tests/yosupo_cnt_distinct_subseq.test.cpp
  - DP/tests/aizu_alds1_5_d_count_inversions.test.cpp
documentation_of: Misc/compress.h
layout: document
redirect_from:
- /library/Misc/compress.h
- /library/Misc/compress.h.html
title: Misc/compress.h
---
