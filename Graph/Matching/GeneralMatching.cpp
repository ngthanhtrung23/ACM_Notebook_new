const int MAXN = 411;
int n;
vector<int> g[MAXN];
int match[MAXN], p[MAXN], base[MAXN], q[MAXN];
bool used[MAXN], blossom[MAXN];

int lca(int a, int b) {
    bool used[MAXN] = { 0 };
    for(;;) {
        a = base[a]; used[a] = true;
        if (match[a] == -1)  break;
        a = p[match[a]];
    }
    for(;;) {
        b = base[b];
        if (used[b]) return b;
        b = p[match[b]];
    }
}
void mark_path(int v, int b, int children) {
    while (base[v] != b) {
        blossom[base[v]] = blossom[base[match[v]]] = true;
        p[v] = children; children = match[v]; v = p[match[v]];
    }
}
int find_path(int root) {
    memset(used, 0, sizeof used); memset(p, -1, sizeof p);
    REP(i,n) base[i] = i;
    used[root] = true;
    int qh=0, qt=0;
    q[qt++] = root;
    while (qh < qt) {
        int v = q[qh++];
        REP(i,g[v].size()) {
            int to = g[v][i];
            if (base[v] == base[to] || match[v] == to)  continue;
            if (to == root || match[to] != -1 && p[match[to]] != -1) {
                int curbase = lca (v, to);
                memset (blossom, 0, sizeof blossom);
                mark_path (v, curbase, to); mark_path (to, curbase, v);
                REP(i,n)
                    if (blossom[base[i]]) {
                        base[i] = curbase;
                        if (!used[i]) { used[i] = true; q[qt++] = i; }
                    }
            }
            else if (p[to] == -1) {
                p[to] = v;
                if (match[to] == -1) return to;
                to = match[to]; used[to] = true; q[qt++] = to;
            }
        }
    }
    return -1;
}
// Usage: Init n, g
          memset (match, -1, sizeof match);
          REP(i,n) if (match[i] == -1)
                REP(j, g[i].size())
                     if (match[g[i][j]] == -1) {
                          match[g[i][j]] = i; match[i] = g[i][j];
                          break;
                     }
          REP(i,n) if (match[i] == -1) {
                int v = find_path(i);
                while (v != -1) {
                     int pv = p[v], ppv = match[pv];
                     match[v] = pv, match[pv] = v;
                     v = ppv;
                }
          }