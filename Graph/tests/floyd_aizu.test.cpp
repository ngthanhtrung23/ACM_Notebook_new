#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include "../../template.h"
#include "../floyd.h"

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<ll>> c(n, vector<ll> (n, INF));
    for (int i = 0; i < n; i++) c[i][i] = 0;

    while (m--) {
        int u, v; ll cost; cin >> u >> v >> cost;
        c[u][v] = min(c[u][v], cost);
    }

    Floyd f(n, c);
    for (int i = 0; i < n; i++) {
        if (f.c[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f.c[i][j] == INF) cout << "INF";
            else cout << f.c[i][j];
            cout << (j == n-1 ? '\n' : ' ');
        }
    }
}
