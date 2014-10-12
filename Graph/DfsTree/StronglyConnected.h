struct DirectedDFS {
    vector<int> num, low, visited, S;
    int counter;
    vector< vector<int> > scc;

    DirectedDFS() : num(V, -1), low(V, 0), visited(V, 0), counter(0) {}

    void solve() {
        REP(i,V) if (num[i] == -1) dfs(i);
    }

    void dfs(int u) {
        low[u] = num[u] = counter++;
        S.push_back(u);
        visited[u] = 1;
        REP(j, G[u].size()) {
            int v = G[u][j];
            if (num[v] == -1) dfs(v);
            if (visited[v]) low[u] = min(low[u], low[v]);
        }
        if (low[u] == num[u]) {
            scc.push_back(vector<int>());
            while (1) {
                int v = S.back(); S.pop_back(); visited[v] = 0;
                scc.back().push_back(v);
                if (u == v) break;
            }
        }
    }
};
