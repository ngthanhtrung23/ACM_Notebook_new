---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Geometry/basic.h
    title: Geometry/basic.h
  - icon: ':warning:'
    path: Geometry/circle.h
    title: Geometry/circle.h
  - icon: ':warning:'
    path: Geometry/smallestEnclosingCircle.h
    title: Geometry/smallestEnclosingCircle.h
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
    #include \"smallestEnclosingCircle.h\"\n\nint main()\n{\n    int test, n;\n  \
    \  double x, y;\n\n    cin >> test;\n    while (test--) {\n        cin >> n;\n\
    \        vector<Point> points;\n        while (n--) {\n            scanf(\"%lf%lf\"\
    , &x, &y);\n            points.push_back(Point(x, y));\n        }\n\n        SmallestEnclosingCircle\
    \ scc;\n        Circle c = scc.getCircle(points);\n        printf(\"%.2lf\\n%.2lf\
    \ %.2lf\\n\", c.r, c.x, c.y);\n    }\n}\n\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  - Geometry/circle.h
  - Geometry/smallestEnclosingCircle.h
  isVerificationFile: false
  path: Geometry/SPOJ_ALIENS.cpp
  requiredBy: []
  timestamp: '2022-01-10 23:38:23+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/SPOJ_ALIENS.cpp
layout: document
redirect_from:
- /library/Geometry/SPOJ_ALIENS.cpp
- /library/Geometry/SPOJ_ALIENS.cpp.html
title: Geometry/SPOJ_ALIENS.cpp
---
