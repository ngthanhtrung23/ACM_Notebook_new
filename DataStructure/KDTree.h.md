---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://open.kattis.com/problems/closestpair1
    - https://open.kattis.com/problems/closestpair2
  bundledCode: "#line 1 \"DataStructure/KDTree.h\"\n// Tested:\n// - https://open.kattis.com/problems/closestpair1\n\
    // - https://open.kattis.com/problems/closestpair2\n//\n// A straightforward,\
    \ but probably sub-optimal KD-tree implmentation that's\n// probably good enough\
    \ for most things (current it's a 2D-tree)\n//\n// - constructs from n Points\
    \ in O(n lg^2 n) time\n// - handles nearest-neighbor query in O(lg n) if Points\
    \ are well distributed\n// - worst case for nearest-neighbor may be linear in\
    \ pathological case\n// Note:\n// - When there are multiple points in same position\
    \ & we need to tell a Point\n//   not to find itself, must handle separatedly.\n\
    \ntypedef long long ll;\nconst ll sentry = numeric_limits<ll>::max();\nstruct\
    \ Point {\n    ll x, y;\n    Point(ll xx = 0, ll yy = 0) : x(xx), y(yy) {}\n\n\
    \    Point operator - (Point a) const { return Point(x-a.x, y-a.y); }\n\n    ll\
    \ dist2() { return x*x + y*y; }\n};\n\nbool operator == (const Point &a, const\
    \ Point &b){\n    return a.x == b.x && a.y == b.y;\n}\nbool on_x(const Point &a,\
    \ const Point &b) {\n    return a.x < b.x;\n}\nbool on_y(const Point &a, const\
    \ Point &b) {\n    return a.y < b.y;\n}\n\n// bounding box for a set of Points\n\
    struct Bbox {\n    ll x0, x1, y0, y1;\n    Bbox() : x0(sentry), x1(-sentry), y0(sentry),\
    \ y1(-sentry) {}\n    // computes bounding box from a bunch of Points\n    void\
    \ compute(const vector<Point> &v) {\n        for (int i = 0; i < v.size(); ++i)\
    \ {\n            x0 = min(x0, v[i].x); x1 = max(x1, v[i].x);\n            y0 =\
    \ min(y0, v[i].y); y1 = max(y1, v[i].y);\n        }\n    }\n    // squared distance\
    \ between a Point and this Bbox, 0 if inside\n    ll distance(const Point &p)\
    \ {\n        if (p.x < x0) {\n            if (p.y < y0)       return (Point(x0,\
    \ y0) - p).dist2();\n            else if (p.y > y1)  return (Point(x0, y1) - p).dist2();\n\
    \            else                return (Point(x0, p.y) - p).dist2();\n      \
    \  } else if (p.x > x1) {\n            if (p.y < y0)       return (Point(x1, y0)\
    \ - p).dist2();\n            else if (p.y > y1)  return (Point(x1, y1) - p).dist2();\n\
    \            else                return (Point(x1, p.y) - p).dist2();\n      \
    \  } else {\n            if (p.y < y0)       return (Point(p.x, y0) - p).dist2();\n\
    \            else if (p.y > y1)  return (Point(p.x, y1) - p).dist2();\n      \
    \      else                return 0;\n        }\n    }\n};\n\nstruct Kdnode {\n\
    \    bool leaf;      // true if this is a leaf node (has one Point)\n    Point\
    \ pt;       // the single Point of this is a leaf\n    Bbox bound;     // bounding\
    \ box for set of Points in children\n\n    Kdnode *first, *second; // two children\
    \ of this kd-node\n\n    Kdnode() : leaf(false), first(0), second(0) {}\n    ~Kdnode()\
    \ { if (first) delete first; if (second) delete second; }\n\n    ll intersect(const\
    \ Point &p) {\n        return bound.distance(p);\n    }\n    void construct(vector<Point>\
    \ &vp) {\n        bound.compute(vp);\n        if (vp.size() == 1) { leaf = true;\
    \ pt = vp[0]; }\n        else {\n            if (bound.x1-bound.x0 >= bound.y1-bound.y0)\n\
    \                sort(vp.begin(), vp.end(), on_x);\n            else // otherwise\
    \ split on y-coordinate\n                sort(vp.begin(), vp.end(), on_y);\n\n\
    \            // divide by taking half the array for each child\n            //\
    \ (not best performance if many duplicates in the middle)\n            int half\
    \ = vp.size()/2;\n            vector<Point> vl(vp.begin(), vp.begin()+half);\n\
    \            vector<Point> vr(vp.begin()+half, vp.end());\n            first =\
    \ new Kdnode();   first->construct(vl);\n            second = new Kdnode();  second->construct(vr);\n\
    \        }\n    }\n};\n\nstruct kdtree {\n    Kdnode *root;\n    kdtree(const\
    \ vector<Point> &vp) {\n        vector<Point> v(vp.begin(), vp.end());\n     \
    \   root = new Kdnode(); root->construct(v);\n    }\n    ~kdtree() { delete root;\
    \ }\n\n    ll search(Kdnode *node, const Point &p) {\n        if (node->leaf)\
    \ {\n            // commented special case tells a Point not to find itself\n\
    \            // BUT NOTE THAT THIS WILL FAIL WHEN THERE ARE MULTIPLE POINTS AT\
    \ SAME POSITION\n            //            if (p == node->pt) return sentry;\n\
    \            //            else\n            return (p - node->pt).dist2();\n\
    \        }\n        ll bfirst = node->first->intersect(p);\n        ll bsecond\
    \ = node->second->intersect(p);\n        if (bfirst < bsecond) {\n           \
    \ ll best = search(node->first, p);\n            if (bsecond < best) best = min(best,\
    \ search(node->second, p));\n            return best;\n        }\n        else\
    \ {\n            ll best = search(node->second, p);\n            if (bfirst <\
    \ best) best = min(best, search(node->first, p));\n            return best;\n\
    \        }\n    }\n    // squared distance to the nearest\n    ll nearest(const\
    \ Point &p) {\n        return search(root, p);\n    }\n};\n"
  code: "// Tested:\n// - https://open.kattis.com/problems/closestpair1\n// - https://open.kattis.com/problems/closestpair2\n\
    //\n// A straightforward, but probably sub-optimal KD-tree implmentation that's\n\
    // probably good enough for most things (current it's a 2D-tree)\n//\n// - constructs\
    \ from n Points in O(n lg^2 n) time\n// - handles nearest-neighbor query in O(lg\
    \ n) if Points are well distributed\n// - worst case for nearest-neighbor may\
    \ be linear in pathological case\n// Note:\n// - When there are multiple points\
    \ in same position & we need to tell a Point\n//   not to find itself, must handle\
    \ separatedly.\n\ntypedef long long ll;\nconst ll sentry = numeric_limits<ll>::max();\n\
    struct Point {\n    ll x, y;\n    Point(ll xx = 0, ll yy = 0) : x(xx), y(yy) {}\n\
    \n    Point operator - (Point a) const { return Point(x-a.x, y-a.y); }\n\n   \
    \ ll dist2() { return x*x + y*y; }\n};\n\nbool operator == (const Point &a, const\
    \ Point &b){\n    return a.x == b.x && a.y == b.y;\n}\nbool on_x(const Point &a,\
    \ const Point &b) {\n    return a.x < b.x;\n}\nbool on_y(const Point &a, const\
    \ Point &b) {\n    return a.y < b.y;\n}\n\n// bounding box for a set of Points\n\
    struct Bbox {\n    ll x0, x1, y0, y1;\n    Bbox() : x0(sentry), x1(-sentry), y0(sentry),\
    \ y1(-sentry) {}\n    // computes bounding box from a bunch of Points\n    void\
    \ compute(const vector<Point> &v) {\n        for (int i = 0; i < v.size(); ++i)\
    \ {\n            x0 = min(x0, v[i].x); x1 = max(x1, v[i].x);\n            y0 =\
    \ min(y0, v[i].y); y1 = max(y1, v[i].y);\n        }\n    }\n    // squared distance\
    \ between a Point and this Bbox, 0 if inside\n    ll distance(const Point &p)\
    \ {\n        if (p.x < x0) {\n            if (p.y < y0)       return (Point(x0,\
    \ y0) - p).dist2();\n            else if (p.y > y1)  return (Point(x0, y1) - p).dist2();\n\
    \            else                return (Point(x0, p.y) - p).dist2();\n      \
    \  } else if (p.x > x1) {\n            if (p.y < y0)       return (Point(x1, y0)\
    \ - p).dist2();\n            else if (p.y > y1)  return (Point(x1, y1) - p).dist2();\n\
    \            else                return (Point(x1, p.y) - p).dist2();\n      \
    \  } else {\n            if (p.y < y0)       return (Point(p.x, y0) - p).dist2();\n\
    \            else if (p.y > y1)  return (Point(p.x, y1) - p).dist2();\n      \
    \      else                return 0;\n        }\n    }\n};\n\nstruct Kdnode {\n\
    \    bool leaf;      // true if this is a leaf node (has one Point)\n    Point\
    \ pt;       // the single Point of this is a leaf\n    Bbox bound;     // bounding\
    \ box for set of Points in children\n\n    Kdnode *first, *second; // two children\
    \ of this kd-node\n\n    Kdnode() : leaf(false), first(0), second(0) {}\n    ~Kdnode()\
    \ { if (first) delete first; if (second) delete second; }\n\n    ll intersect(const\
    \ Point &p) {\n        return bound.distance(p);\n    }\n    void construct(vector<Point>\
    \ &vp) {\n        bound.compute(vp);\n        if (vp.size() == 1) { leaf = true;\
    \ pt = vp[0]; }\n        else {\n            if (bound.x1-bound.x0 >= bound.y1-bound.y0)\n\
    \                sort(vp.begin(), vp.end(), on_x);\n            else // otherwise\
    \ split on y-coordinate\n                sort(vp.begin(), vp.end(), on_y);\n\n\
    \            // divide by taking half the array for each child\n            //\
    \ (not best performance if many duplicates in the middle)\n            int half\
    \ = vp.size()/2;\n            vector<Point> vl(vp.begin(), vp.begin()+half);\n\
    \            vector<Point> vr(vp.begin()+half, vp.end());\n            first =\
    \ new Kdnode();   first->construct(vl);\n            second = new Kdnode();  second->construct(vr);\n\
    \        }\n    }\n};\n\nstruct kdtree {\n    Kdnode *root;\n    kdtree(const\
    \ vector<Point> &vp) {\n        vector<Point> v(vp.begin(), vp.end());\n     \
    \   root = new Kdnode(); root->construct(v);\n    }\n    ~kdtree() { delete root;\
    \ }\n\n    ll search(Kdnode *node, const Point &p) {\n        if (node->leaf)\
    \ {\n            // commented special case tells a Point not to find itself\n\
    \            // BUT NOTE THAT THIS WILL FAIL WHEN THERE ARE MULTIPLE POINTS AT\
    \ SAME POSITION\n            //            if (p == node->pt) return sentry;\n\
    \            //            else\n            return (p - node->pt).dist2();\n\
    \        }\n        ll bfirst = node->first->intersect(p);\n        ll bsecond\
    \ = node->second->intersect(p);\n        if (bfirst < bsecond) {\n           \
    \ ll best = search(node->first, p);\n            if (bsecond < best) best = min(best,\
    \ search(node->second, p));\n            return best;\n        }\n        else\
    \ {\n            ll best = search(node->second, p);\n            if (bfirst <\
    \ best) best = min(best, search(node->first, p));\n            return best;\n\
    \        }\n    }\n    // squared distance to the nearest\n    ll nearest(const\
    \ Point &p) {\n        return search(root, p);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/KDTree.h
  requiredBy: []
  timestamp: '2015-09-09 01:11:48+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/KDTree.h
layout: document
redirect_from:
- /library/DataStructure/KDTree.h
- /library/DataStructure/KDTree.h.html
title: DataStructure/KDTree.h
---
