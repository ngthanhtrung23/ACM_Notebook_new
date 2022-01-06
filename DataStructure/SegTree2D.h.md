---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
    title: DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SegTree2D.h\"\n// 2D segment tree\n// Requires\
    \ SegTree.h\ntemplate<\n    class S,        // aggregate data type\n    S (*op)\
    \ (S, S), // combine aggregate data\n    S (*e) (),      // empty element\n  \
    \  class Coord     // for x and y coordinates\n> struct SegTree2D {\n    using\
    \ P = pair<Coord, Coord>;\n\n    // _points must contains all add queries\n  \
    \  SegTree2D(const vector<P>& _points) : points(_points) {\n        sort(points.begin(),\
    \ points.end());\n        points.erase(unique(points.begin(), points.end()), points.end());\n\
    \        n = points.size();\n\n        // init segtrees\n        coords.resize(n\
    \ * 2);\n        for (int i = 0; i < n; i++) {\n            coords[n + i] = {{points[i].second,\
    \ points[i].first}};\n        }\n        for (int i = n-1; i > 0; i--) {\n   \
    \         std::merge(coords[i*2].begin(), coords[i*2].end(),\n               \
    \        coords[i*2+1].begin(), coords[i*2+1].end(),\n                       std::back_inserter(coords[i]));\n\
    \            coords[i].erase(unique(coords[i].begin(), coords[i].end()), coords[i].end());\n\
    \        }\n        for (const auto& c : coords) {\n            segs.emplace_back(SegTree<S,\
    \ op, e>(c.size()));\n        }\n    }\n\n    // Set value(p) = val\n    void\
    \ set(P p, S val) {\n        int i = lower_bound(points.begin(), points.end(),\
    \ p) - points.begin();\n        assert(i < n && points[i] == p);\n        for\
    \ (i += n; i; i >>= 1) {\n            int j = lower_bound(coords[i].begin(), coords[i].end(),\
    \ P{p.second, p.first}) - coords[i].begin();\n            segs[i].set(j, val);\n\
    \        }\n    }\n\n    // Get value at p\n    S get(P p) const {\n        return\
    \ prod(p, P{p.first + 1, p.second + 1});\n    }\n\n    // Get sum of points in\
    \ rectangles, given bottom-left and top-right\n    // [low.x, high.x - 1] * [low.y,\
    \ high.y - 1]\n    S prod(P low, P high) const {\n        assert(low.first <=\
    \ high.first);\n        assert(low.second <= high.second);\n        if (low.first\
    \ == high.first) return e();\n        if (low.second == high.second) return e();\n\
    \n        int l = n + (lower_bound(points.begin(), points.end(), low, cmpFirst)\
    \ - points.begin());\n        int r = n + (lower_bound(points.begin(), points.end(),\
    \ high, cmpFirst) - points.begin());\n        S res = e();\n        while (l <\
    \ r) {\n            if (l & 1) res = op(res, prod_1d(l++, low.second, high.second));\n\
    \            if (r & 1) res = op(res, prod_1d(--r, low.second, high.second));\n\
    \            l >>= 1; r >>= 1;\n        }\n        return res;\n    }\n\n// private:\n\
    \    S prod_1d(int x, Coord l, Coord r) const {\n        auto il = lower_bound(coords[x].begin(),\
    \ coords[x].end(), P{l, l}, cmpFirst) - coords[x].begin();\n        auto ir =\
    \ lower_bound(coords[x].begin(), coords[x].end(), P{r, r}, cmpFirst) - coords[x].begin();\n\
    \        return segs[x].prod(il, ir);\n    }\n\n    static bool cmpFirst(const\
    \ P& u, const P& v) {\n        return u.first < v.first;\n    }\n\n    int n;\n\
    \    vector<P> points;\n\n    // segtrees, outer layer by x-coordinate\n    vector<vector<P>>\
    \ coords;  // coords[i] stores all points maintained by i-th node in ST\n    vector<SegTree<S,\
    \ op, e>> segs;\n};\n"
  code: "// 2D segment tree\n// Requires SegTree.h\ntemplate<\n    class S,      \
    \  // aggregate data type\n    S (*op) (S, S), // combine aggregate data\n   \
    \ S (*e) (),      // empty element\n    class Coord     // for x and y coordinates\n\
    > struct SegTree2D {\n    using P = pair<Coord, Coord>;\n\n    // _points must\
    \ contains all add queries\n    SegTree2D(const vector<P>& _points) : points(_points)\
    \ {\n        sort(points.begin(), points.end());\n        points.erase(unique(points.begin(),\
    \ points.end()), points.end());\n        n = points.size();\n\n        // init\
    \ segtrees\n        coords.resize(n * 2);\n        for (int i = 0; i < n; i++)\
    \ {\n            coords[n + i] = {{points[i].second, points[i].first}};\n    \
    \    }\n        for (int i = n-1; i > 0; i--) {\n            std::merge(coords[i*2].begin(),\
    \ coords[i*2].end(),\n                       coords[i*2+1].begin(), coords[i*2+1].end(),\n\
    \                       std::back_inserter(coords[i]));\n            coords[i].erase(unique(coords[i].begin(),\
    \ coords[i].end()), coords[i].end());\n        }\n        for (const auto& c :\
    \ coords) {\n            segs.emplace_back(SegTree<S, op, e>(c.size()));\n   \
    \     }\n    }\n\n    // Set value(p) = val\n    void set(P p, S val) {\n    \
    \    int i = lower_bound(points.begin(), points.end(), p) - points.begin();\n\
    \        assert(i < n && points[i] == p);\n        for (i += n; i; i >>= 1) {\n\
    \            int j = lower_bound(coords[i].begin(), coords[i].end(), P{p.second,\
    \ p.first}) - coords[i].begin();\n            segs[i].set(j, val);\n        }\n\
    \    }\n\n    // Get value at p\n    S get(P p) const {\n        return prod(p,\
    \ P{p.first + 1, p.second + 1});\n    }\n\n    // Get sum of points in rectangles,\
    \ given bottom-left and top-right\n    // [low.x, high.x - 1] * [low.y, high.y\
    \ - 1]\n    S prod(P low, P high) const {\n        assert(low.first <= high.first);\n\
    \        assert(low.second <= high.second);\n        if (low.first == high.first)\
    \ return e();\n        if (low.second == high.second) return e();\n\n        int\
    \ l = n + (lower_bound(points.begin(), points.end(), low, cmpFirst) - points.begin());\n\
    \        int r = n + (lower_bound(points.begin(), points.end(), high, cmpFirst)\
    \ - points.begin());\n        S res = e();\n        while (l < r) {\n        \
    \    if (l & 1) res = op(res, prod_1d(l++, low.second, high.second));\n      \
    \      if (r & 1) res = op(res, prod_1d(--r, low.second, high.second));\n    \
    \        l >>= 1; r >>= 1;\n        }\n        return res;\n    }\n\n// private:\n\
    \    S prod_1d(int x, Coord l, Coord r) const {\n        auto il = lower_bound(coords[x].begin(),\
    \ coords[x].end(), P{l, l}, cmpFirst) - coords[x].begin();\n        auto ir =\
    \ lower_bound(coords[x].begin(), coords[x].end(), P{r, r}, cmpFirst) - coords[x].begin();\n\
    \        return segs[x].prod(il, ir);\n    }\n\n    static bool cmpFirst(const\
    \ P& u, const P& v) {\n        return u.first < v.first;\n    }\n\n    int n;\n\
    \    vector<P> points;\n\n    // segtrees, outer layer by x-coordinate\n    vector<vector<P>>\
    \ coords;  // coords[i] stores all points maintained by i-th node in ST\n    vector<SegTree<S,\
    \ op, e>> segs;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegTree2D.h
  requiredBy: []
  timestamp: '2022-01-06 20:43:29+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - DataStructure/test/segment_tree_2d_pointaddrectsum.test.cpp
documentation_of: DataStructure/SegTree2D.h
layout: document
redirect_from:
- /library/DataStructure/SegTree2D.h
- /library/DataStructure/SegTree2D.h.html
title: DataStructure/SegTree2D.h
---
