// PersistentDSU
//
// Notes:
// - this doesn't support delete edge operation, so isn't enough to
//   solve dynamic connectivity problem.
// - it has high mem and time usage, so be careful (both TLE and MLE on
//   https://oj.vnoi.info/problem/hello22_schoolplan)
//
// Tested:
// - https://judge.yosupo.jp/problem/persistent_unionfind
#include "PersistentArray.h"
struct PersistentDSU {
    int n;
    using Arr = PersistentArray<int>;

    PersistentDSU(int _n) : n(_n) {
        roots.emplace_back(A.build(std::vector<int> (n, -1)));
    }

    int find(int version, int u) {
        // Note that we can't do path compression here
        int p = A.get(roots[version], u);
        return p < 0 ? u : find(version, p);
    }

    // Note that this will always create a new version,
    // regardless of whether u and v was previously in same component.
    bool merge(int version, int u, int v) {
        u = find(version, u);
        v = find(version, v);
        auto ptr = roots[version];
        if (u != v) {
            int sz_u = -A.get(ptr, u), sz_v = -A.get(ptr, v);
            if (sz_u < sz_v) swap(u, v);
            // sz[u] >= sz[v]
            ptr = A.set(ptr, u, -sz_u - sz_v);
            ptr = A.set(ptr, v, u);
        }

        roots.emplace_back(ptr);
        return u != v;
    }

    int component_size(int version, int u) {
        return -A.get(roots[version], find(version, u));
    }

    bool same_component(int version, int u, int v) {
        return find(version, u) == find(version, v);
    }

    Arr A;
    vector<Arr::Node*> roots;
};

