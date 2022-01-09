#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"

#include <bits/stdc++.h>
using namespace std;

#include "../Matching/GeneralMatching.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    GeneralMatching match(n);
    while (m--) {
        int a, b; cin >> a >> b;
        match.add_edge(a, b);
    }
    cout << match.get_match() << '\n';
    for (int i = 0; i < n; i++) {
        if (match.match[i] != -1 && match.match[i] > i) {
            cout << i << ' ' << match.match[i] << '\n';
        }
    }
    return 0;
}
