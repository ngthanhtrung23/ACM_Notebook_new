---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DSU/DSU_persistent.h
    title: DataStructure/DSU/DSU_persistent.h
  - icon: ':heavy_check_mark:'
    path: DataStructure/PersistentArray.h
    title: DataStructure/PersistentArray.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"DataStructure/test/persistent_dsu.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"DataStructure/DSU/DSU_persistent.h\"\n// PersistentDSU\n\
    //\n// Notes:\n// - this doesn't support delete edge operation, so isn't enough\
    \ to\n//   solve dynamic connectivity problem.\n// - it has high mem and time\
    \ usage, so be careful (both TLE and MLE on\n//   https://oj.vnoi.info/problem/hello22_schoolplan)\n\
    //\n// Tested:\n// - https://judge.yosupo.jp/problem/persistent_unionfind\n#line\
    \ 1 \"DataStructure/PersistentArray.h\"\n// PersistentArray\n//\n// Notes:\n//\
    \ - Reduce mem -> decrease LOG\n// - Reduce time -> increase LOG\n//\n// Tested:\n\
    // - https://codeforces.com/contest/707/problem/D\ntemplate<typename T>\nstruct\
    \ PersistentArray {\n    static const int LOG = 4;\n    static const int FULL_MASK\
    \ = (1<<LOG) - 1;\n\n    struct Node {\n        T x;\n        std::array<Node*,\
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
    \        }\n        return root;\n    }\n};\n#line 12 \"DataStructure/DSU/DSU_persistent.h\"\
    \nstruct PersistentDSU {\n    int n;\n    using Arr = PersistentArray<int>;\n\n\
    \    PersistentDSU(int _n) : n(_n) {\n        roots.emplace_back(A.build(std::vector<int>\
    \ (n, -1)));\n    }\n\n    int find(int version, int u) {\n        // Note that\
    \ we can't do path compression here\n        int p = A.get(roots[version], u);\n\
    \        return p < 0 ? u : find(version, p);\n    }\n\n    // Note that this\
    \ will always create a new version,\n    // regardless of whether u and v was\
    \ previously in same component.\n    bool merge(int version, int u, int v) {\n\
    \        u = find(version, u);\n        v = find(version, v);\n        auto ptr\
    \ = roots[version];\n        if (u != v) {\n            int sz_u = -A.get(ptr,\
    \ u), sz_v = -A.get(ptr, v);\n            if (sz_u < sz_v) swap(u, v);\n     \
    \       // sz[u] >= sz[v]\n            ptr = A.set(ptr, u, -sz_u - sz_v);\n  \
    \          ptr = A.set(ptr, v, u);\n        }\n\n        roots.emplace_back(ptr);\n\
    \        return u != v;\n    }\n\n    int component_size(int version, int u) {\n\
    \        return -A.get(roots[version], find(version, u));\n    }\n\n    bool same_component(int\
    \ version, int u, int v) {\n        return find(version, u) == find(version, v);\n\
    \    }\n\n    Arr A;\n    vector<Arr::Node*> roots;\n};\n\n#line 7 \"DataStructure/test/persistent_dsu.test.cpp\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q;\
    \ cin >> n >> q;\n\n    PersistentDSU dsu(n);\n\n    while (q--) {\n        int\
    \ typ, version; cin >> typ >> version;\n        int u, v; cin >> u >> v;\n\n \
    \       if (typ == 0) {\n            dsu.merge(version + 1, u, v);\n        }\
    \ else {\n            // create extra version, since the input format requires\
    \ it..\n            dsu.merge(version + 1, 0, 0);\n            cout << dsu.same_component(version\
    \ + 1, u, v) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../DSU/DSU_persistent.h\"\
    \n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q;\
    \ cin >> n >> q;\n\n    PersistentDSU dsu(n);\n\n    while (q--) {\n        int\
    \ typ, version; cin >> typ >> version;\n        int u, v; cin >> u >> v;\n\n \
    \       if (typ == 0) {\n            dsu.merge(version + 1, u, v);\n        }\
    \ else {\n            // create extra version, since the input format requires\
    \ it..\n            dsu.merge(version + 1, 0, 0);\n            cout << dsu.same_component(version\
    \ + 1, u, v) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/DSU/DSU_persistent.h
  - DataStructure/PersistentArray.h
  isVerificationFile: true
  path: DataStructure/test/persistent_dsu.test.cpp
  requiredBy: []
  timestamp: '2023-01-07 01:46:12+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/persistent_dsu.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/persistent_dsu.test.cpp
- /verify/DataStructure/test/persistent_dsu.test.cpp.html
title: DataStructure/test/persistent_dsu.test.cpp
---
