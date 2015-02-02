// L[i] = level
// L[root] = -1
// LCA[0][root] = -1
const int MN = 100111;
int V, LCA[22][MN], L[MN];
long long Rmax[22][MN];
#define LL long long
inline void initLCA () {
    FOR (lg, 1, 19) {
        REP (i, V) {
            if (LCA[lg - 1][i] == -1) continue;
            LCA[lg][i] = LCA[lg - 1][LCA[lg - 1][i]];
            Rmax[lg][i] = max (Rmax[lg - 1][LCA[lg - 1][i]], Rmax[lg - 1][i]);
        }
    }
}

inline LL query (LL a, LL b) {
    LL ret = 0;
    if (L[a] < L[b]) swap (a, b);

    FORD(lg,19,0) {
        if (LCA[lg][a] != -1 && L[LCA[lg][a]] >= L[b]) {
            ret = max (ret, Rmax[lg][a]);
            a = LCA[lg][a];
        }
    }
    if (a == b) return ret; // if LCA, return a
    FORD(lg,19,0) {
        if (LCA[lg][a] != LCA[lg][b]) {
            ret = max (ret, Rmax[lg][a]);
            ret = max (ret, Rmax[lg][b]);
            a = LCA[lg][a];
            b = LCA[lg][b];
        }
    }
    ret = max (ret, Rmax[0][a]);
    ret = max (ret, Rmax[0][b]);
    return ret; // if LCA, return LCA[0][a]
}

