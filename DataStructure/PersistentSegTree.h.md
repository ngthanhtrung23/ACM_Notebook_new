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
    - https://cses.fi/problemset/task/1737
    - https://oj.vnoi.info/problem/vquery
  bundledCode: "#line 1 \"DataStructure/PersistentSegTree.h\"\n// Notes:\n// - class\
    \ PersistentSegTree doesn't store any data.\n//   -> Need to store seg tree roots\
    \ separately.\n// - assume all versions have same size (it isn't really necessary,\
    \ but makes interface nicer)\n//\n// Tested:\n// - https://cses.fi/problemset/task/1737\n\
    // - https://oj.vnoi.info/problem/vquery\ntemplate<\n    class S,         // node\
    \ aggregate data\n    S (*op) (S, S),  // combine 2 nodes\n    S (*e) ()     \
    \   // aggregate data of empty node\n> struct PersistentSegTree {\n    struct\
    \ Node {\n        Node* left;\n        Node* right;\n        S sum;\n\n      \
    \  static Node* nil() {\n            static Node* nil_node = NULL;\n         \
    \   if (nil_node) return nil_node;\n            nil_node = new Node();\n     \
    \       nil_node->left = nil_node->right = nil_node;\n            return nil_node;\n\
    \        }\n\n        Node() = default;\n        Node(const S& val) : left(nil()),\
    \ right(nil()), sum(val) {}\n        Node(const Node& src) : left(src.left), right(src.right),\
    \ sum(src.sum) {}\n    };\n\n    PersistentSegTree(int _n) : n(_n) {}\n\n    Node*\
    \ create(const vector<S>& a) {\n        assert(SZ(a) == n);\n        return _create(a,\
    \ 0, SZ(a));\n    }\n\n    // product a[u, v)\n    S prod(Node* p, int u, int\
    \ v) {\n        assert(0 <= u && u <= v && v <= n);\n        return _prod(p, 0,\
    \ n, u, v);\n    }\n\n    // set a[u] = val. Returns new version\n    Node* set(Node*\
    \ p, int u, S val) {\n        assert(0 <= u && u < n);\n        return _set(p,\
    \ 0, n, u, val);\n    }\n\n// private:\n    int n;\n\n    // create segtre from\
    \ a[l, r)\n    Node* _create(const vector<S>& a, int l, int r) {\n        if (l\
    \ >= r) return Node::nil();\n        if (l == r - 1) {\n            return new\
    \ Node(a[l]);\n        }\n\n        int mid = (l + r) / 2;\n        Node* res\
    \ = new Node();\n        res->left = _create(a, l, mid);\n        res->right =\
    \ _create(a, mid, r);\n        res->sum = op(res->left->sum, res->right->sum);\n\
    \        return res;\n    }\n\n    // p maintains [l, r)\n    // query [u, v)\n\
    \    int _prod(Node* p, int l, int r, int u, int v) {\n        if (v <= l || r\
    \ <= u) return 0;  // do not intersect\n        if (u <= l && r <= v) return p->sum;\n\
    \n        int mid = (l + r) / 2;\n        return op(\n            _prod(p->left,\
    \ l, mid, u, v),\n            _prod(p->right, mid, r, u, v)\n        );\n    }\n\
    \n    // p maintains [l, r)\n    Node* _set(Node* p, int l, int r, int u, int\
    \ val) {\n        if (u < l || r <= u) return p;\n        if (l == r-1) {\n  \
    \          return new Node(val);\n        }\n\n        int mid = (l + r) / 2;\n\
    \        Node* res = new Node();\n        res->left = _set(p->left, l, mid, u,\
    \ val);\n        res->right = _set(p->right, mid, r, u, val);\n        res->sum\
    \ = op(res->left->sum, res->right->sum);\n        return res;\n    }\n};\n\n/*\
    \ Example\nint op(int l, int r) { return l + r; }\nint e() { return 0; }\n\nint32_t\
    \ main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n, q; cin >> n >>\
    \ q;\n    vector<int> a(n); for (int& x : a) cin >> x;\n\n    using P = PersistentSegTree<int,\
    \ op, e>;\n    using Node = P::Node;\n    vector<Node*> roots;\n    P p(n);\n\
    \    roots.push_back(p.create(a));\n\n    while (q--) {\n        int typ; cin\
    \ >> typ;\n        if (typ == 1) {\n            int k, pos, x; cin >> k >> pos\
    \ >> x;\n            --k; --pos;\n            roots[k] = p.set(roots[k], pos,\
    \ x);\n        } else if (typ == 2) {\n            int k, l, r; cin >> k >> l\
    \ >> r;\n            --k; --l;\n            cout << p.prod(roots[k], l, r) <<\
    \ '\\n';\n        } else if (typ == 3) {\n            int k; cin >> k;\n     \
    \       --k;\n            roots.push_back(new Node(*roots[k]));\n        } else\
    \ assert(false);\n    }\n    return 0;\n}\n*/\n"
  code: "// Notes:\n// - class PersistentSegTree doesn't store any data.\n//   ->\
    \ Need to store seg tree roots separately.\n// - assume all versions have same\
    \ size (it isn't really necessary, but makes interface nicer)\n//\n// Tested:\n\
    // - https://cses.fi/problemset/task/1737\n// - https://oj.vnoi.info/problem/vquery\n\
    template<\n    class S,         // node aggregate data\n    S (*op) (S, S),  //\
    \ combine 2 nodes\n    S (*e) ()        // aggregate data of empty node\n> struct\
    \ PersistentSegTree {\n    struct Node {\n        Node* left;\n        Node* right;\n\
    \        S sum;\n\n        static Node* nil() {\n            static Node* nil_node\
    \ = NULL;\n            if (nil_node) return nil_node;\n            nil_node =\
    \ new Node();\n            nil_node->left = nil_node->right = nil_node;\n    \
    \        return nil_node;\n        }\n\n        Node() = default;\n        Node(const\
    \ S& val) : left(nil()), right(nil()), sum(val) {}\n        Node(const Node& src)\
    \ : left(src.left), right(src.right), sum(src.sum) {}\n    };\n\n    PersistentSegTree(int\
    \ _n) : n(_n) {}\n\n    Node* create(const vector<S>& a) {\n        assert(SZ(a)\
    \ == n);\n        return _create(a, 0, SZ(a));\n    }\n\n    // product a[u, v)\n\
    \    S prod(Node* p, int u, int v) {\n        assert(0 <= u && u <= v && v <=\
    \ n);\n        return _prod(p, 0, n, u, v);\n    }\n\n    // set a[u] = val. Returns\
    \ new version\n    Node* set(Node* p, int u, S val) {\n        assert(0 <= u &&\
    \ u < n);\n        return _set(p, 0, n, u, val);\n    }\n\n// private:\n    int\
    \ n;\n\n    // create segtre from a[l, r)\n    Node* _create(const vector<S>&\
    \ a, int l, int r) {\n        if (l >= r) return Node::nil();\n        if (l ==\
    \ r - 1) {\n            return new Node(a[l]);\n        }\n\n        int mid =\
    \ (l + r) / 2;\n        Node* res = new Node();\n        res->left = _create(a,\
    \ l, mid);\n        res->right = _create(a, mid, r);\n        res->sum = op(res->left->sum,\
    \ res->right->sum);\n        return res;\n    }\n\n    // p maintains [l, r)\n\
    \    // query [u, v)\n    int _prod(Node* p, int l, int r, int u, int v) {\n \
    \       if (v <= l || r <= u) return 0;  // do not intersect\n        if (u <=\
    \ l && r <= v) return p->sum;\n\n        int mid = (l + r) / 2;\n        return\
    \ op(\n            _prod(p->left, l, mid, u, v),\n            _prod(p->right,\
    \ mid, r, u, v)\n        );\n    }\n\n    // p maintains [l, r)\n    Node* _set(Node*\
    \ p, int l, int r, int u, int val) {\n        if (u < l || r <= u) return p;\n\
    \        if (l == r-1) {\n            return new Node(val);\n        }\n\n   \
    \     int mid = (l + r) / 2;\n        Node* res = new Node();\n        res->left\
    \ = _set(p->left, l, mid, u, val);\n        res->right = _set(p->right, mid, r,\
    \ u, val);\n        res->sum = op(res->left->sum, res->right->sum);\n        return\
    \ res;\n    }\n};\n\n/* Example\nint op(int l, int r) { return l + r; }\nint e()\
    \ { return 0; }\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n, q; cin >> n >> q;\n    vector<int> a(n); for (int& x : a) cin >> x;\n\
    \n    using P = PersistentSegTree<int, op, e>;\n    using Node = P::Node;\n  \
    \  vector<Node*> roots;\n    P p(n);\n    roots.push_back(p.create(a));\n\n  \
    \  while (q--) {\n        int typ; cin >> typ;\n        if (typ == 1) {\n    \
    \        int k, pos, x; cin >> k >> pos >> x;\n            --k; --pos;\n     \
    \       roots[k] = p.set(roots[k], pos, x);\n        } else if (typ == 2) {\n\
    \            int k, l, r; cin >> k >> l >> r;\n            --k; --l;\n       \
    \     cout << p.prod(roots[k], l, r) << '\\n';\n        } else if (typ == 3) {\n\
    \            int k; cin >> k;\n            --k;\n            roots.push_back(new\
    \ Node(*roots[k]));\n        } else assert(false);\n    }\n    return 0;\n}\n\
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PersistentSegTree.h
  requiredBy: []
  timestamp: '2022-01-09 17:21:15+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/PersistentSegTree.h
layout: document
redirect_from:
- /library/DataStructure/PersistentSegTree.h
- /library/DataStructure/PersistentSegTree.h.html
title: DataStructure/PersistentSegTree.h
---
