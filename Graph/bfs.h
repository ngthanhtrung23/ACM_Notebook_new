// BFS
// - Index from 0
// - Directed
// - Supports multi-source BFS
// - Supports reconstruct path
//
// Tested:
// - https://oj.vnoi.info/problem/vmunch
// - https://oj.vnoi.info/problem/vcoldwat
// - (trace) https://cses.fi/problemset/task/1667/
// - (multi-source) https://cses.fi/problemset/task/1193/
struct Graph {
    Graph(int _n) : n(_n), g(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    // return
    // - shortest distance from start -> target
    // - path
    // If no path -> returns -1
    pair<int, vector<int>> bfs(int start, int target) {
        assert(0 <= start && start < n);
        assert(0 <= target && target < n);

        auto [dist, trace] = _bfs({start}, target);
        if (dist[target] < 0) {
            return {dist[target], {}};
        }
        vector<int> path;
        for (int u = target; u != start; u = trace[u]) {
            path.push_back(u);
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        return {dist[target], path};
    }

    // return: dist: vector<int>, dist[u] = shortest distance from start -> u
    vector<int> bfs(int start) {
        assert(0 <= start && start < n);
        return _bfs({start}, -1).first;
    }

    // multi-source BFS
    // Return: dist[u] = shortest distance from any source -> u
    vector<int> bfs(vector<int> starts) {
        return _bfs(starts, -1).first;
    }

// private:

    // Start BFS from start, and stop when reaching target.
    // Start = -1 -> BFS whole graph
    // Returns {distance, trace}
    pair<vector<int>, vector<int>> _bfs(vector<int> starts, int target) {
        assert(-1 <= target && target < n);

        queue<int> qu;
        vector<int> dist(g.size(), -1);
        vector<int> trace(g.size(), -1);

        for (int start : starts) {
            assert(0 <= start && start < n);
            dist[start] = 0;
            qu.push(start);
        }

        while (!qu.empty()) {
            auto u = qu.front(); qu.pop();
            if (u == target) {
                break;
            }

            for (const auto& v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    trace[v] = u;
                    qu.push(v);
                }
            }
        }

        return {dist, trace};
    }

    int n;
    vector<vector<int>> g;
};
