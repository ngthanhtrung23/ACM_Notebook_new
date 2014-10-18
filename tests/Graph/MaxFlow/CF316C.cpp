#include "template.h"
#include "Graph/MaxFlow/MinCostMaxFlowSPFA.h"

int m, n, a[111][111], id[111][111];
const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

int main() {
    int m, n;
    while (cin >> m >> n) {
        MinCostFlow<int,int> mcf(m*n+2);

        int now = 0;
        FOR(i,1,m) FOR(j,1,n) {
            cin >> a[i][j];
            id[i][j] = ++now;
        }

        FOR(i,1,m) FOR(j,1,n) {
            if ((i + j) % 2 == 0) {
                mcf.addEdge(0, id[i][j], 1, 0);
                REP(dir,4) {
                    int ii = i + di[dir], jj = j + dj[dir];
                    if (ii < 1 || ii > m || jj < 1 || jj > n) continue;

                    if (a[i][j] == a[ii][jj]) mcf.addEdge(id[i][j], id[ii][jj], 1, 0);
                    else mcf.addEdge(id[i][j], id[ii][jj], 1, 1);
                }
            } else {
                mcf.addEdge(id[i][j], m*n+1, 1, 0);
            }
        }
        pair<int,int> res = mcf.minCostFlow(0, m*n+1);
        cout << res.second << endl;
    }
    return 0;
}

