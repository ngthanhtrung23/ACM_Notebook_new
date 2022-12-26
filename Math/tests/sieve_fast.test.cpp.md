---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Prime/SieveFast.h
    title: Math/Prime/SieveFast.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"Math/tests/sieve_fast.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Math/Prime/SieveFast.h\"\
    \n// Tested:\n// - (3B+) https://oj.vnoi.info/problem/icpc22_national_c\n// -\
    \ (1B, collect into vector of primes) https://www.spoj.com/problems/KPRIMES2/\n\
    // - (1B, print) https://www.spoj.com/problems/PRIMES2/\n//\n// Note:\n// - It's\
    \ possible to extract code from here to have a fast implementation\n//   of segmented\
    \ sieve for [L, R] where R is very big (e.g. 10^12)\n//   See: https://www.spoj.com/status/SUMPRIM2,mr_invincible/\n\
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
    \ segmented_sieve_wheel::sieve;\n// }}}\n#line 7 \"Math/tests/sieve_fast.test.cpp\"\
    \n\nint n, a, b, cnt = 0, cnt_mod = 0;\nvector<int> ps;\nvoid newPrime(int p)\
    \ {\n    if (p > n) {\n        cout << cnt << ' ' << ps.size() << '\\n';\n   \
    \     for (int x : ps) cout << x << ' ';\n        exit(0);\n    }\n    if (cnt_mod\
    \ == b) ps.push_back(p);\n    ++cnt;\n    ++cnt_mod;\n    if (cnt_mod == a) cnt_mod\
    \ = 0;\n}\n\nint32_t main() {\n    cin >> n >> a >> b;\n    sieve(1'000'000'000,\
    \ newPrime);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Prime/SieveFast.h\"\
    \n\nint n, a, b, cnt = 0, cnt_mod = 0;\nvector<int> ps;\nvoid newPrime(int p)\
    \ {\n    if (p > n) {\n        cout << cnt << ' ' << ps.size() << '\\n';\n   \
    \     for (int x : ps) cout << x << ' ';\n        exit(0);\n    }\n    if (cnt_mod\
    \ == b) ps.push_back(p);\n    ++cnt;\n    ++cnt_mod;\n    if (cnt_mod == a) cnt_mod\
    \ = 0;\n}\n\nint32_t main() {\n    cin >> n >> a >> b;\n    sieve(1'000'000'000,\
    \ newPrime);\n    return 0;\n}\n"
  dependsOn:
  - Math/Prime/SieveFast.h
  isVerificationFile: true
  path: Math/tests/sieve_fast.test.cpp
  requiredBy: []
  timestamp: '2022-12-26 19:50:08+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/sieve_fast.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/sieve_fast.test.cpp
- /verify/Math/tests/sieve_fast.test.cpp.html
title: Math/tests/sieve_fast.test.cpp
---
