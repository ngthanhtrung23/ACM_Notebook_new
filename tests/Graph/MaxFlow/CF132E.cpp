#include "template.h"
#include "Graph/MaxFlow/MinCostMaxFlowSPFA.h"

const int MN = 311;
int n, m, a[MN];
char var[MN];
int edgeId[MN][MN];

int main() {
    ios :: sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    while (cin >> n >> m) {
        FOR(i,1,n) cin >> a[i];

        MinCostFlow<int,long long> flow(2 * (m+n) + 2);

        int sink = 2 * (m+n) + 1;
        FOR(i,1,m+n) flow.addEdge(0, i, 1, 0);
        FOR(i,m+n+1,sink-1) flow.addEdge(i, sink, 1, 0);

        memset(edgeId, -1, sizeof edgeId);

        FOR(i,1,m+n)
            if (i <= m) {
                FOR(j,m+1,m+n)
                    edgeId[i][j] = flow.addEdge(i, j+(m+n), 1, __builtin_popcount(a[j-m]));
            } else {
                FOR(j,i+1,m+n) {
                    int cost = (a[i-m] == a[j-m]) ? 0 : __builtin_popcount(a[j-m]);
                    edgeId[i][j] = flow.addEdge(i, j+(m+n), 1, cost);
                }
            }

        pair<int,long long> res = flow.minCostFlow(0, sink);
        vector< pair<int, pair<int,int> > > statements;

        FOR(j,m+1,m+n) {
            int v = m + n + j;
            FOR(i,1,m+n)
                if (edgeId[i][j] >= 0 && !flow.edges[edgeId[i][j]].cap) {
                    if (i <= m) {
                        statements.push_back(make_pair(0, make_pair(i, a[j - m])));
                        statements.push_back(make_pair(1, make_pair(i, 0)));
                        var[j - m] = i;
                    } else {
                        var[j - m] = var[i - m];
                        if (a[i - m] == a[j - m]) {
                            statements.push_back(make_pair(1, make_pair(var[j-m], 0)));
                        } else {
                            statements.push_back(make_pair(0, make_pair(var[j - m], a[j - m])));
                            statements.push_back(make_pair(1, make_pair(var[j-m], 0)));
                        }
                    }
                }
        }
        cout << statements.size() << ' ' << res.second << "\n";
        REP(i,statements.size()) {
            if (statements[i].first == 0) {
                cout << (char) (statements[i].second.first - 1 + 'a') << '=' << statements[i].second.second << "\n";
            }
            else {
                cout << "print(" << (char) (statements[i].second.first - 1 + 'a') << ")\n";
            }
        }
    }
}
