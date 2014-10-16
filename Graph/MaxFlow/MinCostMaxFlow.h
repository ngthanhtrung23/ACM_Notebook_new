/*
 * mincostflow implementation. Vertex indices from 0
 * Usage:
 *   for i = 1..N: int v = mcf.addV();
 *   for i = 1..E: MinCostFlow<int,int>::Edge* e = mcf.addEdge(u, v, flow, cost);
 *   mcf.minCostFlow --> return pair<flow, cost>
 * DANGEROUS!!!!!!! If need to find flow through each edge, remember that there can
 * be flow through both (u, v) and (v, u)
 */

// Slow version (Ford Bellman)
// Can work with negative edges. (not loop!)
// Must be careful when used with double.

#define _MAX_COST INT_MAX
#define _MAX_FLOW INT_MAX

template<class Flow = int, class Cost = int>
struct MinCostFlow {
    struct Edge {
        int t;
        Flow f;
        Cost c;
        Edge*next, *rev;
        Edge(int _t, Flow _f, Cost _c, Edge*_next) :
                t(_t), f(_f), c(_c), next(_next) {
        }
    };
    vector<Edge*> E;

    int addV() {
        E.push_back((Edge*) 0);
        return E.size() - 1;
    }
    Edge* makeEdge(int s, int t, Flow f, Cost c) {
        return E[s] = new Edge(t, f, c, E[s]);
    }
    Edge* addEdge(int s, int t, Flow f, Cost c) {
        Edge*e1 = makeEdge(s, t, f, c), *e2 = makeEdge(t, s, 0, -c);
        e1->rev = e2, e2->rev = e1;
        return e1;
    }
    pair<Flow, Cost> minCostFlow(int vs, int vt) {
        int n = E.size();
        Flow flow = 0;
        Cost cost = 0;
        const Cost MAX_COST = _MAX_COST;
        const Flow MAX_FLOW = _MAX_FLOW;
        for (;;) {
            vector<Cost> dist(n, MAX_COST);
            vector<Flow> am(n, 0);
            vector<Edge*> prev(n);
            vector<bool> inQ(n, false);
            queue<int> que;

            dist[vs] = 0;
            am[vs] = MAX_FLOW;
            que.push(vs);
            inQ[vs] = true;

            while (!que.empty()) {
                int u = que.front();
                Cost c = dist[u];
                que.pop();
                inQ[u] = false;
                for (Edge*e = E[u]; e; e = e->next)
                    if (e->f > 0) {
                        Cost nc = c + e->c;
                        if (nc < dist[e->t]) {
                            dist[e->t] = nc;
                            prev[e->t] = e;
                            am[e->t] = min(am[u], e->f);
                            if (!inQ[e->t]) {
                                que.push(e->t);
                                inQ[e->t] = true;
                            }
                        }
                    }
            }

            if (dist[vt] == MAX_COST) // careful with double
                break;
            Flow by = am[vt];
            int u = vt;
            flow += by;
            cost += by * dist[vt];
            while (u != vs) {
                Edge*e = prev[u];
                e->f -= by;
                e->rev->f += by;
                u = e->rev->t;
            }
        }
        return make_pair(flow, cost);
    }
};
