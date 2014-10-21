#include "template.h"
#include "Graph/MaxFlow/MaxFlowDinic.h"

const int di[] = {-1,1,0,0};
const int dj[] = {0,0,-1,1};

int n, t, startx, starty;
char scientistMap[22][22], locationMap[22][22];
int d[22][22][22][22];

void bfs(int turn, int u, int v) {
    int curu = u, curv = v;
    queue<int> qu, qv;
    qu.push(u); qv.push(v);
    d[u][v][u][v] = 0;

    while (!qu.empty()) {
        u = qu.front(); qu.pop();
        v = qv.front(); qv.pop();

        REP(dir,4) {
            int uu = u + di[dir], vv = v + dj[dir];
            if (uu < 1 || uu > n || vv < 1 || vv > n || locationMap[uu][vv] == 'Y') continue;
            if (d[curu][curv][uu][vv] >= 0) continue;

            if (turn && d[startx][starty][uu][vv] >= 0 && d[curu][curv][u][v] + 1 > d[startx][starty][uu][vv]) continue;

            if (turn && d[startx][starty][uu][vv] >= 0 && d[curu][curv][u][v] + 1 == d[startx][starty][uu][vv]) {
                if (locationMap[uu][vv] >= '1' && locationMap[uu][vv] <= '9') {
                    d[curu][curv][uu][vv] = d[curu][curv][u][v] + 1;
                    continue;
                }
                continue;
            }

            d[curu][curv][uu][vv] = d[curu][curv][u][v] + 1;
            qu.push(uu);
            qv.push(vv);
        }
    }
}

int id[22][22];

int main() {
    while (cin >> n >> t) {
        FOR(i,1,n) FOR(j,1,n) cin >> scientistMap[i][j];
        FOR(i,1,n) FOR(j,1,n) cin >> locationMap[i][j];
        memset(d, -1, sizeof d);

        FOR(i,1,n) FOR(j,1,n) if (locationMap[i][j] == 'Z') {
            startx = i;
            starty = j;
            bfs(0, i, j);
        }

        int cur = 0;
        FOR(i,1,n) FOR(j,1,n) id[i][j] = ++cur;

        MaxFlow flow(2*n*n+2);
        FOR(i,1,n) FOR(j,1,n) {
            if (scientistMap[i][j] >= '1' && scientistMap[i][j] <= '9')
                flow.addEdge(0, id[i][j], scientistMap[i][j] - '0');
            if (locationMap[i][j] >= '1' && locationMap[i][j] <= '9')
                flow.addEdge(n*n+id[i][j], 2*n*n+1, locationMap[i][j] - '0');
        }

        FOR(i,1,n) FOR(j,1,n) if (scientistMap[i][j] >= '1' && scientistMap[i][j] <= '9') {
            bfs(1, i, j);

            FOR(u,1,n) FOR(v,1,n) if (locationMap[u][v] >= '1' && locationMap[u][v] <= '9')
                if (d[i][j][u][v] >= 0 && d[i][j][u][v] <= t) {
                    flow.addEdge(id[i][j], n*n+id[u][v], min(locationMap[u][v] - '0', scientistMap[i][j] - '0'));
                }
        }
        cout << flow.getMaxFlow(0, 2*n*n+1) << endl;
    }
    return 0;
}
