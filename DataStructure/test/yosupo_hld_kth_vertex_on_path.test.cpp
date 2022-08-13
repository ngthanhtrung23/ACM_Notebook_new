#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include <bits/stdc++.h>
using namespace std;

#include "../HeavyLight_adamant.h"
#include "../../buffered_reader.h"

#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = IO::get<int>();
    int q = IO::get<int>();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; ++i) {
        int u = IO::get<int>();
        int v = IO::get<int>();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HLD hld(adj, 0);

    while (q--) {
        int u = IO::get<int>();
        int v = IO::get<int>();
        int k = IO::get<int>();
        cout << hld.kth_vertex_on_path(u, v, k) << '\n';
    }
    return 0;
}
