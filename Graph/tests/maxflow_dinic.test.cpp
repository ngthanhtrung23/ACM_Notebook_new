#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <bits/stdc++.h>
using namespace std;

#include "../MaxFlow/MaxFlowDinic.h"

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;

    MaxFlow flow(n);
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        flow.addEdge(u, v, c);
    }
    cout << flow.getMaxFlow(0, n-1) << endl;
}
