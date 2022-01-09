---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Prime/IterativeSieve.h
    title: Math/Prime/IterativeSieve.h
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
  bundledCode: "#line 1 \"Math/tests/sieve.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Math/Prime/IterativeSieve.h\"\
    \n// Tested:\n// - (up to 5e8) https://judge.yosupo.jp/problem/enumerate_primes\n\
    typedef unsigned int uint;\n\n// NOTE: gP(n) is incorrect for even values of n\n\
    const uint N = 5e8 + 11;\nuint mark[N / 64 + 1];\n// DO NOT USE gP(n) directly.\n\
    #define gP(n) (mark[(n)>>6]&(1<<(((n)>>1)&31)))\n#define rP(n) (mark[(n)>>6]&=~(1<<(((n)>>1)&31)))\n\
    \n// prime indexed from 0\nuint prime[30111000], nprime;\n\nvoid sieve() {\n \
    \   memset(mark, -1, sizeof mark);\n    uint i;\n    uint sqrtN = (uint)sqrt((double)\
    \ N) + 1;\n\n    for (i = 3; i < sqrtN; i += 2) if (gP(i)) {\n        uint i2\
    \ = i + i;\n        for (uint j = i * i; j < N; j += i2) rP(j);\n    }\n    nprime\
    \ = 0;\n    prime[nprime++] = 2;\n    for (i = 3; i < N; i += 2)\n        if (gP(i))\
    \ prime[nprime++] = i;\n}\n\nbool isPrime(uint n) {\n    if (n <= 1) return false;\n\
    \    if (n == 2) return true;\n    if (n % 2 == 0) return false;\n\n    if (gP(n))\
    \ return true;\n    return false;\n}\n#line 7 \"Math/tests/sieve.test.cpp\"\n\n\
    int32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, a, b; cin\
    \ >> n >> a >> b;\n    sieve();\n\n    int cnt1 = 0;\n    for (int i = 0; i <\
    \ nprime; i++) {\n        if (prime[i] > n) break;\n        ++cnt1;\n    }\n\n\
    \    int cnt2 = 0;\n    for (int i = 0; ; i++) {\n        int id = a*i + b;\n\
    \        if (id >= nprime || prime[id] > n) break;\n\n        ++cnt2;\n    }\n\
    \    cout << cnt1 << ' ' << cnt2 << '\\n';\n\n    for (int i = 0; ; i++) {\n \
    \       int id = a*i + b;\n        if (id >= nprime || prime[id] > n) break;\n\
    \n        cout << prime[id] << ' ';\n    }\n    cout << endl;\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Prime/IterativeSieve.h\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, a,\
    \ b; cin >> n >> a >> b;\n    sieve();\n\n    int cnt1 = 0;\n    for (int i =\
    \ 0; i < nprime; i++) {\n        if (prime[i] > n) break;\n        ++cnt1;\n \
    \   }\n\n    int cnt2 = 0;\n    for (int i = 0; ; i++) {\n        int id = a*i\
    \ + b;\n        if (id >= nprime || prime[id] > n) break;\n\n        ++cnt2;\n\
    \    }\n    cout << cnt1 << ' ' << cnt2 << '\\n';\n\n    for (int i = 0; ; i++)\
    \ {\n        int id = a*i + b;\n        if (id >= nprime || prime[id] > n) break;\n\
    \n        cout << prime[id] << ' ';\n    }\n    cout << endl;\n    return 0;\n\
    }\n"
  dependsOn:
  - Math/Prime/IterativeSieve.h
  isVerificationFile: true
  path: Math/tests/sieve.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 00:30:04+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/sieve.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/sieve.test.cpp
- /verify/Math/tests/sieve.test.cpp.html
title: Math/tests/sieve.test.cpp
---
