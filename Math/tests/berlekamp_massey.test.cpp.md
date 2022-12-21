---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/LinearRecurrence_BerlekampMassey.h
    title: Math/LinearRecurrence_BerlekampMassey.h
  - icon: ':heavy_check_mark:'
    path: Math/modint.h
    title: Math/modint.h
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
    using namespace std;\n\n#line 1 \"Math/modint.h\"\n// ModInt {{{\ntemplate<int\
    \ MD> struct ModInt {\n    using ll = long long;\n    int x;\n\n    constexpr\
    \ ModInt() : x(0) {}\n    constexpr ModInt(ll v) { _set(v % MD + MD); }\n    constexpr\
    \ static int mod() { return MD; }\n    constexpr explicit operator bool() const\
    \ { return x != 0; }\n\n    constexpr ModInt operator + (const ModInt& a) const\
    \ {\n        return ModInt()._set((ll) x + a.x);\n    }\n    constexpr ModInt\
    \ operator - (const ModInt& a) const {\n        return ModInt()._set((ll) x -\
    \ a.x + MD);\n    }\n    constexpr ModInt operator * (const ModInt& a) const {\n\
    \        return ModInt()._set((ll) x * a.x % MD);\n    }\n    constexpr ModInt\
    \ operator / (const ModInt& a) const {\n        return ModInt()._set((ll) x *\
    \ a.inv().x % MD);\n    }\n    constexpr ModInt operator - () const {\n      \
    \  return ModInt()._set(MD - x);\n    }\n\n    constexpr ModInt& operator += (const\
    \ ModInt& a) { return *this = *this + a; }\n    constexpr ModInt& operator -=\
    \ (const ModInt& a) { return *this = *this - a; }\n    constexpr ModInt& operator\
    \ *= (const ModInt& a) { return *this = *this * a; }\n    constexpr ModInt& operator\
    \ /= (const ModInt& a) { return *this = *this / a; }\n\n    friend constexpr ModInt\
    \ operator + (ll a, const ModInt& b) {\n        return ModInt()._set(a % MD +\
    \ b.x);\n    }\n    friend constexpr ModInt operator - (ll a, const ModInt& b)\
    \ {\n        return ModInt()._set(a % MD - b.x + MD);\n    }\n    friend constexpr\
    \ ModInt operator * (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD * b.x % MD);\n    }\n    friend constexpr ModInt operator / (ll a, const\
    \ ModInt& b) {\n        return ModInt()._set(a % MD * b.inv().x % MD);\n    }\n\
    \n    constexpr bool operator == (const ModInt& a) const { return x == a.x; }\n\
    \    constexpr bool operator != (const ModInt& a) const { return x != a.x; }\n\
    \n    friend std::istream& operator >> (std::istream& is, ModInt& x) {\n     \
    \   ll val; is >> val;\n        x = ModInt(val);\n        return is;\n    }\n\
    \    constexpr friend std::ostream& operator << (std::ostream& os, const ModInt&\
    \ x) {\n        return os << x.x;\n    }\n\n    constexpr ModInt pow(ll k) const\
    \ {\n        ModInt ans = 1, tmp = x;\n        while (k) {\n            if (k\
    \ & 1) ans *= tmp;\n            tmp *= tmp;\n            k >>= 1;\n        }\n\
    \        return ans;\n    }\n\n    constexpr ModInt inv() const {\n        if\
    \ (x < 1000111) {\n            _precalc(1000111);\n            return invs[x];\n\
    \        }\n        int a = x, b = MD, ax = 1, bx = 0;\n        while (b) {\n\
    \            int q = a/b, t = a%b;\n            a = b; b = t;\n            t =\
    \ ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a == 1);\n\
    \        if (ax < 0) ax += MD;\n        return ax;\n    }\n\n    static std::vector<ModInt>\
    \ factorials, inv_factorials, invs;\n    constexpr static void _precalc(int n)\
    \ {\n        if (factorials.empty()) {\n            factorials = {1};\n      \
    \      inv_factorials = {1};\n            invs = {0};\n        }\n        if (n\
    \ > MD) n = MD;\n        int old_sz = factorials.size();\n        if (n <= old_sz)\
    \ return;\n\n        factorials.resize(n);\n        inv_factorials.resize(n);\n\
    \        invs.resize(n);\n\n        for (int i = old_sz; i < n; ++i) factorials[i]\
    \ = factorials[i-1] * i;\n        inv_factorials[n-1] = factorials.back().pow(MD\
    \ - 2);\n        for (int i = n - 2; i >= old_sz; --i) inv_factorials[i] = inv_factorials[i+1]\
    \ * (i+1);\n        for (int i = n-1; i >= old_sz; --i) invs[i] = inv_factorials[i]\
    \ * factorials[i-1];\n    }\n\n    static int get_primitive_root() {\n       \
    \ static int primitive_root = 0;\n        if (!primitive_root) {\n           \
    \ primitive_root = [&]() {\n                std::set<int> fac;\n             \
    \   int v = MD - 1;\n                for (ll i = 2; i * i <= v; i++)\n       \
    \             while (v % i == 0) fac.insert(i), v /= i;\n                if (v\
    \ > 1) fac.insert(v);\n                for (int g = 1; g < MD; g++) {\n      \
    \              bool ok = true;\n                    for (auto i : fac)\n     \
    \                   if (ModInt(g).pow((MD - 1) / i) == 1) {\n                \
    \            ok = false;\n                            break;\n               \
    \         }\n                    if (ok) return g;\n                }\n      \
    \          return -1;\n            }();\n        }\n        return primitive_root;\n\
    \    }\n    \nprivate:\n    // Internal, DO NOT USE.\n    // val must be in [0,\
    \ 2*MD)\n    constexpr inline __attribute__((always_inline)) ModInt& _set(ll v)\
    \ {\n        x = v >= MD ? v - MD : v;\n        return *this;\n    }\n};\ntemplate\
    \ <int MD> std::vector<ModInt<MD>> ModInt<MD>::factorials = {1};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::inv_factorials = {1};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n// }}}\n#line 7 \"Math/tests/berlekamp_massey.test.cpp\"\
    \n\nusing modular = ModInt<998244353>;\n\n#line 1 \"Math/LinearRecurrence_BerlekampMassey.h\"\
    \n// Berlekamp Massey {{{\n// Given sequence s0, ..., s(N-1)\n// Find sequence\
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
    \   return ret;\n}\n// }}}\n#line 11 \"Math/tests/berlekamp_massey.test.cpp\"\n\
    \n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x)\
    \ ((int)(x).size())\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n; cin >> n;\n    vector<modular> a(n);\n    REP(i,n) cin >> a[i];\n\n\
    \    vector<modular> c = berlekampMassey<modular>(a);\n    cout << SZ(c) << endl;\n\
    \    for (auto x : c) cout << x << ' ';\n    cout << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../modint.h\"\
    \n\nusing modular = ModInt<998244353>;\n\n#include \"../LinearRecurrence_BerlekampMassey.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n#define SZ(x)\
    \ ((int)(x).size())\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n; cin >> n;\n    vector<modular> a(n);\n    REP(i,n) cin >> a[i];\n\n\
    \    vector<modular> c = berlekampMassey<modular>(a);\n    cout << SZ(c) << endl;\n\
    \    for (auto x : c) cout << x << ' ';\n    cout << endl;\n    return 0;\n}\n"
  dependsOn:
  - Math/modint.h
  - Math/LinearRecurrence_BerlekampMassey.h
  isVerificationFile: true
  path: Math/tests/berlekamp_massey.test.cpp
  requiredBy: []
  timestamp: '2022-11-13 20:48:45+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/berlekamp_massey.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/berlekamp_massey.test.cpp
- /verify/Math/tests/berlekamp_massey.test.cpp.html
title: Math/tests/berlekamp_massey.test.cpp
---
