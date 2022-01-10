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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 355, in update\n    raise BundleErrorAt(path, i + 1, \"found codes out\
    \ of include guard\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Geometry/basic.h: line 4: found codes out of include guard\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D\"\
    \n\n#include \"../../template.h\"\n#include \"../basic.h\"\n\nvoid solve() {\n\
    \    int q; cin >> q;\n    cout << (fixed) << setprecision(9);\n    while (q--)\
    \ {\n        Point a, b; cin >> a >> b;\n        Point c, d; cin >> c >> d;\n\
    \        Point t;\n\n        if (segmentIntersect(a, b, c, d)) cout << \"0\\n\"\
    ;\n        else {\n            cout << min(\n                    distToLineSegment(a,\
    \ c, d, t),\n                    distToLineSegment(b, c, d, t)) << '\\n';\n  \
    \      }\n    }\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  isVerificationFile: true
  path: Geometry/tests/basic_segment_distance.test.cpp
  requiredBy: []
  timestamp: '2022-01-10 23:38:23+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Geometry/tests/basic_segment_distance.test.cpp
layout: document
redirect_from:
- /verify/Geometry/tests/basic_segment_distance.test.cpp
- /verify/Geometry/tests/basic_segment_distance.test.cpp.html
title: Geometry/tests/basic_segment_distance.test.cpp
---
