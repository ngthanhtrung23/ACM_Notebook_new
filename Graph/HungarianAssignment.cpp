/* Hungarian Implementation
 * When change it to long long, remove EPS
 * Indices from 0
 */
typedef LL VD[MAXV + 5];
typedef LL VVD[MAXV + 5][MAXV + 5];
typedef int VI[MAXV + 5];

#define EPS 1e-10
 
LL MinCostMatching(int n, const VVD cost, VI Lmate, VI Rmate) {
    VD u = {0};
    VD v = {0};
    REP (i, n) {
        u[i] = cost[i][0];
        FOR (j, 1, n-1) u[i] = min(u[i], cost[i][j]);
    }
    REP (j, n) {
        v[j] = cost[0][j] - u[0];
        FOR (i, 1, n-1) v[j] = min(v[j], cost[i][j] - u[i]);
    }
    REP (i, n) Lmate[i] = Rmate[i] = -1;
    int mated = 0;
    REP (i, n) REP (j, n) {
        if (Rmate[j] != -1) continue;
        if (fabs(cost[i][j] - u[i] - v[j]) < EPS) {
            Lmate[i] = j;
            Rmate[j] = i;
            mated++;
            break;
        }
    }
    VD dist = {0};
    VI dad = {0};
    VI seen = {0};
    while (mated < n) {
        int s = 0;
        while (Lmate[s] != -1) s++;
        fill(dad, dad + n, -1);
        fill(seen, seen + n, 0);
        REP (k, n) dist[k] = cost[s][k] - u[s] - v[k];
        int j = 0;
        while (true) {
            j = -1;
            REP (k, n) {
                if (seen[k]) continue;
                if (j == -1 || dist[k] < dist[j]) j = k;
            }
            seen[j] = 1;
            if (Rmate[j] == -1) break;
            const int i = Rmate[j];
            REP (k, n) {
                if (seen[k]) continue;
                const LL new_dist = dist[j] + cost[i][k] - u[i] - v[k];
                if (dist[k] > new_dist) {
                    dist[k] = new_dist;
                    dad[k] = j;
                }
            }
        }
        REP (k, n) {
            if (k == j || !seen[k]) continue;
            const int i = Rmate[k];
            v[k] += dist[k] - dist[j];
            u[i] -= dist[k] - dist[j];
        }
        u[s] += dist[j];
        while (dad[j] >= 0) {
            const int d = dad[j];
            Rmate[j] = Rmate[d];
            Lmate[Rmate[j]] = j;
            j = d;
        }
        Rmate[j] = s;
        Lmate[s] = j;
        mated++;
    }
    LL value = 0;
    REP (i, n) value += cost[i][Lmate[i]];
    return value;
}