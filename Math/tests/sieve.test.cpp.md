---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/Prime/Sieve.h
    title: Math/Prime/Sieve.h
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
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Math/Prime/Sieve.h\"\
    \n// F is called for each prime\n// Sieve (odd only + segmented) {{{\ntemplate<typename\
    \ F>\nvoid sieve(int MAX, F func) {\n\n    const int S = sqrt(MAX + 0.5);\n  \
    \  vector<char> sieve(S + 1, true);\n    vector<array<int, 2>> cp;\n    for (int\
    \ i = 3; i <= S; i += 2) {\n        if (!sieve[i])\n            continue;\n  \
    \      cp.push_back({i, (i * i - 1) / 2});\n        for (int j = i * i; j <= S;\
    \ j += 2 * i)\n            sieve[j] = false;\n    }\n    func(2);\n    vector<char>\
    \ block(S);\n    int high = (MAX - 1) / 2;\n    for (int low = 0; low <= high;\
    \ low += S) {\n        fill(block.begin(), block.end(), true);\n        for (auto\
    \ &i : cp) {\n            int p = i[0], idx = i[1];\n            for (; idx <\
    \ S; idx += p)\n                block[idx] = false;\n            i[1] = idx -\
    \ S;\n        }\n        if (low == 0)\n            block[0] = false;\n      \
    \  for (int i = 0; i < S && low + i <= high; i++)\n            if (block[i]) {\n\
    \                func((low + i) * 2 + 1);\n            }\n    };\n}\n// }}}\n\
    #line 7 \"Math/tests/sieve.test.cpp\"\n\nint n, a, b, cnt = 0, cnt_mod = 0;\n\
    vector<int> ps;\nvoid newPrime(int p) {\n    if (p > n) {\n        cout << cnt\
    \ << ' ' << ps.size() << '\\n';\n        for (int x : ps) cout << x << ' ';\n\
    \        exit(0);\n    }\n    if (cnt_mod == b) ps.push_back(p);\n    ++cnt;\n\
    \    ++cnt_mod;\n    if (cnt_mod == a) cnt_mod = 0;\n}\n\nint32_t main() {\n \
    \   cin >> n >> a >> b;\n    sieve(1'000'000'000, newPrime);\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Prime/Sieve.h\"\
    \n\nint n, a, b, cnt = 0, cnt_mod = 0;\nvector<int> ps;\nvoid newPrime(int p)\
    \ {\n    if (p > n) {\n        cout << cnt << ' ' << ps.size() << '\\n';\n   \
    \     for (int x : ps) cout << x << ' ';\n        exit(0);\n    }\n    if (cnt_mod\
    \ == b) ps.push_back(p);\n    ++cnt;\n    ++cnt_mod;\n    if (cnt_mod == a) cnt_mod\
    \ = 0;\n}\n\nint32_t main() {\n    cin >> n >> a >> b;\n    sieve(1'000'000'000,\
    \ newPrime);\n    return 0;\n}\n"
  dependsOn:
  - Math/Prime/Sieve.h
  isVerificationFile: true
  path: Math/tests/sieve.test.cpp
  requiredBy: []
  timestamp: '2022-12-14 02:22:04+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/sieve.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/sieve.test.cpp
- /verify/Math/tests/sieve.test.cpp.html
title: Math/tests/sieve.test.cpp
---
