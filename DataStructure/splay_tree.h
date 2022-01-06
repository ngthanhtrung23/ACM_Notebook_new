// SplayTreeById
//
// Note:
// - op() must be commutative, otherwise reverse queries won't work.
//   To fix it, need to store aggregate data from right->left
//   See https://judge.yosupo.jp/submission/53778 (and look at invsum)
//
// Tested:
// - (cut, join)      https://vn.spoj.com/problems/CARDS/
// - (keys, reverse)  https://oj.vnoi.info/problem/twist
// - (insert, prod)   https://oj.vnoi.info/problem/qmax3vn
// - (insert, delete) https://vn.spoj.com/problems/QMAX4/
// - (insert, delete) https://vn.spoj.com/problems/CARDSHUF/
// - (lazy)           https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
// - (lazy)           https://oj.vnoi.info/problem/upit
template<class K, class S, class F>
struct node_t {
    using Node = node_t<K, S, F>;

    std::array<Node*, 2> child;
    Node *father;
    int size;
    
    // Whether we will need to reverse this subtree.
    // Handling reverse operations requires some specialized code,
    // so I couldn't put this in F
    bool reverse;

    K key;
    S data;
    F lazy;
};
template<
    class K,                               // key
    class S,                               // node aggregate data
    S (*op) (S, K, S),                     // for recomputing data of a node
    pair<K, S> (*e) (),                    // identity data
    class F,                               // lazy propagation tag
    pair<K, S> (*mapping) (F, node_t<K, S, F>*),  // apply tag F on a node
    F (*composition) (F, F),               // combine 2 tags
    F (*id)()                              // identity tag
>
struct SplayTreeById {
    using Node = node_t<K, S, F>;

    Node *nil, *root;

    SplayTreeById() {
        initNil();
        root = nil;
    }
    SplayTreeById(const vector<K>& keys) {
        initNil();
        root = createNode(keys, 0, (int) keys.size());
    }

    vector<K> getKeys() {
        vector<K> keys;
        traverse(root, keys);
        return keys;
    }

    // k in [0, n-1]
    Node* kth(int k) {
        auto res = _kth(root, k);
        splay(res);
        root = res;
        return res;
    }

    // Return <L, R>:
    // - L contains [0, k-1]
    // - R contains [k, N-1]
    // Modify tree
    pair<Node*, Node*> cut(int k) {
        if (k == 0) {
            return {nil, root};
        } else if (k == root->size) {
            return {root, nil};
        } else {
            Node *left = kth(k - 1);  // kth already splayed
            Node* right = left->child[1];
            left->child[1] = right->father = nil;
            pushUp(left);
            return {left, right};
        }
    }

    // Return <X, Y, Z>:
    // - X contains [0, u-1]
    // - Y contains [u, v-1]
    // - Z contains [v, N-1]
    // This is useful for queries on [u, v-1]
    // Modify tree
    tuple<Node*, Node*, Node*> cut(int u, int v) {
        auto [xy, z] = cut(v);
        root = xy;
        auto [x, y] = cut(u);
        return {x, y, z};
    }

    // Make this tree x + y
    void join(Node *x, Node *y) {
        if (x == nil) {
            root = y;
            return;
        }
        while (1) {
            pushDown(x);
            if (x->child[1] == nil) break;
            x = x->child[1];
        }
        splay(x);
        setChild(x, y, 1);
        pushUp(x);
        root = x;
    }

    // reverse range [u, v-1]
    void reverse(int u, int v) {
        assert(0 <= u && u <= v && v <= root->size);
        if (u == v) return;

        auto [x, y, z] = cut(u, v);
        y->reverse = true;
        join(x, y);
        join(root, z);
    }

    // apply F on range [u, v-1]
    void apply(int u, int v, const F& f) {
        assert(0 <= u && u <= v && v <= root->size);
        if (u == v) return;

        auto [x, y, z] = cut(u, v);
        y->lazy = composition(f, y->lazy);
        std::tie(y->key, y->data) = mapping(f, y);

        join(x, y);
        join(root, z);
    }

