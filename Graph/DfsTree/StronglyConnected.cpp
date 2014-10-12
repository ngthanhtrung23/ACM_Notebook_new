#include "../../template.h"

int V;
vector< vector<int> > G;

#include "StronglyConnected.h"

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
        }

        DirectedDfs tree;
        tree.solve();

        DEBUG(V);
        REP(i,tree.scc.size()) {
            REP(j,tree.scc[i].size())
                cout << 1+tree.scc[i][j] << ' ';
            cout << endl;
        }
    }
}
