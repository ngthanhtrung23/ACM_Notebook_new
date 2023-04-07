---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Graph/tests/aizu_grl_7_a_matching_bipartite.test.cpp
    title: Graph/tests/aizu_grl_7_a_matching_bipartite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/tests/matching_bipartite.test.cpp
    title: Graph/tests/matching_bipartite.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/gym/100337
    - https://codeforces.com/gym/100337/submission/139751832)
    - https://judge.yosupo.jp/problem/bipartitematching
    - https://oj.vnoi.info/problem/fmatch
  bundledCode: "#line 1 \"Graph/Matching/BipartiteMatching.h\"\n// Max Bipartite matching.\n\
    // Index from 0\n// Assume 2 sides have same number of vertices\n//\n// Notes:\n\
    // - If TLE --> try shuffle edges\n//   REP(i,n) shuffle(ke[i].begin(), ke[i].end(),\
    \ rng)\n// - It should be quite fast, can AC 10^5 vertices\n//\n// Find vertices\
    \ that belong to all maximum matching:\n// (see https://codeforces.com/gym/100337/submission/139751832)\n\
    // - L = vertices not matched on left side --> BFS from these vertices\n//   (left\
    \ --> right: unmatched edges, right --> left: matched edges)\n//   reachable vertices\
    \ on left side --> not belong to some maximum matching\n// - Do similar for right\
    \ side\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/bipartitematching\n\
    // - https://oj.vnoi.info/problem/fmatch\n// - https://codeforces.com/gym/100337\
    \ - A: find vertices belong to all max matching\n\n// Bipartite Matching {{{\n\
    struct Matching {\n    int n;\n    vector< vector<int> > ke;\n    vector< int\
    \ > seen;\n    vector< int > matchL, matchR;\n    int iteration;\n\n    Matching(int\
    \ _n) : n(_n), ke(_n), seen(_n, false), matchL(_n, -1), matchR(_n, -1), iteration{0}\
    \ {\n    }\n\n    void addEdge(int u, int v) {\n        ke[u].push_back(v);\n\
    \    }\n\n    bool dfs(int u) {\n        seen[u] = iteration;\n        for (int\
    \ v : ke[u]) {\n            if (matchR[v] < 0) {\n                matchR[v] =\
    \ u;\n                matchL[u] = v;\n                return true;\n         \
    \   }\n        }\n        for (int v : ke[u]) {\n            if (seen[matchR[v]]\
    \ != iteration && dfs(matchR[v])) {\n                matchR[v] = u;\n        \
    \        matchL[u] = v;\n                return true;\n            }\n       \
    \ }\n        return false;\n    }\n\n    int match() {\n        int res = 0;\n\
    \        int newMatches = 0;\n        do {\n            iteration++;\n       \
    \     newMatches = 0;\n            for (int u = 0; u < n; u++) {\n           \
    \     if (matchL[u] < 0 && dfs(u)) ++newMatches;\n            }\n            res\
    \ += newMatches;\n        } while (newMatches > 0);\n        return res;\n   \
    \ }\n};\n// }}}\n"
  code: "// Max Bipartite matching.\n// Index from 0\n// Assume 2 sides have same\
    \ number of vertices\n//\n// Notes:\n// - If TLE --> try shuffle edges\n//   REP(i,n)\
    \ shuffle(ke[i].begin(), ke[i].end(), rng)\n// - It should be quite fast, can\
    \ AC 10^5 vertices\n//\n// Find vertices that belong to all maximum matching:\n\
    // (see https://codeforces.com/gym/100337/submission/139751832)\n// - L = vertices\
    \ not matched on left side --> BFS from these vertices\n//   (left --> right:\
    \ unmatched edges, right --> left: matched edges)\n//   reachable vertices on\
    \ left side --> not belong to some maximum matching\n// - Do similar for right\
    \ side\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/bipartitematching\n\
    // - https://oj.vnoi.info/problem/fmatch\n// - https://codeforces.com/gym/100337\
    \ - A: find vertices belong to all max matching\n\n// Bipartite Matching {{{\n\
    struct Matching {\n    int n;\n    vector< vector<int> > ke;\n    vector< int\
    \ > seen;\n    vector< int > matchL, matchR;\n    int iteration;\n\n    Matching(int\
    \ _n) : n(_n), ke(_n), seen(_n, false), matchL(_n, -1), matchR(_n, -1), iteration{0}\
    \ {\n    }\n\n    void addEdge(int u, int v) {\n        ke[u].push_back(v);\n\
    \    }\n\n    bool dfs(int u) {\n        seen[u] = iteration;\n        for (int\
    \ v : ke[u]) {\n            if (matchR[v] < 0) {\n                matchR[v] =\
    \ u;\n                matchL[u] = v;\n                return true;\n         \
    \   }\n        }\n        for (int v : ke[u]) {\n            if (seen[matchR[v]]\
    \ != iteration && dfs(matchR[v])) {\n                matchR[v] = u;\n        \
    \        matchL[u] = v;\n                return true;\n            }\n       \
    \ }\n        return false;\n    }\n\n    int match() {\n        int res = 0;\n\
    \        int newMatches = 0;\n        do {\n            iteration++;\n       \
    \     newMatches = 0;\n            for (int u = 0; u < n; u++) {\n           \
    \     if (matchL[u] < 0 && dfs(u)) ++newMatches;\n            }\n            res\
    \ += newMatches;\n        } while (newMatches > 0);\n        return res;\n   \
    \ }\n};\n// }}}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Matching/BipartiteMatching.h
  requiredBy: []
  timestamp: '2023-01-28 18:33:13+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Graph/tests/matching_bipartite.test.cpp
  - Graph/tests/aizu_grl_7_a_matching_bipartite.test.cpp
documentation_of: Graph/Matching/BipartiteMatching.h
layout: document
redirect_from:
- /library/Graph/Matching/BipartiteMatching.h
- /library/Graph/Matching/BipartiteMatching.h.html
title: Graph/Matching/BipartiteMatching.h
---
