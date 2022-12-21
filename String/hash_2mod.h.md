---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/modint.h
    title: Math/modint.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/modint.h\"\n// ModInt {{{\ntemplate<int MD> struct\
    \ ModInt {\n    using ll = long long;\n    int x;\n\n    constexpr ModInt() :\
    \ x(0) {}\n    constexpr ModInt(ll v) { _set(v % MD + MD); }\n    constexpr static\
    \ int mod() { return MD; }\n    constexpr explicit operator bool() const { return\
    \ x != 0; }\n\n    constexpr ModInt operator + (const ModInt& a) const {\n   \
    \     return ModInt()._set((ll) x + a.x);\n    }\n    constexpr ModInt operator\
    \ - (const ModInt& a) const {\n        return ModInt()._set((ll) x - a.x + MD);\n\
    \    }\n    constexpr ModInt operator * (const ModInt& a) const {\n        return\
    \ ModInt()._set((ll) x * a.x % MD);\n    }\n    constexpr ModInt operator / (const\
    \ ModInt& a) const {\n        return ModInt()._set((ll) x * a.inv().x % MD);\n\
    \    }\n    constexpr ModInt operator - () const {\n        return ModInt()._set(MD\
    \ - x);\n    }\n\n    constexpr ModInt& operator += (const ModInt& a) { return\
    \ *this = *this + a; }\n    constexpr ModInt& operator -= (const ModInt& a) {\
    \ return *this = *this - a; }\n    constexpr ModInt& operator *= (const ModInt&\
    \ a) { return *this = *this * a; }\n    constexpr ModInt& operator /= (const ModInt&\
    \ a) { return *this = *this / a; }\n\n    friend constexpr ModInt operator + (ll\
    \ a, const ModInt& b) {\n        return ModInt()._set(a % MD + b.x);\n    }\n\
    \    friend constexpr ModInt operator - (ll a, const ModInt& b) {\n        return\
    \ ModInt()._set(a % MD - b.x + MD);\n    }\n    friend constexpr ModInt operator\
    \ * (ll a, const ModInt& b) {\n        return ModInt()._set(a % MD * b.x % MD);\n\
    \    }\n    friend constexpr ModInt operator / (ll a, const ModInt& b) {\n   \
    \     return ModInt()._set(a % MD * b.inv().x % MD);\n    }\n\n    constexpr bool\
    \ operator == (const ModInt& a) const { return x == a.x; }\n    constexpr bool\
    \ operator != (const ModInt& a) const { return x != a.x; }\n\n    friend std::istream&\
    \ operator >> (std::istream& is, ModInt& x) {\n        ll val; is >> val;\n  \
    \      x = ModInt(val);\n        return is;\n    }\n    constexpr friend std::ostream&\
    \ operator << (std::ostream& os, const ModInt& x) {\n        return os << x.x;\n\
    \    }\n\n    constexpr ModInt pow(ll k) const {\n        ModInt ans = 1, tmp\
    \ = x;\n        while (k) {\n            if (k & 1) ans *= tmp;\n            tmp\
    \ *= tmp;\n            k >>= 1;\n        }\n        return ans;\n    }\n\n   \
    \ constexpr ModInt inv() const {\n        if (x < 1000111) {\n            _precalc(1000111);\n\
    \            return invs[x];\n        }\n        int a = x, b = MD, ax = 1, bx\
    \ = 0;\n        while (b) {\n            int q = a/b, t = a%b;\n            a\
    \ = b; b = t;\n            t = ax - bx*q;\n            ax = bx; bx = t;\n    \
    \    }\n        assert(a == 1);\n        if (ax < 0) ax += MD;\n        return\
    \ ax;\n    }\n\n    static std::vector<ModInt> factorials, inv_factorials, invs;\n\
    \    constexpr static void _precalc(int n) {\n        if (factorials.empty())\
    \ {\n            factorials = {1};\n            inv_factorials = {1};\n      \
    \      invs = {0};\n        }\n        if (n > MD) n = MD;\n        int old_sz\
    \ = factorials.size();\n        if (n <= old_sz) return;\n\n        factorials.resize(n);\n\
    \        inv_factorials.resize(n);\n        invs.resize(n);\n\n        for (int\
    \ i = old_sz; i < n; ++i) factorials[i] = factorials[i-1] * i;\n        inv_factorials[n-1]\
    \ = factorials.back().pow(MD - 2);\n        for (int i = n - 2; i >= old_sz; --i)\
    \ inv_factorials[i] = inv_factorials[i+1] * (i+1);\n        for (int i = n-1;\
    \ i >= old_sz; --i) invs[i] = inv_factorials[i] * factorials[i-1];\n    }\n\n\
    \    static int get_primitive_root() {\n        static int primitive_root = 0;\n\
    \        if (!primitive_root) {\n            primitive_root = [&]() {\n      \
    \          std::set<int> fac;\n                int v = MD - 1;\n             \
    \   for (ll i = 2; i * i <= v; i++)\n                    while (v % i == 0) fac.insert(i),\
    \ v /= i;\n                if (v > 1) fac.insert(v);\n                for (int\
    \ g = 1; g < MD; g++) {\n                    bool ok = true;\n               \
    \     for (auto i : fac)\n                        if (ModInt(g).pow((MD - 1) /\
    \ i) == 1) {\n                            ok = false;\n                      \
    \      break;\n                        }\n                    if (ok) return g;\n\
    \                }\n                return -1;\n            }();\n        }\n\
    \        return primitive_root;\n    }\n    \nprivate:\n    // Internal, DO NOT\
    \ USE.\n    // val must be in [0, 2*MD)\n    constexpr inline __attribute__((always_inline))\
    \ ModInt& _set(ll v) {\n        x = v >= MD ? v - MD : v;\n        return *this;\n\
    \    }\n};\ntemplate <int MD> std::vector<ModInt<MD>> ModInt<MD>::factorials =\
    \ {1};\ntemplate <int MD> std::vector<ModInt<MD>> ModInt<MD>::inv_factorials =\
    \ {1};\ntemplate <int MD> std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n//\
    \ }}}\n#line 2 \"String/hash_2mod.h\"\n\n// NOT TESTED\nconst int MOD = 1e9 +\
    \ 7;\nusing modular = ModInt<MOD>;\n\nstruct Hash {\n    long long x;\n    modular\
    \ y;\n\n    Hash operator + (const Hash& a) const { return Hash{x + a.x, y + a.y};\
    \ }\n    Hash operator - (const Hash& a) const { return Hash{x - a.x, y - a.y};\
    \ }\n    Hash operator * (const Hash& a) const { return Hash{x * a.x, y * a.y};\
    \ }\n    Hash operator * (int k) const { return Hash{x*k, y*k}; }\n    Hash operator\
    \ / (int k) const { return Hash{x/k, y/k}; }\n\n    Hash& operator += (const Hash&\
    \ a) { return *this = *this + a; }\n    Hash& operator -= (const Hash& a) { return\
    \ *this = *this - a; }\n    Hash& operator *= (const Hash& a) { return *this =\
    \ *this * a; }\n    Hash& operator /= (const Hash& a) { return *this = *this /\
    \ a; }\n};\nbool operator == (const Hash& a, const Hash& b) {\n    return a.x\
    \ == b.x && a.y == b.y;\n}\nstd::ostream& operator << (std::ostream& out, const\
    \ Hash& h) {\n    out << '(' << h.x << \", \" << h.y << ')';\n    return out;\n\
    }\n"
  code: "#include \"../Math/modint.h\"\n\n// NOT TESTED\nconst int MOD = 1e9 + 7;\n\
    using modular = ModInt<MOD>;\n\nstruct Hash {\n    long long x;\n    modular y;\n\
    \n    Hash operator + (const Hash& a) const { return Hash{x + a.x, y + a.y}; }\n\
    \    Hash operator - (const Hash& a) const { return Hash{x - a.x, y - a.y}; }\n\
    \    Hash operator * (const Hash& a) const { return Hash{x * a.x, y * a.y}; }\n\
    \    Hash operator * (int k) const { return Hash{x*k, y*k}; }\n    Hash operator\
    \ / (int k) const { return Hash{x/k, y/k}; }\n\n    Hash& operator += (const Hash&\
    \ a) { return *this = *this + a; }\n    Hash& operator -= (const Hash& a) { return\
    \ *this = *this - a; }\n    Hash& operator *= (const Hash& a) { return *this =\
    \ *this * a; }\n    Hash& operator /= (const Hash& a) { return *this = *this /\
    \ a; }\n};\nbool operator == (const Hash& a, const Hash& b) {\n    return a.x\
    \ == b.x && a.y == b.y;\n}\nstd::ostream& operator << (std::ostream& out, const\
    \ Hash& h) {\n    out << '(' << h.x << \", \" << h.y << ')';\n    return out;\n\
    }\n"
  dependsOn:
  - Math/modint.h
  isVerificationFile: false
  path: String/hash_2mod.h
  requiredBy: []
  timestamp: '2022-10-04 22:56:32-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/hash_2mod.h
layout: document
redirect_from:
- /library/String/hash_2mod.h
- /library/String/hash_2mod.h.html
title: String/hash_2mod.h
---
