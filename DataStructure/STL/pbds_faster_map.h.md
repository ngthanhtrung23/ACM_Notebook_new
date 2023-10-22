---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/60737
    - https://codeforces.com/contest/1006/submission/41804666
    - https://ideone.com/LhpILA
  bundledCode: "#line 1 \"DataStructure/STL/pbds_faster_map.h\"\n// From https://codeforces.com/blog/entry/60737\n\
    \n// Note: it's probably useful to test if these tricks make unordered_map fast\
    \ enough first:\n// unordered_map<...> mp;\n// mp.reserve(N);   // maybe use 2^x?\n\
    // mp.max_load_factor(0.25);\n\n// Code copied from https://codeforces.com/contest/1006/submission/41804666\n\
    #include <ext/pb_ds/assoc_container.hpp>\nusing namespace __gnu_pbds;\n\nunsigned\
    \ hash_f(unsigned x) {\n    x = ((x >> 16) ^ x) * 0x45d9f3b;\n    x = ((x >> 16)\
    \ ^ x) * 0x45d9f3b;\n    x = (x >> 16) ^ x;\n    return x;\n}\nstruct chash {\n\
    \    int operator()(int x) const { return hash_f(x); }\n};\n\ngp_hash_table<int,\
    \ int, chash> mp;\n\n\n// alternative hash function:\n// Code copied from https://ideone.com/LhpILA\n\
    const ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    const ll SEED = (ll)(new ll);\nconst ll RANDOM = TIME ^ SEED;\nconst ll MOD =\
    \ (int)1e9+7;\nconst ll MUL = (int)1e6+3;\n\nstruct chash{\n    ll operator()(ll\
    \ x) const { return std::hash<ll>{}((x ^ RANDOM) % MOD * MUL); }\n};\n"
  code: "// From https://codeforces.com/blog/entry/60737\n\n// Note: it's probably\
    \ useful to test if these tricks make unordered_map fast enough first:\n// unordered_map<...>\
    \ mp;\n// mp.reserve(N);   // maybe use 2^x?\n// mp.max_load_factor(0.25);\n\n\
    // Code copied from https://codeforces.com/contest/1006/submission/41804666\n\
    #include <ext/pb_ds/assoc_container.hpp>\nusing namespace __gnu_pbds;\n\nunsigned\
    \ hash_f(unsigned x) {\n    x = ((x >> 16) ^ x) * 0x45d9f3b;\n    x = ((x >> 16)\
    \ ^ x) * 0x45d9f3b;\n    x = (x >> 16) ^ x;\n    return x;\n}\nstruct chash {\n\
    \    int operator()(int x) const { return hash_f(x); }\n};\n\ngp_hash_table<int,\
    \ int, chash> mp;\n\n\n// alternative hash function:\n// Code copied from https://ideone.com/LhpILA\n\
    const ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();\n\
    const ll SEED = (ll)(new ll);\nconst ll RANDOM = TIME ^ SEED;\nconst ll MOD =\
    \ (int)1e9+7;\nconst ll MUL = (int)1e6+3;\n\nstruct chash{\n    ll operator()(ll\
    \ x) const { return std::hash<ll>{}((x ^ RANDOM) % MOD * MUL); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/STL/pbds_faster_map.h
  requiredBy: []
  timestamp: '2023-10-22 16:42:38+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/STL/pbds_faster_map.h
layout: document
redirect_from:
- /library/DataStructure/STL/pbds_faster_map.h
- /library/DataStructure/STL/pbds_faster_map.h.html
title: DataStructure/STL/pbds_faster_map.h
---
