// Source: http://codeforces.com/blog/entry/13225
// Non-strict.
multiset<int> s;
vector<int> a;

for (int i = 1; i <= n; i++) {
    s.insert(a[i]);
    auto it = s.upper_bound(a[i]);

    if (it != s.end())
        s.erase(it);
}
cout << s.size() << endl;

// Strict.
multiset<int> s;
for (int i = 1; i <= n; i++) {
    s.insert(a[i]);
    it = s.lower_bound(a[i]);
    it++;
    
    if (it != s.end())
        s.erase(it);
}

// Trace
vector<int> b(n+1, 0);
int answer = 0;
for (int i = 1; i <= n; i++) {
    f[i] = lower_bound(b+1, b+answer+1, a[i]) - b;
    answer = max(answer, f[i]);
    b[f[i]] = a[i];
}

int require = answer;
vector<int> T;
for (int i = n; i >= 1; i--) {
    if (f[i] == require) {
        T.push_back(a[i]);
        require--;
    }
}
reverse(T.begin(), T.end());
