// Source: https://codeforces.com/blog/entry/53170
//
// Tested:
// - HLD on vertices: https://oj.vnoi.info/problem/icpc21_mt_l
// - HLD on vertices: https://oj.vnoi.info/problem/qtree3
// - HLD on edges: https://oj.vnoi.info/problem/qtreex
//
// Usage:
// 
// ```
// // init g
// depth[1] = 1;
// dfs_parent(1, -1);
// 
// // If there's parent node in g --> need to delete it
// FOR(i,1,n) {
//   auto it = std::find(g[i].begin(), g[i].end(), parent[i]);
//   if (it != g[i].end()) g[i].erase(it);
// }
// dfs_number = 1;
// nxt[1] = 1;
// dfs_sz(1);
// dfs_hld(1);
//
// query(u, v)
// ```
//
// T(v) = [in[v]; out[v])
// path from v -> last vertex in ascending heavy path from v (nxt[v]): [in[nxt[v]]; in[v]] 

int parent[MN], depth[MN];
int in[MN], out[MN], nxt[MN], sz[MN], dfs_number, order[MN];

// initialize parent[] and depth[]
void dfs_parent(int v, int pv) {
    parent[v] = pv;
    for (int u : g[v]) {
        if (u != pv) {
            depth[u] = depth[v] + 1;
            dfs_parent(u, v);
        }
    }
}

// initialize sz[] and re-organize tree
void dfs_sz(int v) {
    sz[v] = 1;
    for(auto &u: g[v]) {
        dfs_sz(u);
        sz[v] += sz[u];
        if(sz[u] > sz[g[v][0]])
            swap(u, g[v][0]);
    }
}

// initialize in[], out[] and order[]
void dfs_hld(int v) {
    order[dfs_number] = v;
    in[v] = dfs_number++;
    for(auto u: g[v]) {
        nxt[u] = (u == g[v][0] ? nxt[v] : u);
        dfs_hld(u);
    }
    out[v] = dfs_number;
}

// return true if u is ancestor of v
bool isAncestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

// Return all segments on path from u -> v
// For this problem, the order (u -> v is different from v -> u)
vector< pair<int,int> > getSegments(int u, int v) {
    vector< pair<int,int> > upFromU, upFromV;

    int fu = nxt[u], fv = nxt[v];
    while (fu != fv) {  // u and v are on different chains
        if (depth[fu] >= depth[fv]) { // move u up
            upFromU.push_back({u, fu});
            u = parent[fu];
            fu = nxt[u];
        } else { // move v up
            upFromV.push_back({fv, v});
            v = parent[fv];
            fv = nxt[v];
        }
    }
    upFromU.push_back({u, v});
    reverse(upFromV.begin(), upFromV.end());
    upFromU.insert(upFromU.end(), upFromV.begin(), upFromV.end());
    return upFromU;
}

int query(int start, int target) {
    auto segments = getSegments(start, target);

    int res = 0;
    for (auto [u, v] : segments) {
        // update res using [in[u], in[v]].
        // Be careful about order of in[u] and in[v]
    }
    return res;
}

/**
 * For query by edges, can reuse everything above. After calling
 * getSegments, we just query each segments, ignoring segments' ancestors
 */
int query(int start, int target) {
    auto segments = getSegments(start, target);

    for (int i = 0; i < (int) segments.size(); i++) {
        auto [u, v] = segments[i];
        if (isAncestor(u, v)) swap(u, v);
        // u is now children of v
        assert(in[v] <= in[u]);
        // query segment tree [in[v], in[u]]

        // connect end of this segment to start of next segment
        v = segments[i].second;
        if (i+1 < SZ(segments)) {
            auto [x, y] = segments[i+1];
            // need to query edge (v, x)
            if (v == parent[x]) swap(v, x);
            // query segment tree [in[v], in[v]]
        }
    }
}
