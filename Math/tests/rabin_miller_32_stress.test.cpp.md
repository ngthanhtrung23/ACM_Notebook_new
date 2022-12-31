---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Prime/RabinMiller32.h
    title: Math/Prime/RabinMiller32.h
  - icon: ':heavy_check_mark:'
    path: Math/Prime/SieveFast.h
    title: Math/Prime/SieveFast.h
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
  bundledCode: "#line 1 \"Math/tests/rabin_miller_32_stress.test.cpp\"\n#define PROBLEM\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Math/Prime/SieveFast.h\"\n// Tested:\n\
    // - (3B+) https://oj.vnoi.info/problem/icpc22_national_c\n// - (1B, collect into\
    \ vector of primes) https://www.spoj.com/problems/KPRIMES2/\n// - (1B, print)\
    \ https://www.spoj.com/problems/PRIMES2/\n//\n// Note:\n// - It's possible to\
    \ extract code from here to have a fast implementation\n//   of segmented sieve\
    \ for [L, R] where R is very big (e.g. 10^12)\n//   See: https://www.spoj.com/status/SUMPRIM2,mr_invincible/\n\
    //   However there are several things that need to be fixed:\n//   1. Initialization\
    \ of small primes:\n//      - Need to change 256 -> R^0.25\n//      - Change 32768\
    \ -> R^0.5\n//   2. Change N_SMALL_PRIMES\n//   3. If R^0.5 is around 10^6, p^2\
    \ overflow int, so need to check everywhere..\n//   4. si[SIEVE_SIZE] may not\
    \ have enough elements to sieve small_primes..\n//   5. update_sieve(offset) assumes\
    \ offset is a multiple of SIEVE_SPAN. This\n//      is not true if we sieve a\
    \ segment [L, R]\n//   6. Maybe more issues..\n//   Essentially if we need to\
    \ do this, either use SegmentedSieve or copy from\n//   https://www.spoj.com/status/SUMPRIM2,mr_invincible/\
    \ which I spent like an\n//   hour to make it work..\n\n// Segmented sieve with\
    \ wheel factorization {{{\nnamespace segmented_sieve_wheel {\nconst int WHEEL\
    \ = 3 * 5 * 7 * 11 * 13;\nconst int N_SMALL_PRIMES = 6536;             // cnt\
    \ primes less than 2^16\nconst int SIEVE_SPAN = WHEEL * 64;           // one iteration\
    \ of segmented sieve\nconst int SIEVE_SIZE = SIEVE_SPAN / 128 + 1;\n \nuint64_t\
    \ ONES[64];                           // ONES[i] = 1<<i\nint small_primes[N_SMALL_PRIMES];\
    \            // primes less than 2^16\n \n// each element of sieve is a 64-bit\
    \ bitmask.\n// Each bit (0/1) stores whether the corresponding element is a prime\
    \ number.\n// We only need to store odd numbers\n// -> 1st bitmask stores 3, 5,\
    \ 7, 9, ...\nuint64_t si[SIEVE_SIZE];\n// for each 'wheel', we store the sieve\
    \ pattern (i.e. what numbers cannot\n// be primes)\nuint64_t pattern[WHEEL];\n\
    \ \ninline void mark(uint64_t* s, int o) { s[o >> 6] |= ONES[o & 63]; }\ninline\
    \ int test(uint64_t* s, int o) { return (s[o >> 6] & ONES[o & 63]) == 0; }\n \n\
    // update_sieve {{{\nvoid update_sieve(uint32_t offset) {\n    // copy each wheel\
    \ pattern to sieve\n    for (int i = 0, k; i < SIEVE_SIZE; i += k) {\n       \
    \ k = std::min(WHEEL, SIEVE_SIZE - i);\n        memcpy(si + i, pattern, sizeof(*pattern)\
    \ * k);\n    }\n \n    // Correctly mark 1, 3, 5, 7, 11, 13 as not prime / primes\n\
    \    if (offset == 0) {\n        si[0] |= ONES[0];\n        si[0] &= ~(ONES[1]\
    \ | ONES[2] | ONES[3] | ONES[5] | ONES[6]);\n    }\n \n    // sieve for primes\
    \ >= 17 (stored in `small_primes`)\n    for (int i = 0; i < N_SMALL_PRIMES; ++i)\
    \ {\n        uint32_t j = small_primes[i] * (uint32_t) small_primes[i];\n    \
    \    if (j > offset + SIEVE_SPAN - 1) break;\n        if (j > offset) j = (j -\
    \ offset) >> 1;\n        else {\n            j = small_primes[i] - offset % small_primes[i];\n\
    \            if ((j & 1) == 0) j += small_primes[i];\n            j >>= 1;\n \
    \       }\n        while (j < SIEVE_SPAN / 2) {\n            mark(si, j);\n  \
    \          j += small_primes[i];\n        }\n    }\n}\n// }}}\n \ntemplate<typename\
    \ F>\nvoid sieve(uint32_t MAX, F func) {\n    // init small primes {{{\n    for\
    \ (int i = 0; i < 64; ++i) ONES[i] = 1ULL << i;\n \n    // sieve to find small\
    \ primes\n    for (int i = 3; i < 256; i += 2) {\n        if (test(si, i >> 1))\
    \ {\n            for (int j = i*i / 2; j < 32768; j += i) mark(si, j);\n     \
    \   }\n    }\n    // store primes >= 17 in `small_primes` (we will sieve differently\n\
    \    // for primes 2, 3, 5, 7, 11, 13)\n    {\n        int m = 0;\n        for\
    \ (int i = 8; i < 32768; ++i) {\n            if (test(si, i)) small_primes[m++]\
    \ = i*2 + 1;\n        }\n        assert(m == N_SMALL_PRIMES);\n    }\n    // }}}\n\
    \ \n    // For primes 3, 5, 7, 11, 13: we initialize wheel pattern..\n    for\
    \ (int i = 1; i < WHEEL * 64; i += 3) mark(pattern, i);\n    for (int i = 2; i\
    \ < WHEEL * 64; i += 5) mark(pattern, i);\n    for (int i = 3; i < WHEEL * 64;\
    \ i += 7) mark(pattern, i);\n    for (int i = 5; i < WHEEL * 64; i += 11) mark(pattern,\
    \ i);\n    for (int i = 6; i < WHEEL * 64; i += 13) mark(pattern, i);\n \n   \
    \ // Segmented sieve\n    if (2 <= MAX) func(2);\n    for (uint32_t offset = 0;\
    \ offset < MAX; offset += SIEVE_SPAN) {\n        update_sieve(offset);\n \n  \
    \      for (uint32_t j = 0; j < SIEVE_SIZE; j++){\n            uint64_t x = ~si[j];\n\
    \            while (x){\n                uint32_t p = offset + (j << 7) + (__builtin_ctzll(x)\
    \ << 1) + 1;\n                if (p > offset + SIEVE_SPAN - 1) break;\n      \
    \          if (p <= MAX) {\n                    func(p);\n                }\n\
    \                x ^= (-x & x);\n            }\n        }\n    }\n}\n}\nusing\
    \ segmented_sieve_wheel::sieve;\n// }}}\n#line 1 \"Math/Prime/RabinMiller32.h\"\
    \n// Tested:\n// - https://www.spoj.com/problems/PRIC/\n\n#line 5 \"Math/Prime/RabinMiller32.h\"\
    \n// Rabin Miller for 32-bit numbers {{{\ninline unsigned mod_mult(unsigned a,\
    \ unsigned b, unsigned m) {\n    return (uint64_t)a*b%m;\n}\n \nunsigned mod_pow(unsigned\
    \ a, uint64_t b, unsigned m) {\n    unsigned ret = 1;\n    for(;;) {\n       \
    \ if (b&1) ret = mod_mult(ret, a, m);\n        if (!(b>>=1)) return ret;\n   \
    \     a = mod_mult(a, a, m);\n    }\n}\n \nbool is_prime(unsigned n) {\n    if\
    \ (n <= 3) return (n >= 2);\n    static const unsigned small[] = {\n        2,\
    \ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,\n     \
    \   71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,\n   \
    \ };\n    for (size_t i = 0; i < sizeof(small)/sizeof(unsigned); i++) {\n    \
    \    if (n%small[i] == 0) return n == small[i];\n    }\n \n    // Jaeschke93 showed\
    \ that 2,7,61 suffice for n < 4,759,123,141.\n    static const unsigned millerrabin[]\
    \ = {2, 7, 61};\n    unsigned s = n-1, r = 0;\n    while (s%2 == 0) {s /= 2; r++;}\n\
    \ \n    for (size_t i = 0, j; i < sizeof(millerrabin)/sizeof(unsigned); i++) {\n\
    \        unsigned md = mod_pow(millerrabin[i], s, n);\n        if (md == 1) continue;\n\
    \        for (j = 1; j < r; j++) {\n            if (md == n-1) break;\n      \
    \      md = mod_mult(md, md, n);\n        }\n        if (md != n-1) return false;\n\
    \    }\n \n    return true;\n}\n// }}}\n#line 6 \"Math/tests/rabin_miller_32_stress.test.cpp\"\
    \n\nbitset<INT_MAX> all_primes;\nvoid newPrime(int p) {\n    all_primes[p] = 1;\n\
    }\n\nvoid solve() {\n    srand(7777);\n    sieve(INT_MAX, newPrime);\n    cerr\
    \ << \"DONE SIEVE\" << endl;\n    for (int i = 0; i < INT_MAX; ++i) {\n      \
    \  if (rand() % 30) continue;\n        if (all_primes[i] == 1) assert(is_prime(i));\n\
    \        else assert(!is_prime(i));\n    }\n\n    cout << \"Hello World\\n\";\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../template.h\"\n#include \"../Prime/SieveFast.h\"\n#include\
    \ \"../Prime/RabinMiller32.h\"\n\nbitset<INT_MAX> all_primes;\nvoid newPrime(int\
    \ p) {\n    all_primes[p] = 1;\n}\n\nvoid solve() {\n    srand(7777);\n    sieve(INT_MAX,\
    \ newPrime);\n    cerr << \"DONE SIEVE\" << endl;\n    for (int i = 0; i < INT_MAX;\
    \ ++i) {\n        if (rand() % 30) continue;\n        if (all_primes[i] == 1)\
    \ assert(is_prime(i));\n        else assert(!is_prime(i));\n    }\n\n    cout\
    \ << \"Hello World\\n\";\n}\n"
  dependsOn:
  - template.h
  - Math/Prime/SieveFast.h
  - Math/Prime/RabinMiller32.h
  isVerificationFile: true
  path: Math/tests/rabin_miller_32_stress.test.cpp
  requiredBy: []
  timestamp: '2022-12-26 20:01:50+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/rabin_miller_32_stress.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/rabin_miller_32_stress.test.cpp
- /verify/Math/tests/rabin_miller_32_stress.test.cpp.html
title: Math/tests/rabin_miller_32_stress.test.cpp
---
