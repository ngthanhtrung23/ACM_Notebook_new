---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Misc/container_pipe_utils.h
    title: Misc/container_pipe_utils.h
  - icon: ':heavy_check_mark:'
    path: debug.h
    title: debug.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"Misc/tests/pipe_utils.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#line 1 \"debug.h\"\n#define\
    \ FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)\n#define REP(i, a)\
    \ for (int i = 0, _##i = (a); i < _##i; ++i)\n \n#define DEBUG(X) { auto _X =\
    \ (X); std::cerr << \"L\" << __LINE__ << \": \" << #X << \" = \" << (_X) << std::endl;\
    \ }\n#define PR(A, n) { std::cerr << \"L\" << __LINE__ << \": \" << #A << \" =\
    \ \"; FOR(_, 1, n) std::cerr << A[_] << ' '; std::cerr << std::endl; }\n#define\
    \ PR0(A, n) { std::cerr << \"L\" << __LINE__ << \": \" << #A << \" = \"; REP(_,\
    \ n) std::cerr << A[_] << ' '; std::cerr << std::endl; }\n\n// For printing std::pair,\
    \ container, etc.\n// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html\n\
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
    \ t);\n}\n#line 1 \"Misc/container_pipe_utils.h\"\n// Container operations, idea\
    \ from https://codeforces.com/submissions/Yuu {{{\ntemplate<typename T> struct\
    \ accumulator_type { using type = T; };\ntemplate<> struct accumulator_type<int32_t>\
    \ { using type = int64_t; };\ntemplate<> struct accumulator_type<uint32_t> { using\
    \ type = uint64_t; };\ntemplate<> struct accumulator_type<int64_t> { using type\
    \ = __int128_t; };\ntemplate<> struct accumulator_type<uint64_t> { using type\
    \ = __uint128_t; };\n\nenum ReduceOp { MIN, MAX };\ntemplate<typename Container>\n\
    auto operator | (const Container& a, ReduceOp op) {\n    switch (op) {\n     \
    \   case MIN:\n            return *min_element(a.begin(), a.end());\n        case\
    \ MAX:\n            return *max_element(a.begin(), a.end());\n    }\n    assert(false);\n\
    }\nenum SumOp { SUM, SUM_XOR };\ntemplate<typename Container>\nauto operator |\
    \ (const Container& a, SumOp op) {\n    typename accumulator_type<typename Container::value_type>::type\
    \ sum{};\n    switch (op) {\n        case SUM:\n            for (const auto& elem\
    \ : a) sum += elem;\n            return sum;\n        case SUM_XOR:\n        \
    \    for (const auto& elem : a) sum ^= elem;\n            return sum;\n    }\n\
    \    assert(false);\n}\nenum ComparableOp { SORT };\ntemplate<typename Container>\n\
    Container& operator | (Container& a, ComparableOp op) {\n    __typeof(a) values;\n\
    \    switch (op) {\n        case SORT:\n            std::sort(a.begin(), a.end());\n\
    \            break;\n    }\n    return a;\n}\nenum TransformOp { ADD_1, PREFIX_SUM,\
    \ PREFIX_SUM_XOR, REVERSE, SUB_1, COMPRESS };\ntemplate<typename Container>\n\
    Container& operator | (Container& a, TransformOp op) {\n    __typeof(a) values;\n\
    \    switch (op) {\n        case ADD_1:\n            for (auto& elem : a) elem\
    \ += 1;\n            break;\n        case COMPRESS:\n            values = a;\n\
    \            std::sort(values.begin(), values.end());\n            values.erase(std::unique(values.begin(),\
    \ values.end()), values.end());\n            for (auto& value : a) value = std::lower_bound(values.begin(),\
    \ values.end(), value) - values.begin();\n            break;\n        case PREFIX_SUM:\n\
    \            std::partial_sum(a.begin(), a.end(), a.begin());\n            break;\n\
    \        case PREFIX_SUM_XOR:\n            std::partial_sum(a.begin(), a.end(),\
    \ a.begin(), [] (int x, int y) { return x ^ y; });\n            break;\n     \
    \   case REVERSE:\n            std::reverse(a.begin(), a.end());\n           \
    \ break;\n        case SUB_1:\n            for (auto& elem : a) elem -= 1;\n \
    \           break;\n    }\n    return a;\n}\nenum IOp { IN };\ntemplate<typename\
    \ Container>\nContainer& operator | (Container& a, IOp op) {\n    switch (op)\
    \ {\n        case IN:\n            for (auto& elem : a) cin >> elem;\n       \
    \     break;\n    }\n    return a;\n}\nenum OOp { OUT_ONE_PER_LINE, OUT_1_LINE\
    \ };\ntemplate<typename Container>\nContainer& operator | (Container& a, OOp op)\
    \ {\n    switch (op) {\n        case OUT_1_LINE:\n            for (size_t i =\
    \ 0; i < a.size(); ++i) {\n                if (i > 0) cout << ' ';\n         \
    \       cout << a[i];\n            }\n            break;\n        case OUT_ONE_PER_LINE:\n\
    \            for (const auto& elem : a) cout << elem << '\\n';\n            break;\n\
    \    }\n    return a;\n}\n// }}}\n#line 7 \"Misc/tests/pipe_utils.test.cpp\"\n\
    \nint main() {\n    // min, max\n    {\n        vector<int> a {3, 5, 4, 1, 2};\n\
    \        assert((a | MIN) == 1);\n        assert((a | MAX) == 5);\n\n        vector<int64_t>\
    \ a64 {3000111000111LL, 5000111000111LL, 4000111000111LL, 1000111000111LL, 2000111000111LL};\n\
    \        assert((a64 | MIN) == 1000111000111LL);\n        assert((a64 | MAX) ==\
    \ 5000111000111LL);\n\n        vector<string> as {\"10\", \"3\", \"5\", \"4\"\
    , \"1\"};\n        assert((as | MIN) == \"1\");\n        assert((as | MAX) ==\
    \ \"5\");\n    }\n\n    // sum\n    {\n        vector<int> a {1000111000, 1000111000,\
    \ 1000111000};\n        assert((a | SUM) == 3000333000LL);\n\n        vector<int>\
    \ a2 {1, 2, 3};\n        assert((a2 | SUM_XOR) == 0);\n\n        vector<int> a3\
    \ {1, 2, 4};\n        assert((a3 | SUM_XOR) == 7);\n    }\n\n    // sort\n   \
    \ {\n        vector<int> a {3, 5, 4, 1, 2};\n        a | SORT | ADD_1;\n     \
    \   assert((a == vector<int>{2, 3, 4, 5, 6}));\n\n        vector<int> a2 {30,\
    \ 50, 0, 40, 10, 20};\n        a2 | COMPRESS;\n        assert((a2 == vector<int>{3,\
    \ 5, 0, 4, 1, 2}));\n\n        vector<int> a3 {2, 3, 4};\n        a3 | SUB_1 |\
    \ PREFIX_SUM;\n        assert((a3 == vector<int>{1, 3, 6}));\n\n        vector<int>\
    \ a4 {3, 2, 1};\n        a4 | REVERSE | SUB_1;\n        assert((a4 == vector<int>{0,\
    \ 1, 2}));\n    }\n\n    cout << \"Hello World\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n#include \"../../debug.h\"\
    \n#include \"../container_pipe_utils.h\"\n\nint main() {\n    // min, max\n  \
    \  {\n        vector<int> a {3, 5, 4, 1, 2};\n        assert((a | MIN) == 1);\n\
    \        assert((a | MAX) == 5);\n\n        vector<int64_t> a64 {3000111000111LL,\
    \ 5000111000111LL, 4000111000111LL, 1000111000111LL, 2000111000111LL};\n     \
    \   assert((a64 | MIN) == 1000111000111LL);\n        assert((a64 | MAX) == 5000111000111LL);\n\
    \n        vector<string> as {\"10\", \"3\", \"5\", \"4\", \"1\"};\n        assert((as\
    \ | MIN) == \"1\");\n        assert((as | MAX) == \"5\");\n    }\n\n    // sum\n\
    \    {\n        vector<int> a {1000111000, 1000111000, 1000111000};\n        assert((a\
    \ | SUM) == 3000333000LL);\n\n        vector<int> a2 {1, 2, 3};\n        assert((a2\
    \ | SUM_XOR) == 0);\n\n        vector<int> a3 {1, 2, 4};\n        assert((a3 |\
    \ SUM_XOR) == 7);\n    }\n\n    // sort\n    {\n        vector<int> a {3, 5, 4,\
    \ 1, 2};\n        a | SORT | ADD_1;\n        assert((a == vector<int>{2, 3, 4,\
    \ 5, 6}));\n\n        vector<int> a2 {30, 50, 0, 40, 10, 20};\n        a2 | COMPRESS;\n\
    \        assert((a2 == vector<int>{3, 5, 0, 4, 1, 2}));\n\n        vector<int>\
    \ a3 {2, 3, 4};\n        a3 | SUB_1 | PREFIX_SUM;\n        assert((a3 == vector<int>{1,\
    \ 3, 6}));\n\n        vector<int> a4 {3, 2, 1};\n        a4 | REVERSE | SUB_1;\n\
    \        assert((a4 == vector<int>{0, 1, 2}));\n    }\n\n    cout << \"Hello World\\\
    n\";\n    return 0;\n}\n"
  dependsOn:
  - debug.h
  - Misc/container_pipe_utils.h
  isVerificationFile: true
  path: Misc/tests/pipe_utils.test.cpp
  requiredBy: []
  timestamp: '2023-05-21 16:46:44+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Misc/tests/pipe_utils.test.cpp
layout: document
redirect_from:
- /verify/Misc/tests/pipe_utils.test.cpp
- /verify/Misc/tests/pipe_utils.test.cpp.html
title: Misc/tests/pipe_utils.test.cpp
---
