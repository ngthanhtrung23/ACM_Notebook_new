// MST. 0-based index
//
// Returns:
// {mst cost, edges in mst}
//
// If graph is not connected, returns forest (number of edges will be < n-1)

#include "../DataStructure/DSU/DisjointSet.h"

// MST {{{
using ll = long long;
template<typename EdgeT>
std::pair<ll, std::vector<EdgeT>> mst(
        int n,
        std::vector<EdgeT> edges) {
    std::sort(edges.begin(), edges.end());

    DSU dsu(n + 1);  // tolerate 1-based index
    ll total = 0;
    vector<EdgeT> tree;
    for (const auto& e : edges) {
        if (dsu.merge(e.u, e.v)) {
            total += e.c;
            tree.push_back(e);
        }
    }
    return {total, tree};
}
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
// }}}
