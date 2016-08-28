// Source: e-maxx.ru
// Tested with: VOJ - NKFLOW, VOJ - MCQUERY (Gomory Hu)

// Usage:
// MaxFlow flow(n)
// For each edge: flow.addEdge(u, v, c, edge_id)
// flow.getMaxFlow(s, t)
// flow.trace()
// Index from 0

// Tested:
// - https://open.kattis.com/problems/maxflow
const int INF = 1000111000111000111LL;
 
struct Edge {
    int a, b, cap, flow, id;
};

struct MaxFlow {
    int n, s, t;
    vector<int> d, ptr, q;
    vector< Edge > e;
    vector< vector<int> > g;

    MaxFlow(int n) : n(n), d(n), ptr(n), q(n), g(n) {
        e.clear();
        REP(i,n) {
            g[i].clear();
            ptr[i] = 0;
        }
    }

    void addEdge(int a, int b, int cap, int id) {
        Edge e1 = { a, b, cap, 0, id };
        Edge e2 = { b, a, 0, 0, id };
        g[a].push_back( (int) e.size() );
        e.push_back(e1);
        g[b].push_back( (int) e.size() );
        e.push_back(e2);
    }
    int getMaxFlow(int _s, int _t) {
        s = _s; t = _t;
        int flow = 0;
        for (;;) {
            if (!bfs()) break;
            REP(i,n) ptr[i] = 0;
            while (int pushed = dfs(s, INF))
                flow += pushed;
        }
        return flow;
    }

    vector<int> trace() {
        bfs();
        vector<int> res;
        for(auto edge : e) {
            if (d[edge.a] >= 0 && d[edge.b] < 0 && edge.cap > 0) {
                res.push_back(edge.id);
            }
        }
        return res;
    }

private:
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        REP(i,n) d[i] = -1;
        d[s] = 0;

        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            REP(i,g[v].size()) {
                int id = g[v][i], to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        if (!flow) return 0;
        if (v == t) return flow;
        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
                to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
};

