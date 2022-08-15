// 2D Fenwick
// Note:
// - already included coordinate compression, so any `int` coordinates
//   should work
//
// Tested:
// - https://judge.yosupo.jp/problem/rectangle_sum
// - https://judge.yosupo.jp/problem/point_add_rectangle_sum
// - https://oj.vnoi.info/problem/kl11b

#include "../Misc/compress.h"
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
        CompressorBuilder<int> cx_builder, cy_builder;
        cx_builder.add(INF);
        cy_builder.add(INF);
        for (const auto& query : queries) {
            if (query.typ == Query<T>::ADD) {
                cx_builder.add(query.x);
                cy_builder.add(query.y);
            }
        }
        auto cx = cx_builder.build();
        auto cy = cy_builder.build();
        sx = cx.size();

        // Compress
        for (auto& query : queries) {
            query.x = cx.must_geq(query.x) + 1;
            query.y = cy.must_geq(query.y) + 1;

            if (query.typ == Query<T>::QUERY) {
                query.x2 = cx.must_geq(query.x2) + 1;
                query.y2 = cy.must_geq(query.y2) + 1;
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
