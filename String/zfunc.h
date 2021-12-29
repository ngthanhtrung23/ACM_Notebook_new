// z[i] = length of longest common prefix of s[0..N] and s[i..N]
//
// Tested:
// - https://judge.yosupo.jp/problem/zalgorithm
// - (string matching) https://oj.vnoi.info/problem/substr
vector<int> zfunc(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// Examples:
// Find all occurrences of p in t

/**
    string s = p + "_" + t;
    auto z = zfunc(s);

    REP(i,SZ(t)) {
        if (z[i + SZ(p) + 1] == SZ(p)) {
            cout << 1+i << ' ';
        }
    }
    cout << endl;
*/
