#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include "../../template.h"
#include "../topo_sort.h"

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    while (m--) {
        int u, v; std::cin >> u >> v;
        g[u].push_back(v);
    }

    auto [_, order] = topo_sort(g);
    for (int u : order) std::cout << u << '\n';
}
