---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Prime/EulerPhi.h
    title: Math/Prime/EulerPhi.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"Math/tests/euler_phi.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
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
    \ cin.tie(0);\n    solve();\n    return 0;\n}\n#line 1 \"Math/Prime/EulerPhi.h\"\
    \nlong long eulerPhi(long long n) { // = n (1-1/p1) ... (1-1/pn)\n    if (n ==\
    \ 0) return 0;\n    long long ans = n;\n    for (int x = 2; x*x <= n; ++x) {\n\
    \        if (n % x == 0) {\n            ans -= ans / x;\n            while (n\
    \ % x == 0) n /= x;\n        }\n    }\n    if (n > 1) ans -= ans / n;\n    return\
    \ ans;\n}\n// LookUp Version\nconst int N = 1000000;\nint eulerPhi_lookup(int\
    \ n) {\n    static int lookup = 0, p[N], f[N];\n    if (!lookup) {\n        REP(i,N)\
    \ p[i] = 1, f[i] = i;\n        for (int i = 2; i < N; ++i) {\n            if (p[i])\
    \ {\n            f[i] -= f[i] / i;\n                for (int j = i+i; j < N; j+=i)\n\
    \                    p[j] = 0, f[j] -= f[j] / i;\n            }\n        }\n \
    \       lookup = 1;\n    }\n    return f[n];\n}\n#line 5 \"Math/tests/euler_phi.test.cpp\"\
    \n\nusing ll = long long;\nvoid solve() {\n    ll n; cin >> n;\n    if (n < N)\
    \ {\n        assert(eulerPhi(n) == eulerPhi_lookup(n));\n    }\n    cout << eulerPhi(n)\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include \"../../template.h\"\n#include \"../Prime/EulerPhi.h\"\n\nusing ll\
    \ = long long;\nvoid solve() {\n    ll n; cin >> n;\n    if (n < N) {\n      \
    \  assert(eulerPhi(n) == eulerPhi_lookup(n));\n    }\n    cout << eulerPhi(n)\
    \ << endl;\n}\n"
  dependsOn:
  - template.h
  - Math/Prime/EulerPhi.h
  isVerificationFile: true
  path: Math/tests/euler_phi.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 20:18:36+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/euler_phi.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/euler_phi.test.cpp
- /verify/Math/tests/euler_phi.test.cpp.html
title: Math/tests/euler_phi.test.cpp
---
