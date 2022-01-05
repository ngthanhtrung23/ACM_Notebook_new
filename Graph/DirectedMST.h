// include DSU_rollback.h

// Directed MST
// Index from 0
//
// Tested:
// - https://judge.yosupo.jp/problem/directedmst

using ll = long long;
struct Edge {
    int u, v;  // directed, u -> v
    ll cost;
};
struct HeapNode {  // lazy skew heap node
    Edge key;
    HeapNode *l, *r;
    ll delta;

    void prop() {
        key.cost += delta;
        if (l) l->delta += delta;
        if (r) r->delta += delta;
        delta = 0;
    }
    Edge top() {
        prop();
        return key;
    }
};
HeapNode* merge(HeapNode *a, HeapNode *b) {
    if (!a) return b;
    if (!b) return a;
    a->prop(); b->prop();
    if (a->key.cost > b->key.cost) swap(a, b);
    swap(a->l, (a->r = merge(b, a->r)));
    return a;
}
void pop(HeapNode *&a) {
    a->prop();
    a = merge(a->l, a->r);
}

// return {cost, parent[i]}
// parent[root] = -1
// Not found -> return {-1, {}}
pair<ll, vector<int>> directed_mst(int n, int root, vector<Edge>& edges) {
    DSU dsu(n);
    int dsu_time = 0;
    vector<HeapNode*> heap(n);
    for (const Edge& e : edges) {
        heap[e.v] = merge(heap[e.v], new HeapNode{e});
    }

    ll res = 0;
    vector<int> seen(n, -1), path(n);
    seen[root] = root;
    vector<Edge> Q(n), in(n, {-1, -1});
    deque<tuple<int, int, vector<Edge>>> cycs;
    for (int s = 0; s < n; ++s) {
        int u = s, qi = 0, w;
        while (seen[u] < 0) {
            if (!heap[u]) return {-1, {}};
            Edge e = heap[u]->top();
            heap[u]->delta -= e.cost;
            pop(heap[u]);
            Q[qi] = e;
            path[qi++] = u;
            seen[u] = s;
            res += e.cost;
            u = dsu.getRoot(e.u);

            if (seen[u] == s) {
                HeapNode* cyc = 0;
                int end = qi;
                int time = dsu_time;
                do {
                    cyc = merge(cyc, heap[w = path[--qi]]);
                } while (dsu.join(u, w, ++dsu_time));

                u = dsu.getRoot(u);
                heap[u] = cyc;
                seen[u] = -1;
                cycs.push_front({u, time, {&Q[qi], &Q[end]}});
            }
        }
        for (int i = 0; i < qi; i++) in[dsu.getRoot(Q[i].v)] = Q[i];
    }

    for (auto& [u, t, comp] : cycs) {
        dsu.rollback(t);
        Edge inEdge = in[u];
        for (auto& e : comp) in[dsu.getRoot(e.v)] = e;
        in[dsu.getRoot(inEdge.v)] = inEdge;
    }

    vector<int> par(n);
    for (int i = 0; i < n; i++) par[i] = in[i].u;
    return {res, par};
}
