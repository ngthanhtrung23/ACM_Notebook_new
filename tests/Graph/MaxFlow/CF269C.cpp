// Problem: http://codeforces.com/contest/269/problem/C

#include "template.h"
#include "Graph/MaxFlow/MaxFlow.h"

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    MaxFlow flow(n);
    while (m--) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u; --v;
        flow.addEdge(u, v, c, true);
    }
    int res = flow.getFlow(0, n-1);

    for(int i = 0; i < flow.edges.size(); i += 2) {
        if (flow.edges[i].f >= 0) {
            puts("0");
        }
        else {
            puts("1");
        }
    }
}

