---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/NumberTheory/Pollard.h
    title: Math/NumberTheory/Pollard.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"Math/tests/aizu_ntl_1_a_factorize.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\n\n#line\
    \ 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b);\
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
    \ (0, r-1)(rng);\n}\n\ntemplate<typename T>\nvector<T> read_vector(int n) {\n\
    \    vector<T> res(n);\n    for (int& x : res) cin >> x;\n    return res;\n}\n\
    \nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n  \
    \  solve();\n    return 0;\n}\n#line 1 \"Math/NumberTheory/Pollard.h\"\n// Pollard\n\
    // Copied from https://judge.yosupo.jp/submission/61447\n//\n// Tested:\n// -\
    \ (up to 10^18) https://judge.yosupo.jp/problem/factorize\n// - https://oj.vnoi.info/problem/icpc21_beta_l\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    ll mult(ll x, ll y, ll md) {\n    ull q = (ld)x * y / md;\n    ll res = ((ull)x\
    \ * y - q * md);\n    if (res >= md) res -= md;\n    if (res < 0) res += md;\n\
    \    return res;\n}\n\nll bin_pow(ll x, ll p, ll md) {\n    if (p == 0) return\
    \ 1;\n    if (p & 1) return mult(x, bin_pow(x, p - 1, md), md);\n    return bin_pow(mult(x,\
    \ x, md), p / 2, md);\n}\n\nbool checkMillerRabin(ll x, ll md, ll s, int k) {\n\
    \    x = bin_pow(x, s, md);\n    if (x == 1) return true;\n    while(k--) {\n\
    \        if (x == md - 1) return true;\n        x = mult(x, x, md);\n        if\
    \ (x == 1) return false;\n    }\n    return false;\n}\nbool isPrime(ll x) {\n\
    \    if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n    if (x % 2 ==\
    \ 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n    if (x < 121)\
    \ return x > 1;\n    ll s = x - 1;\n    int k = 0;\n    while(s % 2 == 0) {\n\
    \        s >>= 1;\n        k++;\n    }\n    if (x < 1LL << 32) {\n        for\
    \ (ll z : {2, 7, 61}) {\n            if (!checkMillerRabin(z, x, s, k)) return\
    \ false;\n        }\n    } else {\n        for (ll z : {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\n            if (!checkMillerRabin(z, x, s, k)) return\
    \ false;\n        }\n    }\n    return true;\n}\n\nll gcd(ll x, ll y) {\n    return\
    \ y == 0 ? x : gcd(y, x % y);\n}\n\nvoid pollard(ll x, vector<ll> &ans) {\n  \
    \  if (isPrime(x)) {\n        ans.push_back(x);\n        return;\n    }\n    ll\
    \ c = 1;\n    while(true) {\n        c = 1 + get_rand(x - 1);\n        auto f\
    \ = [&](ll y) {\n            ll res = mult(y, y, x) + c;\n            if (res\
    \ >= x) res -= x;\n            return res;\n        };\n        ll y = 2;\n  \
    \      int B = 100;\n        int len = 1;\n        ll g = 1;\n        while(g\
    \ == 1) {\n            ll z = y;\n            for (int i = 0; i < len; i++) {\n\
    \                z = f(z);\n            }\n            ll zs = -1;\n         \
    \   int lft = len;\n            while(g == 1 && lft > 0) {\n                zs\
    \ = z;\n                ll p = 1;\n                for (int i = 0; i < B && i\
    \ < lft; i++) {\n                    p = mult(p, abs(z - y), x);\n           \
    \         z = f(z);\n                }\n                g = gcd(p, x);\n     \
    \           lft -= B;\n            }\n            if (g == 1) {\n            \
    \    y = z;\n                len <<= 1;\n                continue;\n         \
    \   }\n            if (g == x) {\n                g = 1;\n                z =\
    \ zs;\n                while(g == 1) {\n                    g = gcd(abs(z - y),\
    \ x);\n                    z = f(z);\n                }\n            }\n     \
    \       if (g == x) break;\n            assert(g != 1);\n            pollard(g,\
    \ ans);\n            pollard(x / g, ans);\n            return;\n        }\n  \
    \  }\n}\nvector<ll> factorize(ll x) {\n    vector<ll> ans;\n    for (ll p : {2,\
    \ 3, 5, 7, 11, 13, 17, 19}) {\n        while(x % p == 0) {\n            x /= p;\n\
    \            ans.push_back(p);\n        }\n    }\n    if (x != 1) {\n        pollard(x,\
    \ ans);\n    }\n    sort(ans.begin(), ans.end());\n    return ans;\n}\n#line 5\
    \ \"Math/tests/aizu_ntl_1_a_factorize.test.cpp\"\n\nvoid solve() {\n    int n;\n\
    \    cin >> n;\n    auto facs = factorize(n);\n    cout << n << ':';\n    for\
    \ (auto x : facs) cout << ' ' << x;\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#include \"../../template.h\"\n#include \"../NumberTheory/Pollard.h\"\n\n\
    void solve() {\n    int n;\n    cin >> n;\n    auto facs = factorize(n);\n   \
    \ cout << n << ':';\n    for (auto x : facs) cout << ' ' << x;\n    cout << '\\\
    n';\n}\n"
  dependsOn:
  - template.h
  - Math/NumberTheory/Pollard.h
  isVerificationFile: true
  path: Math/tests/aizu_ntl_1_a_factorize.test.cpp
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Math/tests/aizu_ntl_1_a_factorize.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/aizu_ntl_1_a_factorize.test.cpp
- /verify/Math/tests/aizu_ntl_1_a_factorize.test.cpp.html
title: Math/tests/aizu_ntl_1_a_factorize.test.cpp
---
