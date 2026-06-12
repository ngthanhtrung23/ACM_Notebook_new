---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Fraction.h\"\n// Fraction {{{\nint cmp(int a, int b)\
    \ { return (a == b) ? 0 : ((a < b) ? -1 : 1); }\n\nstruct Fraction {\n    int\
    \ a, b;\n\n    Fraction() {\n        a = 0;\n        b = 1;\n    }\n\n    Fraction(int\
    \ _a, int _b) {\n        a = _a;\n        b = _b;\n        norm();\n    }\n\n\
    \    Fraction(int x) {\n        a = x;\n        b = 1;\n    }\n\n    Fraction\
    \ operator + (const Fraction& other) const {\n        return Fraction(a * other.b\
    \ + b * other.a, b * other.b);\n    }\n    Fraction operator - (const Fraction&\
    \ other) const {\n        return Fraction(a * other.b - b * other.a, b * other.b);\n\
    \    }\n    Fraction operator * (const Fraction& other) const {\n        return\
    \ Fraction(a * other.a, b * other.b);\n    }\n    Fraction operator / (const Fraction&\
    \ other) const {\n        assert(other.a != 0);\n        return Fraction(a * other.b,\
    \ b * other.a);\n    }\n\n    int cmp(Fraction other) const {\n        return\
    \ ::cmp(a * other.b, b * other.a);\n    }\n\n#define Comp(x) bool operator x (Fraction\
    \ q) const { return cmp(q) x 0; }\n    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=)\
    \ Comp(!=)\n#undef Comp\n\n    void norm() {\n        if (b < 0) {\n         \
    \   a = -a;\n            b = -b;\n        }\n\n        if (a == 0) b = 1;\n  \
    \      else {\n            int g = __gcd(llabs(a), llabs(b));\n            a /=\
    \ g;\n            b /= g;\n        }\n    }\n};\nistream& operator >> (istream&\
    \ cin, Fraction& p) {\n    cin >> p.a;\n    p.b = 1;\n    return cin;\n}\nostream&\
    \ operator << (ostream& cout, Fraction& p) {\n    cout << p.a << '/' << p.b;\n\
    \    return cout;\n}\n// }}}\n"
  code: "// Fraction {{{\nint cmp(int a, int b) { return (a == b) ? 0 : ((a < b) ?\
    \ -1 : 1); }\n\nstruct Fraction {\n    int a, b;\n\n    Fraction() {\n       \
    \ a = 0;\n        b = 1;\n    }\n\n    Fraction(int _a, int _b) {\n        a =\
    \ _a;\n        b = _b;\n        norm();\n    }\n\n    Fraction(int x) {\n    \
    \    a = x;\n        b = 1;\n    }\n\n    Fraction operator + (const Fraction&\
    \ other) const {\n        return Fraction(a * other.b + b * other.a, b * other.b);\n\
    \    }\n    Fraction operator - (const Fraction& other) const {\n        return\
    \ Fraction(a * other.b - b * other.a, b * other.b);\n    }\n    Fraction operator\
    \ * (const Fraction& other) const {\n        return Fraction(a * other.a, b *\
    \ other.b);\n    }\n    Fraction operator / (const Fraction& other) const {\n\
    \        assert(other.a != 0);\n        return Fraction(a * other.b, b * other.a);\n\
    \    }\n\n    int cmp(Fraction other) const {\n        return ::cmp(a * other.b,\
    \ b * other.a);\n    }\n\n#define Comp(x) bool operator x (Fraction q) const {\
    \ return cmp(q) x 0; }\n    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)\n\
    #undef Comp\n\n    void norm() {\n        if (b < 0) {\n            a = -a;\n\
    \            b = -b;\n        }\n\n        if (a == 0) b = 1;\n        else {\n\
    \            int g = __gcd(llabs(a), llabs(b));\n            a /= g;\n       \
    \     b /= g;\n        }\n    }\n};\nistream& operator >> (istream& cin, Fraction&\
    \ p) {\n    cin >> p.a;\n    p.b = 1;\n    return cin;\n}\nostream& operator <<\
    \ (ostream& cout, Fraction& p) {\n    cout << p.a << '/' << p.b;\n    return cout;\n\
    }\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Fraction.h
  requiredBy: []
  timestamp: '2023-01-17 11:24:16+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Fraction.h
layout: document
redirect_from:
- /library/Math/Fraction.h
- /library/Math/Fraction.h.html
title: Math/Fraction.h
---
