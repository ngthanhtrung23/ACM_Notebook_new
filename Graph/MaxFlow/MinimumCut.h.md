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
  bundledCode: "#line 1 \"Graph/MaxFlow/MinimumCut.h\"\n// Minimum cut between every\
    \ pair of vertices (Stoer Wagner)\npair<int, VI> GetMinCut(VVI &weights) {\n \
    \   int N = weights.size();\n    VI used(N), cut, best_cut;\n    int best_weight\
    \ = -1;\n    \n    for (int phase = N-1; phase >= 0; phase--) {\n        VI w\
    \ = weights[0];\n        VI added = used;\n        int prev, last = 0;\n     \
    \   for (int i = 0; i < phase; i++) {\n            prev = last;\n            last\
    \ = -1;\n            for (int j = 1; j < N; j++)\n            if (!added[j] &&\
    \ (last == -1 || w[j] > w[last])) last = j;\n            if (i == phase-1) {\n\
    \                for (int j = 0; j < N; j++) weights[prev][j] += weights[last][j];\n\
    \                for (int j = 0; j < N; j++) weights[j][prev] = weights[prev][j];\n\
    \                used[last] = true;\n                cut.push_back(last);\n  \
    \              if (best_weight == -1 || w[last] < best_weight) {\n           \
    \         best_cut = cut;\n                    best_weight = w[last];\n      \
    \          }\n            }\n            else {\n                for (int j =\
    \ 0; j < N; j++)\n                    w[j] += weights[last][j];\n            \
    \    added[last] = true;\n            }\n        }\n    }\n    return make_pair(best_weight,\
    \ best_cut);\n}\n"
  code: "// Minimum cut between every pair of vertices (Stoer Wagner)\npair<int, VI>\
    \ GetMinCut(VVI &weights) {\n    int N = weights.size();\n    VI used(N), cut,\
    \ best_cut;\n    int best_weight = -1;\n    \n    for (int phase = N-1; phase\
    \ >= 0; phase--) {\n        VI w = weights[0];\n        VI added = used;\n   \
    \     int prev, last = 0;\n        for (int i = 0; i < phase; i++) {\n       \
    \     prev = last;\n            last = -1;\n            for (int j = 1; j < N;\
    \ j++)\n            if (!added[j] && (last == -1 || w[j] > w[last])) last = j;\n\
    \            if (i == phase-1) {\n                for (int j = 0; j < N; j++)\
    \ weights[prev][j] += weights[last][j];\n                for (int j = 0; j < N;\
    \ j++) weights[j][prev] = weights[prev][j];\n                used[last] = true;\n\
    \                cut.push_back(last);\n                if (best_weight == -1 ||\
    \ w[last] < best_weight) {\n                    best_cut = cut;\n            \
    \        best_weight = w[last];\n                }\n            }\n          \
    \  else {\n                for (int j = 0; j < N; j++)\n                    w[j]\
    \ += weights[last][j];\n                added[last] = true;\n            }\n \
    \       }\n    }\n    return make_pair(best_weight, best_cut);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaxFlow/MinimumCut.h
  requiredBy: []
  timestamp: '2015-09-08 17:23:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/MaxFlow/MinimumCut.h
layout: document
redirect_from:
- /library/Graph/MaxFlow/MinimumCut.h
- /library/Graph/MaxFlow/MinimumCut.h.html
title: Graph/MaxFlow/MinimumCut.h
---
