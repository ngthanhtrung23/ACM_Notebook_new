bool bfs() {
    first=1; last=0;
    FOR(u,1,n)
    if (!mx[u]) {
        dist[u]=0;
        queue[++last]=u;
    } else dist[u]=MAXN;
    dist[0]=MAXN;
    
    while (first<=last) {
        long u=queue[first++];
        FORV(v,ke[u])
        if (dist[my[*v]]==MAXN) {
            dist[my[*v]]=dist[u]+1;
            queue[++last]=my[*v];
        }
    }
    return dist[0]!=MAXN;
}

bool dfs(long u) {
    if (u) {
        FORV(v,ke[u])
        if (dist[my[*v]]==dist[u]+1)
            if (dfs(my[*v])) {
                mx[u]=*v;
                my[*v]=u;
                return true;
            }
        dist[u]=MAXN;
        return false;
    }
    return true;
}
void solve() {
    long res=0;
    while (bfs()) {
        FOR(u,1,n)
            if (!mx[u])
                if (dfs(u)) res++;
    }
    printf("%ld",res);
}