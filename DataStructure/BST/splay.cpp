#include <iostream>
using namespace std;

struct Node {
    Node *child[2], *father;
    int size, key;
} *root, *nil;

int initTree() { // Must be called at the start of program
    nil = new Node;
    nil->child[0] = nil->child[1] = nil->father = nil;
    nil->size = nil->key = 0;
    return 0;
}
int ensureInit = initTree();

// For updating node's value based on children (sum, min, max...)
void update(Node *x) {
    if (x == nil) return ;
    x->size = x->child[0]->size + x->child[1]->size + 1;
}

// For pushing down lazy update values
void refine(Node *x) {
    if (x == nil) return ;
}

void print(Node *x) {
    if (x == nil) return;
    refine(x);
    print(x->child[0]);
    cout << x->key << ' ';
    print(x->child[1]);
}

Node *createNode(int key) {
    Node * tmp = new Node();
    tmp->child[0] = tmp->child[1] = tmp->father = nil;
    tmp->key = key;
    tmp->size = 1;
    return tmp;
}

void setChild(Node *x, Node *y, int d) {
    x->child[d] = y;
    y->father = x;
}

int getDirection(Node *x, Node *y) {
    return x->child[0] == y ? 0 : 1;
}

void rotate(Node *x, int d) {
    Node *y = x->father;
    Node *z = x->child[d];
    setChild(x, z->child[d ^ 1], d);
    setChild(y, z, getDirection(y, x));
    setChild(z, x, d ^ 1);
    update(x);
    update(z);
}

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

Node *access2(Node *p, int k) {
    refine(p);
    if (k <= p->child[0]->size) return access2(p->child[0], k);
    k -= p->child[0]->size + 1;
    if (!k) return p;
    return access2(p->child[1], k);
}

Node *access(Node * &root, int k) {
    Node *res = access2(root, k);
    splay(res);
    root = res;
    return root;
}

Node *join(Node *x, Node *y) {
    if (x == nil) return y;
    while (1) {
        refine(x);
        if (x->child[1] == nil) break;
        x = x->child[1];
    }
    splay(x);
    setChild(x, y, 1);
    update(x);
    return x;
}

// Note: If cut by position, really careful to return nil if empty
void cut(Node *x, Node * &t1, Node * &t2) {
    t1 = splay(x);
    t2 = t1->child[1];
    t2->father = t1->child[1] = nil;
    update(t1);
}

// t1 = (1 --> k); t2 = (k+1 --> size)
void cut(Node * &root, Node * &t1, Node * &t2, int k) {
    if (k == 0) {
        t1 = nil;
        t2 = root;
    } else if (k == root->size) {
        t1 = root;
        t2 = nil;
    } else {
        Node *x = access(root, k);
        cut(x, t1, t2);
    }
}

Node *create(int from, int to) {
    if (from > to) return nil;

    int mid = (from + to) >> 1;
    Node *p = createNode(mid);
    Node *left = create(from, mid - 1);
    Node *right = create(mid + 1, to);

    if (left != nil) setChild(p, left, 0);
    if (right != nil) setChild(p, right, 1);
    update(p);
    return p;
}

// NOTE: If we get access to pointer of some node & want to move it up,
// need to carefully lazy update the parents. HOW???

int main() {
}
