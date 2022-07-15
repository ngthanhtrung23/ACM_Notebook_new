---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: String/tests/lcp.test.cpp
    title: String/tests/lcp.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/suffix_array.test.cpp
    title: String/tests/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: String/tests/suffix_array_queries.test.cpp
    title: String/tests/suffix_array_queries.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - http://codeforces.com/contest/452/submission/7269543
    - https://cses.fi/problemset/task/2102
    - https://cses.fi/problemset/task/2103
    - https://cses.fi/problemset/task/2104
    - https://cses.fi/problemset/task/2106/
    - https://cses.fi/problemset/task/2108
    - https://judge.yosupo.jp/problem/number_of_substrings
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"String/SuffixArray.h\"\n// Source: http://codeforces.com/contest/452/submission/7269543\n\
    // Efficient Suffix Array O(N*logN)\n\n// String index from 0\n// Usage:\n// string\
    \ s;  (s[i] > 0)\n// SuffixArray sa(s);\n// Now we can use sa.SA and sa.LCP\n\
    // sa.LCP[i] = max common prefix suffix of sa.SA[i-1] and sa.SA[i]\n//\n// Notes:\n\
    // - Number of distinct substrings = |S| * (|S| + 1) / 2 - sum(LCP)\n//\n// Tested:\n\
    // - (build SA) https://judge.yosupo.jp/problem/suffixarray\n// - (LCP) https://judge.yosupo.jp/problem/number_of_substrings\n\
    // - (LCP - kth distinct substr) https://cses.fi/problemset/task/2108\n// - (LCP\
    \ - longest repeated substr) https://cses.fi/problemset/task/2106/\nstruct SuffixArray\
    \ {\n    string a;\n    int N, m;\n    vector<int> SA, LCP, x, y, w, c;\n\n  \
    \  SuffixArray(string _a, int _m = 256) : a(\" \" + _a), N(a.length()), m(_m),\n\
    \            SA(N), LCP(N), x(N), y(N), w(max(m, N)), c(N) {\n        a[0] = 0;\n\
    \        DA();\n        kasaiLCP();\n        #define REF(X) { rotate(X.begin(),\
    \ X.begin()+1, X.end()); X.pop_back(); }\n        REF(SA); REF(LCP);\n       \
    \ a = a.substr(1, a.size());\n        for(int i = 0; i < (int) SA.size(); ++i)\
    \ --SA[i];\n        #undef REF\n    }\n\n    inline bool cmp (const int u, const\
    \ int v, const int l) {\n        return (y[u] == y[v] && (u + l < N && v + l <\
    \ N ? y[u + l] == y[v + l] : false));\n    }\n\n    void Sort() {\n        for(int\
    \ i = 0; i < m; ++i) w[i] = 0;\n        for(int i = 0; i < N; ++i) ++w[x[y[i]]];\n\
    \        for(int i = 0; i < m - 1; ++i) w[i + 1] += w[i];\n        for(int i =\
    \ N - 1; i >= 0; --i) SA[--w[x[y[i]]]] = y[i];\n    }\n\n    void DA() {\n   \
    \     for(int i = 0; i < N; ++i) x[i] = a[i], y[i] = i;\n        Sort();\n   \
    \     for(int i, j = 1, p = 1; p < N; j <<= 1, m = p) {\n            for(p = 0,\
    \ i = N - j; i < N; i++) y[p++] = i;\n            for (int k = 0; k < N; ++k)\
    \ if (SA[k] >= j) y[p++] = SA[k] - j;\n            Sort();\n            for(swap(x,\
    \ y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)\n                x[SA[i]] = cmp(SA[i\
    \ - 1], SA[i], j) ? p - 1 : p++;\n        }\n    }\n\n    void kasaiLCP() {\n\
    \        for (int i = 0; i < N; i++) c[SA[i]] = i;\n        for (int i = 0, j,\
    \ k = 0; i < N; LCP[c[i++]] = k)\n            if (c[i] > 0) for (k ? k-- : 0,\
    \ j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++);\n            else k = 0;\n   \
    \ }\n};\n\n// Example:\n// given string S and Q queries pat_i, for each query,\
    \ count how many\n// times pat_i appears in S\n// O(min(|S|, |pat|) * log(|S|))\
    \ per query\n//\n// Tested:\n// - (yes / no) https://cses.fi/problemset/task/2102\n\
    // - (count) https://cses.fi/problemset/task/2103\n// - (position) https://cses.fi/problemset/task/2104\n\
    int count_occurrence(const string& s, const vector<int>& sa, const string& pat)\
    \ {\n    int n = s.size(), m = pat.size();\n    assert(n == (int) sa.size());\n\
    \    if (n < m) return 0;\n\n    auto f = [&] (int start) {  // compare S[start..]\
    \ and pat[0..]\n        for (int i = 0; start + i < n && i < m; ++i) {\n     \
    \       if (s[start + i] < pat[i]) return true;\n            if (s[start + i]\
    \ > pat[i]) return false;\n        }\n        return n - start < m;\n    };\n\
    \    auto g = [&] (int start) {\n        for (int i = 0; start + i < n && i <\
    \ m; ++i) {\n            if (s[start + i] > pat[i]) return false;\n        }\n\
    \        return true;\n    };\n    auto l = std::partition_point(sa.begin(), sa.end(),\
    \ f);\n    auto r = std::partition_point(l, sa.end(), g);\n    return std::distance(l,\
    \ r);\n}\n"
  code: "// Source: http://codeforces.com/contest/452/submission/7269543\n// Efficient\
    \ Suffix Array O(N*logN)\n\n// String index from 0\n// Usage:\n// string s;  (s[i]\
    \ > 0)\n// SuffixArray sa(s);\n// Now we can use sa.SA and sa.LCP\n// sa.LCP[i]\
    \ = max common prefix suffix of sa.SA[i-1] and sa.SA[i]\n//\n// Notes:\n// - Number\
    \ of distinct substrings = |S| * (|S| + 1) / 2 - sum(LCP)\n//\n// Tested:\n//\
    \ - (build SA) https://judge.yosupo.jp/problem/suffixarray\n// - (LCP) https://judge.yosupo.jp/problem/number_of_substrings\n\
    // - (LCP - kth distinct substr) https://cses.fi/problemset/task/2108\n// - (LCP\
    \ - longest repeated substr) https://cses.fi/problemset/task/2106/\nstruct SuffixArray\
    \ {\n    string a;\n    int N, m;\n    vector<int> SA, LCP, x, y, w, c;\n\n  \
    \  SuffixArray(string _a, int _m = 256) : a(\" \" + _a), N(a.length()), m(_m),\n\
    \            SA(N), LCP(N), x(N), y(N), w(max(m, N)), c(N) {\n        a[0] = 0;\n\
    \        DA();\n        kasaiLCP();\n        #define REF(X) { rotate(X.begin(),\
    \ X.begin()+1, X.end()); X.pop_back(); }\n        REF(SA); REF(LCP);\n       \
    \ a = a.substr(1, a.size());\n        for(int i = 0; i < (int) SA.size(); ++i)\
    \ --SA[i];\n        #undef REF\n    }\n\n    inline bool cmp (const int u, const\
    \ int v, const int l) {\n        return (y[u] == y[v] && (u + l < N && v + l <\
    \ N ? y[u + l] == y[v + l] : false));\n    }\n\n    void Sort() {\n        for(int\
    \ i = 0; i < m; ++i) w[i] = 0;\n        for(int i = 0; i < N; ++i) ++w[x[y[i]]];\n\
    \        for(int i = 0; i < m - 1; ++i) w[i + 1] += w[i];\n        for(int i =\
    \ N - 1; i >= 0; --i) SA[--w[x[y[i]]]] = y[i];\n    }\n\n    void DA() {\n   \
    \     for(int i = 0; i < N; ++i) x[i] = a[i], y[i] = i;\n        Sort();\n   \
    \     for(int i, j = 1, p = 1; p < N; j <<= 1, m = p) {\n            for(p = 0,\
    \ i = N - j; i < N; i++) y[p++] = i;\n            for (int k = 0; k < N; ++k)\
    \ if (SA[k] >= j) y[p++] = SA[k] - j;\n            Sort();\n            for(swap(x,\
    \ y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)\n                x[SA[i]] = cmp(SA[i\
    \ - 1], SA[i], j) ? p - 1 : p++;\n        }\n    }\n\n    void kasaiLCP() {\n\
    \        for (int i = 0; i < N; i++) c[SA[i]] = i;\n        for (int i = 0, j,\
    \ k = 0; i < N; LCP[c[i++]] = k)\n            if (c[i] > 0) for (k ? k-- : 0,\
    \ j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++);\n            else k = 0;\n   \
    \ }\n};\n\n// Example:\n// given string S and Q queries pat_i, for each query,\
    \ count how many\n// times pat_i appears in S\n// O(min(|S|, |pat|) * log(|S|))\
    \ per query\n//\n// Tested:\n// - (yes / no) https://cses.fi/problemset/task/2102\n\
    // - (count) https://cses.fi/problemset/task/2103\n// - (position) https://cses.fi/problemset/task/2104\n\
    int count_occurrence(const string& s, const vector<int>& sa, const string& pat)\
    \ {\n    int n = s.size(), m = pat.size();\n    assert(n == (int) sa.size());\n\
    \    if (n < m) return 0;\n\n    auto f = [&] (int start) {  // compare S[start..]\
    \ and pat[0..]\n        for (int i = 0; start + i < n && i < m; ++i) {\n     \
    \       if (s[start + i] < pat[i]) return true;\n            if (s[start + i]\
    \ > pat[i]) return false;\n        }\n        return n - start < m;\n    };\n\
    \    auto g = [&] (int start) {\n        for (int i = 0; start + i < n && i <\
    \ m; ++i) {\n            if (s[start + i] > pat[i]) return false;\n        }\n\
    \        return true;\n    };\n    auto l = std::partition_point(sa.begin(), sa.end(),\
    \ f);\n    auto r = std::partition_point(l, sa.end(), g);\n    return std::distance(l,\
    \ r);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixArray.h
  requiredBy: []
  timestamp: '2022-01-07 20:41:49+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - String/tests/suffix_array.test.cpp
  - String/tests/suffix_array_queries.test.cpp
  - String/tests/lcp.test.cpp
documentation_of: String/SuffixArray.h
layout: document
redirect_from:
- /library/String/SuffixArray.h
- /library/String/SuffixArray.h.html
title: String/SuffixArray.h
---
