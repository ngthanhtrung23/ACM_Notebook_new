// Gomory Hu tree - calculate cut between every pair of vertices
// Applictions:
// - http://codeforces.com/contest/343/problem/E
// - http://vn.spoj.com/problems/MCQUERY/

int ok[1000], saveCap[1000][1000], qu[1000];
int answer[1000][1000], parent[1000];
void bfs(int start) {
    memset(ok,0,sizeof ok);
    int first=1, last=1; qu[1]=start;
    while (first <= last) {
        int u=qu[first++];
        REP(i,deg[u]) {
            int v = adj[u][i];
            if (cap[u][v] && !ok[v]) {
                ok[v]=1;
                qu[++last]=v;
            }
        }
    }
}
void solve() {
    REP(i,n) parent[i]=0;
    REP(i,n) REP(j,n) answer[i][j]=2000111000;
    REP(i,n) REP(j,n) saveCap[i][j] = cap[i][j];
        
    FOR(i,1,n-1) {
        REP(u,n) REP(v,n) cap[u][v] = saveCap[u][v];        
        int f=dinic(n, i, parent[i]);
        bfs(i);
        FOR(j,i+1,n-1)
            if (ok[j] && parent[j]==parent[i])
                parent[j]=i;
        
        answer[i][parent[i]] = answer[parent[i]][i] = f;
        FOR(j,0,i-1)
            answer[i][j]=answer[j][i]=min(f,answer[parent[i]][j]);
    }
}
