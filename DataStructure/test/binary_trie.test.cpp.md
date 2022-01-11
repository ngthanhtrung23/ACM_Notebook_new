---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryTrie.h
    title: DataStructure/BinaryTrie.h
  - icon: ':heavy_check_mark:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"DataStructure/test/binary_trie.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 1 \"template.h\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#define FOR(i,a,b) for(int i=(a),_b=(b);\
    \ i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)\n#define\
    \ REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a) for(__typeof(a.begin())\
    \ it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x) { cout << #x << \"\
    \ = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n)\
    \ cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n) { cout << #a << \" =\
    \ \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\n\
    \n// For printing pair, container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
    template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>&\
    \ p) {\n    return out << '(' << p.first << \", \" << p.second << ')';\n}\n\n\
    template<class Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
    \ string>::value, ostream&>::type\noperator << (ostream& out, const Con& con)\
    \ {\n    out << '{';\n    for (auto beg = con.begin(), it = beg; it != con.end();\
    \ it++) {\n        out << (it == beg ? \"\" : \", \") << *it;\n    }\n    return\
    \ out << '}';\n}\ntemplate<size_t i, class T> ostream& print_tuple_utils(ostream&\
    \ out, const T& tup) {\n    if constexpr(i == tuple_size<T>::value) return out\
    \ << \")\"; \n    else return print_tuple_utils<i + 1, T>(out << (i ? \", \" :\
    \ \"(\") << get<i>(tup), tup); \n}\ntemplate<class ...U> ostream& operator <<\
    \ (ostream& out, const tuple<U...>& t) {\n    return print_tuple_utils<0, tuple<U...>>(out,\
    \ t);\n}\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r) {\n    return uniform_int_distribution<long long>\
    \ (0, r-1)(rng);\n}\n\nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    solve();\n    return 0;\n}\n#line 1 \"DataStructure/BinaryTrie.h\"\
    \n// Binary Trie\n// Based on https://judge.yosupo.jp/submission/72657\n// Supports:\n\
    // - get min / max / kth element\n// - given K, find x: x^K is min / max / kth\n\
    //\n// Tested:\n// - (insert, remove, min xor) https://judge.yosupo.jp/problem/set_xor_min\n\
    // - (insert, max xor) https://cses.fi/problemset/task/1655/\ntemplate<\n    class\
    \ Val = long long,   // values stored in Trie\n    class Count = long long, //\
    \ frequency of values\n    int B = (sizeof(Val) * 8 - 2)  // max number of bit\n\
    > struct BinaryTrie {\n    struct Node {\n        std::array<int, 2> child;\n\
    \        Count count;\n        Node() : child{-1, -1}, count(0) {}\n    };\n\n\
    \    BinaryTrie() : nodes{Node()} {} // create root node\n\n    // Number of elements\
    \ in the trie\n    Count size() {\n        return nodes[0].count;\n    }\n\n \
    \   void insert(Val x, Count cnt = 1) {\n        update(x, cnt);\n    }\n    void\
    \ remove(Val x, Count cnt = 1) {\n        update(x, -cnt);\n    }\n\n    // return\
    \ X: X ^ xor_val is minimum\n    pair<Val, Node> min_element(Val xor_val = 0)\
    \ {\n        assert(0 < size());\n        return kth_element(0, xor_val);\n  \
    \  }\n\n    // return X: X ^ xor_val is maximum\n    pair<Val, Node> max_element(Val\
    \ xor_val = 0) {\n        assert(0 < size());\n        return kth_element(size()\
    \ - 1, xor_val);\n    }\n\n    // return X: X ^ xor_val is K-th (0 <= K < size())\n\
    \    pair<Val, Node> kth_element(Count k, Val xor_val = 0) {\n        assert(0\
    \ <= k && k < size());\n        int u = 0;\n        Val x = 0;\n        for (int\
    \ i = B - 1; i >= 0; i--) {\n            int b = get_bit(xor_val, i);\n      \
    \      int v0 = get_child(u, b);\n            if (nodes[v0].count <= k) {\n  \
    \              k -= nodes[v0].count;\n                u = get_child(u, 1-b);\n\
    \                x |= 1LL << i;\n            } else {\n                u = v0;\n\
    \            }\n        }\n        return {x, nodes[u]};\n    }\n\n    // return\
    \ frequency of x\n    Count count(Val x) {\n        int u = 0;\n        for (int\
    \ i = B - 1; i >= 0; i--) {\n            int b = get_bit(x, i);\n            if\
    \ (nodes[u].child[b] == -1) {\n                return 0;\n            }\n    \
    \        u = get_child(u, b);\n        }\n        return nodes[u].count;\n   \
    \ }\n\n// private:\n    vector<Node> nodes;\n\n    int get_child(int p, int b)\
    \ {\n        assert(0 <= p && p < (int) nodes.size());\n        assert(0 <= b\
    \ && b < 2);\n        if (nodes[p].child[b] == -1) {\n            nodes[p].child[b]\
    \ = nodes.size();\n            nodes.push_back(Node{});\n        }\n        return\
    \ nodes[p].child[b];\n    }\n\n    void update(Val x, Count cnt) {\n        int\
    \ u = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            nodes[u].count\
    \ += cnt;\n            assert(nodes[u].count >= 0);  // prevent over delete\n\
    \            int b = get_bit(x, i);\n            u = get_child(u, b);\n      \
    \  }\n        nodes[u].count += cnt;\n        assert(nodes[u].count >= 0);  //\
    \ prevent over delete\n    }\n\n    inline int get_bit(Val v, int bit) {\n   \
    \     return (v >> bit) & 1;\n    }\n};\n\n#line 5 \"DataStructure/test/binary_trie.test.cpp\"\
    \n\nvoid solve() {\n    BinaryTrie<int, int, 30> trie;\n    int q; cin >> q;\n\
    \    while (q--) {\n        int typ, x; cin >> typ >> x;\n        if (typ == 0)\
    \ {\n            int has = trie.count(x);\n            if (has == 0) trie.insert(x);\n\
    \        } else if (typ == 1) {\n            int has = trie.count(x);\n      \
    \      if (has == 1) trie.remove(x);\n        }\n        else cout << trie.min_element(x).first\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../template.h\"\n#include \"../BinaryTrie.h\"\n\nvoid solve() {\n    BinaryTrie<int,\
    \ int, 30> trie;\n    int q; cin >> q;\n    while (q--) {\n        int typ, x;\
    \ cin >> typ >> x;\n        if (typ == 0) {\n            int has = trie.count(x);\n\
    \            if (has == 0) trie.insert(x);\n        } else if (typ == 1) {\n \
    \           int has = trie.count(x);\n            if (has == 1) trie.remove(x);\n\
    \        }\n        else cout << trie.min_element(x).first << '\\n';\n    }\n\
    }\n"
  dependsOn:
  - template.h
  - DataStructure/BinaryTrie.h
  isVerificationFile: true
  path: DataStructure/test/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 03:56:32+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/binary_trie.test.cpp
- /verify/DataStructure/test/binary_trie.test.cpp.html
title: DataStructure/test/binary_trie.test.cpp
---
