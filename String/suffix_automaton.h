const int MAX_N = int(1e5) + 4;
const int MAX_SAM = 2 * MAX_N;
// a node in the "directed acyclic word graph" (or simply "DAWG")
struct State {
    // len: length of the path from root to this node (number of edges)
    // link: link to a node which is a suffix of this state
    // nexts: the node which is adjanced with this node by an edge ('a'..'z', '0'..'9', ...)
    int len, link;
    map<int, int> nexts;
    State() {
        len = 0;
        link = -1;
        nexts.clear();
    }
    void operator = (const State &other) {
        len = other.len;
        link = other.link;
        nexts = other.nexts;
    }
    bool hasNext(int x) {
        return nexts.find(x) != nexts.end();
    }
};
void sam_init() {
    nSAM = 1;       // number of nodes
    last = 0;       // id of the last node (start from 0)
    sam[0] = State();   // this is the root node
    f[0] = 0;           // for some applications
}
void sam_extend(int x) {
    int cur = nSAM++;       // id of new node
    sam[cur] = State();
    sam[cur].len = sam[last].len + 1;
    f[cur] = 1;
    int p = last;
    for (; p != -1 && !sam[p].hasNext(x); p = sam[p].link)
        sam[p].nexts[x] = cur;
    if (p == -1) sam[cur].link = 0;
    else {
        int q = sam[p].nexts[x];
        if (sam[q].len == sam[p].len + 1) sam[cur].link = q;
        else {
            int clone = nSAM++;     // create a clone node of q
            sam[clone] = sam[q];
            sam[clone].len = sam[p].len + 1;
            f[clone] = 0;
            for (; p != -1 && sam[p].nexts[x] == q; p = sam[p].link)
                sam[p].nexts[x] = clone;
            sam[cur].link = sam[q].link = clone;
        }
    }
    last = cur;
}
// // APLICATIONS
// // we should do the topo sort (by length) before implement other features
// for (int i = 0; i <= n; ++i) c[i] = 0;
// for (int i = 0; i < nSAM; ++i) ++c[sam[i].len];
// for (int i = 1; i <= n; ++i) c[i] += c[i-1];
// for (int i = 0; i < nSAM; ++i) id[--c[sam[i].len]] = i;
// // number of occurrents of state u, which corresponding with
// // number of occurrents of each substrings from root to u
// for (int i = nSAM-1; i >= 0; --i) {
//  int u = id[i];
//  f[sam[u].link] += f[u];
// }
// // number of ways to go from root to state u, which corresponding with
// // number of different substrings end at u.
// // If we sort these strings increasing by their lengths,
// // then the i-th string is a suffix of the (i+1)-th string.
// fill(g, 0);
// g[0] = 1;
// for (int i = 0; i < nSAM; ++i) {
//  int u = id[i];
//  tr(sam[u].nexts, it)
//      g[it->second] += g[u];
// }
// // number of substrings which have state u as its prefix
// for (int i = nSAM-1; i >= 0; --i) {
//  int u = id[i];
//  f[u] = 1;
//  tr(sam[u].nexts, it)
//      f[u] += [it->second];
// }