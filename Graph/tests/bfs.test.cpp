#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

#include <bits/stdc++.h>
using namespace std;

#include "../bfs.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Graph g(n);

    REP(i,n) {
        int u, k; cin >> u >> k;
        --u;
        while (k--) {
            int v; cin >> v;
            --v;
            g.add_edge(u, v);
        }
    }
    auto dist = g.bfs(0);
    REP(i,n) {
        cout << (i+1) << ' ' << dist[i] << '\n';
    }
    return 0;
}
