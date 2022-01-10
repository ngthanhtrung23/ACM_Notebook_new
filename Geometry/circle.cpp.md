---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Geometry/basic.h
    title: Geometry/basic.h
  - icon: ':warning:'
    path: Geometry/circle.h
    title: Geometry/circle.h
  - icon: ':question:'
    path: template.h
    title: template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 355, in update\n    raise BundleErrorAt(path, i + 1, \"found codes out\
    \ of include guard\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Geometry/basic.h: line 4: found codes out of include guard\n"
  code: "#include \"../template.h\"\n#include \"basic.h\"\n#include \"circle.h\"\n\
    \nint main() {\n    // Example: Check point inside circle\n    Circle C1(2, 2,\
    \ 7);\n    assert(cmp((C1 - Point(8, 2)).norm(), C1.r * C1.r) < 0);\n    assert(cmp((C1\
    \ - Point(9, 2)).norm(), C1.r * C1.r) == 0);\n    assert(cmp((C1 - Point(10, 2)).norm(),\
    \ C1.r * C1.r) > 0);\n\n    // Find common tangents\n    Circle c2(1, 2, sqrt(5.0));\n\
    \    Circle c3(5, 0, 0);\n\n    vector<Line> t = tangents(c2, c3);\n    assert(t.size()\
    \ == 2);\n    assert(cmp(t[0].f(Point(5, 0)), 0) == 0);\n    assert(cmp(t[1].f(Point(5,\
    \ 0)), 0) == 0);\n    cout << \"All tests passed\" << endl;\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  - Geometry/circle.h
  isVerificationFile: false
  path: Geometry/circle.cpp
  requiredBy: []
  timestamp: '2022-01-10 23:30:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/circle.cpp
layout: document
redirect_from:
- /library/Geometry/circle.cpp
- /library/Geometry/circle.cpp.html
title: Geometry/circle.cpp
---
