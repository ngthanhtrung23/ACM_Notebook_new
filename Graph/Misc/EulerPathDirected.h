// Tested:
// - https://open.kattis.com/problems/eulerianpath
// - https://oj.vnoi.info/problem/vnoicup22_final_c
struct EulerDirected {
    EulerDirected(int _n) : n(_n), adj(n), in_deg(n, 0), out_deg(n, 0) {}

    void add_edge(int u, int v) {  // directed edge
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        adj[u].push_front(v);
        in_deg[v]++;
        out_deg[u]++;
    }

    std::pair<bool, std::vector<int>> solve() {
        int start = -1, last = -1;
        for (int i = 0; i < n; i++) {
            // for all u, |in_deg(u) - out_deg(u)| <= 1
            if (std::abs(in_deg[i] - out_deg[i]) > 1) return {false, {}};

            if (out_deg[i] > in_deg[i]) {
                // At most 1 vertex with out_deg[u] - in_deg[u] = 1 (start vertex)
                if (start >= 0) return {false, {}};
                start = i;
            }

            if (in_deg[i] > out_deg[i]) {
                // At most 1 vertex with in_deg[u] - out_deg[u] = 1 (last vertex)
                if (last >= 0) return {false, {}};
                last = i;
            }
        }

        // can start at any vertex with degree > 0
        if (start < 0) {
            for (int i = 0; i < n; i++) {
                if (in_deg[i]) {
                    start = i;
                    break;
                }
            }
            // no start vertex --> all vertices have degree == 0
            if (start < 0) return {true, {}};
        }

        std::vector<int> path;
        find_path(start, path);
        std::reverse(path.begin(), path.end());

        // check that we visited all vertices with degree > 0
        std::vector<bool> visited(n, false);
        for (int u : path) visited[u] = true;

        for (int u = 0; u < n; u++) {
            if (in_deg[u] && !visited[u]) {
                return {false, {}};
            }
        }

        return {true, path};
    }

private:
    int n;
    std::vector<std::list<int>> adj;
    std::vector<int> in_deg, out_deg;

    void find_path(int v, std::vector<int>& path) {
        while (adj[v].size() > 0) {
            int next = adj[v].front();
            adj[v].pop_front();
            find_path(next, path);
        }
        path.push_back(v);
    }
};
