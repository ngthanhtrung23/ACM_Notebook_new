#include "DSU_rollback.h"

// Index from 0
// Tested:
// - https://codeforces.com/gym/100551/problem/A
// - https://www.spoj.com/problems/DYNACON2/
//
// Dynamic connectivity {{{
namespace DynamicConnectivity {
    enum QueryType { ADD, REM, IS_CONNECTED, N_COMPONENTS };
    struct Query {
        QueryType typ;
        int u, v;
    };

    // Segment tree: for each node maintaining [l, r], store all the
    // edges covering all times between l and r.
    vector<vector<pair<int,int>>> edges;
    vector<Query> queries;

    void update(int i, int l, int r, int u, int v, const pair<int,int>& e) {
        if (v < l || r < u) return;
        if (u <= l && r <= v) {
            edges[i].push_back(e);
            return;
        }
        int mid = (l + r) / 2;
        update(i*2, l, mid, u, v, e);
        update(i*2+1, mid+1, r, u, v, e);
    }

    void dfs(
            int i, int l, int r,
            int current_time, int n_connected_components,
            DSU& dsu,
            vector<int>& res) {
        for (auto [u, v] : edges[i]) {
            if (!dsu.same_component(u, v)) {
                --n_connected_components;
            }
            dsu.join(u, v, current_time);
        }

        if (l == r) {
            if (queries[l].typ == IS_CONNECTED) {
                int u = queries[l].u, v = queries[l].v;
                res[l] = dsu.same_component(u, v);
            } else if (queries[l].typ == N_COMPONENTS) {
                res[l] = n_connected_components;
            }
            return;
        }

        int mid = (l + r) / 2;
        dfs(i*2, l, mid, current_time + 1, n_connected_components, dsu, res);
        dsu.rollback(current_time);
        dfs(i*2+1, mid+1, r, current_time + 1, n_connected_components, dsu, res);
    }

    // Returns: vector of length |Q|
    // The i-th element is answer for i-th query
    //     -1 if the i-th query is ADD or REM
    vector<int> solve(int n, const vector<Query>& _queries) {
        queries = _queries;
        edges.clear();
        edges.resize(4 * queries.size());

        map<pair<int,int>, int> addTimes;

        int q = queries.size();
        for (int i = 0; i < q; ++i) {
            const auto& query = queries[i];
            if (query.typ == ADD) {
                int u = query.u, v = query.v;
                if (u > v) swap(u, v);
                auto p = make_pair(u, v);
                assert(!addTimes.count(p));

                addTimes[p] = i;
            } else if (query.typ == REM) {
                int u = query.u, v = query.v;
                if (u > v) swap(u, v);
                auto p = make_pair(u, v);
                assert(addTimes.count(p));

                update(1, 0, q-1, addTimes[p], i, p);

                addTimes.erase(p);
            }
        }
        for (const auto& [e, startTime] : addTimes) {
            update(1, 0, q-1, startTime, q-1, e);
        }

        vector<int> res(queries.size(), -1);
        if (q > 0) {
            DSU dsu(n);
            dfs(1, 0, q-1, 0, n, dsu, res);
        }
        return res;
    }
}
// }}}
