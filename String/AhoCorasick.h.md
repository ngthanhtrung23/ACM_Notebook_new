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
    - https://icpc.kattis.com/problems/firstofhername
    - https://oj.vnoi.info/problem/binpal
    - https://open.kattis.com/problems/stringmultimatching
  bundledCode: "#line 1 \"String/AhoCorasick.h\"\n// Tested:\n// - https://open.kattis.com/problems/stringmultimatching\n\
    // - https://icpc.kattis.com/problems/firstofhername\n// - https://oj.vnoi.info/problem/binpal\n\
    //\n// Notes:\n// - Node IDs from 0 to aho.sz.\n// - Characters should be normalized\
    \ to [0, MC-1].\n// - For each node of AhoCorasick, we store a linked list containing\
    \ all queries \"associated\" with this node.\n//   The reason is that, when we\
    \ reach a node in AhoCorasick, it's possible to match several queries at once.\n\
    //   (this happens when queries are suffix of others, e.g. C, BC, ABC).\n//  \
    \ This also means 1 node maps to several queries, and 1 query maps to several\
    \ nodes.\n//   However I believe that the sum of length of all linked list is\
    \ O(N) -- TODO: Source / proof required.\n\nconst int MN = 1000111; // MN > total\
    \ length of all patterns\nconst int MC = 26; // Alphabet size.\n\n// Start of\
    \ Linked list\nstruct Node {\n    int x; Node *next;\n} *nil;\nstruct List {\n\
    \    Node *first, *last;\n    List() { first = last = nil; }\n    void add(int\
    \ x) {\n        Node *p = new Node;\n        p->x = x; p->next = nil;\n      \
    \  if (first == nil) last = first = p;\n        else last->next = p, last = p;\n\
    \    }\n};\n// End of linked list\n//\nstruct Aho {\n    int qu[MN], suffixLink[MN];\n\
    \    List leaf[MN];\n    int link[MN][MC];\n    int sz;\n    bool calledBuildLink;\n\
    \n    void init() {\n        calledBuildLink = false;\n        sz = 0;\n     \
    \   memset(suffixLink, 0, sizeof suffixLink);\n        leaf[0] = List();\n   \
    \     memset(link[0], -1, sizeof link[0]);\n    }\n    int getChild(int type,\
    \ int v, int c) {\n        if (type == 2) assert(calledBuildLink);\n\n       \
    \ if (link[v][c] >= 0) return link[v][c];\n        if (type == 1) return 0;\n\
    \        if (!v) return link[v][c] = 0;\n        return link[v][c] = getChild(type,\
    \ suffixLink[v], c);\n    }\n    void buildLink() {\n        calledBuildLink =\
    \ true;\n        int first, last;\n        qu[first = last = 1] = 0;\n       \
    \ while (first <= last) {\n            int u = qu[first++];\n            REP(c,MC)\
    \ {\n                int v = link[u][c]; if (v < 0) continue;\n              \
    \  qu[++last] = v;\n                if (u == 0) suffixLink[v] = 0;\n         \
    \       else suffixLink[v] = getChild(2, suffixLink[u], c);\n\n              \
    \  if (leaf[suffixLink[v]].first != nil) {\n                    if (leaf[v].first\
    \ == nil) {\n                        leaf[v].first = leaf[suffixLink[v]].first;\n\
    \                        leaf[v].last = leaf[suffixLink[v]].last;\n          \
    \          }\n                    else {\n                        leaf[v].last->next\
    \ = leaf[suffixLink[v]].first;\n                        leaf[v].last = leaf[suffixLink[v]].last;\n\
    \                    }\n                }\n            }\n        }\n    }\n}\
    \ aho;\n// Usage:\naho.init(); // Initialize\n// Foreach query, insert one character\
    \ at a time:\n            int p = 0;\n            while (k--) {\n            \
    \    int x; scanf(\"%d\", &x);\n                int t = aho.getChild(1, p, x);\n\
    \                if (t > 0) p = t;\n                else {\n                 \
    \   ++aho.sz;\n                    aho.leaf[aho.sz] = List();\n              \
    \      memset(aho.link[aho.sz], -1, sizeof aho.link[aho.sz]);\n\n            \
    \        aho.link[p][x] = aho.sz;\n                    p = aho.sz;\n         \
    \       }\n            }\n            aho.leaf[p].add(i);\n// Init back link\n\
    \        aho.buildLink();\n// After this stage, we should use aho.getChild(2,\
    \ node, c) to jump\n"
  code: "// Tested:\n// - https://open.kattis.com/problems/stringmultimatching\n//\
    \ - https://icpc.kattis.com/problems/firstofhername\n// - https://oj.vnoi.info/problem/binpal\n\
    //\n// Notes:\n// - Node IDs from 0 to aho.sz.\n// - Characters should be normalized\
    \ to [0, MC-1].\n// - For each node of AhoCorasick, we store a linked list containing\
    \ all queries \"associated\" with this node.\n//   The reason is that, when we\
    \ reach a node in AhoCorasick, it's possible to match several queries at once.\n\
    //   (this happens when queries are suffix of others, e.g. C, BC, ABC).\n//  \
    \ This also means 1 node maps to several queries, and 1 query maps to several\
    \ nodes.\n//   However I believe that the sum of length of all linked list is\
    \ O(N) -- TODO: Source / proof required.\n\nconst int MN = 1000111; // MN > total\
    \ length of all patterns\nconst int MC = 26; // Alphabet size.\n\n// Start of\
    \ Linked list\nstruct Node {\n    int x; Node *next;\n} *nil;\nstruct List {\n\
    \    Node *first, *last;\n    List() { first = last = nil; }\n    void add(int\
    \ x) {\n        Node *p = new Node;\n        p->x = x; p->next = nil;\n      \
    \  if (first == nil) last = first = p;\n        else last->next = p, last = p;\n\
    \    }\n};\n// End of linked list\n//\nstruct Aho {\n    int qu[MN], suffixLink[MN];\n\
    \    List leaf[MN];\n    int link[MN][MC];\n    int sz;\n    bool calledBuildLink;\n\
    \n    void init() {\n        calledBuildLink = false;\n        sz = 0;\n     \
    \   memset(suffixLink, 0, sizeof suffixLink);\n        leaf[0] = List();\n   \
    \     memset(link[0], -1, sizeof link[0]);\n    }\n    int getChild(int type,\
    \ int v, int c) {\n        if (type == 2) assert(calledBuildLink);\n\n       \
    \ if (link[v][c] >= 0) return link[v][c];\n        if (type == 1) return 0;\n\
    \        if (!v) return link[v][c] = 0;\n        return link[v][c] = getChild(type,\
    \ suffixLink[v], c);\n    }\n    void buildLink() {\n        calledBuildLink =\
    \ true;\n        int first, last;\n        qu[first = last = 1] = 0;\n       \
    \ while (first <= last) {\n            int u = qu[first++];\n            REP(c,MC)\
    \ {\n                int v = link[u][c]; if (v < 0) continue;\n              \
    \  qu[++last] = v;\n                if (u == 0) suffixLink[v] = 0;\n         \
    \       else suffixLink[v] = getChild(2, suffixLink[u], c);\n\n              \
    \  if (leaf[suffixLink[v]].first != nil) {\n                    if (leaf[v].first\
    \ == nil) {\n                        leaf[v].first = leaf[suffixLink[v]].first;\n\
    \                        leaf[v].last = leaf[suffixLink[v]].last;\n          \
    \          }\n                    else {\n                        leaf[v].last->next\
    \ = leaf[suffixLink[v]].first;\n                        leaf[v].last = leaf[suffixLink[v]].last;\n\
    \                    }\n                }\n            }\n        }\n    }\n}\
    \ aho;\n// Usage:\naho.init(); // Initialize\n// Foreach query, insert one character\
    \ at a time:\n            int p = 0;\n            while (k--) {\n            \
    \    int x; scanf(\"%d\", &x);\n                int t = aho.getChild(1, p, x);\n\
    \                if (t > 0) p = t;\n                else {\n                 \
    \   ++aho.sz;\n                    aho.leaf[aho.sz] = List();\n              \
    \      memset(aho.link[aho.sz], -1, sizeof aho.link[aho.sz]);\n\n            \
    \        aho.link[p][x] = aho.sz;\n                    p = aho.sz;\n         \
    \       }\n            }\n            aho.leaf[p].add(i);\n// Init back link\n\
    \        aho.buildLink();\n// After this stage, we should use aho.getChild(2,\
    \ node, c) to jump\n"
  dependsOn: []
  isVerificationFile: false
  path: String/AhoCorasick.h
  requiredBy: []
  timestamp: '2021-05-03 12:01:04+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/AhoCorasick.h
layout: document
redirect_from:
- /library/String/AhoCorasick.h
- /library/String/AhoCorasick.h.html
title: String/AhoCorasick.h
---
