// Tested:
// - https://open.kattis.com/problems/stringmultimatching
// - https://icpc.kattis.com/problems/firstofhername
// - https://oj.vnoi.info/problem/binpal
//
// Notes:
// - Node IDs from 0 to aho.sz.
// - Characters should be normalized to [0, MC-1].
// - For each node of AhoCorasick, we store a linked list containing all queries "associated" with this node.
//   The reason is that, when we reach a node in AhoCorasick, it's possible to match several queries at once.
//   (this happens when queries are suffix of others, e.g. C, BC, ABC).
//   This also means 1 node maps to several queries, and 1 query maps to several nodes.
//   However I believe that the sum of length of all linked list is O(N) -- TODO: Source / proof required.

const int MN = 1000111; // MN > total length of all patterns
const int MC = 26; // Alphabet size.

// Start of Linked list
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
//
struct Aho {
    int qu[MN], suffixLink[MN];
    List leaf[MN];
    int link[MN][MC];
    int sz;
    bool calledBuildLink;

    void init() {
        calledBuildLink = false;
        sz = 0;
        memset(suffixLink, 0, sizeof suffixLink);
        leaf[0] = List();
        memset(link[0], -1, sizeof link[0]);
    }
    int getChild(int type, int v, int c) {
        if (type == 2) assert(calledBuildLink);

        if (link[v][c] >= 0) return link[v][c];
        if (type == 1) return 0;
        if (!v) return link[v][c] = 0;
        return link[v][c] = getChild(type, suffixLink[v], c);
    }
    void buildLink() {
        calledBuildLink = true;
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
