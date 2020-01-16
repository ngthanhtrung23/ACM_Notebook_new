// Tested with https://codeforces.com/gym/100551/problem/A
// 0-based
struct Data {
    int time, u, par;  // before `time`, `par` = par[u]
};

struct DSU {
    vector<int> par;
    vector<Data> change;

    void init(int n) {
        par = vector<int> (n + 5, -1);
        change.clear();
    }

    // find root of x.
    // if par[x] < 0 then x is a root, and its tree has -par[x] nodes
    int getRoot(int x) {
        while (par[x] >= 0)
            x = par[x];
        return x;
    }

    // join components containing x and y.
    // t should be current time. We use it to update `change`.
    void join(int x, int y, int t) {
        x = getRoot(x);
        y = getRoot(y);
        //union by rank
        if (par[x] < par[y]) swap(x, y); 
        //now x's tree has less nodes than y's tree
        change.push_back({t, y, par[y]});
        par[y] += par[x];
        change.push_back({t, x, par[x]});
        par[x] = y;
        

    }

    // rollback all changes at time > t.
    void rollback(int t) {
        while (!change.empty() && change.back().time > t) {
            par[change.back().u] = change.back().par;
            change.pop_back();
        }
    }
};
