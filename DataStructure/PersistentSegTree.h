// Notes:
// - class PersistentSegTree doesn't store any data.
//   -> Need to store seg tree roots separately.
// - assume all versions have same size (it isn't really necessary, but makes interface nicer)
//
// Tested:
// - https://cses.fi/problemset/task/1737
// - https://oj.vnoi.info/problem/vquery
template<
    class S,         // node aggregate data
    S (*op) (S, S),  // combine 2 nodes
    S (*e) ()        // aggregate data of empty node
> struct PersistentSegTree {
    struct Node {
        Node* left;
        Node* right;
        S sum;

        static Node* nil() {
            static Node* nil_node = NULL;
            if (nil_node) return nil_node;
            nil_node = new Node();
            nil_node->left = nil_node->right = nil_node;
            return nil_node;
        }

        Node() = default;
        Node(const S& val) : left(nil()), right(nil()), sum(val) {}
        Node(const Node& src) : left(src.left), right(src.right), sum(src.sum) {}
    };

    PersistentSegTree(int _n) : n(_n) {}

    Node* create(const vector<S>& a) {
        assert(SZ(a) == n);
        return _create(a, 0, SZ(a));
    }

    // product a[u, v)
    S prod(Node* p, int u, int v) {
        assert(0 <= u && u <= v && v <= n);
        return _prod(p, 0, n, u, v);
    }

    // set a[u] = val. Returns new version
    Node* set(Node* p, int u, S val) {
        assert(0 <= u && u < n);
        return _set(p, 0, n, u, val);
    }

// private:
    int n;

    // create segtre from a[l, r)
    Node* _create(const vector<S>& a, int l, int r) {
        if (l >= r) return Node::nil();
        if (l == r - 1) {
            return new Node(a[l]);
        }

        int mid = (l + r) / 2;
        Node* res = new Node();
        res->left = _create(a, l, mid);
        res->right = _create(a, mid, r);
        res->sum = op(res->left->sum, res->right->sum);
        return res;
    }

    // p maintains [l, r)
    // query [u, v)
    int _prod(Node* p, int l, int r, int u, int v) {
        if (v <= l || r <= u) return 0;  // do not intersect
        if (u <= l && r <= v) return p->sum;

        int mid = (l + r) / 2;
        return op(
            _prod(p->left, l, mid, u, v),
            _prod(p->right, mid, r, u, v)
        );
    }

    // p maintains [l, r)
    Node* _set(Node* p, int l, int r, int u, int val) {
        if (u < l || r <= u) return p;
        if (l == r-1) {
            return new Node(val);
        }

        int mid = (l + r) / 2;
        Node* res = new Node();
        res->left = _set(p->left, l, mid, u, val);
        res->right = _set(p->right, mid, r, u, val);
        res->sum = op(res->left->sum, res->right->sum);
        return res;
    }
};

/* Example
int op(int l, int r) { return l + r; }
int e() { return 0; }

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n); for (int& x : a) cin >> x;

    using P = PersistentSegTree<int, op, e>;
    using Node = P::Node;
    vector<Node*> roots;
    P p(n);
    roots.push_back(p.create(a));

    while (q--) {
        int typ; cin >> typ;
        if (typ == 1) {
            int k, pos, x; cin >> k >> pos >> x;
            --k; --pos;
            roots[k] = p.set(roots[k], pos, x);
        } else if (typ == 2) {
            int k, l, r; cin >> k >> l >> r;
            --k; --l;
            cout << p.prod(roots[k], l, r) << '\n';
        } else if (typ == 3) {
            int k; cin >> k;
            --k;
            roots.push_back(new Node(*roots[k]));
        } else assert(false);
    }
    return 0;
}
*/
