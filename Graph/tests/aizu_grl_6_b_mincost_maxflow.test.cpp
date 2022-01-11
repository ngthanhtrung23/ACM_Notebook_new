#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <bits/stdc++.h>
using namespace std;

#include "../MaxFlow/MinCostMaxFlowPR.h"

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, fl; cin >> n >> m >> fl;

    MinCostFlow<int, int> flow(n+1, 0, n);
    flow.addEdge(n-1, n, fl, 0);
    while (m--) {
        int u, v, f, c; cin >> u >> v >> f >> c;
        flow.addEdge(u, v, f, c);
    }
    auto [f, c] = flow.minCostMaxFlow();
    if (f < fl) {
        cout << -1 << endl;
    } else {
        cout << c << endl;
    }
    return 0;
}
