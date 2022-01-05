// 2D Fenwick
// Note:
// - already included coordinate compression, so any `int` coordinates
//   should work
//
// Tested:
// - https://judge.yosupo.jp/problem/rectangle_sum
// - https://judge.yosupo.jp/problem/point_add_rectangle_sum
// - https://oj.vnoi.info/problem/kl11b
const int INF = 2e9 + 11;  // for coordinates
template<typename T>
struct Query {
    static const int ADD = 0;
    static const int QUERY = 1;

    int typ;  // ADD or QUERY
    int x, y;
    int x2, y2;  // for QUERY: [x1, x2-1] * [y1, y2-1]

    T weight;
};

template<typename T>
struct Fenwick2D {
    vector<T> solve(vector<Query<T>> queries) {
        // Get coordinates of ADD queries
        vector<int> cx {INF}, cy {INF};
        for (const auto& query : queries) {
            if (query.typ == Query<T>::ADD) {
                cx.push_back(query.x);
                cy.push_back(query.y);
            }
        }
        sort(cx.begin(), cx.end());
        sort(cy.begin(), cy.end());
        cx.erase(unique(cx.begin(), cx.end()), cx.end());
        cy.erase(unique(cy.begin(), cy.end()), cy.end());
        sx = cx.size();

        auto getx = [&cx] (int x) {
            return lower_bound(cx.begin(), cx.end(), x) - cx.begin();
        };
        auto gety = [&cy] (int y) {
            return lower_bound(cy.begin(), cy.end(), y) - cy.begin();
        };

        // Compress
        for (auto& query : queries) {
            query.x = getx(query.x) + 1;
            query.y = gety(query.y) + 1;

            if (query.typ == Query<T>::QUERY) {
                query.x2 = getx(query.x2) + 1;
                query.y2 = gety(query.y2) + 1;
            }
        }

        // fake updates
        nodes.resize(sx+1);
        f.resize(sx+1);
        for (const auto& query : queries) {
            if (query.typ == Query<T>::ADD) {
                fakeUpdate(query.x, query.y);
            }
        }

        // init nodes
        for (int i = 1; i <= sx; i++) {
            nodes[i].push_back(INF);
            sort(nodes[i].begin(), nodes[i].end());
            nodes[i].erase(unique(nodes[i].begin(), nodes[i].end()), nodes[i].end());
            f[i].resize(nodes[i].size() + 1);
        }

        // answer queries
        vector<T> res;
        for (const auto& query : queries) {
            if (query.typ == Query<T>::ADD) {
                update(query.x, query.y, query.weight);
            } else {
                res.push_back(
                    + get(query.x2 - 1, query.y2 - 1)
                    - get(query.x2 - 1, query.y  - 1)
                    - get(query.x  - 1, query.y2 - 1)
                    + get(query.x  - 1, query.y  - 1)
                );
            }
        }
        return res;
    }

// private:
    // nodes[x] contains all relevant y coordinates
    vector<vector<int>> nodes;
    vector<vector<T>> f;
    int sx;

    void fakeUpdate(int x, int y) {
        for (; x <= sx; x += x & -x)
            nodes[x].push_back(y);
    }

    // point (u, v) += val
    void update(int u, int v, int val) {
        for(int x = u; x <= sx; x += x & -x)
            for(int y = lower_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin() + 1; y <= (int) nodes[x].size(); y += y & -y)
                f[x][y] += val;
    }

    // Get sum of point in rectangle with corners at (1, 1) and (u, v)
    T get(int u, int v) {
        T res = 0;
        for(int x = u; x > 0; x -= x & -x)
            for(int y = upper_bound(nodes[x].begin(), nodes[x].end(), v) - nodes[x].begin(); y > 0; y -= y & -y)
                res += f[x][y];
        return res;
    }
};
