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
    - https://open.kattis.com/problems/knightstrip
  bundledCode: "#line 1 \"Misc/KnightMove.h\"\n// Knight\u2019s shortest path (from\
    \ (0, 0))\n// Tested:\n// - https://open.kattis.com/problems/knightstrip\nint\
    \ KSP(int x, int y) {\n    if (x < 0) x = -x;\n    if (y < 0) y = -y;\n    if\
    \ (x < y) swap(x, y);\n    if (x == 1 && y == 0) return 3;\n    if (x == 2 &&\
    \ y == 2) return 4;\n    int d = x - y;\n    if (y > d) return 2 * ((y - d + 2)\
    \ / 3) + d;\n    return d - 2 * ((d - y) / 4);\n} \n"
  code: "// Knight\u2019s shortest path (from (0, 0))\n// Tested:\n// - https://open.kattis.com/problems/knightstrip\n\
    int KSP(int x, int y) {\n    if (x < 0) x = -x;\n    if (y < 0) y = -y;\n    if\
    \ (x < y) swap(x, y);\n    if (x == 1 && y == 0) return 3;\n    if (x == 2 &&\
    \ y == 2) return 4;\n    int d = x - y;\n    if (y > d) return 2 * ((y - d + 2)\
    \ / 3) + d;\n    return d - 2 * ((d - y) / 4);\n} \n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/KnightMove.h
  requiredBy: []
  timestamp: '2015-09-09 01:11:48+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/KnightMove.h
layout: document
redirect_from:
- /library/Misc/KnightMove.h
- /library/Misc/KnightMove.h.html
title: Misc/KnightMove.h
---
