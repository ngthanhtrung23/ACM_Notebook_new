// Max matching on general graph
// Copied from https://judge.yosupo.jp/submission/61234
//
// Notes:
// - Index from 0
//
// Tested:
// - https://judge.yosupo.jp/problem/general_matching
// - https://oj.vnoi.info/problem/qbflower
// - https://uoj.ac/problem/79
// - https://acm.timus.ru/problem.aspx?space=1&num=1099

struct GeneralMatching {
    GeneralMatching(int _n) : n(_n), match(_n, -1), g(_n),
            timer(-1), label(_n), parent(_n), orig(_n), aux(_n, -1) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int get_match() {
        for (int i = 0; i < n; i++) {
            if (match[i] == -1) bfs(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (match[i] >= 0) ++res;
        }
        return res / 2;
    }

    int n;
    vector<int> match;

private:
    int lca(int x, int y) {
        for (timer++; ; swap(x, y)) {
            if (x == -1) continue;
            if (aux[x] == timer) return x;
            aux[x] = timer;
            x = (match[x] == -1 ? -1 : orig[parent[match[x]]]);
        }
    }

    void blossom(int v, int w, int a) {
        while (orig[v] != a) {
            parent[v] = w;
            w = match[v];
            if (label[w] == 1) {
                label[w] = 0;
                q.push_back(w);
            }
            orig[v] = orig[w] = a;
            v = parent[w];
        }
    }

    void augment(int v) {
        while (v != -1) {
            int pv = parent[v], nv = match[pv];
            match[v] = pv; match[pv] = v; v = nv;
        }
    }

    int bfs(int root) {
        fill(label.begin(), label.end(), -1);
        iota(orig.begin(), orig.end(), 0);
        q.clear();
        label[root] = 0;
        q.push_back(root);
        for (int i = 0; i < (int) q.size(); ++i) {
            int v = q[i];
            for (auto x : g[v]) {
                if (label[x] == -1) {
                    label[x] = 1;
                    parent[x] = v;
                    if (match[x] == -1) {
                        augment(x);
                        return 1;
                    }
                    label[match[x]] = 0;
                    q.push_back(match[x]);
                } else if (label[x] == 0 && orig[v] != orig[x]) {
                    int a = lca(orig[v], orig[x]);
                    blossom(x, v, a);
                    blossom(v, x, a);
                }
            }
        }
        return 0;
    }

private:
    vector<vector<int>> g;
    int timer;
    vector<int> label, parent, orig, aux, q;
};
