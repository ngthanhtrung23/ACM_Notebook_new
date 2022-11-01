// Manacher {{{
// Return <even_len, odd_len>
// - even_len[i] = length of longest palindrome centered at [i, i+1]
// - odd_len[i] = length of longest palindrome centered at i
//
// Tested:
// - https://judge.yosupo.jp/problem/enumerate_palindromes
// - https://oj.vnoi.info/problem/paliny
std::array<vector<int>, 2> manacher(const string& s) {
    int n = s.size();
    std::array res = {vector<int> (n+1, 0), vector<int> (n, 0)};

    for (int z = 0; z < 2; z++) {
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            int t = r - i + !z;
            if (i < r) res[z][i] = min(t, res[z][l + t]);

            int l2 = i - res[z][i], r2 = i + res[z][i] - !z;
            while (l2 && r2 + 1 < n && s[l2 - 1] == s[r2 + 1]) {
                ++res[z][i];
                --l2;
                ++r2;
            }
            if (r2 > r) {
                l = l2;
                r = r2;
            }
        }
        for (int i = 0; i < n; i++) {
            res[z][i] = 2*res[z][i] + z;
        }
    }
    res[0].erase(res[0].begin(), res[0].begin() + 1);
    res[0].pop_back();
    return res;
}
// }}}
