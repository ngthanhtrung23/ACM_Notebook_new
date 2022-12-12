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
  bundledCode: "#line 1 \"Misc/bitmask_utils.h\"\ninline uint64_t two(int b) {\n \
    \   return 1ULL << b;\n}\ninline uint64_t flip_bit(uint64_t mask, int b) {\n \
    \   return mask ^ two(b);\n}\ninline int get_bit(uint64_t mask, int b) {\n   \
    \ return (mask >> b) & 1ULL;\n}\ninline uint64_t set_bit(uint64_t mask, int b,\
    \ int new_val) {\n    return mask + (new_val - get_bit(mask, b)) * two(b);\n}\n"
  code: "inline uint64_t two(int b) {\n    return 1ULL << b;\n}\ninline uint64_t flip_bit(uint64_t\
    \ mask, int b) {\n    return mask ^ two(b);\n}\ninline int get_bit(uint64_t mask,\
    \ int b) {\n    return (mask >> b) & 1ULL;\n}\ninline uint64_t set_bit(uint64_t\
    \ mask, int b, int new_val) {\n    return mask + (new_val - get_bit(mask, b))\
    \ * two(b);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/bitmask_utils.h
  requiredBy: []
  timestamp: '2022-12-12 13:43:59+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/bitmask_utils.h
layout: document
redirect_from:
- /library/Misc/bitmask_utils.h
- /library/Misc/bitmask_utils.h.html
title: Misc/bitmask_utils.h
---
