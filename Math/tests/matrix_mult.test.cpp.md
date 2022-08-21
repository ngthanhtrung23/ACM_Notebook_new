---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Matrix.h
    title: Math/Matrix.h
  - icon: ':heavy_check_mark:'
    path: Math/modint.h
    title: Math/modint.h
  - icon: ':heavy_check_mark:'
    path: buffered_reader.h
    title: buffered_reader.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"Math/tests/matrix_mult.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"Math/Matrix.h\"\
    \n// Matrix, which works for both double and int {{{\n// Copied partially from\
    \ https://judge.yosupo.jp/submission/54653\n//\n// Tested:\n// - (mat mul): https://judge.yosupo.jp/problem/matrix_product\n\
    // - (mat pow): https://oj.vnoi.info/problem/icpc21_mt_k\n// - (mat pow): https://oj.vnoi.info/problem/icpc21_mb_h\n\
    // - (gauss): https://oj.vnoi.info/problem/vmrook\n// - (inverse): https://oj.vnoi.info/problem/dtl_lsr\n\
    // - (inverse): https://judge.yosupo.jp/problem/inverse_matrix\n// - (det): https://judge.yosupo.jp/problem/matrix_det\n\
    \ntemplate<typename T>\nstruct Matrix {\n    int n_row, n_col;\n    vector<T>\
    \ x;\n\n    // accessors\n    typename vector<T>::iterator operator [] (int r)\
    \ {\n        return x.begin() + r * n_col;\n    }\n    inline T get(int i, int\
    \ j) const { return x[i * n_col + j]; }\n\n    // constructors\n    Matrix() =\
    \ default;\n    Matrix(int _n_row, int _n_col) : n_row(_n_row), n_col(_n_col),\
    \ x(n_row * n_col) {}\n    Matrix(const vector<vector<T>>& d) : n_row(d.size()),\
    \ n_col(d.size() ? d[0].size() : 0) {\n        for (auto& row : d) std::copy(row.begin(),\
    \ row.end(), std::back_inserter(x));\n    }\n\n    // convert to 2d vec\n    vector<vector<T>>\
    \ vecvec() const {\n        vector<vector<T>> ret(n_row);\n        for (int i\
    \ = 0; i < n_row; i++) {\n            std::copy(x.begin() + i*n_col,\n       \
    \             x.begin() + (i+1)*n_col,\n                    std::back_inserter(ret[i]));\n\
    \        }\n        return ret;\n    }\n    operator vector<vector<T>>() const\
    \ { return vecvec(); }\n\n    static Matrix identity(int n) {\n        Matrix\
    \ res(n, n);\n        for (int i = 0; i < n; i++) {\n            res[i][i] = 1;\n\
    \        }\n        return res;\n    }\n\n    Matrix transpose() const {\n   \
    \     Matrix res(n_col, n_row);\n        for (int i = 0; i < n_row; i++) {\n \
    \           for (int j = 0; j < n_col; j++) {\n                res[j][i] = this->get(i,\
    \ j);\n            }\n        }\n        return res;\n    }\n\n    Matrix& operator\
    \ *= (const Matrix& r) { return *this = *this * r; }\n    Matrix operator * (const\
    \ Matrix& r) const {\n        assert(n_col == r.n_row);\n        Matrix res(n_row,\
    \ r.n_col);\n\n        for (int i = 0; i < n_row; i++) {\n            for (int\
    \ k = 0; k < n_col; k++) {\n                for (int j = 0; j < r.n_col; j++)\
    \ {\n                    res[i][j] += this->get(i, k) * r.get(k, j);\n       \
    \         }\n            }\n        }\n        return res;\n    }\n\n    Matrix\
    \ pow(long long n) const {\n        assert(n_row == n_col);\n        Matrix res\
    \ = identity(n_row);\n        if (n == 0) return res;\n\n        bool res_is_id\
    \ = true;\n        for (int i = 63 - __builtin_clzll(n); i >= 0; i--) {\n    \
    \        if (!res_is_id) res *= res;\n            if ((n >> i) & 1) res *= (*this),\
    \ res_is_id = false;\n        }\n        return res;\n    }\n\n    // Gauss\n\
    \    template <typename T2, typename std::enable_if<std::is_floating_point<T2>::value>::type\
    \ * = nullptr>\n    static int choose_pivot(const Matrix<T2> &mtr, int h, int\
    \ c) noexcept {\n        int piv = -1;\n        for (int j = h; j < mtr.n_row;\
    \ j++) {\n            if (mtr.get(j, c) and (piv < 0 or std::abs(mtr.get(j, c))\
    \ > std::abs(mtr.get(piv, c)))) piv = j;\n        }\n        return piv;\n   \
    \ }\n    template <typename T2, typename std::enable_if<!std::is_floating_point<T2>::value>::type\
    \ * = nullptr>\n    static int choose_pivot(const Matrix<T2> &mtr, int h, int\
    \ c) noexcept {\n        for (int j = h; j < mtr.n_row; j++) {\n            if\
    \ (mtr.get(j, c) != T(0)) return j;\n        }\n        return -1;\n    }\n\n\
    \    // return upper triangle matrix\n    Matrix gauss() const {\n        int\
    \ c = 0;\n        Matrix mtr(*this);\n        vector<int> ws;\n        ws.reserve(n_col);\n\
    \n        for (int h = 0; h < n_row; h++) {\n            if (c == n_col) break;\n\
    \            int piv = choose_pivot(mtr, h, c);\n            if (piv == -1) {\n\
    \                c++;\n                h--;\n                continue;\n     \
    \       }\n            if (h != piv) {\n                for (int w = 0; w < n_col;\
    \ w++) {\n                    swap(mtr[piv][w], mtr[h][w]);\n                \
    \    mtr[piv][w] *= -1; // for determinant\n                }\n            }\n\
    \            ws.clear();\n            for (int w = c; w < n_col; w++) {\n    \
    \            if (mtr[h][w] != 0) ws.emplace_back(w);\n            }\n        \
    \    const T hcinv = T(1) / mtr[h][c];\n            for (int hh = 0; hh < n_row;\
    \ hh++) {\n                if (hh != h) {\n                    const T coeff =\
    \ mtr[hh][c] * hcinv;\n                    for (auto w : ws) mtr[hh][w] -= mtr[h][w]\
    \ * coeff;\n                    mtr[hh][c] = 0;\n                }\n         \
    \   }\n            c++;\n        }\n        return mtr;\n    }\n\n    // For upper\
    \ triangle matrix\n    T det() const {\n        T ret = 1;\n        for (int i\
    \ = 0; i < n_row; i++) {\n            ret *= get(i, i);\n        }\n        return\
    \ ret;\n    }\n\n    // return rank of inverse matrix. If rank < n -> not invertible\n\
    \    int inverse() {\n        assert(n_row == n_col);\n        vector<vector<T>>\
    \ ret = identity(n_row), tmp = *this;\n        int rank = 0;\n\n        for (int\
    \ i = 0; i < n_row; i++) {\n            int ti = i;\n            while (ti < n_row\
    \ && tmp[ti][i] == 0) ++ti;\n            if (ti == n_row) continue;\n        \
    \    else ++rank;\n\n            ret[i].swap(ret[ti]);\n            tmp[i].swap(tmp[ti]);\n\
    \n            T inv = T(1) / tmp[i][i];\n            for (int j = 0; j < n_col;\
    \ j++) ret[i][j] *= inv;\n            for (int j = i+1; j < n_col; j++) tmp[i][j]\
    \ *= inv;\n\n            for (int h = 0; h < n_row; h++) {\n                if\
    \ (i == h) continue;\n                const T c = -tmp[h][i];\n              \
    \  for (int j = 0; j < n_col; j++) ret[h][j] += ret[i][j] * c;\n             \
    \   for (int j = i+1; j < n_col; j++) tmp[h][j] += tmp[i][j] * c;\n          \
    \  }\n        }\n\n        *this = ret;\n        return rank;\n    }\n};\n// }}}\n\
    #line 1 \"buffered_reader.h\"\n// Buffered reader {{{\nnamespace IO {\n    const\
    \ int BUFSIZE = 1<<14;\n    char buf[BUFSIZE + 1], *inp = buf;\n\n    bool reacheof;\n\
    \    char get_char() {\n        if (!*inp && !reacheof) {\n            memset(buf,\
    \ 0, sizeof buf);\n            int tmp = fread(buf, 1, BUFSIZE, stdin);\n    \
    \        if (tmp != BUFSIZE) reacheof = true;\n            inp = buf;\n      \
    \  }\n        return *inp++;\n    }\n    template<typename T>\n    T get() {\n\
    \        int neg = 0;\n        T res = 0;\n        char c = get_char();\n    \
    \    while (!std::isdigit(c) && c != '-' && c != '+') c = get_char();\n      \
    \  if (c == '+') { neg = 0; }\n        else if (c == '-') { neg = 1; }\n     \
    \   else res = c - '0';\n\n        c = get_char();\n        while (std::isdigit(c))\
    \ {\n            res = res * 10 + (c - '0');\n            c = get_char();\n  \
    \      }\n        return neg ? -res : res;\n    }\n};\n// }}}\n#line 1 \"Math/modint.h\"\
    \n// ModInt {{{\ntemplate<int MD> struct ModInt {\n    using ll = long long;\n\
    \    int x;\n\n    constexpr ModInt() : x(0) {}\n    constexpr ModInt(ll v) {\
    \ _set(v % MD + MD); }\n    constexpr explicit operator bool() const { return\
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
    \ i >= old_sz; --i) invs[i] = inv_factorials[i] * factorials[i-1];\n    }\n  \
    \  \nprivate:\n    // Internal, DO NOT USE.\n    // val must be in [0, 2*MD)\n\
    \    constexpr inline __attribute__((always_inline)) ModInt& _set(ll v) {\n  \
    \      x = v >= MD ? v - MD : v;\n        return *this;\n    }\n};\ntemplate <int\
    \ MD> std::vector<ModInt<MD>> ModInt<MD>::factorials = {1};\ntemplate <int MD>\
    \ std::vector<ModInt<MD>> ModInt<MD>::inv_factorials = {1};\ntemplate <int MD>\
    \ std::vector<ModInt<MD>> ModInt<MD>::invs = {0};\n// }}}\n#line 9 \"Math/tests/matrix_mult.test.cpp\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\nusing modular\
    \ = ModInt<998244353>;\n\nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n\
    \    int n = IO::get<int>();\n    int m = IO::get<int>();\n    int k = IO::get<int>();\n\
    \    Matrix<modular> a(n, m);\n    Matrix<modular> b(m, k);\n    for (auto& x\
    \ : a.x) x = IO::get<modular>();\n    for (auto& x : b.x) x = IO::get<modular>();\n\
    \n    auto c = a * b;\n    REP(i,n) {\n        REP(j,k) cout << c[i][j] << ' ';\n\
    \        cout << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../Matrix.h\"\n#include\
    \ \"../../buffered_reader.h\"\n#include \"../modint.h\"\n\n#define REP(i, a) for\
    \ (int i = 0, _##i = (a); i < _##i; ++i)\nusing modular = ModInt<998244353>;\n\
    \nint32_t main() {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n\
    \    int m = IO::get<int>();\n    int k = IO::get<int>();\n    Matrix<modular>\
    \ a(n, m);\n    Matrix<modular> b(m, k);\n    for (auto& x : a.x) x = IO::get<modular>();\n\
    \    for (auto& x : b.x) x = IO::get<modular>();\n\n    auto c = a * b;\n    REP(i,n)\
    \ {\n        REP(j,k) cout << c[i][j] << ' ';\n        cout << '\\n';\n    }\n\
    \    return 0;\n}\n"
  dependsOn:
  - Math/Matrix.h
  - buffered_reader.h
  - Math/modint.h
  isVerificationFile: true
  path: Math/tests/matrix_mult.test.cpp
  requiredBy: []
  timestamp: '2022-08-21 20:28:36+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/matrix_mult.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/matrix_mult.test.cpp
- /verify/Math/tests/matrix_mult.test.cpp.html
title: Math/tests/matrix_mult.test.cpp
---
