---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Java/BigMath.java
    title: Java/BigMath.java
  - icon: ':warning:'
    path: Java/InputReader.java
    title: Java/InputReader.java
  - icon: ':warning:'
    path: Java/JS.java
    title: Java/JS.java
  - icon: ':warning:'
    path: Java/RegexTest.java
    title: Java/RegexTest.java
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Java/BigMath.java
    title: Java/BigMath.java
  - icon: ':warning:'
    path: Java/InputReader.java
    title: Java/InputReader.java
  - icon: ':warning:'
    path: Java/JS.java
    title: Java/JS.java
  - icon: ':warning:'
    path: Java/RegexTest.java
    title: Java/RegexTest.java
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: java
  _verificationStatusIcon: ':warning:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/user_defined.py\"\
    , line 68, in bundle\n    raise RuntimeError('bundler is not specified: {}'.format(str(path)))\n\
    RuntimeError: bundler is not specified: Java/Rational.java\n"
  code: "import java.math.*;\n\nclass Rational implements Comparable<Rational> {\n\
    \    public BigInteger a, b;\n\n    public Rational(BigInteger a, BigInteger b)\
    \ {\n        this.a = a;\n        this.b = b;\n        norm();\n    }\n\n    public\
    \ int compareTo(Rational other) {\n        return a.multiply(other.b).compareTo(b.multiply(other.a));\n\
    \    }\n\n    public Rational(BigInteger bigInteger) {\n        this(bigInteger,\
    \ BigInteger.ONE);\n    }\n\n    public Rational(int integer) {\n        this(BigInteger.valueOf(integer),\
    \ BigInteger.ONE);\n    }\n\n    public String toString() {\n        return a.toString()\
    \ + \"/\" + b.toString();\n    }\n\n    private void reduce() {\n        BigInteger\
    \ gcd = a.gcd(b);\n        if (!gcd.equals(BigInteger.ONE)) {\n            a =\
    \ a.divide(gcd);\n            b = b.divide(gcd);\n        }\n    }\n\n    private\
    \ void norm() {\n        if (b.compareTo(BigInteger.ZERO) == -1) {\n         \
    \   a = a.negate();\n            b = b.negate();\n        }\n\n        if (a.equals(BigInteger.ZERO))\
    \ {\n            b = BigInteger.ONE;\n        } else {\n            reduce();\n\
    \        }\n    }\n\n    public Rational add(Rational other) {\n        return\
    \ new Rational(\n                a.multiply(other.b).add(other.a.multiply(b)),\n\
    \                b.multiply(other.b));\n    }\n\n    public Rational negate()\
    \ {\n        return new Rational(a.negate(), b);\n    }\n\n    public Rational\
    \ subtract(Rational other) {\n        return add(other.negate());\n    }\n\n \
    \   public Rational multiply(Rational other) {\n        return new Rational(a.multiply(other.a),\
    \ b.multiply(other.b));\n    }\n\n    public Rational reciprocal() {\n       \
    \ if (a.equals(BigInteger.ZERO)) {\n            throw new java.lang.ArithmeticException();\n\
    \        }\n        return new Rational(b, a);\n    }\n\n    public Rational divide(Rational\
    \ other) {\n        return multiply(other.reciprocal());\n    }\n\n    public\
    \ boolean isInteger() {\n        return b.equals(BigInteger.ONE);\n    }\n\n \
    \   public BigInteger asInteger() {\n        if (!isInteger()) {\n           \
    \ throw new java.lang.ArithmeticException();\n        }\n        return a;\n \
    \   }\n\n    public boolean isZero() {\n        return a.equals(BigInteger.ZERO);\n\
    \    }\n\n    public static final Rational ZERO = new Rational(BigInteger.ZERO);\n\
    \    public static final Rational ONE = new Rational(BigInteger.ONE);\n}\n\n"
  dependsOn:
  - Java/JS.java
  - Java/BigMath.java
  - Java/InputReader.java
  - Java/RegexTest.java
  isVerificationFile: false
  path: Java/Rational.java
  requiredBy:
  - Java/JS.java
  - Java/BigMath.java
  - Java/InputReader.java
  - Java/RegexTest.java
  timestamp: '2021-12-30 17:31:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Java/Rational.java
layout: document
redirect_from:
- /library/Java/Rational.java
- /library/Java/Rational.java.html
title: Java/Rational.java
---
