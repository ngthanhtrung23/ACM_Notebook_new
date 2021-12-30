// Input graph: vector< vector<int> > a, int n
// Note: 0-indexed
// Usage: BiconnectedComponent bc; (bc.components is the list of components)
//
// This is biconnected components by edges (1 vertex can belong to
// multiple components). For vertices biconnected component, remove
// bridges and find components
int n;
vector<vector<int>> g;
struct BiconnectedComponent {
    vector<int> low, num, s;
    vector< vector<int> > components;
    int counter;

    BiconnectedComponent() : low(n, -1), num(n, -1), counter(0) {
        for (int i = 0; i < n; i++)
            if (num[i] < 0)
                dfs(i, 1);
    }

    void dfs(int x, int isRoot) {
        low[x] = num[x] = ++counter;
        if (g[x].empty()) {
            components.push_back(vector<int>(1, x));
            return;
        }
        s.push_back(x);

        for (int i = 0; i < (int) g[x].size(); i++) {
            int y = g[x][i];
            if (num[y] > -1) low[x] = min(low[x], num[y]);
            else {
                dfs(y, 0);
                low[x] = min(low[x], low[y]);

                if (isRoot || low[y] >= num[x]) {
                    components.push_back(vector<int>(1, x));
                    while (1) {
                        int u = s.back();
                        s.pop_back();
                        components.back().push_back(u);
                        if (u == y) break;
                    }
                }
            }
        }
    }
};
