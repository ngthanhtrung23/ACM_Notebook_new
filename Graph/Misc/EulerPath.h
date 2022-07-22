// NOTES:
// - When choosing starting vertex (for calling find_path), make sure deg[start] > 0.
// - If find Euler path, starting vertex must have odd degree.
// - Check no solution: SZ(path) == nEdge + 1.
// - For directed -> see EulerPathDirected.h
//
// Tested:
// - SGU 101 (undirected).
struct Edge {
    int to;
    list<Edge>::iterator rev;

    Edge(int to) :to(to) {}
};

const int MN = 100111;
list<Edge> adj[MN];
vector<int> path; // our result

void find_path(int v) {
    while(adj[v].size() > 0) {
        int vn = adj[v].front().to;
        adj[vn].erase(adj[v].front().rev);
        adj[v].pop_front();
        find_path(vn);
    }
    path.push_back(v);
}

void add_edge(int a, int b) {
    adj[a].push_front(Edge(b));
    auto ita = adj[a].begin();
    adj[b].push_front(Edge(a));
    auto itb = adj[b].begin();
    ita->rev = itb;
    itb->rev = ita;
}
