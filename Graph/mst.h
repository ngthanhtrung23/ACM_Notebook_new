// MST. 0-based index
//
// Returns:
// {mst cost, edges in mst}
//
// If graph is not connected, returns forest (number of edges will be < n-1)

#include "../DataStructure/DisjointSet.h"
using ll = long long;
struct Edge {
    int u, v;
    ll c;
};
bool operator < (const Edge& a, const Edge& b) {
    return a.c < b.c;
}
ostream& operator << (ostream& out, const Edge& e) {
    out << e.u << " - " << e.v << " [" << e.c << ']';
    return out;
}
std::pair<ll, std::vector<Edge>> mst(
        int n,
        std::vector<Edge> edges) {
    std::sort(edges.begin(), edges.end());

    DSU dsu(n + 1);  // tolerate 1-based index
    ll total = 0;
    vector<Edge> tree;
    for (const auto& e : edges) {
        const auto [u, v, c] = e;
        if (dsu.merge(u, v)) {
            total += c;
            tree.push_back(e);
        }
    }
    return {total, tree};
}
