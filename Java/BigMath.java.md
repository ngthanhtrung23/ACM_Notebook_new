---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Java/InputReader.java
    title: Java/InputReader.java
  - icon: ':warning:'
    path: Java/JS.java
    title: Java/JS.java
  - icon: ':warning:'
    path: Java/Rational.java
    title: Java/Rational.java
  - icon: ':warning:'
    path: Java/RegexTest.java
    title: Java/RegexTest.java
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Java/InputReader.java
    title: Java/InputReader.java
  - icon: ':warning:'
    path: Java/JS.java
    title: Java/JS.java
  - icon: ':warning:'
    path: Java/Rational.java
    title: Java/Rational.java
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
    RuntimeError: bundler is not specified: Java/BigMath.java\n"
  code: "import java.math.*;\n\nclass BMath {\n    static int cnt1, cnt2;\n    public\
    \ static MathContext mc = null;\n    public static BigDecimal eps = null;\n  \
    \  public static BigDecimal two = null;\n    public static BigDecimal sqrt3 =\
    \ null;\n    public static BigDecimal pi = null;\n    public static final int\
    \ PRECISION = 128;\n\n    static {\n        mc = new MathContext(PRECISION);\n\
    \        eps = BigDecimal.ONE.scaleByPowerOfTen(-PRECISION);\n        two = BigDecimal.valueOf(2);\n\
    \        sqrt3 = sqrt(BigDecimal.valueOf(3));\n        pi = asin(BigDecimal.valueOf(0.5)).multiply(BigDecimal.valueOf(6));\n\
    \    }\n\n    // val > 0\n    public static BigInteger sqrt(BigInteger val) {\n\
    \        int len = val.bitLength();\n        BigInteger left = BigInteger.ONE.shiftLeft((len\
    \ - 1) / 2);\n        BigInteger right = BigInteger.ONE.shiftLeft(len / 2 + 1);\n\
    \        while (left.compareTo(right) < 0) {\n            BigInteger mid = left.add(right).shiftRight(1);\n\
    \            if (mid.multiply(mid).compareTo(val) <= 0) {\n                left\
    \ = mid.add(BigInteger.ONE);\n            } else {\n                right = mid;\n\
    \            }\n        }\n        return right.subtract(BigInteger.ONE);\n  \
    \  }\n\n    public static BigDecimal sqrt(BigDecimal val) {\n        BigInteger\
    \ unscaledVal = val.scaleByPowerOfTen(2 * mc.getPrecision()).toBigInteger();\n\
    \        return new BigDecimal(sqrt(unscaledVal)).scaleByPowerOfTen(-mc.getPrecision());\n\
    \    }\n\n    // arcsin x =\u2211(n=1\uFF5E\u221E) [(2n)!]x^(2n+1)/[4^n*(n!)^2*(2n+1)]\n\
    \    // arctan x =\u2211(n=1\uFF5E\u221E) [(-1)^n]x^(2n+1)/(2n+1)\n    public\
    \ static BigDecimal asin(BigDecimal val) {\n        BigDecimal tmp = val;\n  \
    \      BigDecimal ret = tmp;\n        val = val.multiply(val, mc);\n        for\
    \ (int n = 1; tmp.compareTo(eps) > 0; ++n) {\n            tmp = tmp.multiply(val,\
    \ mc).multiply(\n                    BigDecimal.valueOf(2 * n - 1).divide(BigDecimal.valueOf(2\
    \ * n), mc), mc);\n            ret = ret.add(tmp.divide(BigDecimal.valueOf(2 *\
    \ n + 1), mc), mc);\n        }\n        return ret;\n    }\n}\n"
  dependsOn:
  - Java/JS.java
  - Java/Rational.java
  - Java/InputReader.java
  - Java/RegexTest.java
  isVerificationFile: false
  path: Java/BigMath.java
  requiredBy:
  - Java/JS.java
  - Java/Rational.java
  - Java/InputReader.java
  - Java/RegexTest.java
  timestamp: '2021-12-30 17:31:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Java/BigMath.java
layout: document
redirect_from:
- /library/Java/BigMath.java
- /library/Java/BigMath.java.html
title: Java/BigMath.java
---
