---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DP/tests/dynamic_hull_lineaddgetmin.test.cpp
    title: DP/tests/dynamic_hull_lineaddgetmin.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/niklasb/contest-algos/blob/master/convex_hull/dynamic.cpp
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"DP/optimizations/dynamic_hull.h\"\n// source: https://github.com/niklasb/contest-algos/blob/master/convex_hull/dynamic.cpp\n\
    // Tested:\n// - https://judge.yosupo.jp/problem/line_add_get_min\nusing ll =\
    \ long long;\nconst ll INF = (1LL<<62);\nstruct Line {\n    ll m, b;\n    mutable\
    \ function<const Line*()> succ;\n    bool operator<(const Line& rhs) const {\n\
    \        if (rhs.b != -INF) return m < rhs.m;\n        const Line* s = succ();\n\
    \        if (!s) return 0;\n        ll x = rhs.m;\n        return b - s->b < (s->m\
    \ - m) * x;\n    }\n};\n\nstruct HullDynamic : public multiset<Line> { // will\
    \ maintain upper hull for maximum\n    bool bad(iterator y) {\n        auto z\
    \ = next(y);\n        if (y == begin()) {\n            if (z == end()) return\
    \ 0;\n            return y->m == z->m && y->b <= z->b;\n        }\n        auto\
    \ x = prev(y);\n        if (z == end()) return y->m == x->m && y->b <= x->b;\n\
    \        return 1.0 * (x->b - y->b)*(z->m - y->m) >= 1.0 * (y->b - z->b)*(y->m\
    \ - x->m);\n    }\n    void insert_line(ll m, ll b) {\n        auto y = insert({\
    \ m, b });\n        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };\n\
    \        if (bad(y)) { erase(y); return; }\n        while (next(y) != end() &&\
    \ bad(next(y))) erase(next(y));\n        while (y != begin() && bad(prev(y)))\
    \ erase(prev(y));\n    }\n    ll eval(ll x) {\n        auto l = *lower_bound((Line)\
    \ { x, -INF });\n        return l.m * x + l.b;\n    }\n};\n"
  code: "// source: https://github.com/niklasb/contest-algos/blob/master/convex_hull/dynamic.cpp\n\
    // Tested:\n// - https://judge.yosupo.jp/problem/line_add_get_min\nusing ll =\
    \ long long;\nconst ll INF = (1LL<<62);\nstruct Line {\n    ll m, b;\n    mutable\
    \ function<const Line*()> succ;\n    bool operator<(const Line& rhs) const {\n\
    \        if (rhs.b != -INF) return m < rhs.m;\n        const Line* s = succ();\n\
    \        if (!s) return 0;\n        ll x = rhs.m;\n        return b - s->b < (s->m\
    \ - m) * x;\n    }\n};\n\nstruct HullDynamic : public multiset<Line> { // will\
    \ maintain upper hull for maximum\n    bool bad(iterator y) {\n        auto z\
    \ = next(y);\n        if (y == begin()) {\n            if (z == end()) return\
    \ 0;\n            return y->m == z->m && y->b <= z->b;\n        }\n        auto\
    \ x = prev(y);\n        if (z == end()) return y->m == x->m && y->b <= x->b;\n\
    \        return 1.0 * (x->b - y->b)*(z->m - y->m) >= 1.0 * (y->b - z->b)*(y->m\
    \ - x->m);\n    }\n    void insert_line(ll m, ll b) {\n        auto y = insert({\
    \ m, b });\n        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };\n\
    \        if (bad(y)) { erase(y); return; }\n        while (next(y) != end() &&\
    \ bad(next(y))) erase(next(y));\n        while (y != begin() && bad(prev(y)))\
    \ erase(prev(y));\n    }\n    ll eval(ll x) {\n        auto l = *lower_bound((Line)\
    \ { x, -INF });\n        return l.m * x + l.b;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DP/optimizations/dynamic_hull.h
  requiredBy: []
  timestamp: '2022-12-26 18:06:15+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DP/tests/dynamic_hull_lineaddgetmin.test.cpp
documentation_of: DP/optimizations/dynamic_hull.h
layout: document
redirect_from:
- /library/DP/optimizations/dynamic_hull.h
- /library/DP/optimizations/dynamic_hull.h.html
title: DP/optimizations/dynamic_hull.h
---
