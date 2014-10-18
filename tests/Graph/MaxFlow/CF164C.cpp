// Problem: http://codeforces.com/contest/164/problem/C

#include "template.h"
#include "Graph/MaxFlow/MinCostMaxFlowSPFA.h"

const int MN = 2011;
struct Work {
    int s, t, c;
    int edge;
} a[MN];
int n, k, c[MN];

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    while (cin >> n >> k) {
        FOR(i,1,n) cin >> a[i].s >> a[i].t >> a[i].c;
        int s = 0;
        FOR(i,1,n) c[++s] = a[i].s, c[++s] = a[i].s + a[i].t - 1;
        sort(c+1, c+s+1);
        s = unique(c+1, c+s+1) - c - 1;

        MinCostFlow<int,long long> flow(s+2);
        REP(i,s+1) flow.addEdge(i, i+1, k, 0);

        FOR(i,1,n) {
            int from = lower_bound(c+1, c+s+1, a[i].s) - c;
            int to = lower_bound(c+1, c+s+1, a[i].s + a[i].t - 1) - c;

            a[i].edge = flow.addEdge(from, to + 1, 1, -a[i].c);
        }
        auto res = flow.minCostFlow(0, s+1);

        FOR(i,1,n)
            if (flow.edges[a[i].edge].cap == 0) cout << "1 ";
            else cout << "0 ";
        cout << endl;
    }
    return 0;
}
