#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include "../../template.h"
#include "../mst.h"

struct E : Edge {
    int id;
};

void solve() {
    int n, m; cin >> n >> m;
    vector<E> edges(m);
    REP(i,m) {
        auto& e = edges[i];
        cin >> e.u >> e.v >> e.c;
        e.id = i;
    }
    auto g = mst<E>(n, edges);
    cout << g.first << '\n';
    for (auto& e : g.second) cout << e.id << ' ';
    cout << '\n';
}
