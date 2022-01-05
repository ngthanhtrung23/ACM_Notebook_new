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
    - http://codeforces.com/contest/776/problem/F
  bundledCode: "#line 1 \"Geometry/polygon_region.h\"\n// Given polygon with N vertices,\
    \ and M diagonals.\n// Diagonals does not intersect in internal point.\n// Split\
    \ polygon into regions.\n//\n// Usage:\n// PolygonRegion a(n);\n// for (auto p\
    \ : diagonals) a.addEdge(p.first - 1, p.second - 1);\n// a.init();\n// Tested:\
    \ http://codeforces.com/contest/776/problem/F\nconst int MN = 300111;\nvector<int>\
    \ ke[MN];  // 0-based index\nstruct PolygonRegion {  // everything is 0-based\
    \ index\n    int n;\n    set<int> vertices;\n    vector< pair<int,int> > diagonals;\n\
    \    vector< vector<int> > regions;\n\n    PolygonRegion(int n) : n(n) {\n   \
    \     vertices.clear();\n        REP(i,n) vertices.insert(i);\n        diagonals.clear();\n\
    \    }\n\n    void addEdge(int a, int b) {\n        assert(a != b);\n        if\
    \ (a > b) swap(a, b);\n        assert(a + 1 != b);\n        if (a == n) assert(b\
    \ != 1);\n\n        diagonals.emplace_back(b - a, a);\n    }\n\n    void init()\
    \ {\n        diagonals.emplace_back(n-1, 0);\n        regions.clear();\n\n   \
    \     REP(i,n+1) ke[i].clear();\n\n        sort(diagonals.begin(), diagonals.end());\n\
    \        REP(idiag,SZ(diagonals)) {\n            auto diagonal = diagonals[idiag];\n\
    \n            // (s, t) = current diagonal\n            int s = diagonal.second;\n\
    \            int t = s + diagonal.first;\n\n            // extract polygon\n \
    \           auto it = vertices.find(s); ++it;\n            vector<int> cur;\n\
    \            cur.push_back(s);\n            while (true) {\n                if\
    \ (*it == t) break;\n                cur.push_back(*it);\n                vertices.erase(it++);\n\
    \            }\n            cur.push_back(t);\n\n            // update adjacent\
    \ list.\n            REP(j,SZ(cur)-1) {  // consider all edges except (s, t)\n\
    \                if (cur[j+1] - cur[j] > 1) {\n                    int low = lower_bound(diagonals.begin(),\
    \ diagonals.end(), make_pair(cur[j+1] - cur[j], cur[j])) - diagonals.begin();\n\
    \                    ke[low].push_back(idiag);\n                    ke[idiag].push_back(low);\n\
    \                }\n            }\n\n            regions.push_back(cur);\n   \
    \     }\n    }\n};\n"
  code: "// Given polygon with N vertices, and M diagonals.\n// Diagonals does not\
    \ intersect in internal point.\n// Split polygon into regions.\n//\n// Usage:\n\
    // PolygonRegion a(n);\n// for (auto p : diagonals) a.addEdge(p.first - 1, p.second\
    \ - 1);\n// a.init();\n// Tested: http://codeforces.com/contest/776/problem/F\n\
    const int MN = 300111;\nvector<int> ke[MN];  // 0-based index\nstruct PolygonRegion\
    \ {  // everything is 0-based index\n    int n;\n    set<int> vertices;\n    vector<\
    \ pair<int,int> > diagonals;\n    vector< vector<int> > regions;\n\n    PolygonRegion(int\
    \ n) : n(n) {\n        vertices.clear();\n        REP(i,n) vertices.insert(i);\n\
    \        diagonals.clear();\n    }\n\n    void addEdge(int a, int b) {\n     \
    \   assert(a != b);\n        if (a > b) swap(a, b);\n        assert(a + 1 != b);\n\
    \        if (a == n) assert(b != 1);\n\n        diagonals.emplace_back(b - a,\
    \ a);\n    }\n\n    void init() {\n        diagonals.emplace_back(n-1, 0);\n \
    \       regions.clear();\n\n        REP(i,n+1) ke[i].clear();\n\n        sort(diagonals.begin(),\
    \ diagonals.end());\n        REP(idiag,SZ(diagonals)) {\n            auto diagonal\
    \ = diagonals[idiag];\n\n            // (s, t) = current diagonal\n          \
    \  int s = diagonal.second;\n            int t = s + diagonal.first;\n\n     \
    \       // extract polygon\n            auto it = vertices.find(s); ++it;\n  \
    \          vector<int> cur;\n            cur.push_back(s);\n            while\
    \ (true) {\n                if (*it == t) break;\n                cur.push_back(*it);\n\
    \                vertices.erase(it++);\n            }\n            cur.push_back(t);\n\
    \n            // update adjacent list.\n            REP(j,SZ(cur)-1) {  // consider\
    \ all edges except (s, t)\n                if (cur[j+1] - cur[j] > 1) {\n    \
    \                int low = lower_bound(diagonals.begin(), diagonals.end(), make_pair(cur[j+1]\
    \ - cur[j], cur[j])) - diagonals.begin();\n                    ke[low].push_back(idiag);\n\
    \                    ke[idiag].push_back(low);\n                }\n          \
    \  }\n\n            regions.push_back(cur);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/polygon_region.h
  requiredBy: []
  timestamp: '2017-03-05 18:38:51+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/polygon_region.h
layout: document
redirect_from:
- /library/Geometry/polygon_region.h
- /library/Geometry/polygon_region.h.html
title: Geometry/polygon_region.h
---
