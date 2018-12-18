// Push relabel in O(V^2 E^0.5) with gap heuristic
// Source: https://github.com/dacin21/dacin21_codebook/blob/master/flow/maxflow_short.cpp
//
// Notes:
// - Index from 0
// - Does not work with unsigned types.
//
// Usage:
// 
// PushRelabel<int> flow(n);
// flow.addEdge(u, v, f);  // directed
// flow.addEdge(u, v, f, f);  // undirected
// int maxFlow = flow.maxFlow(s, t);
//
// Tested:
// - http://vn.spoj.com/problems/NKFLOW/ (directed)
// - http://vn.spoj.com/problems/FFLOW/  (undirected)
// - http://www.spoj.com/problems/FASTFLOW/  (undirected)
// - https://codeforces.com/problemset/problem/269/C  (with trace).
//
// TLE on https://www.lydsy.com/JudgeOnline/problem.php?id=1001. Why? (ACed with Dinic flow).

template<typename flow_t = long long>
struct PushRelabel {
    struct Edge {
        int to, rev;
        flow_t f, c;
    };
    vector<vector<Edge> > g;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

    int addEdge(int s, int t, flow_t cap, flow_t rcap=0) {
        if (s == t) return -1;
        Edge a = {t, (int)g[t].size(), 0, cap};
        Edge b = {s, (int)g[s].size(), 0, rcap};
        g[s].push_back(a);
        g[t].push_back(b);

        // Return ID of forward edge.
        return b.rev;
    }

    flow_t maxFlow(int s, int t) {
        int v = g.size();
        H[s] = v;
        ec[t] = 1;
        vector<int> co(2*v);
        co[0] = v-1;
        for (int i = 0; i < v; ++i) {
            cur[i] = g[i].data();
        }
        for (auto &e : g[s]) {
            add_flow(e, e.c);
        }
        if (hs[0].size()) {
            for (int hi = 0; hi >= 0;) {
                int u = hs[hi].back();
                hs[hi].pop_back();
                while (ec[u] > 0) { // discharge u
                    if (cur[u] == g[u].data() + g[u].size()) {
                        H[u] = 1e9;
                        for (auto &e : g[u]) {
                            if (e.c && H[u] > H[e.to]+1) {
                                H[u] = H[e.to]+1;
                                cur[u] = &e;
                            }
                        }
                        if (++co[H[u]], !--co[hi] && hi < v) {
                            for (int i = 0; i < v; ++i) {
                                if (hi < H[i] && H[i] < v){
                                    --co[H[i]];
                                    H[i] = v + 1;
                                }
                            }
                        }
                        hi = H[u];
                    } else if (cur[u]->c && H[u] == H[cur[u]->to] + 1) {
                        add_flow(*cur[u], min(ec[u], cur[u]->c));
                    }
                    else {
                        ++cur[u];
                    }
                }
                while (hi>=0 && hs[hi].empty()) --hi;
            }
        }
        return -ec[s];
    }

private:
    vector<flow_t> ec;
    vector<Edge*> cur;
    vector<vector<int> > hs;
    vector<int> H;

    void add_flow(Edge& e, flow_t f) {
        Edge &back = g[e.to][e.rev];
        if (!ec[e.to] && f) {
            hs[H[e.to]].push_back(e.to);
        }
        e.f += f; e.c -= f;
        ec[e.to] += f;
        back.f -= f; back.c += f;
        ec[back.to] -= f;
    }
};
