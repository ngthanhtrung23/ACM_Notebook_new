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
    path: Java/Rational.java
    title: Java/Rational.java
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
    path: Java/Rational.java
    title: Java/Rational.java
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: java
  _verificationStatusIcon: ':warning:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/user_defined.py\"\
    , line 68, in bundle\n    raise RuntimeError('bundler is not specified: {}'.format(str(path)))\n\
    RuntimeError: bundler is not specified: Java/RegexTest.java\n"
  code: "package Java;\nimport java.util.regex.*;\npublic class RegexTest {\n    public\
    \ static void main(String[] args) {\n        Pattern p = Pattern.compile(\"a+\"\
    );\n        String s = \"aabbbaaaaabbbabb\";\n        System.out.println(s.matches(\"\
    a+b+a+b+a+b+\"));\n        Matcher m = p.matcher(s);\n        while (m.find())\
    \ {\n            System.out.println(m.start() + \"-->\" + m.end() + \": \" + m.group());\n\
    \        }\n    }\n}\n"
  dependsOn:
  - Java/JS.java
  - Java/BigMath.java
  - Java/Rational.java
  - Java/InputReader.java
  isVerificationFile: false
  path: Java/RegexTest.java
  requiredBy:
  - Java/JS.java
  - Java/BigMath.java
  - Java/Rational.java
  - Java/InputReader.java
  timestamp: '2021-12-30 17:31:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Java/RegexTest.java
layout: document
redirect_from:
- /library/Java/RegexTest.java
- /library/Java/RegexTest.java.html
title: Java/RegexTest.java
---
