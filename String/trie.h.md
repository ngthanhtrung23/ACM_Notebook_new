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
    - https://www.spoj.com/problems/ADAINDEX/
  bundledCode: "#line 1 \"String/trie.h\"\n// Trie {{{\n// Tested:\n// - https://www.spoj.com/problems/ADAINDEX/\n\
    struct Trie {\n    Trie(int _nChild, char _offset)\n        : nChild(_nChild),\
    \ offset(_offset),\n        children(1, std::vector<int> (_nChild, -1))\n    \
    \    // For DP, uncomment:\n        // , dp(1, INITIAL_VALUE)\n    {}\n\n    /**\
    \ For DP:\n    void dfs(int u = 0) {\n        if (u < 0) return;\n        for\
    \ (int v : children[u]) {\n            if (v < 0) continue;\n            dfs(v);\n\
    \n            // Example function: dist to leaf\n            f[u] = max(f[u],\
    \ f[v] + 1);\n        }\n    }\n     */\n\n    // Add a new string s to Trie.\
    \ Returns ID of new node\n    int add(const string& s) {\n        int p = 0;\n\
    \        for (char c : s) {\n            p = getChild(p, c, /* create= */ true);\n\
    \        }\n        // For DP: Initialize f[p] here\n        // f[p] = 0;\n  \
    \      return p;\n    }\n\n    // Follow string s on trie, and return ID of node.\n\
    \    // Returns -1 if no such node.\n    int get(const string& s) {\n        int\
    \ p = 0;\n        for (char c : s) {\n            p = getChild(p, c);\n      \
    \      if (p < 0) return -1;\n        }\n        return p;\n    }\n\n    // Create\
    \ a new child of p, edge from p -> child = c\n    // Returns ID of new node\n\
    \    int addNode(int p, char c) {\n        // create child node\n        int child\
    \ = children.size();\n        children.push_back(std::vector<int> (nChild, -1));\n\
    \        // For DP: Initialize f[p]\n        // f.push_back(INT_MAX / 2);\n\n\
    \        // link\n        children[p][c - offset] = child;\n        return child;\n\
    \    }\n\n    bool hasChild(int p, char c) {\n        return children[p][c - offset]\
    \ >= 0;\n    }\n\n    // Returns -1 if no such child, otherwise returns ID of\
    \ child\n    // If create = true (useful for adding strings to trie), a new\n\
    \    // child is created if not exist\n    int getChild(int p, char c, bool create=false)\
    \ {\n        assert(p < (int) children.size());\n\n        if (!hasChild(p, c)\
    \ && create) {\n            return addNode(p, c);\n        }\n\n        return\
    \ children[p][c - offset];\n    }\n\n    int nChild;\n    char offset;\n    std::vector<std::vector<int>>\
    \ children;\n    // For DP: uncomment\n    // std::vector<int> f;\n};\n// }}}\n"
  code: "// Trie {{{\n// Tested:\n// - https://www.spoj.com/problems/ADAINDEX/\nstruct\
    \ Trie {\n    Trie(int _nChild, char _offset)\n        : nChild(_nChild), offset(_offset),\n\
    \        children(1, std::vector<int> (_nChild, -1))\n        // For DP, uncomment:\n\
    \        // , dp(1, INITIAL_VALUE)\n    {}\n\n    /** For DP:\n    void dfs(int\
    \ u = 0) {\n        if (u < 0) return;\n        for (int v : children[u]) {\n\
    \            if (v < 0) continue;\n            dfs(v);\n\n            // Example\
    \ function: dist to leaf\n            f[u] = max(f[u], f[v] + 1);\n        }\n\
    \    }\n     */\n\n    // Add a new string s to Trie. Returns ID of new node\n\
    \    int add(const string& s) {\n        int p = 0;\n        for (char c : s)\
    \ {\n            p = getChild(p, c, /* create= */ true);\n        }\n        //\
    \ For DP: Initialize f[p] here\n        // f[p] = 0;\n        return p;\n    }\n\
    \n    // Follow string s on trie, and return ID of node.\n    // Returns -1 if\
    \ no such node.\n    int get(const string& s) {\n        int p = 0;\n        for\
    \ (char c : s) {\n            p = getChild(p, c);\n            if (p < 0) return\
    \ -1;\n        }\n        return p;\n    }\n\n    // Create a new child of p,\
    \ edge from p -> child = c\n    // Returns ID of new node\n    int addNode(int\
    \ p, char c) {\n        // create child node\n        int child = children.size();\n\
    \        children.push_back(std::vector<int> (nChild, -1));\n        // For DP:\
    \ Initialize f[p]\n        // f.push_back(INT_MAX / 2);\n\n        // link\n \
    \       children[p][c - offset] = child;\n        return child;\n    }\n\n   \
    \ bool hasChild(int p, char c) {\n        return children[p][c - offset] >= 0;\n\
    \    }\n\n    // Returns -1 if no such child, otherwise returns ID of child\n\
    \    // If create = true (useful for adding strings to trie), a new\n    // child\
    \ is created if not exist\n    int getChild(int p, char c, bool create=false)\
    \ {\n        assert(p < (int) children.size());\n\n        if (!hasChild(p, c)\
    \ && create) {\n            return addNode(p, c);\n        }\n\n        return\
    \ children[p][c - offset];\n    }\n\n    int nChild;\n    char offset;\n    std::vector<std::vector<int>>\
    \ children;\n    // For DP: uncomment\n    // std::vector<int> f;\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/trie.h
  requiredBy: []
  timestamp: '2022-12-29 17:34:35+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/trie.h
layout: document
redirect_from:
- /library/String/trie.h
- /library/String/trie.h.html
title: String/trie.h
---
