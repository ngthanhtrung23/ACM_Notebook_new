// Note: indices from 0

int dfs_num[MAXV + 5], dfs_low[MAXV + 5], visited[MAXV + 5];
int dfsNumberCounter, numSCC;
int V;
vector <int> S;
vector <int> G[MAXV + 5];

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.PB(u);
    visited[u] = 1;
    REP (j, SIZE(G[u])) {
        int v = G[u][j];
        if (dfs_num[v] == -1) tarjanSCC(v);
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        printf("SCC %d:", ++numSCC);
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            printf(" %d", v);
            if (u == v) break;
        }
        printf("\n");
    }
}
int main() {
    // Initialize V, G.
    RESET(dfs_num, -1); RESET(dfs_low, 0); RESET(visited, 0);
    dfsNumberCounter = numSCC = 0;
    REP (i, V) if (dfs_num[i] == -1) tarjanSCC(i);
}
