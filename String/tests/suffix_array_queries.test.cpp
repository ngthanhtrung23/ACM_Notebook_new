#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D"

#include <bits/stdc++.h>
using namespace std;

#include "../SuffixArray.h"

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s, pat;
    int q;
    cin >> s >> q;
    auto sa = suffix_array(s, 0, 255);
    while (q--) {
        cin >> pat;
        int cnt = cnt_occurrences(s, sa, pat);
        cout << (cnt ? 1 : 0) << '\n';
    }
    return 0;
}
