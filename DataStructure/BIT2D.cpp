vector<int> nodes[MN];
vector<int> f[MN];

void fakeUpdate(int u, int v) {
    for(int x = u; x <= n; x += x & -x)
        nodes[x].push_back(v);
}

void fakeGet(int u, int v) {
    for(int x = u; x > 0; x -= x & -x)
        nodes[x].push_back(v);
}

void update(int u, int v) {
    for(int x = u; x <= n; x += x & -x)
        for(int y = lower_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin() + 1; y <= nodes[x].size(); y += y & -y)
            f[x][y]++;
}

int get(int u, int v) {
    int res = 0;
    for(int x = u; x > 0; x -= x & -x)
        for(int y = upper_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin(); y > 0; y -= y & -y)
            res += f[x][y];
    return res;
}

int main() {
    FORD(i,n,1) {
        fakeUpdate(a[i].b, a[i].c);
        fakeGet(a[i].b, a[i].c);
    }
    FOR(i,1,n) {
        nodes[i].push_back(1000111000);
        sort(nodes[i].begin(), nodes[i].end());
        f[i].resize(SZ(nodes[i]) + 3);
    }
}
