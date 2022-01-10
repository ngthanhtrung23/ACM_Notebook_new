---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Geometry/basic.h
    title: Geometry/basic.h
  - icon: ':heavy_check_mark:'
    path: Geometry/polygon.h
    title: Geometry/polygon.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 355, in update\n    raise BundleErrorAt(path, i + 1, \"found codes out\
    \ of include guard\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Geometry/basic.h: line 4: found codes out of include guard\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0412\"\
    \n\n#include \"../../template.h\"\n#include \"../basic.h\"\n#include \"../polygon.h\"\
    \n\nvoid solve() {\n    int n; cin >> n;\n    Polygon g(n);\n    for (auto& p\
    \ : g) cin >> p;\n\n    int q; cin >> q;\n    while (q--) {\n        Point p;\
    \ cin >> p;\n        p = p - (p / 10000.0);\n        cout << (in_convex(g, p)\
    \ ? 1 : 0) << '\\n';\n    }\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  - Geometry/polygon.h
  isVerificationFile: true
  path: Geometry/tests/polygon_in_convex.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 23:32:56+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Geometry/tests/polygon_in_convex.test.cpp
layout: document
redirect_from:
- /verify/Geometry/tests/polygon_in_convex.test.cpp
- /verify/Geometry/tests/polygon_in_convex.test.cpp.html
title: Geometry/tests/polygon_in_convex.test.cpp
---
