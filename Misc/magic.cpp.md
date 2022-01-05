---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Misc/magic.cpp\"\n// Given array D[i]\n// Calculate D'[i]\
    \ = sum( D[j] | j is subset of i )\n//\n// If we want to calculate D'[i] = sum(\
    \ D[j] | j is superset of i ),\n// change D[t|i] += D[f|i] --> D[f|i] += D[t|i]\n\
    \nvoid magic() {\n    for(b=0; b<K; b++) {\n        int f=0, t=(1<<b);\n     \
    \   for(g=0; g<(1<<(K-1-b)); f+=(1<<(b+1)), t+=(1<<(b+1)), g++)\n            for(i=0;\
    \ i<(1<<b); i++)\n                D[t|i] += D[f|i];\n    }\n}\n"
  code: "// Given array D[i]\n// Calculate D'[i] = sum( D[j] | j is subset of i )\n\
    //\n// If we want to calculate D'[i] = sum( D[j] | j is superset of i ),\n// change\
    \ D[t|i] += D[f|i] --> D[f|i] += D[t|i]\n\nvoid magic() {\n    for(b=0; b<K; b++)\
    \ {\n        int f=0, t=(1<<b);\n        for(g=0; g<(1<<(K-1-b)); f+=(1<<(b+1)),\
    \ t+=(1<<(b+1)), g++)\n            for(i=0; i<(1<<b); i++)\n                D[t|i]\
    \ += D[f|i];\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/magic.cpp
  requiredBy: []
  timestamp: '2017-10-31 23:17:12+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/magic.cpp
layout: document
redirect_from:
- /library/Misc/magic.cpp
- /library/Misc/magic.cpp.html
title: Misc/magic.cpp
---
