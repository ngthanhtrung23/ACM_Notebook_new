---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/basic.h
    title: Geometry/basic.h
  - icon: ':heavy_check_mark:'
    path: Geometry/polygon.h
    title: Geometry/polygon.h
  - icon: ':heavy_check_mark:'
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
  code: "#include \"../template.h\"\n#include \"basic.h\"\n#include \"polygon.h\"\n\
    \nint main() {\n    cout << (fixed) << setprecision(9);\n    Polygon P;\n    P.push_back(Point(1,\
    \ 1));\n    P.push_back(Point(3, 3));\n    P.push_back(Point(9, 1));\n    P.push_back(Point(12,\
    \ 4));\n    P.push_back(Point(9, 7));\n    P.push_back(Point(1, 7));\n\n    //\
    \ Basic methods\n    assert(cmp(perimeter(P), 31.638263819) == 0);\n    assert(cmp(area(P),\
    \ 49.00) == 0);\n    assert(!is_convex(P));\n\n    // in_polygon\n    //7 P5--------------P4\n\
    \    //6 |                  \\\n    //5 |                    \\\n    //4 |   P7\
    \                P3\n    //3 |   P1___            /\n    //2 | / P6    \\ ___\
    \    /\n    //1 P0              P2\n    //0 1 2 3 4 5 6 7 8 9 101112\n\n    assert(in_polygon(P,\
    \ Point(3, 4)));\n    assert(!in_polygon(P, Point(3, 2)));\n\n    // Polygon cutting\n\
    \    //7 P5--------------P4\n    //6 |               |  \\\n    //5 |        \
    \       |    \\\n    //4 |               |     P3\n    //3 |   P1___       | \
    \   /\n    //2 | /       \\ ___ |  /\n    //1 P0              P2\n    //0 1 2\
    \ 3 4 5 6 7 8 9 101112\n    // new polygon (notice the index are different now):\n\
    \    //7 P4--------------P3\n    //6 |               |\n    //5 |            \
    \   |\n    //4 |               |\n    //3 |   P1___       |\n    //2 | /     \
    \  \\ ___ |\n    //1 P0              P2\n    //0 1 2 3 4 5 6 7 8 9\n\n    P =\
    \ polygon_cut(P, Line(P[2], P[4]));\n    assert(cmp(perimeter(P), 29.152982445)\
    \ == 0);\n    assert(cmp(area(P), 40.00) == 0);\n\n    // convex hull\n    //7\
    \ P3--------------P2\n    //6 |               |\n    //5 |               |\n \
    \   //4 |   P7          |\n    //3 |               |\n    //2 |              \
    \ |\n    //1 P0--------------P1\n    //0 1 2 3 4 5 6 7 8 9\n\n    P = convex_hull(P);\n\
    \    assert(cmp(perimeter(P), 28.00) == 0);\n    assert(cmp(area(P), 48.00) ==\
    \ 0);\n    assert(is_convex(P));\n    assert(in_convex(P, Point(3, 4)));\n   \
    \ assert(in_convex(P, Point(3, 2)));\n    assert(!in_convex(P, Point(3, 1)));\n\
    \    assert(!in_convex(P, Point(3, 0)));\n\n    assert(in_polygon(P, Point(3,\
    \ 4)));\n    assert(in_polygon(P, Point(3, 2)));\n    assert(!in_polygon(P, Point(3,\
    \ 0)));\n\n    P.clear();\n    for(int i = 0; i < 10; ++i)\n        for(int j\
    \ = 0; j < 10; ++j)\n            for(int turn = 0; turn < 3; ++turn)\n       \
    \         P.push_back(Point(i, j));\n    P = convex_hull(P);\n    assert(P.size()\
    \ == 4);\n    assert(P[0] == Point(0, 0));\n    assert(P[1] == Point(0, 9));\n\
    \    assert(P[2] == Point(9, 9));\n    assert(P[3] == Point(9, 0));\n\n    P.clear();\n\
    \    for(int i = 0; i < 10; ++i)\n        P.push_back(Point(7, 7 * i));\n    P\
    \ = convex_hull(P);\n    assert(P.size() == 2);\n    assert(P[0] == Point(7, 0));\n\
    \    assert(P[1] == Point(7, 63));\n\n    P.clear();\n    for(int i = 0; i < 10;\
    \ ++i)\n        P.push_back(Point(7, 7));\n    P = convex_hull(P);\n    assert(P.size()\
    \ == 1);\n    assert(P[0] == Point(7, 7));\n    cout << \"All test passed \" <<\
    \ endl;\n\n    return 0;\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  - Geometry/polygon.h
  isVerificationFile: false
  path: Geometry/polygon.cpp
  requiredBy: []
  timestamp: '2022-01-10 23:17:53+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/polygon.cpp
layout: document
redirect_from:
- /library/Geometry/polygon.cpp
- /library/Geometry/polygon.cpp.html
title: Geometry/polygon.cpp
---
