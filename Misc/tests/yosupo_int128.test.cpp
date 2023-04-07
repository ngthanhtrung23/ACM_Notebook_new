#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include "../../template.h"
#include "../int128.h"

void solve() {
    int ntest; cin >> ntest;
    while (ntest--) {
        i128 a, b; cin >> a >> b;
        cout << a+b << '\n';
    }
}
