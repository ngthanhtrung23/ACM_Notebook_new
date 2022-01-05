// Assume already have undirected graph vector< vector<int> > G with V vertices
// Vertex index from 0
// Usage:
// UndirectedDfs tree;
// Then you can use tree.bridges and tree.cuts
//
// Tested:
// - https://judge.yosupo.jp/problem/two_edge_connected_components
struct UndirectedDfs {
    vector<vector<int>> g;
    int n;
    vector<int> low, num, parent;
    vector<bool> articulation;
    int counter, root, children;

    vector< pair<int,int> > bridges;
    vector<int> cuts;
    map<pair<int,int>, int> cnt_edges;

    UndirectedDfs(const vector<vector<int>>& _g) : g(_g), n(g.size()),
            low(n, 0), num(n, -1), parent(n, 0), articulation(n, false),
            counter(0), children(0) {
        for (int u = 0; u < n; u++) {
            for (int v : g[u]) {
                cnt_edges[{u, v}] += 1;
                cnt_edges[{v, u}] += 1;
            }
        }
        for(int i = 0; i < n; ++i) if (num[i] == -1) {
            root = i; children = 0;
            dfs(i);
            articulation[root] = (children > 1);
        }
        for(int i = 0; i < n; ++i)
            if (articulation[i]) cuts.push_back(i);
    }
private:
    void dfs(int u) {
        low[u] = num[u] = counter++;
        for (int v : g[u]) {
            if (num[v] == -1) {
                parent[v] = u;
                if (u == root) children++;
                dfs(v);
                if (low[v] >= num[u])
                    articulation[u] = true;
                if (low[v] > num[u]) {
                    if (cnt_edges[{u, v}] == 2) {
                        bridges.push_back(make_pair(u, v));
                    }
                }
                low[u] = min(low[u], low[v]);
            } else if (v != parent[u])
                low[u] = min(low[u], num[v]);
        }
    }
};
