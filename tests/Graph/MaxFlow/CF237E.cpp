// Problem: http://codeforces.com/problemset/problem/237/E
#include "template.h"
#include "Graph/MaxFlow/MinCostMaxFlowSPFA.h"

string t, s[111];
int a[111], n, t_id[111], s_id[111][111];

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    while (cin >> t) {
        cin >> n;
        FOR(i,1,n) cin >> s[i] >> a[i];

        int nId = 0;
        int source = nId++;
        FOR(i,1,n) nId++;
        REP(it,t.length())
            t_id[it] = nId++;

        FOR(i,1,n) {
            REP(is,s[i].length())
                s_id[i][is] = nId++;
        }
        int sink = nId++;

        MinCostFlow<int,int> flow(nId);
        REP(it,t.length())
            flow.addEdge(t_id[it], sink, 1, 0);

        FOR(i,1,n)
            flow.addEdge(source, i, a[i], i);

        FOR(i,1,n) {
            REP(is,s[i].length()) {
                flow.addEdge(i, s_id[i][is], 1, 0);
                REP(it,t.length())
                if (s[i][is] == t[it]) {
                    flow.addEdge(s_id[i][is], t_id[it], 1, 0);
                }
            }
        }
        pair<int,int> res = flow.minCostFlow(source, sink);
        if (res.first == t.length()) cout << res.second << endl;
        else cout << -1 << endl;
    }
    return 0;
}

