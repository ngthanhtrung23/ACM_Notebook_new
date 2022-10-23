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
    - https://www.fb.com/codingcompetitions/hacker-cup/2022/round-3/problems/B
  bundledCode: "#line 1 \"String/trie.h\"\n// Trie {{{\n// Tested: https://www.fb.com/codingcompetitions/hacker-cup/2022/round-3/problems/B\n\
    struct Trie {\n    Trie(int _nChild, char _offset)\n        : nChild(_nChild),\
    \ offset(_offset),\n        children(1, std::vector<int> (_nChild, -1)) {}\n\n\
    \    int addNode(int p, char c) {\n        // create child node\n        int child\
    \ = children.size();\n        children.push_back(std::vector<int> (nChild, -1));\n\
    \n        // link\n        children[p][c - offset] = child;\n        return child;\n\
    \    }\n\n    int nChild;\n    char offset;\n    std::vector<std::vector<int>>\
    \ children;\n};\n// }}}\n"
  code: "// Trie {{{\n// Tested: https://www.fb.com/codingcompetitions/hacker-cup/2022/round-3/problems/B\n\
    struct Trie {\n    Trie(int _nChild, char _offset)\n        : nChild(_nChild),\
    \ offset(_offset),\n        children(1, std::vector<int> (_nChild, -1)) {}\n\n\
    \    int addNode(int p, char c) {\n        // create child node\n        int child\
    \ = children.size();\n        children.push_back(std::vector<int> (nChild, -1));\n\
    \n        // link\n        children[p][c - offset] = child;\n        return child;\n\
    \    }\n\n    int nChild;\n    char offset;\n    std::vector<std::vector<int>>\
    \ children;\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/trie.h
  requiredBy: []
  timestamp: '2022-10-08 21:15:49-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/trie.h
layout: document
redirect_from:
- /library/String/trie.h
- /library/String/trie.h.html
title: String/trie.h
---
