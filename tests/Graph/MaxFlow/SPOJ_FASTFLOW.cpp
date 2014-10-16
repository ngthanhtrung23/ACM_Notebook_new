// Problem: http://www.spoj.com/problems/FASTFLOW/
#include "template.h"
#include "Graph/MaxFlow/MaxFlow.h"

int main() {
    ios :: sync_with_stdio(false);
    int n, m, s, t;
    cin >> n >> m; s = 1; t = n;
    --s; --t;
    MaxFlow flow(n);
    while (m--) {
        int u, v, c; cin >> u >> v >> c;
        --u; --v;
        flow.addEdge(u, v, c);
        flow.addEdge(v, u, c);
    }
    cout << flow.getFlow(s, t) << endl;
}
