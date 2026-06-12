---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Misc/compress.h
    title: Misc/compress.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
    title: DP/tests/yosupo_cnt_distinct_subseq.test.cpp
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
    \ xs;\n};\n// }}}\n#line 2 \"DP/cnt_distinct_subseq.h\"\n\n// Returns number of\
    \ distinct, non-empty subsequences {{{\n// T = type of input elements\n// OutT\
    \ = type of output (e.g. ModInt)\ntemplate<typename T, typename OutT>\nOutT cnt_distinct_subsequences(std::vector<T>\
    \ a) {\n    auto compressor = CompressorBuilder<T>{a}.build();\n    compressor.compress_inplace(a);\n\
    \n    std::vector<OutT> f(a.size() + 1);\n    std::vector<int> last(a.size() +\
    \ 1, -1);\n    f[0] = 1;\n    for (size_t i = 0; i < a.size(); ++i) {\n      \
    \  f[i+1] = f[i] * 2;\n        if (last[a[i]] >= 0) f[i+1] -= f[last[a[i]]];\n\
    \        last[a[i]] = i;\n    }\n    return f.back() - 1;\n}\n// }}}\n"
  code: "#include \"../Misc/compress.h\"\n\n// Returns number of distinct, non-empty\
    \ subsequences {{{\n// T = type of input elements\n// OutT = type of output (e.g.\
    \ ModInt)\ntemplate<typename T, typename OutT>\nOutT cnt_distinct_subsequences(std::vector<T>\
    \ a) {\n    auto compressor = CompressorBuilder<T>{a}.build();\n    compressor.compress_inplace(a);\n\
    \n    std::vector<OutT> f(a.size() + 1);\n    std::vector<int> last(a.size() +\
    \ 1, -1);\n    f[0] = 1;\n    for (size_t i = 0; i < a.size(); ++i) {\n      \
    \  f[i+1] = f[i] * 2;\n        if (last[a[i]] >= 0) f[i+1] -= f[last[a[i]]];\n\
    \        last[a[i]] = i;\n    }\n    return f.back() - 1;\n}\n// }}}\n"
  dependsOn:
  - Misc/compress.h
  isVerificationFile: false
  path: DP/cnt_distinct_subseq.h
  requiredBy: []
  timestamp: '2022-12-26 18:08:50+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DP/tests/yosupo_cnt_distinct_subseq.test.cpp
documentation_of: DP/cnt_distinct_subseq.h
layout: document
redirect_from:
- /library/DP/cnt_distinct_subseq.h
- /library/DP/cnt_distinct_subseq.h.html
title: DP/cnt_distinct_subseq.h
---
