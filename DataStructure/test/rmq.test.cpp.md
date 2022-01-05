---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RMQ.h
    title: DataStructure/RMQ.h
  - icon: ':heavy_check_mark:'
    path: buffered_reader.h
    title: buffered_reader.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"DataStructure/test/rmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"DataStructure/RMQ.h\"\
    \n// Sparse table\n// Usage:\n// RMQ<int, _min> st(v);\n//\n// Note:\n// - doesn't\
    \ work for empty range\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/staticrmq\n\
    template<class T, T (*op) (T, T)> struct RMQ {\n    RMQ() = default;\n    RMQ(const\
    \ vector<T>& v) : t{v} {\n        for (int k = 1, n = (int) v.size(); (1<<k) <=\
    \ n; ++k) {\n            t.emplace_back(n - (1<<k) + 1);\n            for (int\
    \ i = 0; i + (1<<k) <= n; ++i) {\n                t[k][i] = op(t[k-1][i], t[k-1][i\
    \ + (1<<(k-1))]);\n            }\n        }\n    }\n\n    // get range [l, r-1]\n\
    \    // doesn't work for empty range\n    T get(int l, int r) const {\n      \
    \  assert(l < r);\n        int k = __lg(r - l);\n        return op(t[k][l], t[k][r\
    \ - (1<<k)]);\n    }\n\nprivate:\n    vector<vector<T>> t;\n};\ntemplate<class\
    \ T> T _min(T a, T b) { return b < a ? b : a; }\ntemplate<class T> T _max(T a,\
    \ T b) { return a < b ? b : a; }\n#line 2 \"buffered_reader.h\"\nnamespace IO\
    \ {\n    const int BUFSIZE = 1<<14;\n    char buf[BUFSIZE + 1], *inp = buf;\n\n\
    \    bool reacheof;\n    char get_char() {\n        if (!*inp && !reacheof) {\n\
    \            memset(buf, 0, sizeof buf);\n            int tmp = fread(buf, 1,\
    \ BUFSIZE, stdin);\n            if (tmp != BUFSIZE) reacheof = true;\n       \
    \     inp = buf;\n        }\n        return *inp++;\n    }\n    template<typename\
    \ T>\n    T get_int() {\n        int neg = 0;\n        T res = 0;\n        char\
    \ c = get_char();\n        while (!std::isdigit(c) && c != '-' && c != '+') c\
    \ = get_char();\n        if (c == '+') { neg = 0; }\n        else if (c == '-')\
    \ { neg = 1; }\n        else res = c - '0';\n\n        c = get_char();\n     \
    \   while (std::isdigit(c)) {\n            res = res * 10 + (c - '0');\n     \
    \       c = get_char();\n        }\n        return neg ? -res : res;\n    }\n\
    };\n#line 8 \"DataStructure/test/rmq.test.cpp\"\n\n#define REP(i, a) for (int\
    \ i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n, q; cin >> n >> q;\n    vector<int> a(n);\n    REP(i,n)\
    \ cin >> a[i];\n\n    RMQ<int, _min> st(a);\n    while (q--) {\n        int l,\
    \ r; cin >> l >> r;\n        cout << st.get(l, r) << '\\n';\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../RMQ.h\"\n#include \"\
    ../../buffered_reader.h\"\n\n#define REP(i, a) for (int i = 0, _##i = (a); i <\
    \ _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n \
    \   int n, q; cin >> n >> q;\n    vector<int> a(n);\n    REP(i,n) cin >> a[i];\n\
    \n    RMQ<int, _min> st(a);\n    while (q--) {\n        int l, r; cin >> l >>\
    \ r;\n        cout << st.get(l, r) << '\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/RMQ.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/rmq.test.cpp
  requiredBy: []
  timestamp: '2022-01-06 00:00:20+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/rmq.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/rmq.test.cpp
- /verify/DataStructure/test/rmq.test.cpp.html
title: DataStructure/test/rmq.test.cpp
---
