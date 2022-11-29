---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Matrix.h
    title: Math/Matrix.h
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
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"Math/tests/matrix_inverse.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include <bits/stdc++.h>\n\
    #line 1 \"atcoder/modint.hpp\"\n\n\n\n#line 6 \"atcoder/modint.hpp\"\n#include\
    \ <type_traits>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"\
    atcoder/internal_math.hpp\"\n\n\n\n#line 5 \"atcoder/internal_math.hpp\"\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal\
    \ {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long\
    \ long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n\
    }\n\n// Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m < 2^31`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\n\n// @param n `0 <= n`\n// @param\
    \ m `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 7 \"atcoder/internal_type_traits.hpp\"\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 14 \"atcoder/modint.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct\
    \ static_modint_base : modint_base {};\n\ntemplate <class T> using is_modint =\
    \ std::is_base_of<modint_base, T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 5 \"Math/tests/matrix_inverse.test.cpp\"\
    \nusing namespace std;\nusing namespace atcoder;\n\n#line 1 \"Math/Matrix.h\"\n\
    // Matrix, which works for both double and int {{{\n// Copied partially from https://judge.yosupo.jp/submission/54653\n\
    //\n// Tested:\n// - (mat mul): https://judge.yosupo.jp/problem/matrix_product\n\
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
    \    // return upper triangle matrix\n    [[nodiscard]] Matrix gauss() const {\n\
    \        int c = 0;\n        Matrix mtr(*this);\n        vector<int> ws;\n   \
    \     ws.reserve(n_col);\n\n        for (int h = 0; h < n_row; h++) {\n      \
    \      if (c == n_col) break;\n            int piv = choose_pivot(mtr, h, c);\n\
    \            if (piv == -1) {\n                c++;\n                h--;\n  \
    \              continue;\n            }\n            if (h != piv) {\n       \
    \         for (int w = 0; w < n_col; w++) {\n                    swap(mtr[piv][w],\
    \ mtr[h][w]);\n                    mtr[piv][w] *= -1; // for determinant\n   \
    \             }\n            }\n            ws.clear();\n            for (int\
    \ w = c; w < n_col; w++) {\n                if (mtr[h][w] != 0) ws.emplace_back(w);\n\
    \            }\n            const T hcinv = T(1) / mtr[h][c];\n            for\
    \ (int hh = 0; hh < n_row; hh++) {\n                if (hh != h) {\n         \
    \           const T coeff = mtr[hh][c] * hcinv;\n                    for (auto\
    \ w : ws) mtr[hh][w] -= mtr[h][w] * coeff;\n                    mtr[hh][c] = 0;\n\
    \                }\n            }\n            c++;\n        }\n        return\
    \ mtr;\n    }\n\n    // For upper triangle matrix\n    T det() const {\n     \
    \   T ret = 1;\n        for (int i = 0; i < n_row; i++) {\n            ret *=\
    \ get(i, i);\n        }\n        return ret;\n    }\n\n    // return rank of inverse\
    \ matrix. If rank < n -> not invertible\n    int inverse() {\n        assert(n_row\
    \ == n_col);\n        vector<vector<T>> ret = identity(n_row), tmp = *this;\n\
    \        int rank = 0;\n\n        for (int i = 0; i < n_row; i++) {\n        \
    \    int ti = i;\n            while (ti < n_row && tmp[ti][i] == 0) ++ti;\n  \
    \          if (ti == n_row) continue;\n            else ++rank;\n\n          \
    \  ret[i].swap(ret[ti]);\n            tmp[i].swap(tmp[ti]);\n\n            T inv\
    \ = T(1) / tmp[i][i];\n            for (int j = 0; j < n_col; j++) ret[i][j] *=\
    \ inv;\n            for (int j = i+1; j < n_col; j++) tmp[i][j] *= inv;\n\n  \
    \          for (int h = 0; h < n_row; h++) {\n                if (i == h) continue;\n\
    \                const T c = -tmp[h][i];\n                for (int j = 0; j <\
    \ n_col; j++) ret[h][j] += ret[i][j] * c;\n                for (int j = i+1; j\
    \ < n_col; j++) tmp[h][j] += tmp[i][j] * c;\n            }\n        }\n\n    \
    \    *this = ret;\n        return rank;\n    }\n\n    // sum of [r1, r2) x [c1,\
    \ c2)\n    T submatrix_sum(int r1, int c1, int r2, int c2) {\n        T res {0};\n\
    \        for (int r = r1; r < r2; ++r) {\n            res += std::accumulate(\n\
    \                    x.begin() + r * n_col + c1,\n                    x.begin()\
    \ + r * n_col + c2,\n                    T{0});\n        }\n        return res;\n\
    \    }\n};\ntemplate<typename T>\nostream& operator << (ostream& cout, const Matrix<T>&\
    \ m) {\n    cout << m.n_row << ' ' << m.n_col << endl;\n    cout << m.x << endl;\n\
    \    return cout;\n}\n// }}}\n#line 1 \"buffered_reader.h\"\n// Buffered reader\
    \ {{{\nnamespace IO {\n    const int BUFSIZE = 1<<14;\n    char buf[BUFSIZE +\
    \ 1], *inp = buf;\n\n    bool reacheof;\n    char get_char() {\n        if (!*inp\
    \ && !reacheof) {\n            memset(buf, 0, sizeof buf);\n            int tmp\
    \ = fread(buf, 1, BUFSIZE, stdin);\n            if (tmp != BUFSIZE) reacheof =\
    \ true;\n            inp = buf;\n        }\n        return *inp++;\n    }\n  \
    \  template<typename T>\n    T get() {\n        int neg = 0;\n        T res =\
    \ 0;\n        char c = get_char();\n        while (!std::isdigit(c) && c != '-'\
    \ && c != '+') c = get_char();\n        if (c == '+') { neg = 0; }\n        else\
    \ if (c == '-') { neg = 1; }\n        else res = c - '0';\n\n        c = get_char();\n\
    \        while (std::isdigit(c)) {\n            res = res * 10 + (c - '0');\n\
    \            c = get_char();\n        }\n        return neg ? -res : res;\n  \
    \  }\n};\n// }}}\n#line 10 \"Math/tests/matrix_inverse.test.cpp\"\n\n#define REP(i,\
    \ a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main() {\n    ios::sync_with_stdio(0);\
    \ cin.tie(0);\n    int n = IO::get<int>();\n    Matrix<modint998244353> a(n, n);\n\
    \    REP(i,n) REP(j,n) {\n        int x = IO::get<int>();\n        a[i][j] = x;\n\
    \    }\n    int rank = a.inverse();\n    if (rank < n) cout << -1 << '\\n';\n\
    \    else {\n        REP(i,n) {\n            REP(j,n) cout << a[i][j].val() <<\
    \ ' ';\n            cout << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"../../atcoder/modint.hpp\"\nusing namespace std;\n\
    using namespace atcoder;\n\n#include \"../Matrix.h\"\n#include \"../../buffered_reader.h\"\
    \n\n#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)\n\nint32_t main()\
    \ {\n    ios::sync_with_stdio(0); cin.tie(0);\n    int n = IO::get<int>();\n \
    \   Matrix<modint998244353> a(n, n);\n    REP(i,n) REP(j,n) {\n        int x =\
    \ IO::get<int>();\n        a[i][j] = x;\n    }\n    int rank = a.inverse();\n\
    \    if (rank < n) cout << -1 << '\\n';\n    else {\n        REP(i,n) {\n    \
    \        REP(j,n) cout << a[i][j].val() << ' ';\n            cout << '\\n';\n\
    \        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - Math/Matrix.h
  - buffered_reader.h
  isVerificationFile: true
  path: Math/tests/matrix_inverse.test.cpp
  requiredBy: []
  timestamp: '2022-11-29 21:44:39+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/tests/matrix_inverse.test.cpp
layout: document
redirect_from:
- /verify/Math/tests/matrix_inverse.test.cpp
- /verify/Math/tests/matrix_inverse.test.cpp.html
title: Math/tests/matrix_inverse.test.cpp
---
