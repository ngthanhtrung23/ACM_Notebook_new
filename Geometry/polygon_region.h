// Given polygon with N vertices, and M diagonals.
// Diagonals does not intersect in internal point.
// Split polygon into regions.
//
// Usage:
// PolygonRegion a(n);
// for (auto p : diagonals) a.addEdge(p.first - 1, p.second - 1);
// a.init();
// Tested:
// - http://codeforces.com/contest/776/problem/F
// - https://oj.vnoi.info/problem/icpc21_regional_c
const int MN = 300111;
vector<int> ke[MN];  // 0-based index
struct PolygonRegion {  // everything is 0-based index
    int n;
    set<int> vertices;
    vector< pair<int,int> > diagonals;
    vector< vector<int> > regions;

    PolygonRegion(int n) : n(n) {
        vertices.clear();
        REP(i,n) vertices.insert(i);
        diagonals.clear();
    }

    void addEdge(int a, int b) {
        assert(a != b);
        if (a > b) swap(a, b);
        assert(a + 1 != b);
        if (a == n-1) assert(b != 0);

        diagonals.emplace_back(b - a, a);
    }

    void init() {
        diagonals.emplace_back(n-1, 0);
        regions.clear();

        REP(i,n+1) ke[i].clear();

        sort(diagonals.begin(), diagonals.end());
        REP(idiag,SZ(diagonals)) {
            auto diagonal = diagonals[idiag];

            // (s, t) = current diagonal
            int s = diagonal.second;
            int t = s + diagonal.first;

            // extract polygon
            auto it = vertices.find(s); ++it;
            vector<int> cur;
            cur.push_back(s);
            while (true) {
                if (*it == t) break;
                cur.push_back(*it);
                vertices.erase(it++);
            }
            cur.push_back(t);

            // update adjacent list.
            REP(j,SZ(cur)-1) {  // consider all edges except (s, t)
                if (cur[j+1] - cur[j] > 1) {
                    int low = lower_bound(diagonals.begin(), diagonals.end(), make_pair(cur[j+1] - cur[j], cur[j])) - diagonals.begin();
                    ke[low].push_back(idiag);
                    ke[idiag].push_back(low);
                }
            }

            regions.push_back(cur);
        }
    }
};
