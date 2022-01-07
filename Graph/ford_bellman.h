#include "bfs.h"

// Ford Bellman, O(N*M)
using ll = long long;
const ll INF = 4e18;
struct Edge { int u, v; ll cost; }; // one-direction

// Returns {is distance to target bounded?, shortest distance from start -> target}
std::pair<bool, ll> ford_bellman(int n, int start, int target, const vector<Edge>& edges) {
    int m = edges.size();
    std::vector<ll> f(n, INF);
    f[start] = 0;

    // Init f
    for (int turn = 0; turn < m; turn++) {
        for (auto [u, v, cost] : edges) {
            if (f[u] != INF && f[v] > f[u] + cost) {
                f[v] = f[u] + cost;
            }
        }
    }

    // Find all unbounded vertices
    auto cur_f = f;
    for (int turn = 0; turn < m; turn++) {
        for (auto [u, v, cost] : edges) {
            if (f[u] != INF && f[v] > f[u] + cost) {
                f[v] = f[u] + cost;
            }
        }
    }

    vector<int> unbounded;
    for (int i = 0; i < n; i++) {
        if (f[i] != cur_f[i]) {
            unbounded.push_back(i);
        }
    }

    // Check if target is reachable from unbounded vertices
    Graph g(n);
    for (auto [u, v, cost] : edges) {
        g.add_edge(u, v);
    }
    auto dists = g.bfs(unbounded);

    return {dists[target] == -1, f[target]};
}

