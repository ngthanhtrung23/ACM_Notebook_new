---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/NumberTheory/cnt_divisors.h
    title: Math/NumberTheory/cnt_divisors.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/cnt_divisors_stress.test.cpp
    title: Math/tests/cnt_divisors_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/sieve.test.cpp
    title: Math/tests/sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Prime/Sieve.h\"\n// F is called for each prime\n//\
    \ Sieve (odd only + segmented) {{{\ntemplate<typename F>\nvoid sieve(int MAX,\
    \ F func) {\n\n    const int S = sqrt(MAX + 0.5);\n    vector<char> sieve(S +\
    \ 1, true);\n    vector<array<int, 2>> cp;\n    for (int i = 3; i <= S; i += 2)\
    \ {\n        if (!sieve[i])\n            continue;\n        cp.push_back({i, (i\
    \ * i - 1) / 2});\n        for (int j = i * i; j <= S; j += 2 * i)\n         \
    \   sieve[j] = false;\n    }\n    func(2);\n    vector<char> block(S);\n    int\
    \ high = (MAX - 1) / 2;\n    for (int low = 0; low <= high; low += S) {\n    \
    \    fill(block.begin(), block.end(), true);\n        for (auto &i : cp) {\n \
    \           int p = i[0], idx = i[1];\n            for (; idx < S; idx += p)\n\
    \                block[idx] = false;\n            i[1] = idx - S;\n        }\n\
    \        if (low == 0)\n            block[0] = false;\n        for (int i = 0;\
    \ i < S && low + i <= high; i++)\n            if (block[i]) {\n              \
    \  func((low + i) * 2 + 1);\n            }\n    };\n}\n// }}}\n"
  code: "// F is called for each prime\n// Sieve (odd only + segmented) {{{\ntemplate<typename\
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
    \                func((low + i) * 2 + 1);\n            }\n    };\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Prime/Sieve.h
  requiredBy:
  - Math/NumberTheory/cnt_divisors.h
  timestamp: '2022-12-14 02:22:04+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/cnt_divisors_stress.test.cpp
  - Math/tests/sieve.test.cpp
documentation_of: Math/Prime/Sieve.h
layout: document
redirect_from:
- /library/Math/Prime/Sieve.h
- /library/Math/Prime/Sieve.h.html
title: Math/Prime/Sieve.h
---
