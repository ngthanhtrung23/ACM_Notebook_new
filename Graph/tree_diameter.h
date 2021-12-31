// Tree diameter (weighted)
// Index from 0
// Return {length, path}
//
// Tested:
// - https://judge.yosupo.jp/problem/tree_diameter
using ll = long long;
pair<ll, vector<int>> get_diameter(const vector<vector<pair<int,int>>>& g) {
    int n = g.size();
    vector<ll> dist(n);
    vector<int> parent(n);

    function<void(int, int, ll)> dfs = [&] (int u, int fu, ll cur_dist) {
        dist[u] = cur_dist;
        parent[u] = fu;
        for (auto [v, cost] : g[u]) if (v != fu) {
            dfs(v, u, cur_dist + cost);
        }
    };
    dfs(0, -1, 0);
    // r = furthest node from root
    int r = max_element(dist.begin(), dist.end()) - dist.begin();
    dfs(r, -1, 0);
    // r->s = longest path
    int s = max_element(dist.begin(), dist.end()) - dist.begin();

    vector<int> path;
    for (int x = s; x >= 0; x = parent[x]) path.push_back(x);

    return {dist[s], path};
}
