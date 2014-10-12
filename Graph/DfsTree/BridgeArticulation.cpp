#include "../../template.h"

int V;
vector< vector <int> > G;

#include "BridgeArticulation.h"

int main() {
    freopen("input.txt", "r", stdin);
    int m;
    while (cin >> V >> m) {
        G.resize(V);
        REP(i,V) G[i].clear();

        while (m--) {
            int u, v; cin >> u >> v;
            --u; --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        UndirectedDfs tree;
        tree.solve();

        cout << "Bridges: ";
        REP(i,tree.bridges.size()) cout << 1+tree.bridges[i].first << ' ' << 1+tree.bridges[i].second << "   ";
        cout << endl;
        cout << "Cut points: ";
        REP(i,tree.cuts.size()) cout << 1+tree.cuts[i] << ' ';
        cout << endl;
    }
}
