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
  bundledCode: "#line 1 \"Graph/Matching/StableMarriage.h\"\n/* Numbered from 0\n\
    \ * For man i, L[i] = list of women in order of decreasing preference\n * For\
    \ women j, R[j][i] = index of man i in j-th women's list of preference\n * OUTPUTS:\n\
    \ *      - L2R[]:    the mate of man i (always between 0 and n-1)\n *      - R2L[]:\
    \    the mate of woman j (or -1 if single)\n * COMPLEXITY: M^2\n */\n\n#define\
    \ MAXM 1024\n#define MAXW 1024\nint m;\nint L[MAXM][MAXW], R[MAXW][MAXM];\nint\
    \ L2R[MAXM], R2L[MAXW];\nint p[MAXM];\nvoid stableMarriage(){\n    static int\
    \ p[128];\n    memset(R2L, -1, sizeof R2L);\n    memset(p, 0, sizeof p);\n   \
    \ // Each man proposes...\n    for(int i = 0; i < m; i++) {\n        int man =\
    \ i;\n        while (man >= 0) { // propose until success\n            int wom;\n\
    \            while (1) {\n                wom = L[man][p[man]++];\n          \
    \      if (R2L[wom] < 0 || R[wom][man] > R[wom][R2L[wom]]) break;\n          \
    \  }\n            int hubby = R2L[wom];\n            R2L[L2R[man] = wom] = man;\n\
    \            man = hubby; // remarry the dumped guy\n        }\n    }\n}\n"
  code: "/* Numbered from 0\n * For man i, L[i] = list of women in order of decreasing\
    \ preference\n * For women j, R[j][i] = index of man i in j-th women's list of\
    \ preference\n * OUTPUTS:\n *      - L2R[]:    the mate of man i (always between\
    \ 0 and n-1)\n *      - R2L[]:    the mate of woman j (or -1 if single)\n * COMPLEXITY:\
    \ M^2\n */\n\n#define MAXM 1024\n#define MAXW 1024\nint m;\nint L[MAXM][MAXW],\
    \ R[MAXW][MAXM];\nint L2R[MAXM], R2L[MAXW];\nint p[MAXM];\nvoid stableMarriage(){\n\
    \    static int p[128];\n    memset(R2L, -1, sizeof R2L);\n    memset(p, 0, sizeof\
    \ p);\n    // Each man proposes...\n    for(int i = 0; i < m; i++) {\n       \
    \ int man = i;\n        while (man >= 0) { // propose until success\n        \
    \    int wom;\n            while (1) {\n                wom = L[man][p[man]++];\n\
    \                if (R2L[wom] < 0 || R[wom][man] > R[wom][R2L[wom]]) break;\n\
    \            }\n            int hubby = R2L[wom];\n            R2L[L2R[man] =\
    \ wom] = man;\n            man = hubby; // remarry the dumped guy\n        }\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Matching/StableMarriage.h
  requiredBy: []
  timestamp: '2015-08-25 02:08:35+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Matching/StableMarriage.h
layout: document
redirect_from:
- /library/Graph/Matching/StableMarriage.h
- /library/Graph/Matching/StableMarriage.h.html
title: Graph/Matching/StableMarriage.h
---
