---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Prime/RabinMiller.h
    title: Math/Prime/RabinMiller.h
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
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"Math/tests/yosupo_primality_rabin_miller.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#line 1 \"template.h\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define FOR(i,a,b) for(int\
    \ i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b;\
    \ i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a) for(__typeof(a.begin())\
    \ it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x) { cout << #x << \"\
    \ = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n)\
    \ cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n) { cout << #a << \" =\
    \ \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\n\
    \n// For printing pair, container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Math/Prime/RabinMiller.h\"\n// From https://github.com/SnapDragon64/ContestLibrary/blob/master/math.h\n\
    // which also has specialized versions for 32-bit and 42-bit\n//\n// Tested:\n\
    // - https://oj.vnoi.info/problem/icpc22_national_c (fastest solution)\n// - https://www.spoj.com/problems/PON/\n\
    \n// Rabin miller {{{\ninline uint64_t mod_mult64(uint64_t a, uint64_t b, uint64_t\
    \ m) {\n    return __int128_t(a) * b % m;\n}\nuint64_t mod_pow64(uint64_t a, uint64_t\
    \ b, uint64_t m) {\n    uint64_t ret = (m > 1);\n    for (;;) {\n        if (b\
    \ & 1) ret = mod_mult64(ret, a, m);\n        if (!(b >>= 1)) return ret;\n   \
    \     a = mod_mult64(a, a, m);\n    }\n}\n\n// Works for all primes p < 2^64\n\
    bool is_prime(uint64_t n) {\n    if (n <= 3) return (n >= 2);\n    static const\
    \ uint64_t small[] = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,\
    \ 43, 47, 53, 59, 61, 67,\n        71, 73, 79, 83, 89, 97, 101, 103, 107, 109,\
    \ 113, 127, 131, 137, 139,\n        149, 151, 157, 163, 167, 173, 179, 181, 191,\
    \ 193, 197, 199,\n    };\n    for (size_t i = 0; i < sizeof(small) / sizeof(uint64_t);\
    \ ++i) {\n        if (n % small[i] == 0) return n == small[i];\n    }\n\n    //\
    \ Makes use of the known bounds for Miller-Rabin pseudoprimes.\n    static const\
    \ uint64_t millerrabin[] = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    \ 37,\n    };\n    static const uint64_t A014233[] = {  // From OEIS.\n      \
    \  2047LL, 1373653LL, 25326001LL, 3215031751LL, 2152302898747LL,\n        3474749660383LL,\
    \ 341550071728321LL, 341550071728321LL,\n        3825123056546413051LL, 3825123056546413051LL,\
    \ 3825123056546413051LL, 0,\n    };\n    uint64_t s = n-1, r = 0;\n    while (s\
    \ % 2 == 0) {\n        s /= 2;\n        r++;\n    }\n    for (size_t i = 0, j;\
    \ i < sizeof(millerrabin) / sizeof(uint64_t); i++) {\n        uint64_t md = mod_pow64(millerrabin[i],\
    \ s, n);\n        if (md != 1) {\n            for (j = 1; j < r; j++) {\n    \
    \            if (md == n-1) break;\n                md = mod_mult64(md, md, n);\n\
    \            }\n            if (md != n-1) return false;\n        }\n        if\
    \ (n < A014233[i]) return true;\n    }\n    return true;\n}\n// }}}\n#line 5 \"\
    Math/tests/yosupo_primality_rabin_miller.test.cpp\"\n\nvoid solve() {\n    int\
    \ q; cin >> q;\n    while (q--) {\n        int64_t n; cin >> n;\n        cout\
    \ << (is_prime(n) ? \"Yes\" : \"No\") << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ \"../../template.h\"\n#include \"../Prime/RabinMiller.h\"\n\nvoid solve() {\n\
    \    int q; cin >> q;\n    while (q--) {\n        int64_t n; cin >> n;\n     \
    \   cout << (is_prime(n) ? \"Yes\" : \"No\") << '\\n';\n    }\n}\n"
  dependsOn:
  - template.h
  - Math/Prime/RabinMiller.h
  isVerificationFile: true
  path: Math/tests/yosupo_primality_rabin_miller.test.cpp
  requiredBy: []
  timestamp: '2023-05-27 17:03:34+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/yosupo_primality_rabin_miller.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/yosupo_primality_rabin_miller.test.cpp
- /verify/Math/tests/yosupo_primality_rabin_miller.test.cpp.html
title: Math/tests/yosupo_primality_rabin_miller.test.cpp
---
