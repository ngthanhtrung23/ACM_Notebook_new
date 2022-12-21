---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DP/lis.h
    title: DP/lis.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"DP/tests/yosupo_lis.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n\
    #define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int\
    \ i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n\
    #define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)\n\
    \n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl; }\n#define PR(a,n)\
    \ { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }\n#define\
    \ PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout << a[_] << ' '; cout << endl;\
    \ }\n\n#define sqr(x) ((x) * (x))\n\n// For printing pair, container, etc.\n//\
    \ Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
    template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>&\
    \ p) {\n    return out << '(' << p.first << \", \" << p.second << ')';\n}\n\n\
    template<class Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
    \ string>::value, ostream&>::type\noperator << (ostream& out, const Con& con)\
    \ {\n    out << '{';\n    for (auto beg = con.begin(), it = beg; it != con.end();\
    \ it++) {\n        out << (it == beg ? \"\" : \", \") << *it;\n    }\n    return\
    \ out << '}';\n}\ntemplate<size_t i, class T> ostream& print_tuple_utils(ostream&\
    \ out, const T& tup) {\n    if constexpr(i == tuple_size<T>::value) return out\
    \ << \")\"; \n    else return print_tuple_utils<i + 1, T>(out << (i ? \", \" :\
    \ \"(\") << get<i>(tup), tup); \n}\ntemplate<class ...U> ostream& operator <<\
    \ (ostream& out, const tuple<U...>& t) {\n    return print_tuple_utils<0, tuple<U...>>(out,\
    \ t);\n}\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    long long get_rand(long long r) {\n    return uniform_int_distribution<long long>\
    \ (0, r-1)(rng);\n}\n\ntemplate<typename T>\nvector<T> read_vector(int n) {\n\
    \    vector<T> res(n);\n    for (int& x : res) cin >> x;\n    return res;\n}\n\
    \nvoid solve();\n\nint main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n  \
    \  solve();\n    return 0;\n}\n#line 1 \"DP/lis.h\"\n// Source: http://codeforces.com/blog/entry/13225\n\
    // Non-strict.\n\nint lis_non_strict(const vector<int>& a) {\n    multiset<int>\
    \ s;\n    for (int x : a) {\n        s.insert(x);\n        auto it = s.upper_bound(x);\n\
    \n        if (it != s.end())\n            s.erase(it);\n    }\n    return s.size();\n\
    }\n\n// Strict.\nint lis_strict(const vector<int>& a) {\n    multiset<int> s;\n\
    \    for (int x : a) {\n        s.insert(x);\n        auto it = s.lower_bound(x);\n\
    \        it++;\n        \n        if (it != s.end())\n            s.erase(it);\n\
    \    }\n    return s.size();\n}\n\n// Return indices of LIS (strict)\nvector<int>\
    \ lis_strict_trace(const vector<int>& a) {\n    int n = (int) a.size();\n    vector<int>\
    \ b(n+1, 0), f(n, 0);\n    int answer = 0;\n    for (int i = 0; i < n; i++) {\n\
    \        f[i] = lower_bound(b.begin() + 1, b.begin()+answer+1, a[i]) - b.begin();\n\
    \        answer = max(answer, f[i]);\n        b[f[i]] = a[i];\n    }\n\n    int\
    \ require = answer;\n    vector<int> T;\n    for (int i = n-1; i >= 0; i--) {\n\
    \        if (f[i] == require) {\n            T.push_back(i);\n            require--;\n\
    \        }\n    }\n    reverse(T.begin(), T.end());\n    return T;\n}\n\n// Count\
    \ number of LIS\nusing mint = long long;  // Cnt is exponential. Check if statement\
    \ says ModInt here?\n// Returns: (length of LIS, number of LIS)\npair<int,mint>\
    \ count_lis(const vector<int>& a) {\n    if (a.empty()) {\n        return {0,\
    \ 1};\n    }\n\n    // dp[i] = [ (last value, accumulate count) ] for increasing\
    \ seq of\n    //                                            length i+1\n    //\
    \         last value are decreasing\n    vector<vector<pair<int,mint>>> dp(a.size()\
    \ + 1);\n    int max_len = 0;\n\n    // returns true if we can append `val` to\
    \ LIS stored at `cur`.\n    auto pred_len = [] (const vector<pair<int, mint>>&\
    \ cur, int val) {\n        return !cur.empty() && cur.back().first < val;\n  \
    \  };\n    // returns true if we can append `val` after the LIS represented with\
    \ `p`.\n    auto pred_val = [] (int val, const pair<int,mint>& p) { return val\
    \ > p.first; };\n\n    for (int x : a) {\n        int len = lower_bound(dp.begin(),\
    \ dp.end(), x, pred_len) - dp.begin();\n\n        mint cnt = 1;\n        if (len\
    \ >= 1) {\n            int pos = upper_bound(dp[len-1].begin(), dp[len-1].end(),\
    \ x, pred_val) - dp[len-1].begin();\n            cnt = dp[len-1].back().second;\n\
    \            cnt -= (pos == 0) ? 0 : dp[len-1][pos-1].second;\n        }\n   \
    \     dp[len].emplace_back(x, cnt + (dp[len].empty() ? 0 : dp[len].back().second));\n\
    \        max_len = max(max_len, len + 1);\n    }\n    assert(max_len > 0);\n \
    \   return {\n        max_len,\n        dp[max_len-1].back().second,\n    };\n\
    }\n#line 5 \"DP/tests/yosupo_lis.test.cpp\"\n\nvoid solve() {\n    int n; cin\
    \ >> n;\n    vector<int> a(n); for(int& x : a) cin >> x;\n\n    auto res = lis_strict_trace(a);\n\
    \    std::cout << res.size() << std::endl;\n    for (int i : res) std::cout <<\
    \ i << ' ';\n    std::cout << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"../../template.h\"\n#include \"../lis.h\"\n\nvoid solve() {\n \
    \   int n; cin >> n;\n    vector<int> a(n); for(int& x : a) cin >> x;\n\n    auto\
    \ res = lis_strict_trace(a);\n    std::cout << res.size() << std::endl;\n    for\
    \ (int i : res) std::cout << i << ' ';\n    std::cout << std::endl;\n}\n"
  dependsOn:
  - template.h
  - DP/lis.h
  isVerificationFile: true
  path: DP/tests/yosupo_lis.test.cpp
  requiredBy: []
  timestamp: '2022-11-29 22:46:48+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DP/tests/yosupo_lis.test.cpp
layout: document
redirect_from:
- /verify/DP/tests/yosupo_lis.test.cpp
- /verify/DP/tests/yosupo_lis.test.cpp.html
title: DP/tests/yosupo_lis.test.cpp
---
