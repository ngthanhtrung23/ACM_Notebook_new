// Reroot tree DP
//
// e.g. We need to compute:
// - f[u] = longest path starting from u, going inside subtree(u)
// - g[u] = longest path starting from u, going outside subtree(u)
//
// We can easily compute f[u] using normal tree DP.
// To compute g:
// - Init g[0]
// - Current node = u
// - Maintain some data structure to store f[children(u)]
// - Use this data structure to compute f[v]
// - Call dfs(v)
//
// Tested:
// - CSES Tree Distance I: https://cses.fi/problemset/task/1132/
// - https://oj.vnoi.info/problem/icpc21_mn_h

const int MN = 200111;
int g[MN];  // longest path from u, outside subtree(u)
int f[MN];  // longest path from u, inside subtree(u)
int parent[MN];
vector<int> adj[MN];
vector<int> paths_from_u[MN];

// compute f[u]
void dfs1(int u, int fu) {
    parent[u] = fu;
    f[u] = 0;
    for (int v : adj[u]) {
        if (v == fu) continue;

        dfs1(v, u);
        f[u] = max(f[u], f[v] + 1);
    }
}

// compute g[u], using reroot tree DP
void dfs2(int u, int fu) {
    // prefix and suffix max, for f(children(u))
    vector<int> left, right;
    for (int v : adj[u]) {
        if (v == fu) {
            left.push_back(g[u]);
        } else {
            left.push_back(f[v] + 1);
        }
    }
    right = left;
    for (int i = 1; i < SZ(left); i++) {
        left[i] = max(left[i-1], left[i]);
    }
    for (int i = SZ(right) - 2; i >= 0; i--) {
        right[i] = max(right[i+1], right[i]);
    }

    // compute g(children)
    REP(i,SZ(adj[u])) {
        int v = adj[u][i];
        if (v == fu) continue;

        // v -> u
        g[v] = 1;
        // v -> u -> left of v
        if (i > 0) g[v] = max(g[v], left[i-1] + 1);
        if (i+1 < SZ(adj[u])) g[v] = max(g[v], right[i+1] + 1);

        dfs2(v, u);
    }
}

int main() {
    // init g
    dfs1(root, -1);
    dfs2(root, -1);
}
