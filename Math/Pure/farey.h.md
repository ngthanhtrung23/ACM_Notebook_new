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
  bundledCode: "#line 1 \"Math/Pure/farey.h\"\n// Farey sequence (denominator <= N)\
    \ enumeration:\n// Properties\n// 1. Two fractions: 0 <= a/b < c/d <= 1 are neighbors\
    \ in some Farey sequence iff b*c - a*d == 1\n// 2. If b*c - a*d == 1, the (unique)\
    \ fraction between a/b and c/d with smallest denominator is (a+c) / (b+d)\n//\
    \ 3. If a/b < c/d < e/f are 3 consecutives fraction in some Farey sequence, then\
    \ c/d = (a+e) / (b+f)\n\nint N = 12000;\npair<int,int> next(int a, int b, int\
    \ c, int d) {\n    int k = (N + b) / d;\n    return make_pair(k*c - a, k*d - b);\n\
    }\n// To find c/d using only a/b:\n// Using extended euclid, we can find c0, d0\
    \ such that b*c0 - a*d0 == 1\n// c = c0 + (N - d0)/b * a\n// d = d0 + (N - d0)/b\
    \ * b\n\n// To count number of fractions in range (x, y):\n// F(N) = count(k/n\
    \ : x < k/n < y and n <= N)\n// R(N) = count(k/n : x < k/n < y and n <= N and\
    \ gcd(k,n) == 1)\n// F(N) can be easily calculated in O(N)\n// F(N) = sum( R(N\
    \ div m) for m = 1..N )\n// Thus R(N) can be calculated using generalized inversed\
    \ Moebius formula\n"
  code: "// Farey sequence (denominator <= N) enumeration:\n// Properties\n// 1. Two\
    \ fractions: 0 <= a/b < c/d <= 1 are neighbors in some Farey sequence iff b*c\
    \ - a*d == 1\n// 2. If b*c - a*d == 1, the (unique) fraction between a/b and c/d\
    \ with smallest denominator is (a+c) / (b+d)\n// 3. If a/b < c/d < e/f are 3 consecutives\
    \ fraction in some Farey sequence, then c/d = (a+e) / (b+f)\n\nint N = 12000;\n\
    pair<int,int> next(int a, int b, int c, int d) {\n    int k = (N + b) / d;\n \
    \   return make_pair(k*c - a, k*d - b);\n}\n// To find c/d using only a/b:\n//\
    \ Using extended euclid, we can find c0, d0 such that b*c0 - a*d0 == 1\n// c =\
    \ c0 + (N - d0)/b * a\n// d = d0 + (N - d0)/b * b\n\n// To count number of fractions\
    \ in range (x, y):\n// F(N) = count(k/n : x < k/n < y and n <= N)\n// R(N) = count(k/n\
    \ : x < k/n < y and n <= N and gcd(k,n) == 1)\n// F(N) can be easily calculated\
    \ in O(N)\n// F(N) = sum( R(N div m) for m = 1..N )\n// Thus R(N) can be calculated\
    \ using generalized inversed Moebius formula\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Pure/farey.h
  requiredBy: []
  timestamp: '2015-02-02 18:15:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Pure/farey.h
layout: document
redirect_from:
- /library/Math/Pure/farey.h
- /library/Math/Pure/farey.h.html
title: Math/Pure/farey.h
---
