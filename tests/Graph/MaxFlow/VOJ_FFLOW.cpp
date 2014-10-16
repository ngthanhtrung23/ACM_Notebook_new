// Problem: http://vn.spoj.com/problems/FFLOW/
#include "template.h"
#include "buffered_reader.h"
#include "Graph/MaxFlow/MaxFlow.h"

int main() {
    int n; scanf("%d", &n);
    MaxFlow flow(n);
    int x; scanf("%d", &x);
    while (x--) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u; --v;
        flow.addEdge(u, v, c);
        flow.addEdge(v, u, c);
    }
    cout << flow.getFlow(0, n-1) << endl;
    return 0;
}