    // Insert before pos
    // pos in [0, N]
    void insert(int pos, K key) {
        assert(0 <= pos && pos <= root->size);
        // x: [0, pos-1]
        // y: [pos, N-1]
        auto [x, y] = cut(pos);
        auto node = createNode(key);
        setChild(node, x, 0);
        setChild(node, y, 1);
        pushUp(node);
        root = node;
    }

    // Delete pos; pos in [0, N-1]
    K erase(int pos) {
        assert(0 <= pos && pos < root->size);

        // x = [0, pos-1]
        // y = [pos, pos]
        // z = [pos+1, N-1]
        auto [x, y, z] = cut(pos, pos+1);
        join(x, z);
        return y->key;
    }

    // aggregated data of range [l, r-1]
    S prod(int l, int r) {
        auto [x, y, z] = cut(l, r);
        auto res = y->data;
        join(x, y);
        join(root, z);
        return res;
    }

// private:
    void initNil() {
        nil = new Node();
        nil->child[0] = nil->child[1] = nil->father = nil;
        nil->size = 0;
        nil->reverse = false;
        std::tie(nil->key, nil->data) = e();
        nil->lazy = id();
    }
    void pushUp(Node* x) {
        if (x == nil) return;
        x->size = x->child[0]->size + x->child[1]->size + 1;
        x->data = op(x->child[0]->data, x->key, x->child[1]->data);
    }
    void pushDown(Node* x) {
        if (x == nil) return;

        if (x->reverse) {
            for (auto c : x->child) {
                if (c != nil) {
                    c->reverse ^= 1;
                }
            }
            std::swap(x->child[0], x->child[1]);
            x->reverse = false;
        }

        for (auto c : x->child) {
            if (c != nil) {
                std::tie(c->key, c->data) = mapping(x->lazy, c);
                c->lazy = composition(x->lazy, c->lazy);
            }
            // For problem like UPIT, where we want to push different
            // lazy tags to left & right children, may need to modify
            // code here
            // (query L R X: a(L) += X, a(L+1) += 2X, ...)
            // e.g. for UPIT:
            // x->lazy.add_left += (1 + c->size) * x->lazy.step;
        }

        x->lazy = id();
    }
    Node* createNode(K key) {
        Node *res = new Node();
        res->child[0] = res->child[1] = res->father = nil;
        res->key = key;
        res->size = 1;
        res->data = e().second;
        res->lazy = id();
        return res;
    }
    void setChild(Node *x, Node *y, int d) {
        x->child[d] = y;
        if (y != nil) y->father = x;
    }
    // Assumption: x is father of y
    int getDirection(Node *x, Node *y) {
        assert(y->father == x);
        return x->child[0] == y ? 0 : 1;
    }
    // create subtree from keys[l, r-1]
    Node* createNode(const vector<K>& keys, int l, int r) {
        if (l >= r) {  // empty
            return nil;
        }
        int mid = (l + r) / 2;
        Node *p = createNode(keys[mid]);
        Node *left = createNode(keys, l, mid);
        Node *right = createNode(keys, mid + 1, r);

        setChild(p, left, 0);
        setChild(p, right, 1);

        pushUp(p);
        return p;
    }
    void traverse(Node* x, vector<K>& keys) {
        if (x == nil) return;
        pushDown(x);
        traverse(x->child[0], keys);
        keys.push_back(x->key);
        traverse(x->child[1], keys);
    }
    /**
     * Before:
     *    y
     *    |
     *    x
     *  /
     * z
     *  \
     *  zchild
     *
     * After:
     *    y
     *    |
     *    z
     *     \
     *      x
     *     /
     *  zchild
     */
    void rotate(Node *x, int d) {
        Node *y = x->father;
        Node *z = x->child[d];
        setChild(x, z->child[d ^ 1], d);
        setChild(y, z, getDirection(y, x));
        setChild(z, x, d ^ 1);
        pushUp(x);
        pushUp(z);
    }
    // Make x root of tree
    Node *splay(Node *x) {
        if (x == nil) return nil;
        while (x->father != nil) {
            Node *y = x->father;
            Node *z = y->father;
            int dy = getDirection(y, x);
            int dz = getDirection(z, y);
            if (z == nil) {
                rotate(y, dy);
            } else if (dy == dz) {
                rotate(z, dz);
                rotate(y, dy);
            } else {
                rotate(y, dy);
                rotate(z, dz);
            }
        }
        return x;
    }

