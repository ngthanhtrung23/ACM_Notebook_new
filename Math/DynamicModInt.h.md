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
  bundledCode: "#line 1 \"Math/DynamicModInt.h\"\n// Useful when mod changes between\
    \ test cases (we can't use ModInt \n// since mod is templated)\n//\n// DynamicModInt\
    \ {{{\nstruct DynamicModInt {\n    static i64 MOD;\n    i64 x;\n\n    DynamicModInt(i64\
    \ v = 0) {\n        if (MOD == 0) x = v;\n        else {\n            v %= MOD;\n\
    \            if (v < 0) v += MOD;\n            x = v;\n        }\n    }\n\n  \
    \  DynamicModInt& operator += (const DynamicModInt& other) {\n        x += other.x;\n\
    \        if (x >= MOD) x -= MOD;\n        return *this;\n    }\n\n    DynamicModInt&\
    \ operator *= (const DynamicModInt& other) {\n        x = (i128)x * other.x %\
    \ MOD;\n        return *this;\n    }\n\n    friend DynamicModInt operator + (DynamicModInt\
    \ a, const DynamicModInt& b) { return a += b; }\n    friend DynamicModInt operator\
    \ * (DynamicModInt a, const DynamicModInt& b) { return a *= b; }\n\n    bool operator\
    \ != (const DynamicModInt& other) const {\n        return x != other.x;\n    }\n\
    };\n// }}}\n"
  code: "// Useful when mod changes between test cases (we can't use ModInt \n// since\
    \ mod is templated)\n//\n// DynamicModInt {{{\nstruct DynamicModInt {\n    static\
    \ i64 MOD;\n    i64 x;\n\n    DynamicModInt(i64 v = 0) {\n        if (MOD == 0)\
    \ x = v;\n        else {\n            v %= MOD;\n            if (v < 0) v += MOD;\n\
    \            x = v;\n        }\n    }\n\n    DynamicModInt& operator += (const\
    \ DynamicModInt& other) {\n        x += other.x;\n        if (x >= MOD) x -= MOD;\n\
    \        return *this;\n    }\n\n    DynamicModInt& operator *= (const DynamicModInt&\
    \ other) {\n        x = (i128)x * other.x % MOD;\n        return *this;\n    }\n\
    \n    friend DynamicModInt operator + (DynamicModInt a, const DynamicModInt& b)\
    \ { return a += b; }\n    friend DynamicModInt operator * (DynamicModInt a, const\
    \ DynamicModInt& b) { return a *= b; }\n\n    bool operator != (const DynamicModInt&\
    \ other) const {\n        return x != other.x;\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/DynamicModInt.h
  requiredBy: []
  timestamp: '2026-06-13 21:55:08+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/DynamicModInt.h
layout: document
redirect_from:
- /library/Math/DynamicModInt.h
- /library/Math/DynamicModInt.h.html
title: Math/DynamicModInt.h
---
