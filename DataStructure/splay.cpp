#include <iostream>
#include <cassert>
#include <vector>
#include <cstdio>
using namespace std;

struct Node {
    Node * child[2], * parent;
    //int size;
    int sum;
    int key;
} * root, * nil;

void setChild(Node * x, Node * y, int d) {
    x->child[d] = y;
    y->parent = x;
}

int getDirection(Node * x, Node * y) {
    return x->child[0] == y ? 0 : 1;
}

void update(Node * x) {
    if (x == nil) return ;
    //x->size = x->child[0]->size + x->child[1]->size + 1;
    x->sum = x->child[0]->sum + x->child[1]->sum + (x->key >= 0 ? 1 : 0);
}

void rotate(Node * x, int d) {
    Node * y = x->parent;
    Node * z = x->child[d];
    setChild(x, z->child[d ^ 1], d);
    setChild(y, z, getDirection(y, x));
    setChild(z, x, d ^ 1);
    update(x);
    update(z);
}

Node * splay(Node * x) {
    if (x == nil) return nil;
    while (x->parent != nil) {
        Node * y = x->parent;
        Node * z = y->parent;
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

Node * join(Node * x, Node * y) {
    if (x == nil) return y;
    while (x->child[1] != nil) x = x->child[1];
    splay(x);
    setChild(x, y, 1);
    update(x);
    return x;
}

#define left ichigo
#define right nigo
const int N = (int) 1e5 + 1;
vector<int> children[N];
Node * left[N], * right[N];
int n;

Node * createNode(int key) {
    Node * tmp = new Node();
    tmp->child[0] = tmp->child[1] = tmp->parent = nil;
    tmp->key = key;
    tmp->sum = key >= 0 ? 1 : 0;
    //tmp->size = 1;
    return tmp;
}

Node * prev(Node * x) {
    x = splay(x)->child[0];
    while (x->child[1] != nil)
        x = x->child[1];
    return splay(x);
}

void cut(Node * x, Node * &t1, Node * &t2) {
    t1 = splay(x);
    t2 = t1->child[1];
    t2->parent = t1->child[1] = nil;
    update(t1);
}

void dfs(int u) {
    root = join(root, left[u] = createNode(u));
    for (int i = 0; i < (int) children[u].size(); ++i)
        dfs(children[u][i]);
    root = join(root, right[u] = createNode(-1));
}

Node * nodeAt(Node * x, int pos) {
    while (true) {
        if (x->child[0]->sum > pos) {
            x = x->child[0];
        } else if (x->child[0]->sum == pos && x->key >= 0) {
            break;
        } else {
            pos -= x->child[0]->sum + (x->key >= 0 ? 1 : 0);
            x = x->child[1];
        }
    }
    return splay(x);
}

void print(Node * x) {
    if (x == nil) return;
    print(x->child[0]);
    printf("%d ", x->key);
    print(x->child[1]);
}

int main() {
    //assert(freopen("F.in.c", "r", stdin));
    ios::sync_with_stdio(false); cin.tie(NULL);
    int numTests; cin >> numTests;
    for (int testID = 0; testID < numTests; ++testID) {
        int n; cin >> n;
        root = nil = new Node();
        nil->child[0] = nil->child[1] = nil->parent = nil;
        /*nil->size =*/ nil->sum = 0; nil->key = -1;
        for (int i = 0; i <= n; ++i)
            children[i].clear();
        for (int i = 1; i < n; ++i) {
            int x, y; cin >> x >> y;
            children[x].push_back(y);
        }
        children[0].push_back(1);
        dfs(0);
        int numQueries; cin >> numQueries;
        //print(root); printf("\n");
        for (int qID = 0; qID < numQueries; ++qID) {
            int type; cin >> type;
            if (type == 1) {
                int u, v; cin >> u >> v;
                Node * t1, * t2, * t3;
                cut(right[u], t2, t3);
                cut(prev(left[u]), t1, t2);
                root = join(t1, t3);
                cut(prev(right[v]), t1, t3);
                root = join(join(t1, t2), t3);
            } else {
                int pos; cin >> pos;
                int res = (root = nodeAt(root, pos))->key;
                if (res == 0) {
                    cerr << 2 << ' ' << pos << endl;
                }
                printf("%d\n", res);
            }
            //print(root); printf("\n");
        }
    }
    return 0;
}
