// Dijkstra
//
// Notes:
// - Index from 0
//
// Tested:
// - https://judge.yosupo.jp/problem/shortest_path
//
// Param:
// - g[u] = pair<v, cost>, adjacency list
// - start = start vertex
// Returns:
// - distances from start. If unreachable -> dist = INF
// - previous vertex. Previous[start] = start. If unreachable -> trace = -1
using ll = long long;
const ll INF = 1e18;  // must be greater than maximum possible path
pair<vector<ll>, vector<int>> dijkstra(const vector<vector<pair<int, ll>>>& g, int start) {
    int n = g.size();
    vector<ll> f(n, INF);
    vector<int> trace(n, -1);
    f[start] = 0;
    trace[start] = start;
    using P = pair<ll, int>;  // <distance, vertex>

    // priority_queue should be faster than set?
    priority_queue<P, vector<P>, greater<P>> all;
    all.push(P{0LL, start});
    while (!all.empty()) {
        auto [dist, u] = all.top();
        all.pop();
        if (dist != f[u]) continue;

        for (auto [v, c] : g[u]) {
            if (f[v] > f[u] + c) {
                f[v] = f[u] + c;
                trace[v] = u;
                all.push(P{f[v], v});
            }
        }
    }

    return {f, trace};
}

// Dijkstra from start -> target
// Returns:
// - distance. If unreachable -> INF
// - path. If unreachable -> {}
pair<ll, vector<int>> dijkstra(const vector<vector<pair<int, ll>>>& g, int start, int target) {
    auto [f, trace] = dijkstra(g, start);
    if (trace[target] < 0) {
        return {INF, {}};
    }

    vector<int> path;
    for (int u = target; u != start; u = trace[u]) {
        path.push_back(u);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return {f[target], path};
}
