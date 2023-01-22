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
    - https://codeforces.com/blog/entry/76149
  bundledCode: "#line 1 \"DataStructure/misc/vec.h\"\n// Copied from https://codeforces.com/blog/entry/76149\n\
    \n// n-d vector {{{\ntemplate<int D, typename T>\nstruct Vec : public vector<Vec<D\
    \ - 1, T>> {\n    static_assert(D >= 1, \"Dimension must be positive\");\n   \
    \ template<typename... Args>\n    Vec(int n = 0, Args... args) : vector<Vec<D\
    \ - 1, T>>(n, Vec<D - 1, T> (args...)) {}\n};\n\ntemplate<typename T>\nstruct\
    \ Vec<1, T> : public vector<T> {\n    Vec(int n = 0, T val = T()) : vector<T>\
    \ (n, val) {}\n};\n// }}}\n\n// Usage:\n{\n    Vec<2, int> a(10, 50); // int a[10][50]\
    \ initialized with zero\n    Vec<3, double> b(10, 10, 10, 3.14); // double b[10][10][10]\
    \ initialized with 3.14\n\n    Vec<3, long long> c(5, 5); // the third dimension\
    \ has no value yet\n    c[0][0].push_back(100); // now c[0][0][0] has a value\
    \ (100) but others don't\n\n    Vec<4, int> d(10, 10);\n    d[2][3].push_back(Vec<1,\
    \ int>(100, 12345)); // now d[2][3][0] is a vector with 100 values of 12345\n\n\
    \    Vec<1, string> e; // just blank vector of strings\n}\n"
  code: "// Copied from https://codeforces.com/blog/entry/76149\n\n// n-d vector {{{\n\
    template<int D, typename T>\nstruct Vec : public vector<Vec<D - 1, T>> {\n   \
    \ static_assert(D >= 1, \"Dimension must be positive\");\n    template<typename...\
    \ Args>\n    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1,\
    \ T> (args...)) {}\n};\n\ntemplate<typename T>\nstruct Vec<1, T> : public vector<T>\
    \ {\n    Vec(int n = 0, T val = T()) : vector<T> (n, val) {}\n};\n// }}}\n\n//\
    \ Usage:\n{\n    Vec<2, int> a(10, 50); // int a[10][50] initialized with zero\n\
    \    Vec<3, double> b(10, 10, 10, 3.14); // double b[10][10][10] initialized with\
    \ 3.14\n\n    Vec<3, long long> c(5, 5); // the third dimension has no value yet\n\
    \    c[0][0].push_back(100); // now c[0][0][0] has a value (100) but others don't\n\
    \n    Vec<4, int> d(10, 10);\n    d[2][3].push_back(Vec<1, int>(100, 12345));\
    \ // now d[2][3][0] is a vector with 100 values of 12345\n\n    Vec<1, string>\
    \ e; // just blank vector of strings\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/misc/vec.h
  requiredBy: []
  timestamp: '2023-01-18 14:36:13+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/misc/vec.h
layout: document
redirect_from:
- /library/DataStructure/misc/vec.h
- /library/DataStructure/misc/vec.h.html
title: DataStructure/misc/vec.h
---
