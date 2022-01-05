#define PROBLEM "https://judge.yosupo.jp/problem/bipartite_edge_coloring"

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;
#include "../bipartite_edge_coloring.h"

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int l, r, m; cin >> l >> r >> m;
    vector<T> ed(m);
    for (auto &x: ed) {
        cin >> x[0] >> x[1];
    }
    EdgeColoring E;
    vector<int> ans;
    int cnt = E.solve(ed, ans);
    cout << cnt << '\n';
    for (auto &x: ans) cout << x - 1 << endl;
    cout << endl;
    return 0;
}
