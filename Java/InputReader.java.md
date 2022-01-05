---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Java/BigMath.java
    title: Java/BigMath.java
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
    path: Java/BigMath.java
    title: Java/BigMath.java
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
    RuntimeError: bundler is not specified: Java/InputReader.java\n"
  code: "import java.io.BufferedReader;\nimport java.io.IOException;\nimport java.io.InputStream;\n\
    import java.io.InputStreamReader;\nimport java.util.StringTokenizer;\n\nclass\
    \ InputReader {\n    private final BufferedReader reader;\n    private StringTokenizer\
    \ tokenizer;\n\n    public InputReader(InputStream stream) {\n        reader =\
    \ new BufferedReader(new InputStreamReader(stream));\n        tokenizer = null;\n\
    \    }\n\n    public String nextLine() {\n        try {\n            return reader.readLine();\n\
    \        } catch (IOException e) {\n            throw new RuntimeException(e);\n\
    \        }\n    }\n\n    public String next() {\n        while (tokenizer == null\
    \ || !tokenizer.hasMoreTokens()) {\n            tokenizer = new StringTokenizer(nextLine());\n\
    \        }\n        return tokenizer.nextToken();\n    }\n\n    public int nextInt()\
    \ {\n        return Integer.parseInt(next());\n    }\n}\n"
  dependsOn:
  - Java/JS.java
  - Java/BigMath.java
  - Java/Rational.java
  - Java/RegexTest.java
  isVerificationFile: false
  path: Java/InputReader.java
  requiredBy:
  - Java/JS.java
  - Java/BigMath.java
  - Java/Rational.java
  - Java/RegexTest.java
  timestamp: '2021-12-30 17:31:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Java/InputReader.java
layout: document
redirect_from:
- /library/Java/InputReader.java
- /library/Java/InputReader.java.html
title: Java/InputReader.java
---
