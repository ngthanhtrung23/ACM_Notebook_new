#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../buffered_reader.h"
#include "../SegTree2D.h"

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

template<typename T>
struct Query {
    static const int ADD = 0;
    static const int QUERY = 1;

    int typ;  // ADD or QUERY
    int x, y;
    int x2, y2;  // for QUERY: [x1, x2-1] * [y1, y2-1]

    T weight;
};

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = IO::get<int>();
    int q = IO::get<int>();

    using ll = long long;
    vector<Query<ll>> queries;
    REP(i,n) {
        int x = IO::get<int>();
        int y = IO::get<int>();
        ll val = IO::get<ll>();
        queries.push_back({Query<ll>::ADD, x, y, -1, -1, val});
    }

    REP(i,q) {
        int typ = IO::get<int>();
        if (typ == 0) {
            int x = IO::get<int>();
            int y = IO::get<int>();
            ll val = IO::get<ll>();
            queries.push_back({Query<ll>::ADD, x, y, -1, -1, val});
        } else {
            int x = IO::get<int>();
            int y = IO::get<int>();
            int x2 = IO::get<int>();
            int y2 = IO::get<int>();
            queries.push_back({Query<ll>::QUERY, x, y, x2, y2, 0});
        }
    }

    using P = pair<int,int>;
    vector<P> points;
    for (auto query : queries) {
        if (query.typ == Query<ll>::ADD) {
            points.push_back({query.x, query.y});
        }
    }

    SegTree2D<ll, SumSegTreeOp::op, SumSegTreeOp::e, int> st(points);
    for (auto query : queries) {
        if (query.typ == Query<ll>::ADD) {
            P p{query.x, query.y};
            st.set(p, st.get(p) + query.weight);
        } else {
            cout << st.prod(P{query.x, query.y}, P{query.x2, query.y2}) << '\n';
        }
    }
    return 0;
}
