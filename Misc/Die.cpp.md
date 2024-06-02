---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Misc/Die.h
    title: Misc/Die.h
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
    \  solve();\n    return 0;\n}\n#line 1 \"Misc/Die.h\"\nconst int rotations[6][4]\
    \ = {\n    {1, 4, 0, 5}, // left\n    {1, 5, 0, 4}, // right\n    {4, 3, 5, 2},\
    \ // up\n    {4, 2, 5, 3}, // down\n};\nstruct Die;\nmap<int, Die> dieMap;\nstruct\
    \ Die {\n    int arr[6]; /* 0 right, 1 left, 2 forward, 3 backward, 4 top, 5 bottom\
    \ */\n    Die(){ REP(i,6) arr[i] = i; }\n    Die(int cipher) { // 0 -> 23\n  \
    \      if (dieMap.empty()) puts(\"Call openDie(die());\"); else (*this) = dieMap[cipher];\n\
    \    }\n    Die move(int dir) {\n        Die res = (*this);\n        int t = res.arr[rotations[dir][0]];\n\
    \        REP(i,3) res.arr[rotations[dir][i]] = res.arr[rotations[dir][i+1]];\n\
    \        res.arr[rotations[dir][3]] = t;\n        return res;\n    }\n    int\
    \ encrypt() { // 0 -> 23\n        int res = arr[0] * 4;\n        FOR(i,3,5) if\
    \ (arr[i] < arr[2]) res++;\n        return res;\n    }\n};\nvoid openDie(Die t)\
    \ {\n    dieMap[t.encrypt()] = t;\n    REP(dir,4) if (!dieMap.count(t.move(dir).encrypt()))\
    \ openDie(t.move(dir));\n}\n\n#line 3 \"Misc/Die.cpp\"\nint main() {\n}\n"
  code: '#include "../template.h"

    #include "Die.h"

    int main() {

    }

    '
  dependsOn:
  - template.h
  - Misc/Die.h
  isVerificationFile: false
  path: Misc/Die.cpp
  requiredBy: []
  timestamp: '2022-01-13 13:16:22+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Die.cpp
layout: document
redirect_from:
- /library/Misc/Die.cpp
- /library/Misc/Die.cpp.html
title: Misc/Die.cpp
---
