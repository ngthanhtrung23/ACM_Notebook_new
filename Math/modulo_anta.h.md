---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: String/hash.h
    title: String/hash.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/hld_vertexsetpathcomposite.test.cpp
    title: DataStructure/test/hld_vertexsetpathcomposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
    title: DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
    title: DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
    title: DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/splay_tree.test.cpp
    title: DataStructure/test/splay_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_1_b_modulo_pow.test.cpp
    title: Math/tests/aizu_ntl_1_b_modulo_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/berlekamp_massey.test.cpp
    title: Math/tests/berlekamp_massey.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/gym/101383
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"Math/modulo_anta.h\"\n// Modified from anta's code\n// Not\
    \ tested with MOD > 10^9 + 7.\n// Slow?\n//\n// Tested:\n// - https://codeforces.com/gym/101383\
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
    \    cin >> m.x;\n    return cin;\n}\n*/\n"
  code: "// Modified from anta's code\n// Not tested with MOD > 10^9 + 7.\n// Slow?\n\
    //\n// Tested:\n// - https://codeforces.com/gym/101383 - F (MOD = 1e9+7, +, *)\n\
    \n// ??? somehow this is 2.5x slower on https://judge.yosupo.jp/problem/matrix_product\n\
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
    \    cin >> m.x;\n    return cin;\n}\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modulo_anta.h
  requiredBy:
  - String/hash.h
  timestamp: '2022-01-11 20:18:36+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/aizu_ntl_1_b_modulo_pow.test.cpp
  - Math/tests/berlekamp_massey.test.cpp
  - DataStructure/test/hld_vertexsetpathcomposite.test.cpp
  - DataStructure/test/link_cut_tree_vertexsetpathcomposite.test.cpp
  - DataStructure/test/segment_tree_pointsetrangecomposite.test.cpp
  - DataStructure/test/splay_tree.test.cpp
  - DataStructure/test/segment_tree_rangeaffinerangesum.test.cpp
documentation_of: Math/modulo_anta.h
layout: document
redirect_from:
- /library/Math/modulo_anta.h
- /library/Math/modulo_anta.h.html
title: Math/modulo_anta.h
---
