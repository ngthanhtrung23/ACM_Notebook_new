---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/convolution_and.test.cpp
    title: Math/tests/convolution_and.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/convolution_xor.test.cpp
    title: Math/tests/convolution_xor.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
    - https://csacademy.com/contest/archive/task/and-closure
    - https://csacademy.com/contest/archive/task/maxor/
    - https://csacademy.com/contest/archive/task/random_nim_generator/
  bundledCode: "#line 1 \"Math/Polynomial/xorFFT.h\"\n// Tutorial: https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it\n\
    // Walsh\u2013Hadamard transform\n//\n// xor FFT:\n// - Given 2 arrays A and B\
    \ of length N = 2^k.\n// - For each (i, j): C[i ^ j] = C[i ^ j] + A[i] * B[j]\n\
    //\n// Tested:\n// XOR:\n// - https://csacademy.com/contest/archive/task/random_nim_generator/\n\
    //\n// AND:\n// - https://csacademy.com/contest/archive/task/and-closure\n//\n\
    // OR:\n// - https://csacademy.com/contest/archive/task/maxor/\n\n#define REP(i,\
    \ a) for (int i = 0, _##i = (a); i < _##i; ++i)\nlong long power(long long x,\
    \ long long k, long long MOD) {\n    long long res = 1;\n    while (k) {\n   \
    \     if (k & 1) res = res * x % MOD;\n        k >>= 1;\n        x = x * x % MOD;\n\
    \    }\n    return res;\n}\n\n// H = [1 1; 1 -1]\nvoid xorFFT(long long a[], int\
    \ n, int MOD, int invert) {\n    assert(__builtin_popcountll(n) == 1);  // N must\
    \ be power of 2.\n\n    for (int len = 1; len < n; len <<= 1) {\n        for (int\
    \ i = 0; i < n; i += len << 1) {\n            for (int j = 0; j < len; j++) {\n\
    \                long long u = a[i + j];\n                long long v = a[i +\
    \ j + len];\n\n                a[i + j] = u + v;\n                if (a[i + j]\
    \ >= MOD) a[i + j] -= MOD;\n\n                a[i + j + len] = u - v;\n      \
    \          if (a[i + j + len] < 0) a[i + j + len] += MOD;\n            }\n   \
    \     }\n    }\n\n    if (invert) {\n        long long inv = power(n, MOD - 2,\
    \ MOD);\n        REP(i,n) a[i] = a[i] * inv % MOD;\n    }\n}\n\n// H = [0 1; 1\
    \ 1]\nvoid andFFT(long long a[], int n, int MOD, int invert) {\n    assert(__builtin_popcountll(n)\
    \ == 1);  // N must be power of 2.\n\n    for (int len = 1; len < n; len <<= 1)\
    \ {\n        for (int i = 0; i < n; i += len << 1) {\n            for (int j =\
    \ 0; j < len; j++) {\n                long long u = a[i + j];\n              \
    \  long long v = a[i + j + len];\n\n                if (!invert) {\n         \
    \           a[i + j] = v;\n                    a[i + j + len] = u + v;\n     \
    \               if (a[i + j + len] >= MOD) a[i + j + len] -= MOD;\n          \
    \      } else {\n                    a[i + j] = v - u;\n                    if\
    \ (a[i + j] < 0) a[i + j] += MOD;\n                    a[i + j + len] = u;\n \
    \               }\n            }\n        }\n    }\n}\n\n// H = [1 1; 1 0]\nvoid\
    \ orFFT(long long a[], int n, int MOD, int invert) {\n    assert(__builtin_popcountll(n)\
    \ == 1);  // N must be power of 2.\n\n    for (int len = 1; len < n; len <<= 1)\
    \ {\n        for (int i = 0; i < n; i += len << 1) {\n            for (int j =\
    \ 0; j < len; j++) {\n                long long u = a[i + j];\n              \
    \  long long v = a[i + j + len];\n\n                if (!invert) {\n         \
    \           a[i + j] = u + v;\n                    if (a[i + j] >= MOD) a[i +\
    \ j] -= MOD;\n\n                    a[i + j + len] = u;\n                } else\
    \ {\n                    a[i + j] = v;\n                    a[i + j + len] = u\
    \ - v;\n                    if (a[i + j + len] < 0) a[i + j + len] += MOD;\n \
    \               }\n            }\n        }\n    }\n}\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    int get_rand(int r) {\n    return uniform_int_distribution<int> (0, r-1)(rng);\n\
    }\n\nnamespace Test {\n#define TWO(X) (1LL << (X))\n    const int MAXN = 1e5 +\
    \ 5;\n    const int MAXV = 100;\n    long long a[MAXN], b[MAXN], c[MAXN];\n  \
    \  void testXorFFT() {\n        memset(a, 0, sizeof a);\n        memset(b, 0,\
    \ sizeof b);\n        memset(c, 0, sizeof c);\n\n        int n = TWO(11);\n  \
    \      const int MOD = 1e9 + 7;\n        REP(i,n) a[i] = get_rand(MAXV);\n   \
    \     REP(i,n) b[i] = get_rand(MAXV);\n\n        REP(i,n) REP(j,n) {\n       \
    \     c[i ^ j] = (c[i ^ j] + a[i] * b[j]) % MOD;\n        }\n        xorFFT(a,\
    \ n, MOD, 0);\n        xorFFT(b, n, MOD, 0);\n        REP(i,n) a[i] = a[i] * b[i]\
    \ % MOD;\n\n        xorFFT(a, n, MOD, 1);\n        REP(i,n) {\n            assert(a[i]\
    \ == c[i]);\n        }\n\n        cerr << \"XOR OK\" << endl;\n    }\n\n    void\
    \ testAndFFT() {\n        memset(a, 0, sizeof a);\n        memset(b, 0, sizeof\
    \ b);\n        memset(c, 0, sizeof c);\n\n        int n = TWO(11);\n        const\
    \ int MOD = 1e9 + 7;\n        REP(i,n) a[i] = get_rand(MAXV);\n        REP(i,n)\
    \ b[i] = get_rand(MAXV);\n\n        REP(i,n) REP(j,n) {\n            c[i & j]\
    \ = (c[i & j] + a[i] * b[j]) % MOD;\n        }\n        andFFT(a, n, MOD, 0);\n\
    \        andFFT(b, n, MOD, 0);\n        REP(i,n) a[i] = a[i] * b[i] % MOD;\n \
    \       andFFT(a, n, MOD, 1);\n        REP(i,n) {\n            assert(a[i] ==\
    \ c[i]);\n        }\n        cerr << \"AND OK\" << endl;\n    }\n\n    void testOrFFT()\
    \ {\n        memset(a, 0, sizeof a);\n        memset(b, 0, sizeof b);\n      \
    \  memset(c, 0, sizeof c);\n\n        int n = TWO(11);\n        const int MOD\
    \ = 1e9 + 7;\n        REP(i,n) a[i] = get_rand(MAXV);\n        REP(i,n) b[i] =\
    \ get_rand(MAXV);\n\n        REP(i,n) REP(j,n) {\n            c[i | j] = (c[i\
    \ | j] + a[i] * b[j]) % MOD;\n        }\n        orFFT(a, n, MOD, 0);\n      \
    \  orFFT(b, n, MOD, 0);\n        REP(i,n) a[i] = a[i] * b[i] % MOD;\n        orFFT(a,\
    \ n, MOD, 1);\n        REP(i,n) {\n            assert(a[i] == c[i]);\n       \
    \ }\n        cerr << \"OR OK\" << endl;\n    }\n}\n"
  code: "// Tutorial: https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it\n\
    // Walsh\u2013Hadamard transform\n//\n// xor FFT:\n// - Given 2 arrays A and B\
    \ of length N = 2^k.\n// - For each (i, j): C[i ^ j] = C[i ^ j] + A[i] * B[j]\n\
    //\n// Tested:\n// XOR:\n// - https://csacademy.com/contest/archive/task/random_nim_generator/\n\
    //\n// AND:\n// - https://csacademy.com/contest/archive/task/and-closure\n//\n\
    // OR:\n// - https://csacademy.com/contest/archive/task/maxor/\n\n#define REP(i,\
    \ a) for (int i = 0, _##i = (a); i < _##i; ++i)\nlong long power(long long x,\
    \ long long k, long long MOD) {\n    long long res = 1;\n    while (k) {\n   \
    \     if (k & 1) res = res * x % MOD;\n        k >>= 1;\n        x = x * x % MOD;\n\
    \    }\n    return res;\n}\n\n// H = [1 1; 1 -1]\nvoid xorFFT(long long a[], int\
    \ n, int MOD, int invert) {\n    assert(__builtin_popcountll(n) == 1);  // N must\
    \ be power of 2.\n\n    for (int len = 1; len < n; len <<= 1) {\n        for (int\
    \ i = 0; i < n; i += len << 1) {\n            for (int j = 0; j < len; j++) {\n\
    \                long long u = a[i + j];\n                long long v = a[i +\
    \ j + len];\n\n                a[i + j] = u + v;\n                if (a[i + j]\
    \ >= MOD) a[i + j] -= MOD;\n\n                a[i + j + len] = u - v;\n      \
    \          if (a[i + j + len] < 0) a[i + j + len] += MOD;\n            }\n   \
    \     }\n    }\n\n    if (invert) {\n        long long inv = power(n, MOD - 2,\
    \ MOD);\n        REP(i,n) a[i] = a[i] * inv % MOD;\n    }\n}\n\n// H = [0 1; 1\
    \ 1]\nvoid andFFT(long long a[], int n, int MOD, int invert) {\n    assert(__builtin_popcountll(n)\
    \ == 1);  // N must be power of 2.\n\n    for (int len = 1; len < n; len <<= 1)\
    \ {\n        for (int i = 0; i < n; i += len << 1) {\n            for (int j =\
    \ 0; j < len; j++) {\n                long long u = a[i + j];\n              \
    \  long long v = a[i + j + len];\n\n                if (!invert) {\n         \
    \           a[i + j] = v;\n                    a[i + j + len] = u + v;\n     \
    \               if (a[i + j + len] >= MOD) a[i + j + len] -= MOD;\n          \
    \      } else {\n                    a[i + j] = v - u;\n                    if\
    \ (a[i + j] < 0) a[i + j] += MOD;\n                    a[i + j + len] = u;\n \
    \               }\n            }\n        }\n    }\n}\n\n// H = [1 1; 1 0]\nvoid\
    \ orFFT(long long a[], int n, int MOD, int invert) {\n    assert(__builtin_popcountll(n)\
    \ == 1);  // N must be power of 2.\n\n    for (int len = 1; len < n; len <<= 1)\
    \ {\n        for (int i = 0; i < n; i += len << 1) {\n            for (int j =\
    \ 0; j < len; j++) {\n                long long u = a[i + j];\n              \
    \  long long v = a[i + j + len];\n\n                if (!invert) {\n         \
    \           a[i + j] = u + v;\n                    if (a[i + j] >= MOD) a[i +\
    \ j] -= MOD;\n\n                    a[i + j + len] = u;\n                } else\
    \ {\n                    a[i + j] = v;\n                    a[i + j + len] = u\
    \ - v;\n                    if (a[i + j + len] < 0) a[i + j + len] += MOD;\n \
    \               }\n            }\n        }\n    }\n}\n\nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    int get_rand(int r) {\n    return uniform_int_distribution<int> (0, r-1)(rng);\n\
    }\n\nnamespace Test {\n#define TWO(X) (1LL << (X))\n    const int MAXN = 1e5 +\
    \ 5;\n    const int MAXV = 100;\n    long long a[MAXN], b[MAXN], c[MAXN];\n  \
    \  void testXorFFT() {\n        memset(a, 0, sizeof a);\n        memset(b, 0,\
    \ sizeof b);\n        memset(c, 0, sizeof c);\n\n        int n = TWO(11);\n  \
    \      const int MOD = 1e9 + 7;\n        REP(i,n) a[i] = get_rand(MAXV);\n   \
    \     REP(i,n) b[i] = get_rand(MAXV);\n\n        REP(i,n) REP(j,n) {\n       \
    \     c[i ^ j] = (c[i ^ j] + a[i] * b[j]) % MOD;\n        }\n        xorFFT(a,\
    \ n, MOD, 0);\n        xorFFT(b, n, MOD, 0);\n        REP(i,n) a[i] = a[i] * b[i]\
    \ % MOD;\n\n        xorFFT(a, n, MOD, 1);\n        REP(i,n) {\n            assert(a[i]\
    \ == c[i]);\n        }\n\n        cerr << \"XOR OK\" << endl;\n    }\n\n    void\
    \ testAndFFT() {\n        memset(a, 0, sizeof a);\n        memset(b, 0, sizeof\
    \ b);\n        memset(c, 0, sizeof c);\n\n        int n = TWO(11);\n        const\
    \ int MOD = 1e9 + 7;\n        REP(i,n) a[i] = get_rand(MAXV);\n        REP(i,n)\
    \ b[i] = get_rand(MAXV);\n\n        REP(i,n) REP(j,n) {\n            c[i & j]\
    \ = (c[i & j] + a[i] * b[j]) % MOD;\n        }\n        andFFT(a, n, MOD, 0);\n\
    \        andFFT(b, n, MOD, 0);\n        REP(i,n) a[i] = a[i] * b[i] % MOD;\n \
    \       andFFT(a, n, MOD, 1);\n        REP(i,n) {\n            assert(a[i] ==\
    \ c[i]);\n        }\n        cerr << \"AND OK\" << endl;\n    }\n\n    void testOrFFT()\
    \ {\n        memset(a, 0, sizeof a);\n        memset(b, 0, sizeof b);\n      \
    \  memset(c, 0, sizeof c);\n\n        int n = TWO(11);\n        const int MOD\
    \ = 1e9 + 7;\n        REP(i,n) a[i] = get_rand(MAXV);\n        REP(i,n) b[i] =\
    \ get_rand(MAXV);\n\n        REP(i,n) REP(j,n) {\n            c[i | j] = (c[i\
    \ | j] + a[i] * b[j]) % MOD;\n        }\n        orFFT(a, n, MOD, 0);\n      \
    \  orFFT(b, n, MOD, 0);\n        REP(i,n) a[i] = a[i] * b[i] % MOD;\n        orFFT(a,\
    \ n, MOD, 1);\n        REP(i,n) {\n            assert(a[i] == c[i]);\n       \
    \ }\n        cerr << \"OR OK\" << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Polynomial/xorFFT.h
  requiredBy: []
  timestamp: '2022-01-06 05:27:57+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/convolution_xor.test.cpp
  - Math/tests/convolution_and.test.cpp
documentation_of: Math/Polynomial/xorFFT.h
layout: document
redirect_from:
- /library/Math/Polynomial/xorFFT.h
- /library/Math/Polynomial/xorFFT.h.html
title: Math/Polynomial/xorFFT.h
---
