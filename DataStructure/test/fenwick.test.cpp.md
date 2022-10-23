---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Fenwick.h
    title: DataStructure/Fenwick.h
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"DataStructure/test/fenwick.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"DataStructure/Fenwick.h\"\n// 1D Fenwick {{{\n\
    // 0 based index\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/static_range_sum\n\
    // - https://judge.yosupo.jp/problem/point_add_range_sum\ntemplate<\n    typename\
    \ T  // need to support operators + -\n> struct Fenwick {\n    Fenwick(int _n)\
    \ : n(_n), f(_n + 1) {}\n\n    // a[u] += val\n    void update(int u, T val) {\n\
    \        assert(0 <= u && u < n);\n        ++u;\n        for (; u <= n; u += u\
    \ & -u) {\n            f[u] += val;\n        }\n    }\n\n    // return a[0] +\
    \ .. + a[u-1]\n    T get(int u) const {\n        assert(0 <= u && u <= n);\n \
    \       T res = 0;\n        for (; u > 0; u -= u & -u) {\n            res += f[u];\n\
    \        }\n        return res;\n    }\n\n    // return a[l] + .. + a[r-1]\n \
    \   T get(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r) return 0;  // empty\n        return get(r) - get(l);\n  \
    \  }\n\n    void reset() {\n        std::fill(f.begin(), f.end(), T(0));\n   \
    \ }\n\n    int n;\n    vector<T> f;\n};\n// }}}\n#line 1 \"buffered_reader.h\"\
    \n// Buffered reader {{{\nnamespace IO {\n    const int BUFSIZE = 1<<14;\n   \
    \ char buf[BUFSIZE + 1], *inp = buf;\n\n    bool reacheof;\n    char get_char()\
    \ {\n        if (!*inp && !reacheof) {\n            memset(buf, 0, sizeof buf);\n\
    \            int tmp = fread(buf, 1, BUFSIZE, stdin);\n            if (tmp !=\
    \ BUFSIZE) reacheof = true;\n            inp = buf;\n        }\n        return\
    \ *inp++;\n    }\n    template<typename T>\n    T get() {\n        int neg = 0;\n\
    \        T res = 0;\n        char c = get_char();\n        while (!std::isdigit(c)\
    \ && c != '-' && c != '+') c = get_char();\n        if (c == '+') { neg = 0; }\n\
    \        else if (c == '-') { neg = 1; }\n        else res = c - '0';\n\n    \
    \    c = get_char();\n        while (std::isdigit(c)) {\n            res = res\
    \ * 10 + (c - '0');\n            c = get_char();\n        }\n        return neg\
    \ ? -res : res;\n    }\n};\n// }}}\n#line 8 \"DataStructure/test/fenwick.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n \
    \   int q = IO::get<int>();\n\n    Fenwick<long long> f(n);\n    REP(i,n) {\n\
    \        int x = IO::get<int>();\n        f.update(i, x);\n    }\n\n    while\
    \ (q--) {\n        int l = IO::get<int>();\n        int r = IO::get<int>();\n\
    \        cout << f.get(l, r) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Fenwick.h\"\n\
    #include \"../../buffered_reader.h\"\n\n#define REP(i, a) for (int i = 0, _##i\
    \ = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n = IO::get<int>();\n    int q = IO::get<int>();\n\n    Fenwick<long\
    \ long> f(n);\n    REP(i,n) {\n        int x = IO::get<int>();\n        f.update(i,\
    \ x);\n    }\n\n    while (q--) {\n        int l = IO::get<int>();\n        int\
    \ r = IO::get<int>();\n        cout << f.get(l, r) << '\\n';\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - DataStructure/Fenwick.h
  - buffered_reader.h
  isVerificationFile: true
  path: DataStructure/test/fenwick.test.cpp
  requiredBy: []
  timestamp: '2022-10-23 21:56:10+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: DataStructure/test/fenwick.test.cpp
layout: document
redirect_from:
- /verify/DataStructure/test/fenwick.test.cpp
- /verify/DataStructure/test/fenwick.test.cpp.html
title: DataStructure/test/fenwick.test.cpp
---
