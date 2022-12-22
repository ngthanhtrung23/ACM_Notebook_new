---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick2D.h
    title: DataStructure/Fenwick2D.h
  - icon: ':heavy_check_mark:'
    path: Misc/compress.h
    title: Misc/compress.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"DataStructure/test/fenwick_2d_rectsum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"DataStructure/Fenwick2D.h\"\n// 2D Fenwick\n\
    // Note:\n// - already included coordinate compression, so any `int` coordinates\n\
    //   should work\n// - For faster implementation which also supports Rectagle\
    \ ADD, see:\n//   https://hitonanode.github.io/cplib-cpp/data_structure/rectangle_add_rectangle_sum.hpp\n\
    //\n// If cannot use the struct directly (e.g. ICPC Vietnam national 2022 - G),\
    \ do:\n// 1. fakeUpdate\n// 2. initNodes\n// 3. Queries\n//\n// Tested:\n// -\
    \ https://judge.yosupo.jp/problem/rectangle_sum\n// - https://judge.yosupo.jp/problem/point_add_rectangle_sum\n\
    // - https://oj.vnoi.info/problem/kl11b\n\n#line 1 \"Misc/compress.h\"\n// Compressor\
    \ {{{\n/* Example usage:\n    auto compressor = CompressorBuilder<T>{vs}.build();\n\
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
    \ xs;\n};\n// }}}\n#line 19 \"DataStructure/Fenwick2D.h\"\nconst int INF = 2e9\
    \ + 11;  // for coordinates\ntemplate<typename T>\nstruct Query {\n    static\
    \ const int ADD = 0;\n    static const int QUERY = 1;\n\n    int typ;  // ADD\
    \ or QUERY\n    int x, y;\n    int x2, y2;  // for QUERY: [x1, x2-1] * [y1, y2-1]\n\
    \n    T weight;\n};\n\ntemplate<typename T>\nstruct Fenwick2D {\n    vector<T>\
    \ solve(vector<Query<T>> queries) {\n        // Get coordinates of ADD queries\n\
    \        CompressorBuilder<int> cx_builder, cy_builder;\n        cx_builder.add(INF);\n\
    \        cy_builder.add(INF);\n        for (const auto& query : queries) {\n \
    \           if (query.typ == Query<T>::ADD) {\n                cx_builder.add(query.x);\n\
    \                cy_builder.add(query.y);\n            }\n        }\n        auto\
    \ cx = cx_builder.build();\n        auto cy = cy_builder.build();\n        sx\
    \ = cx.size();\n\n        // Compress\n        for (auto& query : queries) {\n\
    \            query.x = cx.must_geq(query.x) + 1;\n            query.y = cy.must_geq(query.y)\
    \ + 1;\n\n            if (query.typ == Query<T>::QUERY) {\n                query.x2\
    \ = cx.must_geq(query.x2) + 1;\n                query.y2 = cy.must_geq(query.y2)\
    \ + 1;\n            }\n        }\n\n        // fake updates\n        nodes.resize(sx+1);\n\
    \        f.resize(sx+1);\n        for (const auto& query : queries) {\n      \
    \      if (query.typ == Query<T>::ADD) {\n                fakeUpdate(query.x,\
    \ query.y);\n            }\n        }\n\n        initNodes();\n\n        // answer\
    \ queries\n        vector<T> res;\n        for (const auto& query : queries) {\n\
    \            if (query.typ == Query<T>::ADD) {\n                update(query.x,\
    \ query.y, query.weight);\n            } else {\n                res.push_back(\n\
    \                    + get(query.x2 - 1, query.y2 - 1)\n                    -\
    \ get(query.x2 - 1, query.y  - 1)\n                    - get(query.x  - 1, query.y2\
    \ - 1)\n                    + get(query.x  - 1, query.y  - 1)\n              \
    \  );\n            }\n        }\n        return res;\n    }\n\n// private:\n \
    \   // nodes[x] contains all relevant y coordinates\n    vector<vector<int>> nodes;\n\
    \    vector<vector<T>> f;\n    int sx;\n\n    void initNodes() {\n        for\
    \ (int i = 1; i <= sx; i++) {\n            nodes[i].push_back(INF);\n        \
    \    sort(nodes[i].begin(), nodes[i].end());\n            nodes[i].erase(unique(nodes[i].begin(),\
    \ nodes[i].end()), nodes[i].end());\n            f[i].resize(nodes[i].size() +\
    \ 1);\n        }\n    }\n\n    void fakeUpdate(int x, int y) {\n        for (;\
    \ x <= sx; x += x & -x)\n            nodes[x].push_back(y);\n    }\n\n    // point\
    \ (u, v) += val\n    void update(int u, int v, int val) {\n        for(int x =\
    \ u; x <= sx; x += x & -x)\n            for(int y = lower_bound(nodes[x].begin(),\
    \ nodes[x].end(), v) - nodes[x].begin() + 1; y <= (int) nodes[x].size(); y +=\
    \ y & -y)\n                f[x][y] += val;\n    }\n\n    // Get sum of point in\
    \ rectangle with corners at (1, 1) and (u, v)\n    T get(int u, int v) {\n   \
    \     T res = 0;\n        for(int x = u; x > 0; x -= x & -x)\n            for(int\
    \ y = upper_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin(); y >\
    \ 0; y -= y & -y)\n                res += f[x][y];\n        return res;\n    }\n\
    };\n#line 7 \"DataStructure/test/fenwick_2d_rectsum.test.cpp\"\n\n#define REP(i,\
    \ a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n, q; cin >> n >> q;\n\n    vector<Query<long long>> queries;\n\
    \    REP(i,n) {\n        int x, y, val; cin >> x >> y >> val;\n        queries.push_back({Query<long\
    \ long>::ADD, x, y, -1, -1, val});\n    }\n\n    REP(i,q) {\n        int x, y,\
    \ x2, y2; cin >> x >> y >> x2 >> y2;\n        queries.push_back({Query<long long>::QUERY,\
    \ x, y, x2, y2, 0});\n    }\n\n    Fenwick2D<long long> f;\n    auto res = f.solve(queries);\n\
    \    for (auto r : res) cout << r << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Fenwick2D.h\"\n\n#define\
    \ REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main() {\n \
    \   ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin >> n >> q;\n\n   \
    \ vector<Query<long long>> queries;\n    REP(i,n) {\n        int x, y, val; cin\
    \ >> x >> y >> val;\n        queries.push_back({Query<long long>::ADD, x, y, -1,\
    \ -1, val});\n    }\n\n    REP(i,q) {\n        int x, y, x2, y2; cin >> x >> y\
    \ >> x2 >> y2;\n        queries.push_back({Query<long long>::QUERY, x, y, x2,\
    \ y2, 0});\n    }\n\n    Fenwick2D<long long> f;\n    auto res = f.solve(queries);\n\
    \    for (auto r : res) cout << r << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/Fenwick2D.h
  - Misc/compress.h
  isVerificationFile: true
  path: DataStructure/test/fenwick_2d_rectsum.test.cpp
  requiredBy: []
  timestamp: '2022-12-22 10:28:54+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/fenwick_2d_rectsum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/fenwick_2d_rectsum.test.cpp
- /verify/DataStructure/test/fenwick_2d_rectsum.test.cpp.html
title: DataStructure/test/fenwick_2d_rectsum.test.cpp
---
