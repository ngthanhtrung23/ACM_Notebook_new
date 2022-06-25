// Partially persistent DSU
//
// Supports:
// - Linear history (version t+1 always build on top of version t)
// - Query history information at version t
//
// Tested:
// - https://oj.vnoi.info/problem/vnoicup22_r2_c
struct PartiallyPersistentDSU {
    vector<int> lab, t_unite;

    PartiallyPersistentDSU(int n)
            : lab(n + 1, -1), t_unite(n + 1, INT_MAX) {}

    // return root
    int getRoot(int t, int x) {
        if (t_unite[x] > t) {
            return x;
        }
        return getRoot(t, lab[x]);
    }

    void merge(int t, int x, int y) {
        int root_x = getRoot(t, x);
        int root_y = getRoot(t, y);
        x = root_x; y = root_y;
        if (x == y) {
            return;
        }
        if (lab[x] > lab[y]) {
            std::swap(x, y);
        }
        lab[x] += lab[y];
        lab[y] = x;
        t_unite[y] = t;
    }
};
