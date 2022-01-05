#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

#include "../RMQ.h"
#include "../LCA.h"
#include "../../buffered_reader.h"

#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)

int32_t main() {
    int n = IO::get_int<int>();
    int q = IO::get_int<int>();
    vector<vector<int>> adj(n);
    FOR(i,1,n-1) {
        int pi = IO::get_int<int>();
        adj[i].push_back(pi);
        adj[pi].push_back(i);
    }

    LCA lca(n, adj, 0);

    while (q--) {
        int u = IO::get_int<int>();
        int v = IO::get_int<int>();

        cout << lca.lca(u, v) << '\n';
    }
    return 0;
}
