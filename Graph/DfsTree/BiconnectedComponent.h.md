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
  bundledCode: "#line 1 \"Graph/DfsTree/BiconnectedComponent.h\"\n// Input graph:\
    \ vector< vector<int> > a, int n\n// Note: 0-indexed\n// Usage: BiconnectedComponent\
    \ bc; (bc.components is the list of components)\n//\n// This is biconnected components\
    \ by edges (1 vertex can belong to\n// multiple components). For vertices biconnected\
    \ component, remove\n// bridges and find components\nint n;\nvector<vector<int>>\
    \ g;\nstruct BiconnectedComponent {\n    vector<int> low, num, s;\n    vector<\
    \ vector<int> > components;\n    int counter;\n\n    BiconnectedComponent() :\
    \ low(n, -1), num(n, -1), counter(0) {\n        for (int i = 0; i < n; i++)\n\
    \            if (num[i] < 0)\n                dfs(i, 1);\n    }\n\n    void dfs(int\
    \ x, int isRoot) {\n        low[x] = num[x] = ++counter;\n        if (g[x].empty())\
    \ {\n            components.push_back(vector<int>(1, x));\n            return;\n\
    \        }\n        s.push_back(x);\n\n        for (int i = 0; i < (int) g[x].size();\
    \ i++) {\n            int y = g[x][i];\n            if (num[y] > -1) low[x] =\
    \ min(low[x], num[y]);\n            else {\n                dfs(y, 0);\n     \
    \           low[x] = min(low[x], low[y]);\n\n                if (isRoot || low[y]\
    \ >= num[x]) {\n                    components.push_back(vector<int>(1, x));\n\
    \                    while (1) {\n                        int u = s.back();\n\
    \                        s.pop_back();\n                        components.back().push_back(u);\n\
    \                        if (u == y) break;\n                    }\n         \
    \       }\n            }\n        }\n    }\n};\n"
  code: "// Input graph: vector< vector<int> > a, int n\n// Note: 0-indexed\n// Usage:\
    \ BiconnectedComponent bc; (bc.components is the list of components)\n//\n// This\
    \ is biconnected components by edges (1 vertex can belong to\n// multiple components).\
    \ For vertices biconnected component, remove\n// bridges and find components\n\
    int n;\nvector<vector<int>> g;\nstruct BiconnectedComponent {\n    vector<int>\
    \ low, num, s;\n    vector< vector<int> > components;\n    int counter;\n\n  \
    \  BiconnectedComponent() : low(n, -1), num(n, -1), counter(0) {\n        for\
    \ (int i = 0; i < n; i++)\n            if (num[i] < 0)\n                dfs(i,\
    \ 1);\n    }\n\n    void dfs(int x, int isRoot) {\n        low[x] = num[x] = ++counter;\n\
    \        if (g[x].empty()) {\n            components.push_back(vector<int>(1,\
    \ x));\n            return;\n        }\n        s.push_back(x);\n\n        for\
    \ (int i = 0; i < (int) g[x].size(); i++) {\n            int y = g[x][i];\n  \
    \          if (num[y] > -1) low[x] = min(low[x], num[y]);\n            else {\n\
    \                dfs(y, 0);\n                low[x] = min(low[x], low[y]);\n\n\
    \                if (isRoot || low[y] >= num[x]) {\n                    components.push_back(vector<int>(1,\
    \ x));\n                    while (1) {\n                        int u = s.back();\n\
    \                        s.pop_back();\n                        components.back().push_back(u);\n\
    \                        if (u == y) break;\n                    }\n         \
    \       }\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/DfsTree/BiconnectedComponent.h
  requiredBy: []
  timestamp: '2021-12-30 14:41:41+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/DfsTree/BiconnectedComponent.h
layout: document
redirect_from:
- /library/Graph/DfsTree/BiconnectedComponent.h
- /library/Graph/DfsTree/BiconnectedComponent.h.html
title: Graph/DfsTree/BiconnectedComponent.h
---
