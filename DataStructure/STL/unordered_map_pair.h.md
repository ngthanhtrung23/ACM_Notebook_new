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
  bundledCode: "#line 1 \"DataStructure/STL/unordered_map_pair.h\"\nnamespace std\
    \ {\n    template<>\n    struct hash< pair<int,long long> > {\n        public:\n\
    \            size_t operator() (pair<int,long long> x) const {\n             \
    \   return x.first * 1000000009 + x.second;\n            }\n    };\n}\n"
  code: "namespace std {\n    template<>\n    struct hash< pair<int,long long> > {\n\
    \        public:\n            size_t operator() (pair<int,long long> x) const\
    \ {\n                return x.first * 1000000009 + x.second;\n            }\n\
    \    };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/STL/unordered_map_pair.h
  requiredBy: []
  timestamp: '2015-04-04 01:15:29+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/STL/unordered_map_pair.h
layout: document
redirect_from:
- /library/DataStructure/STL/unordered_map_pair.h
- /library/DataStructure/STL/unordered_map_pair.h.html
title: DataStructure/STL/unordered_map_pair.h
---
