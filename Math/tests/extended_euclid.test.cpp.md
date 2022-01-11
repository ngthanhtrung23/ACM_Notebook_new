---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/NumberTheory/ExtendedEuclid.h
    title: Math/NumberTheory/ExtendedEuclid.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"Math/tests/extended_euclid.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\n\n#line 1\
    \ \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define FOR(i,a,b)\
    \ for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b);\
    \ i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a)\
    \ for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x)\
    \ { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a\
    \ << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n)\
    \ { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define\
    \ sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n// Copied from\
    \ https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\ntemplate<class\
    \ U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {\n   \
    \ return out << '(' << p.first << \", \" << p.second << ')';\n}\n\ntemplate<class\
    \ Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
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
    \ cin.tie(0);\n    solve();\n    return 0;\n}\n#line 1 \"Math/NumberTheory/ExtendedEuclid.h\"\
    \n// D\xF9ng Extended Euclid \u0111\u1EC3 t\xECm nghi\u1EC7m c\u1EE7a ph\u01B0\
    \u01A1ng tr\xECnh ax + by = gcd(a, b).\n// Gi\u1EA3 s\u1EED k\u1EBFt qu\u1EA3\
    \ tr\u1EA3 v\u1EC1 l\xE0 (x0, y0), h\u1ECD nghi\u1EC7m c\u1EE7a ph\u01B0\u01A1\
    ng tr\xECnh s\u1EBD l\xE0 (x_0+kb/d,y_0-ka/d) v\u1EDBi k\u2208Z.\n// Ph\u01B0\u01A1\
    ng tr\xECnh t\u1ED5ng qu\xE1t ax + by = d ch\u1EC9 c\xF3 nghi\u1EC7m khi d chia\
    \ h\u1EBFt cho gcd(a, b).\n// a x + b y = gcd(a, b)\ntemplate<typename T>\nT extgcd(T\
    \ a, T b, T &x, T &y) {\n    T g = a; x = 1; y = 0;\n    if (b != 0) g = extgcd(b,\
    \ a % b, y, x), y -= (a / b) * x;\n    return g;\n}\n#line 5 \"Math/tests/extended_euclid.test.cpp\"\
    \n\nusing ll = long long;\nvoid solve() {\n    ll a, b; cin >> a >> b;\n    ll\
    \ x, y;\n    extgcd(a, b, x, y);\n    cout << x << ' ' << y << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include \"../../template.h\"\n#include \"../NumberTheory/ExtendedEuclid.h\"\
    \n\nusing ll = long long;\nvoid solve() {\n    ll a, b; cin >> a >> b;\n    ll\
    \ x, y;\n    extgcd(a, b, x, y);\n    cout << x << ' ' << y << endl;\n}\n"
  dependsOn:
  - template.h
  - Math/NumberTheory/ExtendedEuclid.h
  isVerificationFile: true
  path: Math/tests/extended_euclid.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 20:18:36+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/extended_euclid.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/extended_euclid.test.cpp
- /verify/Math/tests/extended_euclid.test.cpp.html
title: Math/tests/extended_euclid.test.cpp
---
