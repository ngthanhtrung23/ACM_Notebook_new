// Problem: http://vn.spoj.com/problems/MCQUERY
#include "template.h"

const int MN = 211;
const int oo = 1000111000;

#include "Graph/MaxFlow/MaxFlowDinic.h"
#include "Graph/MaxFlow/GomoryHu.h"

int main() {
    ios :: sync_with_stdio(false);
    int ntest; cin >> ntest;
    while (ntest--) {
        int n, m; cin >> n >> m;
        GomoryHu gh(n);
        while (m--) {
            int u, v, c; cin >> u >> v >> c;
            --u; --v;
            gh.addEdge(u, v, c);
            gh.addEdge(v, u, c);
        }

        gh.calc();

        int q; cin >> q;
        while (q--) {
            int t; cin >> t;
            int res = 0;
            REP(i,n) FOR(j,i+1,n-1)
                if (gh.answer[i][j] <= t) {
                    ++res;
                }
            cout << res << endl;
        }
        cout << endl;
    }
}
