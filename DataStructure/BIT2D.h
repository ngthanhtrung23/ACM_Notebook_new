// MAX_COORD = max X-coordinates

vector<int> nodes[MN];
vector<int> f[MN];  // sum

void fakeUpdate(int u, int v) {
    for(int x = u; x <= MAX_COORD; x += x & -x)
        nodes[x].push_back(v);
}

void fakeGet(int u, int v) {
    for(int x = u; x > 0; x -= x & -x)
        nodes[x].push_back(v);
}

// Add point (u, v)
void update(int u, int v) {
    for(int x = u; x <= MAX_COORD; x += x & -x)
        for(int y = lower_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin() + 1;
                y <= (int) nodes[x].size(); y += y & -y)
            f[x][y]++;
}

// Get number of point in rectangle with corners at (1, 1) and (u, v)
int get(int u, int v) {
    int res = 0;
    for(int x = u; x > 0; x -= x & -x)
        for(int y = upper_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin(); y > 0; y -= y & -y)
            res += f[x][y];
    return res;
}

int main() {
    // Note: Make sure coordinates <= MAX_COORD
    // Otherwise, must fix fakeUpdate and update above.
    FOR(i,1,MAX_COORD) {
        fakeUpdate(a[i].b, a[i].c);
        fakeGet(a[i].b, a[i].c);
    }
    FOR(i,1,MAX_COORD) {
        nodes[i].push_back(1000111000);
        sort(nodes[i].begin(), nodes[i].end());
        nodes[i].resize(unique(nodes[i].begin(), nodes[i].end()) - nodes[i].begin());
        f[i].resize(SZ(nodes[i]) + 3);
    }
}
