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
  bundledCode: "#line 1 \"DataStructure/misc/offset_vector.h\"\ntemplate<typename\
    \ V>\nstruct OffsetVector {\n    // Index should be in [minIndex, maxIndex].\n\
    \    // minIndex and maxIndex can be negative.\n    OffsetVector(int minIndex,\
    \ int maxIndex) {\n        x.resize(maxIndex - minIndex + 1);\n        offset\
    \ = minIndex;\n    }\n\n    V& operator [] (int index) {\n        return x[index\
    \ - offset];\n    }\n\n    auto begin() { return x.begin(); }\n    auto end()\
    \ { return x.end(); }\n    auto size() { return x.size(); }\n\nprivate:\n    std::vector<V>\
    \ x;\n    int offset;\n};\n"
  code: "template<typename V>\nstruct OffsetVector {\n    // Index should be in [minIndex,\
    \ maxIndex].\n    // minIndex and maxIndex can be negative.\n    OffsetVector(int\
    \ minIndex, int maxIndex) {\n        x.resize(maxIndex - minIndex + 1);\n    \
    \    offset = minIndex;\n    }\n\n    V& operator [] (int index) {\n        return\
    \ x[index - offset];\n    }\n\n    auto begin() { return x.begin(); }\n    auto\
    \ end() { return x.end(); }\n    auto size() { return x.size(); }\n\nprivate:\n\
    \    std::vector<V> x;\n    int offset;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/misc/offset_vector.h
  requiredBy: []
  timestamp: '2021-12-29 17:52:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/misc/offset_vector.h
layout: document
redirect_from:
- /library/DataStructure/misc/offset_vector.h
- /library/DataStructure/misc/offset_vector.h.html
title: DataStructure/misc/offset_vector.h
---
