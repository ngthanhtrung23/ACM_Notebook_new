#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../template.h"
#include "../mst.h"

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& [u, v, c] : edges) cin >> u >> v >> c;

    cout << mst(n, edges).first << endl;
}
