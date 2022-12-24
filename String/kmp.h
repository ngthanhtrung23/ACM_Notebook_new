// prefix function: *length* of longest prefix which is also suffix:
//   pi[i] = max(k: s[0..k-1] == s[i-(k-1)..i]
//
// KMP {{{
template<typename Container>
std::vector<int> prefix_function(const Container& s) {
    int n = s.size();
    std::vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

// Tested: https://oj.vnoi.info/problem/substr
// Return all positions (0-based) that pattern `pat` appears in `text`
std::vector<int> kmp(const std::string& pat, const std::string& text) {
    auto pi = prefix_function(pat + '\0' + text);
    std::vector<int> res;
    for (size_t i = pi.size() - text.size(); i < pi.size(); ++i) {
        if (pi[i] == (int) pat.size()) {
            res.push_back(i - 2 * pat.size());
        }
    }
    return res;
}

// Tested: https://oj.vnoi.info/problem/icpc22_mt_b
// Returns cnt[i] = # occurrences of prefix of length-i
// NOTE: cnt[0] = n+1 (0-length prefix appears n+1 times)
std::vector<int> prefix_occurrences(const string& s) {
    int n = s.size();
    auto pi = prefix_function(s);
    std::vector<int> res(n + 1);
    for (int i = 0; i < n; ++i) res[pi[i]]++;
    for (int i = n-1; i > 0; --i) res[pi[i-1]] += res[i];
    for (int i = 0; i <= n; ++i) res[i]++;
    return res;
}
// }}}
