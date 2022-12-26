---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/persistent_fenwick_tree_rmq.test.cpp
    title: DataStructure/test/persistent_fenwick_tree_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/PartiallyPersistentFenwick.h\"\n// NOTE:\n\
    // - 0-based index\n// - for updates: time must be in increasing order\n// - Update:\
    \ O(log), Get: O(log^2)\n//\n// Partially Persistent FenwickTree {{{\ntemplate<\n\
    \    typename T  // need to support operators + - <\n> struct PartiallyPersistentFenwick\
    \ {\n    PartiallyPersistentFenwick(int _n) : n(_n), f(_n + 1) {\n        for\
    \ (int i = 0; i <= n; ++i) {\n            f[i].emplace_back(INT_MIN, T{});\n \
    \       }\n    }\n\n    // a[u] += val\n    void update(int time, int u, T val)\
    \ {\n        assert(0 <= u && u < n);\n        assert(last_updated_time <= time);\n\
    \        last_updated_time = time;\n        ++u;\n        for (; u <= n; u +=\
    \ u & -u) {\n            f[u].emplace_back(time, f[u].back().second + val);\n\
    \        }\n    }\n\n    // return a[0] + .. + a[u-1]\n    T get(int time, int\
    \ u) const {\n        assert(0 <= u && u <= n);\n        T res{};\n        for\
    \ (; u > 0; u -= u & -u) {\n            auto it = lower_bound(f[u].begin(), f[u].end(),\
    \ make_pair(time+1, T{}));\n            res = res + prev(it)->second;\n      \
    \  }\n        return res;\n    }\n\n    // return a[l] + .. + a[r-1]\n    T get(int\
    \ time, int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n \
    \       if (l == r) return T{};  // empty\n        return get(time, r) - get(time,\
    \ l);\n    }\n\n    int n;\n    int last_updated_time = INT_MIN;\n    vector<vector<pair<int,\
    \ T>>> f;  // (time, data)\n};\n// }}}\n"
  code: "// NOTE:\n// - 0-based index\n// - for updates: time must be in increasing\
    \ order\n// - Update: O(log), Get: O(log^2)\n//\n// Partially Persistent FenwickTree\
    \ {{{\ntemplate<\n    typename T  // need to support operators + - <\n> struct\
    \ PartiallyPersistentFenwick {\n    PartiallyPersistentFenwick(int _n) : n(_n),\
    \ f(_n + 1) {\n        for (int i = 0; i <= n; ++i) {\n            f[i].emplace_back(INT_MIN,\
    \ T{});\n        }\n    }\n\n    // a[u] += val\n    void update(int time, int\
    \ u, T val) {\n        assert(0 <= u && u < n);\n        assert(last_updated_time\
    \ <= time);\n        last_updated_time = time;\n        ++u;\n        for (; u\
    \ <= n; u += u & -u) {\n            f[u].emplace_back(time, f[u].back().second\
    \ + val);\n        }\n    }\n\n    // return a[0] + .. + a[u-1]\n    T get(int\
    \ time, int u) const {\n        assert(0 <= u && u <= n);\n        T res{};\n\
    \        for (; u > 0; u -= u & -u) {\n            auto it = lower_bound(f[u].begin(),\
    \ f[u].end(), make_pair(time+1, T{}));\n            res = res + prev(it)->second;\n\
    \        }\n        return res;\n    }\n\n    // return a[l] + .. + a[r-1]\n \
    \   T get(int time, int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= n);\n        if (l == r) return T{};  // empty\n        return get(time,\
    \ r) - get(time, l);\n    }\n\n    int n;\n    int last_updated_time = INT_MIN;\n\
    \    vector<vector<pair<int, T>>> f;  // (time, data)\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PartiallyPersistentFenwick.h
  requiredBy: []
  timestamp: '2022-12-26 20:29:27+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/persistent_fenwick_tree_rmq.test.cpp
documentation_of: DataStructure/PartiallyPersistentFenwick.h
layout: document
redirect_from:
- /library/DataStructure/PartiallyPersistentFenwick.h
- /library/DataStructure/PartiallyPersistentFenwick.h.html
title: DataStructure/PartiallyPersistentFenwick.h
---
