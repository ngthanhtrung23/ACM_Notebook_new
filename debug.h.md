---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Misc/tests/pipe_utils.test.cpp
    title: Misc/tests/pipe_utils.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
  bundledCode: "#line 1 \"debug.h\"\n#define FOR(i, a, b) for (int i = (a), _##i =\
    \ (b); i <= _##i; ++i)\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i;\
    \ ++i)\n \n#define DEBUG(X) { auto _X = (X); std::cerr << \"L\" << __LINE__ <<\
    \ \": \" << #X << \" = \" << (_X) << std::endl; }\n#define PR(A, n) { std::cerr\
    \ << \"L\" << __LINE__ << \": \" << #A << \" = \"; FOR(_, 1, n) std::cerr << A[_]\
    \ << ' '; std::cerr << std::endl; }\n#define PR0(A, n) { std::cerr << \"L\" <<\
    \ __LINE__ << \": \" << #A << \" = \"; REP(_, n) std::cerr << A[_] << ' '; std::cerr\
    \ << std::endl; }\n\n// For printing std::pair, container, etc.\n// Copied from\
    \ https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\ntemplate<class\
    \ U, class V> std::ostream& operator << (std::ostream& out, const std::pair<U,\
    \ V>& p) {\n    return out << '(' << p.first << \", \" << p.second << ')';\n}\n\
    \ntemplate<class Con, class = decltype(begin(std::declval<Con>()))>\ntypename\
    \ std::enable_if<!std::is_same<Con, std::string>::value, std::ostream&>::type\n\
    operator << (std::ostream& out, const Con& con) {\n    out << '{';\n    for (auto\
    \ beg = con.begin(), it = beg; it != con.end(); it++) {\n        out << (it ==\
    \ beg ? \"\" : \", \") << *it;\n    }\n    return out << '}';\n}\ntemplate<size_t\
    \ i, class T> std::ostream& print_tuple_utils(std::ostream& out, const T& tup)\
    \ {\n    if (i == std::tuple_size<T>::value) return out << \")\"; \n    else return\
    \ print_tuple_utils<i + 1, T>(out << (i ? \", \" : \"(\") << get<i>(tup), tup);\
    \ \n}\ntemplate<class ...U> std::ostream& operator << (std::ostream& out, const\
    \ std::tuple<U...>& t) {\n    return print_tuple_utils<0, std::tuple<U...>>(out,\
    \ t);\n}\n"
  code: "#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n#define\
    \ REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n \n#define DEBUG(X) {\
    \ auto _X = (X); std::cerr << \"L\" << __LINE__ << \": \" << #X << \" = \" <<\
    \ (_X) << std::endl; }\n#define PR(A, n) { std::cerr << \"L\" << __LINE__ << \"\
    : \" << #A << \" = \"; FOR(_, 1, n) std::cerr << A[_] << ' '; std::cerr << std::endl;\
    \ }\n#define PR0(A, n) { std::cerr << \"L\" << __LINE__ << \": \" << #A << \"\
    \ = \"; REP(_, n) std::cerr << A[_] << ' '; std::cerr << std::endl; }\n\n// For\
    \ printing std::pair, container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
    template<class U, class V> std::ostream& operator << (std::ostream& out, const\
    \ std::pair<U, V>& p) {\n    return out << '(' << p.first << \", \" << p.second\
    \ << ')';\n}\n\ntemplate<class Con, class = decltype(begin(std::declval<Con>()))>\n\
    typename std::enable_if<!std::is_same<Con, std::string>::value, std::ostream&>::type\n\
    operator << (std::ostream& out, const Con& con) {\n    out << '{';\n    for (auto\
    \ beg = con.begin(), it = beg; it != con.end(); it++) {\n        out << (it ==\
    \ beg ? \"\" : \", \") << *it;\n    }\n    return out << '}';\n}\ntemplate<size_t\
    \ i, class T> std::ostream& print_tuple_utils(std::ostream& out, const T& tup)\
    \ {\n    if (i == std::tuple_size<T>::value) return out << \")\"; \n    else return\
    \ print_tuple_utils<i + 1, T>(out << (i ? \", \" : \"(\") << get<i>(tup), tup);\
    \ \n}\ntemplate<class ...U> std::ostream& operator << (std::ostream& out, const\
    \ std::tuple<U...>& t) {\n    return print_tuple_utils<0, std::tuple<U...>>(out,\
    \ t);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: debug.h
  requiredBy: []
  timestamp: '2022-07-23 00:59:09+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Misc/tests/pipe_utils.test.cpp
documentation_of: debug.h
layout: document
redirect_from:
- /library/debug.h
- /library/debug.h.html
title: debug.h
---
