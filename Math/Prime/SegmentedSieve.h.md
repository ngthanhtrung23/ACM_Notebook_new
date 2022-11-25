---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Prime/SegmentedSieve.h\"\n// table[i-L] == true <=>\
    \ i == prime\nconst int SQRTN = 1<<16; // upperbound of sqrt(H) + 10\n\n// [L,\
    \ H)\nvector<bool> segmentSieve(ll L, ll H) {\n    static ll p[SQRTN];\n    static\
    \ int lookup = 0;\n    if (!lookup) {\n        for (ll i = 2; i < SQRTN; ++i)\
    \ p[i] = i;\n        for (ll i = 2; i*i < SQRTN; ++i)\n            if (p[i])\n\
    \                for (ll j = i*i; j < SQRTN; j += i)\n                    p[j]\
    \ = 0;\n        remove(p, p+SQRTN, 0);\n        lookup = 1;\n    }\n    vector<bool>\
    \ table(H - L);\n    for (ll i = L; i < H; ++i) table[i - L] = 1;\n    for (ll\
    \ i = 0, j; p[i] * p[i] < H; ++i) { // O( \\sqrt(H) )\n        if (p[i] >= L)\
    \ j = p[i] * p[i];\n        else if (L % p[i] == 0) j = L;\n        else j = L\
    \ - (L % p[i]) + p[i];\n        for (; j < H; j += p[i]) table[j-L] = 0;\n   \
    \ }\n    return table;\n}\n"
  code: "// table[i-L] == true <=> i == prime\nconst int SQRTN = 1<<16; // upperbound\
    \ of sqrt(H) + 10\n\n// [L, H)\nvector<bool> segmentSieve(ll L, ll H) {\n    static\
    \ ll p[SQRTN];\n    static int lookup = 0;\n    if (!lookup) {\n        for (ll\
    \ i = 2; i < SQRTN; ++i) p[i] = i;\n        for (ll i = 2; i*i < SQRTN; ++i)\n\
    \            if (p[i])\n                for (ll j = i*i; j < SQRTN; j += i)\n\
    \                    p[j] = 0;\n        remove(p, p+SQRTN, 0);\n        lookup\
    \ = 1;\n    }\n    vector<bool> table(H - L);\n    for (ll i = L; i < H; ++i)\
    \ table[i - L] = 1;\n    for (ll i = 0, j; p[i] * p[i] < H; ++i) { // O( \\sqrt(H)\
    \ )\n        if (p[i] >= L) j = p[i] * p[i];\n        else if (L % p[i] == 0)\
    \ j = L;\n        else j = L - (L % p[i]) + p[i];\n        for (; j < H; j +=\
    \ p[i]) table[j-L] = 0;\n    }\n    return table;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Prime/SegmentedSieve.h
  requiredBy: []
  timestamp: '2022-11-25 16:33:51+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Prime/SegmentedSieve.h
layout: document
redirect_from:
- /library/Math/Prime/SegmentedSieve.h
- /library/Math/Prime/SegmentedSieve.h.html
title: Math/Prime/SegmentedSieve.h
---
