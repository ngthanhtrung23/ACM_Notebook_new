// Topo sort
// returns: <has topo sort?, topo order>
//
// Notes:
// - To find lexicographically min -> change queue<int> qu to set
//
// Tested:
// - https://cses.fi/problemset/task/1679/
// - https://cses.fi/problemset/task/1757/
std::pair<bool, std::vector<int>> topo_sort(const std::vector<std::vector<int>>& g) {
    int n = g.size();
    // init in_deg
    std::vector<int> in_deg(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) {
            in_deg[v]++;
        }
    }

    // find topo order
    std::vector<int> res;
    std::queue<int> qu;
    for (int u = 0; u < n; u++) {
        if (in_deg[u] == 0) {
            qu.push(u);
        }
    }

    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        res.push_back(u);
        for (int v : g[u]) {
            in_deg[v]--;
            if (in_deg[v] == 0) {
                qu.push(v);
            }
        }
    }

    if ((int) res.size() < n) {
        return {false, {}};
    }
    return {true, res};
}
