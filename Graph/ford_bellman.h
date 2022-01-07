// Ford Bellman, O(N*M)
// Tested:
// - https://cses.fi/problemset/task/1673
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
 
    // Set all unbounded vertices to -INF
    for (int i = 0; i < n; i++) {
        if (f[i] != cur_f[i]) {
            f[i] = -INF;
        }
    }
 
    // Re-update all f
    for (int turn = 0; turn < m; turn++) {
        for (auto [u, v, cost] : edges) {
            if (f[u] != INF && f[v] > f[u] + cost) {
                f[v] = f[u] + cost;
            }
        }
    }
    return {f[target] == cur_f[target], f[target]};
}
