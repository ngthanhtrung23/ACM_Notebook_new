#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../template.h"
#include "../hash.h"

void solve() {
    HashGenerator g(500111);
    string s; cin >> s;
    auto h = g.hash(s);

    int n = s.size();
    REP(i,n) {
        cout << g.maxCommonPrefix(h, 0, n-1, h, i, n-1) << ' ';
    }
    cout << endl;
}
