// Problem: http://codeforces.com/contest/277/problem/E

#include "template.h"
#include "Graph/MaxFlow/MinCostMaxFlow.h"

int x[411], y[411];

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(9);
    int n;
    while (cin >> n) {
        REP(i,n) cin >> x[i] >> y[i];
        int ymax = *max_element(y, y+n);
        int cnt_max = 0;
        REP(i,n) if (y[i] == ymax) ++cnt_max;

        if (cnt_max > 1) {
            cout << -1 << endl;
            continue;
        }

        MinCostFlow<long long, double> mcf;
        REP(i,2*n+2) mcf.addV();

        REP(i,n) if (y[i] != ymax) mcf.addEdge(2*n, i, 1, 0);
        REP(i,n) mcf.addEdge(n+i, 2*n+1, 2, 0);

        REP(i,n) REP(j,n) if (y[i] < y[j]) {
            double dx = x[i] - x[j], dy = y[i] - y[j];
            mcf.addEdge(i, n+j, 1, sqrt(dx*dx + dy*dy));
        }
        pair<long long, double> ans = mcf.minCostFlow(2*n, 2*n+1);
        if (ans.first != n-1) cout << -1 << endl;
        else cout << ans.second << endl;
    }
    return 0;
}

