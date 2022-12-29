---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/binary_trie.test.cpp
    title: DataStructure/test/binary_trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cses.fi/problemset/task/1655/
    - https://judge.yosupo.jp/problem/set_xor_min
    - https://judge.yosupo.jp/submission/72657
    - https://www.spoj.com/problems/SUBXOR/
    - https://www.spoj.com/problems/XORX/
  bundledCode: "#line 1 \"DataStructure/BinaryTrie.h\"\n// Binary Trie\n// Based on\
    \ https://judge.yosupo.jp/submission/72657\n// Supports:\n// - get min / max /\
    \ kth element\n// - given K, find x: x^K is min / max / kth\n//\n// Notes:\n//\
    \ - high mem usage. If just need kth_element\n//   -> use OrderedSet.h if MAX_VALUE\
    \ is ~10^6\n//   -> use STL/order_statistic.cpp if MAX_VALUE is big / custom type\n\
    //\n// Tested:\n// - (insert, remove, min xor) https://judge.yosupo.jp/problem/set_xor_min\n\
    // - (insert, max xor) https://cses.fi/problemset/task/1655/\n// Binary trie {{{\n\
    template<\n    class Val = long long,   // values stored in Trie\n    class Count\
    \ = long long, // frequency of values\n    int B = (sizeof(Val) * 8 - 1)  // max\
    \ number of bit\n> struct BinaryTrie {\n    struct Node {\n        std::array<int,\
    \ 2> child;\n        Count count;\n        Node() : child{-1, -1}, count(0) {}\n\
    \    };\n\n    BinaryTrie() : nodes{Node()} {} // create root node\n\n    // Number\
    \ of elements in the trie\n    Count size() {\n        return nodes[0].count;\n\
    \    }\n\n    void insert(Val x, Count cnt = 1) {\n        update(x, cnt);\n \
    \   }\n    void remove(Val x, Count cnt = 1) {\n        update(x, -cnt);\n   \
    \ }\n\n    // return min(X ^ xor_val)\n    pair<Val, Node> min_element(Val xor_val\
    \ = 0) {\n        assert(0 < size());\n        return kth_element(0, xor_val);\n\
    \    }\n\n    // return max(X ^ xor_val)\n    // Tested: https://www.spoj.com/problems/XORX/\n\
    \    pair<Val, Node> max_element(Val xor_val = 0) {\n        assert(0 < size());\n\
    \        return kth_element(size() - 1, xor_val);\n    }\n\n    // return k-th\
    \ smallest (X ^ xor_val)  (0 <= K < size())\n    pair<Val, Node> kth_element(Count\
    \ k, Val xor_val = 0) {\n        assert(0 <= k && k < size());\n        int u\
    \ = 0;\n        Val x = 0;\n        for (int i = B - 1; i >= 0; i--) {\n     \
    \       int b = get_bit(xor_val, i);\n            int v0 = get_child(u, b);\n\
    \            if (nodes[v0].count <= k) {\n                k -= nodes[v0].count;\n\
    \                u = get_child(u, 1-b);\n                x |= 1LL << i;\n    \
    \        } else {\n                u = v0;\n            }\n        }\n       \
    \ return {x, nodes[u]};\n    }\n\n    // return frequency of x\n    Count count(Val\
    \ x) {\n        int u = 0;\n        for (int i = B - 1; i >= 0; i--) {\n     \
    \       int b = get_bit(x, i);\n            if (nodes[u].child[b] == -1) {\n \
    \               return 0;\n            }\n            u = get_child(u, b);\n \
    \       }\n        return nodes[u].count;\n    }\n\n    // return how many values\
    \ a where a ^ xor_val < x\n    // Tested: https://www.spoj.com/problems/SUBXOR/\n\
    \    Count count_less_than(Val x, Val xor_val) {\n        Count sum = 0;\n   \
    \     int u = 0;\n        for (int i = B - 1; i >= 0; --i) {\n            int\
    \ bx = get_bit(x, i);\n            int bxor = get_bit(xor_val, i);\n         \
    \   if (bx == 1) {\n                // i = first bit where a^xor_val differ from\
    \ x\n                if (nodes[u].child[bxor] >= 0) {\n                    sum\
    \ += nodes[nodes[u].child[bxor]].count;\n                }\n            }\n  \
    \          if (nodes[u].child[bx ^ bxor] == -1) {\n                return sum;\n\
    \            }\n            u = get_child(u, bx ^ bxor);\n        }\n        return\
    \ sum;\n    }\n\n// private:\n    vector<Node> nodes;\n\n    int get_child(int\
    \ p, int b) {\n        assert(0 <= p && p < (int) nodes.size());\n        assert(0\
    \ <= b && b < 2);\n        if (nodes[p].child[b] == -1) {\n            nodes[p].child[b]\
    \ = nodes.size();\n            nodes.push_back(Node{});\n        }\n        return\
    \ nodes[p].child[b];\n    }\n\n    void update(Val x, Count cnt) {\n        int\
    \ u = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            nodes[u].count\
    \ += cnt;\n            assert(nodes[u].count >= 0);  // prevent over delete\n\
    \            int b = get_bit(x, i);\n            u = get_child(u, b);\n      \
    \  }\n        nodes[u].count += cnt;\n        assert(nodes[u].count >= 0);  //\
    \ prevent over delete\n    }\n\n    inline int get_bit(Val v, int bit) {\n   \
    \     return (v >> bit) & 1;\n    }\n};\n// }}}\n"
  code: "// Binary Trie\n// Based on https://judge.yosupo.jp/submission/72657\n//\
    \ Supports:\n// - get min / max / kth element\n// - given K, find x: x^K is min\
    \ / max / kth\n//\n// Notes:\n// - high mem usage. If just need kth_element\n\
    //   -> use OrderedSet.h if MAX_VALUE is ~10^6\n//   -> use STL/order_statistic.cpp\
    \ if MAX_VALUE is big / custom type\n//\n// Tested:\n// - (insert, remove, min\
    \ xor) https://judge.yosupo.jp/problem/set_xor_min\n// - (insert, max xor) https://cses.fi/problemset/task/1655/\n\
    // Binary trie {{{\ntemplate<\n    class Val = long long,   // values stored in\
    \ Trie\n    class Count = long long, // frequency of values\n    int B = (sizeof(Val)\
    \ * 8 - 1)  // max number of bit\n> struct BinaryTrie {\n    struct Node {\n \
    \       std::array<int, 2> child;\n        Count count;\n        Node() : child{-1,\
    \ -1}, count(0) {}\n    };\n\n    BinaryTrie() : nodes{Node()} {} // create root\
    \ node\n\n    // Number of elements in the trie\n    Count size() {\n        return\
    \ nodes[0].count;\n    }\n\n    void insert(Val x, Count cnt = 1) {\n        update(x,\
    \ cnt);\n    }\n    void remove(Val x, Count cnt = 1) {\n        update(x, -cnt);\n\
    \    }\n\n    // return min(X ^ xor_val)\n    pair<Val, Node> min_element(Val\
    \ xor_val = 0) {\n        assert(0 < size());\n        return kth_element(0, xor_val);\n\
    \    }\n\n    // return max(X ^ xor_val)\n    // Tested: https://www.spoj.com/problems/XORX/\n\
    \    pair<Val, Node> max_element(Val xor_val = 0) {\n        assert(0 < size());\n\
    \        return kth_element(size() - 1, xor_val);\n    }\n\n    // return k-th\
    \ smallest (X ^ xor_val)  (0 <= K < size())\n    pair<Val, Node> kth_element(Count\
    \ k, Val xor_val = 0) {\n        assert(0 <= k && k < size());\n        int u\
    \ = 0;\n        Val x = 0;\n        for (int i = B - 1; i >= 0; i--) {\n     \
    \       int b = get_bit(xor_val, i);\n            int v0 = get_child(u, b);\n\
    \            if (nodes[v0].count <= k) {\n                k -= nodes[v0].count;\n\
    \                u = get_child(u, 1-b);\n                x |= 1LL << i;\n    \
    \        } else {\n                u = v0;\n            }\n        }\n       \
    \ return {x, nodes[u]};\n    }\n\n    // return frequency of x\n    Count count(Val\
    \ x) {\n        int u = 0;\n        for (int i = B - 1; i >= 0; i--) {\n     \
    \       int b = get_bit(x, i);\n            if (nodes[u].child[b] == -1) {\n \
    \               return 0;\n            }\n            u = get_child(u, b);\n \
    \       }\n        return nodes[u].count;\n    }\n\n    // return how many values\
    \ a where a ^ xor_val < x\n    // Tested: https://www.spoj.com/problems/SUBXOR/\n\
    \    Count count_less_than(Val x, Val xor_val) {\n        Count sum = 0;\n   \
    \     int u = 0;\n        for (int i = B - 1; i >= 0; --i) {\n            int\
    \ bx = get_bit(x, i);\n            int bxor = get_bit(xor_val, i);\n         \
    \   if (bx == 1) {\n                // i = first bit where a^xor_val differ from\
    \ x\n                if (nodes[u].child[bxor] >= 0) {\n                    sum\
    \ += nodes[nodes[u].child[bxor]].count;\n                }\n            }\n  \
    \          if (nodes[u].child[bx ^ bxor] == -1) {\n                return sum;\n\
    \            }\n            u = get_child(u, bx ^ bxor);\n        }\n        return\
    \ sum;\n    }\n\n// private:\n    vector<Node> nodes;\n\n    int get_child(int\
    \ p, int b) {\n        assert(0 <= p && p < (int) nodes.size());\n        assert(0\
    \ <= b && b < 2);\n        if (nodes[p].child[b] == -1) {\n            nodes[p].child[b]\
    \ = nodes.size();\n            nodes.push_back(Node{});\n        }\n        return\
    \ nodes[p].child[b];\n    }\n\n    void update(Val x, Count cnt) {\n        int\
    \ u = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            nodes[u].count\
    \ += cnt;\n            assert(nodes[u].count >= 0);  // prevent over delete\n\
    \            int b = get_bit(x, i);\n            u = get_child(u, b);\n      \
    \  }\n        nodes[u].count += cnt;\n        assert(nodes[u].count >= 0);  //\
    \ prevent over delete\n    }\n\n    inline int get_bit(Val v, int bit) {\n   \
    \     return (v >> bit) & 1;\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryTrie.h
  requiredBy: []
  timestamp: '2022-12-29 19:07:59+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/binary_trie.test.cpp
documentation_of: DataStructure/BinaryTrie.h
layout: document
redirect_from:
- /library/DataStructure/BinaryTrie.h
- /library/DataStructure/BinaryTrie.h.html
title: DataStructure/BinaryTrie.h
---
