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
  code: "#include \"../template.h\"\n#include \"basic.h\"\n\nint main() {\n    Point\
    \ P1, P2, P3(0, 1);\n    assert((P1 == P2) == true);\n    assert((P1 == P3) ==\
    \ false);\n\n    vector<Point> P;\n    P.push_back(Point(2, 2));\n    P.push_back(Point(4,\
    \ 3));\n    P.push_back(Point(2, 4));\n    P.push_back(Point(6, 6));\n    P.push_back(Point(2,\
    \ 6));\n    P.push_back(Point(6, 5));\n\n    // sorting points demo\n    sort(P.begin(),\
    \ P.end());\n    assert(P[0] == Point(2, 2));\n    assert(P[1] == Point(2, 4));\n\
    \    assert(P[2] == Point(2, 6));\n    assert(P[3] == Point(4, 3));\n    assert(P[4]\
    \ == Point(6, 5));\n    assert(P[5] == Point(6, 6));\n\n    // rearrange the points\
    \ as shown in the diagram below\n    P.clear();\n    P.push_back(Point(2, 2));\n\
    \    P.push_back(Point(4, 3));\n    P.push_back(Point(2, 4));\n    P.push_back(Point(6,\
    \ 6));\n    P.push_back(Point(2, 6));\n    P.push_back(Point(6, 5));\n    P.push_back(Point(8,\
    \ 6));\n\n    /*\n    // the positions of these 7 points (0-based indexing)\n\
    \    6   P4      P3  P6\n    5           P5\n    4   P2\n    3       P1\n    2\
    \   P0\n    1\n    0 1 2 3 4 5 6 7 8\n    */\n\n    double d = (P[0] - P[5]).len();\n\
    \    assert(cmp(d, 5.0) == 0);\n\n    // Line equations\n    Line l1(P[0], P[1]);\n\
    \    assert(cmp(l1.a * P[0].x + l1.b * P[0].y + l1.c, 0) == 0);\n    assert(cmp(l1.a\
    \ * P[1].x + l1.b * P[1].y + l1.c, 0) == 0);\n\n    Line l2(P[0], P[2]);\n   \
    \ assert(cmp(l2.a * P[0].x + l2.b * P[0].y + l2.c, 0) == 0);\n    assert(cmp(l2.a\
    \ * P[2].x + l2.b * P[0].y + l2.c, 0) == 0);\n\n    // parallel, same, and Line\
    \ intersection tests\n    Line l3(P[2], P[3]);\n    assert(areParallel(l1, l2)\
    \ == false);\n    assert(areParallel(l1, l3) == true);\n\n    Line l4(P[2], P[4]);\n\
    \    assert(areSame(l1, l2) == false);\n    assert(areSame(l2, l4) == true);\n\
    \n    Point p12;\n    bool res = areIntersect(l1, l2, p12);\n    assert(res);\n\
    \    assert(p12 == Point(2, 2));\n\n    // other distances\n    Point ans;\n \
    \   d = distToLine(P[0], P[2], P[3], ans);\n    assert(cmp(d, 1.788854382) ==\
    \ 0);\n    assert(ans == Point(1.2, 3.6));\n\n    closestPoint(l3, P[0], ans);\n\
    \    assert(cmp(d, 1.788854382) == 0);\n    assert(ans == Point(1.2, 3.6));\n\n\
    \    d = distToLineSegment(P[0], P[2], P[3], ans);\n    assert(cmp(d, 2) == 0);\n\
    \    assert(ans == Point(2, 4));\n\n    d = distToLineSegment(P[1], P[2], P[3],\
    \ ans);\n    assert(cmp(d, 1.788854382) == 0);\n    assert(ans == Point(3.2, 4.6));\n\
    \n    d = distToLineSegment(P[6], P[2], P[3], ans);\n    assert(cmp(d, 2) == 0);\n\
    \    assert(ans == Point(6, 6));\n\n    reflectionPoint(l4, P[1], ans);\n    assert(ans\
    \ == Point(0, 3));\n\n    assert(cmp(RAD_to_DEG(angle(P[0], P[4], P[3])), 90)\
    \ == 0);\n    assert(cmp(RAD_to_DEG(angle(P[0], P[2], P[1])), 63.434948823) ==\
    \ 0);\n    assert(cmp(RAD_to_DEG(angle(P[4], P[3], P[6])), 180) == 0);\n\n   \
    \ assert(ccw(P[0], P[2], P[3]) == -1);\n    assert(ccw(P[0], P[3], P[2]) == 1);\n\
    \n    assert(ccw(P[0], P[2], P[3]) != 0);\n    assert(ccw(P[0], P[2], P[4]) ==\
    \ 0);\n\n    Point p(3, 7), q(11, 13), r(35, 30);\n    assert(ccw(p, q, r) ==\
    \ -1);\n\n    /*\n    // the positions of these 6 points\n     E<--  4\n     \
    \      3       B D<--\n           2   A C\n           1\n    -4-3-2-1 0 1 2 3\
    \ 4 5 6\n          -1\n          -2\n    F<--   -3\n    */\n\n    // translation\n\
    \    Point A(2.0, 2.0);\n    Point B(4.0, 3.0);\n    Point v = B - A;\n\n    Point\
    \ C(3.0, 2.0);\n    Point D = C + v;\n    assert(D == Point(5, 3));\n    Point\
    \ E = C + v * 0.5;\n    assert(E == Point(4, 2.5));\n\n    // rotation\n    assert(B\
    \ == Point(4, 3));\n    Point F = B.rotate(DEG_to_RAD(90));\n    assert(F == Point(-3,\
    \ 4));\n    Point G = B.rotate(DEG_to_RAD(180));\n    assert(G == Point(-4, -3));\n\
    \n    cout << \"All tests passed\" << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - template.h
  - Geometry/basic.h
  isVerificationFile: false
  path: Geometry/basic.cpp
  requiredBy: []
  timestamp: '2022-01-10 23:30:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/basic.cpp
layout: document
redirect_from:
- /library/Geometry/basic.cpp
- /library/Geometry/basic.cpp.html
title: Geometry/basic.cpp
---
