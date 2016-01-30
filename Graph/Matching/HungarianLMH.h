// Index from 1
// Min cost matching
// Usage: init(); for[i,j,cost] addEdge(i, j, cost)

#define arg __arg
long long c[MN][MN];
long long fx[MN], fy[MN];
int mx[MN], my[MN];
int trace[MN], qu[MN], arg[MN];
long long d[MN];
int front, rear, start, finish;

void init() {
    FOR(i,1,n) {
        fy[i] = mx[i] = my[i] = 0;
        FOR(j,1,n) c[i][j] = inf;
    }
}

void addEdge(int i, int j, long long cost) {
    c[i][j] = min(c[i][j], cost);
}

inline long long getC(int i, int j) {
    return c[i][j] - fx[i] - fy[j];
}

void initBFS() {
    front = rear = 1;
    qu[1] = start;
    memset(trace, 0, sizeof trace);
    FOR(j,1,n) {
        d[j] = getC(start, j);
        arg[j] = start;
    }
    finish = 0;
}

void findAugPath() {
    while (front <= rear) {
        int i = qu[front++];
        FOR(j,1,n) if (!trace[j]) {
            long long w = getC(i, j);
            if (!w) {
                trace[j] = i;
                if (!my[j]) {
                    finish = j;
                    return ;
                }
                qu[++rear] = my[j];
            }
            if (d[j] > w) {
                d[j] = w;
                arg[j] = i;
            }
        }
    }
}

void subx_addy() {
    long long delta = inf;
    FOR(j,1,n)
        if (trace[j] == 0 && d[j] < delta) delta = d[j];

    // xoay
    fx[start] += delta;
    FOR(j,1,n)
        if (trace[j]) {
            int i = my[j];
            fy[j] -= delta;
            fx[i] += delta;
        }
        else d[j] -= delta;

    FOR(j,1,n)
        if (!trace[j] && !d[j]) {
            trace[j] = arg[j];
            if (!my[j]) { finish = j; return ; }
            qu[++rear] = my[j];
        }
}

void enlarge() {
    do {
        int i = trace[finish];
        int next = mx[i];
        mx[i] = finish;
        my[finish] = i;
        finish = next;
    } while (finish);
}

int mincost() {
    FOR(i,1,n) fx[i] = *min_element(c[i]+1, c[i]+n+1);
    FOR(i,1,n) {
        start = i;
        initBFS();
        while (finish == 0) {
            findAugPath();
            if (!finish) subx_addy();
        }
        enlarge();
    }
    int res = 0;
    FOR(i,1,n) res += c[i][mx[i]];
    return res;
}
