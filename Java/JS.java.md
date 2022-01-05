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
    path: Java/InputReader.java
    title: Java/InputReader.java
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
    RuntimeError: bundler is not specified: Java/JS.java\n"
  code: "package Java;\nimport javax.script.*;\n\npublic class JS {\n    public static\
    \ void main(String[] args) throws Exception {\n        ScriptEngineManager manager\
    \ = new ScriptEngineManager();\n        ScriptEngine engine = manager.getEngineByName(\"\
    JavaScript\");\n\n        String s = \"(1 + 1) * 2\";\n        engine.put(\"s\"\
    , s);\n        engine.eval(\"print('In JS, s = ' + s); s = eval(s);\");\n\n  \
    \      Integer t = (Integer) engine.get(\"s\");\n        System.out.println(\"\
    In Java, t = \" + t);\n    }\n}\n"
  dependsOn:
  - Java/BigMath.java
  - Java/Rational.java
  - Java/InputReader.java
  - Java/RegexTest.java
  isVerificationFile: false
  path: Java/JS.java
  requiredBy:
  - Java/BigMath.java
  - Java/Rational.java
  - Java/InputReader.java
  - Java/RegexTest.java
  timestamp: '2021-12-30 17:31:11+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Java/JS.java
layout: document
redirect_from:
- /library/Java/JS.java
- /library/Java/JS.java.html
title: Java/JS.java
---
