#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../template.h"
#include "../hash.h"

void solve() {
    HashGenerator g(500111);
    string s; cin >> s;
    auto h = g.hash(s);

    REP(i,SZ(s)) {
        cout << g.maxCommonPrefix(h, 0, SZ(s)-1, h, i, SZ(s)-1) << ' ';
    }
    cout << endl;
}
