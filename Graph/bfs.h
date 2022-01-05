// BFS
// Index from 0
// Directed
//
// Tested:
// - https://oj.vnoi.info/problem/vmunch
// - https://oj.vnoi.info/problem/vcoldwat
struct Graph {
    Graph(int n) : g(n) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    // return shortest distance from start -> target
    // If no path -> returns -1
    int bfs(int start, int target) {
        auto dist = _bfs(start, target);
        return dist[target];
    }

    // return: dist: vector<int>, dist[u] = shortest distance from start -> u
    vector<int> bfs(int start) {
        return _bfs(start, -1);
    }

// private:

    // Start BFS from start, and stop when reaching target.
    // Returns distance
    vector<int> _bfs(int start, int target) {
        queue<int> qu;
        vector<int> dist(g.size(), -1);

        dist[start] = 0;
        qu.push(start);

        while (!qu.empty()) {
            auto u = qu.front(); qu.pop();
            if (u == target) {
                break;
            }

            for (const auto& v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    qu.push(v);
                }
            }
        }

        return dist;
    }
    vector<vector<int>> g;
};
