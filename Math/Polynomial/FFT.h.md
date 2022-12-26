---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastFourierTransform.h
    - https://open.kattis.com/problems/polymul2
    - https://www.spoj.com/problems/MAXMATCH
    - https://www.spoj.com/problems/MUL/
    - https://www.spoj.com/problems/TSUM/
    - https://www.spoj.com/problems/VFMUL/
  bundledCode: "#line 1 \"Math/Polynomial/FFT.h\"\n// Note:\n// - When convert double\
    \ -> int, use my_round(x) which handles negative numbers\n//   correctly.\n//\n\
    // Tested:\n// - https://open.kattis.com/problems/polymul2\n// - https://www.spoj.com/problems/TSUM/\n\
    // - (bigint mul) https://www.spoj.com/problems/VFMUL/\n// - (bigint mul) https://www.spoj.com/problems/MUL/\n\
    // - (string matching) https://www.spoj.com/problems/MAXMATCH\n//\n// FFT {{{\n\
    // Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastFourierTransform.h\n\
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
    }\nlong long my_round(ld x) {\n    if (x < 0) return -my_round(-x);\n    return\
    \ (long long) (x + 1e-2);\n}\n// }}}\n"
  code: "// Note:\n// - When convert double -> int, use my_round(x) which handles\
    \ negative numbers\n//   correctly.\n//\n// Tested:\n// - https://open.kattis.com/problems/polymul2\n\
    // - https://www.spoj.com/problems/TSUM/\n// - (bigint mul) https://www.spoj.com/problems/VFMUL/\n\
    // - (bigint mul) https://www.spoj.com/problems/MUL/\n// - (string matching) https://www.spoj.com/problems/MAXMATCH\n\
    //\n// FFT {{{\n// Source: https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastFourierTransform.h\n\
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
    }\nlong long my_round(ld x) {\n    if (x < 0) return -my_round(-x);\n    return\
    \ (long long) (x + 1e-2);\n}\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Polynomial/FFT.h
  requiredBy: []
  timestamp: '2022-11-27 02:07:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Polynomial/FFT.h
layout: document
redirect_from:
- /library/Math/Polynomial/FFT.h
- /library/Math/Polynomial/FFT.h.html
title: Math/Polynomial/FFT.h
---
