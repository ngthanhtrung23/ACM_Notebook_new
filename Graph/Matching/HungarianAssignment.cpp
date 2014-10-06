#include "../../template.h"

const int maxn = 511;
const int inf = 1000111000;

// Vertex: 1 --> nx, 1 --> ny
// cost >= 0
// fx[x] + fy[y] <= cost[x][y] for all x, y

struct Hungary {
    int nx, ny, cost[maxn][maxn], fx[maxn], fy[maxn], maty[maxn], which[maxn], dist[maxn];
    bool used[maxn];

    void init(int _nx, int _ny) {
        nx = _nx; ny = _ny;
        memset(fx, 0, sizeof fx);
        memset(fy, 0, sizeof fy);
        FOR(i, 0, nx) FOR(j, 0, ny) cost[i][j] = inf;
    }

    void add(int x, int y, int c) { cost[x][y] = c; }

    int mincost() {
        FOR(x, 1, nx) {
            int y0 = 0; maty[0] = x;
            FOR(y, 0, ny) { dist[y] = inf + 1; used[y] = false; }

            do {
                used[y0] = true;
                int x0 = maty[y0], delta = inf + 1, y1;

                FOR(y, 1, ny) if (!used[y]) {
                    int curdist = cost[x0][y] - fx[x0] - fy[y];
                    if (curdist < dist[y]) {
                        dist[y] = curdist;
                        which[y] = y0;
                    }
                    if (dist[y] < delta) {
                        delta = dist[y];
                        y1 = y;
                    }
                }

                FOR(y, 0, ny) if (used[y]) {
                    fx[maty[y]] += delta;
                    fy[y] -= delta;
                } else dist[y] -= delta;

                y0 = y1;
            } while (maty[y0] != 0);

            do {
                int y1 = which[y0];
                maty[y0] = maty[y1];
                y0 = y1;
            } while (y0);
        }
//      return -fy[0]; // nếu luôn đảm bảo có bộ ghép đầy đủ
        int ret = 0;
        FOR(y, 1, ny) {
            int x = maty[y];
            if (cost[x][y] < inf) ret += cost[x][y];
        }
        return ret;
    }
} hungary;

int main() {
}