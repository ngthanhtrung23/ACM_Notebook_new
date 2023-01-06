template<class S>
struct WeightedDSU {
    std::vector<int> lab;
    std::vector<S> w;  // relative to parent

    WeightedDSU(int n) : lab(n, -1), w(n) {}

    int getRoot(int u) {
        if (lab[u] < 0) return u;
        return getRoot(lab[u]);
    }

    int weight(int u) {
        if (lab[u] < 0) return w[u];
        return w[u] + weight(lab[u]);
    }

    // weight(t) = weight(s) + diff
    // returns false if contradicts
    bool merge(int s, int t, S diff) {
        // jump to root
        diff = diff + weight(s) - weight(t);
        s = getRoot(s);
        t = getRoot(t);
        if (s == t) return diff == 0;
        if (lab[s] > lab[t]) {
            std::swap(s, t);
            diff = -diff;
        }
        lab[s] += lab[t];
        lab[t] = s;
        w[t] = diff;
        return true;
    }
};
