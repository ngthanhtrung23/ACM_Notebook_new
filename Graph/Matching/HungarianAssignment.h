const int MN = 3210;
const int inf = 1000111000;

// Vertex: 1 --> nx, 1 --> ny
// cost >= 0
// fx[x] + fy[y] <= cost[x][y] for all x, y
// Min cost matching

struct Hungary {
    int nx, ny, cost[MN][MN], fx[MN], fy[MN], matx[MN], which[MN], dist[MN];
    bool used[MN];

    void init(int _nx, int _ny) {
        nx = _nx; ny = _ny;
        memset(fx, 0, sizeof fx);
        memset(fy, 0, sizeof fy);
        memset(used, false, sizeof used);
        memset(matx, 0, sizeof matx);
        for(int i=0; i<=nx; ++i) for(int j=0; j<=ny; ++j) cost[i][j] = inf;
    }

    void add(int x, int y, int c) { cost[x][y] = min(cost[x][y],c); }

    int mincost() {
        for(int x=1; x<=nx; ++x) {
            int y0 = 0; matx[0] = x;
            for(int y=0; y<=ny; ++y) { dist[y] = inf + 1; used[y] = false; }

            do {
                used[y0] = true;
                int x0 = matx[y0], delta = inf + 1, y1;

                for(int y=1; y<=ny; ++y) if (!used[y]) {
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

                for(int y=0; y<=ny; ++y) if (used[y]) {
                    fx[matx[y]] += delta;
                    fy[y] -= delta;
                } else dist[y] -= delta;

                y0 = y1;
            } while (matx[y0] != 0);

            do {
                int y1 = which[y0];
                matx[y0] = matx[y1];
                y0 = y1;
            } while (y0);
        }
//      return -fy[0]; // nếu luôn đảm bảo có bộ ghép đầy đủ
        int ret = 0;
        for(int y=1; y<=ny; ++y) {
            int x = matx[y];
            if (cost[x][y] < inf) ret += cost[x][y];
        }
        return ret;
    }
} hungary;

