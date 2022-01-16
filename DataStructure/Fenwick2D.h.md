---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
    - https://judge.yosupo.jp/problem/rectangle_sum
    - https://oj.vnoi.info/problem/kl11b
  bundledCode: "#line 1 \"DataStructure/Fenwick2D.h\"\n// 2D Fenwick\n// Note:\n//\
    \ - already included coordinate compression, so any `int` coordinates\n//   should\
    \ work\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/rectangle_sum\n//\
    \ - https://judge.yosupo.jp/problem/point_add_rectangle_sum\n// - https://oj.vnoi.info/problem/kl11b\n\
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
    \        return res;\n    }\n};\n"
  code: "// 2D Fenwick\n// Note:\n// - already included coordinate compression, so\
    \ any `int` coordinates\n//   should work\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/rectangle_sum\n\
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
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Fenwick2D.h
  requiredBy: []
  timestamp: '2022-01-06 03:05:50+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/fenwick_2d_pointaddrectsum.test.cpp
  - DataStructure/test/fenwick_2d_rectsum.test.cpp
documentation_of: DataStructure/Fenwick2D.h
layout: document
redirect_from:
- /library/DataStructure/Fenwick2D.h
- /library/DataStructure/Fenwick2D.h.html
title: DataStructure/Fenwick2D.h
---
