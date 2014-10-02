struct Node {
    Node *left, *right, *father;
    int size, key, sum;
} *root, *sentinel;
// Must call initTree before using splay tree
void initTree() {
    sentinel = new Node;
    sentinel -> left = sentinel -> right = sentinel -> father = sentinel;
    sentinel -> size = 0;
    sentinel -> key = sentinel -> sum = 0;
}
void setLink(Node *x, Node *y, bool left) {
    if (left) x -> left = y;
    else x -> right = y;
    y -> father = x;
}
void update(Node *x) {
    x -> size = x -> left -> size + x -> right -> size + 1;
    x -> sum = x->key + x->left->sum + x->right->sum;
}
void upTree(Node *x) {
    Node *y = x -> father;
    Node *z = y -> father;
    Node *tmp;
    if (y->right == x) {
        tmp = x -> left;
        setLink(x, y, true);
        setLink(y, tmp, false);
    }
    else {
        tmp = x -> right;
        setLink(x, y, false);
        setLink(y, tmp, true);
    }
    setLink(z, x, z->left == y);
    update(y); update(x);
}
void splay(Node *x) {
    while (1) {
        Node *y = x -> father;
        if (y == sentinel) return ;
        Node *z = y -> father;
        if (z != sentinel)
            if ((z->right == y) == (y->right == x)) upTree(y);
            else upTree(x);
        upTree(x);
    }
}
Node *access2(Node *p, int k) {
    refine(p); // Need for cover range
    if (k <= p->left->size) return access2(p->left, k);
    k -= p->left->size + 1;
    if (!k) return p;
    return access2(p->right, k);
}
Node *access(Node * &root, int k) {
    Node *res = access2(root, k);
    splay(res);
    root = res;
    return res;
}
// Split Node 1..k-1 to tree t1 and Node k..size to tree t2
void split(Node *r, Node * &t1, Node * &t2, int k) {
    if (k == 1) {
        t1 = sentinel;
        t2 = r;
        return ;
    } else if (k == r->size + 1) {
        t1 = r;
        t2 = sentinel;
        return ;
    }
    Node *p = access(r, k);
    t1 = p->left;
    t2 = p;
    t1 -> father = t2 -> left = sentinel;
    update(t2);
}
Node *join(Node *t1, Node *t2) {
    if (t1 == sentinel) return t2;
    if (t2 == sentinel) return t1;
    while (1) {
        refine(t1); // Used for range cover
        if (t1 -> right == sentinel) break;
        t1 = t1 -> right;
    }
    splay(t1);
    setLink(t1, t2, false);
    update(t1);
    return t1;
}
void insert(Node * &r, int k, int x) { // insert x at kth position
    Node *p = new Node;
    p->size = 1;
    p->key = p->sum = x;
    p->left = p->right = p->father = sentinel;
    Node *t1, *t2;
    split(r, t1, t2, k);
    r = join(t1, p);
    r = join(r, t2);
}
void del(Node * &r, int k) { // delete kth position
    r = access(r, k);
    Node *t1 = r->left, *t2 = r->right;
    delete r;
    t1->father = sentinel;
    t2->father = sentinel;
    r = join(t1, t2);
}
void cover(Node *root, int l, int r, int u, int v, ll val) {
    if (root == sentinel) return ;
    if (l > r) return ;
    if (v < l || r < u) return ;
    if (u <= l && r <= v) {
        setValue(root, val);
        return ;
    }
    refine(root);
    int mid = l + root->left->size;
    if (u <= mid && mid <= v) root -> key = val;
    cover(root->left, l, mid-1, u, v, val);
    cover(root->right, mid+1, r, u, v, val);
    root->sum = root->left->sum + root->right->sum + root->key;
}