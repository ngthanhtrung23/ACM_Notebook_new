---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick2D.h
    title: DataStructure/Fenwick2D.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/Fenwick2D.h\"\
    \n// 2D Fenwick\n// Note:\n// - already included coordinate compression, so any\
    \ `int` coordinates\n//   should work\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/rectangle_sum\n\
    // - https://judge.yosupo.jp/problem/point_add_rectangle_sum\n// - https://oj.vnoi.info/problem/kl11b\n\
    const int INF = 2e9 + 11;  // for coordinates\ntemplate<typename T>\nstruct Query\
    \ {\n    static const int ADD = 0;\n    static const int QUERY = 1;\n\n    int\
    \ typ;  // ADD or QUERY\n    int x, y;\n    int x2, y2;  // for QUERY: [x1, x2-1]\
    \ * [y1, y2-1]\n\n    T weight;\n};\n\ntemplate<typename T>\nstruct Fenwick2D\
    \ {\n    vector<T> solve(vector<Query<T>> queries) {\n        // Get coordinates\
    \ of ADD queries\n        vector<int> cx {INF}, cy {INF};\n        for (const\
    \ auto& query : queries) {\n            if (query.typ == Query<T>::ADD) {\n  \
    \              cx.push_back(query.x);\n                cy.push_back(query.y);\n\
    \            }\n        }\n        sort(cx.begin(), cx.end());\n        sort(cy.begin(),\
    \ cy.end());\n        cx.erase(unique(cx.begin(), cx.end()), cx.end());\n    \
    \    cy.erase(unique(cy.begin(), cy.end()), cy.end());\n        sx = cx.size();\n\
    \n        auto getx = [&cx] (int x) {\n            return lower_bound(cx.begin(),\
    \ cx.end(), x) - cx.begin();\n        };\n        auto gety = [&cy] (int y) {\n\
    \            return lower_bound(cy.begin(), cy.end(), y) - cy.begin();\n     \
    \   };\n\n        // Compress\n        for (auto& query : queries) {\n       \
    \     query.x = getx(query.x) + 1;\n            query.y = gety(query.y) + 1;\n\
    \n            if (query.typ == Query<T>::QUERY) {\n                query.x2 =\
    \ getx(query.x2) + 1;\n                query.y2 = gety(query.y2) + 1;\n      \
    \      }\n        }\n\n        // fake updates\n        nodes.resize(sx+1);\n\
    \        f.resize(sx+1);\n        for (const auto& query : queries) {\n      \
    \      if (query.typ == Query<T>::ADD) {\n                fakeUpdate(query.x,\
    \ query.y);\n            }\n        }\n\n        // init nodes\n        for (int\
    \ i = 1; i <= sx; i++) {\n            nodes[i].push_back(INF);\n            sort(nodes[i].begin(),\
    \ nodes[i].end());\n            nodes[i].erase(unique(nodes[i].begin(), nodes[i].end()),\
    \ nodes[i].end());\n            f[i].resize(nodes[i].size() + 1);\n        }\n\
    \n        // answer queries\n        vector<T> res;\n        for (const auto&\
    \ query : queries) {\n            if (query.typ == Query<T>::ADD) {\n        \
    \        update(query.x, query.y, query.weight);\n            } else {\n     \
    \           res.push_back(\n                    + get(query.x2 - 1, query.y2 -\
    \ 1)\n                    - get(query.x2 - 1, query.y  - 1)\n                \
    \    - get(query.x  - 1, query.y2 - 1)\n                    + get(query.x  - 1,\
    \ query.y  - 1)\n                );\n            }\n        }\n        return\
    \ res;\n    }\n\n// private:\n    // nodes[x] contains all relevant y coordinates\n\
    \    vector<vector<int>> nodes;\n    vector<vector<T>> f;\n    int sx;\n\n   \
    \ void fakeUpdate(int x, int y) {\n        for (; x <= sx; x += x & -x)\n    \
    \        nodes[x].push_back(y);\n    }\n\n    // point (u, v) += val\n    void\
    \ update(int u, int v, int val) {\n        for(int x = u; x <= sx; x += x & -x)\n\
    \            for(int y = lower_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin()\
    \ + 1; y <= (int) nodes[x].size(); y += y & -y)\n                f[x][y] += val;\n\
    \    }\n\n    // Get sum of point in rectangle with corners at (1, 1) and (u,\
    \ v)\n    T get(int u, int v) {\n        T res = 0;\n        for(int x = u; x\
    \ > 0; x -= x & -x)\n            for(int y = upper_bound(nodes[x].begin(), nodes[x].end(),\
    \ v) - nodes[x].begin(); y > 0; y -= y & -y)\n                res += f[x][y];\n\
    \        return res;\n    }\n};\n#line 7 \"DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin >> n >> q;\n\n\
    \    vector<Query<long long>> queries;\n    REP(i,n) {\n        int x, y, val;\
    \ cin >> x >> y >> val;\n        queries.push_back({Query<long long>::ADD, x,\
    \ y, -1, -1, val});\n    }\n\n    REP(i,q) {\n        int typ; cin >> typ;\n \
    \       if (typ == 0) {\n            int x, y, val; cin >> x >> y >> val;\n  \
    \          queries.push_back({Query<long long>::ADD, x, y, -1, -1, val});\n  \
    \      } else {\n            int x, y, x2, y2; cin >> x >> y >> x2 >> y2;\n  \
    \          queries.push_back({Query<long long>::QUERY, x, y, x2, y2, 0});\n  \
    \      }\n    }\n\n    Fenwick2D<long long> f;\n    auto res = f.solve(queries);\n\
    \    for (auto r : res) cout << r << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Fenwick2D.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin >> n >> q;\n\n\
    \    vector<Query<long long>> queries;\n    REP(i,n) {\n        int x, y, val;\
    \ cin >> x >> y >> val;\n        queries.push_back({Query<long long>::ADD, x,\
    \ y, -1, -1, val});\n    }\n\n    REP(i,q) {\n        int typ; cin >> typ;\n \
    \       if (typ == 0) {\n            int x, y, val; cin >> x >> y >> val;\n  \
    \          queries.push_back({Query<long long>::ADD, x, y, -1, -1, val});\n  \
    \      } else {\n            int x, y, x2, y2; cin >> x >> y >> x2 >> y2;\n  \
    \          queries.push_back({Query<long long>::QUERY, x, y, x2, y2, 0});\n  \
    \      }\n    }\n\n    Fenwick2D<long long> f;\n    auto res = f.solve(queries);\n\
    \    for (auto r : res) cout << r << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/Fenwick2D.h
  isVerificationFile: true
  path: DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
  requiredBy: []
  timestamp: '2022-01-12 13:12:33+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
- /verify/DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp.html
title: DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
---
