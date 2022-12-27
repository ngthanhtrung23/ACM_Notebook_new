---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/NumberTheory/Pollard.h
    title: Math/NumberTheory/Pollard.h
  - icon: ':heavy_check_mark:'
    path: Math/NumberTheory/cnt_divisors.h
    title: Math/NumberTheory/cnt_divisors.h
  - icon: ':heavy_check_mark:'
    path: Math/multiplicative_function.h
    title: Math/multiplicative_function.h
  - icon: ':heavy_check_mark:'
    path: Math/multiplicative_functions_linear.h
    title: Math/multiplicative_functions_linear.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"Math/tests/cnt_divisors_stress.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n#line\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Math/NumberTheory/Pollard.h\"\n// Pollard\
    \ {{{\n// Copied from https://judge.yosupo.jp/submission/61447\n// O(N^0.25)\n\
    //\n// Tested:\n// - (up to 10^18; 200 tests) https://judge.yosupo.jp/problem/factorize\n\
    // - https://oj.vnoi.info/problem/icpc21_beta_l\n// - https://www.spoj.com/problems/FACT0/\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    ll mult(ll x, ll y, ll md) {\n    ull q = (ld)x * y / md;\n    ll res = ((ull)x\
    \ * y - q * md);\n    if (res >= md) res -= md;\n    if (res < 0) res += md;\n\
    \    return res;\n}\n\nll powMod(ll x, ll p, ll md) {\n    if (p == 0) return\
    \ 1;\n    if (p & 1) return mult(x, powMod(x, p - 1, md), md);\n    return powMod(mult(x,\
    \ x, md), p / 2, md);\n}\n\nbool checkMillerRabin(ll x, ll md, ll s, int k) {\n\
    \    x = powMod(x, s, md);\n    if (x == 1) return true;\n    while(k--) {\n \
    \       if (x == md - 1) return true;\n        x = mult(x, x, md);\n        if\
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
    \  }\n}\n// return list of all prime factors of x (can have duplicates)\nvector<ll>\
    \ factorize(ll x) {\n    vector<ll> ans;\n    for (ll p : {2, 3, 5, 7, 11, 13,\
    \ 17, 19}) {\n        while(x % p == 0) {\n            x /= p;\n            ans.push_back(p);\n\
    \        }\n    }\n    if (x != 1) {\n        pollard(x, ans);\n    }\n    sort(ans.begin(),\
    \ ans.end());\n    return ans;\n}\n// return pairs of (p, k) where x = product(p^k)\n\
    vector<pair<ll, int>> factorize_pk(ll x) {\n    auto ps = factorize(x);\n    ll\
    \ last = -1, cnt = 0;\n    vector<pair<ll, int>> res;\n    for (auto p : ps) {\n\
    \        if (p == last) ++cnt;\n        else {\n            if (last > 0) res.emplace_back(last,\
    \ cnt);\n            last = p;\n            cnt = 1;\n        }\n    }\n    if\
    \ (cnt > 0) {\n        res.emplace_back(last, cnt);\n    }\n    return res;\n\
    }\n// }}}\n#line 2 \"Math/NumberTheory/cnt_divisors.h\"\n\n// Tested: https://www.spoj.com/problems/NUMDIV/\n\
    int64_t cnt_divisors(int64_t n) {\n    assert(n > 0);\n    auto ps = factorize(n);\n\
    \    int cnt_ps = ps.size();\n    int i = 0;\n    int64_t res = 1;\n    while\
    \ (i < cnt_ps) {\n        int j = i;\n        while (j+1 < cnt_ps && ps[j+1] ==\
    \ ps[j]) ++j;\n        res *= j - i + 2;\n        i = j + 1;\n    }\n    return\
    \ res;\n}\n#line 1 \"Math/multiplicative_function.h\"\n// NOTE: calculate upto\
    \ N-1\n//\n// Multiplicative function {{{\ntemplate<int N>\nstruct MultiplicativeFunction\
    \ {\n    // Init sieve and pk\n    MultiplicativeFunction() {\n        // Init\
    \ sieve\n        for (int i = 2; i*i < N; i++) {\n            if (!sieve[i]) {\n\
    \                for (int j = i*i; j < N; j += i) {\n                    sieve[j]\
    \ = i;\n                }\n            }\n        }\n\n        // Init pk\n  \
    \      for (int i = 2; i < N; i++) {\n            if (!sieve[i]) {\n         \
    \       pk[i] = {i, 1};\n            } else {\n                int p = sieve[i];\n\
    \n                if (pk[i/p].first == p) { // i = p^k\n                    pk[i]\
    \ = {p, pk[i/p].second + 1};\n                } else {\n                    pk[i]\
    \ = {-1, 0};\n                }\n            }\n        }\n    }\n\n    // Tested:\
    \ https://cses.fi/problemset/task/1713\n    array<int, N> divisors() {\n     \
    \   array<int, N> res;\n        res[1] = 1;\n\n        for (int i = 2; i < N;\
    \ i++) {\n            if (pk[i].first > 0) {  // i = p^k\n                res[i]\
    \ = pk[i].second + 1;\n            } else {\n                // i = u * v, gcd(u,\
    \ v) = 1\n                int u = i, v = 1;\n                int p = sieve[i];\n\
    \                while (u % p == 0) {\n                    u /= p;\n         \
    \           v *= p;\n                }\n                res[i] = res[u] * res[v];\n\
    \            }\n        }\n\n        return res;\n    }\n\n    // mobius(n) =\
    \ 1  if n is square-free and has *even* number of prime factors\n    // mobius(n)\
    \ = -1 if n is square-free and has *odd* number of of prime factors\n    // mobius(n)\
    \ = 0  if n is not square-free\n    array<int, N> mobius() {\n        array<int,\
    \ N> res;\n        res[1] = 1;\n\n        for (int i = 2; i < N; ++i) {\n    \
    \        if (pk[i].first > 0) {  // i = p^k\n                res[i] = (pk[i].second\
    \ >= 2) ? 0 : -1;\n            } else {\n                // i = u * v, gcd(u,\
    \ v) = 1\n                int u = i, v = 1;\n                int p = sieve[i];\n\
    \                while (u % p == 0) {\n                    u /= p;\n         \
    \           v *= p;\n                }\n                res[i] = res[u] * res[v];\n\
    \            }\n        }\n        return res;\n    }\n\n// private:\n    // sieve[i]\
    \ == 0 if i is prime,\n    // sieve[i] = any prime factor p otherwise\n    array<int,\
    \ N> sieve = {0};\n\n    // pk[i] = {p, k} if i == p^k\n    // pk[i] = {-1, 0}\
    \ otherwise\n    array<pair<int,int>, N> pk;\n};\n// }}}\n#line 6 \"Math/tests/cnt_divisors_stress.test.cpp\"\
    \n\nconst int N = 1000000;\nMultiplicativeFunction<N + 1> mf;\nauto divisors =\
    \ mf.divisors();\n\n#line 1 \"Math/multiplicative_functions_linear.h\"\n// This\
    \ is only for calculating multiplicative functions\n// If we need a fast sieve,\
    \ see SieveFast.h\n// From https://codeforces.com/blog/entry/54090\nnamespace\
    \ linear_sieve {\nconst int MN = 2e7;\nvector<int> primes;\n\n// Euler Phi {{{\n\
    bool is_composite[MN];\nint phi[MN];\n\nvoid linear_sieve_phi(int n) {\n    memset(is_composite,\
    \ false, sizeof is_composite);\n    primes.clear();\n \n    phi[1] = 1;\n    for\
    \ (int i = 2; i < n; ++i) {\n        if (!is_composite[i]) {\n            primes.push_back(i);\n\
    \            phi[i] = i - 1; // i is prime\n        }\n        for (int j = 0;\
    \ j < (int) primes.size() && i * primes[j] < n; ++j) {\n            is_composite[i\
    \ * primes[j]] = true;\n            if (i % primes[j] == 0) {\n              \
    \  phi[i * primes[j]] = phi[i] * primes[j]; //primes[j] divides i\n          \
    \      break;\n            } else {\n                phi[i * primes[j]] = phi[i]\
    \ * phi[primes[j]]; //primes[j] does not divide i\n            }\n        }\n\
    \    }\n}\n// }}}\n\n// Number of divisors {{{\nint cnt_divisors[MN + 11];  //\
    \ call linear_sieve_divisors(n+1) to init\nint cnt[MN + 11];\nvoid linear_sieve_divisors(int\
    \ n) {  // init range [1, n-1]\n    memset(is_composite, false, sizeof is_composite);\n\
    \    primes.clear();\n\n    cnt_divisors[1] = 1;\n    for (int i = 2; i < n; ++i)\
    \ {\n        if (!is_composite[i]) {\n            primes.push_back(i);\n     \
    \       cnt[i] = 1;\n            cnt_divisors[i] = 2;\n        }\n        for\
    \ (int j = 0; j < (int) primes.size() && i * primes[j] < n; ++j) {\n         \
    \   int ip = i * primes[j];\n            is_composite[ip] = true;\n          \
    \  if (i % primes[j] == 0) {\n                cnt[ip] = cnt[i] + 1;\n        \
    \        cnt_divisors[ip] = cnt_divisors[i] / (cnt[i] + 1) * (cnt[i] + 2);\n \
    \           } else {\n                cnt[ip] = 1;\n                cnt_divisors[ip]\
    \ = 2 * cnt_divisors[i];\n            }\n        }\n    }\n}\n// }}}\n\n}\n#line\
    \ 12 \"Math/tests/cnt_divisors_stress.test.cpp\"\n\nvoid solve() {\n    linear_sieve::linear_sieve_divisors(N\
    \ + 1);\n    for (int i = 1; i <= N; ++i) {\n        assert(divisors[i] == cnt_divisors(i));\n\
    \        assert(divisors[i] == linear_sieve::cnt_divisors[i]);\n    }\n    cout\
    \ << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../template.h\"\n#include \"../NumberTheory/cnt_divisors.h\"\
    \n#include \"../multiplicative_function.h\"\n\nconst int N = 1000000;\nMultiplicativeFunction<N\
    \ + 1> mf;\nauto divisors = mf.divisors();\n\n#include \"../multiplicative_functions_linear.h\"\
    \n\nvoid solve() {\n    linear_sieve::linear_sieve_divisors(N + 1);\n    for (int\
    \ i = 1; i <= N; ++i) {\n        assert(divisors[i] == cnt_divisors(i));\n   \
    \     assert(divisors[i] == linear_sieve::cnt_divisors[i]);\n    }\n    cout <<\
    \ \"Hello World\\n\";\n}\n"
  dependsOn:
  - template.h
  - Math/NumberTheory/cnt_divisors.h
  - Math/NumberTheory/Pollard.h
  - Math/multiplicative_function.h
  - Math/multiplicative_functions_linear.h
  isVerificationFile: true
  path: Math/tests/cnt_divisors_stress.test.cpp
  requiredBy: []
  timestamp: '2022-12-27 15:34:50+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/cnt_divisors_stress.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/cnt_divisors_stress.test.cpp
- /verify/Math/tests/cnt_divisors_stress.test.cpp.html
title: Math/tests/cnt_divisors_stress.test.cpp
---
