#include "../../template.h"
#include "MinCostMaxFlow.h"

const int MN = 111*111*2;
int id[111];
MinCostFlow<long long,long long>::Edge* edges[MN];
int f[111][111], c[111][111];
int id_u[MN], id_v[MN];

int main() {
    MinCostFlow<long long, long long> mcf;
    int n, m, k, s, t;
    while (cin >> n >> m >> k >> s >> t) {
        FOR(i,0,n) id[i] = mcf.addV();

        mcf.addEdge(id[0], id[s], k, 0);

        memset(f, 0, sizeof f);
        FOR(i,1,m) {
            int u, v;
            cin >> u >> v;
            cin >> c[u][v] >> f[u][v];
            c[v][u] = c[u][v]; f[v][u] = f[u][v];
        }

        m = 0;
        FOR(i,1,n) FOR(j,i+1,n) if (f[i][j]) {
            edges[++m] = mcf.addEdge(i, j, f[i][j], c[i][j]); id_u[m] = i; id_v[m] = j;
            edges[++m] = mcf.addEdge(j, i, f[i][j], c[i][j]); id_u[m] = j; id_v[m] = i;
        }

        pair<long long, long long> res = mcf.minCostFlow(id[0], id[t]);

        if (res.first < k) {
            cout << -1 << endl;
            continue;
        }
        cout << res.second << endl;

        FOR(i,1,m/2) {
            int u = id_u[i], v = id_v[i];
            int f_xuoi = f[u][v] - edges[i*2-1]->f;
            int f_nguoc = f[v][u] - edges[i*2]->f;

            int t = min(f_xuoi, f_nguoc);
            f_xuoi -= t;
            f_nguoc -= t;

            if (f_xuoi > 0) {
                cout << id_u[i*2-1] << ' ' << id_v[i*2-1] << ' ' << f_xuoi << endl;
            }
            if (f_nguoc > 0) {
                cout << id_u[i*2] << ' ' << id_v[i*2] << ' ' << f_nguoc << endl;
            }
        }
        cout << "0 0 0" << endl;
    }
}
