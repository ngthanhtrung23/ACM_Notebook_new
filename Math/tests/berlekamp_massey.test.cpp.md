---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/LinearRecurrence_BerlekampMassey.h
    title: Math/LinearRecurrence_BerlekampMassey.h
  - icon: ':question:'
    path: Math/modulo_anta.h
    title: Math/modulo_anta.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"Math/tests/berlekamp_massey.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"Math/modulo_anta.h\"\n// Modified from anta's\
    \ code\n// Not tested with MOD > 10^9 + 7.\n// Slow?\n//\n// Tested:\n// - https://codeforces.com/gym/101383\
    \ - F (MOD = 1e9+7, +, *)\n\n// ??? somehow this is 2.5x slower on https://judge.yosupo.jp/problem/matrix_product\n\
    inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d,\
    \ unsigned &out_m) {\n    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x,\
    \ d, m;\n#ifdef __GNUC__\n    asm(\n        \"divl %4; \\n\\t\"\n        : \"\
    =a\" (d), \"=d\" (m)\n        : \"d\" (xh), \"a\" (xl), \"r\" (y)\n    );\n#else\n\
    \    __asm {\n        mov edx, dword ptr[xh];\n        mov eax, dword ptr[xl];\n\
    \        div dword ptr[y];\n        mov dword ptr[d], eax;\n        mov dword\
    \ ptr[m], edx;\n    };\n#endif\n    out_d = d; out_m = m;\n}\n\ntemplate<int MOD>\n\
    struct ModInt {\n    unsigned x;\n\n    constexpr ModInt() : x(0) { }\n    constexpr\
    \ ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD;\
    \ x = sigt; }\n\n#define COMPAREOP(OP) bool constexpr operator OP(ModInt b) const\
    \ { return x OP b.x; }\n    COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>)\
    \ COMPAREOP(<=) COMPAREOP(>=)\n#undef COMPAREOP\n\n    ModInt operator-() const\
    \ { return ModInt(x ? MOD - x : 0); }\n\n    ModInt constexpr& operator+=(ModInt\
    \ that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }\n    ModInt constexpr&\
    \ operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this;\
    \ }\n    ModInt &operator*=(ModInt that) {\n        unsigned dummy;\n        fasterLLDivMod((unsigned\
    \ long long)x * that.x, MOD, dummy, x);\n        return *this;\n    }\n    ModInt\
    \ operator*(ModInt that) const {\n        ModInt res;\n        unsigned dummy;\n\
    \        fasterLLDivMod((unsigned long long)x * that.x, MOD, dummy, res.x);\n\
    \        return res;\n    }\n    ModInt operator+(ModInt that) const { return\
    \ ModInt(*this) += that; }\n    ModInt operator-(ModInt that) const { return ModInt(*this)\
    \ -= that; }\n\n    // Below: copied from user202729_, not tested.\n    ModInt\
    \ inv() const {\n        int a = x, b = MOD, ax = 1, bx = 0;\n        while (b)\
    \ {\n            int q = a/b, t = a%b;\n            a = b; b = t;\n          \
    \  t = ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a ==\
    \ 1);\n        if (ax < 0) ax += MOD;\n        return ax;\n    }\n    ModInt&\
    \ operator /= (ModInt m) { return (*this) *= m.inv(); }\n    ModInt operator /\
    \ (ModInt that) const { return ModInt(*this) /= that; }\n};\n\ntemplate<int MOD>\n\
    ModInt<MOD> power(ModInt<MOD> n, long long k) {\n    if (k == 0) return ModInt<MOD>\
    \ (1);\n    ModInt<MOD> res(1);\n    while (k > 0) {\n        if (k & 1) res =\
    \ res * n;\n        n = n * n;\n        k >>= 1;\n    }\n    return res;\n}\n\n\
    /* Example:\nconst int MOD = 1e9 + 7;\nusing modular = ModInt<MOD>;\n\nstd::ostream&\
    \ operator << (std::ostream& cout, const modular& m) {\n    cout << m.x;\n   \
    \ return cout;\n}\nstd::istream& operator >> (std::istream& cin, modular& m) {\n\
    \    cin >> m.x;\n    return cin;\n}\n*/\n#line 7 \"Math/tests/berlekamp_massey.test.cpp\"\
    \n\nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\n#line 1 \"Math/LinearRecurrence_BerlekampMassey.h\"\n// Berlekamp Massey\n\
    // Given sequence s0, ..., s(N-1)\n// Find sequence c1, ..., cd with minimum d\
    \ (d >= 0), such that:\n//   si = sum(s(i-j) * c(j), for j = 1..d)\n//\n// Tutorial:\
    \ https://mzhang2021.github.io/cp-blog/berlekamp-massey/\n// If we have the linear\
    \ recurrence, we can compute s(n):\n// - O(n*d) naively\n// - O(d^3 * log(n))\
    \ with matrix exponentiation\n// - O(d*log(d)*log(k)) with generating function\
    \ (tutorial above)\n//\n// Solving problems where we need to compute f(n) mod\
    \ P (e.g. VOJ SELFDIV)\n// - Guess that f is a linear recurrence\n// - Compute\
    \ f(n) for small n\n// - Run Berlekamp Massey to find C (we must have 2*|C| <\
    \ n, otherwise it's wrong)\n//\n// Note:\n// - should be calculated in prime modulo\
    \ (i.e. T=modint), as it\n//   requires modular inverse\n// - when modulo is not\
    \ prime --> https://github.com/zimpha/algorithmic-library/blob/master/cpp/mathematics/linear-recurrence.cc\n\
    //   but this comment says it doesn't work on some problem: https://codeforces.com/blog/entry/61306?#comment-454682\n\
    //\n// Tested:\n// - (BM) https://judge.yosupo.jp/problem/find_linear_recurrence\n\
    // - (BM + find_kth) https://oj.vnoi.info/problem/selfdiv\n// - (find_kth) https://oj.vnoi.info/problem/errichto_matexp_fibonacci\n\
    // - (find_kth) https://cses.fi/problemset/task/2181/\n\n// Returns c1, ..., cd\n\
    template<typename T>\nvector<T> berlekampMassey(vector<T> s) {\n    if (s.empty())\
    \ return {};\n\n    int n = s.size(), L = 0, m = 0; // m = i - f\n    vector<T>\
    \ C(n), D(n), oldC;\n    C[0] = D[0] = 1;\n    T df1 = 1;  // d(f+1)\n    for\
    \ (int i = 0; i < n; i++) {\n        ++m;\n        // check if C(i) == a(i)\n\
    \        // delta = s_i - sum( cj * s(i-j) ) = d(f+1)?\n        T delta = s[i];\n\
    \        for (int j = 1; j <= L; j++) {\n            delta += C[j] * s[i-j]; \
    \ // C(j) is already multiplied by -1\n        }\n        if (delta == 0) continue;\
    \  // C(i) is correct\n\n        // Update c = c + d\n        oldC = C;\n    \
    \    T coeff = delta * df1.inv();\n        for (int j = m; j < n; j++) {\n   \
    \         C[j] -= coeff * D[j - m];  // prepend D with m zeroes, multiply by coeff\
    \ and add to C\n        }\n        if (2*L > i) continue;\n        L = i + 1 -\
    \ L, D = oldC, df1 = delta, m = 0;\n    }\n    C.resize(L + 1);\n    C.erase(C.begin());\n\
    \    for (auto& x : C) x = -x;\n    return C;\n}\n\n// Helper function\ntemplate<typename\
    \ T>\nvector<T> mul(const vector<T> &a, const vector<T> &b, const vector<T>& c)\
    \ {\n    vector<T> ret(a.size() + b.size() - 1);\n    // ret = a * b\n    for\
    \ (int i=0; i<(int)a.size(); i++)\n        for (int j=0; j<(int)b.size(); j++)\n\
    \            ret[i+j] += a[i] * b[j];\n\n    int n = c.size();\n    // reducing\
    \ ret mod f(x)\n    for (int i=(int)ret.size()-1; i>=n; i--)\n        for (int\
    \ j=n-1; j>=0; j--)\n            ret[i-j-1] += ret[i] * c[j];\n    ret.resize(min((int)\
    \ ret.size(), n));\n    return ret;\n}\n\n// Find k-th element in linear recurrence:\
    \ O(d^2 * logn)\n// Need faster code? See https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\n\
    //   (but usually not needed since bottleneck is BerlekampMassey\n//\n// Params:\n\
    // - c: as returned by berlekampMassey\n// - s: s0, s1, ..., s(N-1)\n// Returns:\
    \ s(k)\ntemplate<typename T>\nT solve(const vector<T> &c, const vector<T> &s,\
    \ long long k) {\n    int n = (int) c.size();\n    assert(c.size() <= s.size());\n\
    \n    vector<T> a = n == 1 ? vector<T>{c[0]} : vector<T>{0, 1}, x{1};\n    for\
    \ (; k>0; k/=2) {\n        if (k % 2)\n            x = mul(x, a, c);  // mul(a,\
    \ b) computes a(x) * b(x) mod f(x)\n        a = mul(a, a, c);\n    }\n    x.resize(n);\n\
    \n    T ret = 0;\n    for (int i=0; i<n; i++)\n        ret += x[i] * s[i];\n \
    \   return ret;\n}\n#line 19 \"Math/tests/berlekamp_massey.test.cpp\"\n\n#define\
    \ REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x) ((int)(x).size())\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n; cin >>\
    \ n;\n    vector<modular> a(n);\n    REP(i,n) cin >> a[i];\n\n    vector<modular>\
    \ c = berlekampMassey<modular>(a);\n    cout << SZ(c) << endl;\n    for (auto\
    \ x : c) cout << x << ' ';\n    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../modulo_anta.h\"\
    \n\nusing modular = ModInt<998244353>;\nstd::ostream& operator << (std::ostream&\
    \ cout, const modular& m) {\n    cout << m.x;\n    return cout;\n}\nstd::istream&\
    \ operator >> (std::istream& cin, modular& m) {\n    cin >> m.x;\n    return cin;\n\
    }\n\n#include \"../LinearRecurrence_BerlekampMassey.h\"\n\n#define REP(i, a) for\
    \ (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x) ((int)(x).size())\n\n\
    int32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n; cin >>\
    \ n;\n    vector<modular> a(n);\n    REP(i,n) cin >> a[i];\n\n    vector<modular>\
    \ c = berlekampMassey<modular>(a);\n    cout << SZ(c) << endl;\n    for (auto\
    \ x : c) cout << x << ' ';\n    cout << endl;\n    return 0;\n}\n"
  dependsOn:
  - Math/modulo_anta.h
  - Math/LinearRecurrence_BerlekampMassey.h
  isVerificationFile: true
  path: Math/tests/berlekamp_massey.test.cpp
  requiredBy: []
  timestamp: '2022-01-11 20:18:36+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/berlekamp_massey.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/berlekamp_massey.test.cpp
- /verify/Math/tests/berlekamp_massey.test.cpp.html
title: Math/tests/berlekamp_massey.test.cpp
---
