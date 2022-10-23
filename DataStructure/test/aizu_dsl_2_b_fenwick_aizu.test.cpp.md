---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick.h
    title: DataStructure/Fenwick.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/Fenwick.h\"\
    \n// 1D Fenwick {{{\n// 0 based index\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/static_range_sum\n\
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
    \ }\n\n    int n;\n    vector<T> f;\n};\n// }}}\n#line 7 \"DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin\
    \ >> n >> q;\n    Fenwick<long long> bit(n);\n    while (q--) {\n        int typ,\
    \ x, y; cin >> typ >> x >> y;\n        --x;\n        if (typ == 0) bit.update(x,\
    \ y);\n        else cout << bit.get(x, y) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Fenwick.h\"\
    \n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin\
    \ >> n >> q;\n    Fenwick<long long> bit(n);\n    while (q--) {\n        int typ,\
    \ x, y; cin >> typ >> x >> y;\n        --x;\n        if (typ == 0) bit.update(x,\
    \ y);\n        else cout << bit.get(x, y) << '\\n';\n    }\n}\n"
  dependsOn:
  - DataStructure/Fenwick.h
  isVerificationFile: true
  path: DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp
  requiredBy: []
  timestamp: '2022-10-23 21:56:10+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp
- /verify/DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp.html
title: DataStructure/test/aizu_dsl_2_b_fenwick_aizu.test.cpp
---
