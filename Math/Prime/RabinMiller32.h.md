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
    - https://www.spoj.com/problems/PRIC/
  bundledCode: "#line 1 \"Math/Prime/RabinMiller32.h\"\n// Tested:\n// - https://www.spoj.com/problems/PRIC/\n\
    \n#include <cstdint>\ninline unsigned mod_mult(unsigned a, unsigned b, unsigned\
    \ m) {\n  return (uint64_t)a*b%m;\n}\n \nunsigned mod_pow(unsigned a, uint64_t\
    \ b, unsigned m) {\n  unsigned ret = 1;\n  for(;;) {\n    if (b&1) ret = mod_mult(ret,\
    \ a, m);\n    if (!(b>>=1)) return ret;\n    a = mod_mult(a, a, m);\n  }\n}\n\
    \ \nbool is_prime(unsigned n) {\n  if (n <= 3) return (n >= 2);\n  static const\
    \ unsigned small[] = {\n        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,\
    \ 43, 47, 53, 59, 61, 67,\n        71, 73, 79, 83, 89, 97, 101, 103, 107, 109,\
    \ 113, 127, 131, 137, 139,\n  };\n  for (int i = 0; i < sizeof(small)/sizeof(unsigned);\
    \ i++) {\n    if (n%small[i] == 0) return n == small[i];\n  }\n \n  // Jaeschke93\
    \ showed that 2,7,61 suffice for n < 4,759,123,141.\n  static const unsigned millerrabin[]\
    \ = {2, 7, 61};\n  unsigned s = n-1, r = 0;\n  while (s%2 == 0) {s /= 2; r++;}\n\
    \ \n  for (int i = 0, j; i < sizeof(millerrabin)/sizeof(unsigned); i++) {\n  \
    \  unsigned md = mod_pow(test[i], s, n);\n    if (md == 1) continue;\n    for\
    \ (j = 1; j < r; j++) {\n      if (md == n-1) break;\n      md = mod_mult(md,\
    \ md, n);\n    }\n    if (md != n-1) return false;\n  }\n \n  return true;\n}\n"
  code: "// Tested:\n// - https://www.spoj.com/problems/PRIC/\n\n#include <cstdint>\n\
    inline unsigned mod_mult(unsigned a, unsigned b, unsigned m) {\n  return (uint64_t)a*b%m;\n\
    }\n \nunsigned mod_pow(unsigned a, uint64_t b, unsigned m) {\n  unsigned ret =\
    \ 1;\n  for(;;) {\n    if (b&1) ret = mod_mult(ret, a, m);\n    if (!(b>>=1))\
    \ return ret;\n    a = mod_mult(a, a, m);\n  }\n}\n \nbool is_prime(unsigned n)\
    \ {\n  if (n <= 3) return (n >= 2);\n  static const unsigned small[] = {\n   \
    \     2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,\n\
    \        71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,\n\
    \  };\n  for (int i = 0; i < sizeof(small)/sizeof(unsigned); i++) {\n    if (n%small[i]\
    \ == 0) return n == small[i];\n  }\n \n  // Jaeschke93 showed that 2,7,61 suffice\
    \ for n < 4,759,123,141.\n  static const unsigned millerrabin[] = {2, 7, 61};\n\
    \  unsigned s = n-1, r = 0;\n  while (s%2 == 0) {s /= 2; r++;}\n \n  for (int\
    \ i = 0, j; i < sizeof(millerrabin)/sizeof(unsigned); i++) {\n    unsigned md\
    \ = mod_pow(test[i], s, n);\n    if (md == 1) continue;\n    for (j = 1; j < r;\
    \ j++) {\n      if (md == n-1) break;\n      md = mod_mult(md, md, n);\n    }\n\
    \    if (md != n-1) return false;\n  }\n \n  return true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Prime/RabinMiller32.h
  requiredBy: []
  timestamp: '2022-11-18 18:23:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Prime/RabinMiller32.h
layout: document
redirect_from:
- /library/Math/Prime/RabinMiller32.h
- /library/Math/Prime/RabinMiller32.h.html
title: Math/Prime/RabinMiller32.h
---
