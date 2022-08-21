---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Polynomial/FormerPowerSeries.h
    title: Math/Polynomial/FormerPowerSeries.h
  - icon: ':question:'
    path: Math/Polynomial/NTT.h
    title: Math/Polynomial/NTT.h
  - icon: ':question:'
    path: Math/modint.h
    title: Math/modint.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"Math/tests/formal_power_series_multiply.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include <bits/stdc++.h>\n\
    \n#line 1 \"Math/modint.h\"\n// ModInt {{{\ntemplate<int MD> struct ModInt {\n\
    \    using ll = long long;\n    int x;\n\n    constexpr ModInt() : x(0) {}\n \
    \   constexpr ModInt(ll v) { _set(v % MD + MD); }\n    constexpr static int mod()\
    \ { return MD; }\n    constexpr explicit operator bool() const { return x != 0;\
    \ }\n\n    constexpr ModInt operator + (const ModInt& a) const {\n        return\
    \ ModInt()._set((ll) x + a.x);\n    }\n    constexpr ModInt operator - (const\
    \ ModInt& a) const {\n        return ModInt()._set((ll) x - a.x + MD);\n    }\n\
    \    constexpr ModInt operator * (const ModInt& a) const {\n        return ModInt()._set((ll)\
    \ x * a.x % MD);\n    }\n    constexpr ModInt operator / (const ModInt& a) const\
    \ {\n        return ModInt()._set((ll) x * a.inv().x % MD);\n    }\n    constexpr\
    \ ModInt operator - () const {\n        return ModInt()._set(MD - x);\n    }\n\
    \n    constexpr ModInt& operator += (const ModInt& a) { return *this = *this +\
    \ a; }\n    constexpr ModInt& operator -= (const ModInt& a) { return *this = *this\
    \ - a; }\n    constexpr ModInt& operator *= (const ModInt& a) { return *this =\
    \ *this * a; }\n    constexpr ModInt& operator /= (const ModInt& a) { return *this\
    \ = *this / a; }\n\n    friend constexpr ModInt operator + (ll a, const ModInt&\
    \ b) {\n        return ModInt()._set(a % MD + b.x);\n    }\n    friend constexpr\
    \ ModInt operator - (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD - b.x + MD);\n    }\n    friend constexpr ModInt operator * (ll a, const\
    \ ModInt& b) {\n        return ModInt()._set(a % MD * b.x % MD);\n    }\n    friend\
    \ constexpr ModInt operator / (ll a, const ModInt& b) {\n        return ModInt()._set(a\
    \ % MD * b.inv().x % MD);\n    }\n\n    constexpr bool operator == (const ModInt&\
    \ a) const { return x == a.x; }\n    constexpr bool operator != (const ModInt&\
    \ a) const { return x != a.x; }\n\n    friend std::istream& operator >> (std::istream&\
    \ is, ModInt& x) {\n        ll val; is >> val;\n        x = ModInt(val);\n   \
    \     return is;\n    }\n    constexpr friend std::ostream& operator << (std::ostream&\
    \ os, const ModInt& x) {\n        return os << x.x;\n    }\n\n    constexpr ModInt\
    \ pow(ll k) const {\n        ModInt ans = 1, tmp = x;\n        while (k) {\n \
    \           if (k & 1) ans *= tmp;\n            tmp *= tmp;\n            k >>=\
    \ 1;\n        }\n        return ans;\n    }\n\n    constexpr ModInt inv() const\
    \ {\n        if (x < 1000111) {\n            _precalc(1000111);\n            return\
    \ invs[x];\n        }\n        int a = x, b = MD, ax = 1, bx = 0;\n        while\
    \ (b) {\n            int q = a/b, t = a%b;\n            a = b; b = t;\n      \
    \      t = ax - bx*q;\n            ax = bx; bx = t;\n        }\n        assert(a\
    \ == 1);\n        if (ax < 0) ax += MD;\n        return ax;\n    }\n\n    static\
    \ std::vector<ModInt> factorials, inv_factorials, invs;\n    constexpr static\
    \ void _precalc(int n) {\n        if (factorials.empty()) {\n            factorials\
    \ = {1};\n            inv_factorials = {1};\n            invs = {0};\n       \
    \ }\n        if (n > MD) n = MD;\n        int old_sz = factorials.size();\n  \
    \      if (n <= old_sz) return;\n\n        factorials.resize(n);\n        inv_factorials.resize(n);\n\
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
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n// }}}\n#line 1 \"Math/Polynomial/FormerPowerSeries.h\"\
    \n// Formal Power Series {{{\n//\n// Notes:\n// - T must be ModInt\n\n#line 1\
    \ \"Math/Polynomial/NTT.h\"\n// NTT {{{\n//\n// Faster than NTT_chemthan.h\n//\n\
    // Usage:\n// auto c = multiply(a, b);\n// where a and b are vector<ModInt<ANY_MOD>>\n\
    // (If mod is NOT NTT_PRIMES, it does 3 NTT and combine result)\n\nconstexpr int\
    \ NTT_PRIMES[] = {998244353, 167772161, 469762049};\n\n// assumptions:\n// - |a|\
    \ is power of 2\n// - mint::mod() is a valid NTT primes (2^k * m + 1)\ntemplate<typename\
    \ mint> void ntt(std::vector<mint>& a, bool is_inverse) {\n    int n = a.size();\n\
    \    if (n == 1) return;\n\n    static const int mod = mint::mod();\n    static\
    \ const mint root = mint::get_primitive_root();\n    assert(__builtin_popcount(n)\
    \ == 1 && (mod - 1) % n == 0);\n\n    static std::vector<mint> w{1}, iw{1};\n\
    \    for (int m = w.size(); m < n / 2; m *= 2) {\n        mint dw = root.pow((mod\
    \ - 1) / (4 * m));\n        mint dwinv = dw.inv();\n        w.resize(m * 2);\n\
    \        iw.resize(m * 2);\n        for (int i = 0; i < m; ++i) {\n          \
    \  w[m + i] = w[i] * dw;\n            iw[m + i] = iw[i] * dwinv;\n        }\n\
    \    }\n\n    if (!is_inverse) {\n        for (int m = n; m >>= 1; ) {\n     \
    \       for (int s = 0, k = 0; s < n; s += 2 * m, ++k) {\n                for\
    \ (int i = s; i < s + m; ++i) {\n                    mint x = a[i], y = a[i +\
    \ m] * w[k];\n                    a[i] = x + y;\n                    a[i + m]\
    \ = x - y;\n                }\n            }\n        }\n    } else {\n      \
    \  for (int m = 1; m < n; m *= 2) {\n            for (int s = 0, k = 0; s < n;\
    \ s += 2 * m, ++k) {\n                for (int i = s; i < s + m; ++i) {\n    \
    \                mint x = a[i], y = a[i + m];\n                    a[i] = x +\
    \ y;\n                    a[i + m] = (x - y) * iw[k];\n                }\n   \
    \         }\n        }\n        int n_inv = mint(n).inv().x;\n        for (auto&\
    \ v : a) v *= n_inv;\n    }\n}\n\ntemplate<typename mint>\nstd::vector<mint> ntt_multiply(int\
    \ sz, std::vector<mint> a, std::vector<mint> b) {\n    a.resize(sz);\n    b.resize(sz);\n\
    \    if (a == b) { // optimization for squaring polynomial\n        ntt(a, false);\n\
    \        b = a;\n    } else {\n        ntt(a, false);\n        ntt(b, false);\n\
    \    }\n    for (int i = 0; i < sz; ++i) a[i] *= b[i];\n    ntt(a, true);\n  \
    \  return a;\n}\n\ntemplate<int MOD, typename mint>\nstd::vector<ModInt<MOD>>\
    \ convert_mint_and_multiply(\n        int sz,\n        const std::vector<mint>&\
    \ a,\n        const std::vector<mint>& b) {\n    using mint2 = ModInt<MOD>;\n\n\
    \    std::vector<mint2> a2(a.size()), b2(b.size());\n    for (size_t i = 0; i\
    \ < a.size(); ++i) {\n        a2[i] = mint2(a[i].x);\n    }\n    for (size_t i\
    \ = 0; i < b.size(); ++i) {\n        b2[i] = mint2(b[i].x);\n    }\n    return\
    \ ntt_multiply(sz, a2, b2);\n}\n\nlong long combine(int r0, int r1, int r2, int\
    \ mod) {\n    using mint2 = ModInt<NTT_PRIMES[2]>;\n    static const long long\
    \ m01 = 1LL * NTT_PRIMES[0] * NTT_PRIMES[1];\n    static const long long m0_inv_m1\
    \ = ModInt<NTT_PRIMES[1]>(NTT_PRIMES[0]).inv().x;\n    static const long long\
    \ m01_inv_m2 = mint2(m01).inv().x;\n\n    int v1 = (m0_inv_m1 * (r1 + NTT_PRIMES[1]\
    \ - r0)) % NTT_PRIMES[1];\n    auto v2 = (mint2(r2) - r0 - mint2(NTT_PRIMES[0])\
    \ * v1) * m01_inv_m2;\n    return (r0 + 1LL * NTT_PRIMES[0] * v1 + m01 % mod *\
    \ v2.x) % mod;\n}\n\ntemplate<typename mint>\nstd::vector<mint> multiply(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\n    if (a.empty() || b.empty())\
    \ return {};\n    int sz = 1, sz_a = a.size(), sz_b = b.size();\n    while (sz\
    \ < sz_a + sz_b) sz <<= 1;\n    if (sz <= 16) {\n        std::vector<mint> res(sz_a\
    \ + sz_b - 1);\n        for (int i = 0; i < sz_a; ++i) {\n            for (int\
    \ j = 0; j < sz_b; ++j) {\n                res[i + j] += a[i] * b[j];\n      \
    \      }\n        }\n        return res;\n    }\n\n    int mod = mint::mod();\n\
    \    std::vector<mint> res;\n    if (std::find(std::begin(NTT_PRIMES), std::end(NTT_PRIMES),\
    \ mod) != std::end(NTT_PRIMES)) {\n        res = ntt_multiply(sz, a, b);\n   \
    \ } else {\n        auto c0 = convert_mint_and_multiply<NTT_PRIMES[0], mint> (sz,\
    \ a, b);\n        auto c1 = convert_mint_and_multiply<NTT_PRIMES[1], mint> (sz,\
    \ a, b);\n        auto c2 = convert_mint_and_multiply<NTT_PRIMES[2], mint> (sz,\
    \ a, b);\n\n        res.resize(sz);\n        for (int i = 0; i < sz; ++i) {\n\
    \            res[i] = combine(c0[i].x, c1[i].x, c2[i].x, mod);\n        }\n  \
    \  }\n\n    res.resize(sz_a + sz_b - 1);\n    return res;\n}\n// }}}\n#line 7\
    \ \"Math/Polynomial/FormerPowerSeries.h\"\ntemplate<typename T> struct FormalPowerSeries\
    \ : std::vector<T> {\n    using std::vector<T>::vector;\n    using P = FormalPowerSeries;\n\
    \n    // Remove zeroes at the end\n    void shrink() {\n        while (!this->empty()\
    \ && this->back() == T(0)) this->pop_back();\n    }\n\n    // basic operators\
    \ with another FPS: + - * / % {{{\n    P operator + (const P& r) { return P(*this)\
    \ += r; }\n    P operator - (const P& r) { return P(*this) -= r; }\n    P operator\
    \ * (const P& r) { return P(*this) *= r; }\n\n    P& operator += (const P& r)\
    \ {\n        if (r.size() > this->size()) this->resize(r.size());\n        for\
    \ (int i = 0; i < static_cast<int> (r.size()); ++i)\n            (*this)[i] +=\
    \ r[i];\n        shrink();\n        return *this;\n    }\n    P& operator -= (const\
    \ P& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n    \
    \    for (int i = 0; i < static_cast<int> (r.size()); ++i)\n            (*this)[i]\
    \ -= r[i];\n        shrink();\n        return *this;\n    }\n    P& operator *=\
    \ (const P& r) {\n        if (this->empty() || r.empty()) {\n            this->clear();\n\
    \        } else {\n            auto res = multiply(*this, r);\n            *this\
    \ = P(res.begin(), res.end());\n        }\n        return *this;\n    }\n    //\
    \ }}}\n};\n// }}}\n#line 7 \"Math/tests/formal_power_series_multiply.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\nusing mint =\
    \ ModInt<998244353>;\n\nint32_t main() {\n    int n, m; std::cin >> n >> m;\n\
    \    FormalPowerSeries<mint> a(n), b(m);\n    for (auto& val : a) std::cin >>\
    \ val;\n    for (auto& val : b) std::cin >> val;\n\n    auto c = a * b;\n    for\
    \ (auto val : c) std::cout << val << ' ';\n    std::cout << std::endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../modint.h\"\n#include \"../Polynomial/FormerPowerSeries.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\nusing mint =\
    \ ModInt<998244353>;\n\nint32_t main() {\n    int n, m; std::cin >> n >> m;\n\
    \    FormalPowerSeries<mint> a(n), b(m);\n    for (auto& val : a) std::cin >>\
    \ val;\n    for (auto& val : b) std::cin >> val;\n\n    auto c = a * b;\n    for\
    \ (auto val : c) std::cout << val << ' ';\n    std::cout << std::endl;\n    return\
    \ 0;\n}\n"
  dependsOn:
  - Math/modint.h
  - Math/Polynomial/FormerPowerSeries.h
  - Math/Polynomial/NTT.h
  isVerificationFile: true
  path: Math/tests/formal_power_series_multiply.test.cpp
  requiredBy: []
  timestamp: '2022-08-21 23:45:42+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/formal_power_series_multiply.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/formal_power_series_multiply.test.cpp
- /verify/Math/tests/formal_power_series_multiply.test.cpp.html
title: Math/tests/formal_power_series_multiply.test.cpp
---
