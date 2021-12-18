// Max matching on general graph
// Copied from https://judge.yosupo.jp/submission/51961
//
// It's short and seems to run fast..
//
// Notes:
// - Index from 0
//
// Tested:
// - https://judge.yosupo.jp/problem/general_matching
// - https://oj.vnoi.info/problem/qbflower

struct GeneralMatching {
    GeneralMatching(int _n) : n(_n), g(_n) {}

    void add_edge(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        assert(a != b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int get_match() {
        match.assign(n, -1);
        hits.assign(n, 0);
        for (int i = 0; i < n; i++) if (!g[i].empty()) {
            unmatched.emplace(0, i);
        }

        /////// If WA, increase this
        // there are some cases that need >=1.3*n^2 steps for BLOCK=1
        // no idea what the actual bound needed here is.
        const int MAX_STEPS = 10 + 2*n + n*n/BLOCK/2;
        for (int it = 0; it < MAX_STEPS; ++it) {
            if (unmatched.empty()) break;
            int u = unmatched.top().second;
            unmatched.pop();
            if (match[u] != -1) continue;

            for (int it2 = 0; it2 < BLOCK; it2++) {
                ++hits[u];
                auto &e = g[u];
                const int v = e[get_rand(e.size())];
                match[u] = v;
                swap(u, match[v]);
                if (u == -1) break;
            }
            if (u != -1) {
                match[u] = -1;
                unmatched.emplace(hits[u] * 100ull / (g[u].size() + 1), u);
            }
        }
        int size = 0;
        for (auto& e : match) size += (e != -1);
        return size / 2;
    }

    vector<int> match;

private:
    template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
    const int BLOCK = 10;

    int n;
    vector<vector<int> > g;
    vector<int> hits;
    min_heap<pair<uint64_t, int> > unmatched;
};
