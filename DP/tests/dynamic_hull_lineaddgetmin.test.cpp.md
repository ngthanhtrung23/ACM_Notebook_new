---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/optimizations/dynamic_hull.h
    title: DP/optimizations/dynamic_hull.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"DP/tests/dynamic_hull_lineaddgetmin.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"DP/optimizations/dynamic_hull.h\"\n// source:\
    \ https://github.com/niklasb/contest-algos/blob/master/convex_hull/dynamic.cpp\n\
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
    \ { x, -INF });\n        return l.m * x + l.b;\n    }\n};\n#line 7 \"DP/tests/dynamic_hull_lineaddgetmin.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin >> n >> q;\n\
    \    HullDynamic hull;\n    REP(i,n) {\n        long long a, b; cin >> a >> b;\n\
    \        hull.insert_line(-a, -b);\n    }\n    REP(i,q) {\n        int typ; cin\
    \ >> typ;\n        if (typ == 0) {\n            long long a, b; cin >> a >> b;\n\
    \            hull.insert_line(-a, -b);\n        } else {\n            long long\
    \ x; cin >> x;\n            cout << -hull.eval(x) << '\\n';\n        }\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../optimizations/dynamic_hull.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin >> n >> q;\n\
    \    HullDynamic hull;\n    REP(i,n) {\n        long long a, b; cin >> a >> b;\n\
    \        hull.insert_line(-a, -b);\n    }\n    REP(i,q) {\n        int typ; cin\
    \ >> typ;\n        if (typ == 0) {\n            long long a, b; cin >> a >> b;\n\
    \            hull.insert_line(-a, -b);\n        } else {\n            long long\
    \ x; cin >> x;\n            cout << -hull.eval(x) << '\\n';\n        }\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - DP/optimizations/dynamic_hull.h
  isVerificationFile: true
  path: DP/tests/dynamic_hull_lineaddgetmin.test.cpp
  requiredBy: []
  timestamp: '2022-12-26 18:09:30+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DP/tests/dynamic_hull_lineaddgetmin.test.cpp
layout: document
redirect_from:
- /verify/DP/tests/dynamic_hull_lineaddgetmin.test.cpp
- /verify/DP/tests/dynamic_hull_lineaddgetmin.test.cpp.html
title: DP/tests/dynamic_hull_lineaddgetmin.test.cpp
---
