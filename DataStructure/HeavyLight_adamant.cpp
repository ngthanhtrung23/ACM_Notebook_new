// Usage:
// dfs_sz(1)
// dfs_hld(1)
//
// T(v) = [in[v]; out[v])
// path from v -> last vertexn ascending heavy path from v (next[v]): [in[next[v]]; in[v]] 
void dfs_sz(int v) {
    sz[v] = 1;
    for(auto &u: g[v]) {
        dfs_sz(u);
        sz[v] += sz[u];
        if(sz[u] > sz[g[v][0]])
            swap(u, g[v][0]);
    }
}

void dfs_hld(int v) {
    in[v] = t++;
    rin[in[v]] = v;
    for(auto u: g[v]) {
        nxt[u] = (u == g[v][0] ? nxt[v] : u);
        dfs_hld(u);
    }
    out[v] = t;
}

