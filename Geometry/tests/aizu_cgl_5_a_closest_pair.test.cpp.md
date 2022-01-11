---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Geometry/closest_pair.h
    title: Geometry/closest_pair.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
  bundledCode: "#line 1 \"Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\"\
    \n\n#line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int\
    \ i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n\
    #define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\
    \n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n)\
    \ { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define\
    \ PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl;\
    \ }\n\n#define sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n//\
    \ Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
    template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>&\
    \ p) {\n    return out << '(' << p.first << \", \" << p.second << ')';\n}\n\n\
    template<class Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
    \ string>::value, ostream&>::type\noperator << (ostream& out, const Con& con)\
    \ {\n    out << '{';\n    for (auto beg = con.begin(), it = beg; it != con.end();\
    \ it++) {\n        out << (it == beg ? \"\" : \", \") << *it;\n    }\n    return\
    \ out << '}';\n}\ntemplate<size_t i, class T> ostream& print_tuple_utils(ostream&\
    \ out, const T& tup) {\n    if constexpr(i == tuple_size<T>::value) return out\
    \ << \")\"; \n    else return print_tuple_utils<i + 1, T>(out << (i ? \", \" :\
    \ \"(\") << get<i>(tup), tup); \n}\ntemplate<class ...U> ostream& operator <<\
    \ (ostream& out, const tuple<U...>& t) {\n    return print_tuple_utils<0, tuple<U...>>(out,\
    \ t);\n}\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r) {\n    return uniform_int_distribution<long long>\
    \ (0, r-1)(rng);\n}\n\nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    solve();\n    return 0;\n}\n#line 1 \"Geometry/closest_pair.h\"\
    \n// Closest pair\n//\n// Tested:\n// - https://open.kattis.com/problems/closestpair1\n\
    // - https://open.kattis.com/problems/closestpair2\n//\n// Returns: {dist, 2 points}\n\
    //\n// If need point ids -> add ID to struct P\n// If need exact square dist ->\
    \ can compute from returned points\ntemplate<typename T>\nstd::pair<double, std::pair<P<T>,\
    \ P<T>>> closest_pair(vector<P<T>> a) {\n    int n = a.size();\n    assert(n >=\
    \ 2);\n    double mindist = 1e20;\n    std::pair<P<T>, P<T>> best_pair;\n    std::vector<P<T>>\
    \ t(n);\n    sort(a.begin(), a.end());\n\n    auto upd_ans = [&] (const P<T>&\
    \ u, const P<T>& v) {\n        double cur = (u - v).len();\n        if (cur <\
    \ mindist) {\n            mindist = cur;\n            best_pair = {u, v};\n  \
    \      }\n    };\n\n    std::function<void(int,int)> rec = [&] (int l, int r)\
    \ {\n        if (r - l <= 3) {\n            for (int i = l; i < r; ++i) {\n  \
    \              for (int j = i + 1; j < r; ++j) {\n                    upd_ans(a[i],\
    \ a[j]);\n                }\n            }\n            sort(a.begin() + l, a.begin()\
    \ + r, cmpy<T>);\n            return;\n        }\n\n        int m = (l + r) >>\
    \ 1;\n        T midx = a[m].x;\n        rec(l, m);\n        rec(m, r);\n\n   \
    \     std::merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(),\
    \ cmpy<T>);\n        std::copy(t.begin(), t.begin() + r - l, a.begin() + l);\n\
    \n        int tsz = 0;\n        for (int i = l; i < r; ++i) {\n            if\
    \ (abs(a[i].x - midx) < mindist) {\n                for (int j = tsz - 1; j >=\
    \ 0 && a[i].y - t[j].y < mindist; --j)\n                    upd_ans(a[i], t[j]);\n\
    \                t[tsz++] = a[i];\n            }\n        }\n    };\n    rec(0,\
    \ n);\n\n    return {mindist, best_pair};\n}\n#line 5 \"Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp\"\
    \n\n#define ERROR 1e-6\n\nvoid solve() {\n    cout << (fixed) << setprecision(10);\n\
    \    int n; cin >> n;\n    vector<P<double>> a(n);\n    for (auto& p : a) cin\
    \ >> p;\n\n    auto [dist, ps] = closest_pair(a);\n    cout << dist << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\"\
    \n\n#include \"../../template.h\"\n#include \"../closest_pair.h\"\n\n#define ERROR\
    \ 1e-6\n\nvoid solve() {\n    cout << (fixed) << setprecision(10);\n    int n;\
    \ cin >> n;\n    vector<P<double>> a(n);\n    for (auto& p : a) cin >> p;\n\n\
    \    auto [dist, ps] = closest_pair(a);\n    cout << dist << endl;\n}\n"
  dependsOn:
  - template.h
  - Geometry/closest_pair.h
  isVerificationFile: true
  path: Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp
  requiredBy: []
  timestamp: '2022-01-12 00:40:19+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp
layout: document
redirect_from:
- /verify/Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp
- /verify/Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp.html
title: Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp
---
