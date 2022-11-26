---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/Polynomial/FFT.h
    title: Math/Polynomial/FFT.h
  - icon: ':heavy_check_mark:'
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
    \  solve();\n    return 0;\n}\n#line 2 \"Math/Polynomial/VOJ_POST2.cpp\"\n\nconst\
    \ int MN = 1000111;\n#line 1 \"Math/Polynomial/FFT.h\"\n// Note:\n// - When convert\
    \ double -> int, use my_round(x) which handles negative numbers\n//   correctly.\n\
    //\n// Tested:\n// - https://open.kattis.com/problems/polymul2\n// - https://www.spoj.com/problems/VFMUL/\n\
    // - https://www.spoj.com/problems/MUL/\n//\n// FFT {{{\n// Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastFourierTransform.h\n\
    \nusing ld = long double;\n// Can use std::complex<ld> instead to make code shorter\
    \ (but it will be slightly slower)\nstruct Complex {\n    ld x[2];\n\n    Complex()\
    \ { x[0] = x[1] = 0.0; }\n    Complex(ld a) { x[0] = a; }\n    Complex(ld a, ld\
    \ b) { x[0] = a; x[1] = b; }\n    Complex(const std::complex<ld>& c) {\n     \
    \   x[0] = c.real();\n        x[1] = c.imag();\n    }\n\n    Complex conj() const\
    \ {\n        return Complex(x[0], -x[1]);\n    }\n\n    Complex operator + (const\
    \ Complex& c) const {\n        return Complex {\n            x[0] + c.x[0],\n\
    \            x[1] + c.x[1],\n        };\n    }\n    Complex operator - (const\
    \ Complex& c) const {\n        return Complex {\n            x[0] - c.x[0],\n\
    \            x[1] - c.x[1],\n        };\n    }\n    Complex operator * (const\
    \ Complex& c) const {\n        return Complex(\n            x[0] * c.x[0] - x[1]\
    \ * c.x[1],\n            x[0] * c.x[1] + x[1] * c.x[0]\n        );\n    }\n\n\
    \    Complex& operator += (const Complex& c) { return *this = *this + c; }\n \
    \   Complex& operator -= (const Complex& c) { return *this = *this - c; }\n  \
    \  Complex& operator *= (const Complex& c) { return *this = *this * c; }\n};\n\
    void fft(vector<Complex>& a) {\n    int n = a.size();\n    int L = 31 - __builtin_clz(n);\n\
    \    static vector<Complex> R(2, 1);\n    static vector<Complex> rt(2, 1);\n \
    \   for (static int k = 2; k < n; k *= 2) {\n        R.resize(n);\n        rt.resize(n);\n\
    \        auto x = Complex(polar(1.0L, acos(-1.0L) / k));\n        for (int i =\
    \ k; i < 2*k; ++i) {\n            rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];\n\
    \        }\n    }\n    vector<int> rev(n);\n    for (int i = 0; i < n; ++i) rev[i]\
    \ = (rev[i/2] | (i&1) << L) / 2;\n    for (int i = 0; i < n; ++i) if (i < rev[i])\
    \ swap(a[i], a[rev[i]]);\n\n    for (int k = 1; k < n; k *= 2) {\n        for\
    \ (int i = 0; i < n; i += 2*k) {\n            for (int j = 0; j < k; ++j) {\n\
    \                auto x = (ld*) &rt[j+k].x, y = (ld*) &a[i+j+k].x;\n         \
    \       Complex z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);\n           \
    \     a[i + j + k] = a[i + j] - z;\n                a[i + j] += z;\n         \
    \   }\n        }\n    }\n}\nvector<ld> multiply(const vector<ld>& a, const vector<ld>&\
    \ b) {\n    if (a.empty() || b.empty()) return {};\n    vector<ld> res(a.size()\
    \ + b.size() - 1);\n    int L = 32 - __builtin_clz(res.size()), n = 1<<L;\n  \
    \  vector<Complex> in(n), out(n);\n\n    for (size_t i = 0; i < a.size(); ++i)\
    \ in[i].x[0] = a[i];\n    for (size_t i = 0; i < b.size(); ++i) in[i].x[1] = b[i];\n\
    \n    fft(in);\n    for (Complex& x : in) x *= x;\n\n    for (int i = 0; i < n;\
    \ ++i) out[i] = in[-i & (n-1)] - in[i].conj();\n    fft(out);\n\n    for (size_t\
    \ i = 0; i < res.size(); ++i) res[i] = out[i].x[1] / (4*n);\n    return res;\n\
    }\nint my_round(double x) {\n    if (x < 0) return -my_round(-x);\n    return\
    \ (int) (x + 1e-6);\n}\n// }}}\n#line 5 \"Math/Polynomial/VOJ_POST2.cpp\"\n\n\
    int cnt_a[MN], cnt_b[MN];\nBase a[3][MN];\n\nint main() {\n    ios :: sync_with_stdio(false);\
    \ cin.tie(NULL);\n    int n; cin >> n;\n    FOR(i,1,n) {\n        int u; cin >>\
    \ u;\n        ++cnt_a[u + 50000];\n    }\n    FOR(i,1,n) {\n        int u; cin\
    \ >> u;\n        ++cnt_b[u + 50000];\n    }\n\n    FOR(i,0,100000) {\n       \
    \ a[0][i] = Base(cnt_a[i], 0);\n        a[1][i] = Base(cnt_b[i], 0);\n    }\n\
    \    multiply(a, 100000);\n\n    long long res = 0;\n    FOR(i,1,n) {\n      \
    \  int u; cin >> u;\n        res += (long long) (a[2][100000 + u].real() + 0.5);\n\
    \    }\n    cout << res << endl;\n}\n"
  code: "#include \"../../template.h\"\n\nconst int MN = 1000111;\n#include \"FFT.h\"\
    \n\nint cnt_a[MN], cnt_b[MN];\nBase a[3][MN];\n\nint main() {\n    ios :: sync_with_stdio(false);\
    \ cin.tie(NULL);\n    int n; cin >> n;\n    FOR(i,1,n) {\n        int u; cin >>\
    \ u;\n        ++cnt_a[u + 50000];\n    }\n    FOR(i,1,n) {\n        int u; cin\
    \ >> u;\n        ++cnt_b[u + 50000];\n    }\n\n    FOR(i,0,100000) {\n       \
    \ a[0][i] = Base(cnt_a[i], 0);\n        a[1][i] = Base(cnt_b[i], 0);\n    }\n\
    \    multiply(a, 100000);\n\n    long long res = 0;\n    FOR(i,1,n) {\n      \
    \  int u; cin >> u;\n        res += (long long) (a[2][100000 + u].real() + 0.5);\n\
    \    }\n    cout << res << endl;\n}\n"
  dependsOn:
  - template.h
  - Math/Polynomial/FFT.h
  isVerificationFile: false
  path: Math/Polynomial/VOJ_POST2.cpp
  requiredBy: []
  timestamp: '2022-11-27 00:28:22+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Polynomial/VOJ_POST2.cpp
layout: document
redirect_from:
- /library/Math/Polynomial/VOJ_POST2.cpp
- /library/Math/Polynomial/VOJ_POST2.cpp.html
title: Math/Polynomial/VOJ_POST2.cpp
---
