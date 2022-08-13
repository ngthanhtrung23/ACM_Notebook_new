---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Misc/left_nearest_smaller.h
    title: Misc/left_nearest_smaller.h
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
  bundledCode: "#line 1 \"Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\"\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Misc/left_nearest_smaller.h\"\n// Tested:\n\
    // - https://cses.fi/problemset/task/1645\n// - https://cses.fi/problemset/task/1142\n\
    // - https://oj.vnoi.info/problem/kagain\n//\n// return:\n// - left[i] = largest\
    \ j such that\n//      j < i\n//      a[j] < a[i]\n// - no such j -> left[i] =\
    \ -1\nvector<int> leftNearestSmaller(const vector<int>& a) {\n    int n = a.size();\n\
    \    vector<int> left(n);\n    stack<int> st;  // positions of candidates, A is\
    \ increasing\n    st.push(-1);\n    for (int i = 0; i < n; i++) {\n        while\
    \ (st.top() >= 0 && a[st.top()] >= a[i]) st.pop();\n        left[i] = st.top();\n\
    \        st.push(i);\n    }\n    return left;\n}\n\n// return:\n// - right[i]\
    \ = smallest j such that:\n//      j > i\n//      a[j] < a[i]\n// - no such j\
    \ -> right[i] = n\nvector<int> rightNearestSmaller(const vector<int>& a) {\n \
    \   int n = a.size();\n    vector<int> right(n);\n    stack<int> st;   // positions\
    \ of candidates, A is increasing\n    st.push(n);\n    for (int i = n-1; i >=\
    \ 0; i--) {\n        while (st.top() < n && a[st.top()] >= a[i]) st.pop();\n \
    \       right[i] = st.top();\n        st.push(i);\n    }\n    return right;\n\
    }\n#line 5 \"Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp\"\n\nlong long\
    \ largestHistogram(const vector<int>& a) {\n    int n = a.size();\n    auto left\
    \ = leftNearestSmaller(a);\n    auto right = rightNearestSmaller(a);\n\n    long\
    \ long res = 0;\n    for (int i = 0; i < n; i++) {\n        int l = left[i] +\
    \ 1;\n        int r = right[i] - 1;\n        res = max(res, a[i] * (r - l + 1LL));\n\
    \    }\n    return res;\n}\n\nvoid solve() {\n    int n_row, n_col; cin >> n_row\
    \ >> n_col;\n    vector<vector<int>> a(n_row, vector<int> (n_col));\n    for (auto&\
    \ row : a) {\n        for (auto& x : row) {\n            cin >> x;\n         \
    \   x = 1 - x;\n        }\n    }\n\n    long long res = 0;\n    for (int r = 0;\
    \ r < n_row; r++) {\n        if (r > 0) {\n            for (int c = 0; c < n_col;\
    \ c++) {\n                if (a[r][c]) a[r][c] = a[r-1][c] + 1;\n            \
    \    else a[r][c] = 0;\n            }\n        }\n        res = max(res, largestHistogram(a[r]));\n\
    \    }\n    cout << res << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\"\
    \n\n#include \"../../template.h\"\n#include \"../left_nearest_smaller.h\"\n\n\
    long long largestHistogram(const vector<int>& a) {\n    int n = a.size();\n  \
    \  auto left = leftNearestSmaller(a);\n    auto right = rightNearestSmaller(a);\n\
    \n    long long res = 0;\n    for (int i = 0; i < n; i++) {\n        int l = left[i]\
    \ + 1;\n        int r = right[i] - 1;\n        res = max(res, a[i] * (r - l +\
    \ 1LL));\n    }\n    return res;\n}\n\nvoid solve() {\n    int n_row, n_col; cin\
    \ >> n_row >> n_col;\n    vector<vector<int>> a(n_row, vector<int> (n_col));\n\
    \    for (auto& row : a) {\n        for (auto& x : row) {\n            cin >>\
    \ x;\n            x = 1 - x;\n        }\n    }\n\n    long long res = 0;\n   \
    \ for (int r = 0; r < n_row; r++) {\n        if (r > 0) {\n            for (int\
    \ c = 0; c < n_col; c++) {\n                if (a[r][c]) a[r][c] = a[r-1][c] +\
    \ 1;\n                else a[r][c] = 0;\n            }\n        }\n        res\
    \ = max(res, largestHistogram(a[r]));\n    }\n    cout << res << endl;\n}\n"
  dependsOn:
  - template.h
  - Misc/left_nearest_smaller.h
  isVerificationFile: true
  path: Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp
layout: document
redirect_from:
- /verify/Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp
- /verify/Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp.html
title: Misc/tests/aizu_dpl_3_b_largest_01_rectangle.test.cpp
---
