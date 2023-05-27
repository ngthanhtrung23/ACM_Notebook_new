---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/splay_tree.test.cpp
    title: DataStructure/test/splay_tree.test.cpp
  - icon: ':x:'
    path: DataStructure/test/yosupo_rangereversesum_splay.test.cpp
    title: DataStructure/test/yosupo_rangereversesum_splay.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    - https://judge.yosupo.jp/submission/53778
    - https://oj.vnoi.info/problem/qmax3vn
    - https://oj.vnoi.info/problem/twist
    - https://oj.vnoi.info/problem/upit
    - https://vn.spoj.com/problems/CARDS/
    - https://vn.spoj.com/problems/CARDSHUF/
    - https://vn.spoj.com/problems/QMAX4/
  bundledCode: "#line 1 \"DataStructure/splay_tree.h\"\n// SplayTreeById\n//\n// Note:\n\
    // - op() must be commutative, otherwise reverse queries won't work.\n//   To\
    \ fix it, need to store aggregate data from right->left\n//   See https://judge.yosupo.jp/submission/53778\
    \ (and look at invsum)\n//\n// Tested:\n// - (cut, join)      https://vn.spoj.com/problems/CARDS/\n\
    // - (keys, reverse)  https://oj.vnoi.info/problem/twist\n// - (insert, prod)\
    \   https://oj.vnoi.info/problem/qmax3vn\n// - (insert, delete) https://vn.spoj.com/problems/QMAX4/\n\
    // - (insert, delete) https://vn.spoj.com/problems/CARDSHUF/\n// - (lazy)    \
    \       https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\n\
    // - (lazy)           https://oj.vnoi.info/problem/upit\ntemplate<class K, class\
    \ S, class F>\nstruct node_t {\n    using Node = node_t<K, S, F>;\n\n    std::array<Node*,\
    \ 2> child;\n    Node *father;\n    int size;\n    \n    // Whether we will need\
    \ to reverse this subtree.\n    // Handling reverse operations requires some specialized\
    \ code,\n    // so I couldn't put this in F\n    bool reverse;\n\n    K key;\n\
    \    S data;\n    F lazy;\n};\ntemplate<\n    class K,                       \
    \        // key\n    class S,                               // node aggregate\
    \ data\n    S (*op) (S, K, S),                     // for recomputing data of\
    \ a node\n    pair<K, S> (*e) (),                    // identity data\n    class\
    \ F,                               // lazy propagation tag\n    pair<K, S> (*mapping)\
    \ (F, node_t<K, S, F>*),  // apply tag F on a node\n    F (*composition) (F, F),\
    \               // combine 2 tags\n    F (*id)()                             \
    \ // identity tag\n>\nstruct SplayTreeById {\n    using Node = node_t<K, S, F>;\n\
    \n    Node *nil, *root;\n\n    SplayTreeById() {\n        initNil();\n       \
    \ root = nil;\n    }\n    SplayTreeById(const vector<K>& keys) {\n        initNil();\n\
    \        root = createNode(keys, 0, (int) keys.size());\n    }\n\n    vector<K>\
    \ getKeys() {\n        vector<K> keys;\n        traverse(root, keys);\n      \
    \  return keys;\n    }\n\n    // k in [0, n-1]\n    Node* kth(int k) {\n     \
    \   auto res = _kth(root, k);\n        splay(res);\n        root = res;\n    \
    \    return res;\n    }\n\n    // Return <L, R>:\n    // - L contains [0, k-1]\n\
    \    // - R contains [k, N-1]\n    // Modify tree\n    pair<Node*, Node*> cut(int\
    \ k) {\n        if (k == 0) {\n            return {nil, root};\n        } else\
    \ if (k == root->size) {\n            return {root, nil};\n        } else {\n\
    \            Node *left = kth(k - 1);  // kth already splayed\n            Node*\
    \ right = left->child[1];\n            left->child[1] = right->father = nil;\n\
    \            pushUp(left);\n            return {left, right};\n        }\n   \
    \ }\n\n    // Return <X, Y, Z>:\n    // - X contains [0, u-1]\n    // - Y contains\
    \ [u, v-1]\n    // - Z contains [v, N-1]\n    // This is useful for queries on\
    \ [u, v-1]\n    // Modify tree\n    tuple<Node*, Node*, Node*> cut(int u, int\
    \ v) {\n        auto [xy, z] = cut(v);\n        root = xy;\n        auto [x, y]\
    \ = cut(u);\n        return {x, y, z};\n    }\n\n    // Make this tree x + y\n\
    \    void join(Node *x, Node *y) {\n        if (x == nil) {\n            root\
    \ = y;\n            return;\n        }\n        while (1) {\n            pushDown(x);\n\
    \            if (x->child[1] == nil) break;\n            x = x->child[1];\n  \
    \      }\n        splay(x);\n        setChild(x, y, 1);\n        pushUp(x);\n\
    \        root = x;\n    }\n\n    // reverse range [u, v-1]\n    void reverse(int\
    \ u, int v) {\n        assert(0 <= u && u <= v && v <= root->size);\n        if\
    \ (u == v) return;\n\n        auto [x, y, z] = cut(u, v);\n        y->reverse\
    \ = true;\n        join(x, y);\n        join(root, z);\n    }\n\n    // apply\
    \ F on range [u, v-1]\n    void apply(int u, int v, const F& f) {\n        assert(0\
    \ <= u && u <= v && v <= root->size);\n        if (u == v) return;\n\n       \
    \ auto [x, y, z] = cut(u, v);\n        y->lazy = composition(f, y->lazy);\n  \
    \      std::tie(y->key, y->data) = mapping(f, y);\n\n        join(x, y);\n   \
    \     join(root, z);\n    }\n\n    // Insert before pos\n    // pos in [0, N]\n\
    \    void insert(int pos, K key) {\n        assert(0 <= pos && pos <= root->size);\n\
    \        // x: [0, pos-1]\n        // y: [pos, N-1]\n        auto [x, y] = cut(pos);\n\
    \        auto node = createNode(key);\n        setChild(node, x, 0);\n       \
    \ setChild(node, y, 1);\n        pushUp(node);\n        root = node;\n    }\n\n\
    \    // Delete pos; pos in [0, N-1]\n    K erase(int pos) {\n        assert(0\
    \ <= pos && pos < root->size);\n\n        // x = [0, pos-1]\n        // y = [pos,\
    \ pos]\n        // z = [pos+1, N-1]\n        auto [x, y, z] = cut(pos, pos+1);\n\
    \        join(x, z);\n        return y->key;\n    }\n\n    // aggregated data\
    \ of range [l, r-1]\n    S prod(int l, int r) {\n        auto [x, y, z] = cut(l,\
    \ r);\n        auto res = y->data;\n        join(x, y);\n        join(root, z);\n\
    \        return res;\n    }\n\n// private:\n    void initNil() {\n        nil\
    \ = new Node();\n        nil->child[0] = nil->child[1] = nil->father = nil;\n\
    \        nil->size = 0;\n        nil->reverse = false;\n        std::tie(nil->key,\
    \ nil->data) = e();\n        nil->lazy = id();\n    }\n    void pushUp(Node* x)\
    \ {\n        if (x == nil) return;\n        x->size = x->child[0]->size + x->child[1]->size\
    \ + 1;\n        x->data = op(x->child[0]->data, x->key, x->child[1]->data);\n\
    \    }\n    void pushDown(Node* x) {\n        if (x == nil) return;\n\n      \
    \  if (x->reverse) {\n            for (auto c : x->child) {\n                if\
    \ (c != nil) {\n                    c->reverse ^= 1;\n                }\n    \
    \        }\n            std::swap(x->child[0], x->child[1]);\n            x->reverse\
    \ = false;\n        }\n\n        for (auto c : x->child) {\n            if (c\
    \ != nil) {\n                std::tie(c->key, c->data) = mapping(x->lazy, c);\n\
    \                c->lazy = composition(x->lazy, c->lazy);\n            }\n   \
    \         // For problem like UPIT, where we want to push different\n        \
    \    // lazy tags to left & right children, may need to modify\n            //\
    \ code here\n            // (query L R X: a(L) += X, a(L+1) += 2X, ...)\n    \
    \        // e.g. for UPIT:\n            // x->lazy.add_left += (1 + c->size) *\
    \ x->lazy.step;\n        }\n\n        x->lazy = id();\n    }\n    Node* createNode(K\
    \ key) {\n        Node *res = new Node();\n        res->child[0] = res->child[1]\
    \ = res->father = nil;\n        res->key = key;\n        res->size = 1;\n    \
    \    res->data = e().second;\n        res->lazy = id();\n        return res;\n\
    \    }\n    void setChild(Node *x, Node *y, int d) {\n        x->child[d] = y;\n\
    \        if (y != nil) y->father = x;\n    }\n    // Assumption: x is father of\
    \ y\n    int getDirection(Node *x, Node *y) {\n        assert(y->father == x);\n\
    \        return x->child[0] == y ? 0 : 1;\n    }\n    // create subtree from keys[l,\
    \ r-1]\n    Node* createNode(const vector<K>& keys, int l, int r) {\n        if\
    \ (l >= r) {  // empty\n            return nil;\n        }\n        int mid =\
    \ (l + r) / 2;\n        Node *p = createNode(keys[mid]);\n        Node *left =\
    \ createNode(keys, l, mid);\n        Node *right = createNode(keys, mid + 1, r);\n\
    \n        setChild(p, left, 0);\n        setChild(p, right, 1);\n\n        pushUp(p);\n\
    \        return p;\n    }\n    void traverse(Node* x, vector<K>& keys) {\n   \
    \     if (x == nil) return;\n        pushDown(x);\n        traverse(x->child[0],\
    \ keys);\n        keys.push_back(x->key);\n        traverse(x->child[1], keys);\n\
    \    }\n    /**\n     * Before:\n     *    y\n     *    |\n     *    x\n     *\
    \  /\n     * z\n     *  \\\n     *  zchild\n     *\n     * After:\n     *    y\n\
    \     *    |\n     *    z\n     *     \\\n     *      x\n     *     /\n     *\
    \  zchild\n     */\n    void rotate(Node *x, int d) {\n        Node *y = x->father;\n\
    \        Node *z = x->child[d];\n        setChild(x, z->child[d ^ 1], d);\n  \
    \      setChild(y, z, getDirection(y, x));\n        setChild(z, x, d ^ 1);\n \
    \       pushUp(x);\n        pushUp(z);\n    }\n    // Make x root of tree\n  \
    \  Node *splay(Node *x) {\n        if (x == nil) return nil;\n        while (x->father\
    \ != nil) {\n            Node *y = x->father;\n            Node *z = y->father;\n\
    \            int dy = getDirection(y, x);\n            int dz = getDirection(z,\
    \ y);\n            if (z == nil) {\n                rotate(y, dy);\n         \
    \   } else if (dy == dz) {\n                rotate(z, dz);\n                rotate(y,\
    \ dy);\n            } else {\n                rotate(y, dy);\n               \
    \ rotate(z, dz);\n            }\n        }\n        return x;\n    }\n\n    Node*\
    \ _kth(Node* p, int k) {\n        pushDown(p);\n        // left: [0, left->size\
    \ - 1]\n        if (k < p->child[0]->size) {\n            return _kth(p->child[0],\
    \ k);\n        }\n        k -= p->child[0]->size;\n        if (!k) return p;\n\
    \        return _kth(p->child[1], k - 1);\n    }\n};\n\n////////// Below: example\
    \ usage\n// Splay tree only need to store keys (no aggregated value / no lazy\
    \ update)\nstruct KeyOnlyOps {\n    struct S{};\n    struct F{};\n    using Node\
    \ = node_t<int, S, F>;\n    \n    static S op(__attribute__((unused)) S left,\
    \ __attribute__((unused)) int key, __attribute__((unused)) S right) {\n      \
    \  return {};\n    }\n    static pair<int, S> e() {\n        return {-1, {}};\n\
    \    }\n    static pair<int, S> mapping(__attribute__((unused)) F f, Node* node)\
    \ {\n        return {node->key, {}};\n    }\n    static F composition(__attribute__((unused))\
    \ F f, __attribute__((unused)) F g) {\n        return {};\n    }\n    static F\
    \ id() {\n        return {};\n    }\n};\n\n/* Example:\n    SplayTreeById<\n \
    \       int,\n        KeyOnlyOps::S,\n        KeyOnlyOps::op,\n        KeyOnlyOps::e,\n\
    \        KeyOnlyOps::F,\n        KeyOnlyOps::mapping,\n        KeyOnlyOps::composition,\n\
    \        KeyOnlyOps::id\n    > tree(keys);\n */\n\n\n// For query get max of keys\
    \ in range\n// No lazy update tags\nstruct MaxQueryOps {\n    static const int\
    \ INF = 1e9 + 11;\n    struct F{};\n    using Node = node_t<int, int, F>;\n\n\
    \    static int op(const int& left, int key, const int& right) {\n        return\
    \ max({left, key, right});\n    }\n    static pair<int, int> e() {\n        return\
    \ {-1, -INF};\n    }\n    static pair<int, int> mapping(__attribute__((unused))\
    \ const F& f, Node* node) {\n        return {node->key, node->data};\n    }\n\
    \    static F composition(__attribute__((unused)) const F& f, __attribute__((unused))\
    \ const F& g) {\n        return {};\n    }\n    static F id() {\n        return\
    \ {};\n    }\n};\n/* Example:\n    SplayTreeById<\n        int,\n        int,\n\
    \        MaxQueryOps::op,\n        MaxQueryOps::e,\n        MaxQueryOps::F,\n\
    \        MaxQueryOps::mapping,\n        MaxQueryOps::composition,\n        MaxQueryOps::id\n\
    \    > tree;\n */\n\n// For queries a[i] <- a[i]*mult + add\nstruct RangeAffineOps\
    \ {\n    struct S {\n        long long sum, sz;\n    };\n    struct F {\n    \
    \    long long a, b;\n    };\n    using Node = node_t<int, S, F>;\n\n    static\
    \ const int MOD = 998244353;\n    static S op(const S& left, int key, const S&\
    \ right) {\n        return S {\n            (left.sum + key + right.sum) % MOD,\n\
    \            left.sz + 1 + right.sz,\n        };\n    }\n    static pair<int,\
    \ S> e() {\n        return {0, {0, 0}};\n    }\n    static pair<int, S> mapping(const\
    \ F& f, Node* node) {\n        return {\n            (f.a * node->key + f.b) %\
    \ MOD,\n            S {\n                (f.a * node->data.sum + f.b * node->data.sz)\
    \ % MOD,\n                node->data.sz,\n            }\n        };\n    }\n \
    \   static F composition(const F&f, const F& g) {\n        return F {\n      \
    \      f.a * g.a % MOD,\n            (f.a * g.b + f.b) % MOD,\n        };\n  \
    \  }\n    static F id() {\n        return F {1, 0};\n    }\n};\n\n/* Example\n\
    \    SplayTreeById<\n        int,\n        RangeAffineOps::S,\n        RangeAffineOps::op,\n\
    \        RangeAffineOps::e,\n        RangeAffineOps::F,\n        RangeAffineOps::mapping,\n\
    \        RangeAffineOps::composition,\n        RangeAffineOps::id\n    > tree(keys);\n\
    \ */\n"
  code: "// SplayTreeById\n//\n// Note:\n// - op() must be commutative, otherwise\
    \ reverse queries won't work.\n//   To fix it, need to store aggregate data from\
    \ right->left\n//   See https://judge.yosupo.jp/submission/53778 (and look at\
    \ invsum)\n//\n// Tested:\n// - (cut, join)      https://vn.spoj.com/problems/CARDS/\n\
    // - (keys, reverse)  https://oj.vnoi.info/problem/twist\n// - (insert, prod)\
    \   https://oj.vnoi.info/problem/qmax3vn\n// - (insert, delete) https://vn.spoj.com/problems/QMAX4/\n\
    // - (insert, delete) https://vn.spoj.com/problems/CARDSHUF/\n// - (lazy)    \
    \       https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\n\
    // - (lazy)           https://oj.vnoi.info/problem/upit\ntemplate<class K, class\
    \ S, class F>\nstruct node_t {\n    using Node = node_t<K, S, F>;\n\n    std::array<Node*,\
    \ 2> child;\n    Node *father;\n    int size;\n    \n    // Whether we will need\
    \ to reverse this subtree.\n    // Handling reverse operations requires some specialized\
    \ code,\n    // so I couldn't put this in F\n    bool reverse;\n\n    K key;\n\
    \    S data;\n    F lazy;\n};\ntemplate<\n    class K,                       \
    \        // key\n    class S,                               // node aggregate\
    \ data\n    S (*op) (S, K, S),                     // for recomputing data of\
    \ a node\n    pair<K, S> (*e) (),                    // identity data\n    class\
    \ F,                               // lazy propagation tag\n    pair<K, S> (*mapping)\
    \ (F, node_t<K, S, F>*),  // apply tag F on a node\n    F (*composition) (F, F),\
    \               // combine 2 tags\n    F (*id)()                             \
    \ // identity tag\n>\nstruct SplayTreeById {\n    using Node = node_t<K, S, F>;\n\
    \n    Node *nil, *root;\n\n    SplayTreeById() {\n        initNil();\n       \
    \ root = nil;\n    }\n    SplayTreeById(const vector<K>& keys) {\n        initNil();\n\
    \        root = createNode(keys, 0, (int) keys.size());\n    }\n\n    vector<K>\
    \ getKeys() {\n        vector<K> keys;\n        traverse(root, keys);\n      \
    \  return keys;\n    }\n\n    // k in [0, n-1]\n    Node* kth(int k) {\n     \
    \   auto res = _kth(root, k);\n        splay(res);\n        root = res;\n    \
    \    return res;\n    }\n\n    // Return <L, R>:\n    // - L contains [0, k-1]\n\
    \    // - R contains [k, N-1]\n    // Modify tree\n    pair<Node*, Node*> cut(int\
    \ k) {\n        if (k == 0) {\n            return {nil, root};\n        } else\
    \ if (k == root->size) {\n            return {root, nil};\n        } else {\n\
    \            Node *left = kth(k - 1);  // kth already splayed\n            Node*\
    \ right = left->child[1];\n            left->child[1] = right->father = nil;\n\
    \            pushUp(left);\n            return {left, right};\n        }\n   \
    \ }\n\n    // Return <X, Y, Z>:\n    // - X contains [0, u-1]\n    // - Y contains\
    \ [u, v-1]\n    // - Z contains [v, N-1]\n    // This is useful for queries on\
    \ [u, v-1]\n    // Modify tree\n    tuple<Node*, Node*, Node*> cut(int u, int\
    \ v) {\n        auto [xy, z] = cut(v);\n        root = xy;\n        auto [x, y]\
    \ = cut(u);\n        return {x, y, z};\n    }\n\n    // Make this tree x + y\n\
    \    void join(Node *x, Node *y) {\n        if (x == nil) {\n            root\
    \ = y;\n            return;\n        }\n        while (1) {\n            pushDown(x);\n\
    \            if (x->child[1] == nil) break;\n            x = x->child[1];\n  \
    \      }\n        splay(x);\n        setChild(x, y, 1);\n        pushUp(x);\n\
    \        root = x;\n    }\n\n    // reverse range [u, v-1]\n    void reverse(int\
    \ u, int v) {\n        assert(0 <= u && u <= v && v <= root->size);\n        if\
    \ (u == v) return;\n\n        auto [x, y, z] = cut(u, v);\n        y->reverse\
    \ = true;\n        join(x, y);\n        join(root, z);\n    }\n\n    // apply\
    \ F on range [u, v-1]\n    void apply(int u, int v, const F& f) {\n        assert(0\
    \ <= u && u <= v && v <= root->size);\n        if (u == v) return;\n\n       \
    \ auto [x, y, z] = cut(u, v);\n        y->lazy = composition(f, y->lazy);\n  \
    \      std::tie(y->key, y->data) = mapping(f, y);\n\n        join(x, y);\n   \
    \     join(root, z);\n    }\n\n    // Insert before pos\n    // pos in [0, N]\n\
    \    void insert(int pos, K key) {\n        assert(0 <= pos && pos <= root->size);\n\
    \        // x: [0, pos-1]\n        // y: [pos, N-1]\n        auto [x, y] = cut(pos);\n\
    \        auto node = createNode(key);\n        setChild(node, x, 0);\n       \
    \ setChild(node, y, 1);\n        pushUp(node);\n        root = node;\n    }\n\n\
    \    // Delete pos; pos in [0, N-1]\n    K erase(int pos) {\n        assert(0\
    \ <= pos && pos < root->size);\n\n        // x = [0, pos-1]\n        // y = [pos,\
    \ pos]\n        // z = [pos+1, N-1]\n        auto [x, y, z] = cut(pos, pos+1);\n\
    \        join(x, z);\n        return y->key;\n    }\n\n    // aggregated data\
    \ of range [l, r-1]\n    S prod(int l, int r) {\n        auto [x, y, z] = cut(l,\
    \ r);\n        auto res = y->data;\n        join(x, y);\n        join(root, z);\n\
    \        return res;\n    }\n\n// private:\n    void initNil() {\n        nil\
    \ = new Node();\n        nil->child[0] = nil->child[1] = nil->father = nil;\n\
    \        nil->size = 0;\n        nil->reverse = false;\n        std::tie(nil->key,\
    \ nil->data) = e();\n        nil->lazy = id();\n    }\n    void pushUp(Node* x)\
    \ {\n        if (x == nil) return;\n        x->size = x->child[0]->size + x->child[1]->size\
    \ + 1;\n        x->data = op(x->child[0]->data, x->key, x->child[1]->data);\n\
    \    }\n    void pushDown(Node* x) {\n        if (x == nil) return;\n\n      \
    \  if (x->reverse) {\n            for (auto c : x->child) {\n                if\
    \ (c != nil) {\n                    c->reverse ^= 1;\n                }\n    \
    \        }\n            std::swap(x->child[0], x->child[1]);\n            x->reverse\
    \ = false;\n        }\n\n        for (auto c : x->child) {\n            if (c\
    \ != nil) {\n                std::tie(c->key, c->data) = mapping(x->lazy, c);\n\
    \                c->lazy = composition(x->lazy, c->lazy);\n            }\n   \
    \         // For problem like UPIT, where we want to push different\n        \
    \    // lazy tags to left & right children, may need to modify\n            //\
    \ code here\n            // (query L R X: a(L) += X, a(L+1) += 2X, ...)\n    \
    \        // e.g. for UPIT:\n            // x->lazy.add_left += (1 + c->size) *\
    \ x->lazy.step;\n        }\n\n        x->lazy = id();\n    }\n    Node* createNode(K\
    \ key) {\n        Node *res = new Node();\n        res->child[0] = res->child[1]\
    \ = res->father = nil;\n        res->key = key;\n        res->size = 1;\n    \
    \    res->data = e().second;\n        res->lazy = id();\n        return res;\n\
    \    }\n    void setChild(Node *x, Node *y, int d) {\n        x->child[d] = y;\n\
    \        if (y != nil) y->father = x;\n    }\n    // Assumption: x is father of\
    \ y\n    int getDirection(Node *x, Node *y) {\n        assert(y->father == x);\n\
    \        return x->child[0] == y ? 0 : 1;\n    }\n    // create subtree from keys[l,\
    \ r-1]\n    Node* createNode(const vector<K>& keys, int l, int r) {\n        if\
    \ (l >= r) {  // empty\n            return nil;\n        }\n        int mid =\
    \ (l + r) / 2;\n        Node *p = createNode(keys[mid]);\n        Node *left =\
    \ createNode(keys, l, mid);\n        Node *right = createNode(keys, mid + 1, r);\n\
    \n        setChild(p, left, 0);\n        setChild(p, right, 1);\n\n        pushUp(p);\n\
    \        return p;\n    }\n    void traverse(Node* x, vector<K>& keys) {\n   \
    \     if (x == nil) return;\n        pushDown(x);\n        traverse(x->child[0],\
    \ keys);\n        keys.push_back(x->key);\n        traverse(x->child[1], keys);\n\
    \    }\n    /**\n     * Before:\n     *    y\n     *    |\n     *    x\n     *\
    \  /\n     * z\n     *  \\\n     *  zchild\n     *\n     * After:\n     *    y\n\
    \     *    |\n     *    z\n     *     \\\n     *      x\n     *     /\n     *\
    \  zchild\n     */\n    void rotate(Node *x, int d) {\n        Node *y = x->father;\n\
    \        Node *z = x->child[d];\n        setChild(x, z->child[d ^ 1], d);\n  \
    \      setChild(y, z, getDirection(y, x));\n        setChild(z, x, d ^ 1);\n \
    \       pushUp(x);\n        pushUp(z);\n    }\n    // Make x root of tree\n  \
    \  Node *splay(Node *x) {\n        if (x == nil) return nil;\n        while (x->father\
    \ != nil) {\n            Node *y = x->father;\n            Node *z = y->father;\n\
    \            int dy = getDirection(y, x);\n            int dz = getDirection(z,\
    \ y);\n            if (z == nil) {\n                rotate(y, dy);\n         \
    \   } else if (dy == dz) {\n                rotate(z, dz);\n                rotate(y,\
    \ dy);\n            } else {\n                rotate(y, dy);\n               \
    \ rotate(z, dz);\n            }\n        }\n        return x;\n    }\n\n    Node*\
    \ _kth(Node* p, int k) {\n        pushDown(p);\n        // left: [0, left->size\
    \ - 1]\n        if (k < p->child[0]->size) {\n            return _kth(p->child[0],\
    \ k);\n        }\n        k -= p->child[0]->size;\n        if (!k) return p;\n\
    \        return _kth(p->child[1], k - 1);\n    }\n};\n\n////////// Below: example\
    \ usage\n// Splay tree only need to store keys (no aggregated value / no lazy\
    \ update)\nstruct KeyOnlyOps {\n    struct S{};\n    struct F{};\n    using Node\
    \ = node_t<int, S, F>;\n    \n    static S op(__attribute__((unused)) S left,\
    \ __attribute__((unused)) int key, __attribute__((unused)) S right) {\n      \
    \  return {};\n    }\n    static pair<int, S> e() {\n        return {-1, {}};\n\
    \    }\n    static pair<int, S> mapping(__attribute__((unused)) F f, Node* node)\
    \ {\n        return {node->key, {}};\n    }\n    static F composition(__attribute__((unused))\
    \ F f, __attribute__((unused)) F g) {\n        return {};\n    }\n    static F\
    \ id() {\n        return {};\n    }\n};\n\n/* Example:\n    SplayTreeById<\n \
    \       int,\n        KeyOnlyOps::S,\n        KeyOnlyOps::op,\n        KeyOnlyOps::e,\n\
    \        KeyOnlyOps::F,\n        KeyOnlyOps::mapping,\n        KeyOnlyOps::composition,\n\
    \        KeyOnlyOps::id\n    > tree(keys);\n */\n\n\n// For query get max of keys\
    \ in range\n// No lazy update tags\nstruct MaxQueryOps {\n    static const int\
    \ INF = 1e9 + 11;\n    struct F{};\n    using Node = node_t<int, int, F>;\n\n\
    \    static int op(const int& left, int key, const int& right) {\n        return\
    \ max({left, key, right});\n    }\n    static pair<int, int> e() {\n        return\
    \ {-1, -INF};\n    }\n    static pair<int, int> mapping(__attribute__((unused))\
    \ const F& f, Node* node) {\n        return {node->key, node->data};\n    }\n\
    \    static F composition(__attribute__((unused)) const F& f, __attribute__((unused))\
    \ const F& g) {\n        return {};\n    }\n    static F id() {\n        return\
    \ {};\n    }\n};\n/* Example:\n    SplayTreeById<\n        int,\n        int,\n\
    \        MaxQueryOps::op,\n        MaxQueryOps::e,\n        MaxQueryOps::F,\n\
    \        MaxQueryOps::mapping,\n        MaxQueryOps::composition,\n        MaxQueryOps::id\n\
    \    > tree;\n */\n\n// For queries a[i] <- a[i]*mult + add\nstruct RangeAffineOps\
    \ {\n    struct S {\n        long long sum, sz;\n    };\n    struct F {\n    \
    \    long long a, b;\n    };\n    using Node = node_t<int, S, F>;\n\n    static\
    \ const int MOD = 998244353;\n    static S op(const S& left, int key, const S&\
    \ right) {\n        return S {\n            (left.sum + key + right.sum) % MOD,\n\
    \            left.sz + 1 + right.sz,\n        };\n    }\n    static pair<int,\
    \ S> e() {\n        return {0, {0, 0}};\n    }\n    static pair<int, S> mapping(const\
    \ F& f, Node* node) {\n        return {\n            (f.a * node->key + f.b) %\
    \ MOD,\n            S {\n                (f.a * node->data.sum + f.b * node->data.sz)\
    \ % MOD,\n                node->data.sz,\n            }\n        };\n    }\n \
    \   static F composition(const F&f, const F& g) {\n        return F {\n      \
    \      f.a * g.a % MOD,\n            (f.a * g.b + f.b) % MOD,\n        };\n  \
    \  }\n    static F id() {\n        return F {1, 0};\n    }\n};\n\n/* Example\n\
    \    SplayTreeById<\n        int,\n        RangeAffineOps::S,\n        RangeAffineOps::op,\n\
    \        RangeAffineOps::e,\n        RangeAffineOps::F,\n        RangeAffineOps::mapping,\n\
    \        RangeAffineOps::composition,\n        RangeAffineOps::id\n    > tree(keys);\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/splay_tree.h
  requiredBy: []
  timestamp: '2022-01-07 04:26:13+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - DataStructure/test/splay_tree.test.cpp
  - DataStructure/test/yosupo_rangereversesum_splay.test.cpp
documentation_of: DataStructure/splay_tree.h
layout: document
redirect_from:
- /library/DataStructure/splay_tree.h
- /library/DataStructure/splay_tree.h.html
title: DataStructure/splay_tree.h
---
