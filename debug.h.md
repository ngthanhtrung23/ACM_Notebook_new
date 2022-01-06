---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
  bundledCode: "#line 1 \"debug.h\"\n#define FOR(i, a, b) for (int i = (a), _##i =\
    \ (b); i <= _##i; ++i)\n#define FORD(i, a, b) for (int i = (a), _##i = (b); i\
    \ >= _##i; --i)\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\
    \ \n#define DEBUG(X) { auto _X = (X); cerr << \"L\" << __LINE__ << \": \" << #X\
    \ << \" = \" << (_X) << endl; }\n#define PR(A, n) { cerr << \"L\" << __LINE__\
    \ << \": \" << #A << \" = \"; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl;\
    \ }\n#define PR0(A, n) { cerr << \"L\" << __LINE__ << \": \" << #A << \" = \"\
    ; REP(_, n) cerr << A[_] << ' '; cerr << endl; }\n\n// For printing pair, container,\
    \ etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
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
    \ t);\n}\n"
  code: "#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n#define\
    \ FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)\n#define REP(i,\
    \ a) for (int i = 0, _##i = (a); i < _##i; ++i)\n \n#define DEBUG(X) { auto _X\
    \ = (X); cerr << \"L\" << __LINE__ << \": \" << #X << \" = \" << (_X) << endl;\
    \ }\n#define PR(A, n) { cerr << \"L\" << __LINE__ << \": \" << #A << \" = \";\
    \ FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }\n#define PR0(A, n) { cerr\
    \ << \"L\" << __LINE__ << \": \" << #A << \" = \"; REP(_, n) cerr << A[_] << '\
    \ '; cerr << endl; }\n\n// For printing pair, container, etc.\n// Copied from\
    \ https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\ntemplate<class\
    \ U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {\n   \
    \ return out << '(' << p.first << \", \" << p.second << ')';\n}\n\ntemplate<class\
    \ Con, class = decltype(begin(declval<Con>()))>\ntypename enable_if<!is_same<Con,\
    \ string>::value, ostream&>::type\noperator << (ostream& out, const Con& con)\
    \ {\n    out << '{';\n    for (auto beg = con.begin(), it = beg; it != con.end();\
    \ it++) {\n        out << (it == beg ? \"\" : \", \") << *it;\n    }\n    return\
    \ out << '}';\n}\ntemplate<size_t i, class T> ostream& print_tuple_utils(ostream&\
    \ out, const T& tup) {\n    if constexpr(i == tuple_size<T>::value) return out\
    \ << \")\"; \n    else return print_tuple_utils<i + 1, T>(out << (i ? \", \" :\
    \ \"(\") << get<i>(tup), tup); \n}\ntemplate<class ...U> ostream& operator <<\
    \ (ostream& out, const tuple<U...>& t) {\n    return print_tuple_utils<0, tuple<U...>>(out,\
    \ t);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: debug.h
  requiredBy: []
  timestamp: '2022-01-06 16:25:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.h
layout: document
redirect_from:
- /library/debug.h
- /library/debug.h.html
title: debug.h
---
