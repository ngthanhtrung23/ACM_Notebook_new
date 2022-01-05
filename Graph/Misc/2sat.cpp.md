---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://codeforces.com/contest/568/problem/C
    - https://oj.vnoi.info/problem/icpc21_mt_i
    - https://open.kattis.com/contests/nwerc15open/problems/cleaningpipes
  bundledCode: "#line 1 \"Graph/Misc/2sat.cpp\"\n// Tested:\n// - http://codeforces.com/contest/568/problem/C\n\
    // - https://open.kattis.com/contests/nwerc15open/problems/cleaningpipes\n// -\
    \ https://oj.vnoi.info/problem/icpc21_mt_i -> min lexicographical result\n//\n\
    // For lexicographical min result:\n// 1. Find which variables are fixed (if there\
    \ is path i -> i^1 or i^1 -> i)\n// 2. For each variable, when assigning value\
    \ to it\n//    -> DFS to set values of all others\n//    (Not sure if we need\
    \ to do similar for reverse edges?)\n// See https://oj.vnoi.info/problem/icpc21_mt_i\n\
    #include <bits/stdc++.h>\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\nusing\
    \ namespace std;\n\nconst int MN = 200111;   // 2 * no variables.\nint n;\nvector<int>\
    \ g[MN], gt[MN];\nvector<bool> used;\nvector<int> order, comp;\n\nvoid dfs1 (int\
    \ v) {\n    used[v] = true;\n    for (size_t i=0; i<g[v].size(); ++i) {\n    \
    \    int to = g[v][i];\n        if (!used[to])\n            dfs1 (to);\n\t}\n\t\
    order.push_back (v);\n}\nvoid dfs2 (int v, int cl) {\n    comp[v] = cl;\n    for\
    \ (size_t i=0; i<gt[v].size(); ++i) {\n        int to = gt[v][i];\n        if\
    \ (comp[to] == -1)\n            dfs2 (to, cl);\n\t}\n}\nint main() {\n    // n\
    \ = 2 * (number of boolean variables)\n    // NOTE: if we need to fix some variable,\
    \ e.g. set i = 0 --> addEdge(2*i+1, 2*i)\n    // var i --> 2 nodes: 2*i, 2*i+1.\n\
    \n    n = 200000;  // 2 * number of variables.\n    used.clear();\n    order.clear();\n\
    \    comp.clear();\n\n    REP(i,n) {\n        g[i].clear();\n        gt[i].clear();\n\
    \    }\n\n    // for each condition:\n    // u -> v: addEdge(u, v)\n\n    used.assign\
    \ (n, false);\n    REP(i,n)\n        if (!used[i])    dfs1 (i);\n    comp.assign\
    \ (n, -1);\n    for (int i=0, j=0; i<n; ++i) {\n        int v = order[n-i-1];\n\
    \        if (comp[v] == -1) dfs2 (v, j++);\n    }\n    REP(i,n)\n        if (comp[i]\
    \ == comp[i^1]) {\n            puts (\"NO SOLUTION\");\n            return 0;\n\
    \        }\n    for (int i=0; i<n; i += 2) {\n        int ans = comp[i] > comp[i^1]\
    \ ? i : i^1; \n        printf (\"%d \", ans);\n    }\n}\n\n"
  code: "// Tested:\n// - http://codeforces.com/contest/568/problem/C\n// - https://open.kattis.com/contests/nwerc15open/problems/cleaningpipes\n\
    // - https://oj.vnoi.info/problem/icpc21_mt_i -> min lexicographical result\n\
    //\n// For lexicographical min result:\n// 1. Find which variables are fixed (if\
    \ there is path i -> i^1 or i^1 -> i)\n// 2. For each variable, when assigning\
    \ value to it\n//    -> DFS to set values of all others\n//    (Not sure if we\
    \ need to do similar for reverse edges?)\n// See https://oj.vnoi.info/problem/icpc21_mt_i\n\
    #include <bits/stdc++.h>\n#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)\nusing\
    \ namespace std;\n\nconst int MN = 200111;   // 2 * no variables.\nint n;\nvector<int>\
    \ g[MN], gt[MN];\nvector<bool> used;\nvector<int> order, comp;\n\nvoid dfs1 (int\
    \ v) {\n    used[v] = true;\n    for (size_t i=0; i<g[v].size(); ++i) {\n    \
    \    int to = g[v][i];\n        if (!used[to])\n            dfs1 (to);\n\t}\n\t\
    order.push_back (v);\n}\nvoid dfs2 (int v, int cl) {\n    comp[v] = cl;\n    for\
    \ (size_t i=0; i<gt[v].size(); ++i) {\n        int to = gt[v][i];\n        if\
    \ (comp[to] == -1)\n            dfs2 (to, cl);\n\t}\n}\nint main() {\n    // n\
    \ = 2 * (number of boolean variables)\n    // NOTE: if we need to fix some variable,\
    \ e.g. set i = 0 --> addEdge(2*i+1, 2*i)\n    // var i --> 2 nodes: 2*i, 2*i+1.\n\
    \n    n = 200000;  // 2 * number of variables.\n    used.clear();\n    order.clear();\n\
    \    comp.clear();\n\n    REP(i,n) {\n        g[i].clear();\n        gt[i].clear();\n\
    \    }\n\n    // for each condition:\n    // u -> v: addEdge(u, v)\n\n    used.assign\
    \ (n, false);\n    REP(i,n)\n        if (!used[i])    dfs1 (i);\n    comp.assign\
    \ (n, -1);\n    for (int i=0, j=0; i<n; ++i) {\n        int v = order[n-i-1];\n\
    \        if (comp[v] == -1) dfs2 (v, j++);\n    }\n    REP(i,n)\n        if (comp[i]\
    \ == comp[i^1]) {\n            puts (\"NO SOLUTION\");\n            return 0;\n\
    \        }\n    for (int i=0; i<n; i += 2) {\n        int ans = comp[i] > comp[i^1]\
    \ ? i : i^1; \n        printf (\"%d \", ans);\n    }\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Misc/2sat.cpp
  requiredBy: []
  timestamp: '2021-12-13 03:33:30+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Misc/2sat.cpp
layout: document
redirect_from:
- /library/Graph/Misc/2sat.cpp
- /library/Graph/Misc/2sat.cpp.html
title: Graph/Misc/2sat.cpp
---
