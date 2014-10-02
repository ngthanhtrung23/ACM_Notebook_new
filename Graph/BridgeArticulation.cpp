int V;
vector <int> G[MAXV + 5];

int dfs_low[MAXV + 5], dfs_num[MAXV + 5], dfs_parent[MAXV + 5];
int dfsNumberCounter, dfsRoot, rootChildren;
bool articulation_vertex[MAXV + 5];

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    REP (j, SIZE(G[u])) {
        int v = G[u][j];
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v);
            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = true;
            if (dfs_low[v] > dfs_num[u])
                printf(" Edge (%d, %d) is a bridge\n", u, v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}
int main() {
    // init graph, indices from 0
    dfsNumberCounter = 0; RESET(dfs_num, -1); RESET(dfs_low, 0);
    RESET(dfs_parent, 0); RESET(articulation_vertex, 0);
    printf("Bridges:\n");
    REP (i, V) if (dfs_num[i] == -1) {
        dfsRoot = i; rootChildren = 0;
        articulationPointAndBridge(i);
        articulation_vertex[dfsRoot] = (rootChildren > 1);
    }
    printf("Articulation Points:\n");
    REP (i, V) if (articulation_vertex[i])
        printf(" Vertex %d\n", i);
}
