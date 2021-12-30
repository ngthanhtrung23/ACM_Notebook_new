// Find all cycles of length 3 (a.k.a. triangles)
// Complexity: O(N + M*sqrt(M))
//
// Index from 0
//
// Tested:
// - https://judge.yosupo.jp/problem/enumerate_triangles
vector< tuple<int,int,int> > find_all_triangles(
        int n,
        vector<pair<int,int>> edges) {
    // Remove duplicated edges
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());

    // Compute degs
    vector<int> deg(n, 0);
    for (const auto& [u, v] : edges) {
        if (u == v) continue;
        ++deg[u], ++deg[v];
    }

    // Add edge (u, v) where u is 'lower' than v
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        if (u == v) continue;
        if (deg[u] > deg[v] || (deg[u] == deg[v] && u > v)) swap(u, v);
        adj[u].push_back(v);
    }

    // Find all triplets.
    // If it's too slow, remove vector res and compute answer directly
    vector<tuple<int,int,int>> res;
    vector<bool> good(n, false);
    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) good[j] = true;
        for (auto j : adj[i]) {
            for (auto k : adj[j]) {
                if (good[k]) {
                    res.emplace_back(i, j, k);
                }
            }
        }
        for (auto j : adj[i]) good[j] = false;
    }
    return res;
}
