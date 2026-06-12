---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/segment_union.h\"\ndouble segment_union(vector<\
    \ pair<double, double> > segs) {\n    int n = SZ(segs);\n    vector< pair<double,\
    \ bool> > x(n*2);\n    REP(i,n) {\n        x[i*2] = make_pair(segs[i].first, false);\n\
    \        x[i*2+1] = make_pair(segs[i].second, true);\n    }\n    sort(x.begin(),\
    \ x.end());\n\n    double res = 0.0;\n    int c = 0;\n    REP(i,n*2) {\n     \
    \   if (c && i) res += x[i].first - x[i-1].first;\n        if (x[i].second) ++c;\n\
    \        else --c;\n    }\n    return res;\n}\n\n"
  code: "double segment_union(vector< pair<double, double> > segs) {\n    int n =\
    \ SZ(segs);\n    vector< pair<double, bool> > x(n*2);\n    REP(i,n) {\n      \
    \  x[i*2] = make_pair(segs[i].first, false);\n        x[i*2+1] = make_pair(segs[i].second,\
    \ true);\n    }\n    sort(x.begin(), x.end());\n\n    double res = 0.0;\n    int\
    \ c = 0;\n    REP(i,n*2) {\n        if (c && i) res += x[i].first - x[i-1].first;\n\
    \        if (x[i].second) ++c;\n        else --c;\n    }\n    return res;\n}\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/segment_union.h
  requiredBy: []
  timestamp: '2018-05-30 23:12:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/segment_union.h
layout: document
redirect_from:
- /library/Geometry/segment_union.h
- /library/Geometry/segment_union.h.html
title: Geometry/segment_union.h
---
