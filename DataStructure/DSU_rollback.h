struct Data {
    int time, u, par;  // before `time`, `par` = par[u]
};

struct DSU {
    vector<int> par;
    vector<Data> change;

    void init(int n) {
        par = vector<int> (n + 5, 0);
        REP(i, n+5) par[i] = i;
        change.clear();
    }

    // find root of x.
    // t should be current time. We use it to update `change`.
    int getRoot(int x, int t) {
        if (par[x] != x) {
            change.push_back({t, x, par[x]});
            par[x] = getRoot(par[x], t);
        }
        return par[x];
    }

    // join components containing x and y.
    // t should be current time. We use it to update `change`.
    void join(int x, int y, int t) {
        x = getRoot(x, t);
        y = getRoot(y, t);
        if (x != y) {
            change.push_back({t, x, par[x]});
            par[x] = y;
        }
    }

    // rollback all changes at time >= t.
    void rollback(int t) {
        while (!change.empty() && change.back().time == t) {
            par[change.back().u] = change.back().par;
            change.pop_back();
        }
    }
};
