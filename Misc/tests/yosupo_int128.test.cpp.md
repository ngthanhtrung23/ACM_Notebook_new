---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Misc/int128.h
    title: Misc/int128.h
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
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb_128bit
    links:
    - https://judge.yosupo.jp/problem/many_aplusb_128bit
  bundledCode: "#line 1 \"Misc/tests/yosupo_int128.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/many_aplusb_128bit\"\n\n#line 1 \"template.h\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define FOR(i,a,b) for(int\
    \ i=(a),_b=(b); i<=_b; i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b;\
    \ i--)\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a) for(__typeof(a.begin())\
    \ it = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x) { cout << #x << \"\
    \ = \"; cout << (x) << endl; }\n#define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n)\
    \ cout << a[_] << ' '; cout << endl; }\n#define PR0(a,n) { cout << #a << \" =\
    \ \"; REP(_,n) cout << a[_] << ' '; cout << endl; }\n\n#define sqr(x) ((x) * (x))\n\
    \n// For printing pair, container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
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
    \  solve();\n    return 0;\n}\n#line 1 \"Misc/int128.h\"\n// i128 helper functions\
    \ {{{\nusing i128 = __int128_t;\ni128 str2i128(std::string str) {\n    i128 ret\
    \ = 0;\n    bool minus = false;\n    for (auto c : str) {\n        if (c == '-')\n\
    \            minus = true;\n        else\n            ret = ret * 10 + c - '0';\n\
    \    }\n    return minus ? -ret : ret;\n}\nstd::istream &operator>>(std::istream\
    \ &is, i128 &x) {\n    std::string s;\n    return is >> s, x = str2i128(s), is;\n\
    }\nstd::ostream &operator<<(std::ostream &os, const i128 &x) {\n    i128 tmp =\
    \ x;\n    if (tmp == 0) return os << 0;\n    std::vector<int> ds;\n    if (tmp\
    \ < 0) {\n        os << '-';\n        while (tmp) {\n            int d = tmp %\
    \ 10;\n            if (d > 0) d -= 10;\n            ds.emplace_back(-d), tmp =\
    \ (tmp - d) / 10;\n        }\n    } else {\n        while (tmp) ds.emplace_back(tmp\
    \ % 10), tmp /= 10;\n    }\n    std::reverse(ds.begin(), ds.end());\n    for (auto\
    \ i : ds) os << i;\n    return os;\n}\ni128 my_abs(i128 n) {\n    if (n < 0) return\
    \ -n;\n    return n;\n}\ni128 gcd(i128 a, i128 b) {\n    if (b == 0) return a;\n\
    \    return gcd(b, a % b);\n}\n// Count trailing zeroes\nint ctz128(i128 n) {\n\
    \    if (!n) return 128;\n \n    if (!static_cast<uint64_t>(n)) {\n        return\
    \ __builtin_ctzll(static_cast<uint64_t>(n >> 64)) + 64;\n    } else {\n      \
    \  return __builtin_ctzll(static_cast<uint64_t>(n));\n    }\n}\n// }}}\n\n#line\
    \ 5 \"Misc/tests/yosupo_int128.test.cpp\"\n\nvoid solve() {\n    int ntest; cin\
    \ >> ntest;\n    while (ntest--) {\n        i128 a, b; cin >> a >> b;\n      \
    \  cout << a+b << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb_128bit\"\n\n\
    #include \"../../template.h\"\n#include \"../int128.h\"\n\nvoid solve() {\n  \
    \  int ntest; cin >> ntest;\n    while (ntest--) {\n        i128 a, b; cin >>\
    \ a >> b;\n        cout << a+b << '\\n';\n    }\n}\n"
  dependsOn:
  - template.h
  - Misc/int128.h
  isVerificationFile: true
  path: Misc/tests/yosupo_int128.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 01:25:09+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Misc/tests/yosupo_int128.test.cpp
layout: document
redirect_from:
- /verify/Misc/tests/yosupo_int128.test.cpp
- /verify/Misc/tests/yosupo_int128.test.cpp.html
title: Misc/tests/yosupo_int128.test.cpp
---
