#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B"

#include <bits/stdc++.h>
using namespace std;

#include "../DirectedMST.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, root; cin >> n >> m >> root;
    vector<Edge> edges(m);
    for (auto& e : edges) {
        cin >> e.u >> e.v >> e.cost;
    }
    auto [total, par] = directed_mst(n, root, edges);
    cout << total << endl;
    return 0;
}
