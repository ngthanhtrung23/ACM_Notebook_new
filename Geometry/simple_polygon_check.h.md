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
  bundledCode: "#line 1 \"Geometry/simple_polygon_check.h\"\n// Given a polygon a[i].\
    \ Check if it is simple (does not self-intersect)\n// - If a vertex appear >=\
    \ 2 times --> not simple\n// - l[i] = Line(a[i], a[i+1])\ndouble get (int i, double\
    \ cx) { // get y-coordinate of segment a[i] - a[i+1]\n    if (a[i].x == a[i +\
    \ 1].x) return (a[i].y + a[i + 1].y) / 2.0;\n    return a[i].y + (a[i + 1].y -\
    \ a[i].y) / (a[i + 1].x - a[i].x + 0.0) * (cx - a[i].x);\n}\nstruct comp { //\
    \ compare 2 points\n    bool operator() (const int& i, const int& j) const {\n\
    \        double x1 = max (min (a[i].x, a[i + 1].x), min (a[j].x, a[j + 1].x));\n\
    \        double x2 = min (max (a[i].x, a[i + 1].x), max (a[j].x, a[j + 1].x));\n\
    \        double cx = (x1 + x2) / 2;\n        double a = get (i, cx);\n       \
    \ double b = get (j, cx);\n        return a < b - 1e-6 || (abs (a - b) < 1e-6\
    \ && i < j);\n    }   \n};\nbool is_simple() {\n\tvector< pair< pair<ll,int>,\
    \ int > > events;\n\tFOR(i,1,n) {\n\t\tll l = min(a[i].x, a[i+1].x);\n\t\tll r\
    \ = max(a[i].x, a[i+1].x);\n\t\tevents.push_back(make_pair(make_pair(l, 0), i));\n\
    \t\tevents.push_back(make_pair(make_pair(r, 1), i));\n\t}\n\tsort(events.begin(),\
    \ events.end());\n\n\tmemset(mark, 0, sizeof mark);\n\tset<int, comp> all;\n\t\
    for(auto p : events) {\n\t\tint id = p.second;\n\t\tif (!mark[id]) all.insert(id);\n\
    \n\t\tauto it = all.find(id);\n\t\tauto prev = it;\n\t\tif (prev != all.begin())\
    \ {\n\t\t\tprev--;\n\t\t\tif (areIntersect(l[id], l[*prev]))  // l[i] = segment\
    \ a[i] - a[i+1]\n\t\t\t\treturn false; // not simple polygon\n\t\t}\n\t\tauto\
    \ next = it; ++next;\n\t\tif (next != all.end()) {\n\t\t\tif (areIntersect(l[id],\
    \ l[*next]))\n\t\t\t\treturn false;\n\t\t\tif (cntIntersect(l[*prev], l[*next]))\n\
    \t\t\t\treturn false;\n\t\t}\n\t\tif (mark[id]) all.erase(id);\n\t\tmark[id] =\
    \ !mark[id];\n\t}\n\treturn true;\n}\n"
  code: "// Given a polygon a[i]. Check if it is simple (does not self-intersect)\n\
    // - If a vertex appear >= 2 times --> not simple\n// - l[i] = Line(a[i], a[i+1])\n\
    double get (int i, double cx) { // get y-coordinate of segment a[i] - a[i+1]\n\
    \    if (a[i].x == a[i + 1].x) return (a[i].y + a[i + 1].y) / 2.0;\n    return\
    \ a[i].y + (a[i + 1].y - a[i].y) / (a[i + 1].x - a[i].x + 0.0) * (cx - a[i].x);\n\
    }\nstruct comp { // compare 2 points\n    bool operator() (const int& i, const\
    \ int& j) const {\n        double x1 = max (min (a[i].x, a[i + 1].x), min (a[j].x,\
    \ a[j + 1].x));\n        double x2 = min (max (a[i].x, a[i + 1].x), max (a[j].x,\
    \ a[j + 1].x));\n        double cx = (x1 + x2) / 2;\n        double a = get (i,\
    \ cx);\n        double b = get (j, cx);\n        return a < b - 1e-6 || (abs (a\
    \ - b) < 1e-6 && i < j);\n    }   \n};\nbool is_simple() {\n\tvector< pair< pair<ll,int>,\
    \ int > > events;\n\tFOR(i,1,n) {\n\t\tll l = min(a[i].x, a[i+1].x);\n\t\tll r\
    \ = max(a[i].x, a[i+1].x);\n\t\tevents.push_back(make_pair(make_pair(l, 0), i));\n\
    \t\tevents.push_back(make_pair(make_pair(r, 1), i));\n\t}\n\tsort(events.begin(),\
    \ events.end());\n\n\tmemset(mark, 0, sizeof mark);\n\tset<int, comp> all;\n\t\
    for(auto p : events) {\n\t\tint id = p.second;\n\t\tif (!mark[id]) all.insert(id);\n\
    \n\t\tauto it = all.find(id);\n\t\tauto prev = it;\n\t\tif (prev != all.begin())\
    \ {\n\t\t\tprev--;\n\t\t\tif (areIntersect(l[id], l[*prev]))  // l[i] = segment\
    \ a[i] - a[i+1]\n\t\t\t\treturn false; // not simple polygon\n\t\t}\n\t\tauto\
    \ next = it; ++next;\n\t\tif (next != all.end()) {\n\t\t\tif (areIntersect(l[id],\
    \ l[*next]))\n\t\t\t\treturn false;\n\t\t\tif (cntIntersect(l[*prev], l[*next]))\n\
    \t\t\t\treturn false;\n\t\t}\n\t\tif (mark[id]) all.erase(id);\n\t\tmark[id] =\
    \ !mark[id];\n\t}\n\treturn true;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/simple_polygon_check.h
  requiredBy: []
  timestamp: '2016-01-05 03:45:48+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/simple_polygon_check.h
layout: document
redirect_from:
- /library/Geometry/simple_polygon_check.h
- /library/Geometry/simple_polygon_check.h.html
title: Geometry/simple_polygon_check.h
---
