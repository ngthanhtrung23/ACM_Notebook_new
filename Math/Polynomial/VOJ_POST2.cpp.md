---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/Polynomial/FFT.h
    title: Math/Polynomial/FFT.h
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
  bundledCode: "#line 1 \"template.h\"\n#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b;\
    \ i++)\n#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)\n#define REP(i,a)\
    \ for(int i=0,_a=(a); i<_a; i++)\n#define EACH(it,a) for(__typeof(a.begin()) it\
    \ = a.begin(); it != a.end(); ++it)\n\n#define DEBUG(x) { cout << #x << \" = \"\
    ; cout << (x) << endl; }\n#define PR(a,n) { cout << #a << \" = \"; FOR(_,1,n)\
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
    \ (0, r-1)(rng);\n}\n#line 2 \"Math/Polynomial/VOJ_POST2.cpp\"\n\nconst int MN\
    \ = 1000111;\n#line 1 \"Math/Polynomial/FFT.h\"\n// Let's just not use this inefficient\
    \ code and use dacin21's code here:\n// https://github.com/dacin21/dacin21_codebook/blob/master/nt/polynomials_2.0.cpp\n\
    //\n// Example with using Fft class directly (maybe it's easier to use dacin21's\
    \ class Polynomial):\n//\n// const int MOD = 1e9 + 7;\n// vector<int64_t> a, b;\n\
    // vector<int64_t> res;\n// \n// // res = a * b:\n// if (mod <= 5000) Fft<Complex<double>>::poly_mul_faster(res,\
    \ a, b, MOD);\n// else Fft<Complex<double>>::poly_mul_split(res, a, b, MOD);\n\
    //\n// // res = a * a;\n// if (mod <= 5000) Fft<Complex<double>>::poly_mul_faster(res,\
    \ a, a, MOD);\n// else Fft<Complex<double>>::poly_square_split(res, a, MOD);\n\
    \n\n\n\n\n\n\n// Below code is my inefficient implementation:\n// Tested:\n//\
    \ - FBHC 2016 R3 - Problem E\n// - https://open.kattis.com/problems/polymul2 (need\
    \ long double)\n// Note:\n// - a[2] will have size <= 2*n\n// - When rounding,\
    \ careful with negative numbers:\nint my_round(double x) {\n    if (x < 0) return\
    \ -my_round(-x);\n    return (int) (x + 1e-3);\n}\n\nconst double PI = acos((double)\
    \ -1.0);\n\ntypedef complex<double> cplex;\nint rev[MN];\ncplex wlen_pw[MN], fa[MN],\
    \ fb[MN];\n\nvoid fft(cplex a[], int n, bool invert) {\n    for (int i = 0; i\
    \ < n; ++i) if (i < rev[i]) swap (a[i], a[rev[i]]);\n\n    for (int len = 2; len\
    \ <= n; len <<= 1) {\n        double alpha = 2 * PI / len * (invert ? -1 : +1);\n\
    \        int len2 = len >> 1;\n\n        wlen_pw[0] = cplex(1, 0);\n        cplex\
    \ wlen(cos(alpha), sin(alpha));\n        for (int i = 1; i < len2; ++i) wlen_pw[i]\
    \ = wlen_pw[i-1] * wlen;\n\n        for (int i = 0; i < n; i += len) {\n     \
    \       cplex t, *pu = a+i, *pv = a + i + len2,\n                    *pu_end =\
    \ a + i + len2, *pw = wlen_pw;\n            for (; pu != pu_end; ++pu, ++pv, ++pw)\
    \ {\n                t = *pv * *pw;\n                *pv = *pu - t;\n        \
    \        *pu += t;\n            }\n        }\n    }\n\n    if (invert) REP(i,\
    \ n) a[i] /= n;\n}\n\nvoid calcRev(int n, int logn) {\n    REP(i, n) {\n     \
    \   rev[i] = 0;\n        REP(j, logn) if (i & (1 << j)) rev[i] |= 1 << (logn -\
    \ 1 - j);\n    }\n}\n\nvoid mulpoly(int a[], int b[], ll c[], int na, int nb,\
    \ int &n) {\n    int l = max(na, nb), logn = 0;\n    for (n = 1; n < l; n <<=\
    \ 1) ++logn;\n    n <<= 1; ++logn;\n    calcRev(n, logn);\n\n    REP(i,n) fa[i]\
    \ = fb[i] = cplex(0);\n    REP(i,na) fa[i] = cplex(a[i]);\n    REP(i,nb) fb[i]\
    \ = cplex(b[i]);\n\n    fft(fa, n, false);\n    fft(fb, n, false);\n\n    REP(i,n)\
    \ fa[i] *= fb[i];\n    fft(fa, n, true);\n\n    REP(i,n) c[i] = (ll)(fa[i].real()\
    \ + 0.5);\n}\n#line 5 \"Math/Polynomial/VOJ_POST2.cpp\"\n\nint cnt_a[MN], cnt_b[MN];\n\
    Base a[3][MN];\n\nint main() {\n    ios :: sync_with_stdio(false); cin.tie(NULL);\n\
    \    int n; cin >> n;\n    FOR(i,1,n) {\n        int u; cin >> u;\n        ++cnt_a[u\
    \ + 50000];\n    }\n    FOR(i,1,n) {\n        int u; cin >> u;\n        ++cnt_b[u\
    \ + 50000];\n    }\n\n    FOR(i,0,100000) {\n        a[0][i] = Base(cnt_a[i],\
    \ 0);\n        a[1][i] = Base(cnt_b[i], 0);\n    }\n    multiply(a, 100000);\n\
    \n    long long res = 0;\n    FOR(i,1,n) {\n        int u; cin >> u;\n       \
    \ res += (long long) (a[2][100000 + u].real() + 0.5);\n    }\n    cout << res\
    \ << endl;\n}\n"
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
  timestamp: '2022-01-09 23:35:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Polynomial/VOJ_POST2.cpp
layout: document
redirect_from:
- /library/Math/Polynomial/VOJ_POST2.cpp
- /library/Math/Polynomial/VOJ_POST2.cpp.html
title: Math/Polynomial/VOJ_POST2.cpp
---
