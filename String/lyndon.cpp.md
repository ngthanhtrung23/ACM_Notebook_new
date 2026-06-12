---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: String/lyndon.h
    title: String/lyndon.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.h\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b)\
    \ for(int i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a;\
    \ i++)\n#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end();\
    \ ++it)\n\n#define DEBUG(x) { cout << #x << \" = \"; cout << (x) << endl; }\n\
    #define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n) cout << a[_] << ' '; cout\
    \ << endl; }\n#define PR0(a,n) { cout << #a << \" = \"; REP(_,n) cout << a[_]\
    \ << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\n\n// For printing pair,\
    \ container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
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
    \  solve();\n    return 0;\n}\n#line 1 \"String/lyndon.h\"\n// Decompose s = w1w2..wk\
    \ : k max and w1 >= w2 >= ...\n// each wi is strictly smaller than all its rotation\n\
    void lyndon(string s) {\n    int n = (int) s.length();\n    int i = 0;\n    while\
    \ (i < n) {\n        int j = i + 1, k = i;\n        while (j < n && s[k] <= s[j])\
    \ {\n            if (s[k] < s[j]) k = i;\n            else ++k;\n            ++j;\n\
    \        }\n        while (i <= k) {\n            cout << s.substr(i, j - k) <<\
    \ ' ';\n            i += j - k;\n        }\n    }\n    cout << endl;\n}\n#line\
    \ 3 \"String/lyndon.cpp\"\n\nint main() {\n    lyndon(\"abcdef\"); // abcdef\n\
    \    lyndon(\"fedcba\"); // f e d c b a\n    lyndon(\"aaaaaa\"); // a a a a a\
    \ a\n    lyndon(\"ababab\"); // ab ab ab\n}\n"
  code: "#include \"../template.h\"\n#include \"lyndon.h\"\n\nint main() {\n    lyndon(\"\
    abcdef\"); // abcdef\n    lyndon(\"fedcba\"); // f e d c b a\n    lyndon(\"aaaaaa\"\
    ); // a a a a a a\n    lyndon(\"ababab\"); // ab ab ab\n}\n"
  dependsOn:
  - template.h
  - String/lyndon.h
  isVerificationFile: false
  path: String/lyndon.cpp
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/lyndon.cpp
layout: document
redirect_from:
- /library/String/lyndon.cpp
- /library/String/lyndon.cpp.html
title: String/lyndon.cpp
---
