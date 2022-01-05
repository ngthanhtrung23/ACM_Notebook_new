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
    - https://codeforces.com/gym/100337
    - https://codeforces.com/gym/100337/submission/139751832)
    - https://judge.yosupo.jp/problem/bipartitematching
    - https://oj.vnoi.info/problem/fmatch
  bundledCode: "#line 1 \"Graph/Matching/Matching.h\"\n// Max Bipartite matching.\n\
    // Index from 0\n// Assume 2 sides have same number of vertices\n//\n// Notes:\n\
    // - If TLE --> try shuffle edges\n//   REP(i,n) shuffle(ke[i].begin(), ke[i].end(),\
    \ rng)\n// - It should be quite fast, can AC 10^5 vertices\n//\n// Find vertices\
    \ that belong to all maximum matching:\n// (see https://codeforces.com/gym/100337/submission/139751832)\n\
    // - L = vertices not matched on left side --> BFS from these vertices\n//   (left\
    \ --> right: unmatched edges, right --> left: matched edges)\n//   reachable vertices\
    \ on left side --> not belong to some maximum matching\n// - Do similar for right\
    \ side\n//\n// Tested:\n// - https://judge.yosupo.jp/problem/bipartitematching\n\
    // - https://oj.vnoi.info/problem/fmatch\n// - https://codeforces.com/gym/100337\
    \ - A: find vertices belong to all max matching\n\nstruct Matching {\n    int\
    \ n;\n    vector< vector<int> > ke;\n    vector< int > seen;\n    vector< int\
    \ > matchL, matchR;\n    int iteration;\n\n    Matching(int _n) : n(_n), ke(_n),\
    \ seen(_n, false), matchL(_n, -1), matchR(_n, -1), iteration{0} {\n    }\n\n \
    \   void addEdge(int u, int v) {\n        ke[u].push_back(v);\n    }\n\n    bool\
    \ dfs(int u) {\n        seen[u] = iteration;\n        for (int v : ke[u]) {\n\
    \            if (matchR[v] < 0) {\n                matchR[v] = u;\n          \
    \      matchL[u] = v;\n                return true;\n            }\n        }\n\
    \        for (int v : ke[u]) {\n            if (seen[matchR[v]] != iteration &&\
    \ dfs(matchR[v])) {\n                matchR[v] = u;\n                matchL[u]\
    \ = v;\n                return true;\n            }\n        }\n        return\
    \ false;\n    }\n\n    int match() {\n        int res = 0;\n        int newMatches\
    \ = 0;\n        do {\n            iteration++;\n            newMatches = 0;\n\
    \            for (int u = 0; u < n; u++) {\n                if (matchL[u] < 0\
    \ && dfs(u)) ++newMatches;\n            }\n            res += newMatches;\n  \
    \      } while (newMatches > 0);\n        return res;\n    }\n};\n"
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
    \ - A: find vertices belong to all max matching\n\nstruct Matching {\n    int\
    \ n;\n    vector< vector<int> > ke;\n    vector< int > seen;\n    vector< int\
    \ > matchL, matchR;\n    int iteration;\n\n    Matching(int _n) : n(_n), ke(_n),\
    \ seen(_n, false), matchL(_n, -1), matchR(_n, -1), iteration{0} {\n    }\n\n \
    \   void addEdge(int u, int v) {\n        ke[u].push_back(v);\n    }\n\n    bool\
    \ dfs(int u) {\n        seen[u] = iteration;\n        for (int v : ke[u]) {\n\
    \            if (matchR[v] < 0) {\n                matchR[v] = u;\n          \
    \      matchL[u] = v;\n                return true;\n            }\n        }\n\
    \        for (int v : ke[u]) {\n            if (seen[matchR[v]] != iteration &&\
    \ dfs(matchR[v])) {\n                matchR[v] = u;\n                matchL[u]\
    \ = v;\n                return true;\n            }\n        }\n        return\
    \ false;\n    }\n\n    int match() {\n        int res = 0;\n        int newMatches\
    \ = 0;\n        do {\n            iteration++;\n            newMatches = 0;\n\
    \            for (int u = 0; u < n; u++) {\n                if (matchL[u] < 0\
    \ && dfs(u)) ++newMatches;\n            }\n            res += newMatches;\n  \
    \      } while (newMatches > 0);\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Matching/Matching.h
  requiredBy: []
  timestamp: '2021-12-18 22:52:02+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Matching/Matching.h
layout: document
redirect_from:
- /library/Graph/Matching/Matching.h
- /library/Graph/Matching/Matching.h.html
title: Graph/Matching/Matching.h
---
