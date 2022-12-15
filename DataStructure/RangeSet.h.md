---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_2_d_rangeset.test.cpp
    title: DataStructure/test/aizu_dsl_2_d_rangeset.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/aizu_dsl_4_a_range_set.test.cpp
    title: DataStructure/test/aizu_dsl_4_a_range_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/yukicoder_674_range_set.test.cpp
    title: DataStructure/test/yukicoder_674_range_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://suisen-cp.github.io/cp-library-cpp/library/datastructure/util/range_set.hpp
  bundledCode: "#line 1 \"DataStructure/RangeSet.h\"\n// RangeSet - for maintaining\
    \ set of segments {{{\n//\n// merge_adjacent_segment = true -> merge 2 consecutive\
    \ segments,\n// e.g. [1, 10] and [11, 20] --> [1, 20]\n//\n// Based on https://suisen-cp.github.io/cp-library-cpp/library/datastructure/util/range_set.hpp\n\
    template<typename T, bool merge_adjacent_segment = true>\nstruct RangeSet {\n\
    \    T n_elements() const { return sz; }\n    T n_ranges() const { return ranges.size();\
    \ }\n\n    bool contains(T x) const {\n        auto it = ranges.upper_bound(x);\n\
    \        return it != ranges.begin() && x <= std::prev(it)->second;\n    }\n\n\
    \    // Find range containing x, i.e. l <= x <= r\n    std::optional<std::pair<T,\
    \ T>> find_range(T x) const {\n        auto it = ranges.upper_bound(x);\n    \
    \    if (it == ranges.begin()) return std::nullopt;\n        --it;\n        return\
    \ (x <= it->second) ? std::optional<std::pair<T, T>>{*it} : std::nullopt;\n  \
    \  }\n\n    // Insert [l, r]\n    // Returns number of new integers added.\n \
    \   // AMORTIZED O(logN)\n    T insert(T l, T r) {\n        assert(l <= r);\n\
    \        auto it = ranges.upper_bound(l);\n        if (it != ranges.begin() &&\
    \ is_mergeable(std::prev(it)->second, l)) {\n            it = std::prev(it);\n\
    \            l = std::min(l, it->first);\n        }\n        T inserted = 0;\n\
    \        for (; it != ranges.end() && is_mergeable(r, it->first); it = ranges.erase(it))\
    \ {\n            auto [cl, cr] = *it;\n            r = std::max(r, cr);\n    \
    \        inserted -= cr - cl + 1;\n        }\n\n        inserted += r - l + 1;\n\
    \        ranges[l] = r;\n        sz += inserted;\n        return inserted;\n \
    \   }\n\n    // Erase [l, r]\n    // Returns number of integers removed\n    //\
    \ AMORTIZED O(logN)\n    T erase(T l, T r) {\n        assert(l <= r);\n      \
    \  T tl = l, tr = r;\n        auto it = ranges.upper_bound(l);\n        if (it\
    \ != ranges.begin() && l <= std::prev(it)->second) {\n            it = std::prev(it);\n\
    \            tl = it->first;\n        }\n\n        T erased = 0;\n        for\
    \ (; it != ranges.end() && it->first <= r; it = ranges.erase(it)) {\n        \
    \    auto [cl, cr] = *it;\n            tr = cr;\n            erased += cr - cl\
    \ + 1;\n        }\n        if (tl < l) {\n            ranges[tl] = l-1;\n    \
    \        erased -= l - tl;\n        }\n        if (r < tr) {\n            ranges[r\
    \ + 1] = tr;\n            erased -= tr - r;\n        }\n        sz -= erased;\n\
    \        return erased;\n    }\n\n    // Find min x: x >= lower && x NOT in this\
    \ set\n    T minimum_excluded(T lower) const {\n        static_assert(merge_adjacent_segment);\n\
    \        auto it = find_range(lower);\n        return it == ranges.end() ? lower\
    \ : it->second + 1;\n    }\n\n    // Find max x: x <= upper && x NOT in this set\n\
    \    T maximum_excluded(T upper) const {\n        static_assert(merge_adjacent_segment);\n\
    \        auto it = find_range(upper);\n        return it == ranges.end() ? upper\
    \ : it->first - 1;\n    }\n\n    T sz = 0;\n    std::map<T, T> ranges;\n\n   \
    \ bool is_mergeable(T cur_r, T next_l) {\n        return next_l <= cur_r + merge_adjacent_segment;\n\
    \    }\n};\n// }}}\n"
  code: "// RangeSet - for maintaining set of segments {{{\n//\n// merge_adjacent_segment\
    \ = true -> merge 2 consecutive segments,\n// e.g. [1, 10] and [11, 20] --> [1,\
    \ 20]\n//\n// Based on https://suisen-cp.github.io/cp-library-cpp/library/datastructure/util/range_set.hpp\n\
    template<typename T, bool merge_adjacent_segment = true>\nstruct RangeSet {\n\
    \    T n_elements() const { return sz; }\n    T n_ranges() const { return ranges.size();\
    \ }\n\n    bool contains(T x) const {\n        auto it = ranges.upper_bound(x);\n\
    \        return it != ranges.begin() && x <= std::prev(it)->second;\n    }\n\n\
    \    // Find range containing x, i.e. l <= x <= r\n    std::optional<std::pair<T,\
    \ T>> find_range(T x) const {\n        auto it = ranges.upper_bound(x);\n    \
    \    if (it == ranges.begin()) return std::nullopt;\n        --it;\n        return\
    \ (x <= it->second) ? std::optional<std::pair<T, T>>{*it} : std::nullopt;\n  \
    \  }\n\n    // Insert [l, r]\n    // Returns number of new integers added.\n \
    \   // AMORTIZED O(logN)\n    T insert(T l, T r) {\n        assert(l <= r);\n\
    \        auto it = ranges.upper_bound(l);\n        if (it != ranges.begin() &&\
    \ is_mergeable(std::prev(it)->second, l)) {\n            it = std::prev(it);\n\
    \            l = std::min(l, it->first);\n        }\n        T inserted = 0;\n\
    \        for (; it != ranges.end() && is_mergeable(r, it->first); it = ranges.erase(it))\
    \ {\n            auto [cl, cr] = *it;\n            r = std::max(r, cr);\n    \
    \        inserted -= cr - cl + 1;\n        }\n\n        inserted += r - l + 1;\n\
    \        ranges[l] = r;\n        sz += inserted;\n        return inserted;\n \
    \   }\n\n    // Erase [l, r]\n    // Returns number of integers removed\n    //\
    \ AMORTIZED O(logN)\n    T erase(T l, T r) {\n        assert(l <= r);\n      \
    \  T tl = l, tr = r;\n        auto it = ranges.upper_bound(l);\n        if (it\
    \ != ranges.begin() && l <= std::prev(it)->second) {\n            it = std::prev(it);\n\
    \            tl = it->first;\n        }\n\n        T erased = 0;\n        for\
    \ (; it != ranges.end() && it->first <= r; it = ranges.erase(it)) {\n        \
    \    auto [cl, cr] = *it;\n            tr = cr;\n            erased += cr - cl\
    \ + 1;\n        }\n        if (tl < l) {\n            ranges[tl] = l-1;\n    \
    \        erased -= l - tl;\n        }\n        if (r < tr) {\n            ranges[r\
    \ + 1] = tr;\n            erased -= tr - r;\n        }\n        sz -= erased;\n\
    \        return erased;\n    }\n\n    // Find min x: x >= lower && x NOT in this\
    \ set\n    T minimum_excluded(T lower) const {\n        static_assert(merge_adjacent_segment);\n\
    \        auto it = find_range(lower);\n        return it == ranges.end() ? lower\
    \ : it->second + 1;\n    }\n\n    // Find max x: x <= upper && x NOT in this set\n\
    \    T maximum_excluded(T upper) const {\n        static_assert(merge_adjacent_segment);\n\
    \        auto it = find_range(upper);\n        return it == ranges.end() ? upper\
    \ : it->first - 1;\n    }\n\n    T sz = 0;\n    std::map<T, T> ranges;\n\n   \
    \ bool is_mergeable(T cur_r, T next_l) {\n        return next_l <= cur_r + merge_adjacent_segment;\n\
    \    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RangeSet.h
  requiredBy: []
  timestamp: '2022-08-15 00:18:10+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/yukicoder_674_range_set.test.cpp
  - DataStructure/test/aizu_dsl_2_d_rangeset.test.cpp
  - DataStructure/test/aizu_dsl_4_a_range_set.test.cpp
documentation_of: DataStructure/RangeSet.h
layout: document
redirect_from:
- /library/DataStructure/RangeSet.h
- /library/DataStructure/RangeSet.h.html
title: DataStructure/RangeSet.h
---
