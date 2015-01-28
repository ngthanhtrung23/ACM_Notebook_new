// If directed --> do not need rev, update add_edge method
// No solution? NEED TO CHECK YOURSELF (connected graph, number of odd vertices)
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

