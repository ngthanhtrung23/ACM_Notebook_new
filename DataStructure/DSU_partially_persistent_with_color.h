// Partially persistent DSU
//
// Supports:
// - Linear history (version t+1 always build on top of version t)
// - Query history information at version t
//
// Tested:
// - https://oj.vnoi.info/problem/hello22_schoolplan
struct PartiallyPersistentDSU {
    vector<int> lab, colors, t_unite;  // colors[u] = 0/1 -> same/diff colors from parent

    PartiallyPersistentDSU(int n)
            : lab(n + 1, -1), colors(n + 1, 0), t_unite(n + 1, INT_MAX) {
    }

    // return {root, u same color as root?}
    pair<int,int> getRoot(int t, int x) {
        if (t_unite[x] > t) {
            return { x, 0 };
        }
        auto [r, col] = getRoot(t, lab[x]);
        return {r, col ^ colors[x]};
    }

    // return false if cannot merge u and v
    bool canMerge(int t, int x, int y) {
        auto [root_x, color_x] = getRoot(t, x);
        auto [root_y, color_y] = getRoot(t, y);
        if (root_x == root_y) {
            return color_x != color_y;
        }
        return true;
    }

    bool merge(int t, int x, int y) {
        auto [root_x, color_x] = getRoot(t, x);
        auto [root_y, color_y] = getRoot(t, y);
        x = root_x; y = root_y;
        if (x == y) {
            return color_x != color_y;
        }
        if (lab[x] > lab[y]) {
            std::swap(x, y);
            std::swap(color_x, color_y);
        }
        lab[x] += lab[y];
        lab[y] = x;
        // Note that here we are connecting x and y, not root_x and root_y
        // So we need to set colors according to colors of x and y
        // (relative to their roots)
        colors[y] = color_x == color_y;
        t_unite[y] = t;
        return true;
    }
};
