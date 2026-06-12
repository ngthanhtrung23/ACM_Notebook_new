---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp
    title: Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://open.kattis.com/problems/closestpair1
    - https://open.kattis.com/problems/closestpair2
  bundledCode: "#line 1 \"Geometry/closest_pair.h\"\n// Closest pair\n//\n// Tested:\n\
    // - https://open.kattis.com/problems/closestpair1\n// - https://open.kattis.com/problems/closestpair2\n\
    //\n// Returns: {dist, 2 points}\n//\n// If need point ids -> add ID to struct\
    \ P\n// If need exact square dist -> can compute from returned points\ntemplate<typename\
    \ T>\nstd::pair<double, std::pair<P<T>, P<T>>> closest_pair(vector<P<T>> a) {\n\
    \    int n = a.size();\n    assert(n >= 2);\n    double mindist = 1e20;\n    std::pair<P<T>,\
    \ P<T>> best_pair;\n    std::vector<P<T>> t(n);\n    sort(a.begin(), a.end());\n\
    \n    auto upd_ans = [&] (const P<T>& u, const P<T>& v) {\n        double cur\
    \ = (u - v).len();\n        if (cur < mindist) {\n            mindist = cur;\n\
    \            best_pair = {u, v};\n        }\n    };\n\n    std::function<void(int,int)>\
    \ rec = [&] (int l, int r) {\n        if (r - l <= 3) {\n            for (int\
    \ i = l; i < r; ++i) {\n                for (int j = i + 1; j < r; ++j) {\n  \
    \                  upd_ans(a[i], a[j]);\n                }\n            }\n  \
    \          sort(a.begin() + l, a.begin() + r, cmpy<T>);\n            return;\n\
    \        }\n\n        int m = (l + r) >> 1;\n        T midx = a[m].x;\n      \
    \  rec(l, m);\n        rec(m, r);\n\n        std::merge(a.begin() + l, a.begin()\
    \ + m, a.begin() + m, a.begin() + r, t.begin(), cmpy<T>);\n        std::copy(t.begin(),\
    \ t.begin() + r - l, a.begin() + l);\n\n        int tsz = 0;\n        for (int\
    \ i = l; i < r; ++i) {\n            if (abs(a[i].x - midx) < mindist) {\n    \
    \            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)\n\
    \                    upd_ans(a[i], t[j]);\n                t[tsz++] = a[i];\n\
    \            }\n        }\n    };\n    rec(0, n);\n\n    return {mindist, best_pair};\n\
    }\n"
  code: "// Closest pair\n//\n// Tested:\n// - https://open.kattis.com/problems/closestpair1\n\
    // - https://open.kattis.com/problems/closestpair2\n//\n// Returns: {dist, 2 points}\n\
    //\n// If need point ids -> add ID to struct P\n// If need exact square dist ->\
    \ can compute from returned points\ntemplate<typename T>\nstd::pair<double, std::pair<P<T>,\
    \ P<T>>> closest_pair(vector<P<T>> a) {\n    int n = a.size();\n    assert(n >=\
    \ 2);\n    double mindist = 1e20;\n    std::pair<P<T>, P<T>> best_pair;\n    std::vector<P<T>>\
    \ t(n);\n    sort(a.begin(), a.end());\n\n    auto upd_ans = [&] (const P<T>&\
    \ u, const P<T>& v) {\n        double cur = (u - v).len();\n        if (cur <\
    \ mindist) {\n            mindist = cur;\n            best_pair = {u, v};\n  \
    \      }\n    };\n\n    std::function<void(int,int)> rec = [&] (int l, int r)\
    \ {\n        if (r - l <= 3) {\n            for (int i = l; i < r; ++i) {\n  \
    \              for (int j = i + 1; j < r; ++j) {\n                    upd_ans(a[i],\
    \ a[j]);\n                }\n            }\n            sort(a.begin() + l, a.begin()\
    \ + r, cmpy<T>);\n            return;\n        }\n\n        int m = (l + r) >>\
    \ 1;\n        T midx = a[m].x;\n        rec(l, m);\n        rec(m, r);\n\n   \
    \     std::merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(),\
    \ cmpy<T>);\n        std::copy(t.begin(), t.begin() + r - l, a.begin() + l);\n\
    \n        int tsz = 0;\n        for (int i = l; i < r; ++i) {\n            if\
    \ (abs(a[i].x - midx) < mindist) {\n                for (int j = tsz - 1; j >=\
    \ 0 && a[i].y - t[j].y < mindist; --j)\n                    upd_ans(a[i], t[j]);\n\
    \                t[tsz++] = a[i];\n            }\n        }\n    };\n    rec(0,\
    \ n);\n\n    return {mindist, best_pair};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/closest_pair.h
  requiredBy: []
  timestamp: '2022-01-12 00:40:19+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Geometry/tests/aizu_cgl_5_a_closest_pair.test.cpp
documentation_of: Geometry/closest_pair.h
layout: document
redirect_from:
- /library/Geometry/closest_pair.h
- /library/Geometry/closest_pair.h.html
title: Geometry/closest_pair.h
---
