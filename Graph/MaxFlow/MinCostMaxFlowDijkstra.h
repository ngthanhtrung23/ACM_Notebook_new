// Source: rng_58: http://codeforces.com/contest/277/submission/3212642
// Fast min cost max flow (Dijkstra)
// Index from 0
// NOTE!!!!!! Flow through both direction can be < 0
// --> need to be careful when trace
// Does not work when cost < 0

#define F_INF 1000111000LL
#define C_INF 1000111000LL

template<class Flow = long long, class Cost = long long>
struct MinCostFlow {
    int V, E;
    vector<Flow> cap;
    vector<Cost> cost;
    vector<int> to, prev;

    vector<Cost> dist, pot;
    vector<int> last, path, used;
    priority_queue< pair<Cost, int> > q;

    MinCostFlow(int V, int E) : V(V), E(0), cap(E*2,0), cost(E*2,0), to(E*2,0), prev(E*2,0),
            dist(V,0), pot(V,0), last(V, -1), path(V,0), used(V,0) {}

    int addEdge(int x, int y, Flow f, Cost c) {
        cap[E] = f; cost[E] = c; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
        cap[E] = 0; cost[E] = -c; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
        return E - 2;
    }

    pair<Flow, Cost> search(int s, int t) {
        Flow ansf = 0; Cost ansc = 0;
        REP(i,V) used[i] = false;
        REP(i,V) dist[i] = C_INF;

        dist[s] = 0; path[s] = -1; q.push(make_pair(0, s));
        while (!q.empty()) {
            int x = q.top().second; q.pop();
            if (used[x]) continue; used[x] = true;
            for(int e = last[x]; e >= 0; e = prev[e]) if (cap[e] > 0) {
                Cost tmp = dist[x] + cost[e] + pot[x] - pot[to[e]];
                if (tmp < dist[to[e]] && !used[to[e]]) {
                    dist[to[e]] = tmp;
                    path[to[e]] = e;
                    q.push(make_pair(-dist[to[e]], to[e]));
                }
            }
        }
        REP(i,V) pot[i] += dist[i];
        if (used[t]) {
            ansf = F_INF;
            for(int e=path[t]; e >= 0; e=path[to[e^1]]) ansf = min(ansf, cap[e]);
            for(int e=path[t]; e >= 0; e=path[to[e^1]]) { ansc += cost[e] * ansf; cap[e] -= ansf; cap[e^1] += ansf; }
        }
        return make_pair(ansf, ansc);
    }
    pair<Flow, Cost> minCostFlow(int s, int t) {
        Flow ansf = 0; Cost ansc = 0;
        while (1) {
            pair<Flow, Cost> p = search(s, t);
            if (!used[t]) break;
            ansf += p.first; ansc += p.second;
        }
        return make_pair(ansf, ansc);
    }
};

