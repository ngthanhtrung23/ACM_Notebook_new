// BFS using map, so extra log factor
//
// Note:
// - Can use unordered_map for small speed improvement
//   (see unordered_map_pair.h for how to implement hash for other types)
//
// Tested:
// - https://oj.vnoi.info/problem/vmunch
// - https://cses.fi/problemset/task/1193/
template<typename T>
struct Graph {
    void add_edge(const T& u, const T& v) {
        g[u].push_back(v);
    }

    // return
    // - shortest distance from start -> target
    // - path
    // If no path -> returns {-1, {}}
    std::pair<int, std::vector<T>> bfs(const T& start, const T& target) {
        queue<T> qu;
        std::map<T, int> dist;
        std::map<T, T> trace;

        dist[start] = 0;
        qu.push(start);

        while (!qu.empty()) {
            auto u = qu.front(); qu.pop();
            if (u == target) {
                std::vector<T> path;
                for (auto cur = target; cur != start; cur = trace[cur]) {
                    path.push_back(cur);
                }
                path.push_back(start);
                reverse(path.begin(), path.end());
                return {dist[u], path};
            }

            for (const auto& v : g[u]) {
                if (!dist.count(v)) {
                    dist[v] = dist[u] + 1;
                    trace[v] = u;
                    qu.push(v);
                }
            }
        }

        return {-1, {}};
    }

// private:
    map<T, vector<T>> g;
};

// For grid. Not sure where else to put lol
/**
const vector< pair<int,int> > dirs = {
    {-1, 0},  // down
    {0, -1},  // left
    {1, 0},   // up
    {0, 1},   // right
};
*/
