// Index from 0
// Assume 2 sides have same number of vertices
struct Matching {
    int n;
    vector< vector<int> > ke;
    vector< bool > seen;
    vector< int > matchL, matchR;

    Matching(int n) : n(n), ke(n), seen(n, false), matchL(n, -1), matchR(n, -1) {
    }

    void addEdge(int u, int v) {
        ke[u].push_back(v);
    }

    bool bpm(int u) {
        for(__typeof(ke[u].begin()) v = ke[u].begin(); v != ke[u].end(); ++v) {
            if (seen[*v]) continue;
            seen[*v] = true;

            if (matchR[*v] < 0 || bpm(matchR[*v])) {
                matchL[u] = *v;
                matchR[*v] = u;
                return true;
            }
        }
        return false;
    }

    int match() {
        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int i = 0; i < n; ++i) seen[i] = false;
            if (bpm(i)) ++res;
        }
        return res;
    }
};
