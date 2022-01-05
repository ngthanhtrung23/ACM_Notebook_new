// Max Bipartite matching.
// Index from 0
// Assume 2 sides have same number of vertices
//
// Notes:
// - If TLE --> try shuffle edges
//   REP(i,n) shuffle(ke[i].begin(), ke[i].end(), rng)
// - It should be quite fast, can AC 10^5 vertices
//
// Find vertices that belong to all maximum matching:
// (see https://codeforces.com/gym/100337/submission/139751832)
// - L = vertices not matched on left side --> BFS from these vertices
//   (left --> right: unmatched edges, right --> left: matched edges)
//   reachable vertices on left side --> not belong to some maximum matching
// - Do similar for right side
//
// Tested:
// - https://judge.yosupo.jp/problem/bipartitematching
// - https://oj.vnoi.info/problem/fmatch
// - https://codeforces.com/gym/100337 - A: find vertices belong to all max matching

struct Matching {
    int n;
    vector< vector<int> > ke;
    vector< int > seen;
    vector< int > matchL, matchR;
    int iteration;

    Matching(int _n) : n(_n), ke(_n), seen(_n, false), matchL(_n, -1), matchR(_n, -1), iteration{0} {
    }

    void addEdge(int u, int v) {
        ke[u].push_back(v);
    }

    bool dfs(int u) {
        seen[u] = iteration;
        for (int v : ke[u]) {
            if (matchR[v] < 0) {
                matchR[v] = u;
                matchL[u] = v;
                return true;
            }
        }
        for (int v : ke[u]) {
            if (seen[matchR[v]] != iteration && dfs(matchR[v])) {
                matchR[v] = u;
                matchL[u] = v;
                return true;
            }
        }
        return false;
    }

    int match() {
        int res = 0;
        int newMatches = 0;
        do {
            iteration++;
            newMatches = 0;
            for (int u = 0; u < n; u++) {
                if (matchL[u] < 0 && dfs(u)) ++newMatches;
            }
            res += newMatches;
        } while (newMatches > 0);
        return res;
    }
};
