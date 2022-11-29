// Source: http://codeforces.com/blog/entry/13225
// Non-strict.

int lis_non_strict(const vector<int>& a) {
    multiset<int> s;
    for (int x : a) {
        s.insert(x);
        auto it = s.upper_bound(x);

        if (it != s.end())
            s.erase(it);
    }
    return s.size();
}

// Strict.
int lis_strict(const vector<int>& a) {
    multiset<int> s;
    for (int x : a) {
        s.insert(x);
        auto it = s.lower_bound(x);
        it++;
        
        if (it != s.end())
            s.erase(it);
    }
    return s.size();
}

// Return indices of LIS (strict)
vector<int> lis_strict_trace(const vector<int>& a) {
    int n = (int) a.size();
    vector<int> b(n+1, 0), f(n, 0);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        f[i] = lower_bound(b.begin() + 1, b.begin()+answer+1, a[i]) - b.begin();
        answer = max(answer, f[i]);
        b[f[i]] = a[i];
    }

    int require = answer;
    vector<int> T;
    for (int i = n-1; i >= 0; i--) {
        if (f[i] == require) {
            T.push_back(i);
            require--;
        }
    }
    reverse(T.begin(), T.end());
    return T;
}

// Count number of LIS
using mint = long long;  // Cnt is exponential. Check if statement says ModInt here?
// Returns: (length of LIS, number of LIS)
pair<int,mint> count_lis(const vector<int>& a) {
    if (a.empty()) {
        return {0, 1};
    }

    // dp[i] = [ (last value, accumulate count) ] for increasing seq of
    //                                            length i+1
    //         last value are decreasing
    vector<vector<pair<int,mint>>> dp(a.size() + 1);
    int max_len = 0;

    // returns true if we can append `val` to LIS stored at `cur`.
    auto pred_len = [] (const vector<pair<int, mint>>& cur, int val) {
        return !cur.empty() && cur.back().first < val;
    };
    // returns true if we can append `val` after the LIS represented with `p`.
    auto pred_val = [] (int val, const pair<int,mint>& p) { return val > p.first; };

    for (int x : a) {
        int len = lower_bound(dp.begin(), dp.end(), x, pred_len) - dp.begin();

        mint cnt = 1;
        if (len >= 1) {
            int pos = upper_bound(dp[len-1].begin(), dp[len-1].end(), x, pred_val) - dp[len-1].begin();
            cnt = dp[len-1].back().second;
            cnt -= (pos == 0) ? 0 : dp[len-1][pos-1].second;
        }
        dp[len].emplace_back(x, cnt + (dp[len].empty() ? 0 : dp[len].back().second));
        max_len = max(max_len, len + 1);
    }
    assert(max_len > 0);
    return {
        max_len,
        dp[max_len-1].back().second,
    };
}
