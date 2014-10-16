// Problem: http://acm.timus.ru/problem.aspx?space=1&num=1664
#include "template.h"
#include "buffered_reader.h"
#include "Graph/MaxFlow/MaxFlow.h"

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    GN(n);
    REP(i,n) {
        int x, y;
        GN(x); GN(y);
    }
    MaxFlow flow(n);
    GN(m);
    while (m--) {
        int u, v, c; GN(u); GN(v); GN(c);
        --u; --v;
        flow.addEdge(u, v, c, true);
    }
    int res = flow.getFlow(0, n-1);

    printf("%d\n", res);
    for(int i = 0; i < flow.edges.size(); i += 2) {
        if (flow.edges[i].f > 0) {
            printf("%d %d %d\n", 1+flow.edges[i].u, 1+flow.edges[i].v, flow.edges[i].f);
        } else {
            printf("%d %d %d\n", 1+flow.edges[i].v, 1+flow.edges[i].u, flow.edges[i^1].f);
        }
    }
}


