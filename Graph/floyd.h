// Tested:
// - https://cses.fi/problemset/task/1672/
// - (trace) https://oj.vnoi.info/problem/floyd
using ll = long long;
const ll INF = 4e18;
struct Floyd {
    Floyd(int _n, const std::vector<std::vector<ll>> _c) : n(_n), c(_c), trace(n) {
        for (int i = 0; i < n; i++) {
            trace[i] = std::vector<int> (n, -1);
            for (int j = 0; j < n; j++) {
                if (c[i][j] == INF) trace[i][j] = -1;
                else trace[i][j] = i;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (c[i][k] != INF && c[k][j] != INF && c[i][j] > c[i][k] + c[k][j]) {
                        c[i][j] = c[i][k] + c[k][j];
                        trace[i][j] = trace[k][j];
                    }
                }
            }
        }
    }

    // Return {distance, path}
    // If no path -> returns {-1, {}}
    std::pair<ll, std::vector<int>> get_path(int start, int target) {
        if (trace[start][target] == -1) return {-1, {}};

        std::vector<int> path;
        for (int u = target; u != start; u = trace[start][u]) {
            path.push_back(u);
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        return {c[start][target], path};
    }

    int n;
    std::vector<std::vector<ll>> c;
    std::vector<std::vector<int>> trace;
};

