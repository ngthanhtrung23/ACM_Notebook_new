// Tested:
// - https://open.kattis.com/problems/stringmultimatching
// Linked list
struct Node {
    int x; Node *next;
} *nil;
struct List {
    Node *first, *last;
    List() { first = last = nil; }
    void add(int x) {
        Node *p = new Node;
        p->x = x; p->next = nil;
        if (first == nil) last = first = p;
        else last->next = p, last = p;
    }
};
// End of linked list
struct Aho {
    int qu[MN], suffixLink[MN];
    List leaf[MN];
    int link[MN][MC];
    int sz;

    void init() {
        sz = 0;
        memset(suffixLink, 0, sizeof suffixLink);
        leaf[0] = List();
        memset(link[0], -1, sizeof link[0]);
    }
    int getChild(int type, int v, int c) {
        while (1) {
            if (link[v][c] >= 0) return link[v][c];
            if (type == 1) return 0;
            if (!v) return 0;
            v = suffixLink[v];
        }
    }
    void buildLink() {
        int first, last;
        qu[first = last = 1] = 0;
        while (first <= last) {
            int u = qu[first++];
            REP(c,MC) {
                int v = link[u][c]; if (v < 0) continue;
                qu[++last] = v;
                if (u == 0) suffixLink[v] = 0;
                else suffixLink[v] = getChild(2, suffixLink[u], c);

                if (leaf[suffixLink[v]].first != nil) {
                    if (leaf[v].first == nil) {
                        leaf[v].first = leaf[suffixLink[v]].first;
                        leaf[v].last = leaf[suffixLink[v]].last;
                    }
                    else {
                        leaf[v].last->next = leaf[suffixLink[v]].first;
                        leaf[v].last = leaf[suffixLink[v]].last;
                    }
                }
            }
        }
    }
} aho;
// Usage:
aho.init(); // Initialize
// Foreach query, insert one character at a time:
            int p = 0;
            while (k--) {
                int x; scanf("%d", &x);
                int t = aho.getChild(1, p, x);
                if (t > 0) p = t;
                else {
                    ++aho.sz;
                    aho.leaf[aho.sz] = List();
                    memset(aho.link[aho.sz], -1, sizeof aho.link[aho.sz]);

                    aho.link[p][x] = aho.sz;
                    p = aho.sz;
                }
            }
            aho.leaf[p].add(i);
// Init back link
        aho.buildLink();
// After this stage, we should use aho.getChild(2, node, c) to jump
