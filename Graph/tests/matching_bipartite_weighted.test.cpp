#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <bits/stdc++.h>
using namespace std;

const int MN = 511;
const long long inf = 1000111000111LL;
int N;

#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#include "../Matching/HungarianLMH.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    FOR(i,1,N) FOR(j,1,N) cin >> c[i][j];
    cout << mincost() << '\n';
    FOR(i,1,N) {
        cout << mx[i] - 1 << ' ';
    }
    cout << '\n';
    return 0;
}
