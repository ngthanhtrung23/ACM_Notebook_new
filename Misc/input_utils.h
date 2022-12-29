// read undirected graph, N M u1 v1 u2 v2 ... {{{
int n, m; cin >> n >> m;
vector<vector<int>> g(n);
for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
}
// }}}
