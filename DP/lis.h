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