    Node* _kth(Node* p, int k) {
        pushDown(p);
        // left: [0, left->size - 1]
        if (k < p->child[0]->size) {
            return _kth(p->child[0], k);
        }
        k -= p->child[0]->size;
        if (!k) return p;
        return _kth(p->child[1], k - 1);
    }
};

////////// Below: example usage
// Splay tree only need to store keys (no aggregated value / no lazy update)
struct KeyOnlyOps {
    struct S{};
    struct F{};
    using Node = node_t<int, S, F>;
    
    static S op(__attribute__((unused)) S left, __attribute__((unused)) int key, __attribute__((unused)) S right) {
        return {};
    }
    static pair<int, S> e() {
        return {-1, {}};
    }
    static pair<int, S> mapping(__attribute__((unused)) F f, Node* node) {
        return {node->key, {}};
    }
    static F composition(__attribute__((unused)) F f, __attribute__((unused)) F g) {
        return {};
    }
    static F id() {
        return {};
    }
};

/* Example:
    SplayTreeById<
        int,
        KeyOnlyOps::S,
        KeyOnlyOps::op,
        KeyOnlyOps::e,
        KeyOnlyOps::F,
        KeyOnlyOps::mapping,
        KeyOnlyOps::composition,
        KeyOnlyOps::id
    > tree(keys);
 */


// For query get max of keys in range
// No lazy update tags
struct MaxQueryOps {
    static const int INF = 1e9 + 11;
    struct F{};
    using Node = node_t<int, int, F>;

    static int op(const int& left, int key, const int& right) {
        return max({left, key, right});
    }
    static pair<int, int> e() {
        return {-1, -INF};
    }
    static pair<int, int> mapping(__attribute__((unused)) const F& f, Node* node) {
        return {node->key, node->data};
    }
    static F composition(__attribute__((unused)) const F& f, __attribute__((unused)) const F& g) {
        return {};
    }
    static F id() {
        return {};
    }
};
/* Example:
    SplayTreeById<
        int,
        int,
        MaxQueryOps::op,
        MaxQueryOps::e,
        MaxQueryOps::F,
        MaxQueryOps::mapping,
        MaxQueryOps::composition,
        MaxQueryOps::id
    > tree;
 */

// For queries a[i] <- a[i]*mult + add
struct RangeAffineOps {
    struct S {
        long long sum, sz;
    };
    struct F {
        long long a, b;
    };
    using Node = node_t<int, S, F>;

    static const int MOD = 998244353;
    static S op(const S& left, int key, const S& right) {
        return S {
            (left.sum + key + right.sum) % MOD,
            left.sz + 1 + right.sz,
        };
    }
    static pair<int, S> e() {
        return {0, {0, 0}};
    }
    static pair<int, S> mapping(const F& f, Node* node) {
        return {
            (f.a * node->key + f.b) % MOD,
            S {
                (f.a * node->data.sum + f.b * node->data.sz) % MOD,
                node->data.sz,
            }
        };
    }
    static F composition(const F&f, const F& g) {
        return F {
            f.a * g.a % MOD,
            (f.a * g.b + f.b) % MOD,
        };
    }
    static F id() {
        return F {1, 0};
    }
};

/* Example
    SplayTreeById<
        int,
        RangeAffineOps::S,
        RangeAffineOps::op,
        RangeAffineOps::e,
        RangeAffineOps::F,
        RangeAffineOps::mapping,
        RangeAffineOps::composition,
        RangeAffineOps::id
    > tree(keys);
 */
