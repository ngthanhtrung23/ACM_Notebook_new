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
    - https://cses.fi/problemset/task/1679/
    - https://cses.fi/problemset/task/1757/
    - https://www.spoj.com/problems/TOPOSORT/)
  bundledCode: "#line 1 \"Graph/topo_sort.h\"\n// Topo sort\n// returns: <has topo\
    \ sort?, topo order>\n//\n// Notes:\n// - To find lexicographically min -> change\
    \ queue<int> qu to set\n//   (see https://www.spoj.com/problems/TOPOSORT/)\n//\n\
    // Tested:\n// - https://cses.fi/problemset/task/1679/\n// - https://cses.fi/problemset/task/1757/\n\
    std::pair<bool, std::vector<int>> topo_sort(const std::vector<std::vector<int>>&\
    \ g) {\n    int n = g.size();\n    // init in_deg\n    std::vector<int> in_deg(n,\
    \ 0);\n    for (int u = 0; u < n; u++) {\n        for (int v : g[u]) {\n     \
    \       in_deg[v]++;\n        }\n    }\n\n    // find topo order\n    std::vector<int>\
    \ res;\n    std::queue<int> qu;\n    for (int u = 0; u < n; u++) {\n        if\
    \ (in_deg[u] == 0) {\n            qu.push(u);\n        }\n    }\n\n    while (!qu.empty())\
    \ {\n        int u = qu.front(); qu.pop();\n        res.push_back(u);\n      \
    \  for (int v : g[u]) {\n            in_deg[v]--;\n            if (in_deg[v] ==\
    \ 0) {\n                qu.push(v);\n            }\n        }\n    }\n\n    if\
    \ ((int) res.size() < n) {\n        return {false, {}};\n    }\n    return {true,\
    \ res};\n}\n"
  code: "// Topo sort\n// returns: <has topo sort?, topo order>\n//\n// Notes:\n//\
    \ - To find lexicographically min -> change queue<int> qu to set\n//   (see https://www.spoj.com/problems/TOPOSORT/)\n\
    //\n// Tested:\n// - https://cses.fi/problemset/task/1679/\n// - https://cses.fi/problemset/task/1757/\n\
    std::pair<bool, std::vector<int>> topo_sort(const std::vector<std::vector<int>>&\
    \ g) {\n    int n = g.size();\n    // init in_deg\n    std::vector<int> in_deg(n,\
    \ 0);\n    for (int u = 0; u < n; u++) {\n        for (int v : g[u]) {\n     \
    \       in_deg[v]++;\n        }\n    }\n\n    // find topo order\n    std::vector<int>\
    \ res;\n    std::queue<int> qu;\n    for (int u = 0; u < n; u++) {\n        if\
    \ (in_deg[u] == 0) {\n            qu.push(u);\n        }\n    }\n\n    while (!qu.empty())\
    \ {\n        int u = qu.front(); qu.pop();\n        res.push_back(u);\n      \
    \  for (int v : g[u]) {\n            in_deg[v]--;\n            if (in_deg[v] ==\
    \ 0) {\n                qu.push(v);\n            }\n        }\n    }\n\n    if\
    \ ((int) res.size() < n) {\n        return {false, {}};\n    }\n    return {true,\
    \ res};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/topo_sort.h
  requiredBy: []
  timestamp: '2022-11-19 11:13:09+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/topo_sort.h
layout: document
redirect_from:
- /library/Graph/topo_sort.h
- /library/Graph/topo_sort.h.html
title: Graph/topo_sort.h
---
