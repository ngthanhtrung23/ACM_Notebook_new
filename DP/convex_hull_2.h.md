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
    - http://codeforces.com/contest/678/standings/friends/true
    - https://oj.vnoi.info/problem/segtree_itds2
  bundledCode: "#line 1 \"DP/convex_hull_2.h\"\n// Add lines a*x + b, must be in:\n\
    // - increasing order of a\n// - decreasing order of b\n// Get y = max(a*x + b)\n\
    //\n// Tested:\n// - http://codeforces.com/contest/678/standings/friends/true\n\
    // - https://oj.vnoi.info/problem/segtree_itds2\n\nconst long long INF = 1e18\
    \ + 11;\nstruct Line {\n    long long a, b;\n    long long f(long long x) {\n\
    \        return a*x + b;\n    }\n};\nbool operator < (const Line& f, const Line&\
    \ g) {\n    if (f.a != g.a) return f.a < g.a;\n    return f.b > g.b;\n}\n\nstruct\
    \ Hull {\n    vector<double> x;\n    vector<Line> segs;\n\n    void insert(Line\
    \ l) {\n        if (segs.empty()) {\n            x.push_back(-INF);\n        \
    \    segs.push_back(l);\n            return;\n        }\n        double xNew =\
    \ -INF;\n        while (!segs.empty()) {\n            if (segs.back().a == l.a)\
    \ {\n                assert(segs.back().b >= l.b);\n                return;\n\
    \            }\n            xNew = intersection(segs.back(), l);\n           \
    \ if (xNew < x.back()) {\n                remove();\n            } else break;\n\
    \        }\n\n        segs.push_back(l);\n        x.push_back(xNew);\n    }\n\n\
    \    long long get(long long x0) {\n        if (segs.empty()) {\n            return\
    \ -INF;\n        }\n        auto i = upper_bound(x.begin(), x.end(), x0) - x.begin()\
    \ - 1;\n        return segs[i].f(x0);\n    }\n\nprivate:\n    void remove() {\n\
    \        segs.pop_back();\n        x.pop_back();\n    }\n    double intersection(const\
    \ Line& f, const Line& g) {\n        return 1.0 * (f.b - g.b) / (g.a - f.a);\n\
    \    }\n};\n"
  code: "// Add lines a*x + b, must be in:\n// - increasing order of a\n// - decreasing\
    \ order of b\n// Get y = max(a*x + b)\n//\n// Tested:\n// - http://codeforces.com/contest/678/standings/friends/true\n\
    // - https://oj.vnoi.info/problem/segtree_itds2\n\nconst long long INF = 1e18\
    \ + 11;\nstruct Line {\n    long long a, b;\n    long long f(long long x) {\n\
    \        return a*x + b;\n    }\n};\nbool operator < (const Line& f, const Line&\
    \ g) {\n    if (f.a != g.a) return f.a < g.a;\n    return f.b > g.b;\n}\n\nstruct\
    \ Hull {\n    vector<double> x;\n    vector<Line> segs;\n\n    void insert(Line\
    \ l) {\n        if (segs.empty()) {\n            x.push_back(-INF);\n        \
    \    segs.push_back(l);\n            return;\n        }\n        double xNew =\
    \ -INF;\n        while (!segs.empty()) {\n            if (segs.back().a == l.a)\
    \ {\n                assert(segs.back().b >= l.b);\n                return;\n\
    \            }\n            xNew = intersection(segs.back(), l);\n           \
    \ if (xNew < x.back()) {\n                remove();\n            } else break;\n\
    \        }\n\n        segs.push_back(l);\n        x.push_back(xNew);\n    }\n\n\
    \    long long get(long long x0) {\n        if (segs.empty()) {\n            return\
    \ -INF;\n        }\n        auto i = upper_bound(x.begin(), x.end(), x0) - x.begin()\
    \ - 1;\n        return segs[i].f(x0);\n    }\n\nprivate:\n    void remove() {\n\
    \        segs.pop_back();\n        x.pop_back();\n    }\n    double intersection(const\
    \ Line& f, const Line& g) {\n        return 1.0 * (f.b - g.b) / (g.a - f.a);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/convex_hull_2.h
  requiredBy: []
  timestamp: '2021-12-26 02:20:02+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DP/convex_hull_2.h
layout: document
redirect_from:
- /library/DP/convex_hull_2.h
- /library/DP/convex_hull_2.h.html
title: DP/convex_hull_2.h
---
