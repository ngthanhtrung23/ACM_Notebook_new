#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
using namespace std;

#include "../SuffixArray.h"

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    auto sa = suffix_array(s, 'a', 'z');
    for (int x : sa) std::cout << x << ' ';
    cout << endl;
    return 0;
}
