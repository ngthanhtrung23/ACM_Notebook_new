inline void initLCA () {
    FOR (lg, 1, 19) {
        REP (i, V) {
            if (LCA[lg - 1][i] == -1) continue;
            LCA[lg][i] = LCA[lg - 1][LCA[lg - 1][i]];
            RMAX[lg][i] = MAX (RMAX[lg - 1][LCA[lg - 1][i]], RMAX[lg - 1][i]);
        }
    }
}

inline LL query (LL a, LL b) {
    LL ret = 0;
    if (L[a] < L[b]) swap (a, b);

    REPD (lg, 20) {
        if (LCA[lg][a] != -1 && L[LCA[lg][a]] >= L[b]) {
            ret = MAX (ret, RMAX[lg][a]);
            a = LCA[lg][a];
        }
    }
    if (a == b) return ret; // if LCA, return a
    REPD (lg, 20) {
        if (LCA[lg][a] != LCA[lg][b]) {
            ret = MAX (ret, RMAX[lg][a]);
            ret = MAX (ret, RMAX[lg][b]);
            a = LCA[lg][a];
            b = LCA[lg][b];
        }
    }
    ret = MAX (ret, RMAX[0][a]);
    ret = MAX (ret, RMAX[0][b]);
    return ret; // if LCA, return LCA[0][a]
}