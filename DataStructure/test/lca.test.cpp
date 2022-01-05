#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

#include "../RMQ.h"
#include "../LCA.h"
#include "../../buffered_reader.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = IO::get_int<int>();
    int q = IO::get_int<int>();

    LCA lca(n);
    FOR(i,1,n-1) {
        int pi = IO::get_int<int>();
        lca.add_edge(i, pi);
    }
    lca.build(0);

    while (q--) {
        int u = IO::get_int<int>();
        int v = IO::get_int<int>();

        cout << lca.lca(u, v) << '\n';
    }
    return 0;
}
