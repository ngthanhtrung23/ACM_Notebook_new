---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://www.spoj.com/problems/MATSUM/
  bundledCode: "#line 1 \"DataStructure/Fenwick/Fenwick2D_smallN.h\"\n// 0-based index\n\
    // Tested:\n// - https://www.spoj.com/problems/MATSUM/\n//\n// Fenwick 2D, small\
    \ N {{{\ntemplate<\n    typename T  // need to support +, -\n> struct Fenwick2D\
    \ {\n    Fenwick2D(int _n1, int _n2) : n1(_n1), n2(_n2), f(1+n1, vector<T> (1+n2,\
    \ T(0))) {}\n\n    // a[x][y] += val\n    void update(int x, int y, T val) {\n\
    \        assert(0 <= x && x < n1);\n        assert(0 <= y && y < n2);\n      \
    \  ++x; ++y;\n        for (int u = x; u <= n1; u += u & -u) {\n            for\
    \ (int v = y; v <= n2; v += v & -v) {\n                f[u][v] += val;\n     \
    \       }\n        }\n    }\n\n    // return rect sum of [0, 0] -> [x-1, y-1]\n\
    \    T get(int x, int y) const {\n        assert(0 <= x && x <= n1);\n       \
    \ assert(0 <= y && y <= n2);\n        T res(0);\n        for (int u = x; u > 0;\
    \ u -= u & -u) {\n            for (int v = y; v > 0; v -= v & -v) {\n        \
    \        res += f[u][v];\n            }\n        }\n        return res;\n    }\n\
    \n    // returns rect sum of [x1, y1] -> [x2-1, y2-1]\n    T get(int x1, int y1,\
    \ int x2, int y2) const {\n        assert(0 <= x1 && x1 <= x2 && x2 <= n1);\n\
    \        assert(0 <= y1 && y1 <= y2 && y2 <= n2);\n        if (x1 == x2 || y1\
    \ == y2) return T(0);\n        return get(x2, y2) - get(x1, y2) - get(x2, y1)\
    \ + get(x1, y1);\n    }\n\n    int n1, n2;\n    vector<vector<T>> f;\n};\n// }}}\n"
  code: "// 0-based index\n// Tested:\n// - https://www.spoj.com/problems/MATSUM/\n\
    //\n// Fenwick 2D, small N {{{\ntemplate<\n    typename T  // need to support\
    \ +, -\n> struct Fenwick2D {\n    Fenwick2D(int _n1, int _n2) : n1(_n1), n2(_n2),\
    \ f(1+n1, vector<T> (1+n2, T(0))) {}\n\n    // a[x][y] += val\n    void update(int\
    \ x, int y, T val) {\n        assert(0 <= x && x < n1);\n        assert(0 <= y\
    \ && y < n2);\n        ++x; ++y;\n        for (int u = x; u <= n1; u += u & -u)\
    \ {\n            for (int v = y; v <= n2; v += v & -v) {\n                f[u][v]\
    \ += val;\n            }\n        }\n    }\n\n    // return rect sum of [0, 0]\
    \ -> [x-1, y-1]\n    T get(int x, int y) const {\n        assert(0 <= x && x <=\
    \ n1);\n        assert(0 <= y && y <= n2);\n        T res(0);\n        for (int\
    \ u = x; u > 0; u -= u & -u) {\n            for (int v = y; v > 0; v -= v & -v)\
    \ {\n                res += f[u][v];\n            }\n        }\n        return\
    \ res;\n    }\n\n    // returns rect sum of [x1, y1] -> [x2-1, y2-1]\n    T get(int\
    \ x1, int y1, int x2, int y2) const {\n        assert(0 <= x1 && x1 <= x2 && x2\
    \ <= n1);\n        assert(0 <= y1 && y1 <= y2 && y2 <= n2);\n        if (x1 ==\
    \ x2 || y1 == y2) return T(0);\n        return get(x2, y2) - get(x1, y2) - get(x2,\
    \ y1) + get(x1, y1);\n    }\n\n    int n1, n2;\n    vector<vector<T>> f;\n};\n\
    // }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Fenwick/Fenwick2D_smallN.h
  requiredBy: []
  timestamp: '2023-01-07 01:54:04+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Fenwick/Fenwick2D_smallN.h
layout: document
redirect_from:
- /library/DataStructure/Fenwick/Fenwick2D_smallN.h
- /library/DataStructure/Fenwick/Fenwick2D_smallN.h.html
title: DataStructure/Fenwick/Fenwick2D_smallN.h
---
