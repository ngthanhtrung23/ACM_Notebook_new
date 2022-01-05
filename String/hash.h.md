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
  bundledCode: "#line 1 \"String/hash.h\"\nstruct Hash {\n    ll x, y;\n    Hash(ll\
    \ x = 0, ll y = 0) : x(x), y(y) {}\n\n    Hash operator + (const Hash& a) const\
    \ { return Hash((x+a.x) % MOD, y+a.y); }\n    Hash operator - (const Hash& a)\
    \ const { return Hash((x-a.x+MOD) % MOD, y-a.y); }\n    Hash operator * (const\
    \ Hash& a) const { return Hash((x*a.x) % MOD, y*a.y); }\n    Hash operator * (ll\
    \ k) { return Hash((x*k) % MOD, y*k); }\n\n    friend ostream& operator << (ostream&\
    \ cout, const Hash& h) {\n        cout << h.x << ' ' << h.y;\n        return cout;\n\
    \    }\n};\nbool operator == (const Hash& a, const Hash& b) {\n    return a.x\
    \ == b.x && a.y == b.y;\n}\nbool operator < (const Hash& a, const Hash& b) {\n\
    \    if (a.x != b.x) return a.x < b.x;\n    return a.y < b.y;\n}\n"
  code: "struct Hash {\n    ll x, y;\n    Hash(ll x = 0, ll y = 0) : x(x), y(y) {}\n\
    \n    Hash operator + (const Hash& a) const { return Hash((x+a.x) % MOD, y+a.y);\
    \ }\n    Hash operator - (const Hash& a) const { return Hash((x-a.x+MOD) % MOD,\
    \ y-a.y); }\n    Hash operator * (const Hash& a) const { return Hash((x*a.x) %\
    \ MOD, y*a.y); }\n    Hash operator * (ll k) { return Hash((x*k) % MOD, y*k);\
    \ }\n\n    friend ostream& operator << (ostream& cout, const Hash& h) {\n    \
    \    cout << h.x << ' ' << h.y;\n        return cout;\n    }\n};\nbool operator\
    \ == (const Hash& a, const Hash& b) {\n    return a.x == b.x && a.y == b.y;\n\
    }\nbool operator < (const Hash& a, const Hash& b) {\n    if (a.x != b.x) return\
    \ a.x < b.x;\n    return a.y < b.y;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/hash.h
  requiredBy: []
  timestamp: '2016-04-15 22:48:44+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/hash.h
layout: document
redirect_from:
- /library/String/hash.h
- /library/String/hash.h.html
title: String/hash.h
---
