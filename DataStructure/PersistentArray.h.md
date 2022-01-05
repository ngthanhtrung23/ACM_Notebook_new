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
    - https://codeforces.com/contest/707/problem/D
  bundledCode: "#line 1 \"DataStructure/PersistentArray.h\"\n// PersistentArray\n\
    //\n// Notes:\n// - Reduce mem -> decrease LOG\n// - Reduce time -> increase LOG\n\
    //\n// Tested:\n// - https://codeforces.com/contest/707/problem/D\ntemplate<typename\
    \ T>\nstruct PersistentArray {\n    static const int LOG = 4;\n    static const\
    \ int FULL_MASK = (1<<LOG) - 1;\n\n    struct Node {\n        T x;\n        std::array<Node*,\
    \ 1<<LOG> child;\n        Node(const T& _x) : x(_x) {\n            std::fill(child.begin(),\
    \ child.end(), nullptr);\n        }\n        Node(const Node& n) : x(n.x) {\n\
    \            std::copy(n.child.begin(), n.child.end(), child.begin());\n     \
    \   }\n    };\n\n    // get p-th element in `t` version\n    static T get(Node*\
    \ t, int p) {\n        if (t == NULL) return 0;\n        return p ? get(t->child[p\
    \ & FULL_MASK], p >> LOG) : t->x;\n    }\n\n    // set p-th element in `t` version\
    \ to x, and return new version\n    static Node* set(Node* t, int p, const T&\
    \ x) {\n        t = (t == NULL) ? new Node(0) : new Node(*t);\n        if (p ==\
    \ 0) t->x = x;\n        else {\n            auto ptr = set(t->child[p & FULL_MASK],\
    \ p >> LOG, x);\n            t->child[p & FULL_MASK] = ptr;\n        }\n     \
    \   return t;\n    }\n\n    // init a persistent array and return root node\n\
    \    Node* build(const vector<T>& v) {\n        Node* root = NULL;\n        for\
    \ (int i = 0; i < (int) v.size(); i++) {\n            root = set(root, i, v[i]);\n\
    \        }\n        return root;\n    }\n};\n"
  code: "// PersistentArray\n//\n// Notes:\n// - Reduce mem -> decrease LOG\n// -\
    \ Reduce time -> increase LOG\n//\n// Tested:\n// - https://codeforces.com/contest/707/problem/D\n\
    template<typename T>\nstruct PersistentArray {\n    static const int LOG = 4;\n\
    \    static const int FULL_MASK = (1<<LOG) - 1;\n\n    struct Node {\n       \
    \ T x;\n        std::array<Node*, 1<<LOG> child;\n        Node(const T& _x) :\
    \ x(_x) {\n            std::fill(child.begin(), child.end(), nullptr);\n     \
    \   }\n        Node(const Node& n) : x(n.x) {\n            std::copy(n.child.begin(),\
    \ n.child.end(), child.begin());\n        }\n    };\n\n    // get p-th element\
    \ in `t` version\n    static T get(Node* t, int p) {\n        if (t == NULL) return\
    \ 0;\n        return p ? get(t->child[p & FULL_MASK], p >> LOG) : t->x;\n    }\n\
    \n    // set p-th element in `t` version to x, and return new version\n    static\
    \ Node* set(Node* t, int p, const T& x) {\n        t = (t == NULL) ? new Node(0)\
    \ : new Node(*t);\n        if (p == 0) t->x = x;\n        else {\n           \
    \ auto ptr = set(t->child[p & FULL_MASK], p >> LOG, x);\n            t->child[p\
    \ & FULL_MASK] = ptr;\n        }\n        return t;\n    }\n\n    // init a persistent\
    \ array and return root node\n    Node* build(const vector<T>& v) {\n        Node*\
    \ root = NULL;\n        for (int i = 0; i < (int) v.size(); i++) {\n         \
    \   root = set(root, i, v[i]);\n        }\n        return root;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentArray.h
  requiredBy: []
  timestamp: '2022-01-02 20:29:22+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/PersistentArray.h
layout: document
redirect_from:
- /library/DataStructure/PersistentArray.h
- /library/DataStructure/PersistentArray.h.html
title: DataStructure/PersistentArray.h
---
