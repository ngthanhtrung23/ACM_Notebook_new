#define PROBLEM "https://judge.yosupo.jp/problem/lca"

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
    FOR(i,1,n-1) {
        int pi = IO::get<int>();
        adj[pi].push_back(i);
    }

    HLD hld(adj, 0);

    while (q--) {
        int u = IO::get<int>();
        int v = IO::get<int>();

        cout << hld.lca(u, v) << '\n';
    }
    return 0;
}
