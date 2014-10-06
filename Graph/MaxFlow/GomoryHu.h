// Source: RR
// Tested with VOJ - MCQUERY

/*
 * Find min cut between every pair of vertices using N max_flow call (instead of N^2)
 * Not tested with directed graph
 * Index start from 0
 */
struct GomoryHu {
    int ok[MN], cap[MN][MN];
    int answer[MN][MN], parent[MN];
    int n;
    MaxFlow flow;

    GomoryHu(int n) : n(n), flow(n) {
        REP(i,n) ok[i] = parent[i] = 0;
        REP(i,n) REP(j,n) cap[i][j] = 0, answer[i][j] = oo;
    }

    void addEdge(int u, int v, int c) {
        cap[u][v] += c;
    }

    void calc() {
        REP(i,n) parent[i]=0;
        REP(i,n) REP(j,n) answer[i][j]=2000111000;

        FOR(i,1,n-1) {
            flow = MaxFlow(n);
            REP(u,n) REP(v,n)
                if (cap[u][v])
                    flow.addEdge(u, v, cap[u][v]);

            int f = flow.getMaxFlow(i, parent[i]);

            bfs(i);
            FOR(j,i+1,n-1)
                if (ok[j] && parent[j]==parent[i])
                    parent[j]=i;
            
            answer[i][parent[i]] = answer[parent[i]][i] = f;
            FOR(j,0,i-1)
                answer[i][j]=answer[j][i]=min(f,answer[parent[i]][j]);
        }
    }
    void bfs(int start) {
        memset(ok,0,sizeof ok);
        queue<int> qu;
        qu.push(start);
        while (!qu.empty()) {
            int u=qu.front(); qu.pop();
            REP(xid,flow.g[u].size()) {
                int id = flow.g[u][xid];
                int v = flow.e[id].b, fl = flow.e[id].flow, cap = flow.e[id].cap;
                if (!ok[v] && fl < cap) {
                    ok[v]=1;
                    qu.push(v);
                }
            }
        }
    }
};
