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
  bundledCode: "#line 1 \"Misc/bitmask_utils.h\"\n// bitmask utils {{{\ninline uint64_t\
    \ two(int b) {\n    return 1ULL << b;\n}\ninline uint64_t flip_bit(uint64_t mask,\
    \ int b) {\n    return mask ^ two(b);\n}\ninline int get_bit(uint64_t mask, int\
    \ b) {\n    return (mask >> b) & 1ULL;\n}\ninline uint64_t set_bit(uint64_t mask,\
    \ int b, int new_val) {\n    return mask + (new_val - get_bit(mask, b)) * two(b);\n\
    }\ninline int popcount(uint64_t mask) {\n    return __builtin_popcountll(mask);\n\
    }\ninline int ctz(uint64_t mask) {\n    return __builtin_ctzll(mask);\n}\ntemplate<typename\
    \ F>\ninline void for_each_submask(uint64_t mask, F f) {\n    for (uint64_t submask\
    \ = mask; submask > 0; submask = (submask - 1) & mask) {\n        f(submask);\n\
    \    }\n}\n// }}}\n"
  code: "// bitmask utils {{{\ninline uint64_t two(int b) {\n    return 1ULL << b;\n\
    }\ninline uint64_t flip_bit(uint64_t mask, int b) {\n    return mask ^ two(b);\n\
    }\ninline int get_bit(uint64_t mask, int b) {\n    return (mask >> b) & 1ULL;\n\
    }\ninline uint64_t set_bit(uint64_t mask, int b, int new_val) {\n    return mask\
    \ + (new_val - get_bit(mask, b)) * two(b);\n}\ninline int popcount(uint64_t mask)\
    \ {\n    return __builtin_popcountll(mask);\n}\ninline int ctz(uint64_t mask)\
    \ {\n    return __builtin_ctzll(mask);\n}\ntemplate<typename F>\ninline void for_each_submask(uint64_t\
    \ mask, F f) {\n    for (uint64_t submask = mask; submask > 0; submask = (submask\
    \ - 1) & mask) {\n        f(submask);\n    }\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/bitmask_utils.h
  requiredBy: []
  timestamp: '2023-01-04 02:50:55+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/bitmask_utils.h
layout: document
redirect_from:
- /library/Misc/bitmask_utils.h
- /library/Misc/bitmask_utils.h.html
title: Misc/bitmask_utils.h
---
