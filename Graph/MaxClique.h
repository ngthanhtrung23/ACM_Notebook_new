// MaxClique
// Copied from https://judge.yosupo.jp/submission/15825
//
// 0-based index
//
// Tested:
// - https://judge.yosupo.jp/problem/maximum_independent_set
struct MaxClique {
    static const int MN = 64; // change to bitset for n > 64
    int n, deg[MN];
    uint64_t g[MN], ans;
    vector<pair<int,int>> edges;

    MaxClique(int _n) : n(_n) {
        fill(g, g+n, 0ull);
        fill(deg, deg+n, 0);
        edges.clear();
    }

    // Add bi-directional edge
    // 0-based index
    void addEdge(int u, int v) {
        edges.emplace_back(u, v);
        ++deg[u]; ++deg[v];
    }

    vector<int> solve() {
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&] (int u, int v) { return deg[u] < deg[v]; });
        vector<int> id(n);
        for (int i = 0; i < n; i++) id[ord[i]] = i;

        for (const auto& e : edges) {
            int u = id[e.first], v = id[e.second];
            g[u] |= 1ull << v;
            g[v] |= 1ull << u;
        }
        uint64_t r = 0, p = (1ull << n) - 1;
        ans = 0;
        dfs(r, p);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if ((ans >> i) & 1) res.push_back(ord[i]);
        }
        return res;
    }

#define cnt __builtin_popcountll
    void dfs(uint64_t r, uint64_t p) {
        if (p == 0) {
            if (cnt(r) > cnt(ans)) ans = r;
            return;
        }
        if (cnt(r | p) <= cnt(ans)) return;
        int x = __builtin_ctzll(p & -p);
        uint64_t c = p;
        while (c > 0) {
            x = __builtin_ctzll(c & -c);
            r |= 1ull << x;
            dfs(r, p & g[x]);
            r &= ~(1ull << x);
            p &= ~(1ull << x);
            c ^= 1ull << x;
        }
    }
};
