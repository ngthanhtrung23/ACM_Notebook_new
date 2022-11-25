---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_2_a_bigint_add.test.cpp
    title: Math/tests/aizu_ntl_2_a_bigint_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_2_b_bigint_sub.test.cpp
    title: Math/tests/aizu_ntl_2_b_bigint_sub.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_2_c_bigint_mul.test.cpp
    title: Math/tests/aizu_ntl_2_c_bigint_mul.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_2_c_bigint_mul_karatsuba.test.cpp
    title: Math/tests/aizu_ntl_2_c_bigint_mul_karatsuba.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_2_d_bigint_div.test.cpp
    title: Math/tests/aizu_ntl_2_d_bigint_div.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_2_e_bigint_mod.test.cpp
    title: Math/tests/aizu_ntl_2_e_bigint_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Math/tests/aizu_ntl_2_f_bigint_mul_fft.test.cpp
    title: Math/tests/aizu_ntl_2_f_bigint_mul_fft.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://stackoverflow.com/questions/13166079/move-semantics-and-pass-by-rvalue-reference-in-overloaded-arithmetic
    - 'https://www.e-olymp.com/en/problems/1327:'
    - https://www.e-olymp.com/en/problems/1328
    - 'https://www.e-olymp.com/en/problems/266:'
    - 'https://www.e-olymp.com/en/problems/267:'
    - 'https://www.e-olymp.com/en/problems/271:'
    - 'https://www.e-olymp.com/en/problems/272:'
    - 'https://www.e-olymp.com/en/problems/313:'
    - 'https://www.e-olymp.com/en/problems/314:'
    - 'https://www.e-olymp.com/en/problems/317:'
  bundledCode: "#line 1 \"Math/bigint.h\"\n// BigInt {{{\n// NOTE:\n// This code contains\
    \ various bug fixes compared to the original version from\n// indy256 (github.com/indy256/codelibrary/blob/master/cpp/numbertheory/bigint-full.cpp),\n\
    // including:\n// - Fix overflow bug in mul_karatsuba.\n// - Fix overflow bug\
    \ in fft.\n// - Fix bug in initialization from long long.\n// - Optimized operators\
    \ + - *.\n//\n// Tested:\n// - https://www.e-olymp.com/en/problems/266: Comparison\n\
    // - https://www.e-olymp.com/en/problems/267: Subtraction\n// - https://www.e-olymp.com/en/problems/271:\
    \ Multiplication\n// - https://www.e-olymp.com/en/problems/272: Multiplication\n\
    // - https://www.e-olymp.com/en/problems/313: Addition\n// - https://www.e-olymp.com/en/problems/314:\
    \ Addition/Subtraction\n// - https://www.e-olymp.com/en/problems/317: Multiplication\
    \ (simple / karatsuba / fft)\n// - https://www.e-olymp.com/en/problems/1327: Multiplication\n\
    // - https://www.e-olymp.com/en/problems/1328\n// - VOJ BIGNUM: Addition, Subtraction,\
    \ Multiplication.\n// - SGU 111: sqrt\n// - SGU 193\n// - SPOJ MUL, VFMUL: Multiplication.\n\
    // - SPOJ FDIV, VFDIV: Division.\n// - SPOJ SQRROOT: sqrt\n\nconst int BASE_DIGITS\
    \ = 9;\nconst int BASE = 1000000000;\n\nstruct BigInt {\n    int sign;\n    vector<int>\
    \ a;\n\n    // -------------------- Constructors -------------------- \n    //\
    \ Default constructor.\n    BigInt() : sign(1) {}\n\n    // Constructor from long\
    \ long.\n    BigInt(long long v) {\n        *this = v;\n    }\n    BigInt& operator\
    \ = (long long v) {\n        sign = 1;\n        if (v < 0) {\n            sign\
    \ = -1;\n            v = -v;\n        }\n        a.clear();\n        for (; v\
    \ > 0; v = v / BASE)\n            a.push_back(v % BASE);\n        return *this;\n\
    \    }\n\n    // Initialize from string.\n    BigInt(const string& s) {\n    \
    \    read(s);\n    }\n\n    // -------------------- Input / Output --------------------\n\
    \    void read(const string& s) {\n        sign = 1;\n        a.clear();\n   \
    \     int pos = 0;\n        while (pos < (int) s.size() && (s[pos] == '-' || s[pos]\
    \ == '+')) {\n            if (s[pos] == '-')\n                sign = -sign;\n\
    \            ++pos;\n        }\n        for (int i = s.size() - 1; i >= pos; i\
    \ -= BASE_DIGITS) {\n            int x = 0;\n            for (int j = max(pos,\
    \ i - BASE_DIGITS + 1); j <= i; j++)\n                x = x * 10 + s[j] - '0';\n\
    \            a.push_back(x);\n        }\n        trim();\n    }\n    friend istream&\
    \ operator>>(istream &stream, BigInt &v) {\n        string s;\n        stream\
    \ >> s;\n        v.read(s);\n        return stream;\n    }\n\n    friend ostream&\
    \ operator<<(ostream &stream, const BigInt &v) {\n        if (v.sign == -1 &&\
    \ !v.isZero())\n            stream << '-';\n        stream << (v.a.empty() ? 0\
    \ : v.a.back());\n        for (int i = (int) v.a.size() - 2; i >= 0; --i)\n  \
    \          stream << setw(BASE_DIGITS) << setfill('0') << v.a[i];\n        return\
    \ stream;\n    }\n\n    // -------------------- Comparison --------------------\n\
    \    bool operator<(const BigInt &v) const {\n        if (sign != v.sign)\n  \
    \          return sign < v.sign;\n        if (a.size() != v.a.size())\n      \
    \      return a.size() * sign < v.a.size() * v.sign;\n        for (int i = ((int)\
    \ a.size()) - 1; i >= 0; i--)\n            if (a[i] != v.a[i])\n             \
    \   return a[i] * sign < v.a[i] * sign;\n        return false;\n    }\n\n    bool\
    \ operator>(const BigInt &v) const {\n        return v < *this;\n    }\n    bool\
    \ operator<=(const BigInt &v) const {\n        return !(v < *this);\n    }\n \
    \   bool operator>=(const BigInt &v) const {\n        return !(*this < v);\n \
    \   }\n    bool operator==(const BigInt &v) const {\n        return !(*this <\
    \ v) && !(v < *this);\n    }\n    bool operator!=(const BigInt &v) const {\n \
    \       return *this < v || v < *this;\n    }\n\n    // Returns:\n    // 0 if\
    \ |x| == |y|\n    // -1 if |x| < |y|\n    // 1 if |x| > |y|\n    friend int __compare_abs(const\
    \ BigInt& x, const BigInt& y) {\n        if (x.a.size() != y.a.size()) {\n   \
    \         return x.a.size() < y.a.size() ? -1 : 1;\n        }\n\n        for (int\
    \ i = ((int) x.a.size()) - 1; i >= 0; --i) {\n            if (x.a[i] != y.a[i])\
    \ {\n                return x.a[i] < y.a[i] ? -1 : 1;\n            }\n       \
    \ }\n        return 0;\n    }\n\n    // -------------------- Unary operator -\
    \ and operators +- --------------------\n    BigInt operator-() const {\n    \
    \    BigInt res = *this;\n        if (isZero()) return res;\n\n        res.sign\
    \ = -sign;\n        return res;\n    }\n\n    // Note: sign ignored.\n    void\
    \ __internal_add(const BigInt& v) {\n        if (a.size() < v.a.size()) {\n  \
    \          a.resize(v.a.size(), 0);\n        }\n        for (int i = 0, carry\
    \ = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {\n            if (i\
    \ == (int) a.size()) a.push_back(0);\n\n            a[i] += carry + (i < (int)\
    \ v.a.size() ? v.a[i] : 0);\n            carry = a[i] >= BASE;\n            if\
    \ (carry) a[i] -= BASE;\n        }\n    }\n\n    // Note: sign ignored.\n    void\
    \ __internal_sub(const BigInt& v) {\n        for (int i = 0, carry = 0; i < (int)\
    \ v.a.size() || carry; ++i) {\n            a[i] -= carry + (i < (int) v.a.size()\
    \ ? v.a[i] : 0);\n            carry = a[i] < 0;\n            if (carry) a[i] +=\
    \ BASE;\n        }\n        this->trim();\n    }\n\n    BigInt operator += (const\
    \ BigInt& v) {\n        if (sign == v.sign) {\n            __internal_add(v);\n\
    \        } else {\n            if (__compare_abs(*this, v) >= 0) {\n         \
    \       __internal_sub(v);\n            } else {\n                BigInt vv =\
    \ v;\n                swap(*this, vv);\n                __internal_sub(vv);\n\
    \            }\n        }\n        return *this;\n    }\n\n    BigInt operator\
    \ -= (const BigInt& v) {\n        if (sign == v.sign) {\n            if (__compare_abs(*this,\
    \ v) >= 0) {\n                __internal_sub(v);\n            } else {\n     \
    \           BigInt vv = v;\n                swap(*this, vv);\n               \
    \ __internal_sub(vv);\n                this->sign = -this->sign;\n           \
    \ }\n        } else {\n            __internal_add(v);\n        }\n        return\
    \ *this;\n    }\n\n    // Optimize operators + and - according to\n    // https://stackoverflow.com/questions/13166079/move-semantics-and-pass-by-rvalue-reference-in-overloaded-arithmetic\n\
    \    template< typename L, typename R >\n        typename std::enable_if<\n  \
    \          std::is_convertible<L, BigInt>::value &&\n            std::is_convertible<R,\
    \ BigInt>::value &&\n            std::is_lvalue_reference<R&&>::value,\n     \
    \       BigInt>::type friend operator + (L&& l, R&& r) {\n        BigInt result(std::forward<L>(l));\n\
    \        result += r;\n        return result;\n    }\n    template< typename L,\
    \ typename R >\n        typename std::enable_if<\n            std::is_convertible<L,\
    \ BigInt>::value &&\n            std::is_convertible<R, BigInt>::value &&\n  \
    \          std::is_rvalue_reference<R&&>::value,\n            BigInt>::type friend\
    \ operator + (L&& l, R&& r) {\n        BigInt result(std::move(r));\n        result\
    \ += l;\n        return result;\n    }\n\n    template< typename L, typename R\
    \ >\n        typename std::enable_if<\n            std::is_convertible<L, BigInt>::value\
    \ &&\n            std::is_convertible<R, BigInt>::value,\n            BigInt>::type\
    \ friend operator - (L&& l, R&& r) {\n        BigInt result(std::forward<L>(l));\n\
    \        result -= r;\n        return result;\n    }\n\n    // --------------------\
    \ Operators * / % --------------------\n    friend pair<BigInt, BigInt> divmod(const\
    \ BigInt& a1, const BigInt& b1) {\n        assert(b1 > 0);  // divmod not well-defined\
    \ for b < 0.\n\n        long long norm = BASE / (b1.a.back() + 1);\n        BigInt\
    \ a = a1.abs() * norm;\n        BigInt b = b1.abs() * norm;\n        BigInt q\
    \ = 0, r = 0;\n        q.a.resize(a.a.size());\n\n        for (int i = a.a.size()\
    \ - 1; i >= 0; i--) {\n            r *= BASE;\n            r += a.a[i];\n    \
    \        long long s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];\n    \
    \        long long s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];\n\
    \            long long d = ((long long) BASE * s1 + s2) / b.a.back();\n      \
    \      r -= b * d;\n            while (r < 0) {\n                r += b, --d;\n\
    \            }\n            q.a[i] = d;\n        }\n\n        q.sign = a1.sign\
    \ * b1.sign;\n        r.sign = a1.sign;\n        q.trim();\n        r.trim();\n\
    \        auto res = make_pair(q, r / norm);\n        if (res.second < 0) res.second\
    \ += b1;\n        return res;\n    }\n    BigInt operator/(const BigInt &v) const\
    \ {\n        if (v < 0) return divmod(-*this, -v).first;\n        return divmod(*this,\
    \ v).first;\n    }\n\n    BigInt operator%(const BigInt &v) const {\n        return\
    \ divmod(*this, v).second;\n    }\n\n    void operator/=(int v) {\n        assert(v\
    \ > 0);  // operator / not well-defined for v <= 0.\n        if (llabs(v) >= BASE)\
    \ {\n            *this /= BigInt(v);\n            return ;\n        }\n      \
    \  if (v < 0)\n            sign = -sign, v = -v;\n        for (int i = (int) a.size()\
    \ - 1, rem = 0; i >= 0; --i) {\n            long long cur = a[i] + rem * (long\
    \ long) BASE;\n            a[i] = (int) (cur / v);\n            rem = (int) (cur\
    \ % v);\n        }\n        trim();\n    }\n\n    BigInt operator/(int v) const\
    \ {\n        assert(v > 0);  // operator / not well-defined for v <= 0.\n\n  \
    \      if (llabs(v) >= BASE) {\n            return *this / BigInt(v);\n      \
    \  }\n        BigInt res = *this;\n        res /= v;\n        return res;\n  \
    \  }\n    void operator/=(const BigInt &v) {\n        *this = *this / v;\n   \
    \ }\n\n    long long operator%(long long v) const {\n        assert(v > 0);  //\
    \ operator / not well-defined for v <= 0.\n        assert(v < BASE);\n       \
    \ int m = 0;\n        for (int i = a.size() - 1; i >= 0; --i)\n            m =\
    \ (a[i] + m * (long long) BASE) % v;\n        return m * sign;\n    }\n\n    void\
    \ operator*=(int v) {\n        if (llabs(v) >= BASE) {\n            *this *= BigInt(v);\n\
    \            return ;\n        }\n        if (v < 0)\n            sign = -sign,\
    \ v = -v;\n        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i)\
    \ {\n            if (i == (int) a.size())\n                a.push_back(0);\n \
    \           long long cur = a[i] * (long long) v + carry;\n            carry =\
    \ (int) (cur / BASE);\n            a[i] = (int) (cur % BASE);\n            //asm(\"\
    divl %%ecx\" : \"=a\"(carry), \"=d\"(a[i]) : \"A\"(cur), \"c\"(base));\n     \
    \       /*\n             int val;\n             __asm {\n             lea esi,\
    \ cur\n             mov eax, [esi]\n             mov edx, [esi+4]\n          \
    \   mov ecx, base\n             div ecx\n             mov carry, eax\n       \
    \      mov val, edx;\n             }\n             a[i] = val;\n             */\n\
    \        }\n        trim();\n    }\n\n    BigInt operator*(int v) const {\n  \
    \      if (llabs(v) >= BASE) {\n            return *this * BigInt(v);\n      \
    \  }\n        BigInt res = *this;\n        res *= v;\n        return res;\n  \
    \  }\n\n    // Convert BASE 10^old --> 10^new.\n    static vector<int> convert_base(const\
    \ vector<int> &a, int old_digits, int new_digits) {\n        vector<long long>\
    \ p(max(old_digits, new_digits) + 1);\n        p[0] = 1;\n        for (int i =\
    \ 1; i < (int) p.size(); i++)\n            p[i] = p[i - 1] * 10;\n        vector<int>\
    \ res;\n        long long cur = 0;\n        int cur_digits = 0;\n        for (int\
    \ i = 0; i < (int) a.size(); i++) {\n            cur += a[i] * p[cur_digits];\n\
    \            cur_digits += old_digits;\n            while (cur_digits >= new_digits)\
    \ {\n                res.push_back((long long)(cur % p[new_digits]));\n      \
    \          cur /= p[new_digits];\n                cur_digits -= new_digits;\n\
    \            }\n        }\n        res.push_back((int) cur);\n        while (!res.empty()\
    \ && !res.back())\n            res.pop_back();\n        return res;\n    }\n\n\
    \    void fft(vector<complex<double> > &x, bool invert) const {\n        int n\
    \ = (int) x.size();\n\n        for (int i = 1, j = 0; i < n; ++i) {\n        \
    \    int bit = n >> 1;\n            for (; j >= bit; bit >>= 1)\n            \
    \    j -= bit;\n            j += bit;\n            if (i < j)\n              \
    \  swap(x[i], x[j]);\n        }\n\n        for (int len = 2; len <= n; len <<=\
    \ 1) {\n            double ang = 2 * 3.14159265358979323846 / len * (invert ?\
    \ -1 : 1);\n            complex<double> wlen(cos(ang), sin(ang));\n          \
    \  for (int i = 0; i < n; i += len) {\n                complex<double> w(1);\n\
    \                for (int j = 0; j < len / 2; ++j) {\n                    complex<double>\
    \ u = x[i + j];\n                    complex<double> v = x[i + j + len / 2] *\
    \ w;\n                    x[i + j] = u + v;\n                    x[i + j + len\
    \ / 2] = u - v;\n                    w *= wlen;\n                }\n         \
    \   }\n        }\n        if (invert)\n            for (int i = 0; i < n; ++i)\n\
    \                x[i] /= n;\n    }\n\n    void multiply_fft(const vector<int>\
    \ &x, const vector<int> &y, vector<int> &res) const {\n        vector<complex<double>\
    \ > fa(x.begin(), x.end());\n        vector<complex<double> > fb(y.begin(), y.end());\n\
    \        int n = 1;\n        while (n < (int) max(x.size(), y.size()))\n     \
    \       n <<= 1;\n        n <<= 1;\n        fa.resize(n);\n        fb.resize(n);\n\
    \n        fft(fa, false);\n        fft(fb, false);\n        for (int i = 0; i\
    \ < n; ++i)\n            fa[i] *= fb[i];\n        fft(fa, true);\n\n        res.resize(n);\n\
    \        long long carry = 0;\n        for (int i = 0; i < n; ++i) {\n       \
    \     long long t = (long long) (fa[i].real() + 0.5) + carry;\n            carry\
    \ = t / 1000;\n            res[i] = t % 1000;\n        }\n    }\n\n    BigInt\
    \ mul_simple(const BigInt &v) const {\n        BigInt res;\n        res.sign =\
    \ sign * v.sign;\n        res.a.resize(a.size() + v.a.size());\n        for (int\
    \ i = 0; i < (int) a.size(); ++i)\n            if (a[i])\n                for\
    \ (int j = 0, carry = 0; j < (int) v.a.size() || carry; ++j) {\n             \
    \       long long cur = res.a[i + j] + (long long) a[i] * (j < (int) v.a.size()\
    \ ? v.a[j] : 0) + carry;\n                    carry = (int) (cur / BASE);\n  \
    \                  res.a[i + j] = (int) (cur % BASE);\n                }\n   \
    \     res.trim();\n        return res;\n    }\n\n    typedef vector<long long>\
    \ vll;\n\n    static vll karatsubaMultiply(const vll &a, const vll &b) {\n   \
    \     int n = a.size();\n        vll res(n + n);\n        if (n <= 32) {\n   \
    \         for (int i = 0; i < n; i++)\n                for (int j = 0; j < n;\
    \ j++)\n                    res[i + j] += a[i] * b[j];\n            return res;\n\
    \        }\n\n        int k = n >> 1;\n        vll a1(a.begin(), a.begin() + k);\n\
    \        vll a2(a.begin() + k, a.end());\n        vll b1(b.begin(), b.begin()\
    \ + k);\n        vll b2(b.begin() + k, b.end());\n\n        vll a1b1 = karatsubaMultiply(a1,\
    \ b1);\n        vll a2b2 = karatsubaMultiply(a2, b2);\n\n        for (int i =\
    \ 0; i < k; i++)\n            a2[i] += a1[i];\n        for (int i = 0; i < k;\
    \ i++)\n            b2[i] += b1[i];\n\n        vll r = karatsubaMultiply(a2, b2);\n\
    \        for (int i = 0; i < (int) a1b1.size(); i++)\n            r[i] -= a1b1[i];\n\
    \        for (int i = 0; i < (int) a2b2.size(); i++)\n            r[i] -= a2b2[i];\n\
    \n        for (int i = 0; i < (int) r.size(); i++)\n            res[i + k] +=\
    \ r[i];\n        for (int i = 0; i < (int) a1b1.size(); i++)\n            res[i]\
    \ += a1b1[i];\n        for (int i = 0; i < (int) a2b2.size(); i++)\n         \
    \   res[i + n] += a2b2[i];\n        return res;\n    }\n\n    BigInt mul_karatsuba(const\
    \ BigInt &v) const {\n        vector<int> x6 = convert_base(this->a, BASE_DIGITS,\
    \ 6);\n        vector<int> y6 = convert_base(v.a, BASE_DIGITS, 6);\n        vll\
    \ x(x6.begin(), x6.end());\n        vll y(y6.begin(), y6.end());\n        while\
    \ (x.size() < y.size())\n            x.push_back(0);\n        while (y.size()\
    \ < x.size())\n            y.push_back(0);\n        while (x.size() & (x.size()\
    \ - 1))\n            x.push_back(0), y.push_back(0);\n        vll c = karatsubaMultiply(x,\
    \ y);\n        BigInt res;\n        res.sign = sign * v.sign;\n        long long\
    \ carry = 0;\n        for (int i = 0; i < (int) c.size(); i++) {\n           \
    \ long long cur = c[i] + carry;\n            res.a.push_back((int) (cur % 1000000));\n\
    \            carry = cur / 1000000;\n        }\n        res.a = convert_base(res.a,\
    \ 6, BASE_DIGITS);\n        res.trim();\n        return res;\n    }\n\n    void\
    \ operator*=(const BigInt &v) {\n        *this = *this * v;\n    }\n    BigInt\
    \ operator*(const BigInt &v) const {\n        if (a.size() * v.a.size() <= 1000111)\
    \ return mul_simple(v);\n        if (a.size() > 500111 || v.a.size() > 500111)\
    \ return mul_fft(v);\n        return mul_karatsuba(v);\n    }\n\n    BigInt mul_fft(const\
    \ BigInt& v) const {\n        BigInt res;\n        res.sign = sign * v.sign;\n\
    \        multiply_fft(convert_base(a, BASE_DIGITS, 3), convert_base(v.a, BASE_DIGITS,\
    \ 3), res.a);\n        res.a = convert_base(res.a, 3, BASE_DIGITS);\n        res.trim();\n\
    \        return res;\n    }\n\n    // -------------------- Misc --------------------\n\
    \    BigInt abs() const {\n        BigInt res = *this;\n        res.sign *= res.sign;\n\
    \        return res;\n    }\n    void trim() {\n        while (!a.empty() && !a.back())\n\
    \            a.pop_back();\n        if (a.empty())\n            sign = 1;\n  \
    \  }\n\n    bool isZero() const {\n        return a.empty() || (a.size() == 1\
    \ && !a[0]);\n    }\n\n    friend BigInt gcd(const BigInt &a, const BigInt &b)\
    \ {\n        return b.isZero() ? a : gcd(b, a % b);\n    }\n    friend BigInt\
    \ lcm(const BigInt &a, const BigInt &b) {\n        return a / gcd(a, b) * b;\n\
    \    }\n\n    friend BigInt sqrt(const BigInt &a1) {\n        BigInt a = a1;\n\
    \        while (a.a.empty() || a.a.size() % 2 == 1)\n            a.a.push_back(0);\n\
    \n        int n = a.a.size();\n\n        int firstDigit = (int) sqrt((double)\
    \ a.a[n - 1] * BASE + a.a[n - 2]);\n        int norm = BASE / (firstDigit + 1);\n\
    \        a *= norm;\n        a *= norm;\n        while (a.a.empty() || a.a.size()\
    \ % 2 == 1)\n            a.a.push_back(0);\n\n        BigInt r = (long long) a.a[n\
    \ - 1] * BASE + a.a[n - 2];\n        firstDigit = (int) sqrt((double) a.a[n -\
    \ 1] * BASE + a.a[n - 2]);\n        int q = firstDigit;\n        BigInt res;\n\
    \n        for(int j = n / 2 - 1; j >= 0; j--) {\n            for(; ; --q) {\n\
    \                BigInt r1 = (r - (res * 2 * BigInt(BASE) + q) * q) * BigInt(BASE)\
    \ * BigInt(BASE) + (j > 0 ? (long long) a.a[2 * j - 1] * BASE + a.a[2 * j - 2]\
    \ : 0);\n                if (r1 >= 0) {\n                    r = r1;\n       \
    \             break;\n                }\n            }\n            res *= BASE;\n\
    \            res += q;\n\n            if (j > 0) {\n                int d1 = res.a.size()\
    \ + 2 < r.a.size() ? r.a[res.a.size() + 2] : 0;\n                int d2 = res.a.size()\
    \ + 1 < r.a.size() ? r.a[res.a.size() + 1] : 0;\n                int d3 = res.a.size()\
    \ < r.a.size() ? r.a[res.a.size()] : 0;\n                q = ((long long) d1 *\
    \ BASE * BASE + (long long) d2 * BASE + d3) / (firstDigit * 2);\n            }\n\
    \        }\n\n        res.trim();\n        return res / norm;\n    }\n};\n// }}}\n"
  code: "// BigInt {{{\n// NOTE:\n// This code contains various bug fixes compared\
    \ to the original version from\n// indy256 (github.com/indy256/codelibrary/blob/master/cpp/numbertheory/bigint-full.cpp),\n\
    // including:\n// - Fix overflow bug in mul_karatsuba.\n// - Fix overflow bug\
    \ in fft.\n// - Fix bug in initialization from long long.\n// - Optimized operators\
    \ + - *.\n//\n// Tested:\n// - https://www.e-olymp.com/en/problems/266: Comparison\n\
    // - https://www.e-olymp.com/en/problems/267: Subtraction\n// - https://www.e-olymp.com/en/problems/271:\
    \ Multiplication\n// - https://www.e-olymp.com/en/problems/272: Multiplication\n\
    // - https://www.e-olymp.com/en/problems/313: Addition\n// - https://www.e-olymp.com/en/problems/314:\
    \ Addition/Subtraction\n// - https://www.e-olymp.com/en/problems/317: Multiplication\
    \ (simple / karatsuba / fft)\n// - https://www.e-olymp.com/en/problems/1327: Multiplication\n\
    // - https://www.e-olymp.com/en/problems/1328\n// - VOJ BIGNUM: Addition, Subtraction,\
    \ Multiplication.\n// - SGU 111: sqrt\n// - SGU 193\n// - SPOJ MUL, VFMUL: Multiplication.\n\
    // - SPOJ FDIV, VFDIV: Division.\n// - SPOJ SQRROOT: sqrt\n\nconst int BASE_DIGITS\
    \ = 9;\nconst int BASE = 1000000000;\n\nstruct BigInt {\n    int sign;\n    vector<int>\
    \ a;\n\n    // -------------------- Constructors -------------------- \n    //\
    \ Default constructor.\n    BigInt() : sign(1) {}\n\n    // Constructor from long\
    \ long.\n    BigInt(long long v) {\n        *this = v;\n    }\n    BigInt& operator\
    \ = (long long v) {\n        sign = 1;\n        if (v < 0) {\n            sign\
    \ = -1;\n            v = -v;\n        }\n        a.clear();\n        for (; v\
    \ > 0; v = v / BASE)\n            a.push_back(v % BASE);\n        return *this;\n\
    \    }\n\n    // Initialize from string.\n    BigInt(const string& s) {\n    \
    \    read(s);\n    }\n\n    // -------------------- Input / Output --------------------\n\
    \    void read(const string& s) {\n        sign = 1;\n        a.clear();\n   \
    \     int pos = 0;\n        while (pos < (int) s.size() && (s[pos] == '-' || s[pos]\
    \ == '+')) {\n            if (s[pos] == '-')\n                sign = -sign;\n\
    \            ++pos;\n        }\n        for (int i = s.size() - 1; i >= pos; i\
    \ -= BASE_DIGITS) {\n            int x = 0;\n            for (int j = max(pos,\
    \ i - BASE_DIGITS + 1); j <= i; j++)\n                x = x * 10 + s[j] - '0';\n\
    \            a.push_back(x);\n        }\n        trim();\n    }\n    friend istream&\
    \ operator>>(istream &stream, BigInt &v) {\n        string s;\n        stream\
    \ >> s;\n        v.read(s);\n        return stream;\n    }\n\n    friend ostream&\
    \ operator<<(ostream &stream, const BigInt &v) {\n        if (v.sign == -1 &&\
    \ !v.isZero())\n            stream << '-';\n        stream << (v.a.empty() ? 0\
    \ : v.a.back());\n        for (int i = (int) v.a.size() - 2; i >= 0; --i)\n  \
    \          stream << setw(BASE_DIGITS) << setfill('0') << v.a[i];\n        return\
    \ stream;\n    }\n\n    // -------------------- Comparison --------------------\n\
    \    bool operator<(const BigInt &v) const {\n        if (sign != v.sign)\n  \
    \          return sign < v.sign;\n        if (a.size() != v.a.size())\n      \
    \      return a.size() * sign < v.a.size() * v.sign;\n        for (int i = ((int)\
    \ a.size()) - 1; i >= 0; i--)\n            if (a[i] != v.a[i])\n             \
    \   return a[i] * sign < v.a[i] * sign;\n        return false;\n    }\n\n    bool\
    \ operator>(const BigInt &v) const {\n        return v < *this;\n    }\n    bool\
    \ operator<=(const BigInt &v) const {\n        return !(v < *this);\n    }\n \
    \   bool operator>=(const BigInt &v) const {\n        return !(*this < v);\n \
    \   }\n    bool operator==(const BigInt &v) const {\n        return !(*this <\
    \ v) && !(v < *this);\n    }\n    bool operator!=(const BigInt &v) const {\n \
    \       return *this < v || v < *this;\n    }\n\n    // Returns:\n    // 0 if\
    \ |x| == |y|\n    // -1 if |x| < |y|\n    // 1 if |x| > |y|\n    friend int __compare_abs(const\
    \ BigInt& x, const BigInt& y) {\n        if (x.a.size() != y.a.size()) {\n   \
    \         return x.a.size() < y.a.size() ? -1 : 1;\n        }\n\n        for (int\
    \ i = ((int) x.a.size()) - 1; i >= 0; --i) {\n            if (x.a[i] != y.a[i])\
    \ {\n                return x.a[i] < y.a[i] ? -1 : 1;\n            }\n       \
    \ }\n        return 0;\n    }\n\n    // -------------------- Unary operator -\
    \ and operators +- --------------------\n    BigInt operator-() const {\n    \
    \    BigInt res = *this;\n        if (isZero()) return res;\n\n        res.sign\
    \ = -sign;\n        return res;\n    }\n\n    // Note: sign ignored.\n    void\
    \ __internal_add(const BigInt& v) {\n        if (a.size() < v.a.size()) {\n  \
    \          a.resize(v.a.size(), 0);\n        }\n        for (int i = 0, carry\
    \ = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {\n            if (i\
    \ == (int) a.size()) a.push_back(0);\n\n            a[i] += carry + (i < (int)\
    \ v.a.size() ? v.a[i] : 0);\n            carry = a[i] >= BASE;\n            if\
    \ (carry) a[i] -= BASE;\n        }\n    }\n\n    // Note: sign ignored.\n    void\
    \ __internal_sub(const BigInt& v) {\n        for (int i = 0, carry = 0; i < (int)\
    \ v.a.size() || carry; ++i) {\n            a[i] -= carry + (i < (int) v.a.size()\
    \ ? v.a[i] : 0);\n            carry = a[i] < 0;\n            if (carry) a[i] +=\
    \ BASE;\n        }\n        this->trim();\n    }\n\n    BigInt operator += (const\
    \ BigInt& v) {\n        if (sign == v.sign) {\n            __internal_add(v);\n\
    \        } else {\n            if (__compare_abs(*this, v) >= 0) {\n         \
    \       __internal_sub(v);\n            } else {\n                BigInt vv =\
    \ v;\n                swap(*this, vv);\n                __internal_sub(vv);\n\
    \            }\n        }\n        return *this;\n    }\n\n    BigInt operator\
    \ -= (const BigInt& v) {\n        if (sign == v.sign) {\n            if (__compare_abs(*this,\
    \ v) >= 0) {\n                __internal_sub(v);\n            } else {\n     \
    \           BigInt vv = v;\n                swap(*this, vv);\n               \
    \ __internal_sub(vv);\n                this->sign = -this->sign;\n           \
    \ }\n        } else {\n            __internal_add(v);\n        }\n        return\
    \ *this;\n    }\n\n    // Optimize operators + and - according to\n    // https://stackoverflow.com/questions/13166079/move-semantics-and-pass-by-rvalue-reference-in-overloaded-arithmetic\n\
    \    template< typename L, typename R >\n        typename std::enable_if<\n  \
    \          std::is_convertible<L, BigInt>::value &&\n            std::is_convertible<R,\
    \ BigInt>::value &&\n            std::is_lvalue_reference<R&&>::value,\n     \
    \       BigInt>::type friend operator + (L&& l, R&& r) {\n        BigInt result(std::forward<L>(l));\n\
    \        result += r;\n        return result;\n    }\n    template< typename L,\
    \ typename R >\n        typename std::enable_if<\n            std::is_convertible<L,\
    \ BigInt>::value &&\n            std::is_convertible<R, BigInt>::value &&\n  \
    \          std::is_rvalue_reference<R&&>::value,\n            BigInt>::type friend\
    \ operator + (L&& l, R&& r) {\n        BigInt result(std::move(r));\n        result\
    \ += l;\n        return result;\n    }\n\n    template< typename L, typename R\
    \ >\n        typename std::enable_if<\n            std::is_convertible<L, BigInt>::value\
    \ &&\n            std::is_convertible<R, BigInt>::value,\n            BigInt>::type\
    \ friend operator - (L&& l, R&& r) {\n        BigInt result(std::forward<L>(l));\n\
    \        result -= r;\n        return result;\n    }\n\n    // --------------------\
    \ Operators * / % --------------------\n    friend pair<BigInt, BigInt> divmod(const\
    \ BigInt& a1, const BigInt& b1) {\n        assert(b1 > 0);  // divmod not well-defined\
    \ for b < 0.\n\n        long long norm = BASE / (b1.a.back() + 1);\n        BigInt\
    \ a = a1.abs() * norm;\n        BigInt b = b1.abs() * norm;\n        BigInt q\
    \ = 0, r = 0;\n        q.a.resize(a.a.size());\n\n        for (int i = a.a.size()\
    \ - 1; i >= 0; i--) {\n            r *= BASE;\n            r += a.a[i];\n    \
    \        long long s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];\n    \
    \        long long s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];\n\
    \            long long d = ((long long) BASE * s1 + s2) / b.a.back();\n      \
    \      r -= b * d;\n            while (r < 0) {\n                r += b, --d;\n\
    \            }\n            q.a[i] = d;\n        }\n\n        q.sign = a1.sign\
    \ * b1.sign;\n        r.sign = a1.sign;\n        q.trim();\n        r.trim();\n\
    \        auto res = make_pair(q, r / norm);\n        if (res.second < 0) res.second\
    \ += b1;\n        return res;\n    }\n    BigInt operator/(const BigInt &v) const\
    \ {\n        if (v < 0) return divmod(-*this, -v).first;\n        return divmod(*this,\
    \ v).first;\n    }\n\n    BigInt operator%(const BigInt &v) const {\n        return\
    \ divmod(*this, v).second;\n    }\n\n    void operator/=(int v) {\n        assert(v\
    \ > 0);  // operator / not well-defined for v <= 0.\n        if (llabs(v) >= BASE)\
    \ {\n            *this /= BigInt(v);\n            return ;\n        }\n      \
    \  if (v < 0)\n            sign = -sign, v = -v;\n        for (int i = (int) a.size()\
    \ - 1, rem = 0; i >= 0; --i) {\n            long long cur = a[i] + rem * (long\
    \ long) BASE;\n            a[i] = (int) (cur / v);\n            rem = (int) (cur\
    \ % v);\n        }\n        trim();\n    }\n\n    BigInt operator/(int v) const\
    \ {\n        assert(v > 0);  // operator / not well-defined for v <= 0.\n\n  \
    \      if (llabs(v) >= BASE) {\n            return *this / BigInt(v);\n      \
    \  }\n        BigInt res = *this;\n        res /= v;\n        return res;\n  \
    \  }\n    void operator/=(const BigInt &v) {\n        *this = *this / v;\n   \
    \ }\n\n    long long operator%(long long v) const {\n        assert(v > 0);  //\
    \ operator / not well-defined for v <= 0.\n        assert(v < BASE);\n       \
    \ int m = 0;\n        for (int i = a.size() - 1; i >= 0; --i)\n            m =\
    \ (a[i] + m * (long long) BASE) % v;\n        return m * sign;\n    }\n\n    void\
    \ operator*=(int v) {\n        if (llabs(v) >= BASE) {\n            *this *= BigInt(v);\n\
    \            return ;\n        }\n        if (v < 0)\n            sign = -sign,\
    \ v = -v;\n        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i)\
    \ {\n            if (i == (int) a.size())\n                a.push_back(0);\n \
    \           long long cur = a[i] * (long long) v + carry;\n            carry =\
    \ (int) (cur / BASE);\n            a[i] = (int) (cur % BASE);\n            //asm(\"\
    divl %%ecx\" : \"=a\"(carry), \"=d\"(a[i]) : \"A\"(cur), \"c\"(base));\n     \
    \       /*\n             int val;\n             __asm {\n             lea esi,\
    \ cur\n             mov eax, [esi]\n             mov edx, [esi+4]\n          \
    \   mov ecx, base\n             div ecx\n             mov carry, eax\n       \
    \      mov val, edx;\n             }\n             a[i] = val;\n             */\n\
    \        }\n        trim();\n    }\n\n    BigInt operator*(int v) const {\n  \
    \      if (llabs(v) >= BASE) {\n            return *this * BigInt(v);\n      \
    \  }\n        BigInt res = *this;\n        res *= v;\n        return res;\n  \
    \  }\n\n    // Convert BASE 10^old --> 10^new.\n    static vector<int> convert_base(const\
    \ vector<int> &a, int old_digits, int new_digits) {\n        vector<long long>\
    \ p(max(old_digits, new_digits) + 1);\n        p[0] = 1;\n        for (int i =\
    \ 1; i < (int) p.size(); i++)\n            p[i] = p[i - 1] * 10;\n        vector<int>\
    \ res;\n        long long cur = 0;\n        int cur_digits = 0;\n        for (int\
    \ i = 0; i < (int) a.size(); i++) {\n            cur += a[i] * p[cur_digits];\n\
    \            cur_digits += old_digits;\n            while (cur_digits >= new_digits)\
    \ {\n                res.push_back((long long)(cur % p[new_digits]));\n      \
    \          cur /= p[new_digits];\n                cur_digits -= new_digits;\n\
    \            }\n        }\n        res.push_back((int) cur);\n        while (!res.empty()\
    \ && !res.back())\n            res.pop_back();\n        return res;\n    }\n\n\
    \    void fft(vector<complex<double> > &x, bool invert) const {\n        int n\
    \ = (int) x.size();\n\n        for (int i = 1, j = 0; i < n; ++i) {\n        \
    \    int bit = n >> 1;\n            for (; j >= bit; bit >>= 1)\n            \
    \    j -= bit;\n            j += bit;\n            if (i < j)\n              \
    \  swap(x[i], x[j]);\n        }\n\n        for (int len = 2; len <= n; len <<=\
    \ 1) {\n            double ang = 2 * 3.14159265358979323846 / len * (invert ?\
    \ -1 : 1);\n            complex<double> wlen(cos(ang), sin(ang));\n          \
    \  for (int i = 0; i < n; i += len) {\n                complex<double> w(1);\n\
    \                for (int j = 0; j < len / 2; ++j) {\n                    complex<double>\
    \ u = x[i + j];\n                    complex<double> v = x[i + j + len / 2] *\
    \ w;\n                    x[i + j] = u + v;\n                    x[i + j + len\
    \ / 2] = u - v;\n                    w *= wlen;\n                }\n         \
    \   }\n        }\n        if (invert)\n            for (int i = 0; i < n; ++i)\n\
    \                x[i] /= n;\n    }\n\n    void multiply_fft(const vector<int>\
    \ &x, const vector<int> &y, vector<int> &res) const {\n        vector<complex<double>\
    \ > fa(x.begin(), x.end());\n        vector<complex<double> > fb(y.begin(), y.end());\n\
    \        int n = 1;\n        while (n < (int) max(x.size(), y.size()))\n     \
    \       n <<= 1;\n        n <<= 1;\n        fa.resize(n);\n        fb.resize(n);\n\
    \n        fft(fa, false);\n        fft(fb, false);\n        for (int i = 0; i\
    \ < n; ++i)\n            fa[i] *= fb[i];\n        fft(fa, true);\n\n        res.resize(n);\n\
    \        long long carry = 0;\n        for (int i = 0; i < n; ++i) {\n       \
    \     long long t = (long long) (fa[i].real() + 0.5) + carry;\n            carry\
    \ = t / 1000;\n            res[i] = t % 1000;\n        }\n    }\n\n    BigInt\
    \ mul_simple(const BigInt &v) const {\n        BigInt res;\n        res.sign =\
    \ sign * v.sign;\n        res.a.resize(a.size() + v.a.size());\n        for (int\
    \ i = 0; i < (int) a.size(); ++i)\n            if (a[i])\n                for\
    \ (int j = 0, carry = 0; j < (int) v.a.size() || carry; ++j) {\n             \
    \       long long cur = res.a[i + j] + (long long) a[i] * (j < (int) v.a.size()\
    \ ? v.a[j] : 0) + carry;\n                    carry = (int) (cur / BASE);\n  \
    \                  res.a[i + j] = (int) (cur % BASE);\n                }\n   \
    \     res.trim();\n        return res;\n    }\n\n    typedef vector<long long>\
    \ vll;\n\n    static vll karatsubaMultiply(const vll &a, const vll &b) {\n   \
    \     int n = a.size();\n        vll res(n + n);\n        if (n <= 32) {\n   \
    \         for (int i = 0; i < n; i++)\n                for (int j = 0; j < n;\
    \ j++)\n                    res[i + j] += a[i] * b[j];\n            return res;\n\
    \        }\n\n        int k = n >> 1;\n        vll a1(a.begin(), a.begin() + k);\n\
    \        vll a2(a.begin() + k, a.end());\n        vll b1(b.begin(), b.begin()\
    \ + k);\n        vll b2(b.begin() + k, b.end());\n\n        vll a1b1 = karatsubaMultiply(a1,\
    \ b1);\n        vll a2b2 = karatsubaMultiply(a2, b2);\n\n        for (int i =\
    \ 0; i < k; i++)\n            a2[i] += a1[i];\n        for (int i = 0; i < k;\
    \ i++)\n            b2[i] += b1[i];\n\n        vll r = karatsubaMultiply(a2, b2);\n\
    \        for (int i = 0; i < (int) a1b1.size(); i++)\n            r[i] -= a1b1[i];\n\
    \        for (int i = 0; i < (int) a2b2.size(); i++)\n            r[i] -= a2b2[i];\n\
    \n        for (int i = 0; i < (int) r.size(); i++)\n            res[i + k] +=\
    \ r[i];\n        for (int i = 0; i < (int) a1b1.size(); i++)\n            res[i]\
    \ += a1b1[i];\n        for (int i = 0; i < (int) a2b2.size(); i++)\n         \
    \   res[i + n] += a2b2[i];\n        return res;\n    }\n\n    BigInt mul_karatsuba(const\
    \ BigInt &v) const {\n        vector<int> x6 = convert_base(this->a, BASE_DIGITS,\
    \ 6);\n        vector<int> y6 = convert_base(v.a, BASE_DIGITS, 6);\n        vll\
    \ x(x6.begin(), x6.end());\n        vll y(y6.begin(), y6.end());\n        while\
    \ (x.size() < y.size())\n            x.push_back(0);\n        while (y.size()\
    \ < x.size())\n            y.push_back(0);\n        while (x.size() & (x.size()\
    \ - 1))\n            x.push_back(0), y.push_back(0);\n        vll c = karatsubaMultiply(x,\
    \ y);\n        BigInt res;\n        res.sign = sign * v.sign;\n        long long\
    \ carry = 0;\n        for (int i = 0; i < (int) c.size(); i++) {\n           \
    \ long long cur = c[i] + carry;\n            res.a.push_back((int) (cur % 1000000));\n\
    \            carry = cur / 1000000;\n        }\n        res.a = convert_base(res.a,\
    \ 6, BASE_DIGITS);\n        res.trim();\n        return res;\n    }\n\n    void\
    \ operator*=(const BigInt &v) {\n        *this = *this * v;\n    }\n    BigInt\
    \ operator*(const BigInt &v) const {\n        if (a.size() * v.a.size() <= 1000111)\
    \ return mul_simple(v);\n        if (a.size() > 500111 || v.a.size() > 500111)\
    \ return mul_fft(v);\n        return mul_karatsuba(v);\n    }\n\n    BigInt mul_fft(const\
    \ BigInt& v) const {\n        BigInt res;\n        res.sign = sign * v.sign;\n\
    \        multiply_fft(convert_base(a, BASE_DIGITS, 3), convert_base(v.a, BASE_DIGITS,\
    \ 3), res.a);\n        res.a = convert_base(res.a, 3, BASE_DIGITS);\n        res.trim();\n\
    \        return res;\n    }\n\n    // -------------------- Misc --------------------\n\
    \    BigInt abs() const {\n        BigInt res = *this;\n        res.sign *= res.sign;\n\
    \        return res;\n    }\n    void trim() {\n        while (!a.empty() && !a.back())\n\
    \            a.pop_back();\n        if (a.empty())\n            sign = 1;\n  \
    \  }\n\n    bool isZero() const {\n        return a.empty() || (a.size() == 1\
    \ && !a[0]);\n    }\n\n    friend BigInt gcd(const BigInt &a, const BigInt &b)\
    \ {\n        return b.isZero() ? a : gcd(b, a % b);\n    }\n    friend BigInt\
    \ lcm(const BigInt &a, const BigInt &b) {\n        return a / gcd(a, b) * b;\n\
    \    }\n\n    friend BigInt sqrt(const BigInt &a1) {\n        BigInt a = a1;\n\
    \        while (a.a.empty() || a.a.size() % 2 == 1)\n            a.a.push_back(0);\n\
    \n        int n = a.a.size();\n\n        int firstDigit = (int) sqrt((double)\
    \ a.a[n - 1] * BASE + a.a[n - 2]);\n        int norm = BASE / (firstDigit + 1);\n\
    \        a *= norm;\n        a *= norm;\n        while (a.a.empty() || a.a.size()\
    \ % 2 == 1)\n            a.a.push_back(0);\n\n        BigInt r = (long long) a.a[n\
    \ - 1] * BASE + a.a[n - 2];\n        firstDigit = (int) sqrt((double) a.a[n -\
    \ 1] * BASE + a.a[n - 2]);\n        int q = firstDigit;\n        BigInt res;\n\
    \n        for(int j = n / 2 - 1; j >= 0; j--) {\n            for(; ; --q) {\n\
    \                BigInt r1 = (r - (res * 2 * BigInt(BASE) + q) * q) * BigInt(BASE)\
    \ * BigInt(BASE) + (j > 0 ? (long long) a.a[2 * j - 1] * BASE + a.a[2 * j - 2]\
    \ : 0);\n                if (r1 >= 0) {\n                    r = r1;\n       \
    \             break;\n                }\n            }\n            res *= BASE;\n\
    \            res += q;\n\n            if (j > 0) {\n                int d1 = res.a.size()\
    \ + 2 < r.a.size() ? r.a[res.a.size() + 2] : 0;\n                int d2 = res.a.size()\
    \ + 1 < r.a.size() ? r.a[res.a.size() + 1] : 0;\n                int d3 = res.a.size()\
    \ < r.a.size() ? r.a[res.a.size()] : 0;\n                q = ((long long) d1 *\
    \ BASE * BASE + (long long) d2 * BASE + d3) / (firstDigit * 2);\n            }\n\
    \        }\n\n        res.trim();\n        return res / norm;\n    }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/bigint.h
  requiredBy: []
  timestamp: '2022-11-19 11:13:09+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/tests/aizu_ntl_2_e_bigint_mod.test.cpp
  - Math/tests/aizu_ntl_2_a_bigint_add.test.cpp
  - Math/tests/aizu_ntl_2_f_bigint_mul_fft.test.cpp
  - Math/tests/aizu_ntl_2_c_bigint_mul.test.cpp
  - Math/tests/aizu_ntl_2_b_bigint_sub.test.cpp
  - Math/tests/aizu_ntl_2_d_bigint_div.test.cpp
  - Math/tests/aizu_ntl_2_c_bigint_mul_karatsuba.test.cpp
documentation_of: Math/bigint.h
layout: document
redirect_from:
- /library/Math/bigint.h
- /library/Math/bigint.h.html
title: Math/bigint.h
---
