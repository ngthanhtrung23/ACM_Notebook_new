// BFS using map, so extra log factor
//
// Tested:
// - https://oj.vnoi.info/problem/vmunch
template<typename T>
struct Graph {
    void add_edge(const T& u, const T& v) {
        g[u].push_back(v);
    }

    // return shortest distance from start -> target
    // If no path -> returns -1
    int bfs(const T& start, const T& target) {
        queue<T> qu;
        map<T, int> dist;

        dist[start] = 0;
        qu.push(start);

        while (!qu.empty()) {
            auto u = qu.front(); qu.pop();
            if (u == target) {
                return dist[u];
            }

            for (const auto& v : g[u]) {
                if (!dist.count(v)) {
                    dist[v] = dist[u] + 1;
                    qu.push(v);
                }
            }
        }

        return -1;
    }

// private:
    map<T, vector<T>> g;
};
