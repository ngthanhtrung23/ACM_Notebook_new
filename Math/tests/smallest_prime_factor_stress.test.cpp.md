---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/multiplicative_functions_linear.h
    title: Math/multiplicative_functions_linear.h
  - icon: ':question:'
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
  bundledCode: "#line 1 \"Math/tests/smallest_prime_factor_stress.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
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
    \ (0, r-1)(rng);\n}\n\ntemplate<typename T>\nvector<T> read_vector(int n) {\n\
    \    vector<T> res(n);\n    for (int& x : res) cin >> x;\n    return res;\n}\n\
    \nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n  \
    \  solve();\n    return 0;\n}\n#line 1 \"Math/multiplicative_functions_linear.h\"\
    \n// This is only for calculating multiplicative functions\n// If we need a fast\
    \ sieve, see SieveFast.h\n// From https://codeforces.com/blog/entry/54090\nnamespace\
    \ linear_sieve {\nconst int MN = 2e7;\nvector<int> primes;\n\nint smallest_p[MN];\
    \  // smallest_p[n] = smallest prime factor of n\nvoid linear_sieve_smallest_prime_factor(int\
    \ n) {\n    primes.clear();\n    memset(smallest_p, 0, sizeof smallest_p);\n\n\
    \    for (int i = 2; i < n; ++i) {\n        if (!smallest_p[i]) primes.push_back(i);\n\
    \        for (int j = 0; j < int(primes.size()) && i * primes[j] < n; ++j) {\n\
    \            smallest_p[i * primes[j]] = primes[j];\n            if (i % primes[j]\
    \ == 0) break;\n        }\n    }\n}\n\n// Euler Phi {{{\nbool is_composite[MN];\n\
    int phi[MN];\n\nvoid linear_sieve_phi(int n) {\n    memset(is_composite, false,\
    \ sizeof is_composite);\n    primes.clear();\n \n    phi[1] = 1;\n    for (int\
    \ i = 2; i < n; ++i) {\n        if (!is_composite[i]) {\n            primes.push_back(i);\n\
    \            phi[i] = i - 1; // i is prime\n        }\n        for (int j = 0;\
    \ j < (int) primes.size() && i * primes[j] < n; ++j) {\n            is_composite[i\
    \ * primes[j]] = true;\n            if (i % primes[j] == 0) {\n              \
    \  phi[i * primes[j]] = phi[i] * primes[j]; //primes[j] divides i\n          \
    \      break;\n            } else {\n                phi[i * primes[j]] = phi[i]\
    \ * phi[primes[j]]; //primes[j] does not divide i\n            }\n        }\n\
    \    }\n}\n// }}}\n\n// Number of divisors {{{\nint cnt_divisors[MN + 11];  //\
    \ call linear_sieve_divisors(n+1) to init\nint cnt[MN + 11];           // power\
    \ of smallest prime factor of i\nvoid linear_sieve_divisors(int n) {  // init\
    \ range [1, n-1]\n    memset(is_composite, false, sizeof is_composite);\n    primes.clear();\n\
    \n    cnt_divisors[1] = 1;\n    for (int i = 2; i < n; ++i) {\n        if (!is_composite[i])\
    \ {\n            primes.push_back(i);\n            cnt[i] = 1;\n            cnt_divisors[i]\
    \ = 2;\n        }\n        for (int j = 0; j < (int) primes.size() && i * primes[j]\
    \ < n; ++j) {\n            int ip = i * primes[j];\n            is_composite[ip]\
    \ = true;\n            if (i % primes[j] == 0) {\n                cnt[ip] = cnt[i]\
    \ + 1;\n                cnt_divisors[ip] = cnt_divisors[i] / (cnt[i] + 1) * (cnt[i]\
    \ + 2);\n            } else {\n                cnt[ip] = 1;\n                cnt_divisors[ip]\
    \ = 2 * cnt_divisors[i];\n            }\n        }\n    }\n}\n// }}}\n\n}\n#line\
    \ 5 \"Math/tests/smallest_prime_factor_stress.test.cpp\"\nusing namespace linear_sieve;\n\
    \nvoid solve() {\n    const int N = 10000;\n    linear_sieve_smallest_prime_factor(N\
    \ + 1);\n    assert(smallest_p[1] == 0);\n    for (int n = 2; n <= N; ++n) {\n\
    \        bool is_prime = true;\n        for (int i = 2; i*i <= n; ++i) {\n   \
    \         if (n % i == 0) {\n                is_prime = false;\n             \
    \   assert(smallest_p[n] == i);\n                break;\n            }\n     \
    \   }\n        if (is_prime) assert(smallest_p[n] == 0);\n    }\n    cout << \"\
    Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../template.h\"\n#include \"../multiplicative_functions_linear.h\"\
    \nusing namespace linear_sieve;\n\nvoid solve() {\n    const int N = 10000;\n\
    \    linear_sieve_smallest_prime_factor(N + 1);\n    assert(smallest_p[1] == 0);\n\
    \    for (int n = 2; n <= N; ++n) {\n        bool is_prime = true;\n        for\
    \ (int i = 2; i*i <= n; ++i) {\n            if (n % i == 0) {\n              \
    \  is_prime = false;\n                assert(smallest_p[n] == i);\n          \
    \      break;\n            }\n        }\n        if (is_prime) assert(smallest_p[n]\
    \ == 0);\n    }\n    cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - template.h
  - Math/multiplicative_functions_linear.h
  isVerificationFile: true
  path: Math/tests/smallest_prime_factor_stress.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 13:01:49+07:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/smallest_prime_factor_stress.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/smallest_prime_factor_stress.test.cpp
- /verify/Math/tests/smallest_prime_factor_stress.test.cpp.html
title: Math/tests/smallest_prime_factor_stress.test.cpp
---
