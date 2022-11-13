---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/berlekamp_massey.test.cpp
    title: Math/tests/berlekamp_massey.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/61306?#comment-454682
    - https://cses.fi/problemset/task/2181/
    - https://github.com/zimpha/algorithmic-library/blob/master/cpp/mathematics/linear-recurrence.cc
    - https://judge.yosupo.jp/problem/find_linear_recurrence
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    - https://mzhang2021.github.io/cp-blog/berlekamp-massey/
    - https://oj.vnoi.info/problem/errichto_matexp_fibonacci
    - https://oj.vnoi.info/problem/selfdiv
  bundledCode: "#line 1 \"Math/LinearRecurrence_BerlekampMassey.h\"\n// Berlekamp\
    \ Massey {{{\n// Given sequence s0, ..., s(N-1)\n// Find sequence c1, ..., cd\
    \ with minimum d (d >= 0), such that:\n//   si = sum(s(i-j) * c(j), for j = 1..d)\n\
    //\n// Tutorial: https://mzhang2021.github.io/cp-blog/berlekamp-massey/\n// If\
    \ we have the linear recurrence, we can compute s(n):\n// - O(n*d) naively\n//\
    \ - O(d^3 * log(n)) with matrix exponentiation\n// - O(d*log(d)*log(k)) with generating\
    \ function (tutorial above)\n//\n// Solving problems where we need to compute\
    \ f(n) mod P (e.g. VOJ SELFDIV)\n// - Guess that f is a linear recurrence\n//\
    \ - Compute f(n) for small n\n// - Run Berlekamp Massey to find C (we must have\
    \ 2*|C| < n, otherwise it's wrong)\n//\n// Note:\n// - should be calculated in\
    \ prime modulo (i.e. T=modint), as it\n//   requires modular inverse\n// - when\
    \ modulo is not prime --> https://github.com/zimpha/algorithmic-library/blob/master/cpp/mathematics/linear-recurrence.cc\n\
    //   but this comment says it doesn't work on some problem: https://codeforces.com/blog/entry/61306?#comment-454682\n\
    //\n// Tested:\n// - (BM) https://judge.yosupo.jp/problem/find_linear_recurrence\n\
    // - (BM + find_kth) https://oj.vnoi.info/problem/selfdiv\n// - (find_kth) https://oj.vnoi.info/problem/errichto_matexp_fibonacci\n\
    // - (find_kth) https://cses.fi/problemset/task/2181/\n// - 2022 ICPC Vietnam\
    \ National - H\n\n// Returns c1, ..., cd\ntemplate<typename T>\nvector<T> berlekampMassey(vector<T>\
    \ s) {\n    if (s.empty()) return {};\n\n    int n = s.size(), L = 0, m = 0; //\
    \ m = i - f\n    vector<T> C(n), D(n), oldC;\n    C[0] = D[0] = 1;\n    T df1\
    \ = 1;  // d(f+1)\n    for (int i = 0; i < n; i++) {\n        ++m;\n        //\
    \ check if C(i) == a(i)\n        // delta = s_i - sum( cj * s(i-j) ) = d(f+1)?\n\
    \        T delta = s[i];\n        for (int j = 1; j <= L; j++) {\n           \
    \ delta += C[j] * s[i-j];  // C(j) is already multiplied by -1\n        }\n  \
    \      if (delta == 0) continue;  // C(i) is correct\n\n        // Update c =\
    \ c + d\n        oldC = C;\n        T coeff = delta * df1.inv();\n        for\
    \ (int j = m; j < n; j++) {\n            C[j] -= coeff * D[j - m];  // prepend\
    \ D with m zeroes, multiply by coeff and add to C\n        }\n        if (2*L\
    \ > i) continue;\n        L = i + 1 - L, D = oldC, df1 = delta, m = 0;\n    }\n\
    \    C.resize(L + 1);\n    C.erase(C.begin());\n    for (auto& x : C) x = -x;\n\
    \    return C;\n}\n\n// Helper function\ntemplate<typename T>\nvector<T> mul(const\
    \ vector<T> &a, const vector<T> &b, const vector<T>& c) {\n    vector<T> ret(a.size()\
    \ + b.size() - 1);\n    // ret = a * b\n    for (int i=0; i<(int)a.size(); i++)\n\
    \        for (int j=0; j<(int)b.size(); j++)\n            ret[i+j] += a[i] * b[j];\n\
    \n    int n = c.size();\n    // reducing ret mod f(x)\n    for (int i=(int)ret.size()-1;\
    \ i>=n; i--)\n        for (int j=n-1; j>=0; j--)\n            ret[i-j-1] += ret[i]\
    \ * c[j];\n    ret.resize(min((int) ret.size(), n));\n    return ret;\n}\n\n//\
    \ Find k-th element in linear recurrence: O(d^2 * logn)\n// Need faster code?\
    \ See https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\n\
    //   (but usually not needed since bottleneck is BerlekampMassey\n//\n// Params:\n\
    // - c: as returned by berlekampMassey\n// - s: s0, s1, ..., s(N-1)\n// Returns:\
    \ s(k)\ntemplate<typename T>\nT solve(const vector<T> &c, const vector<T> &s,\
    \ long long k) {\n    int n = (int) c.size();\n    assert(c.size() <= s.size());\n\
    \n    vector<T> a = n == 1 ? vector<T>{c[0]} : vector<T>{0, 1}, x{1};\n    for\
    \ (; k>0; k/=2) {\n        if (k % 2)\n            x = mul(x, a, c);  // mul(a,\
    \ b) computes a(x) * b(x) mod f(x)\n        a = mul(a, a, c);\n    }\n    x.resize(n);\n\
    \n    T ret = 0;\n    for (int i=0; i<n; i++)\n        ret += x[i] * s[i];\n \
    \   return ret;\n}\n// }}}\n"
  code: "// Berlekamp Massey {{{\n// Given sequence s0, ..., s(N-1)\n// Find sequence\
    \ c1, ..., cd with minimum d (d >= 0), such that:\n//   si = sum(s(i-j) * c(j),\
    \ for j = 1..d)\n//\n// Tutorial: https://mzhang2021.github.io/cp-blog/berlekamp-massey/\n\
    // If we have the linear recurrence, we can compute s(n):\n// - O(n*d) naively\n\
    // - O(d^3 * log(n)) with matrix exponentiation\n// - O(d*log(d)*log(k)) with\
    \ generating function (tutorial above)\n//\n// Solving problems where we need\
    \ to compute f(n) mod P (e.g. VOJ SELFDIV)\n// - Guess that f is a linear recurrence\n\
    // - Compute f(n) for small n\n// - Run Berlekamp Massey to find C (we must have\
    \ 2*|C| < n, otherwise it's wrong)\n//\n// Note:\n// - should be calculated in\
    \ prime modulo (i.e. T=modint), as it\n//   requires modular inverse\n// - when\
    \ modulo is not prime --> https://github.com/zimpha/algorithmic-library/blob/master/cpp/mathematics/linear-recurrence.cc\n\
    //   but this comment says it doesn't work on some problem: https://codeforces.com/blog/entry/61306?#comment-454682\n\
    //\n// Tested:\n// - (BM) https://judge.yosupo.jp/problem/find_linear_recurrence\n\
    // - (BM + find_kth) https://oj.vnoi.info/problem/selfdiv\n// - (find_kth) https://oj.vnoi.info/problem/errichto_matexp_fibonacci\n\
    // - (find_kth) https://cses.fi/problemset/task/2181/\n// - 2022 ICPC Vietnam\
    \ National - H\n\n// Returns c1, ..., cd\ntemplate<typename T>\nvector<T> berlekampMassey(vector<T>\
    \ s) {\n    if (s.empty()) return {};\n\n    int n = s.size(), L = 0, m = 0; //\
    \ m = i - f\n    vector<T> C(n), D(n), oldC;\n    C[0] = D[0] = 1;\n    T df1\
    \ = 1;  // d(f+1)\n    for (int i = 0; i < n; i++) {\n        ++m;\n        //\
    \ check if C(i) == a(i)\n        // delta = s_i - sum( cj * s(i-j) ) = d(f+1)?\n\
    \        T delta = s[i];\n        for (int j = 1; j <= L; j++) {\n           \
    \ delta += C[j] * s[i-j];  // C(j) is already multiplied by -1\n        }\n  \
    \      if (delta == 0) continue;  // C(i) is correct\n\n        // Update c =\
    \ c + d\n        oldC = C;\n        T coeff = delta * df1.inv();\n        for\
    \ (int j = m; j < n; j++) {\n            C[j] -= coeff * D[j - m];  // prepend\
    \ D with m zeroes, multiply by coeff and add to C\n        }\n        if (2*L\
    \ > i) continue;\n        L = i + 1 - L, D = oldC, df1 = delta, m = 0;\n    }\n\
    \    C.resize(L + 1);\n    C.erase(C.begin());\n    for (auto& x : C) x = -x;\n\
    \    return C;\n}\n\n// Helper function\ntemplate<typename T>\nvector<T> mul(const\
    \ vector<T> &a, const vector<T> &b, const vector<T>& c) {\n    vector<T> ret(a.size()\
    \ + b.size() - 1);\n    // ret = a * b\n    for (int i=0; i<(int)a.size(); i++)\n\
    \        for (int j=0; j<(int)b.size(); j++)\n            ret[i+j] += a[i] * b[j];\n\
    \n    int n = c.size();\n    // reducing ret mod f(x)\n    for (int i=(int)ret.size()-1;\
    \ i>=n; i--)\n        for (int j=n-1; j>=0; j--)\n            ret[i-j-1] += ret[i]\
    \ * c[j];\n    ret.resize(min((int) ret.size(), n));\n    return ret;\n}\n\n//\
    \ Find k-th element in linear recurrence: O(d^2 * logn)\n// Need faster code?\
    \ See https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\n\
    //   (but usually not needed since bottleneck is BerlekampMassey\n//\n// Params:\n\
    // - c: as returned by berlekampMassey\n// - s: s0, s1, ..., s(N-1)\n// Returns:\
    \ s(k)\ntemplate<typename T>\nT solve(const vector<T> &c, const vector<T> &s,\
    \ long long k) {\n    int n = (int) c.size();\n    assert(c.size() <= s.size());\n\
    \n    vector<T> a = n == 1 ? vector<T>{c[0]} : vector<T>{0, 1}, x{1};\n    for\
    \ (; k>0; k/=2) {\n        if (k % 2)\n            x = mul(x, a, c);  // mul(a,\
    \ b) computes a(x) * b(x) mod f(x)\n        a = mul(a, a, c);\n    }\n    x.resize(n);\n\
    \n    T ret = 0;\n    for (int i=0; i<n; i++)\n        ret += x[i] * s[i];\n \
    \   return ret;\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/LinearRecurrence_BerlekampMassey.h
  requiredBy: []
  timestamp: '2022-11-13 20:48:45+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/berlekamp_massey.test.cpp
documentation_of: Math/LinearRecurrence_BerlekampMassey.h
layout: document
redirect_from:
- /library/Math/LinearRecurrence_BerlekampMassey.h
- /library/Math/LinearRecurrence_BerlekampMassey.h.html
title: Math/LinearRecurrence_BerlekampMassey.h
---
