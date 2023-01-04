// NOTE:
// - MaxFlowHLPP is probably faster
// - UNDIRECTED ONLY (for directed seems there's some infinite loop)
// - Index from 0
//
// Tested:
// - https://www.spoj.com/problems/FFLOW/ (undirected)
// - https://www.spoj.com/problems/FASTFLOW/ (undirected)
// - https://www.spoj.com/problems/MATCHING/ (matching)
//
// Max flow LMH {{{
struct Edge {
    int u, v, c, f;
    int next;
};
 
struct MaxFlow {
    int n, s, t;
    vector< Edge > edges;
    vector<int> head, current, h, avail;
    vector<long long> excess;
 
    MaxFlow(int _n) : n(_n), head(n, -1), current(n, -1), h(n), avail(n), excess(n) {
        edges.clear();
    }
 
    void addEdgeUndirected(int u, int v, int c) {
        Edge xuoi = {u, v, c, 0, head[u]};
        head[u] = edges.size(); edges.push_back(xuoi);
        Edge nguoc = {v, u, c, 0, head[v]};
        head[v] = edges.size(); edges.push_back(nguoc);
    }
 
    long long getFlow(int _s, int _t) {
        s = _s; t = _t;
        init();
 
        int now = 0;
        queue<int> qu[2];
        for (int x = 0; x < n; ++x)
            if (x != s && x != t && excess[x] > 0)
                qu[now].push(x);
        
        globalLabeling();
 
        int cnt = 0;
        while (!qu[now].empty()) {
            while (!qu[1-now].empty()) qu[1-now].pop();
 
            while (!qu[now].empty()) {
                int x = qu[now].front(); qu[now].pop();
                while (current[x] >= 0) {
                    int p = current[x];
                    if (edges[p].c > edges[p].f && h[edges[p].u] > h[edges[p].v]) {
                        bool need = (edges[p].v != s && edges[p].v != t && !excess[edges[p].v]);
                        push(current[x]);
                        if (need) qu[1-now].push(edges[p].v);
                        if (!excess[x]) break;
                    }
                    current[x] = edges[current[x]].next;
                }
                
                if (excess[x] > 0) {
                    lift(x);
                    current[x] = head[x];
                    qu[1-now].push(x);
                    cnt++;
                    if (cnt == n) {
                        globalLabeling();
                        cnt=0;
                    }
                }
            }
            now = 1 - now;
        }
        return excess[t];
    }
 
private:
    void init() {
        current = head;
 
        int p = head[s];
        while (p >= 0) {
            edges[p].f = edges[p].c;
            edges[p^1].f -= edges[p].c;
            excess[edges[p].v] += edges[p].c;
            excess[s] -= edges[p].c;
            p = edges[p].next;
        }
        std::fill(h.begin(), h.end(), 1);
        h[s] = n; h[t] = 0;
    }
 
    void push(int i) {
        long long delta = min(excess[edges[i].u], (long long) edges[i].c - edges[i].f);
        edges[i].f += delta; edges[i^1].f -= delta;
        excess[edges[i].u] -= delta;
        excess[edges[i].v] += delta;
    }
 
    void lift(int u) {
        int minH = 2 * n;
        int p = head[u];
        while (p>=0) {
            if (edges[p].c > edges[p].f)
                minH = min(minH, h[edges[p].v]);
            p = edges[p].next;
        }
        h[u] = minH + 1;
    }
 
    void globalLabeling() {
        std::fill(avail.begin(), avail.end(), 1);
        std::fill(h.begin(), h.end(), 0);
        h[s] = n; h[t] = 0;
        queue<int> q; q.push(t); avail[t] = false;
 
        while (!q.empty()) {
            int x = q.front(); q.pop();
            int p = head[x];
            while (p >= 0) {
                int pp = p^1;
                if (avail[edges[pp].u] && edges[pp].f < edges[pp].c) {
                    h[edges[pp].u] = h[x] + 1;
                    avail[edges[pp].u] = 0;
                    q.push(edges[pp].u);
                }
                p = edges[p].next;
            }
            if (q.empty() && avail[s]) {
                avail[s] = false;
                q.push(s);
            }
        }
        current = head;
    }
};
// }}}
