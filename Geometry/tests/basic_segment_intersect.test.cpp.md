---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Geometry/basic.h
    title: Geometry/basic.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 355, in update\n    raise BundleErrorAt(path, i + 1, \"found codes out\
    \ of include guard\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Geometry/basic.h: line 4: found codes out of include guard\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B\"\
    \n\n#include \"../../template.h\"\n#include \"../basic.h\"\n\nvoid solve() {\n\
    \    int q; cin >> q;\n    while (q--) {\n        Point a, b; cin >> a >> b;\n\
    \        Point c, d; cin >> c >> d;\n        cout << (segmentIntersect(a, b, c,\
    \ d) ? 1 : 0) << '\\n';\n    }\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  isVerificationFile: true
  path: Geometry/tests/basic_segment_intersect.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 23:38:23+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Geometry/tests/basic_segment_intersect.test.cpp
layout: document
redirect_from:
- /verify/Geometry/tests/basic_segment_intersect.test.cpp
- /verify/Geometry/tests/basic_segment_intersect.test.cpp.html
title: Geometry/tests/basic_segment_intersect.test.cpp
---
