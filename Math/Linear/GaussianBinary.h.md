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
    - http://codeforces.com/gym/100211
  bundledCode: "#line 1 \"Math/Linear/GaussianBinary.h\"\n// Tested: http://codeforces.com/gym/100211\
    \ - E\n// n : number of rows\n// m : number of columns\nint gauss (vector < bitset<N>\
    \ > a, int n, int m, bitset<N> & ans) {\n    vector<int> where (m, -1);\n    for\
    \ (int col=0, row=0; col<m && row<n; ++col) {\n        for (int i=row; i<n; ++i)\n\
    \            if (a[i][col]) {\n                swap (a[i], a[row]);\n        \
    \        break;\n            }\n        if (! a[row][col])\n            continue;\n\
    \        where[col] = row;\n \n        for (int i=0; i<n; ++i)\n            if\
    \ (i != row && a[i][col])\n                a[i] ^= a[row];\n        ++row;\n \
    \   }\n    // The rest of implementation is the same as above\n}\n"
  code: "// Tested: http://codeforces.com/gym/100211 - E\n// n : number of rows\n\
    // m : number of columns\nint gauss (vector < bitset<N> > a, int n, int m, bitset<N>\
    \ & ans) {\n    vector<int> where (m, -1);\n    for (int col=0, row=0; col<m &&\
    \ row<n; ++col) {\n        for (int i=row; i<n; ++i)\n            if (a[i][col])\
    \ {\n                swap (a[i], a[row]);\n                break;\n          \
    \  }\n        if (! a[row][col])\n            continue;\n        where[col] =\
    \ row;\n \n        for (int i=0; i<n; ++i)\n            if (i != row && a[i][col])\n\
    \                a[i] ^= a[row];\n        ++row;\n    }\n    // The rest of implementation\
    \ is the same as above\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Linear/GaussianBinary.h
  requiredBy: []
  timestamp: '2016-01-05 03:45:48+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Linear/GaussianBinary.h
layout: document
redirect_from:
- /library/Math/Linear/GaussianBinary.h
- /library/Math/Linear/GaussianBinary.h.html
title: Math/Linear/GaussianBinary.h
---
