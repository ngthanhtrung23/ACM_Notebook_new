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
    - https://spoj.com/problems/DNAOFELF/
  bundledCode: "#line 1 \"Math/Linear/GaussianBinary.h\"\n// Tested:\n// - https://spoj.com/problems/DNAOFELF/\n\
    //\n// Computes the rank of binary vectors over GF(2).\n//\n// Each row a[i] is\
    \ a vector of m bits.\n//\n// Example:\n//   vectors: 101, 011, 110\n//   rank\
    \ = 2 because 101 XOR 011 = 110\n//\n// Parameters:\n//   a : binary vectors\n\
    //   n : number of vectors\n//   m : number of bits / columns to use\n//\n// Returns:\n\
    //   number of linearly independent vectors among the given rows.\n//\n// Complexity:\n\
    //   O(n * m * bitset_cost)\nint gauss(vector<bitset<B>> a, int n, int m) {\n\
    \    int rank = 0;\n\n    for (int col = 0, row = 0; col < m && row < n; ++col)\
    \ {\n        int sel = -1;\n        for (int i = row; i < n; ++i) {\n        \
    \    if (a[i][col]) {\n                sel = i;\n                break;\n    \
    \        }\n        }\n\n        // No vector has bit col = 1, so this column\
    \ cannot add rank.\n        if (sel == -1) continue;\n\n        swap(a[sel], a[row]);\n\
    \n        for (int i = 0; i < n; ++i) {\n            if (i != row && a[i][col])\
    \ {\n                a[i] ^= a[row];\n            }\n        }\n\n        ++row;\n\
    \        ++rank;\n    }\n\n    return rank;\n}\n"
  code: "// Tested:\n// - https://spoj.com/problems/DNAOFELF/\n//\n// Computes the\
    \ rank of binary vectors over GF(2).\n//\n// Each row a[i] is a vector of m bits.\n\
    //\n// Example:\n//   vectors: 101, 011, 110\n//   rank = 2 because 101 XOR 011\
    \ = 110\n//\n// Parameters:\n//   a : binary vectors\n//   n : number of vectors\n\
    //   m : number of bits / columns to use\n//\n// Returns:\n//   number of linearly\
    \ independent vectors among the given rows.\n//\n// Complexity:\n//   O(n * m\
    \ * bitset_cost)\nint gauss(vector<bitset<B>> a, int n, int m) {\n    int rank\
    \ = 0;\n\n    for (int col = 0, row = 0; col < m && row < n; ++col) {\n      \
    \  int sel = -1;\n        for (int i = row; i < n; ++i) {\n            if (a[i][col])\
    \ {\n                sel = i;\n                break;\n            }\n       \
    \ }\n\n        // No vector has bit col = 1, so this column cannot add rank.\n\
    \        if (sel == -1) continue;\n\n        swap(a[sel], a[row]);\n\n       \
    \ for (int i = 0; i < n; ++i) {\n            if (i != row && a[i][col]) {\n  \
    \              a[i] ^= a[row];\n            }\n        }\n\n        ++row;\n \
    \       ++rank;\n    }\n\n    return rank;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Linear/GaussianBinary.h
  requiredBy: []
  timestamp: '2026-06-11 21:03:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Linear/GaussianBinary.h
layout: document
redirect_from:
- /library/Math/Linear/GaussianBinary.h
- /library/Math/Linear/GaussianBinary.h.html
title: Math/Linear/GaussianBinary.h
---
